
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
static char* Overlap(const char* str1, const char* str2, int* overlapping) {
    const int len1 = (int)strlen(str1);
    const int len2 = (int)strlen(str2);
    const int lenShort = len1 < len2 ? len1 : len2;
    const int lenLong = len1 < len2 ? len2 : len1;
    const char* strShort = len1 < len2 ? str1 : str2;
    const char* strLong = len1 < len2 ? str2 : str1;
    // Check if strShort is a substring of strLong
    if (strstr(strLong, strShort) != NULL) {
        char* res = malloc(lenLong + 1);
        strcpy(res, strLong);
        *overlapping = lenShort;
        return res;
    }
    int maxOverlap = 0;
    bool longGoesFirst = true;
    // Try to put strShort at the end of strLong
    for (int i = lenShort - 1; i > 0; --i) {
        if (strncmp(strLong + lenLong - i, strShort, i) == 0) {
            maxOverlap = i;
            break;
        }
    }
    // Try to put strLong and the end of strShort
    for (int i = lenShort - 1; i > maxOverlap; --i) {
        if (strncmp(strLong, strShort + lenShort - i, i) == 0) {
            if (i > maxOverlap) {
                maxOverlap = i;
                longGoesFirst = false;
            }
            break;
        }
    }
    char* res = malloc(lenLong + lenShort - maxOverlap + 1);
    if (longGoesFirst) {
        strcpy(res, strLong);
        strcpy(res + lenLong, strShort + maxOverlap);
    }
    else {
        strcpy(res, strShort);
        strcpy(res + lenShort, strLong + maxOverlap);
    }
    *overlapping = maxOverlap;
    return res;
}
bool coppia(int* v,size_t ss)
{
    int s = 0;
    for (size_t i = 0; i < s; i++)
    {
        if (v[i] == 1)
        {
            s++;
        }
    }
    if (s == 2)
    {
        return true;
    }
return false;
}


char* SolveSuperstringrec(const char** v, size_t v_size, int* vcurr, int pres, int i, int* sov, int** vbest)
{

    if (pres == 2)
    {

        int s1 = -1;
        int s2 = -1;
        for (size_t i = 0; i < v_size; i++)
        {
            if (vcurr[i] == 1 && s1 == -1)
            {
                s1 = i;
                continue;
            }
            if (vcurr[i] == 1 && s2 == -1)
            {
                s2 = i;
            }

        }
        int s = 0;
        Overlap(v[s1], v[s2], &s);
        if (s > *sov)
        {
            for (size_t i = 0, j = 0; i < v_size; i++)
            {
                vbest[j][i] = vcurr[i];
            }
            *sov = s;
        }
        return;
    }
    if (i == v_size)
    {
        return;
    }



    vcurr[i] = 1;
    SolveSuperstringrec(v, v_size, vcurr, pres + 1, i + 1, sov, vbest);
    vcurr[i] = 0;
    SolveSuperstringrec(v, v_size, vcurr, pres, i + 1, sov, vbest);

}

char* SolveSuperstring(const char** v, size_t v_size)
{
    char** vvv = calloc(v_size, sizeof(char));
    for (size_t i = 0; i < v_size; i++)
    {
        vvv[i] = v[i];

    }
    char* out=0;
    int s=v_size;
    int s1 = -1;
    int s2 = -1;
    char* c;

    while (s != 1)
    {
        char** vv = vvv;
        int r = 0;
        int* vcurr = calloc(s, sizeof(int));
        int* vbest = calloc(s, sizeof(vcurr));
        SolveSuperstringrec(vv, s, vcurr, 0, 0, &r, &vbest);
        for (size_t i = 0; i < s; i++)
        {
            if (vbest[i] == 1 && s1 == -1)
            {
                s1 = i;
                continue;
            }
            if (vbest[i] == 1 && s2 == -1)
            {
                s2 = i;
            }

        }

        size_t si1 = strlen(vv[s1]);
        size_t si2 = strlen(vv[s2]);
        char *strin1 = vv[s1];
        char *strin2 = vv[s2];
        int s34 = 0;
         out = Overlap(vv[s1], vv[s2], &s34);
        char** vvvv = calloc(v_size, sizeof(char));
        for (size_t i = 0; i < s; i++)
        {
            vvvv[i] = vvv[i];

        }
        vvv = realloc(vvv, s - 1*sizeof(char));
        vvv[0] = out;
        if (s-1 == 1)
        {
            free(vvv);
            free(vvvv);
            free(vcurr);
            free(vbest);
            free(vv);
            break;
        }
        for (size_t i = 1, j = 0; j < s;j++)
        {
            if (strcmp(vvvv[j],strin1)==0 || strcmp(vvvv[j], strin2)==0 || strcmp(vvvv[j], out)==0)
            {
                continue;
            }
          
            vvv[i] = vvvv[j];
            i++;
        }
        s = s - 1;
        out = 0;
        s1 = -1;
        s2 = -1;

    }
    return out;
    
}
