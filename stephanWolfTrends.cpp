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