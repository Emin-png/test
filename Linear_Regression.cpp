#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;
float aver(float *arr,int m,int n){
float S=0;
float A;
for (int i=m;i<=n;i++){
S=S+arr[i];
}
A=S/(n-m+1);
return A;
}
float standev(float *arr,int m, int n){
float SD;
float R=0;
for (int i=m;i<=n;i++){
R=R+pow(arr[i]-aver(arr,m,n),2);
}
SD=sqrt(R/(n-m+1));
return SD;
}
float cor(float *arr1,float *arr2,int m,int n){
float M=0;
float N;
float R;
for (int i=m;i<=n;i++){
M=M+(arr1[i]-aver(arr1,m,n))*(arr2[i]-aver(arr2,m,n));
}
N=M/(standev(arr1,m,n)*standev(arr2,m,n));
R=N/(n-m+1);
return R;
}
float betta(float *arr1,float *arr2,int m,int n){
float B;
B=cor(arr1,arr2,m,n)*standev(arr2,m,n)/standev(arr1,m,n);
return B;
}
float alpha(float *arr1,float *arr2,int m,int n){
float A;
A=aver(arr2,m,n)+betta(arr1,arr2,m,n)*aver(arr1,m,n);
return A;
}
float arr1[1566];
float arr2[1566];
int main(){
std::ifstream infile;
int n=0;
infile.open("workfile.txt");
if (infile.fail()){
std::cout << "error" << endl;
}
while (!infile.eof()){
infile >> arr1[n];
infile >> arr2[n];
n=n+1;
}
int a;
printf("a (must be more than b) = ");
scanf("%d",&a);
int b;
printf("b = ");
scanf("%d",&b);
float DevT;
printf("First Average: %.6f   \nSecond Average: %.6f",aver(arr1,b,a),aver(arr2,b,a));
printf("\nFirst Standard Deviation: %.6f   \nSecond Standard Deviation: %.6f",standev(arr1,b,a),standev(arr2,b,a));
printf("\nThe Correlation: %.6f",cor(arr1,arr2,b,a));
printf("\nBetta: %.6f",betta(arr1,arr2,b,a));
printf("\nAlpha: %.6f",alpha(arr1,arr2,b,a));
DevT=betta(arr1,arr2,b,a)*(arr1[a]-arr1[b]);
printf("\nTemperature Increase: %.6f",DevT);
}
