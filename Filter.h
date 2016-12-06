//Filter.h for Programming Fundamentals 2 project.
//Authors (of this file):
// Todd Oakes

#pragma once
#ifndef FILTER_H
#define FILTER_H
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Filter {
private:
	ifstream& in = static_cast<ifstream&>(cin);
	ofstream& out = static_cast<ofstream&>(cout);
	bool isFile = false;
public:
	Filter() {
		//istream& in = cin;
		//ostream& out = cout;
	}
	Filter(ifstream& i, ofstream& o)
	{
		cin.rdbuf(i.rdbuf());
		cout.rdbuf(o.rdbuf());
		ifstream& in = i;
		ofstream& out = o;
		isFile = true;
	}

	void doFilter() {
		
		string s;
		if (!isFile) //writing to command line, so only one line to read
		{
			getline(in, s);
			for(int x = 0; x < s.length(); x++) // not at end-of-line
			{
				
				out.put(transform(s.at(x))); //transform the next char and print it
			}
			out.put('\n');
		}
		while (isFile && getline(in,s)) //writing to a file, not at the end of reading it
		{
			
			for (int x = 0; x < s.length(); x++) // not at end-of-line
			{
				out.put(transform(s.at(x))); //transform the next char and print it
			}
			out.put('\n'); // end of line
		}
		
	};
	virtual char transform(char ch)
	{
		return ch; //dummy function
	};
};

#endif // !Filter
