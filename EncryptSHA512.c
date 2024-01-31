#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <crypt.h>
#include <unistd.h>

#define SALT "$6$AS$"

int main(int arg_c, char *arg_v[]){
  
  printf("%s\n", crypt(arg_v[1], SALT));

  return 0;
}