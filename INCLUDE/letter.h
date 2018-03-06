#define p 16

unsigned int ** letterBuffer;

static unsigned char letA[10 * 10] =
{
	0,0,0,0,p,p,0,0,0,0,
	0,0,0,0,p,p,0,0,0,0,
	0,0,0,p,p,p,p,0,0,0,
	0,0,p,p,0,0,p,p,0,0,
	0,0,p,p,0,0,p,p,0,0,
	0,p,p,p,p,p,p,p,p,0,
	0,p,p,p,p,p,p,p,p,0,
	0,p,p,0,0,0,0,p,p,0,
	0,p,p,0,0,0,0,p,p,0,
	p,p,p,p,0,0,p,p,p,p,
};


static unsigned char letB[10 * 10] =
{
	0,p,p,p,p,p,p,0,0,0,
	0,p,p,0,0,0,0,p,0,0,
	0,p,p,0,0,0,0,p,p,0,
	0,p,p,0,0,0,0,p,p,0,
	0,p,p,p,p,p,p,p,p,0,
	0,p,p,p,p,p,p,p,0,0,
	0,p,p,0,0,0,0,p,p,0,
	0,p,p,0,0,0,0,p,p,0,
	0,p,p,0,0,0,0,p,p,0,
	0,p,p,p,p,p,p,p,0,0,
};


static unsigned char letC[10 * 10] =
{
	0,0,0,p,p,p,p,p,0,0,
	0,0,p,p,p,p,p,p,p,0,
	0,p,p,p,0,0,0,0,p,p,
	0,p,p,p,0,0,0,0,0,0,
	0,p,p,p,0,0,0,0,0,0,
	0,p,p,p,0,0,0,0,0,0,
	0,p,p,p,0,0,0,0,0,0,
	0,p,p,p,0,0,0,0,p,p,
	0,0,p,p,p,p,p,p,p,0,
	0,0,0,p,p,p,p,p,0,0,
};

static unsigned char letD[10 * 10] =
{
	0,p,p,p,p,p,p,p,0,0,
	0,p,p,p,p,p,p,p,p,0,
	0,p,p,0,0,0,0,p,p,p,
	0,p,p,0,0,0,0,0,p,p,
	0,p,p,0,0,0,0,0,p,p,
	0,p,p,0,0,0,0,0,p,p,
	0,p,p,0,0,0,0,0,p,p,
	0,p,p,0,0,0,0,p,p,p,
	0,p,p,p,p,p,p,p,p,0,
	0,p,p,p,p,p,p,p,0,0,
};

static unsigned char letE[10 * 10] =
{
	0,p,p,p,p,p,p,p,p,0,
	0,p,p,p,p,p,p,p,p,0,
	0,p,p,0,0,0,0,0,0,0,
	0,p,p,0,0,0,0,0,0,0,
	0,p,p,p,p,p,p,p,p,0,
	0,p,p,p,p,p,p,p,p,0,
	0,p,p,0,0,0,0,0,0,0,
	0,p,p,0,0,0,0,0,0,0,
	0,p,p,p,p,p,p,p,p,0,
	0,p,p,p,p,p,p,p,p,0,
};

static unsigned char letF[10 * 10] =
{
	0,p,p,p,p,p,p,p,p,0,
	0,p,p,p,p,p,p,p,p,0,
	0,p,p,0,0,0,0,0,0,0,
	0,p,p,0,0,0,0,0,0,0,
	0,p,p,p,p,p,0,0,0,0,
	0,p,p,p,p,p,0,0,0,0,
	0,p,p,0,0,0,0,0,0,0,
	0,p,p,0,0,0,0,0,0,0,
	0,p,p,0,0,0,0,0,0,0,
	0,p,p,0,0,0,0,0,0,0,
};

static unsigned char letG[10 * 10] =
{
	0,0,0,p,p,p,p,p,0,0,
	0,0,p,p,p,p,p,p,p,0,
	0,p,p,p,0,0,0,0,0,0,
	0,p,p,p,0,0,0,0,0,0,
	0,p,p,p,0,0,p,p,p,p,
	0,p,p,p,0,0,p,p,p,p,
	0,p,p,p,0,0,0,0,p,p,
	0,p,p,p,0,0,0,0,p,p,
	0,0,p,p,p,p,p,p,p,0,
	0,0,0,p,p,p,p,p,0,0,
};

