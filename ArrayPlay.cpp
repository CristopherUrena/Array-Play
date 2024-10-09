#include <iostream>
using namespace std;

const int CAPACITY = 20;
/*fillArray - fills an int array with values inputted by the user. 
 * stops reading the input when the user inputs -1 
 * int numArray[] is an array of intergers after leaving such function.
 * int &numElements is the number of elements that are in the array when it is done
 * returns void
*/

void fillArray(int numArray[], int &numElements);

/*Prints the array after every operation is done such as
 * adding a value or delete a value to the array or reversing the array
 * int numArray[] is an array of intergers
 */

void printArray(int numArray[], int numElements);

/*isSorted- determines if the array in is order
 * int numArray[] - is an array of intergers
 * int numElements 
 * returns true if the array is sorted, if it is not it returns false. 
*/

bool isSorted(int numArray[], int numElements);

/*insertValue - inserts the inputted value from the user into the provided array. 
 * if the array is sorted, it will place the value where it belongs, 
 * respecting the way the array is sorted.
 * int insertValue - the value that will be inputted by the user
 */

bool insertValue(int numArray[], int &numElements, int insertValue);

/*finds the insert position for a given value in the ordered array. 
 * int array[] -is an array of given intergers 
 *int insertvalue to find the location of the given value within the array
 *returns index of the position where the function findInArray should be inserted. 
 */

int getInsertPosition(int numArray[], int numElements, int insertValue);

/*removes the given value inputted by the user from the array
 * int array[] - the array of intergers 
 * int &numElements 
 * int insertValue is used to delete the given value
 * returns true if the delete was complete, false if it was not. 
 */

bool deleteFromArray(int numArray[], int &numElements, int deleteValue);

/*findInArray - searches for the provided value given in the array.
 * returns index of findInArray or -1 if the value was not found. 
 */

int findInArray(int numArray[], int numElements, int findValue);

/*sortArray - sorts the value in the array. 
 * returns the array sorted
 */ 

void sortArray(int numArray[], int numElements);
/*reverseArray -reverses the value in the given array 
 * to show from biggest to smallest
 */

void reverseArray(int numArray[], int numElements);

int main()
{

    int numArray[CAPACITY];     // an int array with a given CAPACITY
    // numArray can be partially filled, (so use numElements below
    // to indicate the number of elements in the array)

    int numElements = 0;     // the array is initially empty,
                             // i.e., contains 0 elements
    // The numElements variable will store the actual number of elements
    // stored as the program runs. Where appropriate, your code should
    // update the value of numElements.

    // 1. TODO: Call the fillArray function to collect a number of values
    // from a user.
    fillArray(numArray, numElements);

    // 2. TODO: Call the printArray function.
    	printArray(numArray, numElements);

    // 3. TODO: Call the isSorted function. If the array is sorted, print
    // "Array is sorted\n" otherwise print "Array is not sorted\n"
     if(isSorted(numArray, numElements) == true)
	{
		cout << "Array is sorted\n";	
	}
	else
	{
		cout << "Array is not sorted\n";
	}
    // 4. TODO: Read a value from the user. Use this prompt: "Enter a value
    // to insert: "
    // Call the insertValue function to insert the value obtained from the
    // user.
     int value;
	cout<< "Enter a value to insert: ";
	cin >> value;
	
	insertValue(numArray, numElements, value);
    // 5. TODO: Call printArray
      	printArray(numArray, numElements);


    // 6. TODO: Read a value from a user and then call the deleteFromArray
    // function to delete the value from the array if it is there. Use this
    // prompt: "Enter a value to delete: "
      int deleteValue;	
	cout << "Enter a value to delete: ";
	cin  >> deleteValue;
	if(deleteFromArray(numArray, numElements, deleteValue))
	{
		printArray(numArray,numElements);
	}
    // 7. TODO: Call printArray
     else
	{
		cout << "Not found\n";
		printArray(numArray, numElements);
	}
 
          
    // 8. TODO: Call the sortArray function. 
      if(!isSorted(numArray,numElements))
	{
		sortArray(numArray, numElements);
		printArray(numArray, numElements);
	}
	
    // 9. TODO: Call printArray
      else
	{
		printArray(numArray, numElements);
	}
    // 10. TODO: Call the reverseArray function
     reverseArray(numArray, numElements);
    // 11. TODO: Print the prompt "Reversing the Array is:\n"
    // and then call the printArray function.
       cout << "Reversing the Array is: " << endl;
       	printArray(numArray, numElements);


    return 0;

}

