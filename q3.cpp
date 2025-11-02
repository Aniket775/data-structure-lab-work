
//a
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

//b
#include <iostream>
using namespace std;

int findMissingBinary(int arr[], int n) {
    int left = 0, right = n - 2; 
    while (left <= right) {
        int mid = left + (right - left) / 2;
        // Element at arr[mid] should be mid + 1 in a perfect array
        if (arr[mid] == mid + 1) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    // The missing number is left + 1
    return left + 1;
}

int main() {
    int arr[] = {1, 2, 3, 4, 6};
    int n = 6;
    cout << "Missing Number (Binary Search): " << findMissingBinary(arr, n) << endl;
    return 0;
}
