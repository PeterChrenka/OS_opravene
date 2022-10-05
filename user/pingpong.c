#include "kernel/types.h"
#include <kernel/stat.h>
#include <user/user.h>
#include <stddef.h>
int main(int argc, char* argv[])
{
int pid;
int p[2];
pipe(p);
pid = fork();
int x = 5;
int y;
if(pid > 0){
    write(p[1], &x, 1);
    close(p[1]);
    read(p[0], &x, 1);
    if (x==6){
    printf("%d: received pong\n",getpid());
    close(p[0]);
    }
}
else{
    read(p[0], &y, 1);
    if(y==5){
    printf("%d: received ping\n",getpid());
    close(p[0]);
    }
    y=6;
    write(p[1],&y,1);
    close(p[1]);
    exit(0);
    
}

return 0;
}
