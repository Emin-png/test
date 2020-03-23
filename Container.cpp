#include<iostream>
#include<cmath>
int main(){
float r=0.6;
float l=1.3;
float h=0;
float z;
float Sfull;
float Vfull;
float pi=3.1415926;
while (h<2*r){
z=h-r;
Sfull=pi*pow(r,2)-pow(r,2)*(acos(z/r)-(z/r)*sqrt(1-pow(z/r,2)));
Vfull=Sfull*l;
printf("\n%.4f   %.4f",h,Vfull);
h=h+0.012;
}
}
