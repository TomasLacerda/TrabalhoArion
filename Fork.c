#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>

#define ITER 1000

int main() {
  struct timespec tp;
  struct timespec tempo1, tempo2;
  struct timezone tzp;
  int pid;
  int fat;
  int y;
  double tempo;

  int fatorial(int denominador) {
    int fat = 1;
    if (denominador == 0) {
      fat = 1;
      return fat;
    }
    for (int j = denominador; j >= 1; j--) {
      fat = fat * j;
    }
    return fat;
  }

  clock_gettime(CLOCK_REALTIME, & tempo1);

  pid = fork();
  if (pid > 0) {
    for (int i = 0; i < ITER; i++) {
      fat = fatorial(i);
      y = y + (1.0 / fat);
    }
  } else {
    pid = fork();
    if (pid > 0) {
      for (int i = 0; i < ITER; i++) {
        fat = fatorial(i);
        y = y + (1.0 / fat);
      }
    } else {
      pid = fork();
      if (pid > 0) {
        for (int i = 0; i < ITER; i++) {
          fat = fatorial(i);
          y = y + (1.0 / fat);
        }
      } else {
        pid = fork();
        if (pid > 0) {
          for (int i = 0; i < ITER; i++) {
            fat = fatorial(i);
            y = y + (1.0 / fat);
          }
        } else {
          pid = fork();
          if (pid > 0) {
            for (int i = 0; i < ITER; i++) {
              fat = fatorial(i);
              y = y + (1.0 / fat);
            }
          } else {
            pid = fork();
            if (pid > 0) {
              for (int i = 0; i < ITER; i++) {
                fat = fatorial(i);
                y = y + (1.0 / fat);
              }
            } else {
              pid = fork();
              if (pid > 0) {
                for (int i = 0; i < ITER; i++) {
                  fat = fatorial(i);
                  y = y + (1.0 / fat);
                }
              } else {
                pid = fork();
                if (pid > 0) {
                  for (int i = 0; i < ITER; i++) {
                    fat = fatorial(i);
                    y = y + (1.0 / fat);
                  }
                } else {
                  pid = fork();
                  if (pid > 0) {
                    for (int i = 0; i < ITER; i++) {
                      fat = fatorial(i);
                      y = y + (1.0 / fat);
                    }
                  } else {
                    for (int i = 0; i < ITER; i++) {
                      fat = fatorial(i);
                      y = y + (1.0 / fat);

                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  clock_gettime(CLOCK_REALTIME, & tempo2);
  tempo = (double)(tempo2.tv_sec - tempo1.tv_sec) + (((double)(tempo2.tv_nsec - tempo1.tv_nsec)) / 1000000);

  printf("\nResultado: %d\n", y);
  printf("\nTempo: %f\n", tempo);

  return 0;
}
