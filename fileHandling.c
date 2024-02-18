#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct studentInfo{
    char id[30];
    char name[30];
    char date[10];
    float cgpa;
};

void push(struct studentInfo stack[100], int top ,struct studentInfo s){
    stack[top] = s;
}

struct studentInfo pop(struct studentInfo stack[100], int top){
    return stack[top--];
}


void getSection(char section[4][100], char line[100]){
    int word = 0, begin = 0;
    for (int i = 0 ; i < 99 ; i++){
        if (line[i+1] == ' ' || i == strlen(line)-1){
            for (int j = begin; j <= i ; j++)
                section[word][j-begin] = line[j];
            // printf("%s", section[word]);ṇ
            word++;begin = i+2; 
        }
    }
}
void main(){
    char line[100];
    struct studentInfo arr[100];
    FILE* file = fopen("inputfile.txt", "r");
    char sections[4][100];
    int lineNumber = 0;

    int top = -1;
    while (fgets(line,100,file) != NULL){
        getSection(sections, line);
        struct studentInfo s;
        strcpy(s.id,sections[0]);
        strcpy(s.name,sections[1]);
        strcpy(s.date,sections[2]);
        s.cgpa = atof(sections[3]);
        push(arr,++top,s);
    }

    struct studentInfo s = pop(arr,top);

}