

//#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string> 
#include "DLinkedBag.cpp" //doubly linked list bag pwdp

using namespace std;

string getMatch(DLinkedBag<string>& dict,string sentText){ 
	
	string exaMatch = " "; // similar sentText
	int maxMatch = 0;

	vector<string> txtItems = dict.toVector();
	int dicEntries = (int)txtItems.size();

	for (int i = dicEntries - 1; i >= 0; i--)
	{
		string getResult = txtItems[i];
		int thisWSim = 0;
		//int name = 0;
		if (getResult == sentText)
		{
			exaMatch = getResult;
			break;
		}
		else
		for (int j = 0; j < sentText.length(); j++)
		{

			if (getResult.find_first_of(tolower(sentText[j]))<getResult.length()){
				
				if (maxMatch <= thisWSim)
				{
					maxMatch ++;
					exaMatch = getResult;
				}// update our exaMatch
				thisWSim++;
			} // find sentText
			
			//cout << sentText.length();
		} // end for


	} // end forreturn exaMatch;
}
int main()
{
	
	string nameOfFile, nameofDict = "dictionary.txt";
	bool dicT = false, usrSnt = false;


	DLinkedBag<string> dict,userSntc; 

	string items;
	ifstream mydicFile(nameofDict.c_str());
	if (mydicFile.is_open())
	{		
	if (mydicFile.is_open()) 
        {
		dicT = true;
		while (!mydicFile.eof()) 
                {
			mydicFile >> items;
			//cout << items<<endl;
			dict.add(items);
		}
	}
	mydicFile.close();
	}
	else cout << "Unable to open Dictionary.txt\n";
	
	cout << "Enter the name of the file that contains sentTexts to check: ";
	cin >> nameOfFile;
	
	ifstream myReadFile(nameOfFile.c_str());
	
        if (myReadFile.is_open())
	{
		if (myReadFile.is_open()) 
                {
			 usrSnt = true;
			while (!myReadFile.eof()) 
                        {
				myReadFile >> items;
				//cout << items << endl;
				userSntc.add(items);
			}
		}
		myReadFile.close();
	}
	else cout << "Unable to open" << nameOfFile<<"\n";

	if (dicT && usrSnt)
	{
                cout << endl;
		vector<string> userItems = userSntc.toVector();
		int userEntries = (int)userItems.size();
		cout << "The following sentTexts in the file" << nameOfFile << " are not spelled correctly: \n";
		
		for (int i = userEntries-1; i >= 0; i--)
		{
			string crctW = getMatch(dict, userItems[i]);
			
			 if (userItems[i]!=crctW)
			cout << userItems[i] << endl;
			
		} // end for
	
	}

	cout << endl;
	return 0;
}

