#include<cstdio>
#include<cuda_runtime.h>
#pragma once 
void launch_add_kernel(int* d_a, int* d_b, int* d_c, int n);
__global__ void add_array(int*a, int*b, int*c, int n){
    int i = blockDim.x * blockIdx.x + threadIdx.x;

    if(i<n)c[i]=a[i]+b[i];
}

void launch_kernel(){
    int n = 8;
    int a[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    int b[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    int c[8];

    // gpu memory:
    int *d_a, *d_b, *d_c;
    
    cudaMalloc(&d_a, n*sizeof(int));
    cudaMalloc(&d_b, n*sizeof(int));
    cudaMalloc(&d_c, n*sizeof(int));
    
    // cpu to gpu :
    cudaMemcpy(d_a, a, n*sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(d_b, b, n*sizeof(int), cudaMemcpyHostToDevice);

    add_array<<<1, 8>>>(d_a, d_b, d_c, n);
    cudaDeviceSynchronize();

    // gpu to cpu
    cudaMemcpy(c, d_c, n*sizeof(int), cudaMemcpyDeviceToHost);

    for(int i=0; i<n; i++)printf("%d", c[i]);
    printf("\n");

    // free mem:
    cudaFree(d_a);
    cudaFree(d_b);
    cudaFree(d_c);
}

int main(){
    launch_kernel();
    return 0;
}