static unsigned char letH[10 * 10] =
{
	0,p,p,0,0,0,0,p,p,0,
	0,p,p,0,0,0,0,p,p,0,
	0,p,p,0,0,0,0,p,p,0,
	0,p,p,0,0,0,0,p,p,0,
	0,p,p,p,p,p,p,p,p,0,
	0,p,p,p,p,p,p,p,p,0,
	0,p,p,0,0,0,0,p,p,0,
	0,p,p,0,0,0,0,p,p,0,
	0,p,p,0,0,0,0,p,p,0,
	0,p,p,0,0,0,0,p,p,0,
};

static unsigned char letI[10 * 10] =
{
	0,0,0,p,p,p,p,0,0,0,
	0,0,0,0,p,p,0,0,0,0,
	0,0,0,0,p,p,0,0,0,0,
	0,0,0,0,p,p,0,0,0,0,
	0,0,0,0,p,p,0,0,0,0,
	0,0,0,0,p,p,0,0,0,0,
	0,0,0,0,p,p,0,0,0,0,
	0,0,0,0,p,p,0,0,0,0,
	0,0,0,0,p,p,0,0,0,0,
	0,0,0,p,p,p,p,0,0,0,
};

static unsigned char letJ[10 * 10] =
{
	0,0,0,p,p,p,p,p,p,0,
	0,0,0,p,p,p,p,p,p,0,
	0,0,0,0,0,0,0,p,p,0,
	0,0,0,0,0,0,0,p,p,0,
	0,0,0,0,0,0,0,p,p,0,
	0,0,0,0,0,0,0,p,p,0,
	0,p,p,0,0,0,0,p,p,0,
	0,p,p,0,0,0,0,p,p,0,
	0,0,p,p,p,p,p,p,0,0,
	0,0,0,p,p,p,p,0,0,0,
};

static unsigned char letK[10 * 10] =
{
	p,p,p,0,0,0,0,p,p,0,
	p,p,p,0,0,0,p,p,p,0,
	p,p,p,0,0,p,p,p,0,0,
	p,p,p,0,p,p,p,0,0,0,
	p,p,p,p,p,p,0,0,0,0,
	p,p,p,p,p,p,0,0,0,0,
	p,p,p,0,p,p,p,0,0,0,
	p,p,p,0,0,p,p,p,0,0,
	p,p,p,0,0,0,p,p,p,0,
	p,p,p,0,0,0,0,p,p,0,
};

static unsigned char letL[10 * 10] =
{
	0,p,p,p,0,0,0,0,0,0,
	0,p,p,p,0,0,0,0,0,0,
	0,p,p,p,0,0,0,0,0,0,
	0,p,p,p,0,0,0,0,0,0,
	0,p,p,p,0,0,0,0,0,0,
	0,p,p,p,0,0,0,0,0,0,
	0,p,p,p,0,0,0,0,0,0,
	0,p,p,p,0,0,0,0,0,0,
	0,p,p,p,p,p,p,p,p,0,
	0,p,p,p,p,p,p,p,p,0,
};

static unsigned char letM[10 * 10] =
{
	p,p,p,0,0,0,0,p,p,p,
	p,p,p,p,0,0,p,p,p,p,
	p,p,0,p,p,p,p,0,p,p,
	p,p,0,0,p,p,0,0,p,p,
	p,p,0,0,0,0,0,0,p,p,
	p,p,0,0,0,0,0,0,p,p,
	p,p,0,0,0,0,0,0,p,p,
	p,p,0,0,0,0,0,0,p,p,
	p,p,0,0,0,0,0,0,p,p,
	p,p,0,0,0,0,0,0,p,p,
};

static unsigned char letN[10 * 10] =
{
	p,p,p,0,0,0,0,0,p,p,
	p,p,p,p,0,0,0,0,p,p,
	p,p,0,p,p,p,0,0,p,p,
	p,p,0,0,p,p,p,0,p,p,
	p,p,0,0,0,p,p,p,p,p,
	p,p,0,0,0,0,p,p,p,p,
	p,p,0,0,0,0,0,p,p,p,
	p,p,0,0,0,0,0,0,p,p,
	p,p,0,0,0,0,0,0,p,p,
	p,p,0,0,0,0,0,0,p,p,
};

