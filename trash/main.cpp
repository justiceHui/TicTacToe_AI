#include "TTT.hpp"

//https://gist.github.com/MatthewSteel/3158579
//http://mllab.tistory.com/137

int main(){
	do{
		TicTacToe ttt;
		//ttt.printMap();
		//printf("%d", ttt.isWin());
		int first; //0 player 1 cpu
		printf("누가 먼저 시작할까요? (0: 플레이어, 1: 컴퓨터)");
		do{
			scanf("%d", &first);
			if(first != 0 && first != 1){
				printf("\n다시 입력해주세요.");
			}
			else break;
		}while(1);
		for(int i=0; i<9 && ttt.isWin()==0; i++){
			if(i%2==first){
				ttt.playerTurn();
			}
			else{
				ttt.cpuTurn();
			}
		}
		switch(ttt.isWin()){
			case 0: printf("무승부\n\n"); break;
			case 1: printf("컴퓨터 승\n\n"); break;
			case -1: printf("플레이어 승\n\n"); break;
		}
		char flag;
		printf("다시 하시겠습니까? (y, n)");
		do{
			scanf("%c", &flag);
			if(flag!='y' && flag!='Y' && flag!='n' && flag!='N') printf("\n다시 입력해주세요.");
			else break;
		}while(1);
		if(flag=='N' || flag=='n') break;
		else system("cls");
	}while(1);
}
