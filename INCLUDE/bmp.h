
/**************************************************************************
 * palette.c                                                              *
 * written by David Brackeen                                              *
 * http://www.brackeen.com/home/vga/                                      *
 *                                                                        *
 * This is a 16-bit program.                                              *
 * Tab stops are set to 2.                                                *
 * Remember to compile in the LARGE memory model!                         *
 * To compile in Borland C: bcc -ml palette.c                             *
 *                                                                        *
 * This program will only work on DOS- or Windows-based systems with a    *
 * VGA, SuperVGA or compatible video adapter.                             *
 *                                                                        *
 * Please feel free to copy this source code.                             *
 *                                                                        *
 * DESCRIPTION: This program demostrates palette manipulation and         *
 * vertical retrace sychronization.                                       *
 **************************************************************************/
 
 //the structure for a bitmap.

typedef struct bmp {
  int width;
  int height;
  char palette[256*3];
  char *data;
} BITMAP;

/**************************************************************************
 *  fskip                                                                 *
 *     Skips bytes in a file.                                             *
 **************************************************************************/

void fskip(FILE *fp, int num_bytes)
{
   int i;
   for (i=0; i<num_bytes; i++)
      fgetc(fp);
}

/**************************************************************************
 *  set_palette                                                           *
 *    Sets all 256 colors of the palette.                                 *
 **************************************************************************/

void set_palette(char far *palette){
  asm {
    les dx, [palette]
    mov ax, 0x1012
    mov bx, 0
    mov cx, 256
    int 0x10
  }
}

/**************************************************************************
 *  load_bmp                                                              *
 *    Loads a bitmap file into memory.                                    *
 **************************************************************************/

void load_bmp(int x, int y, char *file, BITMAP *b, int key)
{
  int i, j;
  FILE *fp;
  long index;
  int num_colors;

  /* open the file */
  if ((fp = fopen(file,"rb")) == NULL)
  {
    printf("Error opening file %s.\n",file);
    exit(1);
  }

  /* check to see if it is a valid bitmap file */
  if (fgetc(fp)!='B' || fgetc(fp)!='M')
  {
    fclose(fp);
    exit(1);
  }

  /* read in the width and height of the image, and the
     number of colors used; ignore the rest */
  fskip(fp,16);
  fread(&b->width, 2, 1, fp);
  fskip(fp,2);
  fread(&b->height, 2, 1, fp);
  fskip(fp,22);
  fread(&num_colors, 2, 1, fp);
  fskip(fp,6);

  /* assume we are working with an 8-bit file */
  if (num_colors==0) num_colors=256;

  /* try to allocate memory */
  /*
  if ((b->data = (byte *) malloc((word)(b->width*b->height))) == NULL)
  {
    fclose(fp);
    printf("Error allocating memory for file %s.\n",file);
    exit(1);
  }
  */

  /* read the palette information */
  for(index=0;index<num_colors;index++)
  {
    b->palette[(int)(index*3+2)] = fgetc(fp) >> 2;
    b->palette[(int)(index*3+1)] = fgetc(fp) >> 2;
    b->palette[(int)(index*3)] = fgetc(fp) >> 2;
    fgetc(fp);
  }
  
  set_palette(b->palette);
  
  if(key == 0){
	  /* read the bitmap */
	  for(j = (b->height + y); j >=0 ;j--){
		for(i=0; i < b->width ; i++){
		  putPixel(i+x, j, fgetc(fp));
		  //cambiarGrosor(i+x, j, 1, fgetc(fp));
		}
	  }
  }
  
  if(key == 1){
	    /* read the bitmap */
	  for(j = (b->height + y); j >= (b->height) ;j--){
		for(i=0; i < b->width ; i++){
		  //putPixel(i+x, j, fgetc(fp));
		  cambiarGrosor(i+x, j, 1, fgetc(fp));
		}
	  }
  }
  
  fclose(fp);
}

/**************************************************************************
 *  guardar_imagen                                                        *
 *    Load canvas to file into memory.                                    *
 **************************************************************************/
 
 
 void guardar_imagen(int x, int y, int xmax, int ymax, char file[])
 {
  FILE * fileSave;
  int count, i, j;
  unsigned char pixel;
  unsigned long headerBuf[13];
  long palette[256];
  char headerInfo[2] = "BM";
  //opens file
  fileSave = fopen(file, "wb");
  fwrite(headerInfo, sizeof(headerInfo[0]), 2, fileSave);
  x--; y--;                          

//Header del Bitmap  
  headerBuf[0] = xmax * ymax + 1024 + 54;  
  headerBuf[1] = 0;              
  //offset
  headerBuf[2] = 1024 + 54;                   
  //tamanio de header
  headerBuf[3] = 40;                          
  //ancho de la imagen
  headerBuf[4] = xmax;                       
  //largo de la imagen
  headerBuf[5] = ymax;                      
  headerBuf[6] = 0x80001;       
  //compresion  
  headerBuf[7] = 0;                           
  headerBuf[8] = xmax*ymax;                
  headerBuf[9] = 0;             
  headerBuf[10] = 0;            
  // colores
  headerBuf[11] = 256;                          
  headerBuf[12] = 256;                          
  fwrite(headerBuf, sizeof(headerBuf[0]), 13,  fileSave);
  //set_palette(palette);
  palette[0] = 0;
  palette[1] = 0x8;
  palette[2] = 0x800;
  palette[3] = 0x808;
  palette[4] = 0x80000;
  palette[5] = 0x80008;
  palette[6] = 0x80400;
  palette[7] = 0xC0C0C;
  palette[8] = 0x80808;
  palette[9] = 0xFF;
  palette[10] = 0xFF00;
  palette[11] = 0xFFFF;
  palette[12] = 0xFF0000;
  palette[13] = 0xFF00FF;
  palette[14] = 0xFFFF00;
  palette[15] = 0xFFFFFF;
  fwrite(palette, sizeof(long), 255,  fileSave);
  
  //llenar el bitmap de la informacion contentenida en el area seleccionada
 
  for(j=(y+ymax); j>=y; j--){
    for(i=x; i<=(xmax+x)-1; i++){
     pixel=getPixel(i, j);
     fwrite(&pixel,1,1, fileSave);
    }
  }
  //cerrar la file
  fclose( fileSave);
}