static unsigned char letO[10 * 10] =
{
	0,0,0,p,p,p,p,p,0,0,
	0,0,p,p,p,p,p,p,p,0,
	0,p,p,p,0,0,0,p,p,p,
	0,p,p,p,0,0,0,p,p,p,
	0,p,p,p,0,0,0,p,p,p,
	0,p,p,p,0,0,0,p,p,p,
	0,p,p,p,0,0,0,p,p,p,
	0,p,p,p,0,0,0,p,p,p,
	0,0,p,p,p,p,p,p,p,0,
	0,0,0,p,p,p,p,p,0,0,
};

static unsigned char letP[10 * 10] =
{
	0,p,p,p,p,p,p,p,p,0,
	0,p,p,p,p,p,p,p,p,0,
	0,p,p,0,0,0,0,p,p,0,
	0,p,p,0,0,0,0,p,p,0,
	0,p,p,p,p,p,p,p,p,0,
	0,p,p,p,p,p,p,p,0,0,
	0,p,p,p,0,0,0,0,0,0,
	0,p,p,p,0,0,0,0,0,0,
	0,p,p,p,0,0,0,0,0,0,
	0,p,p,p,0,0,0,0,0,0,
};

static unsigned char letQ[10 * 10] =
{
	0,0,0,p,p,p,p,p,0,0,
	0,0,p,p,p,p,p,p,p,0,
	0,p,p,p,0,0,0,p,p,p,
	0,p,p,p,0,0,0,p,p,p,
	0,p,p,p,0,0,0,p,p,p,
	0,p,p,p,0,p,0,p,p,p,
	0,p,p,p,0,p,p,p,p,p,
	0,p,p,p,0,0,p,0,0,0,
	0,0,p,p,p,p,p,0,0,p,
	0,0,0,p,p,p,p,0,p,p,
};

static unsigned char letR[10 * 10] =
{
	0,p,p,p,p,p,p,p,p,0,
	0,p,p,p,p,p,p,p,p,0,
	0,p,p,0,0,0,0,p,p,0,
	0,p,p,0,0,0,0,p,p,0,
	0,p,p,p,p,p,p,p,p,0,
	0,p,p,p,p,p,p,p,0,0,
	0,p,p,p,0,0,p,p,p,0,
	0,p,p,p,0,0,0,p,p,p,
	0,p,p,p,0,0,0,0,p,p,
	0,p,p,p,0,0,0,0,p,p,
};

static unsigned char letS[10 * 10] =
{
	0,0,0,p,p,p,p,0,0,0,
	0,0,p,p,p,p,p,p,0,0,
	0,0,p,p,0,0,0,p,p,0,
	0,0,p,p,0,0,0,0,0,0,
	0,0,p,p,p,p,p,p,0,0,
	0,0,0,p,p,p,p,p,p,0,
	0,0,0,0,0,0,0,p,p,0,
	0,0,p,p,0,0,0,p,p,0,
	0,0,p,p,p,p,p,p,p,0,
	0,0,0,p,p,p,p,p,0,0,
};

static unsigned char letT[10 * 10] =
{
	0,p,p,p,p,p,p,p,p,0,
	0,p,p,p,p,p,p,p,p,0,
	0,p,0,0,p,p,0,0,p,0,
	0,0,0,0,p,p,0,0,0,0,
	0,0,0,0,p,p,0,0,0,0,
	0,0,0,0,p,p,0,0,0,0,
	0,0,0,0,p,p,0,0,0,0,
	0,0,0,0,p,p,0,0,0,0,
	0,0,0,0,p,p,0,0,0,0,
	0,0,0,p,p,p,p,0,0,0,
};

static unsigned char letU[10 * 10] =
{
	0,p,p,p,0,0,0,p,p,p,
	0,p,p,p,0,0,0,p,p,p,
	0,p,p,p,0,0,0,p,p,p,
	0,p,p,p,0,0,0,p,p,p,
	0,p,p,p,0,0,0,p,p,p,
	0,p,p,p,0,0,0,p,p,p,
	0,p,p,p,0,0,0,p,p,p,
	0,p,p,p,0,0,0,p,p,p,
	0,0,p,p,p,p,p,p,p,0,
	0,0,0,p,p,p,p,p,0,0,
};

