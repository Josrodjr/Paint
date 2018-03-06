typedef struct {
	double posX[100];
	double posY[100];
	int centroX;
	int centroY;
} poligono;


int point_in_poligon (int vert_number, poligono *basic, int test_x, int test_y){
	int i,j,c = 0;
	for (i=0, j=vert_number-1; i<vert_number; j = i++){
		if ( ((basic->posY[i]>test_y) != (basic->posY[j]>test_y)) && (test_x<(basic->posX[j]-basic->posX[i]) * (test_y-basic->posY[i])/(basic->posY[j]-basic->posY[i]) + basic->posX[i]) ){
      c = !c;
    }
	}
	return c;
}

void print_poligono (poligono *a, int puntos_imprimir, unsigned char color){
	int i;
	for(i=0; i < puntos_imprimir-1; i++){
		if(a->posX[i] != NULL && a->posY[i] != NULL){
			draw_line((int)a->posX[i], (int)a->posY[i], (int)a->posX[i+1], (int)a->posY[i+1], 2, color);
			//delay(2000);
		}
	}

}

void move_transformation (poligono *basic, int distX, int distY){
	int i, x_old, y_old;

	x_old = basic->centroX;
	y_old = basic->centroY;

	basic->centroX = basic->centroX +distX;
	basic->centroY = basic->centroY +distY;

	for (i=0; i<100; i++){
		basic->posX[i] = (basic->posX[i] - x_old)+basic->centroX;
		basic->posY[i] = (basic->posY[i] - y_old)+basic->centroY;
	}

}

void scale_transformation (poligono *basic, int cambio){

	int i;
	double RDX, AMP;

	RDX = 0.8;
	AMP = 1.2;

	switch (cambio) {
		case 1:
			for(i=0; i<100; i++){
					basic->posX[i] = (double)((basic->posX[i] - basic->centroX)*AMP)+basic->centroX;
					basic->posY[i] = (double)((basic->posY[i] - basic->centroY)*AMP)+basic->centroY;
			}
		break;
		case -1:
			for(i=0; i<100; i++){
				basic->posX[i] = (double)((basic->posX[i] - basic->centroX)*RDX)+basic->centroX;
				basic->posY[i] = (double)((basic->posY[i] - basic->centroY)*RDX)+basic->centroY;
			}
		break;
	}
}

void rotation_transformation (poligono *basic, int degrees){

	//multiiplicar al inicio al final por -1 el Y

	int i;
	double x1, y1, radianes;

	radianes = (degrees*3.14)/180;

	for(i=0; i<100; i++){

			//diferencial entre el cambio en X y Y con respecto al centro de la figura
			x1 = (double)(basic->posX[i] - basic->centroX);
			y1 = (double)(basic->posY[i] - basic->centroY);

			//multiplicamos el diferencial de Y por -1 para obtener los puntos cardesianos correctos
			y1 = (-1)*y1;

			//realizamos la transformacion en el punto 0,0
			x1 = (double) x1*cos(radianes)-y1*sin(radianes);
			y1 = (double) x1*sin(radianes)+y1*cos(radianes);

			//multiplicamos por -1 otra vez el cambio en Y para regresarlo a unidades inversas
			y1 = (-1)*y1;

			//movemos el punto de regreso a donde esta colocado el poligono
			basic->posX[i] = (double) x1 + basic->centroX;
			basic->posY[i] = (double) y1 + basic->centroY;
	}

}

void shear_transformation (poligono *basic, double cambio){
	double x1,y1;
	int i;

	for(i=0; i<100; i++){

		//diferencial entre el cambio en X y Y con respecto al centro de la figura
		x1 = (double)(basic->posX[i] - basic->centroX);
		y1 = (double)(basic->posY[i] - basic->centroY);

		basic->posX[i] = (double) x1 + cambio*y1 + basic->centroX;
		basic->posY[i] = (double) y1 + basic->centroY;

	}
}

//void draw_house
//Arg1: Direccion al struct de poligono
//Arg2: Caso de uso: 1 Nueva casa, 2 update

