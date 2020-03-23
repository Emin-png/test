#include<iostream>
#include<cmath>
float func(float x,float y){
float f=y/(1+pow(x,2));
return f;
}
int main(){
float n=200;
float i1=0;
float x0=0;
float dx=0.005;
float xn=0;
float yn=1;
float k1;
float k2;
float k3;
float k4;
while (i1<n+2){
k1=func(xn,yn);
k2=func(xn+(dx/2),yn+(dx/2)*k1);
k3=func(xn+(dx/2),yn+(dx/2)*k2);
k4=func(xn+dx,yn+dx*k3);
xn=x0+dx*i1;
printf("\n%.4f  %.4f",xn,yn);
yn=yn+(dx/6)*(k1+2*k2+2*k3+k4);
i1++;
}
}
