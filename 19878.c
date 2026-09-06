/*
问题描述
你需要实现一个队列，初始时队列为空。有 m 组查询，每次查询为以下
四种操作之一：

push x：向队尾插入一个正整数 x。
pop：删除队首元素，若此时队列为空，则不做任何操作。
empty：判断队列是否为空，若为空输出 YES，否则输出 NO。
query：输出队首元素，若队列为空则输出 empty。

输入格式
第一行输入一个正整数 m。(1≤m≤10^5 )

接下来 m 行，每行输入一种操作，对于 empty 与 query，需要有对应
的输出。push x 的 x 范围 (1≤x≤10^5 )。

输出格式
对于 empty 与 query 操作，按照题目要求输出。
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void push(Node** head, int value) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = NULL;
    if (*head == NULL) {
        *head = new_node;
    } else {
        Node* temp = *head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = new_node;
    }
}

void pop(Node** head) {
    if (*head == NULL) return;
    Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

int main(void) {
    Node* head = NULL;
    int m;
    scanf("%d", &m);

    char output[10000][10];
    int count = 0;

    for (int i = 0; i < m; i++) {
        char command[10];
        scanf("%s", command);
        if (strcmp(command, "push") == 0) {
            int value;
            scanf("%d", &value);
            push(&head, value);
        } else if (strcmp(command, "pop") == 0) {
            pop(&head);
        } else if (strcmp(command, "empty") == 0) {
            strcpy(output[count++], head == NULL ? "YES" : "NO");
        } else if (strcmp(command, "query") == 0) {
            if (head == NULL) {
                strcpy(output[count++], "empty");
            } else {
                sprintf(output[count++], "%d", head->data);
            }
        }
    }

    for (int i = 0; i < count; i++) {
        printf("%s\n", output[i]);
    }
    return 0;
}

/*
双端队列（Deque）
题目描述
维护一个双端队列，支持以下操作：

命令	        说明
push_front x	将整数 x 插入队头
push_back x	    将整数 x 插入队尾
pop_front	    弹出队头元素（若为空则忽略）
pop_back	    弹出队尾元素（若为空则忽略）
front	        输出队头元素（若为空输出 empty）
back	        输出队尾元素（若为空输出 empty）
size	        输出当前元素个数
empty	        队列为空输出 YES，否则输出 NO

输入格式
第一行一个正整数 m（1 ≤ m ≤ 10^5）。
接下来 m 行，每行一个命令，格式如上。

输出格式
所有需要输出的操作结果，按顺序每行一个，在所有输入读完之后统一输出。
*/
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node* prev;//上一个
    struct Node* next;//下一个
} Node;

Node* head = NULL;
Node* tail = NULL;
int cnt=0;

void push_front(int value){
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = value;
    new_node->prev = NULL;
    new_node->next = head;
    if(head!=NULL)head->prev=new_node;
    else tail=new_node;
    head = new_node;
    cnt++;
}

void push_back(int value){
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = NULL;
    new_node->prev = tail;
    if(tail!=NULL)tail->next=new_node;
    else head=new_node;
    cnt++;
}

void pop_front(){
    if(head==NULL)return;
    Node* temp = head;
    head = head->next;
    if(head!=NULL)head->prev=NULL;
    else tail=NULL;
    free(temp);
    cnt--;
}

void pop_back(){
    if(tail==NULL)return;
    Node* temp = tail;
    tail = tail->prev;
    if(tail!=NULL)tail->next=NULL;
    else head=NULL;
    free(temp);
    cnt--;
}

int main(void){
    int m;
    scanf("%d",&m);

    char res[100000][20];
    int count=0;

    for(int i=0;i<m;i++){
        char command[15];
        scanf("%s",command);
        if(strcmp(command,"push_front")==0){
            int value;
            scanf("%d", &value);
            push_front(value);
        }else if(strcmp(command,"push_back")==0){
            int value;
            scanf("%d", &value);
            push_back(value);
        }else if(strcmp(command,"pop_front")==0){
            pop_front();
        }else if(strcmp(command,"pop_back")==0){
            pop_back();
        }else if(strcmp(command,"front")==0){
            if (head == NULL) {
                strcpy(res[count++], "empty");
            } else {
                sprintf(res[count++], "%d", head->data);
            }
        }else if(strcmp(command,"back")==0){
            if(tail == NULL){
                strcpy(res[count++],"empty");
            }else{
                sprintf(res[count++],"%d",tail->data);
            }
        }else if(strcmp(command,"size")==0){
            sprintf(res[count++],"%d",cnt);
        }else if(strcmp(command,"empty")==0){
            strcpy(res[count++], head == NULL ? "YES" : "NO");
        }
    }

    for(int i=0;i<count;i++)
        printf("%s\n",res[i]);

    return 0;
}
*/