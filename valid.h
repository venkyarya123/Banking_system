#include<iostream>
#include<string.h>
using namespace std;
bool isBalance(float b)
{
	if (b>=5000)
		return true;
	else
		return false;
	
}
bool isNameValid(char a[])
{
	int len = strlen(a);
	for(int i=0 ; i<len ; i++)
	{
		if( (a[i]>=65 && a[i]<=90 ) || (a[i]>=97 && a[i]<=122  ))
			continue;
		else
			return false;
	}
	return true;
}

