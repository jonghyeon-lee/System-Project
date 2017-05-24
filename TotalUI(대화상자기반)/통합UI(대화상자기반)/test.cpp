#include <iostream>
#include <string>
using namespace std;

int main(){
	int a = 6;
	int b = 2;
	while( a<10 ){
		b = 5;
		while( a>1 ){
			a = a+100;
		}
		a = a-1;
	}
	if( a<5 ){
		a = b+4;
	}else{
		a = b-3;
	}
}
