//Adapt that program to find anagrams that use only a subset of characters
#include<iostream>
#include<fstream>
#include<algorithm>

using namespace std;

string dictionary,str,dictionary_sort,str_sort;

void sort(string, string);
void find_anagrams();

int main() 
{

	//Reading file
	
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

	cout<<"\nWords present in the anagram are :\n";

	while(!file.eof()){
		getline(file, dictionary);
		sort(dictionary, str);
		find_anagrams();
	}

	cout<<"\n";

	return 0;
}

//sort letters

void sort(string dictionary, string str)
{
	dictionary_sort = dictionary;
	str_sort = str;
	sort(dictionary_sort.begin(), dictionary_sort.end());
	sort(str_sort.begin(), str_sort.end());

}

void find_anagrams()
{
	int i,j, count;
	j=count=0;

	for(i = 0; i<str.length(); i++) {
    	char c = str_sort[i];
    	char w = dictionary_sort[j];
    	if (c==w) {
    		++count;
    		++j;
    	}
	}

	if (count==dictionary_sort.length())
		cout<<dictionary<<"\t";

}


