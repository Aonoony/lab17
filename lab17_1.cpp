#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
using namespace std;

void showData(double *,int,int);

void randData(double *,int,int);

void findRowSum(const double *,double *,int,int);

void findColSum(const double *,double *,int,int);

int main(){
	srand(time(0));
	const int N = 6, M = 8;
	double data[N][M] = {};
	double sum1[N] = {};
	double sum2[M] = {};
	double *dPtr = data[0];
	randData(dPtr,N,M);
	showData(dPtr,N,M);
	
	cout << "---------------------------------------------\n";
	
	findRowSum(dPtr,sum1,N,M);
	showData(sum1,N,1);
	
	cout << "---------------------------------------------\n";
	
	findColSum(dPtr,sum2,N,M); 
	showData(sum2,1,M);
}

void showData(double *a, int n, int m){
	cout << fixed << setprecision(2);
	for(int i = 0; i < n*m; i++){
		cout << a[i];
		if((i+1)%m == 0) cout << endl;
		else cout << " ";
	}
}

void randData(double *a, int n, int m){
	for(int i = 0; i < n*m; i++){
		a[i] = (rand()%101)/100.00;
	}
}

void findRowSum(const double *a, double *b, int n, int m){
	int i = 0;
	for(int j = 0; j < m; j++) b[j] = 0;
	if(m == 1){
		for(int k = 0; k < n*m; k++) b[i] = a[i];
	}else{
		for(int l = 0; l < n*m; l++){
			b[i] += a[l];
			if((l+1)%m == 0) i++;
		}
	}
}

void findColSum(const double*a, double *b, int n, int m){
	if(n == 1){
		for(int i = 0; i<m; i++) b[i] = a[i];
	}else{
		for(int j=0; j < n*m; j++) b[j%m] += a[j];
		for(int k = 0; k < m; k++) b[k] = 0;
		for(int l = 0; l < n*m; l++) b[l%m] += a[l];
	}
}
