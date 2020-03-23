#include<iostream>
#include<cmath>
float func(float x){
float y=sqrt(1-pow(x,2));
return y;
}
int main(){
float a=0;
float b=1;
float n=100;
float i=1;
float dx=(b-a)/n;
float R=0;
float Sapr;
float xi=a;
while (xi<b&&i<n){
R=R+func(xi);
xi=a+dx*i;
i=i+1;
}
Sapr=(dx/2)*(func(a)+func(b)+2*R);
printf("\ndx = %.2f",dx);
printf("\n%.4f ",Sapr);
}
