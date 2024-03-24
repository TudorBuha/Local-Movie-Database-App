#include "Movie.h"

Movie::Movie(string Title, string Genre, int YearOfRelease, int NrLikes, string Link)
{
	this->Title = Title;
	this->Genre = Genre;
	this->YearOfRelease = YearOfRelease;
	this->NrLikes = NrLikes;
	this->Link = Link;
}

string Movie::getTitle() const
{
	return this->Title;
}

string Movie::getGenre() const
{
	return this->Genre;
}

string Movie::getLink() const
{
	return this->Link;
}

int Movie::getNrLikes() const
{
	return this->NrLikes;
}

int Movie::getYearOfRelease() const
{
	return this->YearOfRelease;
}

void Movie::setTitle(string NewTitle)
{
	this->Title = NewTitle;
}

void Movie::setGenre(string NewGenre)
{
	this->Genre = NewGenre;
}

void Movie::setLink(string NewLink)
{
	this->Link = NewLink;
}

void Movie::setNrLikes(int NewNrLikes)
{
	this->NrLikes = NewNrLikes;
}

void Movie::setYearOfRelease(int NewYearOfRelease)
{
	this->YearOfRelease = NewYearOfRelease;
}

//A movie is not unique if it have it's Title and YearOfRelease the same as other movie
bool Movie::operator==(const Movie& MovieToCompare)
{
	if (this->Title == MovieToCompare.Title && this->YearOfRelease == MovieToCompare.YearOfRelease)
		return true;
	else
		return false;
}

void Movie::operator=(const Movie& MovieToCopy)
{
	this->Title = MovieToCopy.Title;
	this->Genre = MovieToCopy.Genre;
	this->YearOfRelease = MovieToCopy.YearOfRelease;
	this->NrLikes = MovieToCopy.NrLikes;
	this->Link = MovieToCopy.Link;
}

string Movie::toString()
{
	return this->Title + " - " + this->Genre + " - " + std::to_string(this->YearOfRelease) + " - " + std::to_string(this->NrLikes) + " likes - " + this->Link;
}