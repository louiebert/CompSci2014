// Programmer: Brendan Curran              Date: 10/5/2014
// File: hw5.cpp                           Class: CS 1570 Sec C
// Description: health indicators calculator

#include <iostream>
using namespace std;

// Description: shows a greeting message on the screen
// Pre : none 
// Post : outputs  greeting
void greeting();

// Description: user inputs height and weight, calculates then outputs bmi
// Pre :  two integer parameters, height and weight
// Post : return float bmi
float bodyMassIndex(const int bmiHeight, const int bmiWeight);
  
// Description: calculates creatinine clearance value from age, weight
// and serum count, and outputs value to screen
// Pre: two integer parameters, age and weight,
// one float parameter, serum creatine value
// Post: return float creatinine clearance value
float creatinineClearance(const int ccWeight, const int ccAge, const float ccSerum);
  
// Description: calculate risk of heart disease
// based on genetics, bmi, and bacon consumption, then outputs value on screen
// Pre: parameters: short of breakfast bacon consumption,
// float bmi, and boolean for genetic predisposition to heart disease
// post: return integer coronary risk score
int coronaryRisk(const float crBMI, const bool crDisposition, const short crBacon);
  
// Description: calculates totter index, ratio of length of legs and 
// outputs to screen
// Pre: two float parameters, left leg and right leg length
// Post: returns float totter index
float totterIndex(const float tiLeft, const float tiRight);

// Description: prints out a goodbye message
// Pre: none
// Post: goodbye message
void goodbye();

// Description: displays a menu of the health calculations the
// program can perform, then takes user choice of calculation and returns it
// Pre: none
// Post: return int menu choice
int mainmenu();

int main()
{
  int choice, weight, height, age, CR;
  short bacon;
  bool loop = true, CRhistory;
  float bmi, serum, creatinine, Lleg, Rleg, TI;
  char answer;
  greeting();
  
  do
  {
    choice = mainmenu();
    switch (choice)
    {
      case 1:
        cout << "Please enter integer height: ";
        cin >> height;
        cout << "Please enter integer weight in pounds: ";
        cin >> weight;
        bmi = bodyMassIndex(height, weight);
        cout << "\nBMI = " << bmi << endl;
        break;
      
      case 2:
        cout << "Please enter your weight in kg: ";
        cin >> weight;
        cout << "Please enter your age: ";
        cin >> age;
        cout << "Please input serum creatine value: ";
        cin >> serum;
        creatinine = creatinineClearance(weight, age, serum);
        cout << "\nCC = " << creatinine << endl;
        break;       
      
      case 3:
        cout << "Please input BMI: ";
        cin >> bmi;
        cout << "Is there a history of heart disease in the family? (y/n): ";
        cin >> answer;
        if (answer == 'y')
          CRhistory = true;
        else
          CRhistory = false;
        cout << "Please input how much bacon you ate this morining(lbs): ";
        cin >> bacon;
        CR = coronaryRisk(bmi, CRhistory, bacon);
        cout << "\nCR = " << CR << endl;
        break;
        
      case 4:
        cout << "Please input length of left leg: ";
        cin >> Lleg;
        cout << "Please input length of right leg: ";
        cin >> Rleg;
        TI = totterIndex(Lleg, Rleg);
        cout << "\nTI = " << TI << endl;
        break;
        
      case 5:
        loop = false;
        break;
      default:
        cout << "Invalid menu choice, try again" << endl;
    }
	cout << endl;
  } while(loop);
  
  goodbye();
}

void greeting()
{
  cout << "Welcome to Dr. Eloe's Health-o-matic Calculator program\n";
  cout << "                     of calculation" << endl;
}

int mainmenu()
{
	int input;
	cout << "    Eloe's Health o-matic "<< endl;
    cout << "1. Body Mass Idex (BMI)" << endl;
    cout << "2. Ceratinine Clearance (CC)" << endl;
    cout << "3. Coronary Risk (CR)" << endl;
    cout << "4. Totter index (TI)" << endl;
    cout << "5. Quit" << endl;
    cout << " your choice: ";
    cin >> input;
    return input;
}

float bodyMassIndex(const int bmiHeight, const int bmiWeight)
{
  float bmi = 1.0*bmiWeight/(bmiHeight*bmiHeight)*703;
  return bmi;
}

float creatinineClearance(const int ccWeight, const int ccAge, const float ccSerum)
{
  float ccValue = ((140.0-ccAge)*ccWeight)/(72.0*ccSerum);
  return ccValue;
}

int coronaryRisk(const float crBMI, const bool crDisposition, const short crBacon)
{
  int crValue= 0;
  if (crBMI > 30)
    crValue += 2;
  if (crDisposition)
    crValue += 1;
  crValue += crBacon;
  return crValue;
}

float totterIndex(const float tiLeft, const float tiRight)
{
  float tiValue;
  if (tiLeft == 0 || tiRight == 0)
    tiValue = 0;
  else
    tiValue = tiLeft/tiRight;
  return tiValue;
}

void goodbye()
{
  cout << "Thank you for using the health-o-matic, goodbye" << endl;
}
