#include<bits/stdc++.h>
using namespace std;

void diagonalmatrix(int n){
	
	int diag[n];
	for(int i=0 ; i<n ; i++){
		cin>>diag[i];
		
	}
	
	for(int i=0 ; i<n ; i++){
		for(int j=0 ; j<n ; j++){
			
			if(i==j){
				cout<<diag[i]<<" ";
			}
			
			else{
				cout<<"0"<<" ";
			}
			
			
		}
		
		cout<<endl;
	}
}


void tridiagonalmatrix(int n){
	
	
	int m=3*n - 2;
	int tridiag[m];
	
	for(int i=0 ; i<m ; i++){
		
		cin>>tridiag[i];
	}
	
	int k=0;
	for(int i=0 ; i<n ; i++){
		for(int j=0 ; j<n ; j++){
			
			if(abs(i-j)<=1){
				cout<<tridiag[k++]<<" ";
			}
			
			else {
				
				cout<<"0"<<" ";
			}
			
			
			
		}
		
		cout<<endl;
	}
	
	
	
}

void lowertriangular(int n){
	int m=n*(n+1)/2;
	
	int lowertri[m];
	for(int i=0 ; i<m ; i++){
		cin>>lowertri[i];
	}
	
	
	int k=0;
	for(int i=0 ; i<n ; i++){
		for(int j =0 ; j< n ; j++){
			if(i>=j){
				cout<<lowertri[k++]<<" ";
			}
			
			else{
				
				cout<<"0"<<" ";
				
			}
		}
		
		cout<<endl;
	}
}

void uppertriangular(int n){
	int m=n*(n+1)/2;
	
	int uppertri[m];
	for(int i=0 ; i<m ; i++){
		cin>>uppertri[i];
	}
	
	
	int k=0;
	for(int i=0 ; i<n ; i++){
		for(int j =0 ; j< n ; j++){
			if(i<=j){
				cout<<uppertri[k++]<<" ";
			}
			
			else{
				
				cout<<"0"<<" ";
				
			}
		}
		
		cout<<endl;
	}
}


void symmetrixmatrix(int n){
	
	int m=n*(n+1)/2;
	
	int symm[m];
	for(int i=0 ; i<m ; i++){
		cin>>symm[i];
	}
	
	cout<<endl;
	
	

	for(int i=0 ; i<n ; i++){
		for(int j =0 ; j< n ; j++){
			if(i>=j){
				cout<<symm[i*(i+1)/2 + j] <<" ";
			}
			
	else{
				
				cout<<symm[j*(j+1)/2 + i]<<" ";
				
			}
		}
		
		cout<<endl;
	}
	
	
}








int main(){
	int n;
	cout<<"enter the value of n";
	cin>>n;
	
//	cout<<"diagonal matrix is:";
//	diagonalmatrix(n);
//	
//	cout<<"tridiagonal matrix is:";
//	tridiagonalmatrix(n);
	
		
//	cout<<"lower triangular matrix is:";
//	lowertriangular(n);
	
//	cout<<"upper triangular matrix is:";
//	uppertriangular(n);
	
		cout<<"symmetric matrix is:";
	symmetrixmatrix(n);
	
	
	
	
	
	
	return 0;
	
}
