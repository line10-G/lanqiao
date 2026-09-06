/*
问题描述
给定一个集合与 q 次操作，每次操作具体如下：
I x：在集合中插入一个值为 x 的数。
Q x：查询 x 是否在集合中出现过。

输入格式
第一行输入一个正整数 q，表示查询次数。(1≤q≤10^5)

接下来 q 行，每行输入代表依次进行一个操作。(1≤x≤10^9)

输出格式
对于每组查询，如果 x 出现过， 则输出 Yes，否则输出 No。
*/

//数组模拟链表
#include <stdio.h>
#include <string.h>

#define HASH_SIZE 100003  // 哈希表大小（质数）
#define MAX_NODES 100000  // 最大插入次数

// 静态链表（数组模拟）
int head[HASH_SIZE];   // 每个哈希桶的头节点下标，-1表示空
int val[MAX_NODES];    // 节点的值
int next[MAX_NODES];   // 节点的下一个节点下标
int idx = 0;           // 当前可用节点下标

// 哈希函数
int hash(int value) {
    // 处理负数：取模后加模数再取模
    return ((value % HASH_SIZE) + HASH_SIZE) % HASH_SIZE;
}

// 插入操作（头插法）
void insert(int value) {
    int h = hash(value);
    val[idx] = value;
    next[idx] = head[h];
    head[h] = idx;
    idx++;
}

// 查询操作
int query(int value) {
    int h = hash(value);
    int cur = head[h];
    while (cur != -1) {
        if (val[cur] == value) {
            return 1;  // 找到
        }
        cur = next[cur];
    }
    return 0;  // 未找到
}

int main(void) {
    // 初始化所有哈希桶为空
    memset(head, -1, sizeof(head));

    int q;
    scanf("%d", &q);

    char res[100000][4];  // 存储结果
    int count = 0;

    for (int i = 0; i < q; i++) {
        char command[2];
        scanf("%s", command);

        if (strcmp(command, "I") == 0) {
            int value;
            scanf("%d", &value);
            insert(value);
        } else if (strcmp(command, "Q") == 0) {
            int value;
            scanf("%d", &value);
            if (query(value)) {
                strcpy(res[count++], "Yes");
            } else {
                strcpy(res[count++], "No");
            }
        }
    }

    // 输出所有结果
    for (int i = 0; i < count; i++) {
        printf("%s\n", res[i]);
    }

    return 0;
}

/*
//链表
#include <stdio.h>
#include <stdlib.h>  // malloc 需要这个头文件
#include <string.h>

#define HASH_SIZE 100003

typedef struct Node {
    int value;
    struct Node* next;
} Node;

Node* hashTable[HASH_SIZE];  // 原来是 int 数组，改成 Node* 数组

int hash(int value) {
    return ((value % HASH_SIZE) + HASH_SIZE) % HASH_SIZE;  // 处理负数
}

int main(void) {
    // 初始化所有桶为 NULL
    memset(hashTable, 0, sizeof(hashTable));

    int q;
    scanf("%d", &q);

    char res[100000][4];
    int count = 0;

    for (int i = 0; i < q; i++) {
        char command[2];
        scanf("%s", command);

        if (strcmp(command, "I") == 0) {
            int value;
            scanf("%d", &value);
            int h = hash(value);

            // 头插法：新节点指向当前头，更新头
            Node* newNode = (Node*)malloc(sizeof(Node));
            newNode->value = value;
            newNode->next = hashTable[h];
            hashTable[h] = newNode;

        } else if (strcmp(command, "Q") == 0) {
            int value;
            scanf("%d", &value);      // 先读 value
            int h = hash(value);      // 再算 hash

            Node* cur = hashTable[h];
            int found = 0;
            while (cur != NULL) {     // 遍历链表，不只是检查头
                if (cur->value == value) {
                    found = 1;
                    break;
                }
                cur = cur->next;
            }
            strcpy(res[count++], found ? "Yes" : "No");
        }
    }

    for (int i = 0; i < count; i++) {
        printf("%s\n", res[i]);
    }

    return 0;
*/
/*
题目描述
给定 n 个操作，支持以下三种操作：
I x：向集合中插入字符串 x
Q x：查询字符串 x 是否在集合中，输出 Yes / No
D x：从集合中删除字符串 x（如果存在）

输入格式
第一行一个整数 n（1 ≤ n ≤ 10^5）
接下来 n 行，每行一个操作，格式为 I x、Q x 或 D x
字符串 x 长度不超过 50，只包含小写字母

输出格式
对于每个 Q 操作，输出一行 Yes 或 No
*/
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char* s;
    struct Node* next;
} Node;

