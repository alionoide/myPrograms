/** *********************************************************************
 * @file 
 *
 * @brief demonstrates the bubble sort, insertion sort, 
 *        and selection sort.
 ***********************************************************************/
 
 /** ********************************************************************
 *
 * @mainpage Program 3 - Simple Sorts
 *
 * @section course_section Course Information
 *
 * @authors Fred Flintstone
 *
 * @date January 31, 2010
 *
 * @par Instructor:
 *         Dr. Slate
 *
 * @par Course:
 *         CSC 150 - Section 3 - 2:00 pm
 *
 * @par Location:
 *         McLaury - Room 313
 *
 * @section program_section Program Information
 *
 * @details This program will make 3 identical arrays using a random number
 * generator. The  function rand returns a number between 0 and 32,767.  This
 * number is then copied into the first location of the three arrays.  Then
 * another number is generated and put into the second location of the arrays.
 * Calls to rand will keep being made until all spots are filled in the arrays.
 * The size of the arrays are provided with the global constant SIZE.
 *
 * After the arrays are filled, we will pass one array to a function that will
 * sort the array using the bubble sort method.  Upon return from this a
 * function will verify that the array was sorted.  If it was not sorted, the
 * program will exit.
 *
 * Because of space, the rest of the details have been omitted.
 *
 * @section compile_section Compiling and Usage
 *
 * @par Compiling Instructions:
 *      None
 *
 * @par Usage:
   @verbatim
   c:\> thpExamX.exe  outputfilename
   d:\> c:\bin\thpExamX.exe outputfilename

        outputfilename - name of the file to output contents of sorted arrays.
   @endverbatim
 *
 * @section todo_bugs_modification_section Todo, Bugs, and Modifications
 *
 * @bug  The isSorted routine has a problem if the first element is not
 * in order (not really though).
 * @bug  Sometimes the arrays fill up with all the same values (not really)
 *
 * @todo Finish documenting with doxygen tags
 * @todo Write a function to generate true random 32 bit integers
 * @todo Modify main to use this new random function
 * @todo Write the code in main to write the arrays out to a file.
 *
 * @par Modifications and Development Timeline:
   @verbatim
   Date          Modification
   ------------  --------------------------------------------------------
   Jan  1, 2011  Started writing the sorts
   Jan 15, 2011  Wrote the isSorted function and found the fictitious  error.
                 Need to generate test cases with the first and last element
                 being out of order.
   Jan 18, 2011  Genereate the random arrays to be sorted.
   Jan 19, 2011  Started learning doxygen
   @endverbatim

   Gitlab commit log, <a href = "https://gitlab.cse.sdsmt.edu/
   rschrade/csc115_examples/-/commits/main" target="_blank">
   Click Here.</a>
 *
 ***********************************************************************/
#include "thpExamX.h"



/** *********************************************************************
 * @author Fred Flintstone
 *
 * @par Description:
 * This is the starting point to the program.  It will retrieve a
 * number form the rand function and place it into three arrays.  Each
 * array will then be sorted using one of three sort techniques,
 * bubble, insertion, and selection.  Upon returning from each sort
 * function the sorted array will then be verified using the isSorted
 * function.  If the array is not in order, a message will be
 * outputted and an error number will be returned.
 *
 * 
 * @param[in] argc - the number of arguments from the command prompt.
 * @param[in] argv - a 2d array of characters containing the arguments.
 *
 * @returns 1 bubble sort failed
 * @returns 2 insertion sort failed
 * @returns 3 selection sort failed
 *
 * @verbatim
   see usage statement above. 
   @endverbatim
 *
 ***********************************************************************/
int main ( int argc, char **argv )
{
    int i;
    int num;

    int barray[SIZE];           // an integer array for the bubble sort
    int iarray[SIZE];           // an integer array for the insertion sort
    int sarray[SIZE];           // an integer array for the selection sort

    // initialize the c++ random number generator
    srand ( ( int ) time ( NULL ) );

    // call the random number generator to retreive a random number
    // then place the random number in all three arrays
    // this will create 3 identical arrays with the same random numbers.
    for ( i = 0; i < SIZE; i++ )
    {
        num = rand();
        barray[i] = num;
        iarray[i] = num;
        sarray[i] = num;
    }

    // call the bubble sort routine to sort the barray
    // upon return, check that the array was correctly sorted
    // if not output error message and exit program.
    bubbleSort ( barray, SIZE );
    if ( !isSorted ( barray, SIZE ) )
    {
        cout << "The array did not get sorted using bubble sort." << endl;
        return 1;
    }

    // call the insertion sort routine to sort the barray
    // upon return, check that the array was correctly sorted
    // if not output error message and exit program.
    insertionSort ( iarray, SIZE );
    if ( !isSorted ( iarray, SIZE ) )
    {
        cout << "The array did not get sorted using insertion sort." << endl;
        return 2;
    }

    // call the selection sort routine to sort the barray
    // upon return, check that the array was correctly sorted
    // if not output error message and exit program.
    selectionSort ( sarray, SIZE );
    if ( !isSorted ( sarray, SIZE ) )
    {
        cout << "The array did not get sorted using selection sort." << endl;
        return 3;
    }

    return 0;
}

