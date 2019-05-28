//optimize to find the highest scoring anagram, rather than just the longest one.
#include<iostream>
#include<fstream>
#include<algorithm>

using namespace std;

string dictionary,str,dictionary_sort,str_sort,max_word,longest_word;
int max_score,longest_len;

void sort(string, string);
bool find_anagrams();
void calculate_score();

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

	cout<<"\nAnagrams formed from string are :\n";

	while(!file.eof()){
		getline(file, dictionary);
		sort(dictionary, str);
		if (find_anagrams()) {
			calculate_score();
		}
	}

	cout<<"\n\nLongest word formed is "<<longest_word<<" with a length of "<<longest_len<<"\n";
	cout<<"\nHighest scoring anagram is "<<max_word<<" with a score of "<<max_score<<"\n";

	return 0;
}

void sort(string dictionary, string str)
{
	dictionary_sort = dictionary;
	str_sort = str;
	sort(dictionary_sort.begin(), dictionary_sort.end());
	sort(str_sort.begin(), str_sort.end());

}

bool find_anagrams()
{
	int i,j, count,len;
	j=count=len=0;

	for(i = 0; i<str.length(); i++) {
    	char c = str_sort[i];
    	char w = dictionary_sort[j];
    	if (c==w) {
    		++count;
    		++j;
    		++len;
    	}
	}


	if (count==dictionary_sort.length()) {
		cout<<dictionary<<"\t";
		if (longest_len<len) {
			longest_len = len;
			longest_word = dictionary;
		}
		return true;
	}
	return false;

}

void calculate_score() {

	int score=0;
	char alphabet[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	int points[26]={1,1,2,1,1,2,1,2,1,3,3,2,2,1,1,2,3,1,1,1,1,2,2,3,2,3};
	int j=0;

	for (int i=0; i<26; i++) {
		char c = dictionary_sort[j];
		if (alphabet[i]==c) {
			score+= points[i];
			j++;
		}
		else if (c==alphabet[i-1]) {
			score+= points[i-1]; //for words with two of the same letters
			j++;
		}
		else if (c==alphabet[i-2]) {
			score+= points[i-2]; //for words with three of the same letters
			j++;
		}
	}
	score = score*score;

	if (max_score<score) {
		max_score = score;
		max_word = dictionary;
	}
}


