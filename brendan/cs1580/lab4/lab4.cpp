// Programmer: Brendan Curran               Date: 9/24/2014
// File: lab4.cpp For and switch            Class: CS 1580 Sec D

#include <iostream>
using namespace std;

int main()
{
  //loop input for number of votes, brands = tallies for votes, vote is user selection
  int loop, apple = 0, lenovo=0, dell=0, hp=0, vote; 
  cout << "Welcome to the laptop brand survey"";
  cout <<"How many times would you like to vote?: ";
  cin >> loop;

  for (int lcv = 1; lcv <=loop; lcv++)
  {
    cout << "What is your favorite laptop brand?";
    cout << ""1. Apple"2. HP"3. Dell"4. Lenovo"";
    cin >> vote;
    while (vote <1 || vote >4)
    {
      //validate vote
      cout << " Invalid vote, please enter again:";
      cin >> vote;
    }
    switch(vote)
    {
      case 1:
        apple++; //add tally to vote
        break;
      case 2:
        hp++;
        break;
      case 3:
        dell++;
        break;
      case 4:
        lenovo++;
        break;
    }
  }
  cout <<""Apple received " << apple << " votes" << endl;
  cout << "HP received " << hp << " votes" << endl;
  cout << "Dell received " << dell << " votes" << endl;
  cout << "Lenovo received " << lenovo << " votes" << endl;
  
  //apple is highest priority when tide, followed by
  //hp, then dell, then lenovo
  //arbitrary order
  if (apple >= lenovo && apple >= dell && apple >= hp) 
    cout <<"Apple is the winner" << endl;
  else if (hp > apple && hp >= dell && hp >= lenovo)
    cout << "HP is the winner";
  else if (dell > apple && dell > hp && dell >= lenovo)
    cout << "Dell is the winner";
  else
    cout << "Lenovo is the winner";

  cout <<"" Thank you for voting"";

}
