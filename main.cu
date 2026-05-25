#include<cstdio>
#include<cuda_runtime.h>
#include "cuda/add_array.cuh"
__global__ void kernel(){
    printf("hello from gpu\n");
}

int main(){
    kernel<<<1, 1>>>();
    cudaDeviceSynchronize();
    return 0;
}