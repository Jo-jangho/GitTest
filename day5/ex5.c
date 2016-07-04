#include <stdio.h>

int main(void)
{
    char cmd;
    char data;
    char buffer[64] = {0, };
    int bLoop = 1;
    int nTailIndex = 0;
    
    while(bLoop)
    {
        printf("a : add, d : delete, f: first out, s : show, q : quit");
        scanf("%c", &cmd);
        getchar();

        switch(cmd)
        {
            case 'a':   //add
                printf("what : ");
                scanf("%c", &data);
                getchar();
                buffer[nTailIndex] = data;
                nTailIndex++;
                break;
            case 'd':   //delete
                nTailIndex--;
                buffer[nTailIndex] = 0x00;
                break;
            case 'f':
                for(int i = 0 ; i < nTailIndex - 1 ; i++)
                {
                    buffer[i] = buffer[i + 1];
                }
                nTailIndex--;
                buffer[nTailIndex] = 0x00;
                break;
            case 's':
                for(int i = 0 ; i < nTailIndex ; i++)
                {
                    printf("%c", *(buffer + nHeadIndex + i));
                }
                puts("");
                break;
            case 'q':
                printf("Quit\n");
                bLoop = 0;
                break;
        }
    }

    return 0;
}