#include <sys/ksys.h>
#include <string.h>
#include <clayer/console.h>

int main()
{
    char str[100];
    strcpy(str, "Hello world!\n");
    con_init(-1, -1, -1, -1, "Hello app!");
    con_write_asciiz(str);
    con_exit(0);
}
