#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
	char arr[9][20];int collide=0;
	for(int i=8;i>-1;i--){
		for(int j=0;j<20;j++){
			cin>>arr[i][j];
		}
	}
	int a=0,b=0;
	int x[4]={1,-1,1,-1};
	int y[4]={1,1,-1,-1};
	int xy=0;
	while(collide!=2){
		cout<<a<<" "<<b<<"\n";
		a+=x[xy]; b+=y[xy];
		if(arr[b][a]=='*'){
			collide++;
			if(a==0)
				xy=3;
			
			if(b==0)
				xy=0;
			
			if(a==19)
				xy=1;
				
			if(b==8)
				xy=3;
							
			continue;
		}
		if(arr[b][a]=='c'){
			arr[b][a]='-';
			switch(xy){
				case 0: xy=2;
					break;
				case 1:xy=0;
					break;
				case 2:xy=3;
					break;
				default:xy=1;			
			}
		}
		else if(arr[b][a]=='a'){
			arr[b][a]='-';
			switch(xy){
				case 0: xy=1;
					break;
				case 1:xy=3;
					break;
				case 2:xy=0;
					break;
				default:xy=2;			
			}
		}
		
	}
	cout<<a<<" "<<b<<"\n";	
	
	int safe=0,infected=0;
	for(int i=8;i>-1;i--){
		for(int j=0;j<20;j++){
			cout<<arr[i][j];
			if(arr[i][j]=='-')
				infected++;
			
			else if(arr[i][j]=='a'||arr[i][j]=='c')
				safe++;
		}
		cout<<"\n";
	}
	cout<<"safe="<<safe<<"\n"<<"infected="<<infected;

//********************
//
//*....c.............*
//
//*...c..............*
//
//*c.................*
//
//*.............a....*
//
//*c.c...............*
//
//*.a................*
//
//*...........c......*
//
//********************




//********************
//
//*..................*
//
//*..c...............*
//
//*....c.............*
//
//*.........a........*
//
//*..................*
//
//*.......a......c...*
//
//*..................*
//
//********************
}

