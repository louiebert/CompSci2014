
#include <iostream>
#include <stdio.h>
#include <ctype.h>

using namespace std;

// make_array() takes a long source char array and creates a two dimensional
//   array with the words separated by spaces. Returns # of words in target.
// Pre: source[] must not have a word exceeding 21 characters. source[] also
//   shouldn't ever have two spaces in a row. target[] must have the second
//   dimension as 22 (second square bracket number).
// Post: Makes a 2D array from the words of source. Punctuation is omitted in
//   the final target array. Returns number of indexes (words) in target.
int make_array(const char source[], char target[][22]);

int main()
{
  string complaints;
  // Correct declaration of a 2D array:<arrayName>[1st dimension][2nd dimension]
  char complaintStr[100][22];

  cout << "Enter complaint: ";
  getline(cin, complaints, '\n');

  // complaintStr becomes a 2D array of chars
  make_array(complaints.c_str(), complaintStr);

  cout << complaintStr[2] << endl;

  return 0;
}


int make_array(const char source[], char target[][22])
{
  int i = 0, j = 0, k = 0;
  while(source[i] != '\0')
  {
    if(source[i] != ' ')
    {
      target[k][j] = tolower(source[i]);
      if (!isalpha(source[i]))
        target[k][j] = '\0';
      i++;
      j++;
    }
    else
    {
      j = 0;
      i++;
      k++;
    }
  }
  return k+1;
}
