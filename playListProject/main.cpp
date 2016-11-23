#include "Playlist.h"
#include <iostream>
using namespace std;

void printMenu(string& playListTitle) {
	cout << endl << playListTitle << " PLAYLIST MENU" << endl;
	cout << "A - Add song" << endl;
	cout << "D - Remove song" << endl;
	cout << "C - Change position of song" << endl;
	cout << "S - Output songs by specific artist" << endl;
	cout << "T - Output total time of playlist (in seconds)" << endl;
	cout << "O - Output full playlist" << endl;
	cout << "Q - Quit" << endl << endl;

	cout << "Choose an option: ";
}

void printPlayList(PlaylistNode* &currObj, PlaylistNode* &headObj) {
	currObj = headObj;
	while (currObj != 0) {
		currObj->PrintPlaylistNode();
		currObj = currObj->GetNext();
	}
}

void checkID(string UID, PlaylistNode* currObj, PlaylistNode* headObj) {
    for(currObj = headObj; currObj != NULL; currObj = currObj->GetNext()) { 
     
		if(currObj->GetID() == UID ){

	    	while(headObj->GetID() == UID || currObj->GetID() == UID) {
	    		
		    	cout << "The ID " << UID << " is not unique" << endl;
		    	cout << "Enter song's unique ID: ";
		     	cin >> UID;
		     	currObj = headObj;
            }
        }
    }
}       
void addSong(int &songCount,  string UID, string songNam, string artistNam, int length, PlaylistNode* tailObj, PlaylistNode* headObj, PlaylistNode* currObj) {   
	cout << "ADD SONG" << endl;
	cout << "Enter song's unique ID: ";
	cin >> UID;
	
    checkID(UID, currObj, headObj);
        
	cout << "Enter song's name: ";
	cin >> songNam;
	cout << "Enter artist's name: ";
	cin >> artistNam;
	cout << "Enter song's length (in seconds) ";
	cin >> length;

	PlaylistNode* temp = 0;
	temp = new PlaylistNode(UID, songNam, artistNam, length);

	if (tailObj == headObj) {
		headObj = temp;
	}
	else {
		tailObj->SetNext(temp);
		tailObj->InsertAfter(tailObj);
		tailObj = temp;
	}
	songCount++;
}

void songsByArtist(PlaylistNode* &head, PlaylistNode* &curr) {
	
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	
	bool flag = true;
	string name = " ";
	cout << "OUTPUT SONGS BY SPECIFIC ARTIST" << endl;
	cout << "Enter artist's name: ";
	getline(cin, name);
	curr = head;
	
	while (flag) {
		if(curr->GetArtistName() == name){
			curr->PrintPlaylistNode();
			flag = false;
		}
		if(curr->GetArtistName() != name && curr->GetNext() == NULL){
			cout << "Artist was not found." << endl;
			flag = false;
		}
		curr = curr->GetNext();
	}
}

void totalTime(PlaylistNode* head, PlaylistNode* curr) {
	
	int songLength = 0;
	
	for (curr = head; curr !=NULL; curr = curr->GetNext()) {
    	songLength += curr->GetSongLength();
	}
	cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl;
  	cout << "Total time: " << songLength << " seconds"<< endl;
} 

void removeSong(int &songCount, PlaylistNode* currObj, PlaylistNode* headObj) {
	string songID = "", option = "";
	PlaylistNode* follower = headObj;
	bool flag = true;

	cout << "Enter song's unique ID: ";
	cin >> songID;
	
	currObj = headObj;

	while (flag) {
		follower = currObj;
		currObj = currObj->GetNext();

		if (currObj->GetID() == songID) {
                             
            cout << "Are you sure you want to delete " << currObj->GetSongName() << "?" << endl;
            cout << "Enter Y or N" << endl;
            cin >> option;
            
            if (option == "Y" || option == "y") {
			   follower->SetNext(currObj->GetNext());
			   cout << currObj->GetSongName() << " removed" << endl;
			   delete currObj;
			   flag = false;
            }
            else {
            break;
            }

			currObj = headObj;
		}
	}
	songCount--;
}

