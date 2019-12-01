#include "stdio.h"
char * cnnString(char *s1,char *s2)
{
    int len,len1,len2,i;
    char *s3;
    len1 = strlen(s1);
    len2 = strlen(s2);
    len = len1+len2+1;
    s3 = (char *)malloc(len);
    for(i=0;i<len1;i++)
        s3[i] = s1[i];      /*¿½±´×Ö·û´®s1*/
    for(i=0;i<len2;i++)
        s3[len1+i]=s2[i];   /*¿½±´×Ö·û´®s2*/
    s3[len-1]='\0';
    return s3;
}
main()
{
    char s1[]="This is a test ";
    char s2[]="for connecting two string.";
    printf("%s\n",s1);			/*Êä³ö×Ö·û´®s1*/
    printf("%s\n",s2);			/*Êä³ö×Ö·û´®s2*/
    printf("%s\n",cnnString(s1,s2));	/*Êä³öÁ¬½ÓºóµÄ×Ö·û´®s3*/
    getche();
}
