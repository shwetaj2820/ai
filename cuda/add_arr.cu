#include<cstdlib>
#include<iostream>
using namespace std;

__global__ void add_arr(int*a, int*b, int*c, int N){
    // global thread id-
    int id = blockIdx.x * blockDim.x + threadIdx.x;
    if(id<N){
        c[id] = a[id] + b[id];
        cout<<c[id];
    }
}

void init_array(int*a, int N){
    for(int i=0; i<N; i++)a[i]=rand()%100;
}

int main(){
    int N = 1<<20;
    size_t byte = N * sizeof(byte);
    int *a, *b, *c;

    cudaMallocManaged(&a, byte);
    cudaMallocManaged(&b, byte);
    cudaMallocManaged(&c, byte);

    init_array(a, N);
    init_array(b, N);

    // initialize grid dim. -
    int THREADS = 256;
    int BLOCKS = (N+THREADS-1)/THREADS;

    // calling kernel-
    add_arr<<<BLOCKS, THREADS>>>(a, b, c, N);
    cudaDeviceSynchronize();
    return 0;
}

