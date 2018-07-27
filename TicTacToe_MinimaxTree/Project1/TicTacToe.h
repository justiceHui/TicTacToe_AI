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
	void print(); //보드 출력
	bool win(char c);
	bool isEnd(); //종료 감지
	int score(); //점수(승:10 패:-10 무:0) 
	void play(); //게임 진행 
	void playerMove(); //플레이어 이동 
	p minimax(char tmpMap[3][3]); //minimax tree
	int minimum(char tmpMap[3][3]); //min 
	int maximum(char tmpMap[3][3]); //max
};
