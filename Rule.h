#ifndef _RULE_H_
#define _RULE_H_

#include <string>
#include <vector>
class Rule{
private:
	std::string rule;
	std::vector<int> bVals;
	std::vector<int> sVals;
	void checkGolly(char* golly);
	bool contains(std::vector<int> vec, int num);
	char* convert(std::string text);
public:
	Rule();
	~Rule();
	void conway();
	void golly(std::string  newRule);
	std::string golly();
	bool eval(bool nw, bool n, bool ne, bool w, bool me, bool e, bool sw, bool s, bool se);
	std::vector<int> getBVals();
	std::vector<int> getSVals();

};
#endif //_RULE_H_
