#include<bits/stdc++.h>
using namespace std;

 int n=0;  
int arr[];
void create(int n){

    cout<<"enter the size of array (non-zero)"<<endl;
    cin>>n;

    for(int i=0 ; i<n ; i++){
        cin>>arr[i];
    }

}
void display(){
    for(int i=0 ; i<n ; i++){
        cout<<arr[i]<<" ";
    }
}
void insert(){
    int pos;
    int ele;
    cout<<"enter the position"<<endl;
    cin>>pos;
    cout<<"enter the element"<<endl;
    cin>>ele;
    for(int i=pos ; i<=n ; i++){
        arr[i]=arr[i-1];
    }

    arr[pos-1]=ele;
    n+=1;
}
void deletion(){
    cout<<"enter the position of the element to be deleted"<<endl;
    int pos;
    cin>>pos;
    for(int i=pos ; i<n ; i++){
        arr[i-1]=arr[i];
    }

    n-=1;
}
void linearsearch(){
    cout<<"enter the element to be searched"<<endl;
    int ele;
    cin>>ele;
    for(int i=0 ; i<n ; i++){
        if(arr[i]==ele){
            int pos=i;
            break;
        }

        cout<<"element found at"<<pos<<"position";
    }
}
int main(){
    do{
        cout<<"select:-"<<endl<<"1. create"<<endl<<"2. display"<<endl<<"3. insert"<<endl<<"4. deletion"<<endl<<"5. linear search"<<endl<<"6. exit"<<endl;
    int option;
    cin>>option;
    switch(option){
        case 1:
        create();
        break;

        case 2:
        display();
        break;

        case 3:
        insert();
        break;

        case 4:
        deletion();
        break;

        case 5:
        linearsearch();
        break;

        case 6:
        cout<<"exiting program";
        break;

        default:
        cout<<"invalid choice";



    }
    }
    while(option<=6);

    return 0;
    
}
