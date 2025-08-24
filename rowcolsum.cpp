/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
   
   int mat[3][3]={{1 , 2 , 3} , { 5 , 6 , 8} , {12 , 67 , 90}};
   
   
   
   
   for(int k=0 ; k<3 ; k++){
       int sum=0;
       for(int i=0 ; i<3 ; i++){
       
       sum+=mat[k][i];
       
       }
       
       cout<<"sum of row "<<k+1<< " " <<sum<<endl;
       
   }
   
   for(int k=0 ; k<3 ; k++){
       int colsum=0;
       for(int i=0 ; i<3 ; i++){
       
       colsum+=mat[i][k];
       
       }
       
       cout<<"sum of col "<<k+1<<" " <<colsum<<endl;
       
   }

    return 0;
}