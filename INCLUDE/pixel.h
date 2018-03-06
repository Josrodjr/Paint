
struct Lista{
  int x;
  int y;
  struct Lista* next;
};

//pixel.h con metodos para hacer calculos de pantalla

void setVESA(int modo){
	asm {
		MOV AX, 04F02h
		MOV BX, modo
		INT 10h		
	}
}

void putPixel(int x, int y, unsigned char color){
	
	
	//Calcular el Offset que vamos a utilizar 
	//Restricciones: Solo valido para 640x480x256 
	asm {
		
		MOV BX, 640
		MOV AX, y
		MUL BX
		ADD AX, x
		ADC DX, 0
		PUSH AX
		
	}
	
	//Cambiar a otro banco
	asm {
		
		MOV AX, 04F05h
		XOR BX, BX
		INT 010h
		//lo que almacenamos en el push de AX
		POP DI
		
		//direccion de el primer pixel
		MOV AX, 0a000h
		MOV ES, AX
		
		//cargar el color a utilizar en dl
		MOV CL, color
		//poner el color en el pixel con el offset calculado anteriormente
		MOV[ES:DI], CL;
		
	}
	
}

unsigned char getPixel(int x, int y){
	
	unsigned char color;
	//Calcular el Offset que vamos a utilizar 
	//Restricciones: Solo valido para 640x480x256 
	asm {
		
		MOV BX, 640
		MOV AX, y
		MUL BX
		ADD AX, x
		ADC DX, 0
		PUSH AX
		
	}
	
	//Cambiar a otro banco
	asm {
		
		MOV AX, 04F05h
		XOR BX, BX
		INT 010h
		//lo que almacenamos en el push de AX
		POP DI
		
		//direccion de el primer pixel
		MOV AX, 0a000h
		MOV ES, AX
		
		//cargar el color a utilizar en dl
		MOV CL, color
		//poner el color en el pixel con el offset calculado anteriormente
		MOV CL, [ES:DI];
		
		MOV color, CL
		
	}
	return color;
}

//cambiar el grosor de el putpixel, SOLO FUNCIONA 1^2, 3^2, 5^2
int cambiarGrosor(int x, int y, int radio, unsigned char color){
	
	if (x < 480 && y < 400){
		
		while (radio >= 1){
			
			switch(radio){
				case 1 :
					putPixel(x, y, color);
					break;
				case 2 :
					putPixel(x+1, y, color);
					putPixel(x+1, y+1, color);
					putPixel(x+1, y-1, color);
					putPixel(x-1, y, color);
					putPixel(x-1, y-1, color);
					putPixel(x-1, y+1, color);
					putPixel(x, y+1, color);
					putPixel(x, y-1, color);
					break;
				case 3 :
					putPixel(x+2, y, color);
					putPixel(x+2, y+2, color);
					putPixel(x+2, y-2, color);
					putPixel(x-2, y, color);
					putPixel(x-2, y-2, color);
					putPixel(x-2, y+2, color);
					putPixel(x, y+2, color);
					putPixel(x, y-2, color);
					
					putPixel(x+1, y-2, color);
					putPixel(x+2, y-1, color);
					putPixel(x+2, y+1, color);
					putPixel(x+1, y+2, color);
					putPixel(x-1, y+2, color);
					putPixel(x-2, y+1, color);
					putPixel(x-2, y-1, color);
					putPixel(x-1, y-2, color);
			}
			radio = radio -1;
			
		}
	}
	
	return 0;
}
//Funcion utilizada para el spray
void randopixel (int x, int y, int radio, unsigned char color){
	int r1 = radio*2;
	int pix = rand() % r1;
	int pix2 = rand() % r1;
	putPixel(x+pix,y+pix2,color);
	putPixel(x-pix2,y-pix,color);
	putPixel(x-pix,y+pix2,color);
	putPixel(x+pix2,y-pix,color);
	delay(5);
	
}

//https://jee-appy.blogspot.com/2011/10/flood-fill-program-in-c.html

/*
void flodfill(int x,int y,unsigned char f){
	unsigned char c;
	c=getPixel(x,y);
	if(c != f){
		//pintar el pixel central
		putPixel(x,y,f);
		//recursividad
		flodfill(x+1,y,f);
		flodfill(x,y+1,f);
		flodfill(x+1,y+1,f);
		flodfill(x-1,y-1,f);
		flodfill(x-1,y,f);
		flodfill(x,y-1,f);
		flodfill(x-1,y+1,f);
		flodfill(x+1,y-1,f);
	}
}
*/

//clear mistake utilizado para la funcion de texto y el getchar

void clearmistake (unsigned char cColor){
	int i, j;
		for (i =0; i < 8; i++){
			for (j =0; j <400; j++){
				putPixel(i, j, cColor);
			}
		}
	//line_fast(mX1, mY1, mX1, mY2, 1, cColor);
}

int insert_list(int x, int y, struct Lista** listaanterior){
    struct Lista* a;
    a = (struct Lista*) malloc (sizeof (struct Lista));
    a->x = x;
    a->y = y;
    a->next = NULL;
    (*listaanterior)->next = a;
    *listaanterior = (*listaanterior)->next;
    return 1;
}

//floodfill de figura utilizando implementacion de lista
//http://arunmvishnu.com/programming/c-and-c/c-program-to-implement-a-stack-using-linked-list.html

void floodfill(int x, int y, unsigned char color_base, unsigned char color_nuevo){
    struct Lista *ultimo_pixel, *primer_pixel, *temporal;
    primer_pixel = (struct Lista*) malloc (sizeof (struct Lista));
   
    if (color_base == color_nuevo)
    {
      free (primer_pixel);
      return;
    }
    primer_pixel->x = x;
    primer_pixel->y = y;
    primer_pixel->next = NULL;
    ultimo_pixel = primer_pixel;

    while (primer_pixel != NULL){
      putPixel (x, y, color_nuevo);
	  //cambiarGrosor(x,y,1,color_nuevo);
	  
	  if (getPixel (x+1, y) == color_base){
        putPixel (x+1, y, color_nuevo);
		//cambiarGrosor(x+1,y,1,color_nuevo);
        insert_list(x+1, y, &ultimo_pixel);
      }

      if (getPixel (x, y+1) == color_base){
        putPixel (x, y+1, color_nuevo);
		//cambiarGrosor(x,y+1,1,color_nuevo);
        insert_list(x, y+1, &ultimo_pixel);
      }

      if (getPixel (x-1, y) == color_base){
        putPixel (x-1, y, color_nuevo);
		//cambiarGrosor(x-1,y,1,color_nuevo);
        insert_list(x-1, y, &ultimo_pixel);
      }
	  
	   if (getPixel (x, y-1) == color_base){
        putPixel (x, y-1, color_nuevo);
		//cambiarGrosor(x,y-1,1,color_nuevo);
        insert_list(x, y-1, &ultimo_pixel);
      }

      temporal = primer_pixel;
      primer_pixel = primer_pixel->next;
      x = primer_pixel->x;
      y = primer_pixel->y;
      free (temporal);
	  //delay(1);
    }
}
