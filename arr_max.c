#include<stdio.h>
float max(float *arr,int k){
float maxim=arr[0];
for (int i=0;i<7;i++){
if (maxim<arr[i]){
maxim=arr[i];
}
}
return maxim;
}
int main(){
float arr[7]={4,3,7,9,5,10,6};
printf("Maximum = %.2f",max(arr,7));
}
