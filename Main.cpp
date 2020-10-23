#include <iostream>
#include <string>

using namespace std;

// Binary Arrays
int bin1[] = {0,0,0,0,0,0,0,0};
int bin2[] = {0,0,0,0,0,0,0,0};
int resBin[] = {0,0,0,0,0,0,0,0};

// Sum Function 
void Sum(){
	int carry=0;
	int aXORb=0,sumANDcarry=0,aANDb=0;
	for(int i=7;i>=0;i--){
		aXORb = bin1[i]^bin2[i]; // XOR operation on A , B = C
		resBin[i] = aXORb^carry; // XOR operation on C , carry
		sumANDcarry = aXORb&carry; // AND operation on C , carry = D
		aANDb = bin1[i]&bin2[i]; // AND operation on A , B = E
		carry = sumANDcarry|aANDb; // OR operation on D , E = carry
	}
}


//Int to Binary Array Function
void ToBinary(int a, int b) {
	int r;
	int i = 7;
	for(;i >= 0; i--)
	{
		r = a % 2;
		bin1[i] = r;
		a /= 2;
	}
	r = 0;
	for (i=7; i >= 0; i--)
	{
		r = b % 2;
		bin2[i] = r;
		b /= 2;
	}
}

//Binary Array to Int Function
int ToInt(){
	int base = 1;
	int dec = 0;
	for(int i=7; i>=0;i--){
		if (resBin[i] == 1)
			dec += base;
		base *= 2;		
	}
	return dec;
}

int main(){

	int num1,num2;
	cout<<"Enter First Number : ";
 	cin>>num1;
	cout<<"Enter Second Number : ";
 	cin>>num2;
 	ToBinary(num1,num2);
	Sum();
	int res = ToInt();
	cout<<"Result : "<<res<<endl;

}