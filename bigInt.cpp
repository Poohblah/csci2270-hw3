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
    bigIntArray = new char[2];
    bigIntArray[0] = '0';
    bigIntArray[1] = '\0';
}

//"c_str" constructor
bigInt::bigInt(const char initialValue [])
{
    //make your bigInt array equal to this c_str
    //being passed in  (i.e. use strlen to allocate
    //memory (remember to add +1 to it though for the null character...
    // and strcpy to copy the stuff over (strcpy adds the null automatically)
    int numc = strlen(initialValue);
    bigIntArray = new char[numc+1];
    strcpy(bigIntArray, initialValue);
}

void bigInt::int2bint(int input) {
    int numc;
    if (input > 0) { numc = log10(input) + 2; } else { numc = 2; }
    bigIntArray = new char[numc];
    int curi = numc - 2;
    while (curi >= 0) {
        char curc = '0' + input % 10; 
        bigIntArray[curi] = curc;
        curi -= 1;
        input /= 10;
    }
    bigIntArray[numc - 1] = '\0';
}

//"integer" constructor
bigInt::bigInt(int initialValue)
{
    //use a loop to count the numberOfDigits in initial value
    //Allocate that memory and copy it over (that good ol divide
    //by 10 and modulo 10 thing
    int2bint(initialValue);
}

//"double" constructor
bigInt::bigInt (double initialValue)
{
    //very similar to the integer constructor strategy above
    //in fact you get this into an int and you can use the same
    //code...    
    int i = initialValue;
    int2bint(i);
}

//Copy Constructor
bigInt::bigInt (const bigInt& toCopyFrom)
{
    //use the getBigIntArray on toCopyFrom to set bigIntArray of you object
    //remember to delete bigIntArray of your object BEFORE setting it
    //or else you'll get a memory leak 

    // delete if we've already allocated? but this is a constructor
    *this = toCopyFrom;
}

