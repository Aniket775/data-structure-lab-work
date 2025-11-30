#include<bits/stdc++.h>
using namespace std;
int main(){
	
	int n;
	cout<<"enter the size of array";
	cin>>n;
	int arr[n];
	for(int i=0  ; i<n ; i++){
		cin>>arr[i];
	}
	
	int uniquesize=0;
	int uniquearr[uniquesize];
	for(int i=0 ; i<n ; i++){
		
		int isunique=1;
		for(int j=0 ; j<uniquesize ; j++){
			if(uniquearr[j]==arr[i]){
				isunique=0;
				break;
			}
		}
		
		
		if(isunique){
			
			uniquearr[uniquesize++]=arr[i];
		}
	}
	
	cout<<"unique array is:-"<<endl;
	for(int i=0 ; i<uniquesize ; i++){
		
		cout<<uniquearr[i]<<" ";
	}
	
	
	
	return 0;
}
