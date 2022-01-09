#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<stdbool.h>
#include<windows.h>

// Structure for storing candidate info and votes.
struct candidates{
    char name[10];
    char code;
    int votes;
};

// Helper
void space_provide(){
    for (int i = 0; i < 64; i++)
    {
        printf(" ");
    }
}

const int admin_key = 45987;

// To collect & verify ID of voter.
int idCheck(){
    
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
        if (countdupli==1)
        {
            fclose(duplicatettxt);
            space_provide();
            printf("You've already given vote. If think this is incorrect please contact authorities.");
            return 420;
        }
        else
        {
            fprintf(duplicatettxt, "%s\n", id);
            fclose(duplicatettxt);
            return 73;
        }
    }
    else
    {
        space_provide();
        printf("VOTER ID is does not exist. If think this is incorrect please contact authorities.");
        return 420;
    }
}

// To start the program and display instruction for admin.
int admin(){
    char a = 'A';
    space_provide();
    printf("Press Enter to start to the program_");
    while (a!='\n')
    {
      scanf("%c", &a);
    }
    system("cls");
    printf("\n\n\n\n\n\n");
    FILE *admin_instruction = NULL;
    char admin_line[100];
    admin_instruction = fopen("instruction_admin.txt", "r");
    space_provide();
    printf("    %c%c%c%c%c%c ADMIN INSTRUCTIONS %c%c%c%c%c%c\n",254,254,254,254,254,254,254,254,254,254,254,254,254,254);
    while (fgets(admin_line, 100, admin_instruction) != NULL)
    {
        space_provide();
        printf("%s", admin_line);
    }
    fclose(admin_instruction);
    printf("\n");
    space_provide();
    printf("Press Enter to continue_");
    a = 'A';
    while (a!='\n')
    {
      scanf("%c", &a);
    }
    system("cls");
    printf("\n\n\n\n\n\n\n\n");
    int key_entered;
    space_provide();
    printf("Enter the admin key: ");
    scanf("%d", &key_entered);
    int count=0;
    while (key_entered != admin_key)
    {
        system("cls");
        printf("\n\n\n\n\n\n\n\n");
        if (count==3)
        {
            space_provide();
            printf("Entering the key wrong again will cause system to shut.\n");
        }
        if (count==4)
        {
            return -69;
        }    
        space_provide();
        printf("Wrong key! Please enter again: ");
        scanf("%d", &key_entered);
        count++;
    }
    system("cls");
    printf("\n\n\n\n\n\n\n\n");
    int num_candidate=0;
    space_provide();
    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidate);
    if (num_candidate<2)
    {
        system("cls");
        printf("\n\n\n\n\n\n\n\n");
        space_provide();
        printf("Invalid input.\n");
        space_provide();
        printf("Enter the number of candidates: ");
        scanf("%d", &num_candidate);
    }
    system("cls");
    printf("\n\n\n\n\n\n\n\n");
    return num_candidate+1;
}

// Voter instruction display.
int voter_instruction(){
    FILE *voters_instructions = NULL;
    voters_instructions = fopen("first_display.txt", "r");
    space_provide();
    printf("    %c%c%c%c%c%c VOTER INSTRUCTIONS %c%c%c%c%c%c\n",254,254,254,254,254,254,254,254,254,254,254,254,254,254);
    char voter_line[100];
    while (fgets(voter_line, 100, voters_instructions) != NULL)
    {
        space_provide();
        printf("%s", voter_line);
    }
    fclose(voters_instructions);
    printf("\n");
    char a = 'A';
    space_provide();
    scanf("%c", &a);
    if (a=='q' || a=='Q')
    {
        return -6565;
    }
    while (a!='\n')
    {
        scanf("%c", &a);
    }
    system("cls");
    printf("\n\n\n\n\n\n\n\n");
    return -89;
}

// To allow voter to vote.
void vote(struct candidates info[], int num_candidate){
    bool flag = true;
    char codeForVote;
    for (int i = 0; i < num_candidate; i++)
    {
        space_provide();
        printf("%s: ", info[i].name);
        printf("%c", info[i].code);
        printf("\n");
    }
    space_provide();
    printf("Enter the code of candidate who you want to vote for: ");
    scanf("%c", &codeForVote);
    for (int i = 0; i < num_candidate && flag; i++)
    {
        if (codeForVote == info[i].code)
        {
            ++info[i].votes;
            flag = false;
        }
    }
}

