#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

int main(){	
    char linr[100], id[10];
    int count=0;
    gets(id);
    FILE *ptr= NULL;
    ptr=fopen("id.txt", "r");
    while(fgets(linr, 10, ptr))
    {
        char *ptr2 = strstr(linr,id);
        if (ptr2!=NULL)
        {
            count=1;
            break;
        }
    }
    fclose(ptr);
    if (count==1)
    {
        printf("yes");
    }
    else{printf("no");}
    return 0;
}