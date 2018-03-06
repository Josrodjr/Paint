//declaracion de funcion signo utilizada en el dibujar linea

int signo(int x){
	if(x > 0){
		return 1;
	}
	if (x < 0){
		return -1;
	}
	return 0;
}
 
 //dibujar una linea utilizando el algoritmo de Bresenham
 //rapido: no division o multiplicacion
 // << y >> LSL y LSR

void line_fast(int x1, int y1, int x2, int y2, int radio, unsigned char color)
{
  int i,dx,dy,sdx,sdy,dxabs,dyabs,x,y,px,py;
  //diferencial en X
  dx=x2-x1;      
  //diferencial en Y
  dy=y2-y1;      
  dxabs=abs(dx);
  dyabs=abs(dy);
  sdx=signo(dx);
  sdy=signo(dy);
  x=dyabs>>1;
  y=dxabs>>1;
  px=x1;
  py=y1;

  //si la linea es mas horizontal que vertical
  if (dxabs>=dyabs) 
  {
    for(i=0;i<dxabs;i++)
    {
      y+=dyabs;
      if (y>=dxabs)
      {
        y-=dxabs;
        py+=sdy;
      }
      px+=sdx;
	  cambiarGrosor(px,py,radio,color);
    }
  }
  //caso de que sea mas vertical que horizontal
  else 
  {
    for(i=0;i<dyabs;i++)
    {
      x+=dxabs;
      if (x>=dyabs)
      {
        x-=dyabs;
        px+=sdx;
      }
      py+=sdy;
	  cambiarGrosor(px,py,radio,color);
    }
  }
}

// Bresenham Para dibujar circulos
// tomado de http://suraj1693.blogspot.com/2013/11/c-program-for-bresenhams-circle-drawing.html


void circle_fast(int xi, int yi, int  r, unsigned char color, int grosor){
			int Pk, x, y;
			x=0;
            y=r;
			cambiarGrosor(xi+x,yi-y,grosor,1);
            Pk=3-(2*r);
            for(x=0;x<=y;x++)
            {
                        if (Pk<0)
                        {
                                    y=y;
                                    Pk=(Pk+(4*x)+6);
                        }
                        else
                        {
                                    y=y-1;
                                    Pk=Pk+((4*(x-y)+10));
                        }
						//pintar las 8 posiciones del circulo
						cambiarGrosor(xi+x,yi-y,grosor,color);
                        
						cambiarGrosor(xi-x,yi-y,grosor,color);
                        
						cambiarGrosor(xi+x,yi+y,grosor,color);
                        
						cambiarGrosor(xi-x,yi+y,grosor,color);
                        
						cambiarGrosor(xi+y,yi-x,grosor,color);
                        
                        cambiarGrosor(xi-y,yi-x,grosor,color);
						
                        cambiarGrosor(xi+y,yi+x,grosor,color);
						
                        cambiarGrosor(xi-y,yi+x,grosor,color);
						
            }
}

//calcular el radio

void radio_value_int(int x1, int x2, int y1, int y2, int *radio){
	int op1;
	int op2;
	double diametro;
	
	if(x1 >= x2){
		op1 = abs(x1-x2);
	}
	if(x2 > x1){
		op1 = abs(x2-x1);
	}
	if(y1 >= y2){
		op2 = abs(y1-y2);
	}
	if(y2 > y1){
		op2 = abs(y2-y1);
	}
	
	diametro = sqrt(op1*op1 + op2*op2);
	*radio = (int) diametro/2;
}

//Calcular el centro del circulo
void circle_center(int x1, int x2, int y1, int y2, int *xcentro, int *ycentro){
	
	int op1;
	int op2;
	op1 = (int)(abs(x2-x1)/2);
	if(x2 >= x1){
		op1 = op1 + x1;
	}
	else {
		op1 = op1 +x2;
	}
	op2 = (int)(abs(y2-y1)/2);
	if(y2 >= y1){
		op2 = op2 + y1;
	}
	else {
		op2 = op2 +y2;
	}
	*xcentro = op1;
	*ycentro = op2;
}

///http://3rdyearcselabprograms.blogspot.com/2010/01/midpoint-ellipse-algorithm.html

void draw_ellipse (int radiox, int radioy, int centrox, int centroy,  int grosor, unsigned char color){
	
	int xc,yc,rx,ry;
	float p1,p2,x,y;

	xc = centrox;
	yc = centroy;
	rx = radiox;
	ry = radioy;
	
	x=0;
	y=ry;
	
	cambiarGrosor(xc+x,yc+y,grosor,color);
	cambiarGrosor(xc-x,yc+y,grosor,color);
	cambiarGrosor(xc+x,yc-y,grosor,color);
	cambiarGrosor(xc-x,yc-y,grosor,color);
	p1=(ry*ry)-(rx*rx*ry)+(rx*rx)/4;
	while((2.0*ry*ry*x)<=(2.0*rx*rx*y))
	{
		x++;
		if(p1<=0)
			p1=p1+(2.0*ry*ry*x)+(ry*ry);
		else
		{
			y--;
			p1=p1+(2.0*ry*ry*x)-(2.0*rx*rx*y)+(ry*ry);
		}
		cambiarGrosor(xc+x,yc+y,grosor,color);
		cambiarGrosor(xc-x,yc+y,grosor,color);
		cambiarGrosor(xc+x,yc-y,grosor,color);
		cambiarGrosor(xc-x,yc-y,grosor,color);
		x=-x;
		cambiarGrosor(xc+x,yc+y,grosor,color);
		cambiarGrosor(xc-x,yc+y,grosor,color);
		cambiarGrosor(xc+x,yc-y,grosor,color);
		cambiarGrosor(xc-x,yc-y,grosor,color);
		x=-x;
	}
	x=rx;
	y=0;
	cambiarGrosor(xc+x,yc+y,grosor,color);
	cambiarGrosor(xc-x,yc+y,grosor,color);
	cambiarGrosor(xc+x,yc-y,grosor,color);
	cambiarGrosor(xc-x,yc-y,grosor,color);
	p2=(rx*rx)+2.0*(ry*ry*rx)+(ry*ry)/4;
	while((2.0*ry*ry*x)>(2.0*rx*rx*y))
	{
		y++;
		if(p2>0)
			p2=p2+(rx*rx)-(2.0*rx*rx*y);
		else
		{
			x--;
			p2=p2+(2.0*ry*ry*x)-(2.0*rx*rx*y)+(rx*rx);
		}
		cambiarGrosor(xc+x,yc+y,grosor,color);
		cambiarGrosor(xc-x,yc+y,grosor,color);
		cambiarGrosor(xc+x,yc-y,grosor,color);
		cambiarGrosor(xc-x,yc-y,grosor,color);
		y=-y;
		cambiarGrosor(xc+x,yc+y,grosor,color);
		cambiarGrosor(xc-x,yc+y,grosor,color);
		cambiarGrosor(xc+x,yc-y,grosor,color);
		cambiarGrosor(xc-x,yc-y,grosor,color);
		y=-y;
	}
	
	
}

//calcular el radio de la elipse
//funciona para X o para Y
int radio_ellipse(int x0, int xf){
	int resultado;
	if(x0 >= xf){
		resultado = (int)(x0 - xf)/2;
	}
	if(xf > x0){
		resultado = (int)(xf - x0)/2;
	}
	return resultado;
}













