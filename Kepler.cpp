#include<iostream>
#include<cmath>
float Kepler(float M){
float E=M;
float E1;
float e=0.5;
float eps=pow(10,-6);
while (fabs(E1-E)>eps){
E1=M+e*sin(E);
E=E1;
return E;
}
}
int main(){
float M=0;	
float pi=3.1415926;	
float dx=0.05;	
while (M<2*pi){
printf("\n%.4f   %.4f",M,Kepler(M));
M=M+dx;	
}
}
