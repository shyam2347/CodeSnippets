#include <stdio.h>
#include <stdlib.h>
#include <execinfo.h>

void foo()
{
    int j;
    void *buffer[100];
    char **strings;

    int nptrs;
    nptrs = backtrace(buffer, 100);
    printf("backtrace returned %d address\n", nptrs);

    strings = backtrace_symbols(buffer, nptrs);
    if (strings == NULL) {
        perror("backtrace_symbols");
        exit(EXIT_FAILURE);
    }

    for (j = 0; j < nptrs; j++)
        printf("%s\n", strings[j]);

    free(strings);
}

void hee(const char *caller)
{
    printf("in hee, caller %s\n", caller);
    foo();
}

int main()
{
    hee(__func__);
    return 0;
}
