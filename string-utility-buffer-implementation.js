/**
	-first approach using ES2017 Buffer object
	-works for both octet and c octet strings
	-encoding can be ascii, utf8, etc
*/
const buf2 = Buffer.allocUnsafe(64);

function getBytesFromCOcteString(message,length,encoding) {
	//perfom sanity checks
	if(message = null && message.length < length) {
		return new Error('out of range exception !!');
	}
	var myBuffer = Buffer.allocUnsafe(message.length);
	var buffer =  new Buffer.from(message.toString(), encoding);
	for (var i = 0; i < buffer.length; i++) {
    myBuffer[i] = buffer[i];
	}
	return myBuffer;
}

/**
	-second approach would still work for both C Octet and Octet strings
	-will not employ buffer object, but instead use javascript Array object
*/
function getBytesFromString(message,length,encoding) {
	var myBuffer = [];
	var buffer =  new Buffer.from(message.toString(), encoding);
	for (var i = 0; i < buffer.length; i++) {
	    myBuffer.push(buffer[i]);
	}
	return myBuffer;
}

function getStringfromBytes(byteArray, offset, length, encoding) {
	return myBuffer.toString(encoding,offset,myBuffer.length);

}

function getOctetStringFromBytes(byteArray, offset, length, encoding) {
	return myBuffer.toString(encoding,offset,myBuffer.length-1);

}

/**
	-concatenate both array buffers to one ouput stream
*/

function WriteToOuputStream() {
	getBytesFromCOcteString("ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789\0","ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789\0".length,'ascii').copy(buf2,0,0,37);
	getBytesFromString("abcdefghijklmnopqrstuvwxyz","abcdefghijklmnopqrstuvwxyz".length, 'ascii').copy(buf2,38,0,26);
	console.log(buf2.toString('ascii',0,64));
}