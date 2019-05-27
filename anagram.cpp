//Make a program that can find 
//single word anagrams that use all the characters in a given string
#include<iostream>
#include<fstream>
#include<algorithm>

using namespace std;

string dictionary;

bool is_anagram(string, string);
void compare();

int main() 
{

	//Reading file

	string str;
	
	cout<<"\nEnter characters : ";
	cin>>str;
	int length_of_anagram = str.length();

	int i=0;

	ifstream file("dictionary.txt", ios::in);
	
	if(!file){
		cout<<"File does not exist."<<endl;
		exit(0);
	}

	//obtain word and length

	while(!file.eof()){
		getline(file, dictionary);
		if (is_anagram(dictionary,str)) {
			cout<<dictionary<<"\t";
		}
	}

	cout<<"\n";

	return 0;
}

//sort letters using ascii values

bool is_anagram(string s1, string s2)
{
	sort(s1.begin(), s1.end());
	sort(s2.begin(), s2.end());
  	return s1 == s2;
}

