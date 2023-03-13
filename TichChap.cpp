#include<iostream>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;

void TinHieu(double *x, double THDuoi, double THTren){
	const double pi=3.1415;
	int choice,i=0,j;
	cout<<"Chon dang cua tin hieu: "<<endl<<"1.Da thuc"<<endl<<"2.Asin(Bt+C)+D"<<endl<<"3.Exponential"<<endl;
	cin>>choice; 
	cout<<"----------------------------------------------------------------------------------"<<endl;
	switch(choice){
		case 1:
			int bac;
			cout<<"Nhap bac cua da thuc: x(t) = a + bt + ct^2 + dt^3 +..."<<endl;
			cin>>bac; 
			double heso[99];
			cout<<"Nhap cac he so theo thu tu bac tang dan: "<<endl;
			for(j=0;j<=bac;j++){
				cout<<"He so bac thu "<<j<<" = "; 
				cin>>heso[j];
			} 
			cout<<endl;
			i=0;
			for(double t=THDuoi;t<=THTren;t=t+0.001){
				x[i]=0;
				for(j=0;j<=bac;j++){
					x[i]=heso[j]*pow(t,j)+x[i]; 
				}
				//cout<<x[i]<<" ";
				i++;
			}
			break;
		case 2:	
			double A,B,C,D;
			cout<<"Nhap cac he so: x(t) = Asin(Bt+C)+D"<<endl;
			cout<<"A = "; cin>>A;
			cout<<"B = "; cin>>B;
			cout<<"C = "; cin>>C;
			cout<<"D = "; cin>>D; cout<<endl;
			for(double t=THDuoi;t<=THTren;t=t+0.001){
				x[i] = A*sin(B*t+C)+D; //cout<<x[i]<<" ";
				i++;
			}
			break;
		case 3:	
			cout<<"Nhap cac he so: x(t) = A.e^(Bt+C)+D"<<endl;
			cout<<"A = "; cin>>A;
			cout<<"B = "; cin>>B;
			cout<<"C = "; cin>>C;
			cout<<"D = "; cin>>D; cout<<endl;
			for(double t=THDuoi;t<=THTren;t=t+0.001){
				x[i] = A*exp(B*t+C)+D; //cout<<x[i]<<" ";
				i++;
			}
			break;
	}
	cout<<"----------------------------------------------------------------------------------"<<endl;
}

void DapUngXung(double *h, double DUXDuoi, double DUXTren){
	const double pi=3.1415;
	int choice,i=0,j;
	cout<<"Chon dang cua dap ung xung: "<<endl<<"1.Da thuc"<<endl<<"2.Asin(Bt+C)+D"<<endl<<"3.Exponential"<<endl;
	cin>>choice;
	cout<<"----------------------------------------------------------------------------------"<<endl;
	switch(choice){
		case 1:
			int bac;
			cout<<"Nhap bac cua da thuc: h(t) = a + bt + ct^2 + dt^3 +..."<<endl;
			cin>>bac; 
			double heso[99];
			cout<<"Nhap cac he so theo thu tu bac tang dan: "<<endl;
			for(j=0;j<=bac;j++){
				cout<<"He so bac thu "<<j<<" = "; 
				cin>>heso[j];
			} 
			i=0;
			for(double t=DUXDuoi;t<=DUXTren;t=t+0.001){
				h[i]=0;
				for(j=0;j<=bac;j++){
					h[i]=heso[j]*pow(t,j)+h[i]; 
				}
				//cout<<h[i]<<" ";
				i++;
			}
			break;
		case 2:	
			double A,B,C,D;
			cout<<"Nhap cac he so: h(t) = Asin(Bt+C)+D"<<endl;
			cout<<"A = "; cin>>A;
			cout<<"B = "; cin>>B;
			cout<<"C = "; cin>>C;
			cout<<"D = "; cin>>D; cout<<endl;
			for(double t=DUXDuoi;t<=DUXTren;t=t+0.001){
				h[i] = A*sin(B*t+C)+D; //cout<<h[i]<<" ";
				i++;
			}
			break;
		case 3:	
			cout<<"Nhap cac he so: h(t) = A.e^(Bt+C)+D"<<endl;
			cout<<"A = "; cin>>A;
			cout<<"B = "; cin>>B;
			cout<<"C = "; cin>>C;
			cout<<"D = "; cin>>D; cout<<endl;
			for(double t=DUXDuoi;t<=DUXTren;t=t+0.001){
				h[i] = A*exp(B*t+C)+D; //cout<<x[i]<<" ";
				i++;
			}
			break;
	}
	cout<<"----------------------------------------------------------------------------------"<<endl;
}
	
