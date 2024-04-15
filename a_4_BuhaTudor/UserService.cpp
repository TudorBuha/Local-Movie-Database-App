#include "UserService.h"
#include <iterator>
#include <algorithm>
/*
  Constructor for the UserService class
*/
UserService::UserService(Repository initialMoviesRepository) : moviesRepository(initialMoviesRepository)
{
}

/*
  Function that returns all the movies from the repository

  Returns:
	- a DynamicArray<Movie> object that contains all the movies from the repository
*/
bool UserService::addMovieToWatchList(Movie movieToAdd)
{
	auto iterator = std::find(this->watchList.begin(), this->watchList.end(), movieToAdd);
	if(iterator != this->watchList.end())
		return false;
	this->watchList.push_back(movieToAdd);
	return true;
}

/*
  Function that removes a movie from the watch list

  Parameters:
	- Title: a string representing the title of the movie to be removed
	- Genre: a string representing the genre of the movie to be removed

  Returns:
	- true, if the movie was removed successfully
	- false, otherwise
*/
bool UserService::removeMovieFromWatchList(string Title, string Genre)
{
	string Link = "";
	int NrLikes = 0, YearOfRelease = 0;
	Movie movieToRemove(Title, Genre, YearOfRelease, NrLikes, Link);
	auto iterator = std::find(this->watchList.begin(), this->watchList.end(), movieToRemove);
	if(iterator == this->watchList.end())
		return false;
	this->watchList.erase(iterator);
	return true;
}

/*
  Function that returns all the movies from the watch list

  Returns:
	- a DynamicArray<Movie> object that contains all the movies from the watch list
*/
vector<Movie> UserService::getMoviesOfGivenGenre(vector<Movie> allMovies, string Genre)
{
	if(Genre.compare("") == 0)
		return allMovies;
	vector<Movie> neededMovies;
	std::copy_if(allMovies.begin(), allMovies.end(), std::back_inserter(neededMovies), [Genre](const Movie& movie) { return movie.getGenre() == Genre; });
	return neededMovies;
}

/*
  Function that returns all the movies from the watch list

  Returns:
	- a DynamicArray<Movie> object that contains all the movies from the watch list
*/
vector<Movie> UserService::getWatchList()
{
	return this->watchList;	
}

/*
  Function that returns all the movies from the watch list

  Returns:
	- a DynamicArray<Movie> object that contains all the movies from the watch list
*/
/*
void UserService::initialiseWatchList()
{
	this->watchList = this->moviesRepository.getAllMovies();
}
*/