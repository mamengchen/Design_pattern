#pragma once
#include "Express.h"
#include "ExpressNode.h"

class BinaryNode : public ExpressNode {
public:
	friend class Express;
	//BinaryNode(void);
	BinaryNode(char, class Express, class Express);
	~BinaryNode();
private:
	void print(ostream&) const;
	int eval() const;
	char opend;
	class Express left;
	class Express right;
};