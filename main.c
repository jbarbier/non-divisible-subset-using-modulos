#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void print_array(int *a, int size)
{
    int i;
    
    for (i = 0; i < size; i++)
    {
        printf("%d ", a[i]);    
    }
    printf("\n");
}

int main() {
    int n, k;
    int *set, *mod_array;
    int i;
    int res;

    scanf("%d %d", &n, &k);
    set = malloc(sizeof(int) * n);
    mod_array = malloc(sizeof(int) * k);
    for (i = 0; i < k; i++)
    {
        mod_array[i] = 0; 
    }
    for (i = 0; i < n; i++)
    {
        scanf("%d", &set[i]);
        mod_array[set[i] % k] += 1;
    }
    //print_array(mod_array, k);
    res = 0;
    if (mod_array[0] > 0)
    {
        res++;
    }   
    if (k % 2 == 0)
    {
       if (mod_array[k / 2] > 0)
       {
           res++;    
       }
       for (i = 1; i < k / 2; i++)
       {
           if (mod_array[k - i] > mod_array[i])
           {
                res += mod_array[k - i];    
           }
           else
           {
                res += mod_array[i];               
           }
       }
    }
    else // k % 2 = 1
    {
        for (i = 1; i < (k + 1) / 2; i++)
        {
           if (mod_array[k - i] > mod_array[i])
           {
                res += mod_array[k - i];    
           }
           else
           {
                res += mod_array[i];               
           }
        }
    }
    printf("%d", res);
    free(mod_array);
    free(set);
    return (0);
}
