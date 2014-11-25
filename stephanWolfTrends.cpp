#include "stephanWolfTrends.h"

void stephanWolfTrends::increaseCount(std::string s, unsigned int amount) {

	bool alreadyExists = false;

	for(unsigned int i = 0; i < wordCountVector.size(); i++) {
		if(wordCountVector[i].second == s) {
			auto a = wordCountTable.find(make_pair(s, wordCountVector[i].first));
			wordCountTable.erase(a);
			wordCountVector[i].first += amount;
			wordCountTable.insert(make_pair(s, wordCountVector[i].first));
			alreadyExists = true;
		} 
	}
	if(alreadyExists == false) {
		wordCountTable.insert(make_pair(s, amount));
		wordCountVector.insert(wordCountVector.back, make_pair(amount, s));
		bubbleUp(numEntries() - 1);
	}
}

void stephanWolfTrends::bubbleUp(unsigned long i){
	int p = (i - 1) / 2;
	while (i > 0 && wordCountVector[i].first < wordCountVector[p].first) {
		wordCountVector.swap(i, p);
		i = p;
		p = (i - 1) / 2;
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