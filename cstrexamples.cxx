//examples of cstring functions
#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
using namespace std;

//All these cstring functions can be found
//http://www.cplusplus.com/reference/cstring/

int main()
{
	char* testString= new char[5];
	
	//cstrings have NULL terminator at the end
	
	for(int i=0; i<4; i++)
	{
		testString[i]='0'+(i+1); //int to char
	}
	testString[4]='\0'; //null terminator
	cout<<testString<<endl; //prints 1234
	
	//Now I'm going to make this int hello into Cstring
	int hello=123456;
	//int to char Arrayone shot-- YOU need to allocate enough
	//memory for every digit before doing this!!
	
	char* testString2= new char [6+1];//IMPORTANT-- must allocate enough for the '\0' character
	
	//we can also use sprintf to make a new cstring from an int without a loop
	sprintf(testString2, "%i", hello); //sprintf automatically appends a null character http://www.cplusplus.com/reference/cstdio/sprintf/
	
	cout<< testString2<<endl; //should cout 123456
	
	//Now I'm going to copy testString2 into testString3
	//strlen does not count the '\0' character so I have to 
	//do the length of testString2+1
	//http://www.cplusplus.com/reference/cstring/strlen/?kw=strlen
	char* testString3= new char [strlen(testString2)+1];
	
	//now we will use strcpy to copy it over 
	//http://www.cplusplus.com/reference/cstring/strcpy/?kw=strcpy
	strcpy(testString3, testString2);
	cout<<testString3<<endl; //should be 123456 again
	
	//Now I'll compare these two strings using strcmp
	//http://www.cplusplus.com/reference/cstring/strcmp/?kw=strcmp
	//IMPORTANT: RETURNS 0 IF THEY ARE EQUAL!!!
	//Returns an integral value indicating the relationship between the strings:
//A zero value indicates that both strings are equal.
//A value greater than zero indicates that the first character that does not match has a greater value in str1 than in str2; And a value less than zero indicates the opposite.
	
	if(strcmp(testString3, testString2)==0)
	{
		cout<< "The last two numbers are equal!"<<endl;
	}
	
	
return 0;
}
