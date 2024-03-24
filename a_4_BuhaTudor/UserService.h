#pragma once
#include "Repository.h"
#include <string>

using std::string;

class UserService
{
private:
	Repository moviesRepository;
	DynamicArray<Movie> watchList;
public:
	UserService(Repository initialMoviesRepository);
	bool addMovieToWatchList(Movie movieToAdd);
	bool removeMovieFromWatchList(string Title, int YearOfRelease);
	DynamicArray<Movie> getMoviesOfGivenGenre(DynamicArray<Movie> allMovies, string Genre);
	DynamicArray<Movie> getWatchList();
};