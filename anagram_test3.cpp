#include<iostream>
#include<fstream>
#include<algorithm>
#include <unordered_map>

using namespace std;

int main() {

	string word = "quuick";
	string sorted_dictionary_word = "quick";

	int q_count_word = count(word.begin(), word.end(), 'q');
	cout<<"\noccurance of q in word : "<<q_count_word;
	int q_count_dictionary = count(sorted_dictionary_word.begin(), sorted_dictionary_word.end(), 'q');
	cout<<"\toccurance of q in dictionary : "<<q_count_dictionary;

	for (int i=0; i<word.length(); i++){
		char c = word[i];
		char w = sorted_dictionary_word[i];

		if ((q_count_word!=0) && (c=='u')) {
			word.erase(i,1);
			--q_count_word;
		}
		if ((q_count_dictionary!=0) && (w=='u')) {
			sorted_dictionary_word.erase(i,1);
			--q_count_dictionary;
		}
	}

	cout<<"\n  word after : "<<word;
	cout<<"\t  dictionary after : "<<sorted_dictionary_word;

	cout<<"\n";

	return 0;

}