static unsigned char letV[10 * 10] =
{
	0,p,p,p,0,0,0,p,p,p,
	0,p,p,p,0,0,0,p,p,p,
	0,p,p,p,0,0,0,p,p,p,
	0,p,p,p,0,0,0,p,p,p,
	0,0,p,p,0,0,0,p,p,0,
	0,0,p,p,0,0,0,p,p,0,
	0,0,p,p,p,0,p,p,p,0,
	0,0,0,p,p,0,p,p,0,0,
	0,0,0,p,p,p,p,p,0,0,
	0,0,0,0,p,p,p,0,0,0,
};

static unsigned char letW[10 * 10] =
{
	p,p,0,0,0,0,0,0,p,p,
	p,p,0,0,0,0,0,0,p,p,
	p,p,0,0,0,0,0,0,p,p,
	p,p,p,0,0,0,0,p,p,p,
	0,p,p,0,p,p,0,p,p,0,
	0,p,p,0,p,p,0,p,p,0,
	0,p,p,0,p,p,0,p,p,0,
	0,p,p,0,p,p,0,p,p,0,
	0,0,p,p,p,p,p,p,p,0,
	0,0,p,p,0,0,p,p,0,0,
};

static unsigned char letX[10 * 10] =
{
	0,p,0,0,0,0,0,0,p,0,
	p,p,p,0,0,0,0,p,p,p,
	0,p,p,p,0,0,p,p,p,0,
	0,0,p,p,p,p,p,p,0,0,
	0,0,0,p,p,p,p,0,0,0,
	0,0,0,p,p,p,p,0,0,0,
	0,0,p,p,0,p,p,p,0,0,
	0,p,p,p,0,0,p,p,p,0,
	p,p,p,0,0,0,0,p,p,p,
	0,p,0,0,0,0,0,0,p,0,
};

static unsigned char letY[10 * 10] =
{
	p,p,0,0,0,0,0,0,p,p,
	p,p,p,0,0,0,0,p,p,p,
	0,p,p,p,0,0,p,p,p,0,
	0,0,p,p,p,p,p,p,0,0,
	0,0,0,p,p,p,p,0,0,0,
	0,0,0,0,p,p,0,0,0,0,
	0,0,0,0,p,p,0,0,0,0,
	0,0,0,0,p,p,0,0,0,0,
	0,0,0,0,p,p,0,0,0,0,
	0,0,0,p,p,p,p,0,0,0,
};

static unsigned char letZ[10 * 10] =
{
	0,p,p,p,p,p,p,p,p,0,
	0,p,p,p,p,p,p,p,p,0,
	0,p,0,0,0,0,0,p,p,0,
	0,0,0,0,0,0,p,p,p,0,
	0,0,0,0,0,p,p,p,0,0,
	0,0,0,0,p,p,p,0,0,0,
	0,0,0,p,p,p,0,0,0,0,
	0,0,p,p,p,0,0,0,p,0,
	0,p,p,p,p,p,p,p,p,0,
	0,p,p,p,p,p,p,p,p,0,
};

void letterShowA(int x, int y) {
  int i,j;
  //allocates memory and returns pointer to it
  //receives size to allocate
  letterBuffer = malloc(sizeof(int) * 10);
  for (i= 0; i < 10; i++) {
    letterBuffer[i] = malloc(sizeof(int) * 10);
    for (j=0; j < 10; j++) {
      letterBuffer[i][j] = getPixel(x+i, y+j);
    }
  }

  for (i=0; i < 10; i++) {
    for (j=0; j < 10; j++) {
      if (letA[10*i+j]!=0){
        putPixel(x + j, y + i, letA[10*i+j]);
      }
    }
	free(letterBuffer[i]);
  }
   free(letterBuffer);
}

void letterShowB(int x, int y) {
  int i,j;
  //allocates memory and returns pointer to it
  //receives size to allocate
  letterBuffer = malloc(sizeof(int) * 10);
  for (i= 0; i < 10; i++) {
    letterBuffer[i] = malloc(sizeof(int) * 10);
    for (j=0; j < 10; j++) {
      letterBuffer[i][j] = getPixel(x+i, y+j);
    }
  }

  for (i=0; i < 10; i++) {
    for (j=0; j < 10; j++) {
      if (letB[10*i+j]!=0){
        putPixel(x + j, y + i, letB[10*i+j]);
      }
    }
	free(letterBuffer[i]);
  }
   free(letterBuffer);
}

