/** *********************************************************************
 * @file
 *
 * @brief   simple sorts and supporting functions.
 ***********************************************************************/
#include "thpExamX.h"

/** *********************************************************************
 * @author Barney Rubble
 *
 * @par Description:
 * This function receives an array and will process the array placing
 * the elements in order using the bubble sort method.  It moves
 * through the array comparing adjacent items and swapping the
 * elements if they are not in order.  It will make n number of
 * passes.  If it makes a complete pass without swapping two
 * elements, the array is in order and no further processing is
 * required.
 *
 * @param[in,out] arr - the array to be processed.
 * @param[in] arraySize - the number of elements in the array.
 *
 * @returns none
 * 
 * @par Example:
   @verbatim
   int i;
   int array[10] = {50, 34, 22, 19, 766, 190, -45, -15, 0, 10};
   
   bubbleSort( array, 10 );

   for( i = 0; i < 10; i++)
   {
        cout << array[i] << " ";
   }

   output: -45 -15 0 10 19 22 34 50 190 766
   @endverbatim

 ***********************************************************************/
void bubbleSort ( int arr[], int arraySize )
{
    int i, j;
    bool swapMade;  // variable to track if a swap was made during a pass

    // make n-1 passes through the data array moving the largest value
    // towards the end
    for ( i = 0; i < arraySize - 1; i++ )
    {
        // assume no swap has been made
        swapMade = false;

        // move the largest element towards the end
        for ( j = 0; j < arraySize - i - 1; j++ )
        {
            // if element is larger than the next element
            // swap and set the tracking variable to true
            // to indicate a swap was made.
            if ( arr[j] > arr[j + 1] )
            {
                swapMade = true;
                swap ( arr[j], arr[j + 1] );
            }
        }

        // if no swap has been made, list is in order
        // and we can return leave the function
        if ( !swapMade )
            return;
    }
}


/** *********************************************************************
 * @author Fred Flintstone
 *
 * @par Description:
 * Will shift elements up in the sorted half of the array as long
 * as the item is larger than the item being inserted.  Once it
 * encounters an item that is <= to the number being inserted, it
 * will stop shifting and insert the item into the vacated spot.
 * this will happen n number of times in order to insert n items
 * into the array.
 *
 * @param[in,out] arr - the array to be processed.
 * @param[in] arraySize - the number of elements in the array.
 *
 * @returns none
 * @par Example:
   @verbatim
   int i;
   int array[10] = {50, 34, 22, 19, 766, 190, -45, -15, 0, 10};

   insertionSort( array, 10 );

   for( i = 0; i < 10; i++)
   {
        cout << array[i] << " ";
   }

   output: -45 -15 0 10 19 22 34 50 190 766
   @endverbatim 
 ***********************************************************************/
void insertionSort ( int arr[], int arraySize )
{
    int i, j;
    int iValue;

    // the first element is in place, insert the remaining
    // elements into the list.
    for ( j = 1; j < arraySize; j++ )
    {
        // save the next element to be inserted
        iValue = arr[j];
        i = j - 1;

        // travers backwards through the numbers that are in order
        // moving any element that is greater than iValue down.
        // Stop when you understep the array or it is less than or
        // equal to the number being inserted.
        while ( arr[i] > iValue && i >= 0 )
        {
            arr[i + 1] = arr[i];
            i--;
        }

        // place our value into the sorted portion of the array.
        arr[i + 1] = iValue;
    }
}


/** *********************************************************************
 * @author Barney Rubble
 *
 * @par Description:
 * This function receives an array and will process the array looking
 * for any values that are out of order.  The numbers in the array
 * should be ascending order to pass the test.
 *
 * @param[in] arr - the array to be processed.
 * @param[in] arraySize - the number of elements in the array.
 *
 * @returns true - the entire array is in ascending order
 * @returns false - the array is not in ascending order
 * 
 * @par Example:
 * @verbatim
   int arr1[10] = {50, 34, 22, 19, 766, 190, -45, -15, 0, 10};
   int arr2[10] = {-45, -15, 0, 10, 19, 22, 34, 50, 190, 766};

   if( isSorted( arr1, 10 ) )
       cout << "arr1 is sorted" << endl;
   else
       cout << "arr1 is not sorted" << endl;

   if( isSorted( arr2, 10 ) )
       cout << "arr2 is sorted" << endl;
   else
       cout << "arr2 is not sorted" << endl;
   
   output:
       arr1 is not sorted
       arr2 is sorted

   @endverbatim
 ***********************************************************************/
bool isSorted ( int arr[], int arraySize )
{
    int i;

    // traverse through the array comparing element i to element i+1
    // if element i is larger, the array is not in ascending order
    // and we should return false.  If the array is in order,
    // return true
    for ( i = 0; i < arraySize - 1; i++ )
    {
        if ( arr[i] > arr[i + 1] )
            return false;
    }

    return true;
}


/** *********************************************************************
 * @author Fred Flintstone
 *
 * @par Credits:
 *    <a href="http://sdmines.sdsmt.edu/sdsmt/directory/personnel/alogar">
 *    Dr. Antonette Logar</a>
 *    gave us this code in CSC 150. A copy of the code can be found
 *    <a href="http://www.cse.sdsmt.edu/csc150">here.</a>
 *
 * @par Description:
 * This function receives an array and will process the array placing
 * the elements in order using the insertion sort method.  It moves
 * through the array finding the location of the smallest item in
 * the list and swapping the elements if they are not in order.
 * It will make N number of passes doing this where N is the size
 * of the list
 *
 * @param[in,out] arr - the array to be processed.
 * @param[in] arraySize - the number of elements in the array.
 *
 * @returns none
 * @par Example:
   @verbatim
   int i;
   int array[10] = {50, 34, 22, 19, 766, 190, -45, -15, 0, 10};

   selectionSort( array, 10 );

   for( i = 0; i < 10; i++)
   {
        cout << array[i] << " ";
   }

   output: -45 -15 0 10 19 22 34 50 190 766
   @endverbatim 
 ***********************************************************************/
void selectionSort ( int arr[], int arraySize )
{
    int i, j;
    int smallestIndex;

    // make n-1 passes through the array finding
    // the smallest and then the next smallest element
    // in the array and moving it into place.
    for ( i = 0; i < arraySize - 1; i++ )
    {
        // assume this is the smallest element out of remaining
        // elements in the array.
        smallestIndex = i;

        // traverse through all the remaining number looking
        // for a smaller number than the one at the array spot
        // smallest index.
        for ( j = i + 1; j < arraySize; j++ )
        {
            // if an element is less than it, store its index
            if ( arr[j] < arr[smallestIndex] )
            {
                smallestIndex = j;
            }
        }

        // swap the smallest element into position
        swap ( arr[i], arr[smallestIndex] );
    }
}


