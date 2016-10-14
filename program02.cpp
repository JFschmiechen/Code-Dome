/*
Author: Schmiechen, James
Group members: Saleh, Zainab; Sherlock, Alec; Lastname, Firstname;
Assignment: Programming Assignment Two
Course: COMP B12
Instructor: Richard Miles
Date submitted: 2016/12/10
*/

/*
	TODO:
	-Code might be over commented
	-Fix bad input ( case 'u', 
*/

#include <iostream>
#include <vector>
#include <sstream> // Allows cin to read strings

using namespace std;

void badJersey(int x) { // Checks for jersey # not between 0 and 99

	if (x > 99 || x < 0) { // || == or
		cout << x << " is an invalid value. Please try again. (0 - 99)" << endl;
		
	}
}

void badRating(int y) { // Checks for rating # not between 1 and 9

	if (y < 1 || y > 9) {
		cout << y << " is an invalid value. Please try again. (1 - 9)" << endl;
		
	}
}

int menuFunction() {	// Outputs menu
	cout << endl << "MENU" << endl;
	cout << "a - Add player" << endl;
	cout << "d - Remove player" << endl;
	cout << "u - update player rating" << endl;
	cout << "r - Output players above a rating" << endl;
	cout << "o - Output roster" << endl;
	cout << "q - Quit" << endl;
	cout << endl << endl << "Choose an option: ";
	return 0;
}

int main() {
	vector<int> jersey, rating;
	int jerseyNum = 0, ratingNum = 0, playCount = 5;
	string temp;
	

	cout << "Enter the jersey numbers (0 - 99) and ratings (1 - 9) for five players." << endl;	// Prompt

	for (int i = 1; i <= playCount; i++) {
		do		
		{

			cout << "Enter player " << i << "'s jersey number: ";	// Collects input and passes it to badJersey
			cin >> jerseyNum;
			badJersey(jerseyNum); // Checks for # not betwenn 0 and 99

		} while (jerseyNum > 99 || jerseyNum < 0);	// Repeats current iteration to allow correction

		do
		{

			cout << endl << "Enter player " << i << "'s rating: ";
			cin >> ratingNum;
			badRating(ratingNum);

		} while (ratingNum < 1 || ratingNum > 9);

		jersey.push_back(jerseyNum);	// Adds input to end of vectors
		rating.push_back(ratingNum);
		cout << endl;
	}

	do
	{

		menuFunction();	// Prints menu
		cin >> temp;
		switch (temp[0]) {	// Uses first letter of input as choice

		case 'a': // Add player

				do
				{

					cout << "Enter a new player's jersey number: ";
					if (!(cin >> jerseyNum)) {
						cin.clear();
						cout << "Please enter a numeric value." << endl;
						break;
					}
					
					badJersey(jerseyNum); // Checks for # not between 0 and 99
					
					for (int i = 0; i < playCount; i++) {

						if (jerseyNum == jersey.at(i)) { // Checks roster for matching jerseyNum
							cout << jerseyNum << " is already being used. Please enter a new number." << endl;
							break;

						}
					}
					
				} while ((find(jersey.begin(), jersey.end(), jerseyNum) != jersey.end()) || (jerseyNum > 99 || jerseyNum < 0));
						// find returns true if it can find jerseyNum in jersey, if true the loop repeats.
				do
				{
					 
					cout << "Enter the player's rating: ";
					cin >> ratingNum;
					badRating(ratingNum); // Checks for # not between 1 and 9

				} while (ratingNum < 1 || ratingNum > 9);

				jersey.push_back(jerseyNum);	// Adds input to end of vectors
				rating.push_back(ratingNum);
				playCount++;	// Allows player roster to grow
				break;

		case 'd': // Remove player 

					cout << "Enter a jersey number: ";
					cin >> jerseyNum;
					badJersey(jerseyNum);

					for (int i = 0; i < playCount; i++) {

							if (jersey.at(i) == jerseyNum) {
								jersey.erase(jersey.begin() + i);	// Removes the value at index i
								rating.erase(rating.begin() + i);
								playCount--;
								break;
							
							}
							else if ((find(jersey.begin(), jersey.end(), jerseyNum) == jersey.end()) && (jerseyNum < 99 && jerseyNum > 0)) {
								cout << jerseyNum << " is not on the roster. Please try a different number." << endl;
								break;	// Specific error return if it can not find jerseyNum in jersey, but it is still a valid Jersey #
							}
					}
					
					break;

		case 'r': // Output players above a rating

				do
				{

					cout << "Enter a rating: ";
					cin >> ratingNum;
					badRating(ratingNum);	// Checks for # not between 1 and 9

				} while (ratingNum < 1 || ratingNum > 9);


				cout << endl << endl << "ABOVE " << ratingNum << endl << endl;

				for (int i = 0, n = 1; i < playCount; i++, n++) { // Searches vector for values higher than ratingNum
					if (rating.at(i) > ratingNum) {		  // n keeps track of player #, and i connects ratingNum and jerseyNum

						cout << "Player " << n << " -- Jersey number: " << jersey.at(i) << ", rating: " << rating.at(i) << endl;
					}
				}

				break;

		case 'u': // Update player rating

				do
				{

					cout << "Enter a jersey number: ";
					cin >> jerseyNum;

					if (find(jersey.begin(), jersey.end(), jerseyNum) == jersey.end())	// Searches the whole vector for jerseyNum

						cout << jerseyNum << " is not part of the roster. Please try again." << endl; // Error if it cant find jerseyNum

				} while (find(jersey.begin(), jersey.end(), jerseyNum) == jersey.end());	// Repeat while it cant find jerseyNum
				do
				{

					cout << "Enter a new rating for player: ";
					cin >> ratingNum;
					badRating(ratingNum);	// Checks for # not between 1 and 9

				} while (ratingNum < 1 || ratingNum > 9);

				for (int i = 0; i <= playCount; i++) {
					if (jerseyNum == jersey.at(i)) { // Searches for index of jerseyNum, and uses that same index to update rating
						rating.at(i) = ratingNum;
						break;
					}
				}

				break;

		case 'o': // Output roster

				for (int i = 0; i < playCount; i++) {
					cout << "Player " << i + 1 << " -- Jersey number: " << jersey.at(i) << ", Rating: " << rating.at(i) << endl;
				}
				break;

		case 'q': // Quit

				exit(0);

		default:

				cout << temp << " is not a menu choice. Please try again." << endl;	// Error if input is not a menu choice

			}
		} while (temp[0] != 'q');	// Repeats the switch until you want to quit
	}