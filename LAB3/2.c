#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <signal.h>
#include <unistd.h>
#include <ucontext.h>

int flag = 0;

void sigHandler(int sigNo, siginfo_t *si, ucontext_t *u)
{
    if (sigNo == SIGUSR1)
    {
        printf("SIGUSR1 odebrano - nic nie robie\n");
    }
    else if (sigNo == SIGUSR2)
    {
        printf("SIGUSR2 odebrano - koncze prace\n");
        exit(1);
    }
    else if (sigNo == SIGALRM)
    {
        printf("SIGALRM odebrano - ignoruje ten sygnal przez kolejne 100 iteracji\n");
        flag = 1;
    }
}

int main()
{
    sigset_t signalSet;
    sigemptyset(&signalSet);
    sigaddset(&signalSet, SIGUSR1);
    sigaddset(&signalSet, SIGUSR2);
    sigaddset(&signalSet, SIGALRM);
    //sigaddset(&signalSet3, SIGTERM);

    sigprocmask(SIG_UNBLOCK, &signalSet, NULL);

    struct sigaction act;
    act.sa_handler = sigHandler;
    act.sa_flags = SA_SIGINFO;

    sigaction(SIGUSR1, &act, 0);
    sigaction(SIGUSR2, &act, 0);
    sigaction(SIGALRM, &act, 0);
    sigignore(SIGTERM);

    struct timespec tv;
    tv.tv_sec = 0;
    tv.tv_nsec = 100000000L;
    printf("My PID is %ld\n", (long)getpid());
    int i = 0;
    int counter = 0;
    while (1)
    {
        ++i;
        --i;
        nanosleep(&tv, (struct timespec *)NULL);
        if (flag == 1 || flag == 2)
        {
            if (flag == 1)
            {
                sigignore(SIGALRM);
                flag = 2;
            }
            counter++;
            if (counter >= 100)
            {
                sigaction(SIGALRM, &act, 0);
                flag = 0;
                counter = 0;
            }
        }
    }
}
