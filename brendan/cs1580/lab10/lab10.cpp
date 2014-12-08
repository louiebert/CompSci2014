// Programmer: Brendan Curran              Date: 11/5/2014
// File: lab10.cpp		                     Class: CS 1580 Sec D
// Description: decpihers a data file using the shift cipher 
// and outputs it to a 

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;


int main()
{
  ifstream in;
  ofstream out;
  int shift;
  char read[80];
  char temp[80];
  
  cout << "Welcome to the shift cipher decoder" << endl;
  cout << "What shift would you like to use for the message?(integer): ";
  cin >> shift;
  
  in.open("message.data");
  out.open("decrpyted.txt");
  
  
  while (in >> read)
  {
    strcpy(temp, read);
    for (int i = 0; i < 80; i++)
    {
      if(temp[i] > 96 && temp[i] < 123)
      {
        temp[i] = temp[i] + shift;
        if(shift<0 && temp[i] < 97)
          temp[i] = temp[i] + 26;
        else if (shift>0 && temp[i] > 122)
          temp[i] = temp[i] - 26;
      }
      else if(temp[i] > 63 && temp[i] < 91)
      {
        temp[i] = temp[i] + shift;
        if (shift<0 && temp[i] < 64)
          temp[i] = temp[i] + 26;
        else if (shift >0 && temp[i] > 92)
          temp[i] = temp[i] -26;
      }
    }
      out << temp << " ";
       
  }
  in.close();
  out.close();
  
  cout << endl << "decryption complete" << endl;

  return 0;
  
  
}

