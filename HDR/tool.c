#include "HDR.h"
/**
 * [LoadImageData]
 * @method LoadImageData
 * @param  pFileName     [the name of opened file INPUT]
 * @param  pImage        [place that store image src OUTPUT]
 * @param  nSize         [size of image to be processed]
 */
void LoadImageData(char *pFileName, int *pImage, int nSize) {
  int i, j;
  FILE *fp;

  fp = fopen("/home/mccreening/Desktop/ISP-DESIGN/HDR/SrcImage/2.raw", "rb");
  if (fp == NULL) {
    printf("ERROR: The Image Date open failed!\n");
    return -1;
  } else
    printf("Success to open the image filepath\n");
  // printf("step -1\n");
  fseek(fp, 0, SEEK_END);
  // printf("step 0\n");
  int count = ftell(fp);
  // printf("step 1\n");
  fseek(fp, 0, SEEK_SET);
  // printf("step 2\n");

  printf("Ftell fp count = %d\n", count);
  unsigned char *ImageData = (unsigned char *)malloc(count);
  fread(ImageData, count, 1, fp);
  printf("LoadImageData count = %s\n\n", ImageData);

  /*
   * input srcImage 10bit :
   * BGGR:
   * B[8] | G[8]  | G[8]  | R[8]  | B[2]G[2]G[2]R[2] |
   */
  if (bitWidth == 10) {
    printf("InputImageData bit width == 10\n");
    for (i = 0, j = 0; i < nSize * 5 / 4; i += 5, j += 4) {
      pImage[j + 0] = (ImageData[i + 0] << 2) + (ImageData[i + 4] & 0x03);
      pImage[j + 1] = (ImageData[i + 1] << 2) + (ImageData[i + 4] & 0x0c) >> 2;
      pImage[j + 2] = (ImageData[i + 2] << 2) + (ImageData[i + 4] & 0x30) >> 4;
      pImage[j + 3] = (ImageData[i + 3] << 2) + (ImageData[i + 4] & 0xc0) >> 6;
    }
  } else if (bitWidth == 12) {
    printf("InputImageData bit width == 12\n");
    printf("nSize = %d\n", nSize);
    for (i = 0, j = 0; i < (nSize * 2 - 2), j < nSize; i += 2, j++) {
      pImage[j] = ((ImageData[i + 1] & 0x0f) << 8) + ImageData[i];
      // printf("1\n");
    }
    printf("WTF , i count = %d\n", i);
  }
  printf("Succeed to load image file:!!!");

  fclose(fp);

  printf("Succeed to load image file:%s!\n", pFileName);
}

/**
 * Save Image Date
 * @method SaveImageData
 * @param  nSize         [the size of processed image]
 * @param  pImage        [input imagedata]
 * @param  pFileName     [output imagedata]
 */
void SaveImageData(int nSize, int *pImage, char *pFileName) {
  int i;
  FILE *fp =
      fopen("/home/mccreening/Desktop/ISP-DESIGN/HDR/ResultImage/result", "w");
  if (fp == NULL) {
    printf("Error:open outputFIle failed!!\n");
  }

  printf("Now step save begin!!\n\n");
  for (i = 0; i < nSize; i++) {
    // fprintf(fp, "%x\n", pImage[i] >> (bitWidth - 8));
    fprintf(fp, "%x\n", pImage[i]);
  }

  fclose(fp);
}
