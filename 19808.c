/*
问题描述
给定一个由 0 和 1 组成的字符串 S，你需要根据以下规则修改字符串
的最后一个字符：
如果 S 的最后一个字符是 0，则将其替换为 1。
如果 S 的最后一个字符是 1，则将其替换为 0。
现在，请你输出修改后的字符串。

输入格式
输入一行，包含一个仅由字符 0、1 组成字符串 S。
数据保证字符串的长度为 1 到 100 之间的整数。

输出格式
输出修改后的字符串。
*/

#include <stdio.h>
#include <string.h>

int main(void){
    char S[101] = {0};
    scanf("%s", S);
    int len = strlen(S);
    if(len > 0){
        S[len-1] = (S[len-1] == '1') ? '0' : '1';
    }
    printf("%s\n", S); 
    
    return 0;
}

/*
问题描述
给定一个由 0 和 1 组成的字符串 S（长度不超过 100），你需要：
将字符串中奇数位置（从 1 开始计数）的字符翻转（0 变 1，1 变 0）
将翻转后的字符串倒序输出
如果翻转后的字符串中 1 的数量是偶数，在末尾追加一个 '0'，否则追
加一个 '1'

输入格式：
一行，一个只含 0 和 1 的字符串

输出格式：
一行，处理后的字符串
*/
/*
#include <stdio.h>
#include <string.h>

int main(void){
    char S[101]={0};
    scanf("%s",S);
    int len = strlen(S);
    for(int i=0;i<len;i+=2){
        S[i] = S[i]=='1'?'0':'1';
    }
    int count = 0;
    for(int j=len-1;j>=0;j--){
        printf("%c",S[j]);
        if(S[j]=='1'){
            count++;
        }
    }
    printf("%c\n", (count % 2 == 0) ? '0' : '1');

    return 0;
}
*/