void letterShowC(int x, int y) {
  int i,j;
  //allocates memory and returns pointer to it
  //receives size to allocate
  letterBuffer = malloc(sizeof(int) * 10);
  for (i= 0; i < 10; i++) {
    letterBuffer[i] = malloc(sizeof(int) * 10);
    for (j=0; j < 10; j++) {
      letterBuffer[i][j] = getPixel(x+i, y+j);
    }
  }

  for (i=0; i < 10; i++) {
    for (j=0; j < 10; j++) {
      if (letC[10*i+j]!=0){
        putPixel(x + j, y + i, letC[10*i+j]);
      }
    }
	free(letterBuffer[i]);
  }
   free(letterBuffer);
}

void letterShowD(int x, int y) {
  int i,j;
  //allocates memory and returns pointer to it
  //receives size to allocate
  letterBuffer = malloc(sizeof(int) * 10);
  for (i= 0; i < 10; i++) {
    letterBuffer[i] = malloc(sizeof(int) * 10);
    for (j=0; j < 10; j++) {
      letterBuffer[i][j] = getPixel(x+i, y+j);
    }
  }

  for (i=0; i < 10; i++) {
    for (j=0; j < 10; j++) {
      if (letD[10*i+j]!=0){
        putPixel(x + j, y + i, letD[10*i+j]);
      }
    }
	free(letterBuffer[i]);
  }
   free(letterBuffer);
}

void letterShowE(int x, int y) {
  int i,j;
  //allocates memory and returns pointer to it
  //receives size to allocate
  letterBuffer = malloc(sizeof(int) * 10);
  for (i= 0; i < 10; i++) {
    letterBuffer[i] = malloc(sizeof(int) * 10);
    for (j=0; j < 10; j++) {
      letterBuffer[i][j] = getPixel(x+i, y+j);
    }
  }

  for (i=0; i < 10; i++) {
    for (j=0; j < 10; j++) {
      if (letE[10*i+j]!=0){
        putPixel(x + j, y + i, letE[10*i+j]);
      }
    }
	free(letterBuffer[i]);
  }
   free(letterBuffer);
}

void letterShowF(int x, int y) {
  int i,j;
  //allocates memory and returns pointer to it
  //receives size to allocate
  letterBuffer = malloc(sizeof(int) * 10);
  for (i= 0; i < 10; i++) {
    letterBuffer[i] = malloc(sizeof(int) * 10);
    for (j=0; j < 10; j++) {
      letterBuffer[i][j] = getPixel(x+i, y+j);
    }
  }

  for (i=0; i < 10; i++) {
    for (j=0; j < 10; j++) {
      if (letF[10*i+j]!=0){
        putPixel(x + j, y + i, letF[10*i+j]);
      }
    }
	free(letterBuffer[i]);
  }
   free(letterBuffer);
}

void letterShowG(int x, int y) {
  int i,j;
  //allocates memory and returns pointer to it
  //receives size to allocate
  letterBuffer = malloc(sizeof(int) * 10);
  for (i= 0; i < 10; i++) {
    letterBuffer[i] = malloc(sizeof(int) * 10);
    for (j=0; j < 10; j++) {
      letterBuffer[i][j] = getPixel(x+i, y+j);
    }
  }

  for (i=0; i < 10; i++) {
    for (j=0; j < 10; j++) {
      if (letG[10*i+j]!=0){
        putPixel(x + j, y + i, letG[10*i+j]);
      }
    }
	free(letterBuffer[i]);
  }
   free(letterBuffer);
}

void letterShowH(int x, int y) {
  int i,j;
  //allocates memory and returns pointer to it
  //receives size to allocate
  letterBuffer = malloc(sizeof(int) * 10);
  for (i= 0; i < 10; i++) {
    letterBuffer[i] = malloc(sizeof(int) * 10);
    for (j=0; j < 10; j++) {
      letterBuffer[i][j] = getPixel(x+i, y+j);
    }
  }

  for (i=0; i < 10; i++) {
    for (j=0; j < 10; j++) {
      if (letH[10*i+j]!=0){
        putPixel(x + j, y + i, letH[10*i+j]);
      }
    }
	free(letterBuffer[i]);
  }
   free(letterBuffer);
}

