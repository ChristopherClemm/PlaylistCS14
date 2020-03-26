#include <iostream>
#include <string>
#include "Playlist.h"

Playlist::Playlist()
{
	head = nullptr;
	tail = nullptr;

}
void Playlist::PrintMenu(string t)
{


	cout << t << " PLAYLIST MENU"<< endl;
	cout << "a - Add song\nd - Remove song\nc - Change position of song\ns - Output songs by specific artist\n"
			"t - Output total time of playlist (in seconds)\no - Output full playlist\nq - Quit" << endl;
	cout << endl;
	cout << "Choose an option:" << endl;
}

void Playlist::InsertAfter()
{
	cout << "ADD SONG" << endl;
	cout << "Enter song's unique ID:" << endl;
	string id;
	cin >> id;
	cin.ignore();
	cout << "Enter song's name:" << endl;
	string sName;
	getline(cin, sName);
	cout << "Enter artist's name:" << endl;
	string aName;
	getline(cin, aName);
	cout << "Enter song's length (in seconds):" <<  endl;
	int sLength;
	cin >> sLength;
	cout << endl;

    PlaylistNode* temp = new PlaylistNode(id,sName,aName,sLength);


        if(head == nullptr)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->SetNext(temp);
            tail = temp;
        }
}

void Playlist::Change()
{
	int counter = 0;
	int currPos = 0;
	int newPos = 0;
	PlaylistNode* currSong = head;
	PlaylistNode* newLoc = head;
	PlaylistNode* previous = head;
	PlaylistNode* previous2 = head;

	/*
	PlaylistNode* counter1 = head;
	while(counter1 != nullptr) {
		++size;
		counter1 = counter1->GetNext();
	}
	*/

	cout << "CHANGE POSITION OF SONG" << endl;
	cout << "Enter song's current position:" << endl;
	cin >> currPos;
	cout << "Enter new position for song:" << endl;
	cin >> newPos;
	if (currPos > 0) {
		counter = 1;
		while(currSong && counter != currPos) {
			previous = currSong;
			currSong = currSong->GetNext();
			++counter;
		}
	}
	if(newPos > 0) {
		counter = 1;
		while(newLoc && counter != newPos) {
			previous2 = newLoc;
			newLoc = newLoc->GetNext();
			++counter;
		}
	}
	if(previous != previous2) {
		cout << "\"" << previous->GetSongName() << "\" moved to position " << newPos << endl << endl;

		if(currSong == head) {
			PlaylistNode* saveHead = currSong->GetNext();
			PlaylistNode* temp = newLoc->GetNext();

			currSong->SetNext(temp);
			newLoc->SetNext(previous);
			head = saveHead;
			if(!currSong->GetNext()) {
				tail = currSong;
			}
		}
		else if(currSong == tail) {
			if(newLoc != head) {
				currSong->SetNext(newLoc);
				previous2->SetNext(currSong);
				previous->SetNext(nullptr);
				tail = previous;
			}
			else {
				currSong->SetNext(previous2);
				previous->SetNext(nullptr);
				tail = previous;
				head = currSong;
			}
		}
		else if(newLoc == head) {
			if(newLoc != tail) {
				PlaylistNode* temp = currSong->GetNext();
				currSong->SetNext(newLoc);
				previous->SetNext(temp);
				head = currSong;
			}
			else {
				currSong->SetNext(previous2);
				previous->SetNext(nullptr);
				tail = previous;
				head = currSong;
			}
		}
		else if(newLoc == tail) {
			if(currSong != head) {
				previous->SetNext(currSong->GetNext());
				newLoc->SetNext(currSong);
				currSong->SetNext(nullptr);
				tail = currSong;
			}
			else {
				head = currSong->GetNext();
				newLoc->SetNext(currSong);
				currSong->SetNext(nullptr);
				tail = currSong;
			}
		}
		else if(currPos < newPos) {
			previous->SetNext(currSong->GetNext());
			currSong->SetNext(newLoc->GetNext());
			newLoc->SetNext(currSong);
		}
		else {
			previous->SetNext(currSong->GetNext());
			currSong->SetNext(newLoc);
			previous2->SetNext(currSong);
		}
	}
}




