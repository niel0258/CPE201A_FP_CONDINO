#include <iostream>
#include <iomanip>//for setprecision and setw
#include <cstdlib> //for Clear screen func
#include <conio.h>  // For _getch()
using namespace std;

const string degSymbol = string(1, char(248));
const string fTemp = degSymbol + "F";
const string cTemp = degSymbol + "C";

void printLine();
void printGreet(int greet);
void printOptions(char checkLoc[], int size);
void changeOption(int ch, int &choice, int minSize, int maxSize, char checkLoc[]);
int choiceSelect();
void printTempMultiples(int i, int mode);
void printTable();
float convTemp(int mode, float startTemp);
void convTempMain(int mode);

int main() {
	printGreet(0);
	cout << "Choose a function you want to use\n";
    int selected = choiceSelect();
    system("cls");
    
    printGreet(selected);
    switch (selected){
    	case 1:
    		convTempMain(1);
    		break;
    	case 2:
    		convTempMain(2);
    		break;
    	case 3:
    		printTable();
    		break;
	}
	cout << endl;
	printGreet(6);
    return 0;
}

void printLine(){
	cout << "===============================================================================================================\n";
}

void printGreet(int greet){
	printLine();
	cout << "\t\t\t\t";
	switch (greet){
		case 0:
			cout << "Welcome To Temperature Program";
			break;
		case 1:
			cout << fTemp << " to " << cTemp << " converter";
			break;
		case 2:
			cout << cTemp << " to " << fTemp << " converter";
			break;
		case 3:
			cout << "Temperature Conversition Table";
			break;
		case 4:
			cout << cTemp << " to " << fTemp << " Table";
			break;
		case 5:
			cout << fTemp << " to " << cTemp << " Table";
			break;
		case 6: 
			cout << "Thank you for using the Temperature Conversion Program";
			break;
	}
	cout << endl;
	printLine();
}

// Prints the options with the marker
void printOptions(char checkLoc[], int size) {
    cout << "\r";  // Move to start of line
    //used .c_str() to convert stdstring to cstring
    printf("(%c)Convert %s to %s (%c)Convert %s to %s (%c) View Conversion Table",checkLoc[0],fTemp.c_str(),cTemp.c_str(),checkLoc[1],cTemp.c_str(),fTemp.c_str(),checkLoc[2]);
}

// Updates the choice and marker
void changeOption(int ch, int &choice, int minSize, int maxSize, char checkLoc[]) {
	
	//Clear check
    for (int i = 0; i < maxSize; i++) {
    	checkLoc[i] = ' ';
	}

    switch (ch) {
        case 77: // Right arrow
            choice++;
            if (choice > maxSize) {
            	choice = minSize;
			}
            break;
        case 75: // Left arrow
            choice--;
            if (choice < minSize) {
            	choice = maxSize;
			}
            break;
    }

    checkLoc[choice - 1] = '/';
    printOptions(checkLoc, maxSize);
}

// Returns the selected option index (1..3)
int choiceSelect() {
    int ch;
    const int maxSize = 3;
    const int minSize = 1;
    int currentChoice = 1;
    char checkLoc[maxSize] = {'/', ' ', ' '};

    printOptions(checkLoc, maxSize);

    while (true) {
        ch = _getch();  // Get a key

        if (ch == 0 || ch == 224) { // Special key
            ch = _getch(); // Get actual key code
            if (ch == 75 || ch == 77) { // Left or right
                changeOption(ch, currentChoice, minSize, maxSize, checkLoc);
            }
        } else if (ch == 13) { // Enter key
            cout << endl; 
            return currentChoice; 
        }
    }
}

float convTemp(int mode,float startTemp){
	//used floats because integer division they become 0
	double convertedTemp;
	if (mode == 1){
		//f to c
		convertedTemp =  (startTemp - 32) * 5.0/9.0;
	}
	else {
		//c to f
		convertedTemp = (startTemp * (9.0/5.0)) + 32;
	}
	return convertedTemp;
}

void printTempMultiples(int i,int mode){
	string unit1 = (mode == 2) ? cTemp : fTemp;
	string unit2 = (mode == 2) ? fTemp : cTemp;
	cout << setw(2) << i << unit1 << " = " << setw(2) << fixed << setprecision(4) << convTemp(mode, i) << unit2 << "\t";
}

void printTable(){
	cout << endl;
	printGreet(4);
	cout << endl;
		
	for (int i = 0;i <= 10;i++){
		printTempMultiples(i,2);
		printTempMultiples(i + 11,2);
		printTempMultiples(i + 22,2);
		printTempMultiples(i + 33,2);
		printTempMultiples(i + 44,2);
		printTempMultiples(i + 55,2);
		printTempMultiples(i + 66,2);
		printTempMultiples(i + 77,2);
		printTempMultiples(i + 88,2);
		if (i < 2) {
			printTempMultiples(i + 99,2);
		}
		cout << endl;
	}
	
	cout << endl;
	printGreet(5);
	cout << endl;
	//32 to 212
	for (int j = 32; j < 50;j++){
		printTempMultiples(j,1);
		printTempMultiples(j+18,1);
		printTempMultiples(j+36,1);
		printTempMultiples(j+54,1);
		printTempMultiples(j+72,1);
		printTempMultiples(j+90,1);
		printTempMultiples(j+108,1);
		printTempMultiples(j+126,1);
		printTempMultiples(j+144,1);
		printTempMultiples(j+162,1);
		cout << endl;
	}
	cout << endl;
	printTempMultiples(212,1);
}

void convTempMain(int mode){
	float startTemp;
	
	cout << "You used temperature converter\n";
	
	cout << "Input Temperature Value:";
	cin >> startTemp;
	
	float outputTemp = convTemp(mode,startTemp);
	string initialUnit = (mode == 1) ? fTemp: cTemp;
	string outputUnit = (mode == 1) ? cTemp:fTemp;
	
	cout << startTemp << initialUnit << " is equal to " << outputTemp << outputUnit << endl; 
}