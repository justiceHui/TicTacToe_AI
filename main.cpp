#include "TTT.hpp"

//https://gist.github.com/MatthewSteel/3158579
//http://mllab.tistory.com/137

int main(){
	do{
		TicTacToe ttt;
		//ttt.printMap();
		//printf("%d", ttt.isWin());
		int first; //0 player 1 cpu
		printf("���� ���� �����ұ��? (0: �÷��̾�, 1: ��ǻ��)");
		do{
			scanf("%d", &first);
			if(first != 0 && first != 1){
				printf("\n�ٽ� �Է����ּ���.");
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
			case 0: printf("���º�\n\n"); break;
			case 1: printf("��ǻ�� ��\n\n"); break;
			case -1: printf("�÷��̾� ��\n\n"); break;
		}
		char flag;
		printf("�ٽ� �Ͻðڽ��ϱ�? (y, n)");
		do{
			scanf("%c", &flag);
			if(flag!='y' && flag!='Y' && flag!='n' && flag!='N') printf("\n�ٽ� �Է����ּ���.");
			else break;
		}while(1);
		if(flag=='N' || flag=='n') break;
		else system("cls");
	}while(1);
}
