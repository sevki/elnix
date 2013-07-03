#include <itoa.h>

#define INT_LENGTH 10
#define UINT_LENGTH 11


char *itoa(int i)
{
    static char buf[INT_LENGTH + 2];
    char *a = buf + INT_LENGTH + 1;
    if(i >=0){
        do{
            *--a = '0' + (i % 10);
            i /= 10;

        }while (i != 0);
    } else
    {
        do{
            *--a = '0' - (i % 10);
            i /= 10;
        }while (i != 0);
        *--a = '-';
    }
    return a;
}
