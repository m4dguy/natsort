#include <iostream>
#include <string>
#include <vector>

#include "natsort.h"

/*
 * Test for natsort header.
 * Apparently the program does not like character/number comparisons if compiled with debug switch (msvc).
 */
int main()
{
    std::vector<std::string> files;

	// Test sequence
	// Contains two positions where numbers can occur:
	// first one after "set" prefix, second after "acquired-" prefix
	files.push_back("C:/set1/acquired-5.jpg");
	files.push_back("C:/set1/acquired-13.jpg");
    files.push_back("C:/set1/acquired-7.jpg");
	files.push_back("C:/setA/acquired-5.jpg");
	files.push_back("C:/set1/acquired-0.jpg");
	files.push_back("C:/set2/acquired-5.jpg");
	files.push_back("C:/set2/acquired-0.jpg");
	files.push_back("C:/set2/acquired-1.jpg");
	files.push_back("C:/set1/acquired-0.jpg");

	/*files.push_back("C:/setA/acquired-5");
	files.push_back("C:/set1/acquired-5");
	files.push_back("C:/set1/acquired-13");
	files.push_back("C:/set1/acquired-7");
	files.push_back("C:/set1/acquired-0");
	files.push_back("C:/set2/acquired-5");
	files.push_back("C:/set2/acquired-0");
	files.push_back("C:/set2/acquired-1");
	files.push_back("C:/set1/acquired-0");*/

	/*files.push_back("C:/set2/acquired-5.jpg");
	files.push_back("C:/set1/acquired-5.jpg");
	files.push_back("C:/set1/acquired-13.jpg");
	files.push_back("C:/set1/acquired-7.jpg");
	files.push_back("C:/set1/acquired-1.jpg");
	files.push_back("C:/set1/acquired-1.jpg");*/

	/*files.push_back("C:/set1/acquired-5.jpg");
	files.push_back("C:/set2/acquired-5.jpg");
	files.push_back("C:/set1/acquired-13.jpg");*/

	//files.push_back("C:/set1/acquired.jpg");
	//files.push_back("C:/set1/acquired.jpg");


    std::cout << "unsorted:" << std::endl;
    for(unsigned int i=0; i<files.size(); ++i)
        std::cout << files[i] << std::endl;

    std::sort(files.begin(), files.end(), natsort::stringcmp);

    std::cout << std::endl << std::endl << "sorted:" << std::endl;
    for(unsigned int i=0; i<files.size(); ++i)
        std::cout << files[i] << std::endl;

    return 0;
}
