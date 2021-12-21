#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<stdbool.h>

// Structure for storing candidate info and votes.
struct candidates{
    char name[10];
    char code;
    int votes;
};

// To collect & verify ID of voter.
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
        printf("VOTER ID is does not exist.\nPlease press Enter to continue.");
        char a = "A";
        while (a!="\n")
        {
            getchar(a);
        }
        system("clear");
        voter_instruction();
    }
}

// To start the program and display instruction for admin.
int admin(){
    char a = "A";
    printf("Press Enter to start to the program_");
    while (a!="\n")
    {
      getchar(a);
    }
    system("clear");
    FILE *admin_instruction = NULL;
    char admin_line[100];
    admin_instruction = fopen("instruction_admin.txt", "r");
    while (fgets(admin_line, 100, admin_instruction) != NULL)
    {
        printf("%s", admin_line);
    }
    fclose(admin_instruction);
    printf("\n");
    printf("Press Enter to continue_");
    a = "A";
    while (a!="\n")
    {
      getchar(a);
    }
    system("clear");
    int key_entered, admin_key = 42069;
    printf("Enter the admin key: ");
    scanf("%d", &key_entered);
    while (key_entered != admin_key)
    {
        system("clear");
        printf("Wrong key! Please enter again: ");
        scanf("%d", &key_entered);
    }
    system("clear");
    int num_candidate=0;
    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidate);
    if (num_candidate<2)
    {
        system("clear");
        printf("Invalid input.\n");
        printf("Enter the number of candidates: ");
        scanf("%d", &num_candidate);
    }
    system("clear");
    return num_candidate;
}

// Voter instruction display
void voter_instruction(){
    FILE *voters_instructions = NULL;
    voters_instructions = fopen("first_display.txt", "r");
    char voter_line[100];
    while (fgets(voter_line, 100, voters_instructions) != NULL)
    {
        printf("%s", voter_line);
    }
    fclose(voters_instructions);
    printf("\n");
    printf("Press Enter to continue_\n");
    printf("Or press Q to close the voting process_\n");
    char a = "A";
    if (a=="q" || a=="Q")
    {
        // Attach here the function to close application
    }
    while (a!="\n")
    {
        getchar(a);
    }
    system("clear");
}

int main(){	
    int num_candidate;
    // calling the fucntion for all admin related stuuf
    num_candidate = admin();
    // Taking the info for candidates.
    struct candidates info[num_candidate];
    for (int i = 0; i < num_candidate; i++)
    {
        gets(info[i].name);
        getchar();
        getchar(info[i].code);
        info[i].votes = 0;
        printf("\n");
    }
    printf("Press Enter to continue_");
    char a;
    a = "A";
    while (a!="\n")
    {
      getchar(a);
    }
    system("clear");
    // Calling the function to display voter instructions 
    voter_instruction();
    printf("Please enter the VOTER ID: ");
    idCheck();
    return 0;
}