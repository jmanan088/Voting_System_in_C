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

const int admin_key = 42069;

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
            printf("You've already given vote. If think this is incorrect please contact authorities.");
            return 420;
        }
        else
        {
            fprintf(duplicatettxt, "%s\n", id);
            fclose(duplicatettxt);
            return 69;
        }
    }
    else
    {
        printf("VOTER ID is does not exist. If think this is incorrect please contact authorities.");
        return 420;
    }
}

// To start the program and display instruction for admin.
int admin(){
    char a = 'A';
    printf("Press Enter to start to the program_");
    while (a!='\n')
    {
      scanf("%c", &a);
    }
    system("cls");
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
    a = 'A';
    while (a!='\n')
    {
      scanf("%c", &a);
    }
    system("cls");
    int key_entered;
    printf("Enter the admin key: ");
    scanf("%d", &key_entered);
    while (key_entered != admin_key)
    {
        system("cls");
        printf("Wrong key! Please enter again: ");
        scanf("%d", &key_entered);
    }
    system("cls");
    int num_candidate=0;
    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidate);
    if (num_candidate<2)
    {
        system("cls");
        printf("Invalid input.\n");
        printf("Enter the number of candidates: ");
        scanf("%d", &num_candidate);
    }
    system("cls");
    return num_candidate;
}

// Voter instruction display.
int voter_instruction(){
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
    char a = 'A';
    if (a=='q' || a=='Q')
    {
        return -6565;
    }
    while (a!='\n')
    {
        scanf("%c", &a);
    }
    system("cls");
    return -89;
}

// To allow voter to vote.
void vote(struct candidates info[], int num_candidate){
    bool flag = true;
    char codeForVote;
    for (int i = 0; i < num_candidate; i++)
    {
        printf("%s: ", info[i].name);
        printf("%c", info[i].code);
        printf("\n");
    }
    printf("Enetr the code of candidate who you want to vote for: ");
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

int exitControl(){
    system("cls");
    int key_entered;
    char a ='A';
    printf("Enter the admin key to close the voting process: ");
    scanf("%d", &key_entered);
    if(key_entered != admin_key)
    {  
        system("cls");
        printf("Key is wrong. You are not authorized to stop the voting process.");
        printf("\n Press Enter to go back_");
        while (a!='\n')
        {
            scanf("%c", &a);
        }
        system("cls");
        return -23451;
    }
    else
    {
        return -7778;
    }
    
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
        scanf("%c", &info[i].code);
        info[i].votes = 0;
        printf("\n");
    }
    printf("Press Enter to continue_");
    char a;
    a = 'A';
    while (a!='\n')
    {
      scanf("%c", &a);
    }
    system("cls");
    // Calling the function to display voter instructions 
    int backFromINstructions = 0;
    label:
    {
        backFromINstructions = voter_instruction();
        for (int i = 0; backFromINstructions = -89 ; i++)
        {
            printf("Please enter the VOTER ID: ");
            int backFromCheck = 0;
            backFromCheck = idCheck();
            if (backFromCheck == 69)
            {
                // here we link function to allow voter to cast vote.
                vote(info, num_candidate);
                printf("Your vote has been recorded press Enter to exit_");
                a = 'A';
                while (a!='\n')
                {
                    scanf("%c", &a);
                }
                system("cls");
                backFromCheck =  voter_instruction();
            }
            else if (backFromCheck == 420)    
            {
                printf("\nPlease press Enter to continue.");
                char a = 'A';
                while (a!='\n')
                {
                    scanf("%c", &a);
                }
                system("cls");
                backFromCheck = voter_instruction();
            }
        }
    }
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