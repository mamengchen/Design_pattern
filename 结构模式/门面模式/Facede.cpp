#include <iostream>
using namespace std;

class Carmera {
public:
	void turnOn()
	{
		cout << "�������" << endl;
	}

	void turnOff()
	{
		cout << "����ر�" << endl;
	}
};

class Light {
public:
	void turnOn()
	{
		cout << "�����ƹر�" << endl;
	}
	void turnOff()
	{
		cout << "�����ƹر�" << endl;
	}
};

class Sensor {
public:
	void active()
	{
		cout << "������ϵͳ" << endl;
	}

	void deactive()
	{
		cout << "�������ر�" << endl;
	}
};

class Alarm {
public:
	void action()
	{
		cout << "����������" << endl;
	}

	void deactive()
	{
		cout << "�������ر�" << endl;
	}
};

class SecuritFacade
{
public:
	SecuritFacade()
	{
		Carmera* pCarmera = new Carmera;
		Light* pLight = new Light;
		Sensor* pSensor = new Sensor;
		Alarm* pAlarm = new Alarm;
	}
	void active()
	{
		pCarmera->turnOn();
		pLight->turnOn();
		pSensor->active();
		pAlarm->action();
	}

	void close()
	{
		pCarmera->turnOff();
		pLight->turnOff();
		pSensor->deactive();
		pAlarm->deactive();
	}
private:
	Carmera* pCarmera;
	Light* pLight;
	Sensor* pSensor;
	Alarm* pAlarm;
};

int main()
{
	/*Carmera* pCarmera = new Carmera;
	Light* pLight = new Light;
	Sensor* pSensor = new Sensor;
	Alarm* pAlarm = new Alarm;
	cout << "����ϵͳ" << endl;
	pCarmera->turnOn();
	pLight->turnOn();
	pSensor->active();
	pAlarm->action();
	cout << "�ر�ϵͳ" << endl;*/
	/* һϵ�йرղ��� �����������и�ȱ����ǿͻ���֪��̫����*/

	SecuritFacade* pv = new SecuritFacade;
	pv->active();
	pv->close();
	system("pause");
	return 0;
}