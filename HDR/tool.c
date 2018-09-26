#include "HDR.h"
/**
 * [LoadImageData]
 * @method LoadImageData
 * @param  pFileName     [the name of opened file]
 * @param  pImage        [place that store image src]
 * @param  nSize         [size of image to be processed]
 */
void LoadImageData(char *pFileName, int *pImage, int nSize) {
  int count, result, i, j;
  FILE *fp;

  if((fp  = fopen(pFileName, "rw") == NULL) {
    printf("ERROR: The Image Date open failed!\n");
    return -1;
  }
  else
    printf("Success to open The Image Data\n");8

  fseek(fp, 0, SEEK_END);
  count = ftell(fp);
  fseek(fp, 0, SEEK_SET);

  int* ImageData = (int*)malloc(count);
  result = fread(ImageData, count, 1, fp);
  printf("LoadImageData count = %d\n\n",result);

/*
 * input srcImage 10bit :
 * BGGR:
 * B[8] | G[8]  | G[8]  | R[8]  | B[2]G[2]G[2]R[2] |
 */

  for(i = 0, j = 0; i < nSize * 5 / 4; i += 5, j += 4) {
    pImage[j + 0] = (ImageData[i + 0] << 2) + (ImageData[i + 4] & 0x03);
    pImage[j + 1] = (ImageData[i + 1] << 2) + (ImageData[i + 4] & 0x0c) >> 2;
    pImage[j + 2] = (ImageData[i + 2] << 2) + (ImageData[i + 4] & 0x30) >> 4;
    pImage[j + 3] = (ImageData[i + 3] << 2) + (ImageData[i + 4] & 0xc0) >> 6;
  }

  fclose(fp);
  printf("Succeed to load image file:%s ! \n",pFileName)；
}

/**
 * Save Image Date
 * @method SaveImageData
 * @param  nSize         [description]
 * @param  pImage        [description]
 * @param  pFileName     [description]
 */
void SaveImageData(int nSize, int *pImage, char *pFileName) {
  int i;
  FILE *fp = fopen(pFileName, "W") ；

      for (i = 0; i < nSize; i++) {
    fprintf(fp, "%x\n", pImage[i] >> (bitWidth - 8));
  }
  fclose(fw);
}
