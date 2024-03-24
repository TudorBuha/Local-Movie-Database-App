#include "Repository.h"

Repository::Repository(DynamicArray<Movie> initialMovies) : allMovies{ initialMovies }
{
}

DynamicArray<Movie> Repository::getAllMovies()
{
	return this->allMovies;
}

bool Repository::addMovie(Movie movieToAdd)
{
	if (this->allMovies.findPositionOfElement(movieToAdd) != -1)
		return false;
	this->allMovies.addElement(movieToAdd);

	return true;
}

bool Repository::removeMovie(int indexOfMovieToRemove)
{
	if (indexOfMovieToRemove < 0 || indexOfMovieToRemove >= this->allMovies.getSize())
		return false;
	this->allMovies.removeElement(indexOfMovieToRemove);
	return true;
}

bool Repository::updateMovie(int indexOfMovieToUpdate, Movie updatedMovie)
{
	if (indexOfMovieToUpdate < 0 || indexOfMovieToUpdate >= this->allMovies.getSize())
		return false;
	this->allMovies.updateElement(indexOfMovieToUpdate, updatedMovie);
	return true;
}

int Repository::getMoviePosition(Movie movieToGetPosition)
{
	return this->allMovies.findPositionOfElement(movieToGetPosition);
}

