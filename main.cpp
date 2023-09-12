#include <iostream>
#include <fstream>
#include <stdexcept>
#include <limits>
#include <string>
#include "assignment-1.hpp"

// ask user for input until an integer is given. return that integer.
int ask_until_valid(std::string message) {
    while (true) {
	std::string input;
	std::cout << message << ": ";
	try {
	    getline(std::cin, input);
	    return stoi(input);
	} catch(...) {
	    std::cout << "Invalid input. Please enter a number." << std::endl;
	}
    }
}

int main (int argc, char* argv[]) {
    // ensure an argument is given for the array length
    if (argc != 2) {
	std::cout << "Incorrect number of arguments. Please supply the length of the array as an argument." << std::endl;
	return 1;
    }

    // get size_total from first command argument. make sure this is a positive integer.
    int size_total;
    try {
	size_total = atoi(argv[1]);
	if (size_total <= 0)
	    throw std::exception();
    } catch(...) {
	std::cout << "Supplied argument must be a positive integer." << std::endl;
	return 1;
    }
    int size_used = 0;
    int arr[size_total];
    
    std::ifstream fin("numbers");

    // populate array until size_total
    int tmp;
    while(fin >> tmp) {
	if (size_used < size_total)
	    arr[size_used] = tmp;
	else
	    break;
	size_used++;
    }

    fin.close();

    // user interface
    bool flag = true;
    while(flag) {
	std::cout << "E) Check if integer exists" << std::endl
		  << "R) Replace integer at index" << std::endl
		  << "A) Add element to array" << std::endl
		  << "D) Remove element from array" << std::endl
		  << "P) Print array" << std::endl
		  << "Q) Exit program" << std::endl
		  << "----------------------------" << std::endl;

	// get user input and handle multiple characters/lower case characters
	char option;
	std::cout << ": ";
	std::cin >> option;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	option = toupper(option);

	int value, index;
	
	switch(option) {
	case 'E':
	    value = ask_until_valid("Enter value");
	    std::cout << int_in_array(value, arr, size_used) << std::endl;
	    break;
	case 'R':
	    value = ask_until_valid("Enter value");
	    index = ask_until_valid("Enter index");
	    replace_at_index(value, index, arr, size_used);
	    break;
	case 'A':
	    value = ask_until_valid("Enter value");
	    add_to_array(value, arr, size_used, size_total);
	    break;
	case 'D':
	    index = ask_until_valid("Enter index");
	    remove_from_array(index, arr, size_used, size_total);
	    break;
	case 'P':
	    for(int i = 0; i < size_used; i++)
		std::cout << arr[i] << std::endl;
	    break;
	case 'Q':
	    flag = false;
	    break;
	default:
	    std::cout << "Invalid input." << std::endl;
	    break;
	}

	std::cout << std::endl;
    }
    
    return 0;
}
