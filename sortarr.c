#include<stdio.h>
int main(){
float arr[7]={4,3,7,9,5,10,6};
int n=7;
float c;
float d;
for (int j=1;j<n-3;j++){
for (int i=0;i<n-1;i++){
if (arr[i]>arr[i+1]){
c=arr[i];
d=arr[i+1];
arr[i]=d;
arr[i+1]=c;
}
}
}
for (int i=0;i<n;i++){
printf(" %.2f ",arr[i]);
}
}
