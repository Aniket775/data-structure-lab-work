#include<bits/stdc++.h>
using namespace std;

void bubblesort(int arr[] , int n){
	for(int i=0 ; i<n ; i++){
		for(int j=i ; j<n-i-1 ; j++){
			if(arr[j]> arr[j+1]){
				swap(arr[j] , arr[j+1]);
			}
		}
	}
	
	
	cout<<"array after sorting:-"<<endl;
	for(int i=0 ; i<n ; i++){
		cout<<arr[i]<<" ";
	}
}


int main(){
	
	int n;
	cout<<"enter the size of array";
	cin>>n;
	int arr[n];
	for(int i=0  ; i<n ; i++){
		cin>>arr[i];
	}
	
	bubblesort(arr , n);
	
	
	
	
	return 0;
}

