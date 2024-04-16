#pragma once
#include "Repository.h"
#include "FileWatchlist.h"
#include <string>
#include <vector>

using std::string;

class UserService
{
private:
	Repository moviesRepository;
	//vector<Movie> watchList;
	FileWatchlist* watchList;
public:
	UserService(Repository initialMoviesRepository, FileWatchlist* initialWatchlist = nullptr);
	bool addMovieToWatchList(Movie movieToAdd);
	bool removeMovieFromWatchList(string Title, string Genre);
	vector<Movie> getMoviesOfGivenGenre(vector<Movie> allMovies, string Genre);
	//vector<Movie> getWatchList();
	//void initialiseWatchList();
	FileWatchlist* getWatchList();

	void saveWatchlist();
	void openWatchlist();
};