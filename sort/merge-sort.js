/**
 * implement merge sort
 */
'use strict'
 async function merge(arr,begin,end) {
  var mid = Math.floor((end+begin)/2);
  if(end >begin) {
    merge(arr,begin,mid);
    merge(arr,mid+1,end);
    mergeSort(arr,begin,mid,end);
  }
  return true;
}

function mergeSort(arr,begin,mid,end) {
  var i = begin, j = mid+1, k = begin, n = begin;
  let temp = [];

  while(i<=mid && j <=end) {
    if(arr[i] > arr[j]) {
      temp[k] = arr[j];
      j++;
    }
    else {
      temp[k] = arr[i];
      i++;
    }
    k++;
  }
  //any unmoved element in first half
  while(i <= mid) {
    temp[k] = arr[i];
    i++;
    k++;
  }
  while(j <= end) {
    temp[k] = arr[j];
    j++;
    k++;
  }
  //copy elements in temp, back to arr
  while(n<k) {
    arr[n] = temp[n];
    n++;
  }
}

async function testDriver() {
  var a = [10, 9, 7, 101, 23, 44, 12, 78, 34, 23];
  let done = await merge(a,0,a.length-1);
  if(done) {
    var i;
    for(i=0;i<a.length;i++) {
      console.log("%d\n",a[i]);
    }
  }
}

testDriver();