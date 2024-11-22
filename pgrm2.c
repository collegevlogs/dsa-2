#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int IPV(char ch){
    if(ch=='+'||ch=='-')return 1;
    if(ch=='*'||ch=='/')return 3;
    if(ch=='(')return 9;
    if(ch==')')return 0;
    if(ch=='^')return 6;
    return 7;
}
int SPV(char ch){
    if(ch=='+'||ch=='-')return 2;
    if(ch=='*'||ch=='/')return 4;
    if(ch=='#')return -1;
    if(ch=='(')return 0;
    if(ch=='^')return 5;
    return 8;
}
void push(char s[10],int *top,char item){
    *top=*top+1;
    s[*top]=item;
}
char pop(char s[10],int *top){
    char item=s[*top];
    *top=*top-1;
    return item;
}
int main(){
    char in[20],post[20],ch,s[10];
    int i,j=0,top=-1;
    printf("Enter the valid infix Expression:");
    scanf("%s",in);
    push(s,&top,'#');
    for(i=0;i<strlen(in);i++){
        ch=in[i];
        while(IPV(ch)<SPV(s[top]))
        post[j++]=pop(s,&top);
        if(IPV(ch)>SPV(s[top]))
        push(s,&top,ch);
        else
        pop(s,&top);
     
    }
    while(s[top]!='#')
    post[j++]=pop(s,&top);
    post[j]='\0';
    printf("\n Converted postfix Experssion is %s",post);
    return 0;
}