#define HASH_SIZE 100003

Node* hashTable[HASH_SIZE];
char res[100000][4]={0};
int count=0;

unsigned long long hashStr(const char* s){
    unsigned long long h = 0;
    for(int i=0;s[i]!='\0';i++){
        h = h*26+(s[i]-'a'+1);
    }
    return h % HASH_SIZE;
}

void insert(char* s){
    int hashvalue = hashStr(s);
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->s = (char*)malloc(strlen(s)+1);
    strcpy(newNode->s,s);
    newNode->next = hashTable[hashvalue];
    hashTable[hashvalue] = newNode;
}

void query(char* s){
    int hashValue = hashStr(s);
    Node* temp = hashTable[hashValue];
    while(temp!=NULL){
        if(strcmp(temp->s,s)==0){
            strcpy(res[count++],"YES");
            return;
        }
        temp = temp->next;
    }
    strcpy(res[count++],"NO");
}

void delete(char* s){
    int hashValue = hashStr(s);
    Node* cur = hashTable[hashValue];
    Node* prev = NULL;
    while(cur!=NULL){
        if(strcmp(cur->s,s)==0){
            if(prev==NULL){
                hashTable[hashValue] = cur->next;
            }else{
                prev->next = cur->next;
            }
            free(cur->s);
            free(cur);
            return;
        }
    prev = cur;
    cur = cur->next;
    }
}

int main(void){
    int n;
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        char command[2];
        scanf("%s",command);
        if(strcmp(command,"I")==0){
            char s[50];
            scanf("%s",s);
            insert(s);
        }else if(strcmp(command,"Q")==0){
            char s[50];
            scanf("%s",s);
            query(s);
        }else if(strcmp(command,"D")==0){
            char s[50];
            scanf("%s",s);
            delete(s);
        }
    }

    for(int i=0;i<count;i++){
        printf("%s\n",res[i]);
    }

    return 0;
}
*/
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_SIZE 100003
#define MAX_NODE 100000

int hashTable[HASH_SIZE];
char* value[MAX_NODE];
int next[MAX_NODE];
int idx = 0;

unsigned long long hashStr(char* s){
    unsigned long long hashValue = 0;
    for(int i=0;s[i]!='\0';i++){
        hashValue = hashValue * 26 + (s[i]-'a'+1);
    }
    return hashValue % HASH_SIZE;
}

void insert(char* s){
    unsigned long long hashValue = hashStr(s);
    value[idx] = (char*)malloc(strlen(s) + 1);
    strcpy(value[idx],s);
    next[idx] = hashTable[hashValue];
    hashTable[hashValue] = idx;
    idx++;
}

int query(char* s){
    unsigned long long hashValue = hashStr(s);
    int cur = hashTable[hashValue];
    while(cur!=-1){
        if(strcmp(value[cur],s)==0){
            return 1;
        }
        cur = next[cur];
    }
    return 0;
}

void delete(char* s){
    unsigned long long hashValue = hashStr(s);
    int cur = hashTable[hashValue];
    int prev = -1;
    while(cur != -1){
        if(strcmp(value[cur],s)==0){
            if(prev == -1){
                hashTable[hashValue] = next[cur];
            }else{
                next[prev] = next[cur];
            }
            free(value[cur]);
            return;
        }
        prev = cur;
        cur = next[cur];
    }
}

int main(void){
    memset(hashTable,-1,sizeof(hashTable));
    char res[100000][4];
    int count=0;

    int n;
    scanf("%d",&n);
    
    for(int i=0;i<n;i++){
        char command[2];
        scanf("%s",command);
        char s[50];
        scanf("%s",s);
        if(strcmp(command,"I")==0){
            insert(s);
        }else if(strcmp(command,"Q")==0){
            if(query(s)){
                strcpy(res[count++],"Yes");
            }else{
                strcpy(res[count++],"No");
            }
        }else if(strcmp(command,"D")==0){
            delete(s);
        }
    }

    for(int i=0;i<=count;i++){
        printf("%s\n",res[i]);
    }

    return 0;
}
*/