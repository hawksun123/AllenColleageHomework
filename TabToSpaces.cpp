/*
  Scan through a file and change all tabs to 2 spaces
*/
#include "c_common.h"

#define STR_LEN     120
#define HSDEBUG			1

// function declaration

int main(int argc, char *argv[]) {
  FILE  *pInFile;
  FILE  *pOutFile;
  char  str1[STR_LEN + 1];

  for (int loop = 1; loop < argc; loop++) {
    pInFile = fopen(argv[loop], "r");
    if (pInFile == NULL) {
      printf("Unable to open input %s file!\n", argv[loop]);
      return FAILURE;
    }
    pOutFile = fopen(strcat(argv[loop], ".out"), "w");
    if (pOutFile == NULL) {
      printf("Unable to open output %s%s file!\n", argv[loop], ".out");
      return FAILURE;
    }
    while (fgets(str1, STR_LEN + 1, pInFile) != NULL) { // end of file ?
      int   loop2 = 0;
      for (int loop1 = 0; loop1 < strlen(str1); loop1++) {
        char  str2[STR_LEN + 1];
        if (str1[loop1] == '\t') {
          str2[loop2++] = ' ';
          str2[loop2++] = ' ';
        } else {
          str2[loop2] = 0;
          strcat(str2, &str1[loop1]);
          fputs(str2, pOutFile);
          break;
        }
      }
    }
    fclose(pInFile);
    fclose(pOutFile);
  }
  return SUCCESS;
}


