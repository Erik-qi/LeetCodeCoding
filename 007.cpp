/**********************************************
* 文件名：007.cpp
* 创建人：qhy
* 创建时间：2024.07.11
* 题目来源：程序员面试金典
* 代码描述：01.07.旋转矩阵
* 复杂度分析：O(N^2)(https://leetcode.cn/studyplan/cracking-the-coding-interview/)
***********************************************/

#include <iostream>
#include <vector>
#include <stack>
#include <sstream>
using namespace std;

class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		int N = matrix.size();

		stack<int> S;
		for (int i = N - 1; i >= 0; i--) {
			for (int j = 0; j < N; j++)
				S.push(matrix[j][i]);
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				matrix[i][j] = S.top();
				S.pop();
			}
		}
	}

};

int main() {
	Solution sol;
	vector<vector<int>> matrix;
	matrix = { {1,2,3},{4,5,6},{7,8,9} };
	sol.rotate(matrix);

	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[0].size(); j++)
			cout << to_string(matrix[i][j]) ;

		cout << endl;
	}

	system("pause");
}

/*Solution2
* class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		// 设矩阵行列数为 n
		int n = matrix.size();
		// 起始点范围为 0 <= i < n / 2 , 0 <= j < (n + 1) / 2
		// 其中 '/' 为整数除法
		for (int i = 0; i < n / 2; i++) {
			for (int j = 0; j < (n + 1) / 2; j++) {
				// 暂存 A 至 tmp
				int tmp = matrix[i][j];
				// 元素旋转操作 A <- D <- C <- B <- tmp
				matrix[i][j] = matrix[n - 1 - j][i];
				matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
				matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
				matrix[j][n - 1 - i] = tmp;
			}
		}
	}
};

作者：Krahets
链接：https://leetcode.cn/problems/rotate-matrix-lcci/solutions/1137482/mian-shi-ti-0107-xuan-zhuan-ju-zhen-yuan-8id6/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/