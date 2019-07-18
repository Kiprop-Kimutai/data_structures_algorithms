var buf2 = [];
function getBytesFromCOcteString(message,length,encoding) {
  console.log(message);
  let str = "".concat(message);
  console.log(str);
  var encoding = encoding;
  var length = length;
	//perfom sanity checks
	if(message == null || message.length < length) {
		return new Error('out of range exception !!');
	}
	var myBuffer = [];
	var buffer =  new Buffer.from(message.toString(), encoding);
	for (var i = 0; i < buffer.length; i++) {
    myBuffer.push(buffer[i]);
	}
  console.log(myBuffer);
	return myBuffer;
}

function getBytesFromString(message,length,encoding) {
	var myBuffer = [];
	var buffer =  new Buffer.from(message.toString(), encoding);
	for (var i = 0; i < buffer.length; i++) {
	    myBuffer.push(buffer[i]);
	}
  console.log(myBuffer);
	return myBuffer;
}

function finalOps() {
//concatenate buffers
buf2 = [...getBytesFromCOcteString("ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789\0","ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789\0".length,'ascii'), ...getBytesFromString("abcdefghijklmnopqrstuvwxyz","abcdefghijklmnopqrstuvwxyz".length, 'ascii')];

const test = Buffer.allocUnsafe(buf2.length);
for(var i = 0; i<buf2.length; i++) {
  test[i] = buf2[i];
}
console.log(String.fromCharCode.apply(null,buf2)); //array implementation
console.log(test.toString('ascii',0,buf2.length)); //buffer implementation
}

finalOps();
 
