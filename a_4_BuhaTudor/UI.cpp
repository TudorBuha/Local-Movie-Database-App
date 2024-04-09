#include "UI.h"
#include <iostream>
#include <string>
#include <cstdlib>

using std::string;
using std::cout;
using std::cin;
using std::getline;

UI::UI(AdminService initialAdminService, UserService initialUserService) : adminService(initialAdminService), userService(initialUserService)
{
}

void UI::addMovieUi()
{
	string Title = "", Genre = "", Link = "";
	int YearOfRelease=0, NrLikes=0;
	
	cout << "Movie title: '\n'";
	cin.ignore(); // ignores the '\n' character from the buffer
	getline(cin, Title);

	cout << "Movie genre: '\n'";
	getline(cin, Genre);

	cout << "Year of release: '\n'";
	cin >> YearOfRelease;

	cout << "Number of likes:'\n' ";
	cin >> NrLikes;

	cout << "Link:'\n' ";
	cin.ignore();
	getline(cin, Link);

	bool checkAdded = this->adminService.addMovie(Title, Genre, YearOfRelease, NrLikes, Link);
	if (checkAdded == true)
		cout << "Movie added successfully!" << '\n';
	else
		cout << "Movie already exists!" << '\n';
}

void UI::removeMovieUI()
{
	string Title = "";
	string Genre = "";

	cout << "Movie title to be removed: ";
	cin.ignore();
	getline(cin, Title);

	cout<<"Genre: ";

	getline(cin, Genre);

	bool checkRemoved = this->adminService.removeMovie(Title, Genre);
	if (checkRemoved == true)
		cout << "Movie removed successfully!" << '\n';
	else
		cout << "Movie does not exist!" << '\n';
}



void UI::updateMovieUI()
{
	string Title, Genre;

	std::cout<<"Enter the title of the movie you want to update: ";
	cin.ignore();
	getline(cin, Title);

	std::cout << "Enter the genre of the movie you want to update: ";
	//cin.ignore();
	getline(cin, Genre);


	std::cout<<"Enter the new title of the movie: ";
	string newTitle;
	//cin.ignore();
	getline(cin, newTitle);

	std::cout<<"Enter the new genre of the movie: ";
	string newGenre;
	//cin.ignore();
	getline(cin, newGenre);

	std::cout<<"Enter the new year of release of the movie: ";
	int newYearOfRelease;
	cin>>newYearOfRelease;

	std::cout<<"Enter the new number of likes of the movie: ";
	int newNrLikes;
	cin>>newNrLikes;

	std::cout<<"Enter the new link of the movie: ";
	string newLink;
	cin.ignore();
	getline(cin, newLink);

	bool checkUpdated = this->adminService.updateMovie(Title, Genre, newTitle, newGenre, newYearOfRelease, newNrLikes, newLink);
	if (checkUpdated == true)
		cout << "Movie updated successfully!" << '\n';
	else
		cout << "Movie does not exist!" << '\n';
}


void UI::displayAllMoviesUI()
{
	DynamicArray<Movie> allMovies = this->adminService.getAllMovies();
	for (int i = 0; i < allMovies.getSize(); i++)
	{
		Movie currentMovie = allMovies.getElement(i);
		cout << "#" << i + 1 << ". ";
		cout << currentMovie.toString() << '\n';
	}
}

void UI::printAdminMenuUI()
{	
	cout<<"Admin menu: "<<'\n';
	cout<<"1. Add movie."<<'\n';
	cout<<"2. Remove movie."<<'\n';
	cout<<"3. Update movie."<<'\n';
	cout<<"4. Display all movies."<<'\n';
	cout<<"0. Exit admin mode."<<'\n';
}

void UI::adminModeUI()
{
	int option;
	printAdminMenuUI();
	while (true)
	{
		cout<<"Enter option: ";
		cin >> option;	

		if(cin.fail() || option < 0  || option > 4)
		{
			cout<<"Invalid option!"<<'\n';
			cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear the buffer from invalid input 
			continue;
		}

		switch (option)
		{
		case 1:
			addMovieUi();
			break;
		case 2:
			removeMovieUI();
			break;
		case 3:
			updateMovieUI();
			break;
		case 4:
			displayAllMoviesUI();
			break;
		case 0:
			cout << std::endl;
			return;
		default:
			cout<<"Invalid option! Please try again!"<<'\n';
			break;
		}
	}
}

