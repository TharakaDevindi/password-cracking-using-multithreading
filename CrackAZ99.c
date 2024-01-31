%%writefile CrackAZ99.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <crypt.h>

int count = 0;

void substr(char *dest, char *src, int begin, int length){
  memcpy(dest, src + begin, length);
  *(dest + length) = '\0'; 
}
void crack(char * salt_and_encrypted){
  int count_len_1;
  int count_len_2;
  int count_len_3;
  char salt[7];
  char plain[7];
  char *enc;
  substr(salt, salt_and_encrypted, 0, 6);

  for(count_len_1='A'; count_len_1<='Z'; count_len_1++){
    for(count_len_2='A'; count_len_2<='Z'; count_len_2++){
      for(count_len_3=0; count_len_3<=99; count_len_3++){
        sprintf(plain, "%c%c%02d", count_len_1, count_len_2, count_len_3);
        enc =(char *) crypt(plain, salt);
        count++;
        if(strcmp(salt_and_encrypted, enc)== 0){
          printf("#%-8d%s %s\n", count, plain, enc);
          //return; //
        }
      }
    }
  }
}

int main(int arg_c, char *arg_v[]){
  crack("$6$AS$UkC0Myn.lIbj96fJ6shL.RewFdcUzPiNHt6d/Txo6FrLqcR72RyyainQVc4cKkgj3dF5w2X85iZLvCzoYApvK0");
  printf("%d Solutions\n", count);

  return 0;
}