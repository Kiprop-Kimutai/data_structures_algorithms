
/**
 * implement linear search
 * traverse the array and return position of the element that matches search query
 * 
 */

function linearSearch(arr,item, position){
  for(position = 0;position<arr.length; position++) {
    if(arr[position] == item) {
      console.log("match found at position %d", position+1);
      return position+1;
    }
  }
  console.log("no match found..\n");
}

linearSearch([10,20,3,6,8,5,44,33,55,33,54,67,21,37],5,0);