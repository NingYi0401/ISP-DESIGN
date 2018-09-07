#include "HDR.h"

void LoadImageData(char* pFileName, int* pImage, int nSize)
{
  int count;
  int result = 1;
  FILE *fp ;

  if((fp  = fopen(pFileName, "rw") == NULL) {
    printf("ERROR: The Image Date open failed!\n");
    return -1;
  }
  else
    printf("Success to open The Image Data\n");

  fseek(fp, 0, SEEK_END);
  count = ftell(fp);
  fseek(fp, 0, SEEK_SET);

  int* ImageData = (int*)malloc(count);
  result = fread(ImageData, count, 1, fp);
  fprintf("LoadImageData count = %d\n\n",result);

  
}
