#include<iostream>
using namespace std;

string Toggle(string str){
	for(int i=0;str[i]!='\0';i++){
		if(str[i]>='A'&& str[i]<='Z'){
			str[i] += 32;
		}
		else if(str[i]>='a' && str[i]<='z'){
			str[i] -= 32;
		}
	}
	return str;
}

int main(){
	string str;
	cin>>str;

	cout<<Toggle(str)<<endl;
	return 0;
}
