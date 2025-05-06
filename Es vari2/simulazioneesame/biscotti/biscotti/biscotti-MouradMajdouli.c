#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

int AssegnaBiscottirec(const int* bam, size_t bam_size,
    const int* bis, size_t bis_size,int *vpres,int i,int *best,int sod)
{
    if (i == bam_size)
    {
        if (sod > *best)
        {
            *best = sod;
        }

        return;
    }


    int som = 0;
    for (size_t j = 0; j < bis_size; j++)
    {
        if (vpres[j] != 1)
        {
            vpres[j] = 1;
            som = som + bis[j];
        }
        if (som >= bam[i])
        {
            AssegnaBiscottirec(bam, bam_size, bis, bis_size, vpres, i + 1,best,sod+1);
            vpres[j] = 0;
        }
        if (j == bis_size - 1)
        {
            AssegnaBiscottirec(bam, bam_size, bis, bis_size, vpres, i + 1, best, sod);
        }
    }

}
int AssegnaBiscotti(const int* bam, size_t bam_size,
    const int* bis, size_t bis_size)
{
    int* bispres = calloc(bis_size, sizeof(int));
    int sbest = 0;
    AssegnaBiscottirec(bam, bam_size, bis, bis_size, bispres, 0, &sbest, 0);
}

void main(void)
{
    int bam[] = {10,20,30};
    int bis[] = { 10,6,7,8 };
    AssegnaBiscotti(bam, 3, bis, 4);

}