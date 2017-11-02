#ifndef _CHAP2
#define _CHAP2

#include "Trace.h"

class Chapter2
{
public:
	Chapter2();
	~Chapter2();

	void question1(); //sums two numbers
	void question2(); //generate companies total revenue
	void question3(); //displays sales tax
	void question4(); //resturant bill
	void question5(); //find average of numbers
	void question7(); //rising sea level calculator
	template <typename T>
	void question9(T); //display size of type (primitive or object)
	void question16(int sizeOfTriangle); //display a triangle of stars
};


// due to linker errors, this has to be inline in the header instead of cpp
template<typename T>
inline void Chapter2::question9(T)
{
	Trace::out("Type size: %i\n", sizeof(T));
}

#endif //header guards
