#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

static int count = 0;

void signal_callback_handler(int signum)
{
   printf("\nCtrl+C was cought (count: %d)\n",++count);
   if (count > 3) {
     printf("Exit\n");
     signal(SIGINT,SIG_DFL);
   }

}

int main()
{
   // регистрируем обработчик сигнала
   signal(SIGINT, signal_callback_handler);

   while(1)
   {
      printf("Program working...\n");
      sleep(1);
      if (count == 4)
      break;
   }
}
