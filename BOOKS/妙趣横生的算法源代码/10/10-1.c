#include <stdio.h>
inputString()
{
    char c, lastc = 'a';
    c = getchar();
    while(c!=EOF)
    {
        if(c!=' '){
            putchar(c); 
            lastc = c;
            c = getchar();    
            }
        else{
            if(lastc!=' ')
                putchar(c);   
            lastc = c;
            c = getchar();
        }
    }
}
main()
{
     inputString();
     getche();
}