void draw_house (poligono *name, int caso){

	if(caso == 1){
		name->centroX = 250;
		name->centroY = 250;
	}

	//punto No 1
	name->posX[0]=name->centroX -50;
	name->posY[0]=name->centroY -50;

	//punto No 2
	name->posX[1]=name->centroX;
	name->posY[1]=name->centroY -80;

	//punto No 3
	name->posX[2]=name->centroX +50;
	name->posY[2]=name->centroY -50;

	//punto No 4
	name->posX[3]=name->centroX +50;
	name->posY[3]=name->centroY +50;

	//punto No 5
	name->posX[4]=name->centroX -50;
	name->posY[4]=name->centroY +50;

	//punto No 6
	name->posX[5]=name->centroX -50;
	name->posY[5]=name->centroY -50;

	//punto No 7
	name->posX[6]=name->centroX +50;
	name->posY[6]=name->centroY -50;

	//punto No 8
	name->posX[7]=name->centroX +50;
	name->posY[7]=name->centroY +50;

	//puntos puerta
	//punto No 9
	name->posX[8]=name->centroX +10;
	name->posY[8]=name->centroY +50;

	//punto No 10
	name->posX[9]=name->centroX +10;
	name->posY[9]=name->centroY +10;

	//punto No 11
	name->posX[10]=name->centroX -10;
	name->posY[10]=name->centroY +10;

	//punto No 12
	name->posX[11]=name->centroX -10;
	name->posY[11]=name->centroY +50;

}

void draw_tree (poligono *name, int caso){

	if(caso == 1){
		name->centroX = 400;
		name->centroY = 225;
	}

	//punto No 1
	name->posX[0]=name->centroX -15;
	name->posY[0]=name->centroY +25;

	//punto No 2
	name->posX[1]=name->centroX -65;
	name->posY[1]=name->centroY +25;

	//punto No 3
	name->posX[2]=name->centroX;
	name->posY[2]=name->centroY -100;

	//punto No 4
	name->posX[3]=name->centroX +65;
	name->posY[3]=name->centroY +25;

	//punto No 5
	name->posX[4]=name->centroX +15;
	name->posY[4]=name->centroY +25;

	//punto No 6
	name->posX[5]=name->centroX +15;
	name->posY[5]=name->centroY +75;

	//punto No 7
	name->posX[6]=name->centroX -15;
	name->posY[6]=name->centroY +75;

	//punto No 8
	name->posX[7]=name->centroX -15;
	name->posY[7]=name->centroY +25;

}

int get_max_x (poligono *basic){
	int i, maximo =0;
	for (i=0; i<100; i++){
		if(maximo <= basic->posX[i]){
			maximo = (int) basic->posX[i];
		}
	}
	return maximo;
}

int get_max_y (poligono *basic){
	int i, maximo =0;
	for (i=0; i<100; i++){
		if(maximo <= basic->posY[i]){
			maximo = (int) basic->posY[i];
		}
	}
	return maximo;
}

int get_min_y (poligono *basic, int puntos){
	int i, minimo;
	for (i=0; i<puntos-1; i++){
		if(minimo >= basic->posY[i]){
			minimo = (int) basic->posY[i];
		}
	}
	return minimo;
}

int get_min_x (poligono *basic, int puntos){
	int i, minimo;
	for (i=0; i<puntos-1; i++){
		if(minimo >= basic->posX[i]){
			minimo = (int) basic->posX[i];
		}
	}
	return minimo;
}

void clear_screen (){
	int i,j;
	for(i=0;i<640;i++){
		for(j=480;j>0;j--){
					putGrosor(i,j,1,0);
		}
	}
}

void fill_polygon (poligono *basic, int vertices, unsigned char color){
	int x_min, x_max, y_min, y_max, i, j;
	int point =0;
/*
	x_min = get_min_x(&basic, vertices);
	y_min = get_min_y(&basic, vertices);
	x_max = get_max_x(&basic);
	y_max = get_max_y(&basic);
*/


	//printf("%d\n", x_min);
	//printf("%d\n", y_min);
	//printf("%d\n", y_max);
	//printf("%d\n", y_max);

/*
	for(i=x_min;i<x_max;i++){
		for(j=y_max;j>y_min;j--){
				point = point_in_poligon(vertices, &basic, i, j);
				if (point == 1){
					putGrosor(i,j,1,color);
				}
		}
	}
	*/

	for(i=0;i<640;i++){
		for(j=480;j>0;j--){
				point = point_in_poligon(vertices, &basic, i, j);
				if (point == 1){
					putGrosor(i,j,1,color);
				}
		}
	}
}
