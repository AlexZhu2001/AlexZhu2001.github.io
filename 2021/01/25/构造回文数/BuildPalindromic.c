#include <stdio.h>
#include <string.h>
#define  MAX_COUNT 1050

char num[MAX_COUNT]={0};
char rev[MAX_COUNT]={0};

void reverse(char *src,char *dst,int c){
    for(int i=0,j=c-1;i<c;i++,j--){
        dst[j]=src[i];
    }
}
void add(char *a,char *b,int c){
    int flag=0,num1,num2,sum;
    for(int i=c-1;i>=0;i--){
        num1=a[i]-'0';
        num2=b[i]-'0';
        sum=num1+num2+(flag?1:0);
        if(sum>9){
            sum-=10;
            flag=1;
        }else{
            flag=0;
        }
        a[i]=sum+'0';
    }
    if(flag){
        for(int i=c;i>0;i--){
            num[i]=num[i-1];
        }
        num[0]='1';
    }
}
int isCorrect(char *num,int c){
    int l=0,r=c-1;
    while(l<r){
        if(num[l]!=num[r]) return 0;
        l++;
        r--;
    }
    return 1;
}
int main() {
    scanf("%s",num);
    for(int i=0;i<10;i++){
        reverse(num,rev,strlen(num));
        printf("%s + %s = ",num,rev);
        add(num,rev,strlen(num));
        printf("%s\n",num);
        if(isCorrect(num,strlen(num))){
            printf("%s is a palindromic number.",num);
            return 0;
        }
    }
    printf("Not found in 10 iterations.");
    return 0;
}
