/*
Author: Schmiechen, James
Group members: Lastname, Firstname; Lastname, Firstname; Lastname, Firstname;
Assignment: Programming Assignment Two
Course: COMP B12
Instructor: Richard Miles
Date submitted: 2106/09/??
*/

// This program allows coaches to maintain a small roster of players.

#include <iostream>
#include <vector>
using namespace std;

int menuFunction() {	// Outputs menu
	cout << endl << "MENU" << endl << "a - Add player" << endl << "d - Remove player" << endl << "u - update player rating" << endl << "r - Output players above a rating" << endl << "o - Output roster" << endl << "q - Quit" << endl;
	cout << endl << endl << "Choose an option: ";
	return 0;
}

int main() {
	vector<int> jersey, rating;
	vector<char> menuList;
	int jerseyNum = 0, ratingNum = 0;
	char menuChoice;

	cout << "Enter the jersey numbers (0 - 99) and ratings (1 - 9) for five players." << endl;	// Prompt

	for (int i = 1; i <= 5; i++) {
		do		// Repeats current iteration to allow correction
		{
			cout << "Enter player " << i << "'s jersey number: ";	// Collects input
			cin >> jerseyNum;
			if (jerseyNum > 99 || jerseyNum < 0) {
				cout << jerseyNum << " is an invalid value. Please try again. (0 - 99)" << endl;
			}
		} while (jerseyNum > 99 || jerseyNum < 0);

		do
		{
			cout << endl << "Enter player " << i << "'s rating: ";
			cin >> ratingNum;
			if (ratingNum < 1 || ratingNum > 9) {
				cout << ratingNum << " is an invalid value. Please try again. (1 - 9)" << endl;
			}
		} while ((ratingNum < 1 || ratingNum > 9));

		jersey.push_back(jerseyNum);	// Adds input to end of vectors
		rating.push_back(ratingNum);
		cout << endl;
	}
	do
	{
		menuFunction();
		cin >> menuChoice;
		switch (menuChoice) {
		case 'a': // Add player
			do
			{
				cout << "Enter a new player's jersey number: ";
				cin >> jerseyNum;
				if (jerseyNum > 99 || jerseyNum < 0) {
					cout << jerseyNum << " is an invalid value. Please try again. (0 - 99)" << endl;
				}
				for (int i = 0; i < 5; i++) {
					if (jerseyNum == jersey.at(i)) {
						cout << jerseyNum << " is already being used. Please enter a new number." << endl;
					}
				}
			} while ((jerseyNum > 99 || jerseyNum < 0));
			do
			{
				cout << "Enter the player's rating: ";
				cin >> ratingNum;
				if (ratingNum < 1 || ratingNum > 9) {
					cout << ratingNum << " is an invalid value. Please try again. (1 - 9)" << endl;
				}
			} while ((ratingNum < 1 || ratingNum > 9));

			jersey.push_back(jerseyNum);	// Adds input to end of vectors
			rating.push_back(ratingNum);
			break;

		case 'd': // Remove player
			cout << "Enter a jersey number: ";
			cin >> jerseyNum;
			for (int i = 0; i <= 5; i++) {
				if (jersey.at(i) == jerseyNum) {
					jersey.erase(jersey.begin() + i);
					rating.erase(rating.begin() + i);
					break;
				}
				else { continue; }
			}
			break;

		case 'r': // Output players above a rating
			do
			{
				cout << "Enter a rating: ";
				cin >> ratingNum;
				if (ratingNum < 1 || ratingNum > 9) {
					cout << ratingNum << " is an invalid value. Please try again. (1 - 9)" << endl;
				}
			} while ((ratingNum < 1 || ratingNum > 9));

			cout << endl << endl << "ABOVE " << ratingNum << endl << endl;
			for (int i = 0, n = 1; i < 5; i++, n++) {
				if (rating.at(i) > ratingNum) {
					cout << "Player " << n << " -- Jeresy number: " << jersey.at(i) << ", rating: " << rating.at(i) << endl;
				}
			}
			break;

		case 'u': // Update player rating
			do
			{
				cout << "Enter a jersey number: ";
				cin >> jerseyNum;
				if (find(jersey.begin(), jersey.end(), jerseyNum) == jersey.end())
					cout << jerseyNum << " is not part of the roster. Please try again." << endl;
			} while (find(jersey.begin(), jersey.end(), jerseyNum) == jersey.end());
			do
			{
				cout << "Enter a new rating for player: ";
				cin >> ratingNum;
				if (ratingNum < 1 || ratingNum > 9) {
					cout << ratingNum << " is an invalid value. Please try again. (1 - 9)" << endl;
				}
			} while ((ratingNum < 1 || ratingNum > 9));

			for (int i = 0; i <= 5; i++) {
				if (jerseyNum == jersey.at(i)) {
					rating.at(i) = ratingNum;
					break;
				}
			}
			break;

		case 'o': // Output roster
				for (int i = 0; i < 5; i++) {
					cout << "Player " << i + 1 << " -- Jersey number: " << jersey.at(i) << ", Rating: " << rating.at(i) << endl;
				}
				break;

		case 'q': // Quit
			break;

		default:
			cout << "That is not a menu choice. Please try again." << endl;
		}
	} while (menuChoice != 'q');
}
