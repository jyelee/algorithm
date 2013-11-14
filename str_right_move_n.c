#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char *org, char *dest) {
  char temp = *org;
  *org = *dest;
  *dest = temp; 
}

void strReverseT(char *str, int begin, int len) {
  char *first = str + begin;
  char *end = str + begin + len - 1;
  while(first < end) {
    swap(first, end);
    first ++;
    end --;
  }
}


void strReverse(char *str, int begin, int len) {
  char *first = str + begin;
  //int middle = begin + len / 2 - 1;
  int middle = len / 2 - 1;
  char *end = str + begin + len - 1;
  //int type = len % 2;
  int i = 0;
  //if(!type) {
    for(; i<=middle; i++) {
      swap(first+i, end-i);
    }
  //} else {
   //for(; i<middle; i++) {
      //swap(first+i, end-i);
    //}
  //}
}

int main(int argc, char *argv[]) {
  if(argc != 3) {
    fprintf(stderr, "Input Error!");
    exit(EXIT_FAILURE);
  }
  int strLen = strlen(argv[1]);
  int tailNum = atoi(argv[2]);
  tailNum = tailNum % strLen;
  strReverseT(argv[1], 0, strLen - tailNum);
  strReverseT(argv[1], strLen - tailNum, tailNum);
  strReverseT(argv[1], 0, strLen);
  printf("%s\n", argv[1]);
  return EXIT_SUCCESS;
}
