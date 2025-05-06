#include<stdlib.h>
#include<stdio.h>


void backtrack(int b, const int* m, size_t m_size, int* solution, int depth,int *count) {
    if (b == 0) {
        // Abbiamo trovato una soluzione, la stampiamo
        for (int i = 0; i < m_size; i++) {
            printf("%d ", solution[i]);
        }
        printf("\n");
        *count=*count+1;
        return ;
    }

    if (b < 0 || depth >= m_size) {
        // Non è possibile costruire il budget
        return;
    }

    int coin = m[depth];
    int max_count = b / coin;

    for (int i = 0; i <= max_count; i++) {
        solution[depth] = i;
        backtrack(b-(coin*i), m, m_size, solution, depth + 1,count);
    }

    
}

extern int CombinaMonete(int b, const int* m, size_t m_size) {
    int *solution=malloc(m_size*sizeof(int));
    int n_sol = 0;
    backtrack(b, m, m_size, solution, 0,&n_sol);
    free(solution);
    return n_sol;
}
	
	
	




//void main(void)
//{
//	int b = 4;
//	int c[] = { 1,2,50,5,20 };
//	CombinaMonete(b, c, 5);
//}