//Programmer: Brendan Curran     Date: 9/23/2014
//File: hw4 Drug Vending Machine Class cs 1570, section C
//purpose: To run a vending machine that dispenses drugs

#include <iostream>
using namespace std;

int main()
{
  int choice, pills, bottle, dfault;
  float money, cost, change;
  bool quit = true;
  
  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(2);
  while (quit)
  {
    dfault = 0; //for working with default case, (invalid option)
    cout << ""Welcome to your drug vending machine "";
    cout << "     INSTA_DRUGS"     -----------"";
    cout << "1. Naprosyn				$10.00		(pain relief)"";
    cout << "2. Krystexxa				$3.50		(gout relief)"";
    cout << "3. Schraut!				$4.00		(diarrhea relief)"";
    cout << "4. Xeljanz				$6.75		(Hippopot... relief)"";
    cout << "5. Qnasl Dipropionate			$12.25";
    cout <<"    (treatment of nasal q tips)"";
    cout << "6. GoLytely				$14.33		(gluttony treatment)"";
    cout << "7. Quit"";
    cout << "Please make a selection: ";
    cin >> choice;
    switch (choice)
    {
      case 1: 
        cout << "You have selected Naprosyn, please insert cash ($10.00): ";
        cost = 10;
        pills = 15;	  
        break;
      case 2:
        cout << "You have selected Krystexxa, please insert cash ($3.50): ";
        cost = 3.50;
        pills = 30;
        break;
      case 3:
        cout << "You have selected Schraut, please insert cash ($4.00): ";
        cost =4;
        break;
      case 4:
        cout << "You have selected Xeljanz, and will also receive Qnasl "; 
        cout <<"Dipropionate and GoLytely, please insert cash ($6.75): ";
        cost = 6.75;
        pills = 46;
        break;
      case 5:
        cout << "You have selected Qnasl Dipropionate, and will also receive";
        cout << " GoLytely, please insert cash ($12.25): ";
        cost = 12.25;
        pills = 41;
        break;
      case 6:
        cout << "You have selected GoLytely, please insert cash ($14.33): ";
        cost = 14.33;
        pills = 1;
        break;
      case 7:
         quit = false;
         break;
      default:
        cout <<""Herp derp I can't do that"";
        dfault = 1;
        break;
    }
    if (quit && dfault != 1)
    {
      cin >> money;
      while (money < cost)
      {
        cout << "Amount tendered is insufficient, please insert again: ";
        cin >> money;
      }
      change = money - cost;
      cout << ""Your change is: $" << change;
	  
      if (pills < 11)
        bottle = 10;
      else if (pills < 26)
        bottle = 25;
      else if (pills < 51)
        bottle = 50;
      else
        bottle = 100;
	  
      cout << ""You will recieve " << pills << " pills, please have a " 
      << bottle << " count bottle ready" << endl;
      cout << ""Dispensing now";
      cout << ""Thank you for your purchase"";
	  }
  }
  cout << "goodbye"";
  return 0;
  

}