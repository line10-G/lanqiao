/*
问题描述
小蓝最近喜添一只可爱的小猫，正为给它取一个长度恰好为 6 的名字而绞
尽脑汁。为了集思广益，他邀请了 6 位朋友帮忙，每位朋友各自想一个单
词。小蓝计划将这 6 个单词的首字母按顺序拼接起来，组成小猫的名字。
朋友们提供的单词分别记为 W1,W2,W3,W4,W5,W6 。例如，朋友们提供的
单词依次是 agile，brave，cute，delightful，energetic，fluffy，
那么小猫的名字将是 "abcdef"。
现在，请你编写一个程序，根据朋友们提供的单词，生成小猫的名字。

输入格式
输入共 6 行，每行包含一个长度不超过 10、仅由小写字母构成的字符串，
表示朋友提供的单词。

输出格式
输出一个长度为 6 的字符串，表示小猫的名字。
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    char str[12];
    char res[7]={0};
    int i;
    for(i=0;i<6;i++){
        scanf("%s",str);
        res[i] = str[0];
    }
    printf("%s\n",res);

    return 0;
}

/*
问题描述
小蓝最近在为自己的账号设计一个安全密码。他有一套特殊的密码生成规
则：
首先，小蓝准备了 n 个单词，按顺序编号为 W1,W2,…,Wn。然后他会给
出一个长度为 n 的指令串 S，只由三种字符组成：
F（Front）：取该单词的首字母
B（Back）：取该单词的末字母
A（All）：取该单词的全部字母
将每次取到的内容按顺序拼接起来，就构成了最终的密码。但密码不能太
长——如果拼接后的总长度超过 L，则只保留前 L 个字符，后面的全部截
断。如果拼接后总长度不足 L，则不作任何补充。

输入格式
第一行包含两个整数 n 和 L，分别表示单词数量和密码最大长度。
(1≤n≤100,1≤L≤1000)
接下来 n 行，每行一个长度不超过 20、仅由小写字母构成的单词 Wi。
第 n+2 行包含一个长度为 n 的字符串 S，由 F、B、A 三种字符组成，
表示对每个单词的取字指令。

输出格式
输出一行字符串，表示最终生成的密码。
*/
/*
#include <stdio.h>
#include <string.h>

int main(void){
    int n,L;
    scanf("%d %d" ,&n ,&L);

    int i;
    char words[100][20]={0};
    for(i=0;i<n;i++){
        scanf("%s",words[i]); 
    }

    char pswd[100]={0};
    scanf("%s",pswd);

    char res[1001]={0};
    for(i=0;i<n;i++){
        switch(pswd[i]){
            case 'F':
                res[strlen(res)] = words[i][0];
                break;
            case 'B':
                res[strlen(res)] = words[i][ strlen(words[i]) - 1 ];
                break;
            case 'A':
                strcat(res,words[i]);
                break;
        }
    }
    if(strlen(res)>L){
        res[L] = '\0';
    }
    printf("%s",res);

    return 0;
}
*/
/*
问题描述
小蓝最近收到了一封神秘密码信，信中有 n 行文字，每行是一个句子。
小蓝发现，将每行句子的第一个单词的首字母和最后一个单词的首字母
按顺序拼接起来，就能得到隐藏的密文。
具体来说，每行句子由若干个单词组成，单词之间用空格分隔。对于每
行句子，取出：
该行第一个单词的首字母
该行最后一个单词的首字母
将这 2n 个字母按顺序拼接，就得到密文。

输入格式
第一行一个整数 n，表示句子行数。(1≤n≤100)
接下来 n 行，每行一个句子。每个句子由若干个仅由小写字母构成的
单词组成，单词之间用单个空格分隔，每行长度不超过 100。保证每行
至少有一个单词。

输出格式
输出一个字符串，表示解码后的密文。
*/
/*
#include <stdio.h>
#include <string.h>

int main(void){
    int n;
    scanf("%d", &n);
    getchar();  // 吃掉 scanf 残留的换行符

    int i;
    char str[101]={0};
    char res[201]={0};
    for(i=0;i<n;i++){
        fgets(str, 101, stdin);          // 读整行（含空格）
        str[ strcspn(str, "\n") ] = '\0'; // 去掉末尾的换行符
        res[strlen(res)] = str[0];
        int last_space = -1;
        int j;
        for (j = 0; str[j] != '\0'; j++) {
            if (str[j] == ' ')
                last_space = j;
        }
        res[ strlen(res) ] = str[last_space + 1];
    }
    printf("%s",res);

    return 0;
}
*/