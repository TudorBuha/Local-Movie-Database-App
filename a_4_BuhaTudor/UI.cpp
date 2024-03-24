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
	//cin.ignore(); 
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
	int YearOfRelease = 0;

	cout << "Movie title to be removed:'\n' ";
	cin.ignore();
	getline(cin, Title);

	cout<< "Year of release:'\n' ";
	cin >> YearOfRelease;

	bool checkRemoved = this->adminService.removeMovie(Title, YearOfRelease);
	if (checkRemoved == true)
		cout << "Movie removed successfully!" << '\n';
	else
		cout << "Movie does not exist!" << '\n';
}


//////////////////////////      TODO      //////////////////////////////////
void UI::updateMovieUI()
{
	string Title = "", Genre = "", Link = "";
	int YearOfRelease = 0, NrLikes = 0;
	string NewTitle = "", NewGenre = "", NewLink = "";
	int NewYearOfRelease = 0, NewNrLikes = 0;

	cout << "Movie title to be updated:'\n' ";
	cin.ignore();
	getline(cin, Title);

	cout<< "Year of release: '\n'";
	cin >> YearOfRelease;

	cout << "New movie title:'\n' ";
	cin.ignore();
	getline(cin, NewTitle);

	cout<< "New movie genre: '\n'";
	cin.ignore();
	getline(cin, NewGenre);

	cout << "New year of release:'\n' ";
	cin >> NewYearOfRelease;

	cout << "New number of likes: '\n'";
	cin >> NewNrLikes;

	cout << "New link:'\n' ";
	cin.ignore();
	getline(cin, NewLink);


	//bool AdminService::updateMovie(string Title, string Genre, string NewTitle, string NewGenre, int NewYearOfRelease, int NewNrLikes, string NewLink)

	bool checkUpdated = this->adminService.updateMovie(Title, Genre, NewTitle, NewGenre, NewYearOfRelease, NewNrLikes, NewLink);
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
	//////////////////////////      TODO      //////////////////////////////////
}

void UI::displayWatchlistUI()
{
	//////////////////////////      TODO      //////////////////////////////////
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
	//////////////////////////      TODO      //////////////////////////////////
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
		//else if (accesMode.compare("user") == 0)
		//	userModeUI();
		else if (accesMode.compare("exit")==0)
		{
			cout<<"App closed succesfully!"<<'\n';
			return;
		}
		else
			cout<<"Invalid acces mode!\nHint: admin/user/exit\n\n";
		
	}
}

