//Programmer: LOUIE BERTONCIN     Date: 9/23/2014
//File: H4 Insty-Meds             Class: CS 1570, Section D
//Purpose: Correctly use the switch-case to make an entirely realistic
//  vending machine

#include <iostream>
using namespace std;

int main()
{
  // Variables
  float money;
  float change;
  short numQuarters;
  short numDimes;
  short numNickels;
  short numPennies;
  bool active = true;
  bool chose_incorrectly = false;
  bool incorrect_payment = true;
  short pill_choice;

  // Pill Constants
  const float NAPROSYN = 10.00;
  const short NUMNAPROSYN = 15;

  const float KRYSTEXXA = 3.50;
  const short NUMKRYSTEXXA = 30;

  const float SCHRAUT = 4.00;
  const short NUMSCHRAUT = 20;

  const float XELJANZ = 6.75;
  const short NUMXELJANZ = 5;

  const float QNASL_DIPROPIONATE = 12.25;
  const short NUMQNASL_DIPROPIONATE = 40;

  const float GOLYTELY = 14.33;
  const short NUMGOLYTELY = 1;

  // Currency Constants
  const short QUARTER = 25;
  const short DIME = 10;
  const short NICKEL = 5;

  // Sets a fixed two decimal output
  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(2);

  cout << "\nWelcome to the wonderful Insty-Meds vending machine!! \n" << endl;
  cout << "========================================================" << endl;

  do
  {
    do
    {
      chose_incorrectly = false;

      cout << "\t\tPrescription Options" << endl;
      cout << "\t\t    ------------\n" << endl;
      cout << "1. Naprosyn (pain relief)                                     $"
        << NAPROSYN << endl;
      cout << "2. Krystexxa (relief from grout)                              $"
        << KRYSTEXXA << endl;
      cout << "3. Schraut! (relief from diarrhea)                            $"
        << SCHRAUT << endl;
      cout << "4. Xeljanz (relief from Hippopotomonstrosesquipedaliophobia)  $"
        << XELJANZ << endl;
      cout << "5. Qnasl Dipropionate (treatment of nasally fitted Q-tips)    $"
        << QNASL_DIPROPIONATE << endl;
      cout << "6. GoLytely (to treat gluttony)                               $"
        << GOLYTELY << endl;
      cout << "7. I don't want any" << endl << endl;
      cout << "Please choose a number from the list above: ";
      cin >> pill_choice;

      switch(pill_choice)
      {
        case 1:
          cout << "You chose Naprosyn which is packaged with " <<
            NUMNAPROSYN << " units per container \n" << endl;
          do
          {
            cout << "Naprosyn costs $" << NAPROSYN << endl;
            cout << "How much money are you paying with? ";
            cin >> money;
            if(money >= NAPROSYN)
            {
              incorrect_payment = false;
            }
            else
            {
              cout << "You did not pay with enough money\n" << endl;
              incorrect_payment = true;
            }
          } while (incorrect_payment);

          change = money - NAPROSYN;
          change *= 100;
          numQuarters = change/QUARTER;
          change -= QUARTER*numQuarters;
          numDimes = change/DIME;
          change -= DIME*numDimes;
          numNickels = change/NICKEL;
          change -= NICKEL*numNickels;
          // Float value of change doesn't translate correctly, so I helped the
          //   compiler round it.
          numPennies = change + 0.5;

          cout << "\nIf this were a real vending machine, you'd now receive"
            << endl;
          if (numQuarters)
            cout << numQuarters << " quarter(s)," << endl;
          if (numDimes)
            cout << numDimes << " dime(s)," << endl;
          if (numNickels)
            cout << numNickels << " nickel(s)," << endl;
          if (numPennies)
            cout << numPennies << " penn(y/ies)," << endl;
          cout << "and " << NUMNAPROSYN << " units of Naprosyn. \n" << endl;
          cout << "Thanks for your purchase!\n\n" <<endl;
        break;

        case 2:
          cout << "You chose Krystexxa which is packaged with " <<
              NUMKRYSTEXXA << " units per container \n" << endl;
          do
          {
            cout << "Krystexxa costs $" << KRYSTEXXA << endl;
            cout << "How much money are you paying with? ";
            cin >> money;
            if(money >= KRYSTEXXA)
            {
              incorrect_payment = false;
            }
            else
            {
              cout << "You did not pay with enough money\n" << endl;
              incorrect_payment = true;
            }
          } while (incorrect_payment);

          change = money - KRYSTEXXA;
          change *= 100;
          numQuarters = change/QUARTER;
          change -= QUARTER*numQuarters;
          numDimes = change/DIME;
          change -= DIME*numDimes;
          numNickels = change/NICKEL;
          change -= NICKEL*numNickels;
          // Float value of change doesn't translate correctly, so I helped the
          //   compiler round it.
          numPennies = change + 0.5;

          cout << "\nIf this were a real vending machine, you'd now receive"
            << endl;
          if (numQuarters)
            cout << numQuarters << " quarter(s)," << endl;
          if (numDimes)
            cout << numDimes << " dime(s)," << endl;
          if (numNickels)
            cout << numNickels << " nickel(s)," << endl;
          if (numPennies)
            cout << numPennies << " penn(y/ies)," << endl;
          cout << "and " << NUMKRYSTEXXA << " units of Krystexxa. \n" << endl;
          cout << "Thanks for your purchase!\n\n" <<endl;
        break;

        case 3:
          cout << "You chose Schraut! which is packaged with " <<
              NUMSCHRAUT << " units per container \n" << endl;
          do
          {
            cout << "Schraut! costs $" << SCHRAUT << endl;
            cout << "How much money are you paying with? ";
            cin >> money;
            if(money >= SCHRAUT)
            {
              incorrect_payment = false;
            }
            else
            {
              cout << "You did not pay with enough money\n" << endl;
              incorrect_payment = true;
            }
          } while (incorrect_payment);

          change = money - SCHRAUT;
          change *= 100;
          numQuarters = change/QUARTER;
          change -= QUARTER*numQuarters;
          numDimes = change/DIME;
          change -= DIME*numDimes;
          numNickels = change/NICKEL;
          change -= NICKEL*numNickels;
          // Float value of change doesn't translate correctly, so I helped the
          //   compiler round it.
          numPennies = change + 0.5;

          cout << "\nIf this were a real vending machine, you'd now receive"
            << endl;
          if (numQuarters)
            cout << numQuarters << " quarter(s)," << endl;
          if (numDimes)
            cout << numDimes << " dime(s)," << endl;
          if (numNickels)
            cout << numNickels << " nickel(s)," << endl;
          if (numPennies)
            cout << numPennies << " penn(y/ies)," << endl;
          cout << "and " << NUMSCHRAUT << " units of Schraut!. \n" << endl;
          cout << "Thanks for your purchase!\n\n" <<endl;
        break;

        case 4:
          cout << "You chose Xeljanz which is packaged with " <<
              NUMXELJANZ << " units per container \n" << endl;
          do
          {
            cout << "Xeljanz costs $" << XELJANZ << endl;
            cout << "How much money are you paying with? ";
            cin >> money;
            if(money >= GOLYTELY)
            {
              incorrect_payment = false;
            }
            else
            {
              cout << "You did not pay with enough money\n" << endl;
              incorrect_payment = true;
            }
          } while (incorrect_payment);

          change = money - GOLYTELY;
          change *= 100;
          numQuarters = change/QUARTER;
          change -= QUARTER*numQuarters;
          numDimes = change/DIME;
          change -= DIME*numDimes;
          numNickels = change/NICKEL;
          change -= NICKEL*numNickels;
          // Float value of change doesn't translate correctly, so I helped the
          //   compiler round it.
          numPennies = change + 0.5;

          cout << "\nIf this were a real vending machine, you'd now receive"
            << endl;
          if (numQuarters)
            cout << numQuarters << " quarter(s)," << endl;
          if (numDimes)
            cout << numDimes << " dime(s)," << endl;
          if (numNickels)
            cout << numNickels << " nickel(s)," << endl;
          if (numPennies)
            cout << numPennies << " penn(y/ies)," << endl;
          cout << NUMXELJANZ << " units of Xeljanz,\n" <<
            NUMQNASL_DIPROPIONATE << " units of Qnasl Dipropionate,\nand " <<
            NUMGOLYTELY << " unit of GoLytely." << endl;
          cout << "Thanks for your purchase!\n\n" <<endl;
        break;

        case 5:
          cout << "You chose Qnasl Dipropionate which is packaged with " <<
              NUMQNASL_DIPROPIONATE << " units per container \n" << endl;
          do
          {
            cout << "Qnasl Dipropionate costs $" << QNASL_DIPROPIONATE << endl;
            cout << "How much money are you paying with? ";
            cin >> money;
            if(money >= GOLYTELY)
            {
              incorrect_payment = false;
            }
            else
            {
              cout << "You did not pay with enough money\n" << endl;
              incorrect_payment = true;
            }
          } while (incorrect_payment);

          change = money - GOLYTELY;
          change *= 100;
          numQuarters = change/QUARTER;
          change -= QUARTER*numQuarters;
          numDimes = change/DIME;
          change -= DIME*numDimes;
          numNickels = change/NICKEL;
          change -= NICKEL*numNickels;
          // Float value of change doesn't translate correctly, so I helped the
          //   compiler round it.
          numPennies = change + 0.5;

          cout << "\nIf this were a real vending machine, you'd now receive"
            << endl;
          if (numQuarters)
            cout << numQuarters << " quarter(s)," << endl;
          if (numDimes)
            cout << numDimes << " dime(s)," << endl;
          if (numNickels)
            cout << numNickels << " nickel(s)," << endl;
          if (numPennies)
            cout << numPennies << " penn(y/ies)," << endl;
          cout << NUMQNASL_DIPROPIONATE <<
            " units of Qnasl Dipropionate,\nand " <<
            NUMGOLYTELY << " unit of GoLytely." << endl;
          cout << "Thanks for your purchase!\n\n" <<endl;
        break;

        case 6:
          cout << "You chose GoLytely which is packaged with " <<
              NUMGOLYTELY << " units per container \n" << endl;
          do
          {
            cout << "GoLytely costs $" << GOLYTELY << endl;
            cout << "How much money are you paying with? ";
            cin >> money;
            if(money >= GOLYTELY)
            {
              incorrect_payment = false;
            }
            else
            {
              cout << "You did not pay with enough money\n" << endl;
              incorrect_payment = true;
            }
          } while (incorrect_payment);

          change = money - GOLYTELY;
          change *= 100;
          numQuarters = change/QUARTER;
          change -= QUARTER*numQuarters;
          numDimes = change/DIME;
          change -= DIME*numDimes;
          numNickels = change/NICKEL;
          change -= NICKEL*numNickels;
          // Float value of change doesn't translate correctly, so I helped the
          //   compiler round it.
          numPennies = change + 0.5;

          cout << "\nIf this were a real vending machine, you'd now receive"
            << endl;
          if (numQuarters)
            cout << numQuarters << " quarter(s)," << endl;
          if (numDimes)
            cout << numDimes << " dime(s)," << endl;
          if (numNickels)
            cout << numNickels << " nickel(s)," << endl;
          if (numPennies)
            cout << numPennies << " penn(y/ies)," << endl;
          cout << "and " << NUMGOLYTELY << " unit of GoLytely. \n" << endl;
          cout << "Thanks for your purchase!\n\n" <<endl;
        break;

        case 7:
          active = false;
        break;

        default:
          cout << "\nYou are a poor English reader. Please choose between 1-7\n"
            << endl;
          chose_incorrectly = true;
      }
    } while (chose_incorrectly);
  } while (active);

  cout << "Dr. Eloe appreciates being able to scam you today, thanks!!" << endl;

  return 0;
}
