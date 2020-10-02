# *Quick Sort Algorithm*

The Quick sort is based upon divide and conquer algorithm. This algorithm picks a pivot element divides the array in 
two halves and put the smaller elements to one side and larger to the other side it recursively put those all elements 
to their respective sides so that the array becomes sorted.

### The Quick Sort algorithm can be explained in following steps.
1. Partition the array
    1. The pivot element can be chosen in various ways as the first, last or any other element.
        it is put in its right place and the smaller and larger elements to its either sides.
2. Sort the array.
     1. The elements recursively partition themselves and put the pivot element at the right place until the array 
     is sorted.
     
### Analysis of quick sort algorithm

The general time taken by the algorithm is:
   <br> <code>T(n) = T(0) + T(n-1) + &Theta;(n)</code>
   
<strong>Worst Case:</strong> The worst case is when the partition function always chooses either the largest or the
 smallest element as pivot element. If we consider that last element is always picked as the pivot element,
 the worst case might occour when the array is already sorted. 
 <br> <code>T(n) = T(0) + T(n-1) + &Theta;(n)</code>
 is equivalent to 
 <br> <code>T(n) = T(n-1) + &Theta;(n)</code>
 The solution of above recurrence is: O(n<sup>2</sup>)
 
 <strong>Best Case:</strong> The best case occurs when the partition process always picks the middle element as pivot. Following is recurrence for best case.
    <br>
  <code>T(n) = 2T(n/2) + &Theta;(n)</code>
  <br>
 The solution of above recurrence is &Theta;(nLog n)