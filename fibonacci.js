function fibonacci(x) {
	if(x == 0) {
		return 0;
	}
	if(x == 1) {
		return 1;
	}
	return (fibonacci(x-1) +fibonacci(x-2));
}

function getFibonacciSeries() {
	//get fibonacci series for numbers between 0 and 10
	for(var i = 0; i< 11; i++) {
		console.log("%d", fibonacci(i));
	}
}