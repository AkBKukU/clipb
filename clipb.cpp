#include <fstream>  // file processing
#include <iostream> // cin and cout
#include <cctype>   // toupper
#include <cstring>  // cstring functions strlen, strcmp, strcpy stored in string.h
#include <string>   // string class

const std::string clipbData = "/tmp/clipb";

void saveClip (std::string text);
std::string loadClip ();
std::string getInput ();

/* Main
 *
 */
int main (int argc, char *argv[])
{	
	// Parse Arguments
	for (int i = 1; i < argc; i++) {

		// Check if inputing
        if (std::string(argv[i]) == "-i") 
        {
            saveClip(getInput());
        }
    	
    }

    // If no args the print clip board
    if (argc == 1)
    {
		std::cout << loadClip();
    }


	return 0;
}

/* getInput
 *
 * Gets input from stream buffer to grap piped text
 *
 * @return std::string String of text passed in std::scin
 */
std::string getInput ()
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
	// Remove last newline
	input = input.substr(1);

	return input;
}

/* saveClip
 *
 * Save input to temporary file
 *
 */
void saveClip (std::string text)
{

	std::ofstream outFile;
	outFile.open( "/tmp/clipb" );

	outFile << text;
}

/* loadClip
 *
 * Gets text from temporary file and returns it
 *
 * @return std::string String of text in temp file
 */
std::string loadClip ()
{
    std::ifstream fileIn;
    fileIn.open( "/tmp/clipb" );
    std::string output = "";

    // Test if file exists
    if ( fileIn.good() )
    {
		while (! fileIn.eof()){
		    
		   output += (char)  fileIn.get() ;

		}
	}
	fileIn.close();

	// Crop off EOF char and return text
	return output.substr(0,output.length()-1);
}