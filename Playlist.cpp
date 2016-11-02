
#include <iostream>
using namespace std;

#include "Playlist.h"
// Constructor
PlaylistNode::PlaylistNode(string initID, string initSongName,  string initArtistName, int initSongLength,  PlaylistNode* nextLoc) {
   this->uniqueID = initID;
   this->songName = initSongName;
   this->artistName = initArtistName;
   this->songLength = initSongLength;
   this->nextNodePtr = nextLoc;
   return;
}

/* Insert node after this node.
 * Before: this -- next
 * After:  this -- node -- next
 */
void PlaylistNode::InsertAfter(PlaylistNode* nodeLoc) {
   PlaylistNode* tmpNext = 0;
   
   tmpNext = this->nextNodePtr;    // Remember next
   this->nextNodePtr = nodeLoc;    // this -- node -- ?
   nodeLoc->nextNodePtr = tmpNext; // this -- node -- next
   return;
}

// Print Node Data
void PlaylistNode::PrintPlaylistNode() {
   cout << "Unique ID: " << this->uniqueID << endl;
   cout << "Song Name: " << this->songName << endl;
   cout << "Artists Name: " << this->artistName << endl;
   cout << "Song Length: " << this->songLength << endl << endl;
   return;
}

//void PlaylistNode::SetNext(PlaylistNode* nodePtr) {
     

// Grab location pointed by nextNodePtr
PlaylistNode* PlaylistNode::GetNext() {
   return this->nextNodePtr;
}


                 


