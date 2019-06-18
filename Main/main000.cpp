#include<iostream>
#include<cmath>
using namespace std;

float function(float x){
	float fun;
	
	//1 / (1 + pow(x,2)) 
	//pow(x,0.5);
	fun = 2 / (pow(x,0.5) + x);
	return fun;
}

int main(){
	float intervalBegin, intervalEnd, h, sum = 0.0, trap, oddSum = 0.0, evenSum = 0.0;
	int n;
	cout << "Enter begining of interval: "; cin >> intervalBegin; 
	cout << "Enter end of interval: "; cin >> intervalEnd;
	cout << "Enter number of iterations: "; cin >> n;
	
	h = (intervalEnd-intervalBegin)/n;
	for(int i = 1; i <= n-1; i++){
		sum = sum + function(intervalBegin + i*h);
		if(i % 2 == 0)
			evenSum += function(intervalBegin + i*h);
		else
			oddSum += function(intervalBegin + i*h);	
	}
	
	cout << "\nTrapezoidal Result = " << (h/2) *( function(intervalBegin) + function(intervalEnd) + 2.0 * sum ) << endl;
	
	//if(n % 3 == 0)
	cout << "Simpson Result = " << (h/3) *( function(intervalBegin) + function(intervalEnd) + 2.0 * evenSum + 4.0 * oddSum) << endl;
	
	return 0;
}


