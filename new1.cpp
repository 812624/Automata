#include<graphics.h>
#include"myheader.cpp"
using namespace std;
void draw(int num, char final[][20])
{          
	int gd = DETECT, gm;
	initgraph(&gd, &gm, NULL);
	int i, j, k= 0;
	char  a[1] = {'1'};
	int x = getmaxx()/20, y = getmaxy()/2;

	for(i =0 ;i< num;i++)
	{
		for(j=0;j<num;j++)
		{
			char c[1] = {final[i][j]};
			if(i==0&&j==0){
				circle(x, y,16);
				outtextxy((x), y, a);
				a[0]+=1;
			}	
			else if(final[i][j] != '-'){
				circle(x+80*j, y, 16);
				outtextxy((x+80*j), y, a);
				a[0]=a[0]+1;
				if(i<j){
					if(j-i!=1){
						arc((x+80*j-x+80*i)/2+40, y, 0, 180, abs(j-i)*40);
						outtextxy(((x+80*j-x+80*i)/2)+40, y+40, c);
					}
					else
					{
						line(x+80*i, y, x+80*j, y);
						outtextxy(((x+80*j-x+80*i)/2)+40, y, c);
					}
				}
				else{
				arc((x+80*i-x+80*j)/2+40, y, 180, 0, abs(j-i)*40);
				outtextxy(((x+80*i-x+80*j)/2)+40, y-40, c);
				}
			}
		}
	}		
/*for(k=0;k<x*100&&num>0;k=k+80){
circle(((getmaxx()/20)+k), getmaxy()/2,16);
outtextxy(((getmaxx()/20)+k), (getmaxy()/2), a);
num--;
a[0]=a[0]+1;
}
	
	//arc((getmaxx()/20), getmaxy()/2, 0, 180, 50);
for(i =0 ;i< num;i++)
{
	k = 0;
	for(j=0;j<num;j++)
	{
		if(final[i][j]!= '-'){
			k=0;
			arc((getmaxx()/20)+(k), getmaxy()/2, 0, 180, 50);
		}	
		k = k+80;
	}''''
	* 
	* 
	* 
	* 
	* Velse if(final[i][j] != '-'){
			if( p != i ){
				circle((x + k + (abs(j - i) * 80)), y, 16);
				outtextxy((x + k), y, a);
				a[0]+=1;
				arc((x+k+40), y, 0, 180, abs(j-i)*40);
				k=k+80;
				p = i;
			}	
			else
			{
				circle((x+k-80+(abs(j-i))*80), y, 16);
				
			}
}*/
 
	delay(100000000);
}
