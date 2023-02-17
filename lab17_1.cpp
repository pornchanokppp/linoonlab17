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

void showData(double x[],int N , int M){
    cout << fixed << setprecision(2);
    for(int i = 0; i < N*M; i++){
        cout <<x[i];
        if( i % M == M-1 ) cout << endl;
        else cout << " ";
    }
}


void randData(double x[],int N , int M){
    for(int i = 0; i < N*M; i++){
      x[i] = rand()%101 /100.00;
    }
}

void findRowSum(const double *w ,double *x ,int N,int M  ) 
{
    int a = 0  ;
    double sum = 0 ;
    for(int i = 0 ;i<N*M  ; i++ )
    {
         sum += *(w + i ) ;
         if (i% M == M-1 ) 
            {
            x[a] = sum ;
            sum = 0 ;
            a++ ;
            }
    }
}

void findColSum(const double *a,double *b,int N,int M){
    double summation=0.00;
    for(int i=0; i<M ;i++){
        for(int j=0; j<N ;j++){
            summation=summation + *(a+i+j*M);
        }
        *(b+i)=summation; summation=0;
    }
}