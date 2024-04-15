#pragma once
#include "Repository.h"
#include <string>

using std::string;

class UserService
{
private:
	Repository moviesRepository;
	vector<Movie> watchList;
public:
	UserService(Repository initialMoviesRepository);
	bool addMovieToWatchList(Movie movieToAdd);
	bool removeMovieFromWatchList(string Title, string Genre);
	vector<Movie> getMoviesOfGivenGenre(vector<Movie> allMovies, string Genre);
	vector<Movie> getWatchList();
	//void initialiseWatchList();
};