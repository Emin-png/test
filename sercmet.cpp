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
float k;
float eps=pow(10,-6);
float c;
int i=0;
while (b-a>eps){
k=(func(b)-func(a))/(b-a);
c=a-func(a)/k;
if (func(a)*func(c)<0){
b=c;
}
if (func(b)*func(c)<0){
a=c;
}
i++;
}
printf("The Root= %.6f",c);
printf("\nNumber of Iterations= %d",i);
}
