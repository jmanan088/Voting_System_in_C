/* For genrating the voter id of citizens. */
// All letters in ID in capital letters
// 1. First letter of the name 
// 2. Number of letter in name like 1if 4 letters then D similarly 1-A 2-B 3-C 4-D 5-E 6-F 7-G 8-H so on...
// 3. 4 letter code unique for everyone...like serial number if S.No. = 1 then AAAA IF S.No = 26 then AAAZ then for 27 AABA....  
// 4. Last letter of name 

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

int main(){	
    char name[20], id[10];
    int n;
    FILE *ptr = NULL;
    FILE *ptr2 = NULL;
    ptr= fopen("id.txt", "a");
    ptr2= fopen("names.txt", "r"); 
    id[2]= 'A';
    id[3]= 'A';
    id[4]= 'A';
    id[5]= 64;
    id[7]= '\n';
    id[8]= '\0';
    for (int i = 0; i <=100; i++)
    {
        fgets(name, 20, ptr2);
        n= strlen(name);
        fprintf(ptr, "%s", name);
        id[0] = name[0];
        id[6]= name[n-2];
        id[6]-= 32; 
        n=(n-2)+65;
        id[1]= n;
        if (id[5]=='Z')
        {
            id[5]= 'A';  
            if (id[4]=='Z')
            {
                id[4]= 'A';
                if (id[3]=='Z')
                {
                    id[3]= 'A';
                    id[7]+=1; 
                }
                else{id[3]+=1;} 
            }
            else{id[4]= id[4]+1;} 
        }
        else{id[5]+=1;}
        fprintf(ptr, "%c", id[0]);
        fprintf(ptr, "%c", id[1]);
        fprintf(ptr, "%c", id[2]);
        fprintf(ptr, "%c", id[3]);
        fprintf(ptr, "%c", id[4]);
        fprintf(ptr, "%c", id[5]);
        fprintf(ptr, "%c", id[6]);
        fprintf(ptr, "%c", id[7]);
    }
    fclose(ptr);
    fclose(ptr2);
    return 0;
}