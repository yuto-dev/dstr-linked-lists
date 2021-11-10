#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct SongDetails
{
	string artist;
	string song;
	int released_year;
	string genre;
	double length;
	SongDetails* PreviousAddress;
	SongDetails* NextAddress;
} * head, * tail, * newnode, *current;

int size = 0;

void insertNewSong(string artist, string song, int released_year, string genre, double length, int position)
{
	//hints as below:
	//1. create new song
	newnode = new SongDetails;
	newnode->artist = artist;
	newnode->genre = genre;
	newnode->song = song;
	newnode->length = length;
	newnode->released_year = released_year;
	newnode->PreviousAddress = NULL;
	newnode->NextAddress = NULL;

	//2. If list is empty, assign head and tail to newnode
	if (head == NULL)
	{
		head = tail = newnode;
	}
	//3. if position = 1, then use insert to the front algorithm
	else if (position == 1) //option 1, 3
	{
		head->PreviousAddress = newnode;
		newnode->NextAddress = head;
		head = newnode;
	}
	//4. If position more than the list size, then use the insert to the end algorithm
	else if (position > ::size) //option 2, 3
	{
		tail->NextAddress = newnode;
		newnode->PreviousAddress = tail;
		tail = newnode;
	}
	//5. If position not the first and not more than the current list size, then use the insert into the middle algorithm
	else
	{
		current = head->NextAddress;
		int current_position = 2;

		while (current != NULL && current_position != position)
		{
			current = current->NextAddress;
			current_position++;
		}

		//refer to the previous node in list from current position : current->previousAddress
		current->PreviousAddress->NextAddress = newnode;
		newnode->PreviousAddress = current->PreviousAddress;
		newnode->NextAddress = current;
		current->PreviousAddress = newnode;
	}
	//6. after insert, always increase 1 to the size of the list.
	::size++;
}

void checkTabfordisplay(string text)
{
	if (text.size() <= 5)
	{
		cout << "\t\t\t\t|";
	}
	else if (text.size() < 15)
	{
		cout << "\t\t\t|";
	}
	else if (text.size() < 25)
	{
		cout << "\t\t|";
	}
	else
	{
		cout << "\t|";
	}
}

void DisplaySongList()
{
	system("cls");
	current = head;
	
	cout << "Song Details as below:" << endl;
	cout << "\n=========================================================================================================\n";
	cout << "|  No.\t|Artist\t\t\t\t|Song\t\t\t\t|Released year\t|Genre\t|Length\t|";
	cout << "\n=========================================================================================================\n";
	int i = 1;
	while (current != NULL)
	{
		cout << fixed << setprecision(2);
		cout << "|  " << i << ".\t|";
		cout << current->artist;
		checkTabfordisplay(current->artist);
		cout << current->song;
		checkTabfordisplay(current->song);
		cout << current->released_year << "\t\t|";
		cout << current->genre << "\t|";
		cout << current->length << "\t|";
		cout << endl;
		current = current->NextAddress;
		i++;
	}
	cout << "=========================================================================================================\n";
	cout << endl;
	system("pause"); //press any key to continue
	system("cls");
}

void ReversedSongList()
{
	system("cls");
	current = tail;

	cout << "Song Details as below:" << endl;
	cout << "\n=========================================================================================================\n";
	cout << "|  No.\t|Artist\t\t\t\t|Song\t\t\t\t|Released year\t|Genre\t|Length\t|";
	cout << "\n=========================================================================================================\n";
	int i = ::size;
	while (current != NULL)
	{
		cout << fixed << setprecision(2);
		cout << "|  " << i << ".\t|";
		cout << current->artist;
		checkTabfordisplay(current->artist);
		cout << current->song;
		checkTabfordisplay(current->song);
		cout << current->released_year << "\t\t|";
		cout << current->genre << "\t|";
		cout << current->length << "\t|";
		cout << endl;
		current = current->PreviousAddress;
		i--;
	}
	cout << "=========================================================================================================\n";
	cout << endl;
	system("pause"); //press any key to continue
	system("cls");
}

