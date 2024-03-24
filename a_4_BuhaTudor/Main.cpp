#include <iostream>
#include <crtdbg.h>
#include "UI.h"
//#include "Tests.h"

int main() 
{
	{
		DynamicArray<Movie> allMovies;

		Repository repo{ allMovies };

		AdminService adminService{ repo };
		adminService.initialiseAllMovies();

		UserService userService{ repo };

		UI console{ adminService, userService };

		//Tests testing;
		//testing.testAll();
		//cout<< "All tests passed!" << endl;

		console.startAppUI();
	}
	//_CrtDumpMemoryLeaks();
}