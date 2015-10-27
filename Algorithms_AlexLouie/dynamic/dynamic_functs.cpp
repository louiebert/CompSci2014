string Dynamic_Programming_LCS(string review1, string review2) 
{
	string lcs = "";
	//TODO: Test if 2D vector is set up correctly
	vector<vector<int>> lcsTable;
		cout << "I've made it this far." << endl;
		for(int g = 0; g < review1.length() + 1; ++g)
		{
			
			cout << "I've made it this many times in the outer loop: " << g << endl;
			
			for(int h = 0; h < review2.length() + 1; ++h)
			{
				cout << "I'm inside the inner loop." << endl;
				
				cout << "g == 0: " << (g == 0) << endl;
				
				if(g == 0 || h == 0)
				{
					cout << "I'm inside the conditional statement" << endl;
					lcsTable[g].push_back(0);
					
				}
				
				
				else
				{
					if(review1.at(g + 1) == review2.at(h + 1))
					{
						lcsTable[g].push_back(1);
					}

					if(lcsTable[g - 1][h] > lcsTable[g][h] || lcsTable[g][h - 1] > lcsTable[g][h])
					{
						int maxVal = fmax(lcsTable[g - 1][h], lcsTable[g][h -1]);
						it = lcsTable[g].push_back(maxVal);
					
					}
				}
			}
		}

		int g = review2.length() + 1;
		for(int h = review1.length() + 1; h > 0; --h)
		{
			if(lcsTable[g][h - 1] < lcsTable[g][h])
			{
				lcs + review1.at(g);
				--g;
			}
		}
	return lcs;	
}