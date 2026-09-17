/*
问题描述
在音乐中，我们常常使用 “do re mi fa sol la si” 来表示音符，它们分
别对应着 C、D、E、F、G、A、B 这七个音名。其中，除了 EF 和 BC 
之间是半音之外，其他相邻的两个音符之间都是全音。
为了表达比某个音高半音的音，我们会在该音名的后面加上 “#” 符号，
例如比 C 高半音的音记作 C#，比 D 高半音的音记作 D#，比 F 高半
音的音记作 F#，比 G 高半音的音记作 G#，比 A 高半音的音记作 A#。
 由于 EF 之间是半音，因此 E 的升音就是 F；同样地，由于 BC 之间
 是半音，因此 B 的升音就是 C。
现在，给定一个音名 S，请你回答比 S 高半音的音名是什么。

输入格式
输入一个字符 S，由大写字母 C、D、E、F、G、A、B 之一组成。

输出格式
输出比 S 高半音的音名。
*/

#include <stdio.h>
#include <string.h>

int main(void){
    const char* yj[12] = {"C", "C#", "D", "D#", "E", "F",
                          "F#", "G", "G#", "A", "A#", "B"};

    char S[3];
    scanf("%2s",S);
    for(int i=0;i<12;i++){
        if(strcmp(S, yj[i]) == 0){
            if(i!=11){
                printf("%s",yj[i+1]);
            }else{
                printf("%s",yj[0]);
            }
            break;
        }
    }

    return 0;
}

/*
题目描述
给定一个音符（如 C#、F、B 等），以及一个整数 n，输出该音符在十
二平均律音阶中向后移动 n 个半音后的音符。
十二平均律音阶（从 C 开始）为：
C, C#, D, D#, E, F, F#, G, G#, A, A#, B

输入格式
第一行一个字符串，表示起始音符（可能包含 #，如 C#、F#）。
第二行一个整数 n，表示向后移动的半音数（n 可以为负数，表示向前
移动）。

输出格式
输出移动后的音符。
*/
/*
#include <stdio.h>
#include <string.h>

int main(void){
    const char* yj[12]={"C", "C#", "D", "D#", 
                        "E", "F", "F#", "G",
                        "G#", "A", "A#", "B"};
    char S[3];
    int n;
    scanf("%2s %d",S,&n);
    int i;
    for(i=0;i<12;i++){
        if(strcmp(S,yj[i])==0){
            break;
        }
    }
    if (i == 12) {
        printf("无效音符\n");
        return 1;
    }
    int loc = ((i + n) % 12 + 12) % 12;
    printf("%s",yj[loc]);

    return 0;
}
*/