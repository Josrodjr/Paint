//UTILIZACION DE LAB, LIBRERIA TOMADA DE: http://nawinbalu.lockernerd.co.uk/documents/tech/AtoZ%20about%20Cprog.pdf?i=1
//PAG 154
//#include "pixel.h"
#define W 16
#define B 255

/*-----------------------------------------------
InitMouse - Initializes Mouse.
Returns 0 for success. */
int InitMouse( void ){
asm {
	MOV AX, 0;
	INT 33h;
	}
return;
} /*--InitMouse( )---*/


/*-----------------------------------------------
ShowMousePtr - Shows Mouse Pointer. */
void ShowMousePtr( void ){
asm {
	MOV AX, 1h;
	INT 33h;
	}
} /*--ShowMousePtr( )----*/


/*-----------------------------------------------
HideMousePtr - Hide Mouse Pointer. */
void HideMousePtr( void ){
asm {
	MOV AX, 2h;
	INT 33h;
	}
} /*--HideMousePtr( )-----*/


/*-----------------------------------------------
MoveMousePtr - Move Mouse Pointer
to (x, y). */
void MoveMousePtr( int x, int y ){
asm {
	MOV AX, 4h;
	MOV CX, x;
	MOV DX, y;
	INT 33h;
	}
} /*--MoveMousePtr( )-----*/


/*-----------------------------------------------
RestrictMousePtr - Restrict Mouse Pointer
to the specified coordinates */
void RestrictMousePtr( int x1, int y1, int x2, int y2 ){
asm {
	MOV AX, 7h;
	MOV CX, x1;
	MOV DX, x2;
	INT 33h;
	MOV AX, 8h;
	MOV CX, y1;
	MOV DX, y2;
	INT 33h;
	}
} /*--RestrictMousePtr( )--------*/



/*-----------------------------------------------
GetMousePos - Gets Mouse position & mouse button value. */
void GetMousePos(int *mX, int *mY, int *mB){
	int mouseB, mouseX, mouseY;
asm {
	MOV AX, 03h
	INT 33h
	AND BX, 11B
	MOV mouseB, BX
	MOV mouseX, CX
	MOV mouseY, DX
	}
	*mB = mouseB;
	*mX = mouseX;
	*mY = mouseY;
	
} /*--GetMousePos( )------*/

//metodos para generar un mouse y reemplazarlo a lo largo de la pantalla

unsigned int ** mouseBuffer;

static unsigned char maus[10 * 10] =
{
	W,W,W,0,0,0,0,0,0,0,
	W,B,B,W,0,0,0,0,0,0,
	W,B,W,B,W,0,0,0,0,0,
	W,B,W,W,B,W,0,0,0,0,
	W,B,W,0,W,B,W,0,0,0,
	W,B,W,0,0,W,B,W,0,0,
	W,B,W,0,0,0,W,B,W,0,
	W,B,W,W,W,W,W,W,B,W,
	W,B,B,B,B,B,B,B,B,W,
	W,W,W,W,W,W,W,W,W,0,
};
void mouseShow(int x, int y) {
  int i,j;
  //declarar memoria para realizar la impresion del mouse
  mouseBuffer = malloc(sizeof(int) * 10);
  for (i= 0; i < 10; i++) {
    mouseBuffer[i] = malloc(sizeof(int) * 10);
    for (j=0; j < 10; j++) {
      mouseBuffer[i][j] = getPixel(x+i, y+j);
    }
  }

  for (i=0; i < 10; i++) {
    for (j=0; j < 10; j++) {
      if (maus[10*i+j]!=0){
        putPixel(x + j, y + i, maus[10*i+j]);
      }
    }
  }
}

//despintar el mouse de la screen
void mouseHide(int x, int y) {
  int i,j;
  for (i=0; i < 10; i++) {
    for (j=0; j < 10; j++) {
      putPixel(x+i,y+j,mouseBuffer[i][j]);
    }
    //liberar la memoria
    free(mouseBuffer[i]);
  }
  //liberar memoria
  free(mouseBuffer);
}


//Revisa el cambio en la posicion de el mouse y si existe un cambio en y 
//o en, lo pinta en la nueva posicion y lo despinta en la posicion vieja.
void repaintMouse(int *x, int *y, int *boton, int *x_temp, int *y_temp) {
  GetMousePos(x, y, boton);
  if (*x_temp != *x || *y_temp != *y) {
	//mouseShow(*x_temp, *y_temp);
    mouseHide(*x_temp, *y_temp);
    mouseShow(*x, *y);
    *x_temp = *x;
    *y_temp = *y;
  }
}







