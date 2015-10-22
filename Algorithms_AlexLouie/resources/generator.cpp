#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <sstream>

using namespace std;

// returns proper filename for the program's output
string getFileName();

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
    cout << "Your selection:";
    cin >> mode;
    if (isalpha(mode))
      mode = tolower(mode);

    if (!(mode == 's' || mode == 'r' || mode == 'd')) {
      bool incorrect = true;
      do {
        cout << "That was a bad input! Please try again..." << endl;
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
      cout << "You have chosen \"Set Length\"" << endl;
      cout << "Please input how long you want each random string to be: ";
      cin >> range1;
      range1 = abs(range1);

      string filename = getFileName();
      ofstream outputFile;
      outputFile.open(filename);
      for (int i = 0; i < NUMSTRINGS; ++i) {
        output = "";
        for (int j = 0; j < range1; ++j) {
          char ltr = 'a' + rand()%26; // Makes a random character
          if (rand()%2) {
            ltr = toupper(ltr);
          }
          output += ltr ;
        }
        outputFile << output << endl;
      }
      outputFile.close();

      cout << "Finished set length output!" << endl;
    }
    else if (mode == 'r') {

    }
    else
      isFinished = true;
  }

  return 0;
}

string getFileName() {
  string filename = "greedy_";
  filename.append(to_string(time(0)));
  filename.append(".txt");
  return filename;
}