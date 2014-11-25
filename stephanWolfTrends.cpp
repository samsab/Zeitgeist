#include "stephanWolfTrends.h"

void stephanWolfTrends::increaseCount(std::string s, unsigned int amount) {
	// Sort through vector pairs. If it's found, increment its amount.
	for(unsigned int i = 0; i < wordCountVector.size(); i++) {
		if(wordCountVector[i].second == s) {
			auto a = wordCountTable.find(make_pair(s, wordCountVector[i].first));
			wordCountVector[i].first += amount;

			wordCountTable.erase(a);
			wordCountTable.insert(a, make_pair(s, wordCountVector[i].first));
			//don't know what to pass here
			//bubbleUp(wordCountTable.find(make_pair(s, wordCountVector[i].first));

			return;
		} 
	}

	// If it is not found, insert it and sort.
	wordCountTable.insert(make_pair(s, amount));
	wordCountVector.insert(wordCountVector.back, make_pair(amount, s));
	bubbleUp(numEntries() - 1);
}

void stephanWolfTrends::bubbleUp(unsigned long i){
	int parent = (i - 1) / 2;
	if (i > 0 && (wordCountVector[parent].first < wordCountVector[i].first)) {
		wordCountVector[parent].swap(wordCountVector[i]);
		bubbleUp(parent);
	}
}

unsigned int stephanWolfTrends::numEntries(){
	return wordCountTable.size();
}

unsigned int stephanWolfTrends::getCount(std::string s){
	//Check to see if word is present
	for (unsigned int i = 0; i < wordCountTable.size(); i++){
		if (wordCountTable[i].first == s){
			//If so, return the count
			return wordCountTable[i].second;
		}
	}
	//otherwise, return 0
	return 0;
}

std::string stephanWolfTrends::getNthPopular(unsigned int n){

	if (n <= numEntries()){
		return wordCountVector[n].second;
	}

	//If they give bad input, return empty string.
	return "";
}
