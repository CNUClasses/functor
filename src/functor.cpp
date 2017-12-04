//============================================================================
// Name        : functor.cpp
// Author      : 
// Version     :
// Copyright   : Steal this code!
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <assert.h>
#include <vector>
#include <algorithm>

using namespace std;

// this is a functor (acts like a function because of operator())
struct add_x {
	add_x(int x) :
			x(x) {
	}
	int operator()(int y) const {
		return x + y;
	}

private:
	int x;
};

int main() {
	// Now you can use it like this:
	add_x add42(42); // create an instance of the functor class
	int i = add42(8); // and "call" it
	assert(i == 50); // and it added 42 to its argument

	std::vector<int> in; // assume this contains a bunch of values)
	std::vector<int> out(in.size());
	// Pass a functor to std::transform, which calls the functor on every element 
	// in the input sequence, and stores the result to the output sequence
	std::transform(in.begin(), in.end(), out.begin(), add_x(1));
	assert(out[i] == in[i] + 1); // for all i
}
