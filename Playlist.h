#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <iostream>
#include <string>

using namespace std;
class PlaylistNode {
	public:
		PlaylistNode();
		PlaylistNode(string, string, string, int);
		void InsertAfter(PlaylistNode*); //(1 pt)
		void SetNext(PlaylistNode*); //- Mutator (1 pt)
		string GetID(); //- Accessor
		string GetSongName(); //- Accessor
		string GetArtistName(); //- Accessor
		int GetSongLength(); //- Accessor
		PlaylistNode* GetNext(); //- Accessor
		void PrintPlaylistNode();

	private:
		string uniqueID;
		string songName;
		string artistName;
		int songLength;
		PlaylistNode* next;
};


class Playlist
{
private:
	PlaylistNode *head;
	PlaylistNode *tail;
 public:
	Playlist();
	void PrintMenu(string);
	void Display() ;
	void Remove(string);
	void TotalTime();
	void OutputArt(string);
	void InsertAfter();
	void Change();



};



#endif


