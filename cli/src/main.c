#include <localcve/localcve.h>

int main(int argc, char* const argv[]) {
    if(localcve_prepare() != LC_OK)
        return 1;

    return 0;
}