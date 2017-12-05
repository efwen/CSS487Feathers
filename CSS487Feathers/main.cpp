#include "FeatherIdentifier.h"

#include <iostream>
using namespace std;

#include <opencv2\core.hpp>
using namespace cv;

int main(int argc, char *argv[])
{
	string testingFile, trainingFile, workingDirectory;

	if (argc < 3)
		return -1;

	if (argc >= 3)
	{
		trainingFile = argv[1];
		testingFile = argv[2];
	}
	
	if (argc >= 4)
	{
		workingDirectory = argv[3];
		workingDirectory += "/";
	}
	else
	{
		workingDirectory = "";
	}

	FeatherIdentifier FeatherID = FeatherIdentifier(workingDirectory);

	bool verify = true;
	if (!FeatherID.Train(trainingFile, verify))
	{
		system("pause");
		return -1;
	}
	

	if (!FeatherID.Identify(testingFile, true))
	{
		system("pause");
		return -1;
	}

	//FeatherID.ListResults(ratings);

	cin.get();

	return 0;
}