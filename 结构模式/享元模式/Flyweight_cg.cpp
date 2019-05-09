//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//
////对于黑白棋的重构
////棋子颜色
//enum PieceColor { BLACK, WHITE };
//struct PiecePos {
//	int x;
//	int y;
//	PiecePos(int a, int b) :x(a), y(b)
//	{}
//};
//
//class Piece {
//protected:
//	PieceColor m_color;
//
//public:
//	Piece(PieceColor color) : m_color(color){}
//
//	~Piece() {}
//
//	virtual void draw()
//	{}
//};
//
//class BlackPiece : public Piece {
//public:
//	BlackPiece(PieceColor color) : Piece(color) {}
//	~BlackPiece()
//	{}
//	void draw() {
//		cout << "绘制一个黑棋" << endl;
//	}
//};
//
//class WhitePiece : public Piece {
//public:
//	WhitePiece(PieceColor color) : Piece(color) {}
//	~WhitePiece()
//	{}
//	void draw() {
//		cout << "绘制一个白棋" << endl;
//	}
//};
//
//class PieceBoard {
//public:
//	PieceBoard(string black, string white) : m_blackName(black), m_WhiteName(white)
//	{
//		m_pBlackPiece = nullptr;
//		m_pWhitePiece = nullptr;
//	}
//
//	~PieceBoard()
//	{
//		clear();
//	}
//
//	void setPiece(PieceColor color, PiecePos pos)
//	{
//		Piece* pPiece = nullptr;
//		if (color == BLACK)
//		{
//			if (m_pBlackPiece == nullptr)
//				m_pBlackPiece = new BlackPiece(color);
//			cout << m_blackName << "在" << pos.x << "， " << pos.y << "下了一步" << endl;
//			m_pBlackPiece->draw();
//		}
//		else
//		{
//			if (m_pWhitePiece == nullptr)
//				m_pWhitePiece = new WhitePiece(color);
//			cout << m_WhiteName << "在" << pos.x << "， " << pos.y << "下了一步" << endl;
//			m_pWhitePiece->draw();
//		}
//		m_vecPiece.push_back(pos);
//	}
//
//	void clear()
//	{
//		delete m_pBlackPiece;
//		delete m_pWhitePiece;
//	}
//private:
//
//	vector<PiecePos> m_vecPiece;
//	string m_blackName;
//	string m_WhiteName;
//	Piece* m_pBlackPiece;
//	Piece* m_pWhitePiece;
//};
//
//int main1(void)
//{
//	PieceBoard pieceBoard("mmc", "lyy");
//	pieceBoard.setPiece(BLACK, PiecePos(33, 45));
//	pieceBoard.setPiece(WHITE, PiecePos(33, 45));
//	pieceBoard.setPiece(BLACK, PiecePos(1, 1));
//	pieceBoard.setPiece(WHITE, PiecePos(2, 42));
//
//	system("pause");
//	return 0;
//}