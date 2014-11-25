#include "stephanWolfTrends.h"


void stephanWolfTrends::increaseCount(std::string s, unsigned int amount) {

	bool alreadyExists = false;

	for(auto i = wordCountTable.begin(); i != wordCountTable.end(); i++) {
		if((*i).first == s) {
			(*i).second += amount;
			alreadyExists = true;
		} 
	}
	for(unsigned int i = 0; i < wordCountVector.size(); i++) {
		if(wordCountVector[i].second == s) {
			wordCountVector[i].first += amount;
			alreadyExists = true;
		} 
	}
	if(alreadyExists == false) {
		wordCountTable.insert(make_pair(s, amount));
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