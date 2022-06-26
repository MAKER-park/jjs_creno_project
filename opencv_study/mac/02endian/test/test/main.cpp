#include <stdio.h>
#include <stdlib.h>

int Test_Little_Endian();

int main()
{
    printf("This program is intended to determine whether this computer is little endian or not.\n\n");
    printf("Result: ");

    if(Test_Little_Endian())
    {
        printf("This pc is on the little endian.\n");
    }
    else
    {
        printf("This pc is on the big endian.\n");
    }
    getchar();
    return 0;
}

int Test_Little_Endian()
{
    unsigned char num = 0x00FF;
    return (*(unsigned char*)&num==0xFF);
}