void TichChap(double THDuoi,double THTren,double DUXDuoi, double DUXTren, double *x,double *h,double*hoanh,double*tung){
	int i=0,j=0;
	int n= 1+(THTren-THDuoi)/0.001;
	int m= 1+(DUXTren-DUXDuoi)/0.001;
	int p= (THTren-THDuoi+DUXTren-DUXDuoi)/0.001;
	hoanh[0]=THDuoi+DUXDuoi;
	for(i=1;i<=p;i++){
		hoanh[i]=hoanh[i-1]+0.001;
	}
	for(i=0;i<=p;i++){
		tung[i]=0;
		for(j=0;j<=i;j++){
			if (n>=m){
				if (i-j<=m) tung[i]=tung[i]+x[j]*h[i-j];
			}
			if (n<m){
				if (i-j<=n) tung[i]=tung[i]+h[j]*x[i-j];
			}
		}
		//cout<<"("<<hoanh[i]<<" ; "<<tung[i]*0.001<<")"<<endl;
	}
}
void TuongQuan(double THDuoi,double THTren,double DUXDuoi, double DUXTren, double *x,double *h,double*hoanh,double*tung){
	int i=0,j=0;
	int n= 1+(THTren-THDuoi)/0.001;
	int m= 1+(DUXTren-DUXDuoi)/0.001;
	int p= (THTren-THDuoi+DUXTren-DUXDuoi)/0.001;
	hoanh[0]=THDuoi+DUXDuoi;
	for(i=1;i<=p;i++){
		hoanh[i]=hoanh[i-1]+0.001;
	}
	for(i=0;i<=1.0*m/2;i++){
		double temp=h[i];
		h[i]=h[m-1-i];
		h[m-1-i]= temp;
	}
	for(i=0;i<=p;i++){
		tung[i]=0;
		for(j=0;j<=i;j++){
			if (n>=m){
				if (i-j<=m) tung[i]=tung[i]+x[j]*h[i-j];
			}
			if (n<m){
				if (i-j<=n) tung[i]=tung[i]+h[j]*x[i-j];
			}
		}
		//cout<<"("<<hoanh[i]<<" ; "<<tung[i]*0.001<<")"<<endl;
	}
}

int main(){
	FILE *fp=NULL;
    fp=fopen("TichCHap.txt","w");
	double THDuoi,THTren,DUXDuoi,DUXTren;
	cout<<"Ben ngoai gioi han duoi va tren, gia tri cua tin hieu va dap ung xung coi nhu = 0 "<<endl;
	cout<<"----------------------------------------------------------------------------------"<<endl;
	cout<<"Nhap gioi han duoi cua tin hieu: "; cin>>THDuoi;
	cout<<"Nhap gioi han tren cua tin hieu: "; cin>>THTren;
	cout<<"----------------------------------------------------------------------------------"<<endl;
	cout<<"Nhap gioi han duoi cua dap ung xung: "; cin>>DUXDuoi;
	cout<<"Nhap gioi han tren cua dap ung xung: "; cin>>DUXTren;
	cout<<"----------------------------------------------------------------------------------"<<endl;
	int n= 1+(THTren-THDuoi)/0.001;
	int m= 1+(DUXTren-DUXDuoi)/0.001;
	int p= (THTren-THDuoi+DUXTren-DUXDuoi)/0.001;
	double x[4*n],h[4*m],hoanh[4*p],tung[4*p];
	TinHieu(x,THDuoi,THTren);
	DapUngXung(h,DUXDuoi,DUXTren);
	int choice;
	cout<<"An 0 de tinh tich chap. An 1 de tinh Tuong Quan"<<endl; cin>>choice;
	if (choice==0) TichChap(THDuoi,THTren,DUXDuoi,DUXTren,x,h,hoanh,tung);
		else TuongQuan(THDuoi,THTren,DUXDuoi, DUXTren,x,h,hoanh,tung);
	for(int i=0;i<=p;i++) fprintf(fp,"%lf\t %lf\n",hoanh[i],tung[i]*0.001);
}
