#include <sys/ksys.h>
#include <string.h>

int main()
{
    char str[100] = "Hello ";
    strcat(str, "world!\n");
    _ksys_debug_puts(str);
}
