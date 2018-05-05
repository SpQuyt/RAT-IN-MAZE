#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <unistd.h>
#include <windows.h>

#define num  7		   //me cung co may hang may cot (trong vi du nay la 1 me cung hinh vuong)
int count = 0;
int visited[num][num]; // check xem o nay da di chua
int maze[num][num] = { // me cung de bai cho
	{1, 1, 0, 1, 1, 1, 1},
	{0, 1, 0, 0, 0, 1, 1},
	{1, 1, 1, 1, 0, 1, 0},
	{0, 1, 0, 1, 1, 1, 1},
	{0, 1, 0, 0, 0, 0, 1},
	{0, 1, 1, 0, 1, 0, 0},
	{0, 0, 0, 0, 1, 1, 1}
};


void display(){
	system ("cls");
	printf("   1 is cell, 0 is block.\n\n\n");
	printf("== ME CUNG ==\n\n");
	for (int i = 0; i < num; i++){
		printf("   ");
		for (int j = 0; j < num; j++){
			printf("%d ", maze[i][j]);
		}
		printf("\n");
	}
	printf("\n== CON DUONG DI SE LA ==\n\n");
	for (int i = 0; i < num; i++){
		printf("   ");
		for (int j = 0; j < num; j++){
			printf("%d ", visited[i][j]);
		}
		printf("\n");
	}
	sleep(1);
}

void gen_path(int row, int col){
	if (row == num-1 && col == num-1){  // den dich roi thi in ra thoi
		//count ++;      // for developer
		visited[row][col] = 1;
		//printf("%d.\n", count);     // for developer
		display();
		printf("\n");
		exit(0);
	}
	else if (row <= num - 1 && row >= 0 && col <= num -1 && col >= 0){ // phai co dieu kien row va col nam trong pham vi me cung
		if (maze[row][col] == 0){  // neu day la block thi bye.
			return;
		}
		else if (visited[row][col] == 1){  // neu path nay da den roi thi bye
			display();
			return;
		}
		else if (maze[row + 1][col] != 1 && maze[row - 1][col] != 1 && maze[row][col + 1] != 1 && maze[row][col - 1] != 1){
			display();
			return;
		}
		else{
			visited[row][col] = 1;
			display();
			gen_path(row, col + 1);
			gen_path(row + 1, col);
			gen_path(row - 1, col);
			gen_path(row, col - 1);
			visited[row][col] = 0; // neu lam het cai ben tren roi thi path nay coi nhu chua den va goi backtracking.
		}	
	}
	
}

int main(){
	for (int i = 0; i < num; i++){
		for (int j = 0; j < num; j++){
			visited[i][j] = 0;
		}
	}
	
	printf("   1 is cell, 0 is block.\n\n\n");
	printf("== ME CUNG ==\n\n");
	for (int i = 0; i < num; i++){
		printf("   ");
		for (int j = 0; j < num; j++){
			printf("%d ", maze[i][j]);
		}
		printf("\n");
	}
	system("pause");
	
	gen_path(0,0); // let's go
}
