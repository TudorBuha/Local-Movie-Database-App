#include <iostream>
#include <crtdbg.h>
#include "UI.h"
#include "Tests.h"

int main() 
{
	//  taskkill /F /IM a_4_BuhaTudor.exe

	DynamicArray<Movie> allMovies;

	Repository repo{ allMovies };

	AdminService adminService{ repo };

	adminService.initialiseAllMovies();

	UserService userService{ repo };

	UI console{ adminService, userService };
		
	Tests testing;
	testing.testAll();

	console.startAppUI();

}