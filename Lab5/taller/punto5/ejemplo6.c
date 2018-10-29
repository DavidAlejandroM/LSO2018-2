#include <unistd.h>
#include <stdio.h>
#include <wait.h>

int main(int argc, char *argv[]) {
  pid_t pid_h1, pid_h2, pid_h3;
  pid_t pid_n;
  int status_h1, status_h2, status_h3, status_n;
  int i = 0;
  pid_h1 = fork();
  wait(&status_h1);
  if(pid_h1 == 0) {
    i++;
    pid_n = fork();
    wait(&status_n);
    if(pid_n==0) {
      i++;      
      printf("NIETO: i = %d\n",i);
    }else {
      printf("HIJO 1: i = %d\n",i);
    }
  }else {
    pid_h2 = fork();
    wait(&status_h1);
    if(pid_h2 == 0) {
      i++;      
      printf("HIJO 2: i = %d\n",i);
    }else {
      pid_h3 = fork();
      if(pid_h3 == 0) {
         i++;
         wait(&status_h2);
         printf("HIJO 3: i = %d\n",i);
      }else {
         wait(&status_h3);
         printf("PAPA: i = %d\n",i);
      }
    }
  }
  return 0;
}
