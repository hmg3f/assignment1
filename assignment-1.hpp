#pragma once

// pre: pass this function a value to search for, an array to search in, and the
//   size of that array.
// post: returns the index of the array that contains the given value if it appears
//   in the array. return -1 otherwise.
int int_in_array(int value, int array[], int size);

// pre: pass this function a value to replace an element by, the index of the element
//   that should be replaced, the array, and the size of the array.
// post: returns nothing. this function modifies the array by replacing the value at
//   /index/ with /value/.
void replace_at_index(int value, int index, int arr[], int size);

// pre: pass this function a value, an array to add the value to, the size of the
//   array currently being used, and the maximum total size of the array.
// post: adds value to the end of the array and increases size_used.
void add_to_array(int value, int arr[], int &size_used, int size_total);

// pre: pass this function an index corresponding to an element in the array that
//   should be removed, the size of the array that is currently bein used, and the
//   total maximum size of the array.
// post: removes the element of the array at index, and shift all elements to the
//   right of index over by one. decrease the value of size_used.
void remove_from_array(int index, int arr[], int &size_used, int size_total);