void letterShowI(int x, int y) {
  int i,j;
  //allocates memory and returns pointer to it
  //receives size to allocate
  letterBuffer = malloc(sizeof(int) * 10);
  for (i= 0; i < 10; i++) {
    letterBuffer[i] = malloc(sizeof(int) * 10);
    for (j=0; j < 10; j++) {
      letterBuffer[i][j] = getPixel(x+i, y+j);
    }
  }

  for (i=0; i < 10; i++) {
    for (j=0; j < 10; j++) {
      if (letI[10*i+j]!=0){
        putPixel(x + j, y + i, letI[10*i+j]);
      }
    }
	free(letterBuffer[i]);
  }
   free(letterBuffer);
}

void letterShowJ(int x, int y) {
  int i,j;
  //allocates memory and returns pointer to it
  //receives size to allocate
  letterBuffer = malloc(sizeof(int) * 10);
  for (i= 0; i < 10; i++) {
    letterBuffer[i] = malloc(sizeof(int) * 10);
    for (j=0; j < 10; j++) {
      letterBuffer[i][j] = getPixel(x+i, y+j);
    }
  }

  for (i=0; i < 10; i++) {
    for (j=0; j < 10; j++) {
      if (letJ[10*i+j]!=0){
        putPixel(x + j, y + i, letJ[10*i+j]);
      }
    }
	free(letterBuffer[i]);
  }
   free(letterBuffer);
}

void letterShowK(int x, int y) {
  int i,j;
  //allocates memory and returns pointer to it
  //receives size to allocate
  letterBuffer = malloc(sizeof(int) * 10);
  for (i= 0; i < 10; i++) {
    letterBuffer[i] = malloc(sizeof(int) * 10);
    for (j=0; j < 10; j++) {
      letterBuffer[i][j] = getPixel(x+i, y+j);
    }
  }

  for (i=0; i < 10; i++) {
    for (j=0; j < 10; j++) {
      if (letK[10*i+j]!=0){
        putPixel(x + j, y + i, letK[10*i+j]);
      }
    }
	free(letterBuffer[i]);
  }
   free(letterBuffer);
}

void letterShowL(int x, int y) {
  int i,j;
  //allocates memory and returns pointer to it
  //receives size to allocate
  letterBuffer = malloc(sizeof(int) * 10);
  for (i= 0; i < 10; i++) {
    letterBuffer[i] = malloc(sizeof(int) * 10);
    for (j=0; j < 10; j++) {
      letterBuffer[i][j] = getPixel(x+i, y+j);
    }
  }

  for (i=0; i < 10; i++) {
    for (j=0; j < 10; j++) {
      if (letL[10*i+j]!=0){
        putPixel(x + j, y + i, letL[10*i+j]);
      }
    }
	free(letterBuffer[i]);
  }
   free(letterBuffer);
}

void letterShowM(int x, int y) {
  int i,j;
  //allocates memory and returns pointer to it
  //receives size to allocate
  letterBuffer = malloc(sizeof(int) * 10);
  for (i= 0; i < 10; i++) {
    letterBuffer[i] = malloc(sizeof(int) * 10);
    for (j=0; j < 10; j++) {
      letterBuffer[i][j] = getPixel(x+i, y+j);
    }
  }

  for (i=0; i < 10; i++) {
    for (j=0; j < 10; j++) {
      if (letM[10*i+j]!=0){
        putPixel(x + j, y + i, letM[10*i+j]);
      }
    }
	free(letterBuffer[i]);
  }
   free(letterBuffer);
}

void letterShowN(int x, int y) {
  int i,j;
  //allocates memory and returns pointer to it
  //receives size to allocate
  letterBuffer = malloc(sizeof(int) * 10);
  for (i= 0; i < 10; i++) {
    letterBuffer[i] = malloc(sizeof(int) * 10);
    for (j=0; j < 10; j++) {
      letterBuffer[i][j] = getPixel(x+i, y+j);
    }
  }

  for (i=0; i < 10; i++) {
    for (j=0; j < 10; j++) {
      if (letN[10*i+j]!=0){
        putPixel(x + j, y + i, letN[10*i+j]);
      }
    }
	free(letterBuffer[i]);
  }
   free(letterBuffer);
}

