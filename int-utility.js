
//little endian
function kim (num) {
  return [(num & 0xff000000) >> 24,
         (num & 0x00ff0000) >> 16,
         (num & 0x0000ff00) >> 8,
         (num & 0x000000ff)];
}

//big endian
function jonah(num) {
  return [(num & 0x000000ff),(num & 0x0000ff00) >> 8,(num & 0x00ff0000) >> 16,(num & 0xff000000) >> 24];
}
var arr = kim(1);
for(var i = 0; i<4;i++) {
  console.log(arr[i]);
}
console.log("--------------------");
var kibiwot = jonah(1);
for(var i = 0; i<4;i++) {
  console.log(kibiwot[i]);
}

bigEndianByteArrayToLong = function(/*byte[]*/byteArray) {
    var value = 0;
    for ( var i = byteArray.length - 1; i >= 0; i--) {
        value = (value * 256) + byteArray[i];
    }

    return value;
};

littelEndianByteArrayToLongg = function(/*byte[]*/byteArray) {
    var value = 0;
    for ( var i = 0; i <= byteArray.length-1; i++) {
        value = (value * 256) + byteArray[i];
    }

    return value;
};

console.log("----------------------\n");
console.log(byteArrayToLong(jonah(1)));
console.log(byteArrayToLongg(kim(1)));
