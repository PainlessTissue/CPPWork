/*
	the purpose of this class is to make my own string class to use
	I find the custom stl string class rather inefficient and difficult to use
	so I wanted to see if I could make my own
*/

class String
{
	char *str;

	int sizeOf(const char *); //custom method to return the size of a string

	String(char *string, bool irrelevant);

public:
	String(const char *);
	~String();

	void operator +=(const char *string); //used for more natural string concatinations
	char charAt(int index);
};

