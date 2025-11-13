#include <iostream>
#include <cmath>
#include <conio.h>  

using namespace std;

void printGreet();
void choiceDialogue(int &curChoice);
bool choiceSelect();

double hypotenuse(double adj, double opp);

int main (){
	bool runLoop = true;
	printGreet();
	while (runLoop){
		double inputSideA,inputSideO;
		cout << "Input 2 sides of the triangle (The opposite and the adjacent)\n";
		cout << "Input side a(Adjacent): ";
		cin >> inputSideA;
		cout << "Input side o(Opposite): ";
		cin >> inputSideO;
		double hyp = hypotenuse(inputSideA,inputSideO);
		printf("From the measurement of the sides: (%g and %g), the measurement of the hypotenuse is %g\n",inputSideA,inputSideO,hyp);
		cout << "\nWould you like to calculate more?\n(/)Yes ( )No";	
		runLoop = choiceSelect();
		if (runLoop){
			system("cls");//Clears output
			printGreet();
		}
	}
	cout << "Exiting program if you need to calculate another hypotenuse, rerun the program" << endl;
	cout << "==================================================================================================================";
	retun 0;
}

void printGreet(){
	cout << "======================================== Welcome To Hypotenuse Finder =======================================\n";
}

void choiceDialogue(bool &curChoice){
	cout << "\r";// Move back to start of line to redraw
	if (curChoice == true){
		cout << "( )Yes (/)No" << flush;
	}
	else {
		cout << "(/)Yes ( )No" << flush;			
	}
	curChoice = !curChoice;//Flips it
}

//if return true break loop if not repeat loop
bool choiceSelect(){
    int ch;
    bool currentChoice = true;//true meaning yes
    while (true) {
        ch = _getch(); // Get a character without waiting for Enter

        if (ch == 0 || ch == 224) { // Special key indicator
            ch = _getch(); // Get the actual key code
            switch (ch) {
                case 75: 
                case 77: 
                    choiceDialogue(currentChoice);
                    break;
            }
        } else if (ch == 13) {
        	cout << endl;
            if (currentChoice == true){
            	return true;
			}
			else {
				return false;
			}
        }
    }
}

double hypotenuse(double adj, double opp){
	return sqrt(pow(adj,2) + pow (opp,2));
}