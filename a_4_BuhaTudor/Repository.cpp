#include "Repository.h"
#include <algorithm>

/*
	Constructor for the Repository class
	Initializes the repository with an empty list of movies
*/
Repository::Repository(std::vector<Movie> initialMovies) : allMovies{ initialMovies }
{
}

/*
	Getter for the list of movies
	Returns a DynamicArray of Movie objects
*/
vector<Movie> Repository::getAllMovies()
{
	return this->allMovies;
}



/*
	Adds a movie to the repository
	Input:
		- movieToAdd - Movie object
	Output:
		- true, if the movie was added successfully
		- false, otherwise
*/
bool Repository::addMovie(Movie movieToAdd)
{
	auto iterator = std::find(this->allMovies.begin(), this->allMovies.end(), movieToAdd);
	if(iterator != this->allMovies.end())
		return false;
	this->allMovies.push_back(movieToAdd);
	return true;
}

/*
	Removes a movie from the repository
	Input:
		- movieToRemove - Movie object
	Output:
		- true, if the movie was removed successfully
		- false, otherwise
*/
bool Repository::removeMovie(int indexOfMovieToRemove)
{
	if (indexOfMovieToRemove < 0 || indexOfMovieToRemove >= this->allMovies.size())
		return false;
	this->allMovies.erase(this->allMovies.begin() + indexOfMovieToRemove);
	return true;
}

/*
	Updates a movie from the repository
	Input:
		- indexOfMovieToUpdate - int
		- updatedMovie - Movie object
	Output:
		- true, if the movie was updated successfully
		- false, otherwise
*/
bool Repository::updateMovie(int indexOfMovieToUpdate, Movie updatedMovie)
{
	if (indexOfMovieToUpdate < 0 || indexOfMovieToUpdate > this->allMovies.size())
		return false;
	this->allMovies[indexOfMovieToUpdate] = updatedMovie;
	return true;
}

/*
	Returns the position of a movie in the repository
	Input:
		- movieToGetPosition - Movie object
	Output:
		- int - the position of the movie in the repository
*/
int Repository::getMoviePosition(Movie movieToGetPosition)
{
	auto iterator = std::find(this->allMovies.begin(), this->allMovies.end(), movieToGetPosition);
	if (iterator == this->allMovies.end())
		return -1;
	return std::distance(this->allMovies.begin(), iterator);
}

