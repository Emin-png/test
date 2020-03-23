#include<stdio.h>
int main(){
    float arr[7]={4,3,7,9,5,10,6};
    float min=arr[0];
    int k;
    for (int i=0;i<7;i++)
        if (min>arr[i]){
            min=arr[i];
            k=i;
        }
    printf("Minimum = %.2f",min);
    printf("\nIndex of Minimum = %d",k);
}