void UI::searchMovieByGenreUI()
{
	string genre = "";
	string userOption = "";

	cout<<"Search a genre: ";
	cin.ignore();
	getline(cin, genre);

	DynamicArray<Movie> searchedMovies = this->userService.getMoviesOfGivenGenre(this->adminService.getAllMovies(), genre);
	int currentMovieIndex = 0;

	while (true)
	{
		if (searchedMovies.getSize() == 0)
		{
			cout << "\nInvalid search! Please enter a valid genre!\n";
			break;
		}
		if(currentMovieIndex == searchedMovies.getSize())
			currentMovieIndex = 0;

		Movie currentMovie = searchedMovies.getElement(currentMovieIndex);
		cout << "\n#" << currentMovieIndex + 1 << std::endl;
		cout << currentMovie.toString() << '\n';

		string command = "start " + currentMovie.getLink();
		system(command.c_str());

		cout << "Do you want to add this movie to your watchlist? (yes/next): ";
		cout<< "Write 'x' to exit search!\n\n";

		while (true)
		{
			cout << "> ";
			cin >> userOption;
			if (userOption.compare("yes") == 0)
			{
				this->userService.addMovieToWatchList(currentMovie);
				currentMovieIndex++;
				cout << "Movie added to watchlist!" << '\n';
				break;
			}
			else if (userOption.compare("next") == 0)
			{
				currentMovieIndex++;
				break;
			}
			else if (userOption.compare("x") == 0) 
			{
				cout << "You exited the search!\n";
				return;
			}
			else
				cout << "\nTake your time to decide!\nHint:\nyes - add to watchlist\nnext - see next tutorial in the search\nx - exit the search\n\n";
		}
		cout << std::endl;
	}
}

void UI::removeMovieFromWatchlistUI()
{
	string Title = "", Genre = "";
	string userOption;

	std::cout<<"Enter the title of the movie you want to remove from the watchlist: ";
	cin.ignore();
	getline(cin, Title);

	std::cout<<"Enter the genre of the movie you want to remove from the watchlist: ";
	//cin.ignore();
	getline(cin, Genre);

	bool checkRemoved = this->userService.removeMovieFromWatchList(Title, Genre);
	if (checkRemoved == false)
		cout << "Movie does not exist in the watchlist!" << '\n';
	else
	{
		cout<<"Would you like to leave a like at this tutorial before removing it? (yes/no)\n";
		while (true)
		{
			cout << "> ";
			cin >> userOption;
			if (userOption.compare("yes") == 0)
			{
				this->adminService.increaseLikes(Title, Genre);
				cout << "Like added! Thank you for feedback!" << '\n';
				break;
			}
			else if (userOption.compare("no") == 0)
			{
				cout << "Like not added! Thank you for feedback!" << '\n';
				break;
			}
			else
				cout << "Invalid option! Please try again!\n Hint:(yes/no)" << '\n';	
			cout << "Movie removed from watchlist successfully!" << '\n';
		}
	}

		
}

void UI::displayWatchlistUI()
{
	DynamicArray<Movie> watchlist = this->userService.getWatchList();
	for (int i = 0; i < watchlist.getSize(); i++)
	{
		Movie currentMovie = watchlist.getElement(i);
		cout << "#" << i + 1 << ". ";
		cout << currentMovie.toString() << '\n';
	}
}

void UI::printUserMenuUI()
{
	cout << "User menu: " << '\n';
	cout << "1. Search movie by genre." << '\n';
	cout << "2. Remove movie from watchlist." << '\n';
	cout << "3. Display watchlist." << '\n';
	cout << "0. Exit user mode." << '\n';
}

void UI::userModeUI()
{
	int optionChosen = -1;
	printUserMenuUI();
	while (true)
	{
		cout<<"Enter option: ";
		cin >> optionChosen;

		if (cin.fail() || optionChosen < 0 || optionChosen > 3)
		{
			cout<<"Invalid option!"<<'\n';
			cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear the buffer from invalid input 
			continue;
		}
		switch (optionChosen)
		{
		case 1:
			searchMovieByGenreUI();
			break;
		case 2:
			removeMovieFromWatchlistUI();
			break;
		case 3:
			displayWatchlistUI();
			break;
		case 0:
			cout << std::endl;
			return;
		default:
			cout<<"Invalid option! Please try again!"<<'\n';
			break;
		}
	}
}


void UI::startAppUI()
{
	cout << "Welcome to Local Movie Database!" << '\n';
	cout << "Please enter your mode (admin/user) or type 'exit' to close the app \n \n";

	string accesMode = "";

	while (true)
	{
		cout<<"Enter mode: ";
		cin >> accesMode;
		if (accesMode.compare("admin") == 0)
			adminModeUI();
		else if (accesMode.compare("user") == 0)
			userModeUI();
		else if (accesMode.compare("exit")==0)
		{
			cout<<"App closed successfully!"<<'\n';
			return;
		}
		else
			cout<<"Invalid acces mode!\nHint: admin/user/exit\n\n";
		
	}
}

