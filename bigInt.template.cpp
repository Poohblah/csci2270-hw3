#include<cassert>//provides assert
#include "bigInt.h" //big int class
#include <iostream> //we are adding ostream and istream
#include <cstdlib>
#include <cmath>
#include <sstream>
#include <cstring>
#include <string>
using namespace std;

//Default constructor
bigInt::bigInt()
{
	//a 2 element array with an initial value of zero and a NULL
	//character  ie: 0th element is 0 and 1st element is NULL
}

//"c_str" constructor
bigInt::bigInt(const char initialValue [])
{
	//make your bigInt array equal to this c_str
	//being passed in  (i.e. use strlen to allocate
	//memory (remember to add +1 to it though for the null character...
	// and strcpy to copy the stuff over (strcpy adds the null automatically)
}

//"integer" constructor
bigInt::bigInt(int initialValue)
{
	//use a loop to count the numberOfDigits in initial value
	//Allocate that memory and copy it over (that good ol divide
	//by 10 and modulo 10 thing
}

//"double" constructor
bigInt::bigInt (double initialValue)
{
	//very similar to the integer constructor strategy above
	//in fact you get this into an int and you can use the same
	//code...	
}

//Copy Constructor
bigInt::bigInt (const bigInt& toCopyFrom)
{
	//use the getBigIntArray on toCopyFrom to set bigIntArray of you object
	//remember to delete bigIntArray of your object BEFORE setting it
	//or else you'll get a memory leak 
}

bigInt::~bigInt()
{
	//delete your bigIntArray
}


//Returns a dynamically allocated copy tot he bigIntArray
char* bigInt::getBigIntArray() const
{
	//Implemented to help you.
//RETURNS A POINTER TO A COPY of our bigIntArray
//with memory already allocated. You can set this 
//to another char * etc.
	char *toReturn;
	toReturn=new char[strlen(bigIntArray)+1];
	strcpy(toReturn, bigIntArray);
	return toReturn;
}

//operator "="
void bigInt::operator = (const bigInt& toEqual)
{
	//use getBigIntArray on toEqual to set your int array to 
	//the intArray of toEqual	
}

//operator "=="
bool operator ==(const bigInt &firstInt, const bigInt &secondInt)	
{
	//check to see if the bigIntArray's are equal
	//you can use strcmp for this
}

//operator !=
bool operator !=(const bigInt &firstInt, const bigInt &secondInt)
{
	//easy once you've done ==
}

//operator <
bool operator <(const bigInt &firstInt, const bigInt &secondInt)
{
	//Not too bad, think about it...
}

//operator >
bool operator >(const bigInt &firstInt, const bigInt &secondInt)
{
	//you've done equals and <, so this should be easy
}

//operator <=
bool operator <=(const bigInt &firstInt, const bigInt &secondInt)
{
	//if it's not greater than..
}

//operator >=
bool operator >=(const bigInt &firstInt, const bigInt &secondInt)
{
	//if it's not less than...
}

bigInt operator +(const bigInt &firstInt, const bigInt &secondInt)
{
	//there are many strategies to this I'll outline the one that we
	//did in class here you can use it 
	//or feel free to devise your own way...
	
	//make two temporary char* to hold the bigIntArray of firstInt and secondInt
    //you can use getBigIntArray (temp1 and temp2)
    
    //find out which one of these bigInts is bigger and make a third char*
    //array of that size to hold the result of our add (result)
    
    //start at the final index of temp1 and temp2 and start adding them
    //index by index, placing them in result and decrementing their indexes (I 
    //had two index variables)
    //Remember to add a carry if the last sum was greater or equal to 10
    
    //When the smaller numbers index is negative, then you only add
    //the bigger ones index to the carry and place this in the result
    
    //when you're done (ie index1 and index2 are negative) - if you have a 
    //carry you resize the result array and put a 1 in the front
    
    //finally you create a bigInt with that array and return it
    //before you do remember to deallocate any dynamic memory before the
    //ptr disappears
}   



void bigInt::operator += (const bigInt& intToAdd)
{
	//now that you've done add,  you can use a temporary bigInt
	//and the "this" pointer to add your current object to 
	//intToAdd. then you can use getbigIntArray on the temp
	//to set "this" big int array, possibly cleaning up
	//memory along the way...
}

void operator - (const bigInt& intToSubtract)
{
	//Think about this....
}

void bigInt::operator -= (const bigInt& intToSubtract)
{
	//If you've done minus, this should be easy
	//you can even use the this ptr.
}

//ostream is implemented for you
ostream& operator <<(ostream& outs, const bigInt& source)
{  
	outs<<source.bigIntArray;
	return outs;
}

//istream is implemented for you in a cheating manner
std::istream& operator >>(std::istream& ins, bigInt& target)
{
	delete [] target.bigIntArray;
	string hello;
	ins>>hello;
	bigInt temp(hello.c_str());
	target.bigIntArray=temp.getBigIntArray();
    return ins;
}