void letterShowO(int x, int y) {
  int i,j;
  //allocates memory and returns pointer to it
  //receives size to allocate
  letterBuffer = malloc(sizeof(int) * 10);
  for (i= 0; i < 10; i++) {
    letterBuffer[i] = malloc(sizeof(int) * 10);
    for (j=0; j < 10; j++) {
      letterBuffer[i][j] = getPixel(x+i, y+j);
    }
  }

  for (i=0; i < 10; i++) {
    for (j=0; j < 10; j++) {
      if (letO[10*i+j]!=0){
        putPixel(x + j, y + i, letO[10*i+j]);
      }
    }
	free(letterBuffer[i]);
  }
   free(letterBuffer);
}

void letterShowP(int x, int y) {
  int i,j;
  //allocates memory and returns pointer to it
  //receives size to allocate
  letterBuffer = malloc(sizeof(int) * 10);
  for (i= 0; i < 10; i++) {
    letterBuffer[i] = malloc(sizeof(int) * 10);
    for (j=0; j < 10; j++) {
      letterBuffer[i][j] = getPixel(x+i, y+j);
    }
  }

  for (i=0; i < 10; i++) {
    for (j=0; j < 10; j++) {
      if (letP[10*i+j]!=0){
        putPixel(x + j, y + i, letP[10*i+j]);
      }
    }
	free(letterBuffer[i]);
  }
   free(letterBuffer);
}

void letterShowQ(int x, int y) {
  int i,j;
  //allocates memory and returns pointer to it
  //receives size to allocate
  letterBuffer = malloc(sizeof(int) * 10);
  for (i= 0; i < 10; i++) {
    letterBuffer[i] = malloc(sizeof(int) * 10);
    for (j=0; j < 10; j++) {
      letterBuffer[i][j] = getPixel(x+i, y+j);
    }
  }

  for (i=0; i < 10; i++) {
    for (j=0; j < 10; j++) {
      if (letQ[10*i+j]!=0){
        putPixel(x + j, y + i, letQ[10*i+j]);
      }
    }
	free(letterBuffer[i]);
  }
   free(letterBuffer);
}

void letterShowR(int x, int y) {
  int i,j;
  //allocates memory and returns pointer to it
  //receives size to allocate
  letterBuffer = malloc(sizeof(int) * 10);
  for (i= 0; i < 10; i++) {
    letterBuffer[i] = malloc(sizeof(int) * 10);
    for (j=0; j < 10; j++) {
      letterBuffer[i][j] = getPixel(x+i, y+j);
    }
  }

  for (i=0; i < 10; i++) {
    for (j=0; j < 10; j++) {
      if (letR[10*i+j]!=0){
        putPixel(x + j, y + i, letR[10*i+j]);
      }
    }
	free(letterBuffer[i]);
  }
   free(letterBuffer);
}

void letterShowS(int x, int y) {
  int i,j;
  //allocates memory and returns pointer to it
  //receives size to allocate
  letterBuffer = malloc(sizeof(int) * 10);
  for (i= 0; i < 10; i++) {
    letterBuffer[i] = malloc(sizeof(int) * 10);
    for (j=0; j < 10; j++) {
      letterBuffer[i][j] = getPixel(x+i, y+j);
    }
  }

  for (i=0; i < 10; i++) {
    for (j=0; j < 10; j++) {
      if (letS[10*i+j]!=0){
        putPixel(x + j, y + i, letS[10*i+j]);
      }
    }
	free(letterBuffer[i]);
  }
   free(letterBuffer);
}

void letterShowT(int x, int y) {
  int i,j;
  //allocates memory and returns pointer to it
  //receives size to allocate
  letterBuffer = malloc(sizeof(int) * 10);
  for (i= 0; i < 10; i++) {
    letterBuffer[i] = malloc(sizeof(int) * 10);
    for (j=0; j < 10; j++) {
      letterBuffer[i][j] = getPixel(x+i, y+j);
    }
  }

  for (i=0; i < 10; i++) {
    for (j=0; j < 10; j++) {
      if (letT[10*i+j]!=0){
        putPixel(x + j, y + i, letT[10*i+j]);
      }
    }
	free(letterBuffer[i]);
  }
   free(letterBuffer);
}

