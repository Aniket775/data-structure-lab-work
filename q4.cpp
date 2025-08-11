#include<bits/stdc++.h>
using namespace std;
int main(){
	//concatenate
	
	string s1="hello";
	string s2="world";
	cout<<"conactenated string is  "<<s1 +s2<<endl ;
	
	
	string s3="hola amigo";
	reverse(s3.begin() , s3.end());
	cout<<"reversed string is  "<<s3<<endl;
	
//	string s4="what a beatiful day";
//	string s5="";
//	for(char c : s4){
//		if(!(c=='a' || c=='e' || c=='i' ||c=='o' ||c=='u' ||c=='A' ||c=='E' ||c=='I' ||c=='O' ||c=='U' )){
//			s5+=c;
//		}
//	}
//	
	cout<<"without vowels it is  "<<s5<<endl;
	
	string arr[]={"hola" , "amigo" , "kaise" , "ho" , "thikho?"};
	int n=5;
	sort(arr, arr+5);
	
	cout<<"sorted in alphabetical order";
	for(int i=0 ; i<n ; i++){
		
		cout<<arr[i]<<endl;
		
	}
	
	
	char c1='A';
	cout<<"in lowercase it is    "<<(char)tolower(c1);
	
	
	return 0;
}
