#include <stdio.h>
#include <stdlib.h>
using namespace std;


class TicTacToe{
	private:
		int map[9]={0}; //0:null 1:O -1:X
		int win[8][3] = {{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};
		
	public:
		char grid(int i);
		void printMap();
		void playerTurn();
		int isWin();
		int danger();
		int good();
		int minimax(int board[9], int player);
		void cpuTurn();
}; 

char TicTacToe::grid(int i){
	switch(i){
		case 0: return ' ';
		case 1: return 'O';
		case -1: return 'X';
		default: return '\0';
	}
}

void TicTacToe::printMap(){
	printf("%c | %c | %c\n", grid(map[0]), grid(map[1]), grid(map[2]));
	printf("--+--+--\n");
	printf("%c | %c | %c\n", grid(map[3]), grid(map[4]), grid(map[5]));
	printf("--+--+--\n");
	printf("%c | %c | %c\n", grid(map[6]), grid(map[7]), grid(map[8]));
	printf("\n\n----------\n\n");
}

void TicTacToe::playerTurn(){
	int a;
	printf("enter number[1 ~ 9]: ");
	do{
		scanf("%d", &a);
		if(map[a-1]!=0) printf("다시 입력해주세요");
		else break;
	}while(1);
	map[a-1]=-1;
	printMap();
	//return a-1;
}

int TicTacToe::isWin(){
	for(int i=0; i<8; i++){
		if(map[win[i][0]] != 0 && map[win[i][0]] == map[win[i][1]] && map[win[i][0]] == map[win[i][2]]) return map[win[i][0]];
	}
	return 0;
}

int TicTacToe::danger(){
	for(int i=0; i<8; i++){
		int cnt=0;
		int tmparr[3]={0, 0, 0};
		if(map[win[i][0]]==-1){
			cnt++;
			tmparr[0]=1;
		}
		if(map[win[i][1]]==-1){
			cnt++;
			tmparr[1]=1;
		}
		if(map[win[i][2]]==-1){
			cnt++;
			tmparr[2]=1;
		}
		if(cnt==2){
			if(tmparr[0]==0 && map[win[i][0]]==0) return win[i][0];
			else if(tmparr[1]==0 && map[win[i][1]]==0) return win[i][1];
			else if(tmparr[2]==0 && map[win[i][2]]==0) return win[i][2];
		}
	}
	return -1;
}

int TicTacToe::good(){
	for(int i=0; i<8; i++){
		int cnt=0;
		int tmparr[3]={0, 0, 0};
		if(map[win[i][0]]==1){
			cnt++;
			tmparr[0]=1;
		}
		if(map[win[i][1]]==1){
			cnt++;
			tmparr[1]=1;
		}
		if(map[win[i][2]]==1){
			cnt++;
			tmparr[2]=1;
		}
		if(cnt==2){
			if(tmparr[0]==0 && map[win[i][0]]==0) return win[i][0];
			else if(tmparr[1]==0 && map[win[i][1]]==0) return win[i][1];
			else if(tmparr[2]==0 && map[win[i][2]]==0) return win[i][2];
		}
	}
	return -1;
}

int TicTacToe::minimax(int board[9], int player){
	if(isWin()!=0){
		return isWin()*player;
	}
	
	int score=-2;
	int next=-1;
	for(int i=0; i<9; i++){ //모든 경우의 수 
		if(board[i]==0){ //비어있을 경우 
			board[i]=player; //일단 착수
			int now=-minimax(board, player*-1);
			if(now > score){ //더 유리하면 
				score=now;
				next=i;
			}
			board[i]=0; //시뮬레이션 종료 
		}
	}
	if(next==-1) return 0;
	return score;
}

void TicTacToe::cpuTurn(){
	int board[9];
	for(int i=0; i<9; i++) board[i]=map[i];
	int next=-1;
	int score=-2;
	for(int i=0; i<9; i++){ //모든 경우의 수 
		if(board[i]==0){
			board[i]=1; //일단 착수 
			int tmp=-TicTacToe::minimax(board, -1); //점수 구하기 
			board[i]=0; //시뮬레이션 종료
			if(tmp > score){
				score=tmp;
				next=i;
			} 
		}
	}
	if(danger()!=-1){
		next=danger();
	}
	if(good()!=-1){
		next=good();
	}
	map[next]=1;
	printMap();
}
