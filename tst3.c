#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct stu
{
    char a;
    char b;
    int c;
};

void func(struct stu infa[],int num){
    ++infa[0].c;
    ++infa[1].c;
}

int main(){	
    int num=2;
    struct stu infa[num];
    scanf("%c %c %d", &infa[0].a, &infa[0].b, &infa[0].c);
    getchar();
    scanf("%c %c %d", &infa[1].a, &infa[1].b, &infa[1].c);
    func(infa, num);
    printf("%c %c %d", infa[0].a, infa[0].b, infa[0].c);
    printf("%c %c %d", infa[1].a, infa[1].b, infa[1].c);
    return 0;
}
/* 
A B 4
G H 5
A B 5G H 6 
*/