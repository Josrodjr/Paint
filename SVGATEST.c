#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#include <math.h>

#include "pixel.h"
#include "mouse.h"
#include "bmp.h"
#include "poligon.h"
#include "letter.h"

//modo 640x480x256 
#define SVGA_MODE 0x101
#define NORMAL_MODE 0x03

void main (){
	int i, j, mB, mX, mY, key, tX, tY, tool, radio, boton, mX1, mX2, mY1, mY2, conditions, circleradio;
	int xcentro, ycentro, ellipserx, ellipsery, contadormouse, letra, letterx, lettery;
	float diametro;
	//int px1, px2, py1, py2;
	unsigned char prueba, cColor, cvfullpall, crellenoviejo;
	BITMAP bitmap, bitmapresultado;
	key = 1;
	contadormouse = 1;
	setVESA(SVGA_MODE);
	InitMouse();
	ShowMousePtr();
	
	RestrictMousePtr(0,0,640,480);
	
	load_bmp(160,0, "pepapls5.bmp", &bitmap, 0);
	
	//pintar la paleta de colores
	
	
	for (i =0; i < 480; i=i+10){
		
		for (j =400; j <480; j++){ 
			putPixel(i, j, i);
			putPixel(i+1, j, i);
			putPixel(i+2, j, i);
			putPixel(i+3, j, i);
			putPixel(i+4, j, i);
			putPixel(i+5, j, i);
			putPixel(i+6, j, i);
			putPixel(i+7, j, i);
			putPixel(i+8, j, i);
			putPixel(i+9, j, i);
		}
	}
	
	
	//pintar un canvas blanco
	
	for (i =0; i < 400; i++){
		for (j =0; j <480; j++){
			cvfullpall = getPixel(550, 0);
			putPixel(j, i, cvfullpall);
		}
	}
	

	while (key = 1){
		GetMousePos(&mX, &mY, &mB);
		
		//obtener color de la paleta
		
		if(mY > 400){
			if(mB == 1){
				cColor = getPixel(mX-1, mY-1);
			}
		}
		
		//importante, locamos la ubicacion de la ultima vez que utilizamos el mouse para poner el texto en esta ubicacion
		if(mB == 1){
			if(mX > 0 && mX < 480){
				if(mY > 0 && mY < 400){
					letterx = mX;
					lettery = mY;
				}
			}
		}
		
		if(mB == 1){
			//Revisar los botones
			if(mY < 400 && mY > 367){
				//Radio Pequenio
				if(mX > 495 && mX < 532){
					radio = 1;
					boton = 0;
				}
				//Radio Mediano	
				if(mX > 547 && mX < 583){
					radio = 2;
					boton = 0;
				}
				//Radio Grande
				if(mX > 597 && mX < 634){
					radio = 3;
					boton = 0;
				}
			}
			
			//Para el icono de LINEA
			if (mY < 98 && mY > 50){
				if(mX > 413+160 && mX < 459+160){
					mX1 = 0;
					mY1 = 0;
					mX2 = 0;
					mY2 = 0;
					boton = 1;
				}
			}
			
			//Para el icono de Cuadrado
			if(mY < 301 && mY > 279){
				if(mX > 415+160 && mX < 444+160){
					mX1 = 0;
					mY1 = 0;
					mX2 = 0;
					mY2 = 0;
					boton = 2;
				}
			}
			
			//boton para salir de el programa
			if(mY < 26 && mY > 4){
				if(mX > 449+160 && mX < 475+160){
					setVESA(NORMAL_MODE);
				}
			}
			
			//boton para circulo vacio
			if(mY < 302 && mY > 278){
				if(mX > 372+160 && mX < 403+160){
					boton = 3;
				}				
			}
			
			//boton para el elipse vacio
			if(mY < 299 && mY > 276){
				if(mX > 454+160 && mX < 472+160){
					mX1 = 0;
					mY1 = 0;
					mX2 = 0;
					mY2 = 0;
					boton = 4;
				}
			}
			
			// boton para el spray
			if(mY < 157 && mY > 115){
				if(mX  > 418+160 && mX < 457+160){
					boton = 5;
				}
			}
			
			//boton para el gotero
			if(mY > 114 && mY < 165){
				if(mX > 342+160 && mX < 383+160){
					boton = 6;
				}
			}
			
			//borrador
			if (mY > 176 && mY < 215){
				if(mX < 461+160 && mX > 415+160){
					boton = 7;
				}
			}
			
			
			//boton de nuevo
			if (mY > 7 && mY < 48){
				if (mX > 343+160 && mX < 389+160){
					boton = 13;
				}
			}
			
			//seleccionar
			if (mY > 228 && mY < 264){
				if (mX > 340+160 && mX < 383+160){
					mX1 = 0;
					mY1 = 0;
					mX2 = 0;
					mY2 = 0;
					boton = 8;
				}
			}
			
			//boton de cuadrado relleno
			if (mY >320 && mY < 346){
				if (mX > 414+160 && mX < 444+160){
					mX1 = 0;
					mY1 = 0;
					mX2 = 0;
					mY2 = 0;
					boton = 9;
				}
			}
			
			//boton de circulo relleno
			if (mY > 321 && mY < 346){
				if (mX > 372+160 && mX < 404+160){
					boton = 10;
				}
			}
			
			//boton de guardado
			if (mY > 60 && mY < 98){
				if (mX > 341+160 && mX < 389+160){
					boton = 11;
				}
			}
			
			//boton del undo
			if (mY > 233 && mY < 256){
				if (mX > 413+160 && mX < 466+160){
					boton = 12;
				}
			}
			
			//boton de texto
			if(mY > 9 && mY < 43){
				if(mX > 396+160 && mX < 442+160){
					boton = 14;
				}
			}
			
			//boton para el paste
			
			if(mY > 284 && mY < 350){
				if(mX > 333+160 && mX < 365+160){
					boton = 15;
				}
			}
			
			//boton para la cubeta
			
			if(mY > 177 && mY < 212){
				if(mX > 340+160 && mX < 390+160){
					boton = 16;
				}
			}
			
			//boton para el elipse relleno
			
			if(mY > 320 && mY < 345){
				if(mX > 454+160 && mX < 472+160){
					boton = 17;
				}
			}
			
			//Switch para los casos de los botones
			
			switch (boton) {
				//CASO 1: LINEA
				case 1:
					while(1){
						GetMousePos(&mX, &mY, &mB);
						//si esta dentro del canvas
						if (mX < 480 && mY < 400){
							//ver si es el default state
							if(mB == 1 && mX1 == 0 && mY1 == 0 && mX2 == 0 && mY2 ==0){
								mX2 = mX;
								mY2 = mY;
							}
							//pintar la linea con los dos puntos extra
							else if(mB == 1 && mX != mX1 && mY != mY1){
								mX1 = mX2;
								mY1 = mY2;
								mX2 = mX;
								mY2 = mY;
								mouseHide(mX, mY);
								line_fast(mX1, mY1, mX2, mY2, radio, cColor);
								mouseShow(mX, mY);
							}
							break;
						}
					}
					break;
				//CASO 0: Pincel Normal	
				case 0: 
				//Pintar en el canvas solo
					if (mX < 480 && mY < 400){
						if (mB == 1){
							cambiarGrosor(mX-3, mY-5, radio, cColor);
						}
					}
					break;
				//Cuadrado Vacio
				case 2:
					while(1){
						GetMousePos(&mX, &mY, &mB);
						//si esta dentro del canvas
						if (mX < 480 && mY < 400){
							//ver si es el default state
							if(mB == 1 && mX1 == 0 && mY1 == 0 && mX2 == 0 && mY2 ==0){
								mX2 = mX;
								mY2 = mY;
							}
							//pintar la linea con los dos puntos extra
							else if(mB == 1 && mX != mX1 && mY != mY1){
								mX1 = mX2;
								mY1 = mY2;
								mX2 = mX;
								mY2 = mY;
								mouseHide(mX, mY);
								line_fast(mX1, mY1, mX1, mY2, radio, cColor);
								line_fast(mX1, mY1, mX2, mY1, radio, cColor);
								line_fast(mX2, mY1, mX2, mY2, radio, cColor);
								line_fast(mX1, mY2, mX2, mY2, radio, cColor);
								mouseShow(mX, mY);
							}
							break;
						}
					}
					break;
					
					//circulo vacio
					
					case 3:
						while(1){
						GetMousePos(&mX, &mY, &mB);
						//si esta dentro del canvas
						if (mX < 480 && mY < 400){
							//ver si es el default state
							if(mB == 1 && mX1 == 0 && mY1 == 0 && mX2 == 0 && mY2 ==0){
								mX1 = 1;
								mY1 = 1;
								mX2 = 20;
								mY2 = 20;
							}
							//pintar la linea con los dos puntos extra
							else if(mB == 1 && mX != mX1 && mY != mY1){
								mX1 = mX2;
								mY1 = mY2;
								mX2 = mX;
								mY2 = mY;
								radio_value_int(mX1, mX2, mY1, mY2, &circleradio);
								circle_center(mX1, mX2, mY1, mY2, &xcentro, &ycentro);
								mouseHide(mX, mY);
								circle_fast(xcentro, ycentro, circleradio, cColor, radio);
								mouseShow(mX, mY);
							}
							break;
						}
					}
					break;
					
					//elipse vacio
					case 4:
						while(1){
						GetMousePos(&mX, &mY, &mB);
						//si esta dentro del canvas
						if (mX < 480 && mY < 400){
							//ver si es el default state
							if(mB == 1 && mX1 == 0 && mY1 == 0 && mX2 == 0 && mY2 ==0){
								//inicializar las variables con algun valor para la primera run
								mX1 = 1;
								mY1 = 1;
								mX2 = 1;
								mY2 = 1;
								xcentro = mX;
								ycentro = mY;
							}
							//pintar la linea con los dos puntos extra
							if(mB == 1 && mX != mX1 && mY != mY1){
								mX1 = mX2;
								mY1 = mY2;
								mX2 = mX;
								mY2 = mY;
								
								circle_center(mX1, mX2, mY1, mY2, &xcentro, &ycentro);
								ellipserx = radio_ellipse(mX2, mX1);
								ellipsery = radio_ellipse(mY2, mY1);
								mouseHide(mX, mY);
								draw_ellipse(ellipserx, ellipsery, xcentro, ycentro, radio, cColor);
								mouseShow(mX, mY);
								delay(800);
								
							}
							break;
						}
					}
					break;
					
					case 5:
						//Pintar en el canvas solo
						if (mX < 480 && mY < 400){
							if (mB == 1){
								randopixel(mX-3, mY-5, radio, cColor);
							}
						}
					break;
					
					case 6:
						//obtener el color de pintura en la pantalla
						if (mX < 480 && mY < 400){
							if (mB == 1){
								cColor = getPixel(mX-1, mY-1);
							}
						}
					break;
					
					case 7:
						//Pintar en el canvas solo
						if (mX < 480 && mY < 400){
							if (mB == 1){
								mouseHide(mX, mY);
								cambiarGrosor(mX, mY, 3, cvfullpall);
								mouseShow(mX, mY);
							}
						}
					break;
					
					//guardar imagen
					case 8:
					
						while(1){
							GetMousePos(&mX, &mY, &mB);
							//si esta dentro del canvas
							if (mX < 480 && mY < 400){
								//ver si es el default state
								if(mB == 1 && mX1 == 0 && mY1 == 0 && mX2 == 0 && mY2 ==0){
									mX1 = 1;
									mY1 = 1;
									mX2 = 1;
									mY2 = 1;
								}
								//pintar la linea con los dos puntos extra
								else if(mB == 1 && mX != mX1 && mY != mY1){
									mX1 = mX2;
									mY1 = mY2;
									mX2 = mX;
									mY2 = mY;
									mouseHide(mX, mY);
									
									guardar_imagen(mX1, mY1, mX2, mY2, "clip.bmp");	
									//delay(1000);
									
									line_fast(mX1, mY1, mX1, mY2, 1, cvfullpall);
									line_fast(mX1, mY1, mX2, mY1, 1, cvfullpall);
									line_fast(mX2, mY1, mX2, mY2, 1, cvfullpall);
									line_fast(mX1, mY2, mX2, mY2, 1, cvfullpall);
									
									if(mY1 > mY2){
										for (i = mY2; i < mY1; i++){
											line_fast(mX1, i, mX2, i, 1, cvfullpall);
										}
									}
									if(mY2 > mY1){
										for (i = mY1; i < mY2; i++){
											line_fast(mX1, i, mX2, i, 1, cvfullpall);
										}
									}
									
									mouseShow(mX, mY);
								}
								break;
							}
						}
					break;
			
			//Cuadrado Relleno
				case 9:
					while(1){
						GetMousePos(&mX, &mY, &mB);
						//si esta dentro del canvas
						if (mX < 480 && mY < 400){
							//ver si es el default state
							if(mB == 1 && mX1 == 0 && mY1 == 0 && mX2 == 0 && mY2 ==0){
								mX1 = 1;
								mY1 = 1;
								mX2 = 1;
								mY2 = 1;
							}
							//pintar la linea con los dos puntos extra
							else if(mB == 1 && mX != mX1 && mY != mY1){
								mX1 = mX2;
								mY1 = mY2;
								mX2 = mX;
								mY2 = mY;
								mouseHide(mX, mY);
								line_fast(mX1, mY1, mX1, mY2, radio, cColor);
								line_fast(mX1, mY1, mX2, mY1, radio, cColor);
								line_fast(mX2, mY1, mX2, mY2, radio, cColor);
								line_fast(mX1, mY2, mX2, mY2, radio, cColor);
								
								if(mY1 > mY2){
									for (i = mY2; i < mY1; i++){
										line_fast(mX1, i, mX2, i, 1, cColor);
									}
								}
								if(mY2 > mY1){
									for (i = mY1; i < mY2; i++){
										line_fast(mX1, i, mX2, i, 1, cColor);
									}
								}
								mouseShow(mX, mY);
							}
							break;
						}
					}
					break;
					
					//circulo relleno
					case 10:
						while(1){
						GetMousePos(&mX, &mY, &mB);
						//si esta dentro del canvas
						if (mX < 480 && mY < 400){
							//ver si es el default state
							if(mB == 1 && mX1 == 0 && mY1 == 0 && mX2 == 0 && mY2 ==0){
								mX1 = 1;
								mY1 = 1;
								mX2 = 20;
								mY2 = 20;
							}
							//pintar la linea con los dos puntos extra
							else if(mB == 1 && mX != mX1 && mY != mY1){
								mX1 = mX2;
								mY1 = mY2;
								mX2 = mX;
								mY2 = mY;
								radio_value_int(mX1, mX2, mY1, mY2, &circleradio);
								circle_center(mX1, mX2, mY1, mY2, &xcentro, &ycentro);
								mouseHide(mX, mY);
								circle_fast(xcentro, ycentro, circleradio, cColor, radio);
								floodfill(xcentro, ycentro,cvfullpall, cColor);
								mouseShow(mX, mY);
							}
							break;
						}
					}
					break;
					
					//boton de guardar
					case 11:
						guardar_imagen(0, 0, 480, 400, "result.bmp");	
					break;
					
					//boton de undo
					case 12:
						load_bmp(3,-1, "result.bmp", &bitmapresultado, 0);
						//bitmap nominal para obtener su paleta
						load_bmp(0,0, "palette.bmp", &bitmap, 1);
						//delay(1000);
					break;
			
					//boton de nuevo
					case 13:
						for (i =0; i < 400; i++){
							for (j =0; j <480; j++){
								putPixel(j, i, cvfullpall);
							}
						}
					break;
					
					//boton de paste
					case 15:
						
						load_bmp(letterx,lettery, "clip.bmp", &bitmapresultado, 1);
						//bitmap nominal para obtener su paleta
						load_bmp(0,0, "palette.bmp", &bitmap, 1);
						
					break;
			
			
					//boton de texto
					case 14:
					
						while(1){
							
								letra = getch();
								if(letra == 'a'){
									letterShowA(letterx, lettery);
									letterx = letterx +10;
								}
								if(letra == 'b'){
									letterShowB(letterx, lettery);
									letterx = letterx +10;
								}
								if(letra == 'c'){
									letterShowC(letterx, lettery);
									letterx = letterx +10;
								}
								if(letra == 'd'){
									letterShowD(letterx, lettery);
									letterx = letterx +10;
								}
								if(letra == 'e'){
									letterShowE(letterx, lettery);
									letterx = letterx +10;
								}
								if(letra == 'f'){
									letterShowF(letterx, lettery);
									letterx = letterx +10;
								}
								if(letra == 'g'){
									letterShowG(letterx, lettery);
									letterx = letterx +10;
								}
								if(letra == 'h'){
									letterShowH(letterx, lettery);
									letterx = letterx +10;
								}
								if(letra == 'i'){
									letterShowI(letterx, lettery);
									letterx = letterx +10;
								}
								if(letra == 'j'){
									letterShowJ(letterx, lettery);
									letterx = letterx +10;
								}
								if(letra == 'k'){
									letterShowK(letterx, lettery);
									letterx = letterx +10;
								}
								if(letra == 'l'){
									letterShowL(letterx, lettery);
									letterx = letterx +10;
								}
								if(letra == 'm'){
									letterShowM(letterx, lettery);
									letterx = letterx +10;
								}
								if(letra == 'n'){
									letterShowN(letterx, lettery);
									letterx = letterx +10;
								}
								if(letra == 'o'){
									letterShowO(letterx, lettery);
									letterx = letterx +10;
								}
								if(letra == 'p'){
									letterShowP(letterx, lettery);
									letterx = letterx +10;
								}
								if(letra == 'q'){
									letterShowQ(letterx, lettery);
									letterx = letterx +10;
								}
								if(letra == 'r'){
									letterShowR(letterx, lettery);
									letterx = letterx +10;
								}
								if(letra == 's'){
									letterShowS(letterx, lettery);
									letterx = letterx +10;
								}
								if(letra == 't'){
									letterShowT(letterx, lettery);
									letterx = letterx +10;
								}
								if(letra == 'u'){
									letterShowU(letterx, lettery);
									letterx = letterx +10;
								}
								if(letra == 'v'){
									letterShowV(letterx, lettery);
									letterx = letterx +10;
								}
								if(letra == 'w'){
									letterShowW(letterx, lettery);
									letterx = letterx +10;
								}
								if(letra == 'x'){
									letterShowX(letterx, lettery);
									letterx = letterx +10;
								}
								if(letra == 'y'){
									letterShowY(letterx, lettery);
									letterx = letterx +10;
								}
								if(letra == 'z'){
									letterShowZ(letterx, lettery);
									letterx = letterx +10;
								}
								if(letra == ' '){
									letterx = letterx +10;
								}
								if(letra == '\b'){
									for (i =lettery; i < lettery+10; i++){
										for (j =letterx-10; j <letterx; j++){
											putPixel(j, i, cvfullpall);
										}
									}
									letterx = letterx -10;
								}
								if(letra == '\r'){
									letterx = letterx-10;
									lettery = lettery +10;
								}
								if(letra == '.'){
									boton = 0;
									//clearmistake(cvfullpall);
									break;
								}
						}
					break;
			
					case 17:
						while(1){
						GetMousePos(&mX, &mY, &mB);
						//si esta dentro del canvas
						if (mX < 480 && mY < 400){
							//ver si es el default state
							if(mB == 1 && mX1 == 0 && mY1 == 0 && mX2 == 0 && mY2 ==0){
								//inicializar las variables con algun valor para la primera run
								mX1 = 1;
								mY1 = 1;
								mX2 = 1;
								mY2 = 1;
								xcentro = mX;
								ycentro = mY;
							}
							//pintar la linea con los dos puntos extra
							if(mB == 1 && mX != mX1 && mY != mY1){
								mX1 = mX2;
								mY1 = mY2;
								mX2 = mX;
								mY2 = mY;
								
								circle_center(mX1, mX2, mY1, mY2, &xcentro, &ycentro);
								ellipserx = radio_ellipse(mX2, mX1);
								ellipsery = radio_ellipse(mY2, mY1);
								mouseHide(mX, mY);
								draw_ellipse(ellipserx, ellipsery, xcentro, ycentro, radio, cColor);
								floodfill(xcentro, ycentro,cvfullpall, cColor);
								mouseShow(mX, mY);
								delay(800);
								
							}
							break;
						}
					}
					break;
					
					case 16:
						while(1){
							GetMousePos(&mX, &mY, &mB);
							//si esta dentro del canvas
							if (mX < 480 && mY < 400){
								if(mB == 1){
								mouseHide(mX, mY);
								crellenoviejo = getPixel(mX, mY);
								floodfill(mX, mY, crellenoviejo, cColor);
								mouseShow(mX, mY);
								delay(800);
								}
								break;
							}
						}
					break;
			
			}
				
			
		}
		//para que no salga la cucaracha ya que despintamos algo que no hemos empezado a pintar
		if (contadormouse == 1){
			mouseShow(mX, mY);
			mouseHide(mX, mY);
			contadormouse = 0;
		}
		repaintMouse(&mX, &mY, &mB, &tX, &tY);
	}

	getch();
}