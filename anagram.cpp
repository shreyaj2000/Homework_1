//optimize to find the highest scoring anagram, rather than just the longest one.
#include<iostream>
#include<fstream>
#include<algorithm>
#include <unordered_map>

using namespace std;

string max_word;
int max_score;

string sort_dictionary_word(string); //sorts the dictionary word and the string entered
bool find_anagrams(string,string,string); //checks if the dictionary word is present in the string enetered
void calculate_highest_score(string,string); //calculates which dictionary word has the highest score
string remove_qu(string&);

int main() 
{
	string dictionary_word,word,sorted_dictionary_word;
	cout<<"\nEnter characters : ";
	cin>>word;

	//sorting word
	transform(word.begin(), word.end(), word.begin(), ::tolower);
	sort(word.begin(), word.end());
	word = remove_qu(word);

	//Reading file
	ifstream file("dictionary.txt", ios::in);
	
	if(!file){
		cout<<"File does not exist."<<endl;
		exit(0);
	}

	//Checking if each word is anagram. Also find highest scoring word
	cout<<"\nAnagrams formed from string are :\n";

	while(!file.eof()){
		getline(file, dictionary_word);
		sorted_dictionary_word = sort_dictionary_word(dictionary_word);
		sorted_dictionary_word = remove_qu(sorted_dictionary_word);
		if (find_anagrams(dictionary_word,word,sorted_dictionary_word)) {
			calculate_highest_score(dictionary_word,sorted_dictionary_word);
		}
	}

	cout<<"\nHighest scoring anagram is "<<max_word<<" with a score of "<<max_score<<"\n";

	return 0;
}

string sort_dictionary_word(string dictionary_word)
{
	string sorted_dictionary_word = dictionary_word;
	transform(sorted_dictionary_word.begin(), sorted_dictionary_word.end(), sorted_dictionary_word.begin(), ::tolower);
	sort(sorted_dictionary_word.begin(), sorted_dictionary_word.end());
	return sorted_dictionary_word;
}

string remove_qu(string& edit_word) {
	int q_count_word = count(edit_word.begin(), edit_word.end(), 'q');

	for (int i=0; i<edit_word.length(); i++){
		char c = edit_word[i];

		if ((q_count_word!=0) && (c=='u')) {
			edit_word.erase(i,1);
			--q_count_word;
		}
	}

	return edit_word;
}

bool find_anagrams(string dictionary_word, string word, string sorted_dictionary_word)
{
	int i,j, count;
	j=count=0;

	for(i = 0; i<word.length(); i++) {
		char c = word[i];
		char w = sorted_dictionary_word[j];
		if (c==w) {
			++count;
			++j;
		}
	}

	if (count==sorted_dictionary_word.length()) {
		cout<<dictionary_word<<"\t";
		return true;
	}
	return false;
}

void calculate_highest_score(string dictionary_word,string sorted_dictionary_word) {

    
    char alphabet[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    int points[26]={1,1,2,1,1,2,1,2,1,3,3,2,2,1,1,2,3,1,1,1,1,2,2,3,2,3};
    int score = 0;

    unordered_map<char, int> freq;
    for (const char &c: sorted_dictionary_word) {
        freq[c]++;
    }

    for (int i=0;i<26;i++) {
        if (freq.find(alphabet[i])!=freq.end()) {
            score = score + (freq[alphabet[i]]*points[i]);
            if (alphabet[i]=='q')
                score -=(1*freq[alphabet[i]]); //Since Qu is 3 points, we subtract 1 for the additional u detected
        }
    }

   	score += 1;
	score = score*score;

	if (max_score<score) {
		max_score = score;
		max_word = dictionary_word;
	}
}