void changePos(int &songCount, PlaylistNode* &currObj, PlaylistNode* &headObj) {
	int currPos, newPos, i = 0;
	bool foundCurr = false, foundNew = false;
	PlaylistNode* tempCurrObj = 0, *tempNewObj = 0, *follower = 0, *temp = 0, *tempHead = headObj;

	cout << "CHANGE POSITION OF SONG" << endl;
	cout << "Enter song's current position: ";
	cin >> currPos;
	cout << "Enter new position for song: ";
	cin >> newPos;

	currObj = headObj;

	while (!(foundCurr && foundNew)) {
		currObj = currObj->GetNext(); // what if you cant find the value?
		headObj = headObj->GetNext();
		if (i == currPos - 1) {
			tempCurrObj = currObj; //object to switch
			foundCurr = true;
			tempCurrObj->PrintPlaylistNode();
		}
		if (i == newPos - 1) {
			tempNewObj = headObj;
			foundNew = true;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
			tempNewObj->PrintPlaylistNode();
		}
		i++;
	}
	headObj = tempHead;
	if (tempNewObj->GetNext() == NULL) {
		headObj->SetNext(tempNewObj);
		tempNewObj->SetNext(tempCurrObj->GetNext());
		temp = tempCurrObj->GetNext();
		temp->SetNext(tempCurrObj);
		tempCurrObj->SetNext(NULL);
	}
	else if (tempCurrObj->GetNext() == NULL) {
		headObj->SetNext(tempCurrObj);
		tempCurrObj->SetNext(tempNewObj->GetNext());
		temp = tempNewObj->GetNext();
		temp->SetNext(tempNewObj);
		tempNewObj->SetNext(NULL);
	}
	if (tempCurrObj == headObj) {
		headObj = tempCurrObj;
		tempNewObj->SetNext(tempCurrObj->GetNext());
		tempCurrObj->SetNext(tempNewObj);
	}
}

int main() {
	string menuChoice, ID, songName2, artistName2, playListTitle;
	int songLength2 = 0, songCount = 4;

	cout << "Enter playlist's title: ";
	cin >> playListTitle;

	PlaylistNode* headObj = 0; // Create node objects
	PlaylistNode* nodeObj1 = 0;
	PlaylistNode* nodeObj2 = 0;
	PlaylistNode* nodeObj3 = 0;
	PlaylistNode* currObj = 0;
	PlaylistNode* tailObj = headObj;

	// Front of nodes list
	headObj = new PlaylistNode("33", "Booky", "Snoop", 100, nodeObj1);

	// Insert nodes
	nodeObj1 = new PlaylistNode("22", "Bakky", "Fifty Cent", 200, nodeObj2);
	headObj->InsertAfter(nodeObj1);

	nodeObj2 = new PlaylistNode("11", "Bobby", "Ice Cube", 300, nodeObj3);
	nodeObj1->InsertAfter(nodeObj2);

	nodeObj3 = new PlaylistNode("00", "Babby", "Drake", 400);
	nodeObj2->InsertAfter(nodeObj3);
	tailObj = nodeObj3;

	do {
		printMenu(playListTitle);
		cin >> menuChoice;

		switch (menuChoice[0]) {
			case 'A':
			case 'a':
				addSong(songCount, ID, songName2, artistName2, songLength2, tailObj, headObj, currObj);
				break;
			case 'D':
			case 'd':
				removeSong(songCount, currObj, headObj);
				break;
			case 'O':
			case 'o':
				printPlayList(currObj, headObj);
				break;
			case 'C':
			case 'c':
				changePos(songCount, currObj, headObj);
				break;
			case 'S':
            case 's':
                 songsByArtist(headObj, currObj);
                 break;
            case 'T':
            case 't':
                 totalTime(headObj, currObj);
                 break;
			default:
				cout << menuChoice << " is not a menu option.";
		}
	} while (menuChoice != "Q" || menuChoice != "q");

	return 0;
	}