bigInt::~bigInt()
{
    //delete your bigIntArray
    delete[] bigIntArray;
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

int bigInt::length() const {
    // returns the number of digits in the bint
    // sanity checks here
    return strlen(bigIntArray);
    // int n = 0;
    // char c = bigIntArray[0];
    // while (c != '\0') {
    //     n += 1;
    //     c = bigIntArray[n];
    // }
    // return n;
}

int bigInt::compare(const bigInt &operand) const {
    int diff = this->length() - operand.length();
    if (diff > 0) { return 1; }
    else if (diff == 0) { return strcmp(this->getBigIntArray(), operand.getBigIntArray()); }
    else { return -1; }
}


//operator "="
void bigInt::operator = (const bigInt& toEqual)
{
    //use getBigIntArray on toEqual to set your int array to 
    //the intArray of toEqual    
    int numc = toEqual.length();
    bigIntArray = new char[numc + 1];
    bigIntArray = toEqual.getBigIntArray();  
}

//operator "=="
bool operator ==(const bigInt &firstInt, const bigInt &secondInt)    
{
    //check to see if the bigIntArray's are equal
    //you can use strcmp for this
    return firstInt.compare(secondInt) == 0;
}

//operator !=
bool operator !=(const bigInt &firstInt, const bigInt &secondInt)
{
    //easy once you've done ==
    return !(firstInt == secondInt);
}

//operator <
bool operator <(const bigInt &firstInt, const bigInt &secondInt)
{
    //Not too bad, think about it...
    return firstInt.compare(secondInt) < 0;
}

//operator >
bool operator >(const bigInt &firstInt, const bigInt &secondInt)
{
    //you've done equals and <, so this should be easy
    return firstInt.compare(secondInt) > 0;
}

//operator <=
bool operator <=(const bigInt &firstInt, const bigInt &secondInt)
{
    //if it's not greater than..
    return !(firstInt > secondInt);
}

//operator >=
bool operator >=(const bigInt &firstInt, const bigInt &secondInt)
{
    //if it's not less than...
    return !(firstInt < secondInt);
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
    
    // gonna do this the horribly slow and inefficient way
    const char* bint1 = firstInt.getBigIntArray();
    const char* bint2 = secondInt.getBigIntArray();

    // cout << "Here are the things we are adding: " << bint1 << ", " << bint2 << endl;

    // first allocate memory, make sure we have enough for the largest of the two + 1 digit
    int size;
    int size1 = firstInt.length();
    int size2 = secondInt.length();
    if (size1 > size2) { size = size1; }
    else { size = size2; }
    size += 1; 
    char* const result = new char[size+1];
    result[size] = '\0';
    // for (int i = 0; i < size; i++) { result[i] = 'X'; }
    // cout << "Here is the result before adding: " << result << " and the size is: " << size << endl;

    // next add digit by digit
    int i = size - 1;
    int i1 = size1 - 1;
    int i2 = size2 - 1;
    int carry = 0;
    while ( (i1 >= 0) || (i2 >= 0) ) {
        // cout << "Indices: i: " << i << " i1: " << i1 << " i2: " << i2 << endl;
        // get the digits at the current index and convert them to ints
        int n; int m;
        if (i1 >= 0 ) { n = bint1[i1] - '0'; } else { n = 0; }
        if (i2 >= 0 ) { m = bint2[i2] - '0'; } else { m = 0; }
        
        // add the ints and the carry
        int sum = n + m + carry;
        char c = sum % 10 + '0';
        carry = sum / 10;

        // put the result into our bint
        // cout << "Here is the current digit: " << c << endl;
        result[i] = c;

        // decrement and move on
        i--; i1--; i2--;
    }

    // finally, make sure the first digit is set correctly
    // cout << "Here is the result: " << result << endl;
    if (carry == 0) {
        return bigInt(result + 1);
    } else { 
        result[0] = carry + '0';
        return bigInt(result);
    }
}   



void bigInt::operator += (const bigInt& intToAdd)
{
    //now that you've done add,  you can use a temporary bigInt
    //and the "this" pointer to add your current object to 
    //intToAdd. then you can use getbigIntArray on the temp
    //to set "this" big int array, possibly cleaning up
    //memory along the way...
    bigInt* bint = new bigInt;
    *bint = *this + intToAdd;
    delete[] this->bigIntArray;
    this->bigIntArray = bint->getBigIntArray();
}

bigInt operator -(const bigInt &firstInt, const bigInt &secondInt)
{
    //Think about this....
    
    // gonna do this the horribly slow and inefficient way
    const char* bint1 = firstInt.getBigIntArray();
    const char* bint2 = secondInt.getBigIntArray();

    // first allocate memory
    int size;
    int size1 = firstInt.length();
    int size2 = secondInt.length();
    if (size1 > size2) { size = size1; }
    else { size = size2; }
    char* const result = new char[size + 1];
    result[size] = '\0';
    for (int i = 0; i < size; i++) { result[i] = '0'; }
    // cout << "Here is the result before subtracting: " << result << endl;

    // next subtract digit by digit
    int i = size - 1;
    int i1 = size1 - 1;
    int i2 = size2 - 1;
    int carry = 0;
    while ( (i1 >= 0) || (i2 >= 0) ) {
        // cout << "Indices: i: " << i << " i1: " << i1 << " i2: " << i2 << endl;
        // get the digits at the current index and convert them to ints
        int n; int m;
        if (i1 >= 0 ) { n = bint1[i1] - '0'; } else { n = 0; }
        if (i2 >= 0 ) { m = bint2[i2] - '0'; } else { m = 0; }
        
        // subtract the ints and the carry
        int diff = n - m + carry;
        char c = (diff + 10) % 10 + '0';
        (diff < 0) ? carry = (diff / 10) - 1 : carry = 0;
        // carry = (diff - 10) / 10;
        // cout << "Carry value: " << carry << endl;

        // put the result into our bint
        // cout << "Here is the current digit: " << c << endl;
        result[i] = c;

        // decrement and move on
        i--; i1--; i2--;
    }

    // cout << "-6 % 10 = " << -6 % 10 << endl;
    // cout << "-2 / 10 = " << -2 / 10 << endl;
    // cout << "-2.0 / 10.0 = " << -2.0 / 10.0 << endl;

    // let's get rid of those first digits
    // cout << "Here is the result so far: " << endl;

    i = 0;
    char c = result[i];
    while (c == '0' && i < (size - 1)) {
        i++;
        c = result[i];
    }
    return bigInt(result + i);
}

void bigInt::operator -= (const bigInt& intToSubtract)
{
    //If you've done minus, this should be easy
    //you can even use the this ptr.
    bigInt* bint = new bigInt;
    *bint = *this - intToSubtract;
    delete[] this->bigIntArray;
    this->bigIntArray = bint->getBigIntArray();
}

// extra credit operators

bigInt operator *(const bigInt &firstInt, const bigInt &secondInt) {
    // take care of base case / sanity check first
    bigInt zero = bigInt("0");
    if (firstInt == zero || secondInt == zero) { return zero; }
    
    // now we do long multiplication!
    // take each digit from each number, multiply together,
    // add appropriate # of zeros to the end, and sum it all up!

    bigInt product = zero;
    char *bint1 = firstInt.getBigIntArray();
    char *bint2 = secondInt.getBigIntArray();

    for (int i = 0; i < firstInt.length(); i++) {
        for (int j = 0; j < secondInt.length(); j++) {
            // declare variable which will hold our intermediate
            char prodc_str[(firstInt.length() - i) + (secondInt.length() - j)];
            prodc_str[0] = '\0';

            // intermediate number is the product of the two
            // can get it using ints and multiplying
            int m1 = bint1[i] - '0';
            int m2 = bint2[j] - '0';
            int prod = m1 * m2;

            char tens[2];
            char ones[2];
            
            if (prod < 10) {
                tens[0] = '\0';
                ones[0] = prod + '0';
            } else {
                tens[0] = (prod / 10) + '0';
                ones[0] = (prod % 10) + '0';
            }

            tens[1] = '\0'; ones[1] = '\0';

            strcat(prodc_str, tens);
            strcat(prodc_str, ones);

            // now we add trailing zeros
            int zeros = (firstInt.length() - i - 1) + (secondInt.length() - j - 1);
            for (int z = 0; z < zeros; z++) { strcat(prodc_str, "0"); }

            // and finally add to our total.
            // cout << " tens: " << tens << " ones: " << ones << " zeros: " << zeros << endl;
            // cout << " intermediate: " << prodc_str << endl;
            product += bigInt(prodc_str);
        }
    }

    return product;
}

bigInt operator /(const bigInt &firstInt, const bigInt &secondInt) {
    // a division algorithm made up by me for decimal division
    // Q = N / D where Q is the quotient, N is the numerator, and D is the denominator
    // basically, multiply N by 10 until the numbers are close
    // then perform repeated subtraction to figure out the rest.
    // It's not particularly efficient, but it's more efficient than repeated subtraction
    // and it's easier to code than pretty much any other division algorithm that I know of
    bigInt zero = bigInt(0);
    bigInt one = bigInt(1);
    
    // base case = N is zero, D is 1, N ==D, or N < D
    if (firstInt == zero) { return zero; }
    if (secondInt == one) { return firstInt; }
    if (firstInt == secondInt) { return one; }
    if (secondInt > firstInt) { return zero; }

    bigInt Q = zero;
    bigInt D = secondInt;
    bigInt N = firstInt;

    // now let's do the whole divide-by-ten thing
    int Nbase = N.length();
    int Dbase = D.length();
    int basediff = Nbase - Dbase - 1;
    if (basediff > 0) {
        // figure out how many zeros we need to add, then add them
        bigInt base = one;
        for (bigInt i = one; i < basediff; i += one) { base = base * bigInt(10); }

        return ((N - (base * D)) / D) + base;
    }

    // here's the repeated subtraction bit
    while (D < N) {
        Q += one;
        D += secondInt;
    }

    return Q;
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

