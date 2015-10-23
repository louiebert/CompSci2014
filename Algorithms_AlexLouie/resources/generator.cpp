// Author: Louie Bertoncin

#include <iostream>
#include <fstream>
#include <ctime>
#include <string>

using namespace std;

// Returns proper filename for the program's output
// Naming structure is as follows: <stringType>_(<length>)_<unix timestamp>
//    <stringType> is either "setLength" or "randLength"
//    <length> will be either the set length or the range of the length of the string
//    <unix timestamp> is the current epoch time of creating the file
string getFileName(char type, int range1, int range2 = 0);

// Returns a random string with set length
string setLengthString(int length);

// Returns a random string with a random length between range1 and range2
string randLengthString(int range1, int range2);

int main() {
  srand(time(NULL));

  bool isFinished = false;
  const int NUMSTRINGS = 100;
  char mode;
  int range1, range2;
  string output = "";

  while (!isFinished) {
    cout << "Welcome to random string generator!\n\n" << endl;
    cout << "Please select whether you want to create strings with a..." << endl;
    cout << "\tSet Length - s" << endl;
    cout << "\tor Random Length Within a Range - r\n" << endl;
    cout << "\tor you're Done with this program - d\n" << endl;
    cout << "Your selection: ";
    cin >> mode;
    if (isalpha(mode))
      mode = tolower(mode);

    if (!(mode == 's' || mode == 'r' || mode == 'd')) {
      bool incorrect = true;
      do {
        cout << "\n\nThat was a bad input! Please try again..." << endl;
        cout << "\tSet Length - s" << endl;
        cout << "\tor Random Length Within a Range - r\n" << endl;
        cout << "\tor you're Done with this program - d\n" << endl;
        cout << "Your selection:";
        cin >> mode;
        if (isalpha(mode))
          mode = tolower(mode);

        if (mode == 's' || mode == 'r' || mode == 'd')
          incorrect = false;
      } while (incorrect);
    }

    if (mode == 's') {
      cout << "\n\nYou have chosen \"Set Length\"" << endl;
      cout << "\nPlease input how long you want each random string to be: ";
      cin >> range1;
      range1 = abs(range1);

      string filename = getFileName(mode, range1);
      ofstream outputFile;
      outputFile.open(filename);
      for (int i = 0; i < NUMSTRINGS; ++i) {
        outputFile << setLengthString(range1) << endl;
      }
      outputFile.close();

      cout << "Finished set length output!" << endl;
    }
    else if (mode == 'r') {
      cout << "\n\nYou have chosen \"Random Length Within a Range\"" << endl;
      cout << "\nPlease input how small the bottom limit of the range should be: ";
      cin >> range1;
      range1 = abs(range1);

      cout << "\nCool! Now input how large the top limit of the range should be: ";
      cin >> range2;
      range2 = abs(range2);
      while (range2 < range1) {
        cout << "\n\nWhoa there! The higher range is smaller than the lower range!" << endl;
        cout << "\nPlease try again with the higher range (it must be larger than " << range1 << "): ";
        cin >> range2;
        range2 = abs(range2);
      }

      string filename = getFileName(mode, range1, range2);
      ofstream outputFile;
      outputFile.open(filename);

      for (int i = 0; i < NUMSTRINGS; ++i) {
        outputFile << randLengthString(range1, range2) << endl;
      }
      outputFile.close();

      cout << "Finished random length output!" << endl;
    }
    else
      isFinished = true;
  }

  return 0;
}

string getFileName(char type, int range1, int range2) {
  string filename = "";
  if (type == 's') {
    filename.append("setLength_(");
    filename.append(to_string(range1));
    filename.append(")_");
  } else {
    filename.append("randLength_(");
    filename.append(to_string(range1));
    filename.append("-");
    filename.append(to_string(range2));
    filename.append(")_");
  }
  filename.append(to_string(time(0)));
  filename.append(".txt");
  return filename;
}

string setLengthString(int length) {
  string output = "";
  for (int j = 0; j < length; ++j) {
    char ltr = 'a' + rand()%26; // Makes a random character
    if (rand()%2)
      ltr = toupper(ltr); // Randomizes capitalization
    output += ltr ;
  }
  return output;
}

string randLengthString(int range1, int range2) {
  int randLength = rand()%(range2 - range1 + 1) + range1;
  string output = "";
  for (int j = 0; j < randLength; ++j) {
    char ltr = 'a' + rand()%26; // Makes a random character
    if (rand()%2)
      ltr = toupper(ltr); // Randomizes capitalization
    output += ltr;
  }
  return output;
}