#include "stephanWolfTrends.h"


void stephanWolfTrends::increaseCount(std::string s, unsigned int amount) {

	//index of s, will equal wordCountTable.end() if it doesn't exist.
	int i = wordCountTable.first.find(s);

	if(i = wordCountTable.first.end()) {
		wordCountTable.insert(s, 1);
	} else {