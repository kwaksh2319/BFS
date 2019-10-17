#include<iostream>
#include<Windows.h>
#include<vector>
using namespace std;
int G[9][9] = { {0,1,1,0,0,0,0,0,0},  //0
			   {0,0,0,1,0,1,0,0,0},   //1
			   {0,0,0,0,0,0,1,0,1},   //2
			   {0,1,0,0,1,0,0,0,0},   //3
			   {0,0,0,1,0,1,0,0,0},   //4
			   {0,1,0,0,1,0,0,0,0},   //5
			   {0,0,1,0,0,0,0,1,1},   //6
			   {0,0,0,0,0,0,1,0,0},   //7
			   {0,0,1,0,0,0,1,0,0}    //8

};
vector<int>QueueData;


int BFS(int i,int j) {

	if (QueueData.size() < 1) {
		QueueData.push_back(j);
	}

	if (G[i][j] == 1) {
		for (int k = 0; k < 9; k++) {
			G[k][j] = 0;
		}

		QueueData.push_back(j);
	}


	if (j < 8 ) {
		j = j + 1;
		return BFS(i,j);
	}
	else {
		i=QueueData[0];
		cout << i;
		QueueData.erase(QueueData.begin());
		j = 0;
		if (QueueData.size() < 1) {

			return -1;
		}
		return BFS(i, j);

	}

	


}




int main() {


	BFS(0, 0);

	system("pause");
	return 0;
}