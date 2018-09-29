#ifndef __HDR_H__
#define __HDR_H__

#include "typedef.h"
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void LoadImageData(char *pFileName, int *pImage, int nSize);
void SaveImageData(int nSize, int *pImage, char *pFileName);

#endif