void Playlist::Display()
{
    PlaylistNode* temp = head;
     int i = 1;

     if ( head == nullptr)
     {
    	 cout << "Playlist is empty" << endl;
    	 cout << endl;
     }
     else
     {
    	 while( temp != tail)
    	 {
    		cout << i << "." << endl;
    		i++;
    		temp->PrintPlaylistNode();
			temp = temp->GetNext();
			cout << endl;

		}
		if(tail != nullptr)
		{
			cout << i << "." << endl;
			temp->PrintPlaylistNode();
			cout << endl;
		}
     }
}

void Playlist::Remove(string r)
{


	PlaylistNode* temp = head;
	//PlaylistNode * temp2 = head;

		if ( r == temp->GetID() )
		{
			PlaylistNode* temp2 = head->GetNext();
			cout << "\"" << temp->GetSongName() << "\"  removed" << endl;
			delete temp;
			//cout << "REMOVE" << endl;
			head = temp2;
			if(!temp2)
			{
				tail = nullptr;
			}
		}
		else
		{
			while(temp->GetNext() && temp->GetNext()->GetID() != r)
			{
				temp = temp->GetNext();
			}
			if(temp->GetNext()->GetID() == r)
			{
				cout << "\""<< temp->GetNext()->GetSongName() << "\"" << " removed." << endl << endl;
				PlaylistNode* temp2 = temp->GetNext()->GetNext();
				delete temp->GetNext();
				temp->SetNext(temp2);
			}
		}

}
void Playlist::TotalTime()
{
	int time = 0;

	PlaylistNode* temp = head;

	while( temp != nullptr)
	{
		time = time + temp->GetSongLength();
		temp = temp->GetNext();
	}
	cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl;
	cout << "Total time: " << time << " seconds" << endl;
	cout << endl;



}

void Playlist::OutputArt(string r)
{

	 PlaylistNode* temp = head;
	     int i = 1;
	     cout << endl;

	     if(head == nullptr)
	     {
	     				cout << "Playlist is empty" << endl << endl;
	     }
	     else
	     {
	    	 while( temp != nullptr)
	    	 {
	    		 if ( temp->GetArtistName() == r)
	    	    {
	    			 cout << i << "." << endl;

					temp->PrintPlaylistNode();

					cout << endl;
	    	    }
	    		 temp = temp->GetNext();
	    		 i++;

			}

	     }


}
PlaylistNode::PlaylistNode() {
	uniqueID = "none";
	songName = "none";
	artistName = "none";
	songLength = 0;
	next = nullptr;
}
PlaylistNode::PlaylistNode(string id, string song, string artist, int length) {
	uniqueID = id;
	songName = song;
	artistName = artist;
	songLength = length;
	next = nullptr;
}
void PlaylistNode::PrintPlaylistNode()
{
	cout << "Unique ID: " << this->uniqueID << endl;
	cout << "Song Name: " << this->songName << endl;
	cout << "Artist Name: " << this->artistName << endl;
	cout << "Song Length (in seconds): " << this->songLength << endl;

}
void PlaylistNode::InsertAfter(PlaylistNode* x) {
	x->next = this->next;
	this->next = x;
}

void PlaylistNode::SetNext(PlaylistNode* x) {
	this->next = x;
}

string PlaylistNode::GetID() {
	return this->uniqueID;
}

string PlaylistNode::GetSongName() {
	return this->songName;
}

string PlaylistNode::GetArtistName() {
	return this->artistName;
}

int PlaylistNode::GetSongLength() {
	return this->songLength;
}

PlaylistNode* PlaylistNode::GetNext() {
	return this->next;
}












