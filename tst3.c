#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int inp(){
    int n;
    scanf("%d", &n);
    return n;
}

int increase(int n){
    return ++n;
}

int main(){	
    printf("%d", increase(inp()));
    return 0;
}