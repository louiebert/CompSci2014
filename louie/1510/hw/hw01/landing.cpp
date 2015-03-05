//Programmer: LOUIE BERTONCIN     Date: 2/8/2015
//File: Landing Zone              Class: CS 1510, Section C
//Purpose: Finding the most environmentally friendly spaceship landing spot.

#include <iostream>
using namespace std;

const int LANDINGWIDTH = 3;
const int LANDINGLENGTH = 3;
const int LANDINGINFOSIZE = 3;
const int NUMDEADFLOWERSINDEX = 0;
const int XCOORDINDEX = 1;
const int YCOORDINDEX = 2;

int main()
{
  int numOfMaps, rows, columns;

  // cout << "The Planet Express crew is landing a ship and needs your help!""
  //   << endl;
  // cout << "Please enter how many grids are on the landscape: ";
  cin >> numOfMaps;
  // cout << endl;

  int ***grids = new int**[numOfMaps];
  int **landingInfo = new int*[numOfMaps];

  for (int i = 0; i < numOfMaps; ++i)
  {
    do
    {
      // cout << "Please enter how many columns (>= " << LANDINGWIDTH <<
      // ") and rows (>= " << LANDINGLENGTH << ") this grid has: ";
      cin >> columns;
      cin >> rows;
    } while (columns < LANDINGWIDTH || rows < LANDINGLENGTH);

    // cout << endl;

    grids[i] = new int*[columns];
    for (int j = 0; j < rows; ++j)
    {
      grids[i][j] = new int[rows];
      // cout << "Now enter how many flowers are in each spot in row " << j + 1 <<
      // "!"\t(There are " << columns << " spots in this row): ";
      for (int k = 0; k < columns; ++k)
      {
        cin >> grids[i][j][k];
      }
    }


    // cout << endl << "Map " << i + 1 << ":" << endl;
    // for (int j = 0; j < rows; ++j)
    // {
    //   cout << "\t";
    //   for (int k = 0; k < columns; ++k)
    //   {
    //     cout << grids[i][j][k] << " ";
    //   }
    //   cout << endl;
    // }

    int lowTotal = 0, xCoord = 0, yCoord = 0;

    for (int j = 0; j < rows - (LANDINGLENGTH - 1); ++j)
    {
      for (int k = 0; k < columns - (LANDINGWIDTH - 1); ++k)
      {
        int total = 0;
        for (int l = 0; l < LANDINGLENGTH; ++l)
        {
          for (int m = 0; m < LANDINGWIDTH; ++m)
          {
            total += grids[i][j+l][k+m];
          }
        }
        if (j == 0 && k == 0)
        {
          lowTotal = total;
          xCoord = k;
          yCoord = j;
        }
        if (total < lowTotal)
        {
          lowTotal = total;
          xCoord = k;
          yCoord = j;
        }
      }
    }

    for (int j = 0; j < rows; ++j)
    {
      delete [] grids[i][j];
      grids[i][j] = NULL;
    }

    landingInfo[i] = new int[LANDINGINFOSIZE];
    landingInfo[i][NUMDEADFLOWERSINDEX] = lowTotal;
    landingInfo[i][XCOORDINDEX] = xCoord;
    landingInfo[i][YCOORDINDEX] = yCoord;

    // cout << endl << endl;
  }

  for (int i = 0; i < numOfMaps; ++i)
  {
    // cout << "The best place in map " << i + 1 << " to land is (" <<
    //   landingInfo[i][XCOORDINDEX] << "," << landingInfo[i][YCOORDINDEX] <<
    //   "), landing on " << landingInfo[i][NUMDEADFLOWERSINDEX] << " flowers."
    //   << endl;
    cout << "#" << i << ": (" << landingInfo[i][XCOORDINDEX] << ", " <<
      landingInfo[i][YCOORDINDEX] << ") " << landingInfo[i][NUMDEADFLOWERSINDEX]
      << endl;
  }

  for (int i = 0; i < numOfMaps; ++i)
  {
    delete [] grids[i];
    grids[i] = NULL;
    delete [] landingInfo[i];
    landingInfo[i] = NULL;
  }
  delete [] grids;
  grids = NULL;
  delete [] landingInfo;
  landingInfo = NULL;

  return 0;
}