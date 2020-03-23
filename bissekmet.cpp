#include<iostream>
#include<cmath>
float func(float x){
float y;
y=exp(x)-2*x-3;
return y;
}
int main(){
float a=-3;
float b=0;
float c;
float eps=pow(10,-6);
float xroot;
int i=0;
while (b-a>eps){
c=(a+b)/2;
if (func(a)*func(c)<0){
b=c;
}
if (func(c)*func(b)<0){
a=c;
}
xroot=c;
i++;
}
printf("The Root: %.6f",xroot);
printf("\nNumber of iterations: %d",i);
//printf(" %.2f %.2f",func(a),func(b));
}
