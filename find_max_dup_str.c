#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>

using namespace std;


void printMaxDupStr(char *str1, char *str2) {
  int str1Len = strlen(str1);
  int str2Len = strlen(str2);
  int minLen = str1Len;
  int maxLen = str2Len;
  int endIndex = -1;
  char *bStr;
  char *sStr;
  if(str1Len < str2Len) {
	bStr = str2;
	sStr = str1;
  } else {
	bStr = str1;
	sStr = str2;
	minLen = str2Len;
	maxLen = str1Len;
  }
  int *dupCount = new int[minLen];
  vector<int> indexVec(minLen);
  int maxDup = 0;
  int i = 0;
  int j = minLen - 1;
  for(; i<minLen; i++) {
	dupCount[i] = 0;
  }
  i = 0;
  for(; i<maxLen; i++) {
	j = minLen - 1;
	for(; j>=0; j--) {
	  if(bStr[i] == sStr[j]) {
		if(i==0 || j==0) {
          dupCount[j] = 1; 
		} else {
		  dupCount[j] = dupCount[j - 1] + 1;
		}
	  } else {
		dupCount[j] = 0;
	  }
	  if(dupCount[j] == 0) 
		continue;
	  if(dupCount[j] > maxDup) {
		maxDup = dupCount[j];
		if(indexVec.size() == 1) {
		  indexVec.erase(indexVec.begin());
		} else if(indexVec.size() >= 2) {
		  indexVec.erase(indexVec.begin(), indexVec.end());
		}
		indexVec.push_back(j);
	  } else if(dupCount[j] == maxDup) {
		indexVec.push_back(j);
	  }
    }
  }
  if(maxDup == 0) {
	printf("No match str\n");
	return;
  }
  j = 0;
  for(; j<indexVec.size(); j++) {
	endIndex = indexVec[j] - maxDup + 1;
      i = 0;
      for(; i<maxDup; i++) {
	    printf("%c ", sStr[endIndex + i]);
      }
	  printf("\n");
  }
  delete []dupCount;
}

int main(int argc, char *argv[]) {
  if(argc != 3) {
	fprintf(stderr, "%s", "Input Error! : find_max_dup_str str1 str2");
	exit(EXIT_FAILURE);
  }
  printMaxDupStr(argv[1], argv[2]);
  return EXIT_SUCCESS;
}
