#pragma once
#include "Movie.h"
#include <vector>

using std::vector;

class Repository
{
private:
	vector<Movie> allMovies;
public:
	Repository(vector<Movie> initialMovies = {});
	vector<Movie> getAllMovies();
	bool addMovie(Movie movieToAdd);
	bool removeMovie(int indexOfMovieToRemove);
	bool updateMovie(int indexOfMovieToUpdate, Movie updatedMovie);
	int getMoviePosition(Movie movieToGetPosition);
};