/*
 * Escreve uma mensagem antes de morrer.
 */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void trata_SIGTERM(int signum) {
  printf("Sou mais forte que SIGTERM!\\n"); 
  raise(SIGTERM); 
}

int main() {

  signal(SIGTERM, trata_SIGTERM);
  while (1)
    sleep(1);
  
  return 0;
}
