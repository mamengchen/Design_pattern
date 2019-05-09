#include <iostream>
#include <string>
#include <vector>
using namespace std;

//������ɫ
enum PieceColor{ BLACK, WHTIE};
struct PiecePos {
	int x;
	int y;
	PiecePos(int a, int b):x(a), y(b)
	{}
};

class Piece {
protected:
	PieceColor m_color;
	PiecePos m_pos;
public:
	Piece(PieceColor color, PiecePos pos) : m_color(color), m_pos(pos)
	{

	}

	~Piece(){
	}

	virtual void draw()
	{}
};

class BlackPiece : public Piece {
public:
	BlackPiece(PieceColor color, PiecePos pos) : Piece(color, pos) {}
	~BlackPiece()
	{}
	void draw() {
		cout << "����һ������" << endl;
	}
};

class WhitePiece : public Piece {
public:
	WhitePiece(PieceColor color, PiecePos pos) : Piece(color, pos) {}
	~WhitePiece()
	{}
	void draw() {
		cout << "����һ������" << endl;
	}
};

class PieceBoard {
public:
	PieceBoard(string black, string white) : m_blackName(black), m_WhiteName(white)
	{}

	~PieceBoard()
	{
		clear();
	}

	void setPiece(PieceColor color, PiecePos pos)
	{
		Piece* pPiece = nullptr;
		if (color == BLACK)
		{
			pPiece = new BlackPiece(color, pos);
			cout << m_blackName << "��" << pos.x << "�� " << pos.y << "����һ��" << endl;
		}
		else
		{
			pPiece = new WhitePiece(color, pos);
			cout << m_WhiteName << "��" << pos.x << "�� " << pos.y << "����һ��" << endl;
		}
		m_vecPiece.push_back(pPiece);
	}

	void clear()
	{
		for (auto iter = m_vecPiece.begin(); iter != m_vecPiece.end(); iter++)
		{
			delete (*iter);
		}
	}
private:
	
	vector<Piece*> m_vecPiece;
	string m_blackName;
	string m_WhiteName;
};