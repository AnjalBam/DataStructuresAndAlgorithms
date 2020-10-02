package algorithms.linearsearch;
/*
All it does is to traverse through all the elements in an array and check if any item matches the given element.
If any element matches it returns the index of the element else returns -1.
 */

public class LinearSearch {
    public static int searchItem(int[] arr, int item) {
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == item) {
                return i;
            }
        }
        return -1;
    }

    public static void main(String[] args) {
//        System.out.println("Hello there!!");
        int[] myArr = {12, 14, 23, 10, 7, 9};
        int result = searchItem(myArr, 7);
        if (result == -1) {
            System.out.println("The Item could not be found!");
        } else {
            System.out.println("The Item found at index " + result);
        }
    }
}
