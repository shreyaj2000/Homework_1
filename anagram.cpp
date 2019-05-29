//optimize to find the highest scoring anagram, rather than just the longest one.
#include<iostream>
#include<fstream>
#include<algorithm>

using namespace std;

string dictionary_word,word,dictionary_word_sort,word_sort,max_word;
int max_score;

void sort(string, string); //sorts the dictionary word and the string entered
bool find_anagrams(); //checks if the dictionary word is present in the string enetered
void calculate_highest_score(); //calculates which dictionary word has the highest score

int main() 
{

	//Reading file
	
	cout<<"\nEnter characters : ";
	cin>>word;
	int length_of_anagram = word.length();

	ifstream file("dictionary.txt", ios::in);
	
	if(!file){
		cout<<"File does not exist."<<endl;
		exit(0);
	}

	//Checking if each word is anagram. Also find highest scoring word

	cout<<"\nAnagrams formed from string are :\n";

	while(!file.eof()){
		getline(file, dictionary_word);
		sort(dictionary_word, word);
		if (find_anagrams()) {
			calculate_highest_score();
		}
	}

	cout<<"\nHighest scoring anagram is "<<max_word<<" with a score of "<<max_score<<"\n";

	return 0;
}

void sort(string dictionary_word, string word)
{
	dictionary_word_sort = dictionary_word;
	word_sort = word;
	sort(dictionary_word_sort.begin(), dictionary_word_sort.end());
	sort(word_sort.begin(), word_sort.end());

}

bool find_anagrams()
{
	int i,j, count,len;
	j=count=len=0;

	for(i = 0; i<word.length(); i++) {
		char c = word_sort[i];
		char w = dictionary_word_sort[j];
		if (c==w) {
			++count;
			++j;
			++len;
		}
	}


	if (count==dictionary_word_sort.length()) {
		cout<<dictionary_word<<"\t";
		return true;
	}
	return false;

}

void calculate_highest_score() {

	int score=0;
	char alphabet[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	int points[26]={1,1,2,1,1,2,1,2,1,3,3,2,2,1,1,2,3,1,1,1,1,2,2,3,2,3};
	int j=0;

	for (int i=0; i<26; i++) {
		char c = dictionary_word_sort[j];
		if (alphabet[i]==c) {
			score+= points[i];
			j++;
			if (c=='q')
				score -=1; //Since Qu is considered as 3 points together, we subtract 1 for the additional u detected
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
		max_word = dictionary_word;
	}
}