void letterShowU(int x, int y) {
  int i,j;
  //allocates memory and returns pointer to it
  //receives size to allocate
  letterBuffer = malloc(sizeof(int) * 10);
  for (i= 0; i < 10; i++) {
    letterBuffer[i] = malloc(sizeof(int) * 10);
    for (j=0; j < 10; j++) {
      letterBuffer[i][j] = getPixel(x+i, y+j);
    }
  }

  for (i=0; i < 10; i++) {
    for (j=0; j < 10; j++) {
      if (letU[10*i+j]!=0){
        putPixel(x + j, y + i, letU[10*i+j]);
      }
    }
	free(letterBuffer[i]);
  }
   free(letterBuffer);
}

void letterShowV(int x, int y) {
  int i,j;
  //allocates memory and returns pointer to it
  //receives size to allocate
  letterBuffer = malloc(sizeof(int) * 10);
  for (i= 0; i < 10; i++) {
    letterBuffer[i] = malloc(sizeof(int) * 10);
    for (j=0; j < 10; j++) {
      letterBuffer[i][j] = getPixel(x+i, y+j);
    }
  }

  for (i=0; i < 10; i++) {
    for (j=0; j < 10; j++) {
      if (letV[10*i+j]!=0){
        putPixel(x + j, y + i, letV[10*i+j]);
      }
    }
	free(letterBuffer[i]);
  }
   free(letterBuffer);
}

void letterShowW(int x, int y) {
  int i,j;
  //allocates memory and returns pointer to it
  //receives size to allocate
  letterBuffer = malloc(sizeof(int) * 10);
  for (i= 0; i < 10; i++) {
    letterBuffer[i] = malloc(sizeof(int) * 10);
    for (j=0; j < 10; j++) {
      letterBuffer[i][j] = getPixel(x+i, y+j);
    }
  }

  for (i=0; i < 10; i++) {
    for (j=0; j < 10; j++) {
      if (letW[10*i+j]!=0){
        putPixel(x + j, y + i, letW[10*i+j]);
      }
    }
	free(letterBuffer[i]);
  }
   free(letterBuffer);
}

void letterShowX(int x, int y) {
  int i,j;
  //allocates memory and returns pointer to it
  //receives size to allocate
  letterBuffer = malloc(sizeof(int) * 10);
  for (i= 0; i < 10; i++) {
    letterBuffer[i] = malloc(sizeof(int) * 10);
    for (j=0; j < 10; j++) {
      letterBuffer[i][j] = getPixel(x+i, y+j);
    }
  }

  for (i=0; i < 10; i++) {
    for (j=0; j < 10; j++) {
      if (letX[10*i+j]!=0){
        putPixel(x + j, y + i, letX[10*i+j]);
      }
    }
	free(letterBuffer[i]);
  }
   free(letterBuffer);
}

void letterShowY(int x, int y) {
  int i,j;
  //allocates memory and returns pointer to it
  //receives size to allocate
  letterBuffer = malloc(sizeof(int) * 10);
  for (i= 0; i < 10; i++) {
    letterBuffer[i] = malloc(sizeof(int) * 10);
    for (j=0; j < 10; j++) {
      letterBuffer[i][j] = getPixel(x+i, y+j);
    }
  }

  for (i=0; i < 10; i++) {
    for (j=0; j < 10; j++) {
      if (letY[10*i+j]!=0){
        putPixel(x + j, y + i, letY[10*i+j]);
      }
    }
	free(letterBuffer[i]);
  }
   free(letterBuffer);
}

void letterShowZ(int x, int y) {
  int i,j;
  //allocates memory and returns pointer to it
  //receives size to allocate
  letterBuffer = malloc(sizeof(int) * 10);
  for (i= 0; i < 10; i++) {
    letterBuffer[i] = malloc(sizeof(int) * 10);
    for (j=0; j < 10; j++) {
      letterBuffer[i][j] = getPixel(x+i, y+j);
    }
  }

  for (i=0; i < 10; i++) {
    for (j=0; j < 10; j++) {
      if (letZ[10*i+j]!=0){
        putPixel(x + j, y + i, letZ[10*i+j]);
      }
    }
	free(letterBuffer[i]);
  }
   free(letterBuffer);
}