#include "UserService.h"

UserService::UserService(Repository initialMoviesRepository) : moviesRepository(initialMoviesRepository)
{
}

bool UserService::addMovieToWatchList(Movie movieToAdd)
{
	if(this->watchList.findPositionOfElement(movieToAdd) == -1)
		return false;
	this->watchList.addElement(movieToAdd);
	return true;
}

bool UserService::removeMovieFromWatchList(string Title, int YearOfRelease)
{
	string Genre= "";
	string Link = "";
	int NrLikes = 0;
	Movie movieToRemove(Title, Genre, YearOfRelease, NrLikes, Link);
	int indexOfMovieToRemove = this->watchList.findPositionOfElement(movieToRemove);
	if(indexOfMovieToRemove < 0 || indexOfMovieToRemove >= this->watchList.getSize())
		return false;
	this->watchList.removeElement(indexOfMovieToRemove);
	return true;
}

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

DynamicArray<Movie> UserService::getWatchList()
{
	return this->watchList;	
}

