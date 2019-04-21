#include "Express.h"
#include "VlaueNode.h"
#include "UnaryNode.h"
#include "BinarayNode.h"

Express::Express(int a)
{
	p = new ValueNode(a);
}

Express::Express(char c, const Express e)
{
	p = new UnaryNode(c, e);
}

Express::Express(char c, const Express e1, const Express e2)
{
	p = new BinaryNode(c, e1, e2);
}

Express::Express(const Express& e1)
{
	p = e1.p;
	p->setUse(p->getUse() + 1);
}

Express& Express::operator=(const Express& e1)
{
	(e1.p)->setUse((e1.p)->getUse() + 1);
	p->setUse(p->getUse() - 1);
	if (p->getUse() == 0)
		delete p;
	p = e1.p;
	return *this;
}

Express::~Express()
{
	p->setUse(p->getUse() - 1);
	if (p->getUse() == 0)
		delete p;
}

int Express::eval() const
{
	return p->eval();
}