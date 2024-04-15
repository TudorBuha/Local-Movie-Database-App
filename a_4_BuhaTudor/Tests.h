#pragma once
#include "Movie.h"
#include "Repository.h"
#include "AdminService.h"
#include "UserService.h"
#include <assert.h>
#include <iostream>
#include <string>


class Tests
{
public:
		void testMovie();
		void testRepository();
		void testAdminService();
		void testToString();
		void testGetAllMovies();
		void testAddMovieToRepository();
		void testRemoveMovieFromRepository();
		void testUpdateMovieFromRepository();
		void testGetMoviePositionInRepository();
		void testUserService();
		void testAll();
};