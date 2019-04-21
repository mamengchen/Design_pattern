#include <iostream>
#include <string>
#include <sstream>
using namespace std;

template<class T>
string iToStr(T value)
{
	stringstream ss;
	ss << value;
	return ss.str();
}

class OrderApi {
public:
	virtual int getOrderProductNum() = 0;
	virtual void setOrderProductNum(int num) = 0; 
	virtual string getOrderContent() = 0;

protected:
	OrderApi() {};
};

class HomeOrder : public OrderApi {
public:
	int getOrderProductNum() override
	{
		return m_num;
	}

	void setOrderProductNum(int num) 
	{
		m_num = num;
	}

	string getOrderContent()
	{
		return "本次订单的客户是：" + m_strCustomerName +
			"订单的数量：" + iToStr(m_num) + "订单的id：" + m_strProductId;
	}

	void setCustomerName(string strCustomerName)
	{
		m_strCustomerName = strCustomerName;
	}
	
	string getCustomerName()
	{
		return m_strCustomerName;
	}

	void setProductId(string strProductId)
	{
		m_strProductId = strProductId;
	}

	string getProductId()
	{
		return m_strProductId;
	}
private:
	string m_strCustomerName;
	string m_strProductId;
	int m_num;
};

class AboardOrder : public OrderApi {
public:
	int getOrderProductNum()
	{
		return m_num;
	}

	void setOrderProductNum(int num)
	{
		m_num = num;
	}

	string getOrderContent()
	{
		return "本次订单的客户是：" + m_strCustomerName +
			"订单的数量：" + iToStr(m_num) + "订单的id：" + m_strProductId;
	}

	void setCustomerName(string strCustomerName)
	{
		m_strCustomerName = strCustomerName;
	}

	string getCustomerName()
	{
		return m_strCustomerName;
	}

	void setProductId(string strProductId)
	{
		m_strProductId = strProductId;
	}

	string getProductId()
	{
		return m_strProductId;
	}
private:
	string m_strCustomerName;
	string m_strProductId;
	int m_num;
};

class OrderBusiness {
public:
	void saveOrder(OrderApi* pOrder);
};

void OrderBusiness::saveOrder(OrderApi* pOrder)
{
	//判读一下，工作的数量有无超过200
	while (pOrder->getOrderProductNum() > 200)
	{
		//新建一个订单
		OrderApi* pNewOrder = nullptr;
		if (dynamic_cast<AboardOrder*>(pOrder) != nullptr)
		{
			//创建一个新对象，去暂存我们的目标
			AboardOrder* p2 = new AboardOrder;
			//赋值对象
			AboardOrder* p1 = static_cast<AboardOrder*>(pOrder);
			p2->setOrderProductNum(200);
			p2->setCustomerName(p1->getCustomerName());
			p2->setProductId(p1->getProductId());
			pNewOrder = p2;
		}

		if (dynamic_cast<HomeOrder*>(pOrder) != nullptr)
		{
			//创建一个新对象，去暂存我们的目标
			HomeOrder* p2 = new HomeOrder;
			//赋值对象
			HomeOrder* p1 = static_cast<HomeOrder*>(pOrder);
			p2->setOrderProductNum(200);
			p2->setCustomerName(p1->getCustomerName());
			p2->setProductId(p1->getProductId());
			pNewOrder = p2;
		}

		//原来的订单，保留，只是数量减少200
		pOrder->setOrderProductNum(pOrder->getOrderProductNum() - 200);
		cout << "新订单是：" << pNewOrder->getOrderContent() << endl;
	}
	//不超过200个
	cout << "最终的订单是" << pOrder->getOrderContent() << endl;
}

int main(void)
{
	HomeOrder* pHome = new HomeOrder;
	pHome->setOrderProductNum(512);
	pHome->setCustomerName("mmc");
	pHome->setProductId("数据结构");
	OrderBusiness* pOb = new OrderBusiness();
	pOb->saveOrder(pHome);
	system("pause");
	return 0;
}