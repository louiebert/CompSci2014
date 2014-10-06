// Programmer: ALEX SHAW         Date: 10-05-14
// File: hw05.cpp                Class:  CS1570 Section B
// Purpose: Prompts for the required values, calculates and displays the
// an indicator of bodily fitness of the user's choosing such as Body Mass
// Index, Creatine Clearance, Coronary Risk, or Totter Index.

#include <iostream>
using namespace std;

//-------------------------------Function prototypes-------------------------//

//Description: greeting() welcomes the user with message to screen.
//Pre-condition: There is no pre-condition.
//Post-condition: This function displays a greeting to the user.
void greeting();

//Description: bodyMassIndex calculates and returns body mass index (BMI).
//Pre-condition: All parameters must be positive.
//Post-condition: The BMI value is returned
float bodyMassIndex(const int mass_lbs, const int height);

//Description: creatineClearance calculates and returns creatine clearance.
//Pre-condition: All parameters must be positive.
//Post-condition: The creatine clearance value is returned
float creatineClearance(const int age, const int weight_kg, const float
                        serum_creatine);

//Description: coronaryRisk calculates and returns the coronary risk.
//Pre-condition: All parameters must be positive.
//Post-condition: The coronary risk value is returned.
float coronaryRisk(const float bmi, const bool parent_heart_disease,
                   const short pounds_bacon_eaten);

//Description: totterIndex calculates and returns the totter index value.
//Pre-condition: All parameters must be non-negative.
//Post-condition: The totter index value is returned.
float totterIndex(const float left_leg_length, const float right_leg_length);

//Description: goodbye bids the user farewell.
//Pre-condition: There is no pre-condition.
//Post-condition: Outputs a sign-off message.
void goodbye();

//Description: menu displays a menu to the screen from which the user chooses.
//Pre-condition: There is not pre-condition.
//Post-condition: The menu is displayed to the screen.
void display_menu();

int main()
{
//----------------------Declaring and initializing variables-----------------//

                                //Input vars

  int height = 0;               //BMI vars
  int mass_lbs = 0;

  int age = 0;                            //Creatine clearance vars
  int weight_kg = 0;
  float serum_creatine = 0.0;
                                          //Coronary risk vars
  bool parent_heart_disease = 0;          //Tells if parent has heart disease
  short pounds_bacon_eaten = 0;           //Holds bacon eaten for breakfast

  float left_leg_length = 0;                //Totter index vars
  float right_leg_length = 0;

  int menu_choice = 0;                    //Holds user's menu choice
  bool quit = 0;                          //Determines if user wants to quit

  float bmi = 0.0;                        //Calculated values
  float creatine_clearance = 0.0;
  float coronary_risk = 0.0;
  float totter_index = 0.0;

  greeting();                             //Greet the user

  do
  {    
    display_menu();                       //Display menu and prompt for choice
    cout << "\nChoice (number): ";    
    cin >> menu_choice;

//-------Prompts for values and calculates based on user choice--------------//

    switch(menu_choice)
    {
      case 1:                                                //BMI choice
        cout << "Enter your mass (lbs): ";
        cin >> mass_lbs;
        cout << "Enter your height (in): ";
        cin >> height;
        bmi = bodyMassIndex(mass_lbs, height);
        cout << "Your BMI value is: " << bmi << endl;
        break;

      case 2:                                                //Creatine
        cout << "Enter your age (years): ";                  // clearance
        cin >> age;                                          // choice

        cout << "Enter your weight (kg): ";
        cin >> weight_kg;

        cout << "Enter your serum creatine value: ";
        cin >> serum_creatine;

        creatine_clearance = creatineClearance(age, weight_kg, serum_creatine);

        cout << "Your creatine clearance value is: " << creatine_clearance <<
        endl;

        break;

      case 3:                                       //Coronary risk choice
        cout << "Please enter your BMI value: ";  
        cin >> bmi;

        do                                      //Prompts until valid input
        {
          cout << "Does one/both parents have heart disease? (y = 1, n = 0): ";
          cin >> parent_heart_disease;
        } while (parent_heart_disease != 0 && parent_heart_disease != 1);


        cout << "How many pounds of bacon did you have this morning: ";
        cin >> pounds_bacon_eaten;

        if (pounds_bacon_eaten > 100)                 //Cares for user's safety
        {
          cout << "ER is on the line now.....you pig!" << endl;
        }

        coronary_risk = coronaryRisk(bmi, parent_heart_disease,
        pounds_bacon_eaten);

        cout << "Your coronary risk value is: " << coronary_risk << endl;

        break;

      case 4:                                                         //Totter
        cout << "Enter the length of your left leg (in): ";           // index
        cin >> left_leg_length;                                       // choice

        cout << "Enter the length of your right leg (in): ";
        cin >> right_leg_length;

        if (0 == left_leg_length || 0 == right_leg_length)        //If either
          totter_index = 0;                                       // leg length
                                                                  // is 0 in,
        else                                                      // TI = 0
          totter_index = totterIndex(left_leg_length, right_leg_length);

        cout << "Your totter index value is: " << totter_index << endl;

        break;

      case 5:                                       //Enables exiting program,
        quit = true;                                // displays sign-off
        goodbye();
        break;

      default:                                     //Displays error message,
        cout << "Error: Invalid input." << endl;   // if invalid choice 
    }

  } while(false == quit);                            //Repeats above until 
                                                     // user chooses to quit
  return 0;
}

//------------------------------Function definitions-------------------------//


//--------------------------------Greets the user----------------------------//

void greeting()
{
  cout << "Welcome to Dr. Eloe's Health-o-Matic!" << endl;
}


//--------------------------------Calculates BMI-----------------------------//

float bodyMassIndex(const int mass_lbs, const int height)
{
  float bmi = ((static_cast<float>(mass_lbs)) / (height * height)) * 703;

  return bmi;
}


//---------------------Calculates Creatine Clearance-------------------------//

float creatineClearance(const int age, const int weight_kg, const float
                        serum_creatine)
{
  float creatine_clearance = (140 - age) * (static_cast<float>(weight_kg)) /
                             (72 * serum_creatine);

  return creatine_clearance;
}


//--------------------------Calculates coronary risk-------------------------//

float coronaryRisk(const float bmi, const bool parent_heart_disease,
                   const short pounds_bacon_eaten)
{
  float coronary_risk;
  int bmi_amount = 0;        //Holds 0 or 2 depending on if the BMI > 30

  if (bmi > 30)              
    bmi_amount = 2;

  coronary_risk = bmi_amount + parent_heart_disease + pounds_bacon_eaten;

  return coronary_risk;
}


//-------------------------Calculates the totter index-----------------------//

float totterIndex(const float left_leg_length, const float right_leg_length)
{
  float totter_index = left_leg_length / right_leg_length;

  return totter_index;
}


//------------------------Outputs a sign-off message-------------------------//

void goodbye()
{
  cout << "Fare thee well." << endl;
}


//-------------------------Displays menu to screen---------------------------//

void display_menu()
{
  cout << "\n\n\t\t\tEloe's Health-o-Matic"
       << "\n\t\t1. Body Mass Index (BMI)"
       << "\n\t\t2. Creatine Clearance (CC)"
       << "\n\t\t3. Coronary Risk (CR)"
       << "\n\t\t4. Totter Index (TI)"
       << "\n\t\t5. Quit" << endl;
  return;
}

