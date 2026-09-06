/*
问题描述
你需要实现一个栈，初始时栈为空。有 m 组查询，每次查询为以下四
种操作之一：
push x：向栈顶插入一个正整数 x。
pop：删除栈顶元素，若此时栈为空，则不做任何操作。
empty：判断栈是否为空，若为空输出 YES，否则输出 NO。
query：输出栈顶元素，若栈为空则输出 empty。

输入格式
第一行输入一个正整数 m。(1≤m≤10^5)

接下来 m 行，每行输入一种操作，对于 empty 与 query，需要有对
应的输出。push x 的 x 范围 (1≤x≤10^5)。

输出格式
对于 empty 与 query 操作，按照题目要求输出。
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

void push(Node** head,int value){
    Node* new_Node = (Node*)malloc(sizeof(Node));
    new_Node->data = value;
    new_Node->next = *head;
    *head = new_Node;
}

void pop(Node** head){
    if(*head==NULL)return;
    Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

int main(void){
    Node* head = NULL;

    int m;
    scanf("%d",&m);

    char res[100000][12];
    int count=0;
    for(int i=0;i<m;i++){
        char command[10];
        scanf("%s",command);
        if(strcmp(command,"push")==0){
            int value;
            scanf("%d",&value);
            push(&head,value);
        }else if(strcmp(command,"pop")==0){
            pop(&head);
        }else if(strcmp(command,"empty")==0){
            strcpy(res[count++],head==NULL?"YES":"NO");
        }else if(strcmp(command,"query")==0){
            if(head==NULL){
                strcpy(res[count++],"empty");
            }else{
                sprintf(res[count++],"%d",head->data);
            }
        }
    }

    for(int i=0;i<count;i++){
        printf("%s\n",res[i]);
    }

    return 0;
}
