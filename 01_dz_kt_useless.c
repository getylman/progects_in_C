#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
  pid_t pid;
  int status, time = 0;
  char filename[30] = {}, launch_file[30] = {};
  scanf("%s", filename);
  FILE *file = fopen(filename, "r"); //aaaaa.txt
  while (1) {
    time = -1;
    fscanf(file, "%d %s\n", &time, launch_file);
    if (time == -1) {
      return 0;
    }
    pid = fork();
    if (pid == 0) {
      printf("running %s\n", launch_file);
      sleep(time);
      execve(launch_file, NULL, NULL);
    }
    wait(&status);
    printf("\n");
  }
  fclose(file);
  return 0;
}