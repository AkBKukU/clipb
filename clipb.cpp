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
for (int i = 1; i < argc; i++) { /* We will iterate over argv[] to get the parameters stored inside.
                                      * Note that we're starting on 1 because we don't need to know the 
                                      * path of the program, which is stored in argv[0] */
        if (i < argc) // Check that we haven't finished parsing already
        {
            if (std::string(argv[i]) == "-i") 
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

				saveClip(input);
            }
    	}
    }

    if (argc == 1)
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
    std::ifstream fileIn;
    fileIn.open( "/tmp/clipb" , std::ifstream::in);
    
    
	while (! fileIn.eof()){
	    
	   std::cout <<  (char)  fileIn.get();

	}

	return "hi";
}