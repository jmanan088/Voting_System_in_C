#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<stdbool.h>

// To collect user ID.
int idCollect(){ 
    char id[7];
    gets(id);
    getchar();
    return id;
}

// To verify ID of user.
int idCheck(int id){

    FILE *idtxt = NULL;
    FILE *duplicatettxt = NULL;
    idtxt = fopen("id.txt", "r");
    duplicatettxt = fopen("duplicate.txt", "a+");
    

}





int main(){	
    
    return 0;
}