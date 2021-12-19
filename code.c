#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<stdbool.h>

// To collect user ID.
// char *idCollect(){ 
    
//     return id;
// }

// To collect & verify ID of user.
void idCheck(){

    char linr[8];
    int count=0;
    char id[8];
    gets(id);
    FILE *idtxt = NULL;
    FILE *duplicatettxt = NULL;
    idtxt = fopen("id.txt", "r");
    duplicatettxt = fopen("duplicate.txt", "a+");
    while(fgets(linr, 10, idtxt))
    {
        char *temp = NULL;
        temp = strstr(linr,id);
        if (temp!=NULL)
        {
            count=1;
            break;
        }
    }
    if (count==1)
    {
        printf("yes");
    }
    else{printf("no");}
    fclose(idtxt);
    fclose(duplicatettxt);
}

int main(){	
    idCheck();
    return 0;
}