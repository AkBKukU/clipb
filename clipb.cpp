#include <fstream>  // file processing
#include <iostream> // cin and cout
#include <cctype>   // toupper
#include <cstring>  // cstring functions strlen, strcmp, strcpy stored in string.h
#include <string>   // string class

const std::string clipbData = "/tmp/clipb";

void saveClip (std::string text);
std::string loadClip ();

int main (int argc, char *argv[])
{	
	std::cout << "args; " << argc << " is; " << argv[1];
	if(argc > 1 && strcmp(argv[1] ,"-i") )
	{	
		// Capture passed input as cin
		std::string temp;
		std::string input;
		// Parse multiple lines
		while(std::cin)
		{
		    std::getline (std::cin,temp);
		    input = input + "\n" + temp;
		}
		input = input.substr(1);

		std::cout << input;
		saveClip(input);
	}
	else
	{
		std::cout << loadClip();
	}
	return 0;
}

void saveClip (std::string text)
{

	std::ofstream outFile;
	outFile.open( "/tmp/clipb" );

	outFile << text;
}

std::string loadClip ()
{

	return "hi";
}