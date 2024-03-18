#include<stdio.h>
#include<stdlib.h>


int AssegnaBiscottirec(const int* bam, size_t bam_size,
    const int* bis, size_t bis_size,int *vcurr,int i,int *pb,int p)
{
    if (i == bam_size)
    {
        if (p > *pb)
        {
            *pb = p;
        }

        return;
    }

    int som = 0;

    for (size_t j = 0; j < bis_size; j++)
    {
        if (vcurr[j] != 1)
        {
            som = som + bis[j];
            vcurr[j] = 1;
        }
        if ((som - bam[i]) >= 0)
        {
            AssegnaBiscottirec(bam, bam_size, bis, bis_size, vcurr, i + 1, pb, p+1);
            vcurr[j] = 0;
        }
        if (j == bis_size - 1)
        {
            AssegnaBiscottirec(bam, bam_size, bis, bis_size, vcurr, i + 1, pb, p);
        }
        

    }


}

int AssegnaBiscotti(const int* bam, size_t bam_size,
    const int* bis, size_t bis_size)
{
    int* sod = calloc(bis_size, sizeof(int));
    int s = 0;
    AssegnaBiscottirec(bam, bam_size, bis, bis_size, sod, 0, &s, 0);
    free(sod);
    return s;

}

