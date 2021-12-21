#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<stdbool.h>

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
        printf("yes1");
        count=0;
        while(fgets(linr, 10, duplicatettxt))
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
            printf("You've already given vote. If think this is incorrect please contact authorities.");
        }
        else
        {
            fprintf(duplicatettxt, "%s\n", id);
            printf("yes2");
            // here we link function to allow voter to cast vote.
        }
        
    }
    else
    {
        printf("no1");
        // Here we will link another function for display of voter instruction scene.
    }
    fclose(idtxt);
    fclose(duplicatettxt);
}

int main(){	
    idCheck();
    return 0;
}