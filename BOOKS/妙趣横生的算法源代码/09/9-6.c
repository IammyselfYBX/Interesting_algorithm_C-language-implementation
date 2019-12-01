#include "stdio.h"

void encryption(char buffer[],int file_size,int key);
void decryption(char buffer[],int file_size,int key);
void Process(int a);
int openSrcFile(char **buffer);
void saveDstFile(char *buffer);
void menu();


main()
{
	char flag; 
	menu();
	flag = getchar();
	getchar();
	while(flag != 'Q')
	{
		switch(flag)
		{
			case 'E':Process(0);break;
			case 'D':Process(1);break;
			default:printf("Input Error!\n");break;
		}
		flag = getchar();
		getchar();
	}
}

void menu()
{
	printf("*****************************************************************\n");
	printf(" =========A SIMPLE ENCRYPTION / DECRYPTION SYSTEM=========\n");
	printf("    ENCRYPTION press 'E'   DECRYPTION press 'D'   QUIT press 'Q'  \n" );
	printf("*****************************************************************\n");
}

int openSrcFile(char **buffer)
{
	FILE *myfile_src;			/*源文件指针*/
	char filename[20];			/*文件名数组*/
	long file_size;				/*记录文件的长度*/
	printf("Please input the path and filename of the file you want to process\n");
	scanf("%s",filename);
	if(!(myfile_src = fopen(filename,"rb")))
	{
		printf("ERROR!");
	}
	fseek(myfile_src,0,SEEK_END);
	file_size = ftell(myfile_src);
	fseek(myfile_src,0,SEEK_SET);
	*buffer = (char *)malloc(file_size);
	fread(*buffer,1,file_size,myfile_src);		/*读入文件*/
	fclose(myfile_src);
	return 	file_size;			
}

void saveDstFile(char *buffer,long file_size)
{
	FILE *myfile_dst;			/*源文件指针*/
	char filename[20];			/*文件名数组*/
	printf("Please input the path and filename of the file you have processed\n");
	scanf("%s",filename);
	if(!(myfile_dst = fopen(filename,"wb")))
	{
		printf("ERROR!");
	}
	fwrite(buffer,1,file_size,myfile_dst);
	printf("OK");
	fclose(myfile_dst);
}

void Process(int a)
{
	FILE *myfile_dst;
	char * buffer;
	int key;
	long file_size;					/*记录文件的长度*/
	file_size = openSrcFile(&buffer);			/*读入源文件*/
	printf("Please input the key (a integer) for encryption or decryption\n");
	scanf("%d",&key);				/*用户输入密钥*/

	if(a == 0)
	{
		/*加密状态*/
		encryption(buffer,file_size,key);
	}
	else
	{
		/*解密状态*/
		decryption(buffer,file_size,key);
	}
	saveDstFile(buffer,file_size);	
}

void encryption(char buffer[],int file_size,int key)
{
	int i;
	for( i = 0; i < file_size; i++)
		buffer[i] = buffer[i] + key;  /* M=2*(P+key) */
}

void decryption(char buffer[],int file_size,int key)
{
	int i;
	for( i = 0; i < file_size; i++)
		buffer[i] = buffer[i] - key;
}
