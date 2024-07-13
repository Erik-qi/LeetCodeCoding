/**********************************************
* �ļ�����08.cpp
* �����ˣ�qhy
* ����ʱ�䣺2024.07.13
* ��Ŀ��Դ������Ա���Խ��
* ����������01.08.�����
* ���Ӷȷ�����(https://leetcode.cn/studyplan/cracking-the-coding-interview/)
***********************************************/

#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		int M = matrix.size();
		int N = matrix[0].size();

		vector<int> row, column;
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (matrix[i][j] == 0) {
					row.push_back(i);
					column.push_back(j);
				}
			}
		}

		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				auto it1 = find(row.begin(), row.end(), i);
				auto it2 = find(column.begin(), column.end(), j);
				if (it1 != row.end() || it2 != column.end()) {
					matrix[i][j] = 0;
				}
			}
		}
	}
};

int main() {
	Solution sol;
	vector<vector<int>> matrix;
	matrix = { { 1,1,1 },{ 1,0,1 },{ 1,1,1 } };
	sol.setZeroes(matrix);

	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[0].size(); j++)
			cout << to_string(matrix[i][j]);

		cout << endl;
	}

	system("pause");
}