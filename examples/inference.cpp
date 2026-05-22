#include<iostream>

void launch_kernel();

int main(){
    std::cout<<"Launched gpu kernel\n";
    launch_kernel();
    std::cout<<"complete\n";
    return 0;
}