// Exiting the program.
int exitControl(){
    system("cls");
    printf("\n\n\n\n\n\n\n\n");
    int key_entered;
    char a ='A';
    system("color 47");
    space_provide();
    printf("Enter the admin key to close the voting process: ");
    scanf("%d", &key_entered);
    fflush(stdin);
    if(key_entered != admin_key)
    {  
        system("cls");
        printf("\n\n\n\n\n\n\n\n");
        space_provide();
        printf(" Key is wrong. You are not authorized to stop the voting process.");
        printf("\n");
        space_provide();
        printf("Please contact authorities");
        printf("\n");
        space_provide();
        printf("Enter the admin key: ");
        scanf("%d", &key_entered);
        int count=0;
        while (key_entered != admin_key)
        {
            system("cls");
            printf("\n\n\n\n\n\n\n\n");
            if (count==3)
            {
                space_provide();
                printf("Entering the key wrong again will cause system to shut.\n");
            }
            if (count==4)
            {
                return -69;
            }    
            space_provide();
            printf("Wrong key! Please enter again: ");
            scanf("%d", &key_entered);
            count++;
        }
        // Redirecting screen

        system("color b0");
        system("cls");
        printf("\n\n\n\n\n\n\n\n");
        return -23451;
    }
    else
    {
        return -7778;
    }
}

int main(){	
    system("cls");
    printf("\n\n\n\n\n\n\n\n");
    system("color b0");
    int num_candidate;
    // calling the function for all admin related stuff
    num_candidate = admin();
    // If the admin key is entered wrong 4 times then program will close
    if (num_candidate==-69)
    {
        return 0;
    }
    // Taking the info for candidates.
    struct candidates info[num_candidate];
    int i;
    for (i = 0; i < num_candidate-1; i++)
    {
        fflush(stdin);
        printf("\n");
        space_provide();
        printf("%d.\n", i+1);
        space_provide();
        printf("Name of candidate = ");
        gets(info[i].name);
        fflush(stdin);
        space_provide();
        printf("Code for the candidate = ");
        scanf("%c", &info[i].code);
        info[i].votes = 0;
    }
    // Adding NOTA option to already entered list
    strcpy(info[i].name, "NOTA");
    info[i].code = 'N';
    info[i].votes = 0;
    fflush(stdin);
    space_provide();
    printf("Press Enter to continue_");
    char a;
    a = 'A';
    while (a!='\n')
    {
    scanf("%c", &a);
    }
    system("cls");
    printf("\n\n\n\n\n\n");
    // Calling the function to display voter instructions 
    int backFromINstructions = 0;
    label:
    {
        backFromINstructions = voter_instruction();
        for (int i = 0; backFromINstructions == -89 ; i++)
        {
            space_provide();
            printf("Please enter the VOTER ID: ");
            int backFromCheck = 0;
            backFromCheck = idCheck();
            if (backFromCheck == 73)
            {
                // here we link function to allow voter to cast vote.
                vote(info, num_candidate);
                fflush(stdin);
                space_provide();
                printf("Your vote has been recorded press Enter to exit ");
                a = 'A';
                while (a!='\n')
                {
                    scanf("%c", &a);
                }
                system("cls");
                printf("\n\n\n\n\n\n");
            }
            else if (backFromCheck == 420)    
            {
                printf("\n");
                space_provide();
                printf("Please press Enter to continue.");
                char a = 'A';
                while (a!='\n')
                {
                    scanf("%c", &a);
                }
                system("cls");
                printf("\n\n\n\n\n\n");
            }
            backFromINstructions = voter_instruction();
        }
    }
    // }
    int exitValue = exitControl();
    if (exitValue == -23451)
    {
        goto label;
    }
    else
    {
        FILE *votePrinter = NULL;
        votePrinter = fopen("vote.txt", "w");
        for (int i = 0; i < num_candidate; i++)
        {
            fprintf(votePrinter, "%s", info[i].name);
            fprintf(votePrinter, ": %c", info[i].code);
            fprintf(votePrinter, "\n%d\n\n", info[i].votes);
        }
        fclose(votePrinter);
    }
    return 0;
}