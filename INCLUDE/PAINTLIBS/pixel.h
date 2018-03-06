
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