void DisplaySongListPageByPage() //go previous item, go next item, go back to main menu
{
	if (head == NULL)
	{
		return;
	}

	system("cls");
	current = head;
	int i = 1; int decision = 1;

	while (decision != 0)
	{
		cout << "Song Details as below:" << endl;
		cout << "\n=========================================================================\n";
		cout << "| " << current->artist << " - " << current->song;
		checkTabfordisplay(current->song);
		cout << "\n=========================================================================\n";
		cout << "| Song Number : " << i;
		checkTabfordisplay(to_string(i));
		cout << endl;
		cout << "| Artist Name : " << current->artist;
		checkTabfordisplay(current->artist);
		cout << endl;
		cout << "| Song Name : " << current->song;
		checkTabfordisplay(current->song);
		cout << endl;
		cout << "| Released Year : " << current->released_year;
		checkTabfordisplay(to_string(current->released_year));
		cout << endl;
		cout << "| Genre Type : " << current->genre;
		checkTabfordisplay(current->genre);
		cout << endl;
		cout << "| Song Duration : " << current->length << "\t\t\t\t\t\t\t|";
		cout << "\n=========================================================================\n";
		cout << "| 1. Next Song\t 2.Previous Song\t 0.Exit to Menu Page \t|";
		cout << "\n=========================================================================\n";
		cout << endl << "Select your option: ";
		cin >> decision;
		cin.ignore();

		switch (decision)
		{
		case 1: 
			if (current->NextAddress != NULL)
			{
				current = current->NextAddress;
				i++;
			}
			else
			{
				cout << "There is no more song!" << endl;
				system("pause");
			}
			break;
		case 2:
			if (current->PreviousAddress != NULL)
			{
				current = current->PreviousAddress;
				i--;
			}
			else
			{
				cout << "There is no more song!" << endl;
				system("pause");
			}
			break;
		case 0:
			return;
		default:
			cout << "Warning: Invalid option!" << endl;
			system("pause");
		}
		system("cls");
	}
}

void deleteASong(int position = NULL)
{
	//1. check list is empty or not?
	if (head == NULL)
	{
		cout << "The list is empty!" << endl;
		system("pause");
		return;
	}
	system("cls");
	//2. find out the option given by the user
	//2.1 - option 8: delete the song from the first location
	if (position == 1)
	{
		current = head;
		head = head->NextAddress;
		if (head != NULL)
		{
			head->PreviousAddress = NULL;
		}
		else
		{
			tail = NULL;
		}
		cout << "The song of " << current->song << " is deleted now!" << endl;
		delete current;
		system("pause");
		DisplaySongList();
		::size--;
	}
	//2.2 - option 9 : delete from the end of the list
	else if (position == ::size)
	{
		current = tail;
		tail = tail->PreviousAddress;
		if (tail != NULL)
		{
			tail->NextAddress = NULL;
		}
		else
		{
			head = NULL;
		}
		cout << "The song of " << current->song << " is deleted now!" << endl;
		delete current;
		system("pause");
		DisplaySongList();
		::size--;
	}
	//2.3: option 10: delete based on the artist name
	else
	{
		string artistname;
		cout << "Which artist you would like to delete? " << endl;
		DisplaySongList();
		cout << "Give your artist name here: ";
		getline(cin, artistname);

		current = head;

		while (current != NULL)
		{
			//situation 1: artist name in the first location
			if (current->artist == artistname && current == head)
			{
				current = head;
				head = head->NextAddress;
				if (head != NULL)
				{
					head->PreviousAddress = NULL;
				}
				else
				{
					tail = NULL;
				}
				cout << "The song of " << current->song << " is deleted now!" << endl;
				delete current;
				system("pause");
				DisplaySongList();
				::size--;
				return;
			}
			//situation 2: artist name is not in the first location
			else if (current->artist == artistname)
			{
				//current->previousAddress = previous node
				current->PreviousAddress->NextAddress = current->NextAddress;
				if (current->NextAddress != NULL)
				{
					current->NextAddress->PreviousAddress = current->PreviousAddress;
				}
				else //no next node after delete
				{
					tail = tail->PreviousAddress;
				}
				cout << "The " << current->artist << "'s song of " << current->song << " is deleted now!" << endl;
				delete current;
				system("pause");
				DisplaySongList();
				::size--;
				return;
			}

			current = current->NextAddress;
		}

		cout << "Artist not found!" << endl;
		system("pause");
		system("cls");
	}
}

