#include<iostream>
#include<cmath>
float func(float x){
float y;
y=exp(x)-2*x-3;
return y;
}
float deriv(float x){
float y;
y=exp(x)-2;
return y;
}
int main(){
float a=-3;
float c;
c=a-func(a)/deriv(a);
int i=0;
float eps=pow(10,-6);
while (fabs(func(a)/deriv(a))>eps){
c=a-func(a)/deriv(a);
a=c;
i++;
}
printf("The Root= %.6f",c);
printf("\nNumber of Iterations= %d",i);
}
