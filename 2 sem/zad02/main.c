#include <stdio.h>
#include <math.h>

const double PI = 3.14159;
const double dx = 0.05;     //dotyczy calego pola
const double dy = 0.05;     //cale pole
const double dxp = 0.001;  //dotyczy prostokata wew
const double dyp  = 0.001;  // prostokata wew
const double e0 = 8.85e-12;
// rozmiar duzego prostokata
const double a = 0.5;
const double b = 0.5;
//rozmiar malego prostokata
const double w = 0.2;
const double h = 0.1;
const double s = 10; //gestasc ladunku

double de;
double dex;
double dey;
double dq;
double r;

int main()
{	
	const double k = 1/(4*PI*e0);
	for(double x = -a; x<a; x+=dx)
	{
		
		for(double y = b;y> -b;y-=dy)
		{
			
			if(fabs(x)<=w+dxp && fabs(y)<=h+dyp){
				printf("%lf %lf 0 0\n",x,y);
			}else{
					dex = 0;
					dey = 0;
					de = 0;				
				for(double xp = -w;xp<w;xp+=dxp)
					{
						for(double yp = h;yp > -h;yp-=dyp)
						{
							dq = s*dxp*dyp;
							r = sqrt((x-xp)*(x-xp)+(y-yp)*(y-yp));
							de = k*dq/r/r;
							dex += (x-xp)*de/r;	
							dey += (y-yp)*de/r;	
						}					
					}
					dex = dex*10e-13;
					dey = dey*10e-13;
					printf("%lf %lf %lf %lf\n",x,y,dex,dey);
				
			}
			
		}
		
	}	
	return 0;
}


