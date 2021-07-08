#include<iostream> 
#include<bits/stdc++.h> 
using namespace std; 
string large;
bool compare(int ar[], int arr[]) 
{ 
    for (int i=0; i<26; i++) {
        if (ar[i] != arr[i]) 
            return false; 
}
    return true; 
} 
  

bool search(string sm) 
{ 
    int s = sm.length(), l = large.length(); 
    int hashs[26] = {0}, hashl[26] = {0}; 
    for (int i = 0; i < s; i++) 
    { 
        (hashs[sm[i]-'a'])++; 
        (hashl[large[i]-'a'])++; 
    } 
    for(int i = s; i < l; i++) { 
        if (compare(hashs, hashl)){
        	large.erase(i-s,s);
        	cout<<large<<"\n";
        	return true;
		} 
        (hashl[large[i]-'a'])++; 
  
        hashl[large[i-s]-'a']--; 
    }  
    	if (compare(hashs, hashl)) {
        	large.erase(l-s,s);
        	cout<<large<<"\n";
        	return true;
		} 
		return false;
} 
  
int main() 
{ 
	cin>>large;
	int num;
	cin>>num;
	string s[num];
	for(int i=0;i<num;i++){
		cin>>s[i];
	}
		
	for(int i=num-1;i>-1;i--){
		if(s[i].length()>large.length()){
			cout<<"NO";
			break;
		}
		if(!search(s[i])){
			cout<<"NO";
			break;
		}
		if(large.length()==0&&i==num-1){
			cout<<"YES";
			break;
		}
		if(i==num-1&&large.length()!=0){
			cout<<"NO";
			break;
		}
		
	}
    return 0; 
} 

//dogisaloyalanimal
//5
//a
//alloy
//is
//god
//lamina

//alloybab
//4
//a
//alloy
//b
//b


//thisisgood
//4
//god
//is
//so
//hit
