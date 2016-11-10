#ifndef PLAYLIST_CPP
#define PLAYLIST_CPP

#include "Playlist.h"
#include <iostream>

using namespace std;



PlaylistNode::PlaylistNode(string initID, string initSongName, string initArtistName, int initSongLength, PlaylistNode* nextLoc) {
	this->uniqueID = initID;
	this->songName = initSongName;
	this->artistName = initArtistName;
	this->songLength = initSongLength;
	this->nextNodePtr = nextLoc;
	return;
}

void PlaylistNode::InsertAfter(PlaylistNode* nodeLoc) {
	PlaylistNode* tmpNext = 0;

	tmpNext = this->nextNodePtr;    // Remember next
	this->nextNodePtr = nodeLoc;    // this -- node -- ?
	nodeLoc->nextNodePtr = tmpNext; // this -- node -- next
	return;
}

void PlaylistNode::PrintPlaylistNode() {
	cout << "Unique ID: " << this->uniqueID << endl;
	cout << "Song Name: " << this->songName << endl;
	cout << "Artists Name: " << this->artistName << endl;
	cout << "Song Length: " << this->songLength << endl << endl;
	return;
}

void PlaylistNode::SetNext(PlaylistNode* nodePtr) {
	nextNodePtr = nodePtr;
}

PlaylistNode* PlaylistNode::GetNext() {
	return this->nextNodePtr;
}

string PlaylistNode::GetID() const {
	return this->uniqueID;
}

string PlaylistNode::GetSongName() const {
	return this->songName;
}

string PlaylistNode::GetArtistName() const {
	return this->artistName;
}

int PlaylistNode::GetSongLength() const {
	return this->songLength;
}

#endif