int main()
{
	string artist; string song; int released_year; string genre; double length; int position;
	head = tail = NULL;
	string defaultSongs[4][5] =
	{
		{"Celine Dion", "Just Walk Away", "1993", "Pop", "4.58"},
		{"Taylor Swift", "You Belong With Me", "2008", "Pop", "3.48"},
		{"The Cranberries", "Promises", "1999", "Rock", "4.30"},
		{"Hello", "Hello", "1999", "Rock", "4.11"}
	};

	for (int i = 0; i < 4; i++)
	{
		insertNewSong(defaultSongs[i][0], defaultSongs[i][1], stoi(defaultSongs[i][2]), defaultSongs[i][3], stod(defaultSongs[i][4]), ::size + 1);
	}

	int decision = 1;
	while (decision != 0)
	{
		cout << "Welcome to ABC Song Music Player!\n";
		cout << "-------------------------------------------------";
		cout << endl;
		cout << "Menu Option:" << endl;
		cout << "-------------------------------------------------\n";
		cout << "1.  Add new song at the beginning of current song list" << endl;
		cout << "2.  Add new song at the end of current song list" << endl;
		cout << "3.  Add new song at any position of current song list" << endl;
		cout << "4.  Display the current list" << endl;
		cout << "5.  Display the current list in reverse sequence" << endl;
		cout << "6.  Display the current list in page by page" << endl;
		cout << "7.  Sort the current list and Display" << endl;
		cout << "8.  Delete a song from the beginning of the current list" << endl;
		cout << "9.  Delete a song from the end of the current list" << endl;
		cout << "10. Delete a song based on the Artist Name" << endl;
		cout << "11. Search a song based on the genre of song" << endl;
		cout << "0.  Exit program" << endl << endl;
		cout << "Select an option: ";
		cin >> decision;
		cin.ignore();

		switch (decision)
		{
		case 1: 
			system("cls");
			cout << "Enter artist name: ";
			getline(cin, artist);
			cout << "Enter song name: ";
			getline(cin, song);
			cout << "Enter song release year: ";
			cin >> released_year;
			cin.ignore();
			cout << "Enter the genre of song: ";
			getline(cin, genre);
			cout << "Enter the song duration: ";
			cin >> length;
			cin.ignore();
			insertNewSong(artist, song, released_year, genre, length, 1);
			break;
		case 2:
			system("cls");
			cout << "Enter artist name: ";
			getline(cin, artist);
			cout << "Enter song name: ";
			getline(cin, song);
			cout << "Enter song release year: ";
			cin >> released_year;
			cin.ignore();
			cout << "Enter the genre of song: ";
			getline(cin, genre);
			cout << "Enter the song duration: ";
			cin >> length;
			cin.ignore();
			insertNewSong(artist, song, released_year, genre, length, ::size +1);
			break;
		case 3:
			system("cls");
			cout << "Enter artist name: ";
			getline(cin, artist);
			cout << "Enter song name: ";
			getline(cin, song);
			cout << "Enter song release year: ";
			cin >> released_year;
			cin.ignore();
			cout << "Enter the genre of song: ";
			getline(cin, genre);
			cout << "Enter the song duration: ";
			cin >> length;
			cout << "Where you want to insert this song (position 1 - position " << ::size + 1 << "): ";
			cin >> position;
			cin.ignore();
			insertNewSong(artist, song, released_year, genre, length, position);
			break;
		case 4: DisplaySongList();break;
		case 5: ReversedSongList();break;
		case 6: DisplaySongListPageByPage(); break;

		case 8: deleteASong(1);break;
		case 9: deleteASong(::size);break;
		case 10: deleteASong();break;

		case 0: system("exit"); break;
		default: cout << "Invalid Option!" << endl;
			system("pause");
		}
		system("cls");
	}
	return 0;
}


