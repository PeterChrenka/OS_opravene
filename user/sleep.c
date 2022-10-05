#include "kernel/types.h"
#include <kernel/stat.h>
#include <user/user.h>
int main(int argc, char* argv[])
{
    int argnumber;
    if(argc > 1){
      argnumber = atoi(argv[1]);
        sleep(argnumber);
    }
    else{ 
        printf("Bad argument");
        exit(1);
    }
    exit(0);
    return 0;
}
