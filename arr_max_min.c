#include<stdio.h>
int main(){
float arr[7]={4,3,7,9,5,10,6};
float max=arr[0];
float min;
for (int i=0;i<7;i++){
if (max<arr[i]){
max=arr[i];
}
}
min=max;
for (int i=0;i<7;i++){
if (min>arr[i]){
min=arr[i];
}
}
printf("Maximum = %.2f",max);
printf("\nMinimum = %.2f",min);
}
