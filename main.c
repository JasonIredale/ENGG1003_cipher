#include <stdio.h>

int main()
{
    char message[] = "aadst";
    int key = 1;
    int index;
    
    for (index=0; message[index] != 0; index++)
    {
        message[index]=message[index]-key;
        
    }
    printf("%s", message);
}