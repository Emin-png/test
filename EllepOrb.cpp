#include<iostream>
#include<cmath>
float Kepler(float M){
float E=M;	
float E1;	
float e=0.01671;
float eps=pow(10,-6);
while (fabs(E1-E)>eps)	{
E1=M+e*sin(E);	
E=E1;
return E;	
}
}
int main(){
float M=0;	
float e=0.01671;
float pi=3.1415926;	
float dx=0.05;	
float fi1;
float fi2;
float r;
float x;
float y;
float rmin=149600000;
float P=rmin*(1+e);
while (M<2*pi){	
M=M+dx;	
fi1=2*atan(sqrt((1+e)/(1-e))*tan(Kepler(M)/2));
if	(fi1>0){
r=P/(1+e*cos(fi1));	
x=r*cos(fi1);
y=r*sin(fi1);
}
if (fi1<0){
fi2=fi1+2*pi;	
r=P/(1+e*cos(fi2));
x=r*cos(fi2);
y=r*sin(fi2);	
}
printf("\n %.4f   %.4f",x/1000000,y/1000000);
}
}
