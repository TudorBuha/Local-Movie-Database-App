#pragma once
#include "Repository.h"
#include <string>

using std::string;


class AdminService
{
private:
	Repository moviesRepository;
public:
	AdminService(Repository initialMovieRepository);
	bool addMovie(string Title, string Genre, int YearOfRelease, int NrLikes, string Link);
	bool removeMovie(string Title, string Genre);
	bool updateMovie(string Title, string Genre, string NewTitle, string NewGenre, int NewYearOfRelease, int NewNrLikes, string NewLink);
	bool increaseLikes(string Title, string Genre);

	DynamicArray<Movie> getAllMovies();
	void initialiseAllMovies();



};