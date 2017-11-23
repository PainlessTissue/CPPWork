#include "CI_Chapter1.h"
#include "Trace.h"

int main()
{
	CI_Chapter1 a;

	Trace::out("%d\n", a.question2STRING("dangerous fsh", "fish dangerous"));
}