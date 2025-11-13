#include <iostream>

using namespace std;

struct arithAns{
	string answerName;
	int answer;
	int remainder;
};

void numChecker(string dialogue, int &input , int minVal, int maxVal);//Error Checking
void printLine();//Formatting purpose

//ILOS
arithAns compArith(int mode,int num1,int num2);
double convTemp(int mode,double startTemp);
float convCur(int mode,float startCur);

//For cleaner switch case
void compArithMain();
void convTempMain();
void convCurMain();

int main(){
	int chosenFunc;
	
	cout << "================================Welcome To Multipurpose Program=================================\n";
	cout << "Choose a function(Input corresponding number):\n (1)Perform arithmetic\n (2)Convert Farenheight To Celsius Or Celsius To Farenheight\n (3)Convert Dollars To Peso Or Peso To Dollars\n (4)Exit Program\n";
	numChecker("Chosen Function: ",chosenFunc,1,4);
	
 	printLine();
	
 	switch (chosenFunc){
	  	case 1:{
	   		compArithMain();
	  		break;
	 	}
	 	case 2:{
	   		convTempMain();
	   		break;
	  	}
	  	case 3:{
	   		convCurMain();
	   		break;
	  	}
	  	case 4:{
	  		//safely exit the program
			break;
		}
	  	default:{
	   	break;
	  	}
 	}
	
	printLine();
	
	cout << "Thank you for using the Multipurpose Program, Rerun me if you need other functions!\n";
	
	printLine();
	return 0;
}

void numChecker(string dialogue, int &input , int minVal, int maxVal){
	bool invalid = true;
 	do {
  		cout << dialogue;
  		cin >> input;
  		invalid = (input > maxVal || input < minVal);
  		if (invalid){
   			cout << "Error, Number Out of Range\n";
  		}
 	}while (invalid);
}

void printLine(){
	cout << "================================================================================================\n";
}

arithAns compArith(int mode,int num1,int num2){
	arithAns answer;
	
	//modes: 1 = add, 2= subtract, 3= multiplication,4=division
	switch (mode){
	case 1:{
		answer.answerName = "sum";
   		answer.answer = num1+num2;
   		break;
  	}
  	case 2:{
   		answer.answerName = "difference";
   		answer.answer = num1-num2;
   		break;
  	}
  	case 3:{
   		answer.answerName = "product";
   		answer.answer = num1*num2;
   		break;
  	}
  	case 4:{
  		answer.answerName = "quotient";
   		answer.answer = num1/num2;
   		answer.remainder = num1%num2;
   		break;
  		}
	}
 	return answer;
}

void compArithMain(){
	int chosenOperation;
	int input1,input2;
	
	cout << "You have chosen to perform arithmetic\n";
	cout << "Choose operation:\n (1)Addition\n (2)Subtraction\n (3)Multiplication\n (4)Division\n";
	numChecker("Chosen operation: ",chosenOperation,1,4);
		
 	cout << "Input first integer: ";
 	cin >> input1;
	
 	cout << "Input second integer: ";
 	cin >> input2;
	
	arithAns output = compArith(chosenOperation,input1,input2);
	
	cout << "The " << output.answerName << " of " << input1 << " and " << input2 << " is " << output.answer;
	
	if (chosenOperation == 4 && output.remainder > 0){
  		cout << " with a remainder of " << output.remainder;
 	}
	
	cout << endl;
}

double convTemp(int mode,double startTemp){
	//used floats because integer division they become 0
 	double convertedTemp;
 	if (mode == 1){
  	convertedTemp = (startTemp - 32) * 5.0/9.0;
 	}
 	else {
  	convertedTemp = (startTemp * (9.0/5.0)) + 32;
 	}
 	return convertedTemp;
}

void convTempMain(){
	int mode;
	int startTemp;
	const char degSymbol = char(248);
	string fTemp = string(1, degSymbol) + "F";
	string cTemp = string(1, degSymbol) + "C";
	
	cout << "You used temperature converter\n";
	cout << "Input 1 if you want to convert " << fTemp <<" to " << cTemp <<" or 2 if you want the reverse\n";
	numChecker("Chosen mode: ",mode,1,2);
	
	cout << "Input Temperature Value:";
	cin >> startTemp;
	
	double outputTemp = convTemp(mode,startTemp);
	string initialUnit = (mode == 1) ? fTemp: cTemp;
	string outputUnit = (mode == 1) ? cTemp:fTemp;
	
	cout << startTemp << initialUnit << " is equal to " << outputTemp << outputUnit << endl; 
}

float convCur(int mode,float startCur){
 	const float pesoDollarRate = 0.017;
	const float dollarPesoRate = 58.16;
	
	float convertedCur;
	
	if (mode == 1){
		convertedCur = startCur * dollarPesoRate;
	}
	else {
		convertedCur = startCur * pesoDollarRate;
 	}
 return convertedCur;
}

void convCurMain(){
	int mode;
	float startCur;
	
	cout << "You used the currency converter\n";
	cout << "Input 1 to convert dollar to peso and 2 if you want the reverse\n";
	
	numChecker("Chosen mode: ",mode,1,2);
	
	cout << "Input currency value: ";
	cin >> startCur;
	
	float outputCur = convCur(mode,startCur);
	
	string inputUnit = (mode == 1) ? "$" : "Php";
	string outputUnit = (mode == 1) ? "Php" : "$";
	
	cout << startCur << inputUnit << " is equal to " << outputCur << outputUnit << endl; 
}
