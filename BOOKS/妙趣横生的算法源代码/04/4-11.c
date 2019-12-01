main()
{
    FILE *myf;
    long f;
    myf=fopen("C:\\test.txt","r");
    fseek(myf,0,SEEK_END);
    f=ftell(myf);
    fclose(myf);
    printf("The length of the file is %d bytes\n",f);
    getche();
}

