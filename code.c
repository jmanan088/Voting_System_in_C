#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<stdbool.h>

// To collect & verify ID of user.
void idCheck(){
    
    char linr[8];
    int countid=0, countdupli = 0;
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
            countid=1;
            break;
        }
    }
    while(fgets(linr, 10, duplicatettxt))
    {
        char *temp = NULL;
        temp = strstr(linr,id);
        if (temp!=NULL)
        {
            countdupli=1;
            break;
        }
    }
    fclose(idtxt);
    if (countid==1)
    {
        printf("yes1");
        if (countdupli==1)
        {
            fclose(duplicatettxt);
            printf("You've already given vote. If think this is incorrect please contact authorities.");
        }
        else
        {
            fprintf(duplicatettxt, "%s\n", id);
            fclose(duplicatettxt);
            printf("yes2");
            // here we link function to allow voter to cast vote.
        }
    }
    else
    {
        printf("no1");
        // Here we will link another function for display of voter instruction scene.
    }
}

int main(){	
    idCheck();
    return 0;
}