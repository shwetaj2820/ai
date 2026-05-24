#include<cstdio>
#include<cuda_runtime.h>
__global__ void kernel_program(){
    printf("hello from thread %d\n", threadIdx.x);
}

void launch_kernel(){
    kernel_program<<<1, 8>>>();
    cudaDeviceSynchronize();
}