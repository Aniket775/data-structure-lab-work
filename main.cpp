/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

void display( int mat[][3], int n) {

	cout<<"row col val"<<endl;
	for(int i=0 ; i<n ; i++) {

		cout<<mat[i][0]<<"    " <<mat[i][1]<<"    " <<mat[i][2]<<endl;
	}
}

void transpose(int mat[][3], int T[][3], int n1) {
	for(int i=0 ; i<n1 ; i++) {
		T[i][0]=mat[i][1];
		T[i][1]=mat[i][0];
		T[i][2]=mat[i][2];

	}
}

int add(int A[][3], int n1, int B[][3], int n2, int C[][3] ) {

	int i=0, j=0, k=0 ;

	while(i<n1 && j<n2) {

		if(A[i][0]==B[j][0] && A[i][1]==B[j][1] ) {

			C[k][0]=A[i][0];
			C[k][1]=A[i][1];
			C[k][2]=A[i][2] + B[j][2];
			i++ ;
			j++;
			k++;
		}


		else if((A[i][0] < B[j][0]) || (A[i][0]==B[j][0]  && A[i][1] < B[j][1])) {


			C[k][0]=A[i][0];
			C[k][1]=A[i][1];
			C[k][2]=A[i][2];

			k++;
			i++;
		}

		else {

			C[k][0]=B[j][0];
			C[k][1]=B[j][1];
			C[k][2]=B[j][2];

			k++;
			j++;


		}
	}

	while(i<n1) {


		C[k][0]=A[i][0];
		C[k][1]=A[i][1];
		C[k][2]=A[i][2];

		i++;
		k++;

	}

	while(j<n2) {


		C[k][0]=B[j][0];
		C[k][1]=B[j][1];
		C[k][2]=B[j][2];

		k++;
		j++;



	}

	return k;


}

int multiply(int A[][3], int n1, int B[][3], int n2, int M[][3]) {

	int k=0;
	for(int i=0 ; i<n1 ; i++) {

		for(int j=0 ; j<n2 ; j++) {

			if(A[i][1]==B[j][0]) {

				M[k][0]=A[i][0];
				M[k][1]=B[j][1];
				M[k][2]=A[i][2]*B[j][2];
				k++;

			}
		}
	}

	return k;
}

int main()
{
	int A[3][3]= {{1, 2, 3}, {5, 7, 8}, {0, 5, 2}};
	int n1=3;



	int B[3][3]= {{4, 5, 3}, {11, 10, 8}, {0, 88, 2}};
	int n2=3;

	display(A, n1);

	int T[10][3];
	cout<<"transpose of A:"<<endl;
	transpose( A, T, n1 );
	display(T, n1);

	int C[10][3];
	int n3= add(A, n1, B, n2, C);
	cout<<"addition is :"<<endl;
	display(C, n3);

	int M[10][3];
	int n4= multiply(A, n1, B, n2, M);
	cout<<"multiplication is :"<<endl;
	display(M, n4);





	return 0;
}