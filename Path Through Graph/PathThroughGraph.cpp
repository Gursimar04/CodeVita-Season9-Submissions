#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(){
	int n1,n2,i;
	cin>>n1>>n2;
	int edges=0;
	if(n1==n2){
		cout<<0;
	}
	else{
		if(n2>n1){
			int temp=n1;
			n1=n2;
			n2=temp;
		}
//		cout<<n1<<"<->";
		for(i=n1-1;i>=1;i--){
			if(n1%i==0){
				edges++;
//				cout<<i<<"<->";
				n1=i;
				if(n2%i==0){
					break;
				}
			}
		}
		
		if(i==n2){
			cout<<edges;
		}
		else{
			for(int j=n2-1;j>=1;j--){
				if(n2%j==0){
					n2=j;
//					cout<<j<<"<->";
					edges++;
					if(i==j){
						break;
					}
				}
			}
			cout<<edges;
		}
		
	}
	
}
