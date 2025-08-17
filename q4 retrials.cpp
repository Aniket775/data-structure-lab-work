#include<bits/stdc++.h>
using namespace std;



int main(){
	
	
	string s8="HELLO BROSKI";
	int n=s8.size();
	
// 	int left=0;
// 	int right=n-1;
	
// 	while(left<=right){
// 		char t=s8[left];
// 		s8[left]=s8[right];
// 		s8[right]=t;
		
// 		left+=1;
// 		right-=1;
// 	}
	
// 	cout<<s8;
	
	
// 	for(int i=0 ; i<n ; i++){
		
// 		for(int j=0 ; j<n-i-1 ; j++){
			
// 			if(s8[j]>s8[j+1]){
				
// 				swap(s8[j] , s8[j+1]);
				
				
// 			}
// 		}
// 	}
	
// 	cout<<s8;

for(int i=0 ; i<n ; i++){
    
    if(s8[i]>=65 && s8[i]<=90){
        
        s8[i]=s8[i]+32;
    }
}

cout<<s8;
}

