#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define RUNS 100

void asm_func(const double* in, double* out, int size);

void c_func(const double* in, double* out, int size)
{
    // TODO: Math Implemetation
}

int main(void)
{
    LARGE_INTEGER freq, start, end;
    QueryPerformanceFrequency(&freq);

    // Size Initialization
    int size = 1 << 20;
    double* arr1 = (double*)malloc(sizeof(double) * size);
    double* arrC = (double*)malloc(sizeof(double) * size);
    double* arr2 = (double*)malloc(sizeof(double) * size);

    if (arr1 == NULL || arrC == NULL || arr2 == NULL) {
        printf("Memory not allocated.\n");
        free(arr1); free(arrC); free(arr2);
        return 1;
    }

    for (int i = 0; i < size; i++)
        arr1[i] = 0.0; // TODO

    memset(arrC, 0, sizeof(double) * size);
    memset(arr2, 0, sizeof(double) * size);


    // Run C Function
    QueryPerformanceCounter(&start);
    for (int r = 0; r < RUNS; r++)
        c_func(arr1, arrC, size);
    QueryPerformanceCounter(&end);
    double c_time = (double)(end.QuadPart - start.QuadPart) * 1000.0 / freq.QuadPart / RUNS;
    printf("C   average time: %.4f ms\n", c_time);

    // Run Asm Function
    QueryPerformanceCounter(&start);
    for (int r = 0; r < RUNS; r++)
        asm_func(arr1, arr2, size);
    QueryPerformanceCounter(&end);
    double asm_time = (double)(end.QuadPart - start.QuadPart) * 1000.0 / freq.QuadPart / RUNS;
    printf("ASM average time: %.4f ms\n", asm_time);

    printf("\n");

    // Print Values
    for (int k = 0; k < 5; k++)
        printf("[%d] input = %f   C = %f   ASM = %f\n",
            k + 1, arr1[k], arrC[k], arr2[k]);
    printf("...\n");
    for (int k = size - 5; k < size; k++)
        printf("[%d] input = %f   C = %f   ASM = %f\n",
            k + 1, arr1[k], arrC[k], arr2[k]);

    free(arr1); free(arrC); free(arr2);
    return 0;
}