//TODO: Implement all functions as required by the instructions.
    void fillArray(int numArray[], int &numElements)
{
	int input=0;
	numElements = 0;

	cout << "Enter non-negative integers. End with -1: "; 
		
	while(input != -1)
	{	
		cin >> input;
		
		if(input != -1)
		{
		 numArray[numElements++] = input;
		}
	}

}

/*Prints the array after every operation is done such as
 * adding a value or delete a value to the array or reversing the array
 * int numArray[] is an array of intergers
 */
void printArray(int numArray[], int numElements)
{

	for(int i = 0; i < numElements; i++)
	{

		cout << numArray[i] <<  " ";
	}

	cout << endl;

}
/*isSorted- determines if the array in is order
 * int numArray[] - is an array of intergers
 * int numElements 
 * returns true if the array is sorted, if it is not it returns false. 
*/

bool isSorted(int numArray[], int numElements)

{

	for(int i = 0; i < numElements - 1; i++)
	{
		if(numArray[i] > numArray[i+1])
		{
		  return false;
		}

	}
	return true;

}

/*insertValue - inserts the inputted value from the user into the provided array. 
 * if the array is sorted, it will place the value where it belongs, 
 * respecting the way the array is sorted.
 * int insertValue - the value that will be inputted by the user
 */

bool insertValue(int numArray[], int &numElements, int insertValue)
{
	if(!isSorted(numArray, numElements))
	{
		numArray[numElements++] = insertValue;

	}
	else
	{
		int belong = getInsertPosition(numArray, numElements, insertValue);

		for (int j = numElements; j > belong; j--)
		{
		 numArray[j] = numArray[j-1];
		}

		numArray[belong] = insertValue;
		numElements++;

         }
return true;
}
/*finds the insert position for a given value in the ordered array. 
 * int array[] -is an array of given intergers 
 *int insertvalue to find the location of the given value within the array
 *returns index of the position where the function findInArray should be inserted. 
 */

int getInsertPosition(int numArray[], int numElements, int insertValue)
{
	

	for(int i =0; i < numElements; i++)
	{
		if(insertValue < numArray[i])
		{
	         return i;
		}

	}
	return numElements++;
}

/*removes the given value inputted by the user from the array
 * int array[] - the array of intergers
 * int &numElements
 * int insertValue is used to delete the given value
 * returns true if the delete was complete, false if it was not.
 */

bool deleteFromArray(int numArray[], int &numElements, int deleteValue)
{
	int pos = findInArray(numArray,numElements,deleteValue);
	if( pos != -1)
	{
		numArray[pos]= numArray[numElements-1];

		numElements--;
		return true;
	}
	return false;
	
}
/*findInArray - searches for the provided value given in the array.
 * returns index of findInArray or -1 if the value was not found. 
 */

int findInArray(int numArray[], int numElements, int findValue)
{
	
	for(int i = 0; i < numElements; i++)
	{
		if( numArray[i] == findValue)
		{
			return i;
		}
	}

	return -1;

}
/*sortArray - sorts the value in the array. 
 * returns the array sorted
 */

void sortArray(int numArray[], int numElements)
{
	
	for(int i = 0; i < numElements ; i++)
	{
		for(int j = 0; j < numElements - i - 1; j ++)
		{
			if (numArray [j]> numArray[j + 1])
			{
				int switchPos = numArray[j];
				numArray[j] = numArray[j + 1];
				numArray[j+1] = switchPos;
			}
		}

	}
}
/*reverseArray -reverses the value in the given array 
 * to show from biggest to smallest
 */

void reverseArray(int numArray[], int numElements)
{

		for(int i = 0; i< numElements / 2; i++)
		{
			int swap = numArray[i];
			
			numArray[i] = numArray[numElements - i - 1];
			numArray[numElements - i - 1] = swap;

		}
}
