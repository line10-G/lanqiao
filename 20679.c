/*
问题描述
小蓝得到了一份编码文件，文件内容是一个由小写字母 a∼z 和数字 0∼9 
组成的字符串。他计划将字母替换为 L，数字替换为 Q，生成一份新的输
出文件，请你帮帮他。

输入格式
输入仅一行，包含一个仅由小写字母 a∼z 和数字0∼9 组成字符串，
长度不超过10^5。

输出格式
输出一行，为替换后的字符串。
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    char c;
        while((c = getchar()) != EOF && c != '\n') {
            if (c >= 'a' && c <= 'z') putchar('L');
            else putchar('Q');
        }
    putchar('\n');
    return 0;
}

/*
题目描述
给定一个由小写字母和数字组成的字符串，请将其中连续相同的字符压缩为「字符 + 出现次数」的形式。
若某字符只连续出现 1 次，则原样输出，不加次数。
若连续出现多次，则输出字符后紧跟次数。

输入格式
输入一行，仅含小写字母 a~z 和数字 0~9，长度不超过 10^5。

输出格式
输出压缩后的字符串。
*/
/*
#include <stdio.h>

int main(void) {
    int c;
    char lc = '\n';
    int count = 0;
    while ((c = getchar()) != EOF && c != '\n') {
        if (c == lc) {
            count += 1;
        } else {
            if (count > 1) {
                printf("[%d]", count);
            }
            putchar(c);
            count = 1;
        }
        lc = c;
    }
    if (count > 1) {
        printf("[%d]", count);
    }
    return 0;
}
*/

