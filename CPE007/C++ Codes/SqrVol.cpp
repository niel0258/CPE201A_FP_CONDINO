#include <iostream>
#include <cmath>

using namespace std;

int getVolSqr(int side);

int main (){
	int inputSide;
	cout << "========================= Welcome to Square Volume Calculator ======================\n";
	cout << "Please input side to calculate the volume \nSide(in cm):";
	cin >> inputSide;
	int sqrVol = getVolSqr(inputSide);
	printf("If a cube has a side of %i cm , then it will have a volume of %i cubic cm\n",inputSide,sqrVol);
	cout << "Thank you for using The Square Volume Calculator\n===============================================================================";
	return 0;
}

int getVolSqr(int side){
	return pow(side,3);
}
