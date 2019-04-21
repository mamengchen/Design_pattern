#include "ExpressNode.h"
#include "VlaueNode.h"
#include "UnaryNode.h"
#include "BinarayNode.h"
#include "Express.h"

int main(void)
{
	Express t = Express(3);
	t = Express('+', t, 12);
	cout << t << "=" << t.eval() << endl;

	Express y = Express('-',4);
	cout << y << "=" << y.eval() << endl;

	Express x = Express('*', Express('-', 4), Express('+', 5, 2));
	cout << x << "=" << x.eval() << endl;
	system("pause");
	return 0;
}