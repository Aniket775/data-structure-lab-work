#include<bits/stdc++.h>
using namespace std;

int binarysearch(int arr[] , int n , int low , int high , int x){
	while(low<high){
		int mid=(low +high)/2;
		if(arr[mid]==x){
			return mid;
		}
		
		else if(arr[mid]<x){
			low=mid+1;
		}
		
		else{
			high=mid-1;
		}
	}
	
	return -1;
}
int main(){
	
	int n;
	cout<<"enter the size of array";
	cin>>n;
	int arr[n];
	for(int i=0  ; i<n ; i++){
		cin>>arr[i];
	}
	
	cout<<"enter the element u wanna search";
	int ele;
	cin>>ele;
	
 int ans=	binarysearch(arr , n , 0 , n-1 , ele);
 
 cout<<"element found at"<<ans<<"index";
	
	
	
	return 0;
}

