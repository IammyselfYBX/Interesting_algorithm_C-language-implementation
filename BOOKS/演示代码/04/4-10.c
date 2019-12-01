#include "stdio.h"
main()
{
    FILE *fp;
    char pathName[20], txt1[20]={'\0'},txt2[20]={'\0'};
    int fileLen;
    /*打开文件*/
    printf("Please type the path name of the file\n");
    scanf("%s",pathName);
    fp=fopen(pathName,"w");
    /*将字符串写入文件*/
    printf("Please input a string to this file\n");
    scanf("%s",txt1);
    fileLen=strlen(txt1);
    fwrite(txt1,fileLen,1,fp);
    fclose(fp);
    printf("The file has been saved\n");
    printf("The content of the file: %s is\n",pathName);
    fp=fopen(pathName,"r");
    fread(txt2,fileLen,1,fp);
    printf("%s\n",txt2);
    getche();
}

