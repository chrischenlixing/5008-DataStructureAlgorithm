//enter your email here
//enter your name here

#include<stdio.h>
#include<string.h>

int compression(char arr[], int n, char res[]){
    int i = 0;
    int j = 0;
    int repeat = 0;
    char current = arr[i];
    char check = arr[j];
    char encoding[100];
    while(i < n){

        while(current == check){
            repeat += 1;
            j ++;
            check = arr[j];

        }

        if (repeat > 1){
            sprintf(encoding,"%c%d",current,repeat);
            strcat(res,encoding);
            i = i + repeat;
            current = arr[i];
            repeat = 0;
        } else{
            sprintf(encoding,"%c",current);
            strcat(res,encoding);
            i ++;
            current = arr[i];
            }
        }


    return strlen(res) ;
    }

 
int main()
{
//    char a[]="aaaaaaaaaaaaaabbbbcccd";
    char a[]="aaaaaaabbbbbbbbbbcddddh";
    char res[50];
    int r,n=strlen(a);//n is the size of input array
    r=compression(a,n,res);
    printf("length of the compressed string:%d\n",r);
    printf("The compressed string:%s\n",res);

    return 0;
}
