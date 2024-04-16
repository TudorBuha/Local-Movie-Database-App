/*

#include "Tests.h"
#include <assert.h>
#include <iostream>
#include <cstdlib>
#include <vector>


void Tests::testMovie()
{
	Movie testMovie("TestTitle", "TestGenre", 2000, 100, "TestLink"); // test the constructor
	assert(testMovie.getTitle() == "TestTitle");
	assert(testMovie.getGenre() == "TestGenre");
	assert(testMovie.getYearOfRelease() == 2000);
	assert(testMovie.getNrLikes() == 100);
	assert(testMovie.getLink() == "TestLink");

	//Test setters	
	testMovie.setTitle("NewTitle");
	testMovie.setGenre("NewGenre");
	testMovie.setYearOfRelease(2001);
	testMovie.setNrLikes(101);
	testMovie.setLink("NewLink");
	assert(testMovie.getTitle() == "NewTitle");
	assert(testMovie.getGenre() == "NewGenre");
	assert(testMovie.getYearOfRelease() == 2001);
	assert(testMovie.getNrLikes() == 101);
	assert(testMovie.getLink() == "NewLink");

	//Test equality operator
	Movie testMovie2("NewTitle", "NewGenre", 2001, 101, "NewLink");
	assert(testMovie == testMovie2);


	//Test assignment operator
	Movie testMovie3 = testMovie;
	assert(testMovie3.getTitle() == "NewTitle");
	assert(testMovie3.getGenre() == "NewGenre");
	assert(testMovie3.getYearOfRelease() == 2001);
	assert(testMovie3.getNrLikes() == 101);
	assert(testMovie3.getLink() == "NewLink");

}

void Tests::testToString()
{
	Movie testMovie("TestTitle", "TestGenre", 2000, 100, "TestLink");
	assert(testMovie.toString() == "TestTitle - TestGenre - 2000 - 100 likes - TestLink");
}

void Tests::testRepository()
{
	this->testGetAllMovies();
	this->testAddMovieToRepository();
	this->testRemoveMovieFromRepository();
	this->testUpdateMovieFromRepository();
	this->testGetMoviePositionInRepository();
}

void Tests::testAdminService()
{
	vector<Movie> initialMovies;
	Repository testRepo{ initialMovies };
	AdminService testService{ testRepo };

	assert(testService.addMovie("TestTitle1", "TestGenre1", 0, 0, "TestLink1") == true);
	assert(testService.addMovie("TestTitle2", "TestGenre2", 0, 0, "TestLink2") == true);

	vector<Movie> allMovies = testService.getAllMovies();
	assert(allMovies.size() == 2);

	assert(testService.removeMovie("TestTitle1", "TestGenre1") == true);
	assert(testService.getAllMovies().size() == 1);

	assert(testService.updateMovie("TestTitle2", "TestGenre2", "NewTitle", "NewGenre", 2001, 101, "NewLink") == true);
	Movie updatedMovie = testService.getAllMovies()[0];
	assert(updatedMovie.getTitle() == "NewTitle");
	assert(updatedMovie.getGenre() == "NewGenre");
	assert(updatedMovie.getYearOfRelease() == 2001);
	assert(updatedMovie.getNrLikes() == 101);
	assert(updatedMovie.getLink() == "NewLink");

	//test increase like function
	assert(testService.increaseLikes("NewTitle", "NewGenre") == true);
	updatedMovie = testService.getAllMovies()[0];
	assert(updatedMovie.getNrLikes() == 102);

}

void Tests::testGetAllMovies()
{
	Movie testMovie("TestTitle", "TestGenre", 2000, 100, "TestLink");
	// Initialize the repository with sample movie
	vector<Movie> initialMovies;
	initialMovies.push_back(testMovie);
	Repository testRepo(initialMovies);
	vector<Movie> allMovies = testRepo.getAllMovies();
	assert(allMovies.size() == 1);
	assert(allMovies[0] == Movie("TestTitle", "TestGenre", 2000, 100, "TestLink"));
}

void Tests::testAddMovieToRepository()
{
	Movie validMovie("TestTitle", "TestGenre", 2000, 100, "TestLink");
	// Initialize the repository with sample movie
	vector<Movie> initialMovies;
	Repository repo(initialMovies);
	// Test the addMovie method
	bool checkAdded = repo.addMovie(validMovie);
	assert(checkAdded == true);
	vector<Movie> allMovies = repo.getAllMovies();
	assert(allMovies.size() == 1);
	assert(allMovies[0] == validMovie);
	//Test adding a movie that already exists (should return false)
	checkAdded = repo.addMovie(validMovie);
	assert(checkAdded == false);
	allMovies = repo.getAllMovies();
	assert(allMovies.size() == 1);
}

void Tests::testRemoveMovieFromRepository()
{
	Movie testMovieToCheckRemoveElement("TestTitle", "TestGenre", 2000, 100, "TestLink");
	Movie testMovieToCheckRemovedPosition("TestTitle2", "TestGenre2", 2001, 101, "TestLink2");
	Movie testMovieToAdd("TestTitle3", "TestGenre3", 2002, 102, "TestLink3");

	// Initialize the repository with the sample movies
	vector<Movie> initialMovies;
	initialMovies.push_back(testMovieToCheckRemoveElement);
	initialMovies.push_back(testMovieToCheckRemovedPosition);
	Repository repo(initialMovies);

	// Test the removeMovieFromRepository function
	bool checkRemoved = repo.removeMovie(1);
	assert(checkRemoved == true);
	vector<Movie> allMovies = repo.getAllMovies();
	assert(allMovies.size() == 1);
	assert(allMovies[0] == testMovieToCheckRemoveElement);

	// Test removing a movie with an invalid index (should not remove)
	checkRemoved = repo.removeMovie(77);
	assert(checkRemoved == false);
	allMovies = repo.getAllMovies();
	assert(allMovies.size() == 1);

	//Test adding a movie after removing one
	bool checkAdded = repo.addMovie(testMovieToAdd);
	assert(checkAdded == true);
	allMovies = repo.getAllMovies();
	assert(allMovies.size() == 2);
	assert(allMovies[1] == testMovieToAdd);

}

void Tests::testUpdateMovieFromRepository()
{
	Movie testMovieToCheckUpdatePosition("TestTitle", "TestGenre", 2000, 100, "TestLink");
	Movie testMovieToUpdate("TestTitle2", "TestGenre2", 2001, 101, "TestLink2");

	// Initialize the repository with the sample movies
	vector<Movie> initialMovies;
	initialMovies.push_back(testMovieToCheckUpdatePosition);
	initialMovies.push_back(testMovieToUpdate);
	Repository repo(initialMovies);

	// Test updateing a movie from a valid position
	Movie movieToTestUpdate("TestTitle3", "TestGenre3", 2002, 102, "TestLink3");
	repo.addMovie(movieToTestUpdate);
	Movie updatedMovie("UpdatedTitle", "UpdatedGenre", 2003, 103, "UpdatedLink");
	bool checkUpdated = repo.updateMovie(2, updatedMovie); 
	assert(checkUpdated == true);
	vector<Movie> allMovies = repo.getAllMovies();
	assert(allMovies.size() == 3);
	assert(allMovies[2] == updatedMovie);

	// Test updating a movie at an invalid index
	checkUpdated = repo.updateMovie(77, updatedMovie);
	assert(checkUpdated == false);
	allMovies = repo.getAllMovies();
	assert(allMovies.size() == 3);
	assert(allMovies[2] == updatedMovie);
}

void Tests::testGetMoviePositionInRepository()
{
	Movie testMovie1("TestTitle", "TestGenre", 2000, 100, "TestLink");

	// Initialize the repository with the sample movies
	vector<Movie> initialMovies;
	initialMovies.push_back(testMovie1);
	Repository repo(initialMovies);

	// Test the getMoviePositionInRepository function with an existing movie
	int position = repo.getMoviePosition(testMovie1);
	assert(position == 0);

	// Test the getMoviePositionInRepository function with a non-existing movie
	Movie nonExistingMovie("NonExistingTitle", "NonExistingGenre", 2000, 100, "NonExistingLink");
	position = repo.getMoviePosition(nonExistingMovie);
	assert(position == -1);
}

void Tests::testUserService()
{
	// Create sample data
	Movie testMovieToCheckUserAdd("TestTitle1", "TestGenre1", 2000, 100, "TestLink1");
	Movie testMovieToCheckUserRemove("TestTitle2", "TestGenre2", 2001, 101, "TestLink2");

	// Create user service
	vector<Movie> initialMovies;
	Repository repo{ initialMovies };
	UserService userService{ repo };
		
	
	// Test addMovieToWatchList
	assert(userService.addMovieToWatchList(testMovieToCheckUserAdd) == true);
	assert(userService.addMovieToWatchList(testMovieToCheckUserAdd) == false);
	assert(userService.getWatchList().size() == 1);

	// Test removeMovieFromWatchList
	assert(userService.removeMovieFromWatchList("TestTitle1", "TestGenre1") == true);
	assert(userService.removeMovieFromWatchList("TestTitle1", "TestGenre1") == false);
	assert(userService.getWatchList().size() == 0);

	// Test getMoviesOfGivenGenre
	vector<Movie> allMovies;
	allMovies.push_back(testMovieToCheckUserAdd);
	allMovies.push_back(testMovieToCheckUserRemove);
	vector<Movie> neededMovies = userService.getMoviesOfGivenGenre(allMovies, "");
	assert(neededMovies.size() == 2);
	neededMovies = userService.getMoviesOfGivenGenre(allMovies, "TestGenre1");
	assert(neededMovies.size() == 1);
	


	
}

void Tests::testAll()
{
	this->testMovie();
	this->testRepository();
	this->testAdminService();
	this->testToString();
	this->testUserService();

	std::cout << "All tests passed!" << std::endl;


}

*/