/**
 * bubble sort
 */

function bubbleSort(arr) {
  var i,j,temp;
  let swapped = false;
  for(i=0;i<arr.length;i++) {
    for(j=i+1;j<arr.length;j++) {
      if(arr[i] > arr[j]) {
        temp = arr[j];
        arr[j] = arr[i];
        arr[i] = temp;
        swapped = true;
      }
    }
    if(!swapped) {
      //list is sorted
      break;
    }
  }
  return arr;
}
console.log(bubbleSort([ 10, 9, 7, 101, 23, 44, 12, 78, 34, 23]));