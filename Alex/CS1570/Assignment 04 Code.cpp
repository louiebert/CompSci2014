//-----------------------------------------------------------------------
// Name: ALEX SHAW 	 Date: 09-25-14
// File: hw04.cpp     Class: Section CS 1570, Section B
//------------------------------------------------------------------------
// Program Description:
// Allows user to purchase medications from vending machine-style menu.
// Calculates and displays change for each transaction, number of overall pills,
// and the size of pill container required.

#include <iostream>
#include <string>

using namespace std;
int main()
{
  const float NAPROSYN_PRICE = 10.00;       //Initialize price constants
  const float KRYSTEXXA_PRICE = 3.50;
  const float SCHRAUT_PRICE = 4.00;
  const float XELIJANZ_PRICE = 6.75;
  const float QNASL_DIPROPIONATE_PRICE = 12.25;
  const float GOLYTELY_PRICE = 14.33;

  const int NAPROSYN_PILL_NUMBER = 15;      //Initialize constants to hold
  const int KRYSTEXXA_PILL_NUMBER = 30;     // number of pills for each med
  const int SCHRAUT_PILL_NUMBER = 20;
  const int XELIJANZ_PILL_NUMBER = 5;
  const int QNASL_DIPROPIONATE_PILL_NUMBER = 40;
  const int GOLYTELY_PILL_NUMBER = 1;

  int user_menu_choice = 0;                 //Input vars
  float amount_paid = 0.00;

  float change = 0.00;                      //Holds user's change
  float remaining_payment = 0.00;           //Holds the money the user owes
  int number_of_pills = 0;                  //Holds overall sum of pills
  string container_size = "";               //Holds pill container size
  bool quit = false;                        //Program runs until quit = true
  bool valid_input = true;                  //Sets to false if invalid choice,
                                            // returns user to menu

  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(2);

  cout << """\t\t\tWelcome to INSTY-MEDS!";
  do
  {
    valid_input = true;                    //Resets valid_input in case user
                                           // previously input invalid choice
    number_of_pills = 0;                //Resets pill number in case user now
                                        // chooses Option 5.

    cout << ""\t\tMedication\tPrice" << endl             //Display menu
         << "\t\t1. Naprosyn\t$10.00" << endl
         << "\t\t2. Krystexxa\t$3.50" << endl
         << "\t\t3. Schraut!\t$4.00" << endl
         << "\t\t4. Xeljanz\t$$6.75" <<endl
         << "\t\t5. Qnasl Diproprionate\t$12.25" << endl
         << "\t\t6. GoLytely\t$14.33" << endl
         << "\t\t7. Quit" << endl
         << "Choice (number): ";
    cin >> user_menu_choice;

    switch (user_menu_choice)                             //Determine amount to
    {                                                     // be paid, sum pills
      case 1:
        cout << "You've chosen Naprosyn" << endl;
        remaining_payment = NAPROSYN_PRICE;
        number_of_pills = NAPROSYN_PILL_NUMBER;
        break;

      case 2:
        cout << "You've chosen Krystexxa" << endl;
        remaining_payment = KRYSTEXXA_PRICE;
        number_of_pills = KRYSTEXXA_PILL_NUMBER;
        break;

      case 3:
        cout << "You've chosen Schraut!" << endl;
        remaining_payment = SCHRAUT_PRICE;
        number_of_pills = SCHRAUT_PILL_NUMBER;
        break;

      case 4:
        cout << "You've chosen Xeljanz" << endl;
        remaining_payment = XELIJANZ_PRICE;
        number_of_pills += XELIJANZ_PILL_NUMBER;


      case 5:
        cout << "You've chosen Qnasl Diproprionate" << endl;
        remaining_payment = QNASL_DIPROPIONATE_PRICE;
        number_of_pills += QNASL_DIPROPIONATE_PILL_NUMBER;


      case 6:
        cout << "You've chosen GoLytely" << endl;
        remaining_payment = GOLYTELY_PRICE;
        number_of_pills += GOLYTELY_PILL_NUMBER;
        break;


      case 7:
        cout << "You've chosen to exit the program" << endl;
        quit = true;
        break;


      default:
        cout << "That's not a valid choice" << endl;
        valid_input = false;
        break;

    }

//------------User pays, change is calculate while user hasn't quit----------//

    if (!quit && valid_input)            //Only occurs if user didn't
    {                                    // quit & did input valid choice
      do                                   //Loops until user pay entire amount
      {
        cout << "Please pay the remaining $" << remaining_payment << endl;
        cout << "Money entered (dollars): $";
        cin >> amount paid;
        remaining_payment -= amount_paid;
      } while (0.00 < remaining_payment);

      change = remaining_payment * -1;                          //Calcs change
      cout << "Your change is $" << remaining_payment << endl;

//--------------------------Calculate size of pill box needed-----------------//

      if (number_of_pills <= 10)
      {
        container_size = “10 count”;
      }

      else if (number_of_pills > 10 && number_of_pills <= 25)
      {
        container_size = “25 count”;
      }

      else if (number_of_pills > 25 && number_of_pills <= 50)
      {
        container_size = “50 count”;
      }

      else if (number_of_pills > 50 && number_of_pills <= 100)
      {
        container_size = “100 count”;
      }

//------------------------Display user's info---------------------------------//

      cout << "/n/n/t/tNumber of pills: " << number_of_pills << " pills"
           << "/n/t/tSize of container needed:" << container_size

    }
  } while (true != quit);          //Repeat above loop until user quits


  cout << "/n/t/t/t/tGoodbye!" endl;
  return 0;
}
