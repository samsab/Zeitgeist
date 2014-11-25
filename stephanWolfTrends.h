#include "Trends.h"

#include <unordered_set>
#include <vector>

class stephanWolfTrends : public Trends {
public:
	//All of these should be the same
	virtual void increaseCount(std::string s, unsigned int amount);
	virtual unsigned int getCount(std::string s);
	virtual std::string getNthPopular(unsigned int n);
	virtual unsigned int numEntries();

protected:
	//Not sure what to do with this
	std::vector<std::pair<int, std::string> > wordCountVector;

	std::unordered_set<std::pair<std::string, int> > wordCountTable;
};
