#include <iostream>
#include <crtdbg.h>
#include "UI.h"
#include "Tests.h"
#include "Exception.h"
#include "CsvWatchlist.h"
#include "HtmlWatchlist.h"

using namespace std;

int main() 
{
	{

		//  taskkill /F /IM a_4_BuhaTudor.exe

		try {
			Repository repo{ "movies.txt" };
			FileWatchlist* filePointer = nullptr;

			cout << "What type of file would you like to use to store the playlist (CSV/HTML)?\n";
			string fileType{};
			cin >> fileType;
			
			if (fileType == "CSV")
				filePointer = new CsvWatchlist{ "watchlist.csv" };
			else
				filePointer = new HtmlWatchlist{ "watchlist.html" };
			

			UserService userService{ repo, filePointer };
			AdminService adminService{ repo };
			UI console{ adminService, userService };
			//Tests testing;
			//testing.testAll();
			//cout<<endl;
			//cout<<endl;
			console.startAppUI();
		}
		catch (FileException&)
		{
			cout << "Repository file could not be opened! The application will terminate." << endl;
			return 1;
		}
	}
	_CrtDumpMemoryLeaks();
}