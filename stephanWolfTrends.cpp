#include "stephanWolfTrends.h"


void stephanWolfTrends::increaseCount(std::string s, unsigned int amount) {

	bool alreadyExists = false;

	for(int i = 0; i < wordCountTable.size(); i++) {
		if(wordCountTable[i].first = s) {
			wordCountTable[i].second + amount;
			alreadyExists = true;
		} 
	}
	if(alreadyExists == false) {
		wordCountTable.insert(s, 1);
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