#include <iostream>
#include <cstdio>
#include <utility>
using namespace std;

typedef pair<int, int> p;

const char me = 'X';  //1
const char cpu = 'O'; //-1

class TTT {
private:
	char map[3][3];
	char first;

public:
	TTT();
	void print(); //���� ���
	bool win(char c);
	bool isEnd(); //���� ����
	int score(); //����(��:10 ��:-10 ��:0) 
	void play(); //���� ���� 
	void playerMove(); //�÷��̾� �̵� 
	p minimax(char tmpMap[3][3]); //minimax tree
	int minimum(char tmpMap[3][3]); //min 
	int maximum(char tmpMap[3][3]); //max
};
