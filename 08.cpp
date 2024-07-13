/**********************************************
* 文件名：08.cpp
* 创建人：qhy
* 创建时间：2024.07.13
* 题目来源：程序员面试金典
* 代码描述：01.08.零矩阵
* 复杂度分析：(https://leetcode.cn/studyplan/cracking-the-coding-interview/)
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