
#include "Playlist.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{

	cout << "Enter playlist's title:" << endl;
    cout << endl;
	string title  = "";

	getline(cin, title);
	Playlist a ;

	char in = 'i';

	while (in != 'q')
	{
		a.PrintMenu(title);
		cin >> in;
		if (in == 'a')
		{
			a.InsertAfter();
		}
		else if (in == 'd')
		{
			cout << "REMOVE SONG\nEnter song's unique ID:" << endl;
			string j;
			cin >> j;
			a.Remove(j);

		}
		else if (in == 'c')
		{

			a.Change();
		}
		else if (in == 's')
		{
			cout << "OUTPUT SONGS BY SPECIFIC ARTIST\nEnter artist's name:" << endl;
			cin.ignore();
			string g;
			getline(cin,g);
			a.OutputArt(g);


		}
		else if (in == 't')
		{
			a.TotalTime();
		}
		else if (in == 'o')
		{
			cout << title << " - OUTPUT FULL PLAYLIST" << endl;
			a.Display();
			//cout << endl;
		}
	}

	//cout << title << endl;

	return 0;
}
