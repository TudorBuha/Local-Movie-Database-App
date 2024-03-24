#pragma once
#include "DynamicArray.h"
#include "Movie.h"

class Repository
{
private:
	DynamicArray<Movie> allMovies;
public:
	Repository(DynamicArray<Movie> initialMovies = NULL);
	DynamicArray<Movie> getAllMovies();
	bool addMovie(Movie movieToAdd);
	bool removeMovie(int indexOfMovieToRemove);
	bool updateMovie(int indexOfMovieToUpdate, Movie updatedMovie);
	int getMoviePosition(Movie movieToGetPosition);
};