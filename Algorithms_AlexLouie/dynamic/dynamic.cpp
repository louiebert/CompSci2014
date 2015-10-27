//Author: Alex Shaw

#include <iostream> 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector> 
#include <math.h>
#include <fstream>
#include "dynamic.h"

using namespace std;

int main() 
{
	const int SIMILARITY_SCORE = 0.7;	//Sequences above this similarity score are stored
	const int NUM_REVIEWS_PER_BUCKET = 100; 	//Holds number of reviews in eahc set length and random length bucket

	vector<string> setLength;
	vector<string> randLength;

	vector<float> setLengthSimScores;
	vector<float> randLengthSimScores;
	vector<float> realInputSimScores;

	vector<float> setLengthExecTimes;
	vector<float> randLengthExecTimes;
	vector<float> realInputExecTimes;

	vector<int> setLengthSimReviews;
	vector<int> randLengthSimReviews;
	vector<int> realInputSimReviews;

	vector<float> setLengthSimScoreAverages;
	vector<float> randLengthSimScoreAverages;
	vector<float> realInputSimScoreAverages;

	vector<float> setLengthAverage

	vector<int> bucketBounds;

	vector<string> lcs;							//

	int averageSimScoresCounter = 0;
	int simScoreIndex = 0;
	int simReviewIndex = 0;
	int bucketBoundIndex = 0;
	int realSimScoreIndex = 0;
	int realSimReviewIndex = 0;
	int realBucketBoundIndex = 0;
	int realSimilarityScoreSum = 0;

	vector<float> realSimilarityScores;
	vector<int> realSimilarReviews;
	vector<int> realBucketBounds;

	int realAveragesCounter;

	vector<string> setLengthFiles;			//Holds names of output files with generated strings
	vector<string> randLengthFiles;
	vector<string> realInputFiles;
	//TODO: Create vector with hardcoded file names for set lengths
	//TODO: Create vector with hardcoded file names for random lengths
	//TODO: Figure out how to access file names for real input

	int lowerBound = 0;
	int upperBound = 99;

	ifstream readReviews;
	string review;

	srand(time(NULL));

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





	for(int i = 0; i < 10; ++i) 
	{

		int numReviews = 0;
		readReviews.open(setLengthFiles[i]);
		while(!readReviews.eof())
		{
			readReviews >> review;
			setLength.push_back(review);
			++numReviews;
		}
		readReviews.close();
	}


	for(int i = 0; i < 10; ++i)
	{
		int numReviews = 0;
		readReviews.open(randLengthFiles[i]);
		while(numReviews < 100) 
		{
			readReviews >> review;
			randLength.push_back(review);
			++numReviews;
		}
		readReviews.close();
	}

	int numReviewsCompared = 0;
	int lowerBound = 0;
	int upperBound = 99;

	while(upperBound <= setLength.size())
	{
		float similarityScoreSum = 0;
		float execTimeSum = 0;
		for(int i = lowerBound; i <= upperBound; ++i)
		{

			for(int j = i + 1; j <= upperBound; ++j)
			{
				float startTime = time(0);
				string lcs = Dynamic_Programming_LCS(setLength[i], setLength[j]);
				float endTime = time(0);
				int numLcsChars = lcs.size();
				int totalChars = fmin(setLength[i].length(), setLength[j].length());
				float similarityScore = static_cast<float>(numLcsChars) / totalChars;
				similarityScores.push_back(similarityScore);
				similarityScoreSum += similarityScore;
				float execTime = endTime - startTime;
				execTimeSum += execTime;
				//TODO: Test if there's any difference in start and end times
				//TODO: Test whether both numerator and denominator have to be static cast 
				if (similarityScore > SIMILARITY_SCORE)
				{
					setLengthSimilarReviews.push_back(i);
					setLengthSimilarReviews.push_back(j);
				}

			}


		}
		float averageSimScore = static_cast<float>(similarityScoreSum) / NUM_REVIEWS_PER_BUCKET;
		setLengthSimScoreAverages.push_back(averageSimScore);

		float averageExecTime = execTimeSum / NUM_REVIEWS_PER_BUCKET;
		setLengthExecTimes.push_back(averageExecTime);

		lowerBound = upperBound + 1;
		upperBound += 100;
	}

	//Calculate execution time and average similarity score for each random length bucket 
	numReviewsCompared = 0;
	lowerBound = 0;
	upperBound = 99;

	while(upperBound <= randLength.size())
	{
		float similarityScoreSum = 0;
		for(int i = lowerBound; i <= upperBound; ++i)
		{

			for(int j = i + 1; j <= upperBound; ++j)
			{
				float startTime = time(0);
				string lcs = Dynamic_Programming_LCS(setLength[i], setLength[j]);
				float endTime = time(0);
				int numLcsChars = lcs.size();
				int totalChars = fmin(setLength[i].length(), setLength[j].length());
				float similarityScore = static_cast<float>(numLcsChars) / totalChars;
				similarityScores.push_back(similarityScore);
				similarityScoreSum += similarityScore;
				float execTime = endTime - startTime;
				//TODO: Test whether both numerator and denominator have to be static cast 
				++numReviewsCompared;
				if (similarityScore > SIMILARITY_SCORE)
				{
					randLengthSimilarReviews.push_back(i);
					randLengthSimilarReviews.push_back(j);
				}
			}
		}
		float averageSimScore = static_cast<float>(similarityScoreSum) / NUM_REVIEWS_PER_BUCKET;
		randLengthSimScoreAverages.push_back(averageSimScore);
		
		float averageExecTime = execTimeSum / NUM_REVIEWS_PER_BUCKET;
		setLengthExecTimes.push_back(averageExecTime);

		bucketBounds.push_back(upperBound);
		lowerBound = upperBound + 1;
		upperBound += 100;
	}



	while()
	//TODO: Figure out how to iterate between vectors meant for real input.


}