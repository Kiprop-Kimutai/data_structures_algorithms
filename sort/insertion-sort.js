/**
 * insertion sort
 */

function insertionSort(arr) {
  var i,j,temp;
  for(i=1;i<arr.length;i++) {
    temp = arr[i];
    j = i-1;
    while( j>=0 && temp <=arr[j]) {
      arr[j+1] = arr[j];
      j--;
    }
    arr[j+1] = temp;
  }
  console.log(arr);
  return arr;
}
insertionSort([12, 11, 13, 5, 6]);