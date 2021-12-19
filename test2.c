#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){	
    char name[20];
    FILE *ptr = NULL;
    ptr = fopen("names.txt", "r");
    for (int i = 0; i < 100; i++)
    {
        fgets(name, 20, ptr);
        printf("%c", name[strlen(name)-2]);
        printf("%d", strlen(name));
        printf("\n");
    }
    fclose(ptr);
    return 0;
}