/**
 * recursive search algorith
 * recursive search works  for sorted items in a list
 * recusrive function takes parameters; array, begin,end and search item
 */

const array = [16, 19, 20, 23, 45, 56, 78, 90, 96, 100];
function recursiveSearch(array, begin,end,item) {
  var mid =  Math.floor((end+begin)/2);
  if(end >= begin) {
      if(array[mid] == item) {
        return mid;
      }
      else if(array[mid] > item) {
        return recursiveSearch(array,begin, mid-1,item);
      }
      else {
        return recursiveSearch(array,mid+1,end,item);
      }
  }
}
var flag = recursiveSearch(array,0,(array.length-1),100);
if(flag>=0) {
  console.log("match found at position %d\n",flag+1);
}
else {
  console.log("No match found..\n");
}