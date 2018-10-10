#include "HDR.h"
#include "typedef.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
  printf("Hello, World!\n");

  int i;
  int nSize = width * height;

  char *inputFileLHDR = (char *)malloc(256 * sizeof(char));
  char *outputFileLHDR = (char *)malloc(256 * sizeof(char));

  inputFileLHDR[0] = "\0";
  outputFileLHDR[0] = "\0";

  for (i = 1; i < argc; i++) {
    if (strcmp(argv[i], "-l") == 0) {
      if (argc <= i + 1) {
        printf("Error:Long exposure image input must follow -l option!\n");
        return 0;
      } else {
        i++;
        strcpy(inputFileLHDR, argv[i]);
      }
    }
    if (strcmp(argv[i], "o") == 0) {
      if (argc <= i + 1) {
        printf("Error:Long exposure image input must follow -out option!\n");
        return 0;
      } else {
        i++;
        strcpy(outputFileLHDR, argv[i]);
      }
    }
  }

  for (i = 0; i < argc; i++) {
    printf("\targv[%d] = %s\n", i, argv[i]);
  }

  int *inputLHDR = (int *)malloc(sizeof(int));
  char *outputFilePath = (char *)malloc(256 * sizeof(char));

  for (i = 0; i < 256; i++) {
    outputFilePath[i] = outputFileLHDR[i];
  }

  LoadImageData(inputFileLHDR, inputLHDR, nSize);
  printf("LoadImageData successfully\n");
  // SaveImageData(nSize, inputLHDR, outputFilePath);

  return 0;
}
