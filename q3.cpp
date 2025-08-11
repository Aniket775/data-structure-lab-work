#include<bits/stdc++.h>
using namespace std;

int main(){
	int arr[]={1 , 2 , 3 , 4 , 6 , 7};
	for(int i=0 ; i<sizeof(arr) ; i++){
		
		if(arr[i]!= arr[i-1]+1){
			cout<<"missing number is "<<arr[i-1]+1<<endl;
			break;
		}
	}
	
	return 0;
}
