// Algorithms Project 1, Greedy Algorithms
// Author: Louie Bertoncin

// setLength_(100)_1445904975.txt

#include <iostream>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <climits>
#include <ctime>
#include <chrono>
#include <algorithm>

using namespace std;

int getdir (string dir, vector<string> &files);

float greedyLCS(string rv1, string rv2);

int main() {
  vector<string> reviews;
  vector< vector<float> > resultSVs;
  ifstream in;
  ofstream out;
  string filename;
  vector<string> files = vector<string>();
  string review;
  char selection;

  typedef std::chrono::high_resolution_clock Clock;
  typedef std::chrono::milliseconds milliseconds;

  cout << "Would you like to use one specific file or all \'.txt\' files in the directory?" << endl;
  cout << "\tSpecific: s" << endl;
  cout << "\tAll: a" << endl;
  cout << "Your selection: ";
  cin >> selection;
  if (isalpha(selection))
    selection = tolower(selection);

  if (!(selection == 's' || selection == 'a')) {
    bool incorrect = true;
    do {
      cout << "\n\nThat was a bad input! Please try again..." << endl;
      cout << "\tSpecific: s" << endl;
      cout << "\tAll: a" << endl;
      cout << "Your selection: ";
      cin >> selection;
      if (isalpha(selection))
        selection = tolower(selection);

      if (selection == 's' || selection == 'a')
        incorrect = false;
    } while (incorrect);
  }

  if (selection == 's') {
    cout << "Please type in the file name to examine: ";
    getline(cin, filename, '\n');

    in.open(filename);
    while (in >> review) {
      reviews.push_back(review);
    }
    in.close();
  } else {
    string dir = ".";
    getdir(dir, files);

    for (unsigned int i = 0; i < files.size(); ++i) {
      if (files[i].size() > 4 && files[i].substr(files[i].size() - 4, 4) == ".txt") {
        in.open(files[i]);
        in >> review;
        reviews.push_back(review);
        in.close();
      }
    }
  }
  cout << endl;

  int zeroes = 0, ones = 0, twos = 0, threes = 0, fours = 0, fives = 0, sixes = 0, sevens = 0, eights = 0, nines = 0, tens = 0;

  Clock::time_point t0 = Clock::now();
  for (int i = 0; i < reviews.size(); ++i) {
    for (int j = i+1; j < reviews.size(); ++j) {
      float sv = greedyLCS(reviews[i], reviews[j]);
      vector<float> tempRes;
      tempRes.push_back(sv);
      tempRes.push_back(i);
      tempRes.push_back(j);
      if (sv >= 0 && sv < 0.1)
        zeroes++;
      if (sv >= 0.1 && sv < 0.2)
        ones++;
      if (sv >= 0.2 && sv < 0.3)
        twos++;
      if (sv >= 0.3 && sv < 0.4)
        threes++;
      if (sv >= 0.4 && sv < 0.5)
        fours++;
      if (sv >= 0.5 && sv < 0.6)
        fives++;
      if (sv >= 0.6 && sv < 0.7)
        sixes++;
      if (sv >= 0.7 && sv < 0.8)
        sevens++;
      if (sv >= 0.8 && sv < 0.9)
        eights++;
      if (sv >= 0.9 && sv < 1.0)
        nines++;
      if (sv >= 1.0)
        tens++;

      if (sv > 0.7)
        resultSVs.push_back(tempRes);
    }
  }
  Clock::time_point t1 = Clock::now();
  milliseconds ms = std::chrono::duration_cast<milliseconds>(t1-t0);
  cout << "Computation took " << ms.count() << " milliseconds" << endl;
  cout << "SV Scores:" << endl;
  cout << "\t0.0: " << zeroes << endl;
  cout << "\t0.1: " << ones << endl;
  cout << "\t0.2: " << twos << endl;
  cout << "\t0.3: " << threes << endl;
  cout << "\t0.4: " << fours << endl;
  cout << "\t0.5: " << fives << endl;
  cout << "\t0.6: " << sixes << endl;
  cout << "\t0.7: " << sevens << endl;
  cout << "\t0.8: " << eights << endl;
  cout << "\t0.9: " << nines << endl;
  cout << "\t1.0: " << tens << endl;
  cout << "There were " << resultSVs.size() << " pairs over a 0.7 score" << endl;

  return 0;
}

int getdir (string dir, vector<string> &files)
{
    DIR *dp;
    struct dirent *dirp;
    if((dp  = opendir(dir.c_str())) == NULL) {
        cout << "Error(" << errno << ") opening " << dir << endl;
        return errno;
    }

    while ((dirp = readdir(dp)) != NULL) {
        files.push_back(string(dirp->d_name));
    }
    closedir(dp);
    return 0;
}

float greedyLCS(string rv1, string rv2) {
  map< char, vector<int> > locs;
  for (int i  = 0; i < rv1.length(); ++i) {
    for (int j = 0; j < rv2.length(); ++j) {
      if (rv1[i] == rv2[j]) {
        if (locs.count(rv1[i]) > 0) { // Does that char element exist?
          if ((find(locs[rv1[i]].begin(), locs[rv1[i]].end(), j) != locs[rv1[i]].end()) && locs[rv1[i]].back() != j) { // Check logic
            locs[rv1[i]].push_back(j);
          }
        } else {
          vector<int> temp;
          temp.push_back(j);
          locs.insert(pair< char, vector<int> >(rv1[i], temp));
        }
      }
    }
  }

  vector<int> poses;
  int last = 0;
  int i = 0, j = 0;
  bool found1 = false;
  while (!found1 && i < rv1.length()) {
    if (locs.count(rv1[i]) > 0)
      found1 = true;
    else
      ++i;
  }
  int early1;
  if (i < rv1.length())
    early1 = locs[rv1[i]][0];

  // locs[rv1[i]].erase(locs[rv1[i]].begin());
  // if (locs[rv1[i]].length() == 0)
  //   locs.erase(rv1[i]);

  while (i < rv1.length()) {
    bool found2 = false;
    j = i+1;
    while (!found2 && j < rv1.length()) {
      if (locs.count(rv1[j]) > 0)
        found2 = true;
      else
        ++j;
    }
    int early2;
    if (j < rv1.length()) {
      early2 = locs[rv1[j]][0];
      locs[rv1[j]].erase(locs[rv1[j]].begin());
      if (locs[rv1[j]].size() == 0) {
        locs.erase(rv1[j]);
      }
      if (early2 < last) {
        last = INT_MAX;
      }
      if (early1 > early2) {
        poses.push_back(early2);
        last = early2;
        ++i;
        found1 = false;
        while (!found1 && i < rv1.length()) {
          if (locs.count(rv1[i]) > 0)
            found1 = true;
          else
            ++i;
        }
        if (i < rv1.length()) {
          early1 = locs[rv1[i]][0];
          locs[rv1[i]].erase(locs[rv1[i]].begin());
          if (locs[rv1[i]].size() == 0)
            locs.erase(rv1[i]);
        }
      } else {
        poses.push_back(early1);
        last = early1;
        early1 = early2;
      }
    } else {
      poses.push_back(early1);
      i = rv1.length();
    }
  }
  string result = "";
  for (int k = 0; k < poses.size(); ++k) {
    result += rv2[poses[k]];
  }
  return static_cast<float>(result.size())/min(rv1.length(), rv2.length());
}
