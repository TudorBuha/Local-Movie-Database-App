#include "AdminService.h"
#include <iostream>

AdminService::AdminService(Repository initialMoviesRepository) : moviesRepository{ initialMoviesRepository }
{
}

bool AdminService::addMovie(string Title, string Genre, int YearOfRelease, int NrLikes, string Link)
{
	Movie movieToAdd{ Title, Genre, YearOfRelease, NrLikes, Link };
	return this->moviesRepository.addMovie(movieToAdd);
}

bool AdminService::removeMovie(string Title, int YearOfRelease)
{
	//////////////idk sure how to remove
	string Genre = "";
	int NrLikes = 0;
	string Link = "";
	Movie movieToRemove{Title, Genre, YearOfRelease, NrLikes, Link};
	int indexOfMovieToRemove = this->moviesRepository.getMoviePosition(movieToRemove);
	return this->moviesRepository.removeMovie(indexOfMovieToRemove);
}

bool AdminService::updateMovie(string Title, string Genre, string NewTitle, string NewGenre, int NewYearOfRelease, int NewNrLikes, string NewLink)
{
	int yearOfRelease = 0;
	int NrLikes = 0;
	string Link = "";
	Movie movieToUpdate{ Title, Genre, yearOfRelease, NrLikes, Link };
	Movie updatedMovie{ NewTitle, NewGenre, NewYearOfRelease, NewNrLikes, NewLink };
	int indexOfMovieToUpdate = this->moviesRepository.getMoviePosition(movieToUpdate);
	return this->moviesRepository.updateMovie(indexOfMovieToUpdate, updatedMovie);
}


bool AdminService::increaseLikes(string Title, int YearOfRelease)
{
	string Genre="", Link="";
	int NrLikes=0;
	Movie movieToUpdate{ Title, Genre, YearOfRelease, NrLikes, Link };
	int indexOfMovieToUpdate = this->moviesRepository.getMoviePosition(movieToUpdate);
	Movie oldMovie = this->moviesRepository.getAllMovies().getElement(indexOfMovieToUpdate);
	Movie updatedMovie{ Title, Genre, oldMovie.getYearOfRelease(), oldMovie.getNrLikes() + 1, oldMovie.getLink() };
	return this->moviesRepository.updateMovie(indexOfMovieToUpdate, updatedMovie);
}

DynamicArray<Movie> AdminService::getAllMovies()
{
	//add an indexing before each print

	//for (int i = 0; i < this->moviesRepository.getAllMovies().getSize(); i++)
	//{
	//	std::cout << i + 1 << ". " << this->moviesRepository.getAllMovies().getElement(i).toString() << std::endl;
	//}

	return this->moviesRepository.getAllMovies();
}

void AdminService::initialiseAllMovies()
{
	this->addMovie("Titanic", "Drama", 1997, 69, "https://www.imdb.com/title/tt0120338/");
	this->addMovie("The Shawshank Redemption", "Drama", 1994, 72, "https://www.imdb.com/title/tt0111161/");
	this->addMovie("The Godfather", "Crime", 1972, 70, "https://www.imdb.com/title/tt0068646/");
	this->addMovie("The Dark Knight", "Action", 2008, 68, "https://www.imdb.com/title/tt0468569/");
	this->addMovie("The Lord of the Rings: The Return of the King", "Adventure", 2003, 67, "https://www.imdb.com/title/tt0167260/");
	this->addMovie("Pulp Fiction", "Crime", 1994, 66, "https://www.imdb.com/title/tt0110912/");
	this->addMovie("Forrest Gump", "Drama", 1994, 65, "https://www.imdb.com/title/tt0109830/");
	this->addMovie("Inception", "Action", 2010, 64, "https://www.imdb.com/title/tt1375666/");
	this->addMovie("The Fellowship of the Ring", "Action", 2001, 63, "https://www.imdb.com/title/tt0120737/");
	this->addMovie("The Matrix", "Action", 1999, 62, "https://www.imdb.com/title/tt0133093/");
}

