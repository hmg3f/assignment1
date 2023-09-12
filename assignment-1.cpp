#include <iostream>
#include <stdexcept>

int int_in_array(int value, int array[], int size) {
    for (int i = 0; i < size; i++) {
	if (array[i] == value) {
	    return i;
	}
    }
    
    return -1;
}

void replace_at_index(int value, int index, int arr[], int size) {
    try {
	if (index >= size || index < 0)
	    throw std::length_error("Given index is out of bounds.");
	arr[index] = value;
    } catch (std::length_error &e) {
	std::cout << e.what() << std::endl;
    }
}

void add_to_array(int value, int arr[], int &size_used, int size_total) {
    try {
	if (size_used >= size_total)
	    throw std::length_error("Given array has no unused space.");
	arr[size_used] = value;
	size_used++;
    } catch (std::length_error &e) {
	std::cout << "ERROR: " << e.what() << std::endl;
	std::cout << "  Tried to add " << value << " to index "
		  << size_used << "/" << size_total - 1 << std::endl;
    }
}

void remove_from_array(int index, int arr[], int &size_used, int size_total) {
    try {
	if (index >= size_total || index < 0)
	    throw std::length_error("Given index is out of bounds.");
	if (index >= size_used)
	    throw std::out_of_range("Given index is already unused. Nothing to do.");
	
	for(int i = index; i < size_used - 1; i++) {
	    arr[i] = arr[i + 1];
	}
	size_used--;
    } catch (std::length_error &e) {
	std::cout << "ERROR: " << e.what() << std::endl;
    } catch (std::out_of_range &e) {
	std::cout << "ERROR: " << e.what() << std::endl;
    }
}
