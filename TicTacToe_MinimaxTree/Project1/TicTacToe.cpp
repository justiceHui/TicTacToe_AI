#include "TicTacToe.h"
using namespace std;

TTT::TTT() {
	for (int i = 0; i<3; i++) for (int j = 0; j<3; j++) map[i][j] = '-';
}

void TTT::print() {
	cout << "----------\n";
	for (int i = 0; i<3; i++) {
		for (int j = 0; j<3; j++) {
			cout << ((map[i][j]) != '-' ? (char)map[i][j] : (char)(i * 3 + j + 1 + '0'));
			if (j != 2) cout << " | ";
			else cout << '\n';
		}
		cout << "----------\n";
	}
	cout << "\n\n";
}

bool TTT::win(char c) {
	for (int i = 0; i<3; i++) {
		if (map[i][0] == c && map[i][1] == c && map[i][2] == c) return true;
		if (map[0][i] == c && map[1][i] == c && map[2][i] == c) return true;
	}

	if (map[0][0] == c && map[1][1] == c && map[2][2] == c) return true;
	if (map[0][2] == c && map[1][1] == c && map[2][0] == c) return true;

	return false;
}

bool TTT::isEnd() {
	if (win(me) || win(cpu)) return true;
	for (int i = 0; i<3; i++) for (int j = 0; j<3; j++) if (map[i][j] == '-') return false;
	return true;
}

int TTT::score() {
	if (win(me)) return 10;
	if (win(cpu)) return -10;
	return 0;
}

void TTT::play() {
	int input;
	do {
		cout << "you first : 1, AI first : 2\ninput : ";
		cin >> input;
	} while (input != 1 && input != 2);

	if (input == 1) first = me;
	if (input == 2) first = cpu;

	print();

	int turn = 0;
	while (!isEnd()) {
		if (turn % 2 == 0) {

			if (first == me) {
				playerMove();
				turn++;
				print();
				if (win(me)) {
					cout << "You Win" << '\n';
					return;
				}
			}
			else {
				p move = minimax(map);
				cout << "AI move : " << (move.first * 3 + move.second + 1) << '\n';

				map[move.first][move.second] = cpu;
				turn++;
				print();
				if (win(cpu)) {
					cout << "AI Win" << '\n';
					return;
				}
			}

		}
		else {

			if (first == me) {
				cout << "AI move : ";
				p move = minimax(map);
				cout << (move.first * 3 + move.second + 1) << '\n';
				map[move.first][move.second] = cpu;
				turn++;
				print();
				if (win(cpu)) {
					cout << "AI Win" << '\n';
					return;
				}
			}
			else {
				playerMove();
				turn++;
				print();
				if (win(me)) {
					cout << "You Win" << '\n';
					return;
				}
			}

		}
	}
	cout << "Draw" << '\n';
	return;
}

void TTT::playerMove() {
	int pos = -1;
	int x = -1, y = -1;
	do {
		cout << "enter your move ex)5 \n";
		cout << "input : ";
		cin >> pos;
		//cin >> x >> y;
		x = (pos - 1) / 3;
		y = (pos - 1) % 3;
	} while (x < 0 || x > 2 || y < 0 || y > 2 || map[x][y] != '-');
	map[x][y] = me;
}

p TTT::minimax(char tmpMap[3][3]) {
	int bestScore = 100;
	p bestMove;

	for (int i = 0; i<3; i++) {
		for (int j = 0; j<3; j++) {
			if (tmpMap[i][j] != '-') continue;
			tmpMap[i][j] = cpu;
			int tmpScore = maximum(tmpMap);
			if (tmpScore <= bestScore) {
				bestScore = tmpScore;
				bestMove = make_pair(i, j);
			}
			tmpMap[i][j] = '-';
		}
	}
	return bestMove;
}

int TTT::minimum(char tmpMap[3][3]) {
	if (isEnd()) return score();

	int bestScore = 500;
	p bestMove;

	for (int i = 0; i<3; i++) {
		for (int j = 0; j<3; j++) {
			if (tmpMap[i][j] != '-') continue;
			tmpMap[i][j] = cpu;
			int tmpScore = maximum(tmpMap);
			if (tmpScore <= bestScore) {
				bestScore = tmpScore;
				bestMove = make_pair(i, j);
			}
			tmpMap[i][j] = '-';
		}
	}
	return bestScore;
}

int TTT::maximum(char tmpMap[3][3]) {
	if (isEnd()) return score();

	int bestScore = -500;
	p bestMove;

	for (int i = 0; i<3; i++) {
		for (int j = 0; j<3; j++) {
			if (tmpMap[i][j] != '-') continue;
			tmpMap[i][j] = me;
			int tmpScore = minimum(tmpMap);
			if (tmpScore >= bestScore) {
				bestScore = tmpScore;
				bestMove = make_pair(i, j);
			}
			tmpMap[i][j] = '-';
		}
	}
	return bestScore;
}