#include "UserService.h"

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
	if(this->watchList.findPositionOfElement(movieToAdd) != -1)
		return false;
	this->watchList.addElement(movieToAdd);
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
	int indexOfMovieToRemove = this->watchList.findPositionOfElement(movieToRemove);
	if(indexOfMovieToRemove < 0 || indexOfMovieToRemove >= this->watchList.getSize())
		return false;
	this->watchList.removeElement(indexOfMovieToRemove);
	return true;
}

/*
  Function that returns all the movies from the watch list

  Returns:
	- a DynamicArray<Movie> object that contains all the movies from the watch list
*/
DynamicArray<Movie> UserService::getMoviesOfGivenGenre(DynamicArray<Movie> allMovies, string Genre)
{
	if(Genre.compare("") == 0)
		return allMovies;
	DynamicArray<Movie> neededMovies;
	int sizeOfRepository = allMovies.getSize();
	for(int index = 0; index < sizeOfRepository; index++)
	{
		Movie currentMovie = allMovies.getElement(index);
		if(currentMovie.getGenre().compare(Genre) == 0)
			neededMovies.addElement(currentMovie);
	}
	return neededMovies;
}

/*
  Function that returns all the movies from the watch list

  Returns:
	- a DynamicArray<Movie> object that contains all the movies from the watch list
*/
DynamicArray<Movie> UserService::getWatchList()
{
	return this->watchList;	
}

/*
  Function that returns all the movies from the watch list

  Returns:
	- a DynamicArray<Movie> object that contains all the movies from the watch list
*/
void UserService::initialiseWatchList()
{
	this->watchList = this->moviesRepository.getAllMovies();
}