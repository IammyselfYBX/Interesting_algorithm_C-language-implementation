#include "stdio.h"
char data_1[19][10]={"one","two","three","four",
                    "five","six","seven","eight",
                    "nine","ten","eleven","twelve",
                    "thirteen","forteen","fifteen","sixteen",
                    "seventeen","eighteen","ninteen"};

char data_2[8][7]={"twenty","thirty","forty","fifty",
                 "sixty","seventy","eighty","ninty"};

translation_A(long N)
{                        /*翻译千位数*/
   long a;
   if(N==0) {printf("Zero\n");return;}
   a = N/1000;
   if(a!=0) {
        translation_B(a);
        printf("thousand ");
        }
   a = N%1000;
   if(a!=0)
        translation_B(a);
}

translation_B(long a)
{                        /*翻译百位数*/
    long b;
    b=a/100;
    if(b!=0){
        translation_C(b);
        printf("hundred ");
    }
    b = a%100;
    if(b!=0)
        translation_C(b);
}

translation_C(long b)
{                    /*翻译十位数和个位数*/
    long c;
    if(b<=19)
        printf("%s ",data_1[b-1]);
    else{
        c = b/10;
        printf("%s ",data_2[c-2]);
        c=b%10;
        if(c!=0)
            printf("%s ",data_1[c-1]);
        }
}

main()
{
    long N;
    printf("Please input a longeger from 0~999999\n");
    scanf("%ld",&N);
    translation_A(N);
    getche();
}

