#include<iostream>
#include<cmath>
using namespace std;
double elaptime(double *arr_month, int n_month, double n_day, double n_hour, double n_min, double n_sec){
double N_Day=0;    
if (n_month==1){
N_Day=0;
}    
else{
for (int i=0;i<n_month-1;i++){
N_Day=N_Day+arr_month[i];
}
}
double t_sec=86400*N_Day+86400*(n_day-1)+3600*n_hour+60*n_min+n_sec;
return t_sec;
}
double Kepler(double M, double e){
double E0=M;
double E;
while (abs(E-E0)>pow(10,-10)){
E=M+e*sin(E0);
E0=E;
}
return E;
}
int main(){    
double e=0.01671022;   
double pi=3.1415926;
double del=pi/180;
double DelE=23.45*del;
double LatMD=41.635880;
double LonMD=46.663052;
double LatM=LatMD*del;
double LonM=LonMD*del;
double T_synodic=86400;
double T_sideral=86164.09164;
double OM_sideral=(2*pi)/T_sideral;
double OM_synodic=(2*pi)/T_synodic;
double T_sideral_Earth_Revolution=365.256*24*3600;
double OM_Sun=(2*pi)/T_sideral_Earth_Revolution;
double arr_month[12]={31,28,31,30,31,30,31,31,30,31,30,31};
double teq=elaptime(arr_month,3,20,21,58,35);
double teq_GMT0=elaptime(arr_month,3,20,24,0,0);
double t_3Jan=elaptime(arr_month,1,3,5,20,0);
double t_4July=elaptime(arr_month,7,4,22,11,0);
double t_20March=elaptime(arr_month,3,20,21,58,35);
double t_21June=elaptime(arr_month,6,21,15,54,0);
double t_23Sep=elaptime(arr_month,9,23,7,50,0);
double t_22Dec=elaptime(arr_month,12,22,4,19,0);
/*printf("3 January: %.2f", t_3Jan);
printf("\n4 July: %.2f", t_4July);
printf("\n20 March: %.2f", t_20March);
printf("\n21 June: %.2f", t_21June);
printf("\n23 September: %.2f", t_23Sep);
printf("\n22 December: %.2f\n", t_22Dec);*/
int n_month=12;
double n_day=31;
double n_hour=24;
double n_min=0;
double n_sec=0;
double G=6.6743*pow(10,-11);
double Earth_mass=1.989*pow(10,30);
double a=1.496*pow(10,11);
double OM_Earth_Rev=(sqrt(G*Earth_mass))/(pow(a,1.5));
double t_max=elaptime(arr_month,n_month,n_day,n_hour,n_min,n_sec);
double t_cur;
double t0=elaptime(arr_month,1,3,5,20,0);
double t_begin=elaptime(arr_month,6,21,0,0,0);
//for (t_cur=0;t_cur<t_max;t_cur=t_cur+86400){
for (t_cur=t_begin;t_cur<t_begin+86400;t_cur=t_cur+12){
double M=OM_Earth_Rev*(t_cur-t0);
double E=Kepler(M,e);
double fi=2*atan(sqrt((1+e)/(1-e))*tan(E/2));
if (E>pi){
fi=fi+2*pi;
}
double fiD=fi/del;
double Dif_fi=12.546190*del;
double fi_new=fi+Dif_fi;
double fi_newD=fi_new/del;
double Lat_Sun=asin(-cos(fi_new)*sin(DelE));
double fi_sun0=acos(sin(fi_new)/cos(Lat_Sun));
double phi_G0=2*pi-OM_sideral*(teq_GMT0-teq);
double phi_G=phi_G0+OM_sideral*(t_cur-teq);
double phi_Gn=phi_G-(int)(phi_G/(2*pi))*(2*pi);
double Lon_Sun=fi_sun0-(phi_Gn-pi);
double Lat_SunD=Lat_Sun/del;
double Lon_SunD=Lat_Sun/del;
double t_hour=(t_cur-t_begin)/3600;
printf(" t_hour =  %.6f   ", t_hour);
//printf("\n fiD = %.6f  ", fiD);
printf("\n fi_newD = %.6f  ",fi_newD);
//printf("\n Lat_SunD = %.2f   ", Lat_SunD);
}
}