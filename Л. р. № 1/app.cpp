#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

int main()
{
    int pid = getpid();
    printf("Initial pid: %d\n", pid);
    int n=0;
    int m=0;
    printf("Please, enter n and m: ");
    scanf("%d %d", &n, &m);
    int p;
    pid=fork();
    if(pid==0)
    {
        p=getpid();
        printf("Child pid=%d. n=%d\n",p, n);
    } else
    {
        p=getpid();
        printf("Father. pid=%d. m=%d\n",p, m);
        kill(pid, SIGKILL);
    }
    exit(0);
}
