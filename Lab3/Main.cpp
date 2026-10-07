/*****************************************************************
Ashton Grady 
Lab 3

start date/End date (9/17/2026 - 10/2/2026)

Goal
program that computes and outputs the mean and population standard deviation 
of a set of four integers that are inputted by a file called “inMeanStd.dat” and the user.
The output should be to the screen for the user inputted values and to a file called “outMeanStd.dat”.
*****************************************************************/
#include <iostream>
#include <fstream>

// prototypes of mean and standaredDeviation functions.
float mean(int a, int b, int c, int d);
float standaredDeviation(float mean, int a, int b, int c, int d);

int main()
{	/************************************/
	// input from user
	int uN1, uN2, uN3, uN4;
	std::cout << "Please enter four (integers) for float standard deviation.";
	std::cin >> uN1 >> uN2 >> uN3 >> uN4;
	std::cin.ignore(999999999,'\n');

	std::cout << "the standered deviation of user numbers is: " << standaredDeviation(mean(uN1, uN2, uN3, uN4), uN1, uN2, uN3, uN4) << std::endl;

	// infile
	std::ifstream infile;
	infile.open("InMeanStd.dat");

	// fN1-4 are the numbers from the file.
	int fN1, fN2, fN3, fN4;
	infile >> fN1 >> fN2 >> fN3 >> fN4;

	// output to screen of InMeanStd.dat of file numbers and standered devation.
	std::cout << "the four numbers from InMeanStd.dat are: " << fN1 << ", " << fN2 << ", " << fN3 << ", " << fN4 << std::endl;
	std::cout << "the standered deviation of InMeanStd.dat is: " << standaredDeviation(mean(fN1, fN2, fN3, fN4), fN1, fN2, fN3, fN4) << std::endl;
	
	infile.close();

	/************************************/
	//fun-extra: rating experance for the program.
	std::cout << "how would you rate your experance 1-10: " << std::endl;
	int rating;
	std::cin >> rating;
	if (rating < 5)
	{
		std::cout << ":( sad.";
	}
	if (rating == 5)
	{
		std::cout << ":|";
	}
	if (rating > 5)
	{
		std::cout << ":) yay!";
		std::cout << std::endl;
	}

	/************************************/
	// out file 
	std::ofstream outfile;
	outfile.open("OutMeanStd.dat");

	// user output to OutMeanstd.dat
	outfile << "the four numbers from user are: " << uN1 << ", " << uN2 << ", " << uN3 << ", " << uN4 << std::endl;
	outfile << "the standered devation of user is: " << standaredDeviation(mean(uN1, uN2, uN3, uN4), uN1, uN2, uN3, uN4) << std::endl;

	// InMeanStd.dat output to OutMeanstd.dat
	outfile << "the four numbers in InMean.dat are: " << fN1 << ", " << fN2 << ", " << fN3 << ", " << fN4 << std::endl;
	outfile << "the standered deviation of InMeanStd.dat is: " << standaredDeviation(mean(fN1, fN2, fN3, fN4), fN1, fN2, fN3, fN4) << std::endl;

	outfile.close();

	return 0;

}

// definitions of mean and standaredDeviation functions.
float mean(int a, int b, int c, int d)
{
	float mean = (a + b + c + d) / 4;
		return mean;
}

float standaredDeviation(float mean, int a, int b, int c, int d)
{
	float standaredDeviation = sqrt(((a - mean) * (a - mean) + (b - mean) * (b - mean) + (c - mean) * (c - mean) + (d - mean) * (d - mean)) / 4);
		return standaredDeviation;
}