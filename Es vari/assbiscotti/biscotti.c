#include<stdlib.h>


int AssegnaBiscottirec(const int* bam, size_t bam_size,
    const int* bis, size_t bis_size,int *vcurr,int *n_sodbest,int i,int j,int som,int sod )
{

    if (i == bam_size)
    {
        if (sod > (*n_sodbest))
        {
            *n_sodbest = sod;
        }
        return;
    }


    for (size_t k = 0; k < bis_size; k++)
    {
       if (bam[i] <= bis[k])
        {
        vcurr[i] = 1;
        AssegnaBiscottirec(bam, bam_size, bis, bis_size, vcurr, n_sodbest, i+1,j+1, bis[i+1], sod + 1);
        }
       if (bam[i] > som)
       {
           vcurr[i] = 0;
           AssegnaBiscottirec(bam, bam_size, bis, bis_size, vcurr, n_sodbest, i, j + 1, som = som + bis[i + 1], sod);
           AssegnaBiscottirec(bam, bam_size, bis, bis_size, vcurr, n_sodbest, i + 1, j, som = som + bis[i + 1], sod);
       }
       

    }
  
        if (bam[i] <= som)
        {
        vcurr[i] = 1;
        AssegnaBiscottirec(bam, bam_size, bis, bis_size, vcurr, n_sodbest, i+1,j+1, bis[i+1], sod + 1);
        }
   
    
    

}



int AssegnaBiscotti(const int* bam, size_t bam_size,
    const int* bis, size_t bis_size)
{

    if ((bam == NULL) || (bis == NULL)||(bam_size==0)||(bis_size==0))
    {
        return 0;
    }

    int* vcurr = calloc(bam_size, sizeof(int));
    int n_sod = 0;


     AssegnaBiscottirec(bam,bam_size,bis,bis_size,vcurr,&n_sod,0,0,bis[0], 0);
}

void main(void)
{
    

    int bam[] = { 5, 10, 15, 20, 25, 30, 35 };
    int bis[] = { 32, 29, 10, 7, 29, 3, 11, 23 };
    AssegnaBiscotti(bam, 7, bis, 8 );
}