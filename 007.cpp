/**********************************************
* �ļ�����007.cpp
* �����ˣ�qhy
* ����ʱ�䣺2024.07.11
* ��Ŀ��Դ������Ա���Խ��
* ����������01.07.��ת����
* ���Ӷȷ�����O(N^2)(https://leetcode.cn/studyplan/cracking-the-coding-interview/)
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
		// �����������Ϊ n
		int n = matrix.size();
		// ��ʼ�㷶ΧΪ 0 <= i < n / 2 , 0 <= j < (n + 1) / 2
		// ���� '/' Ϊ��������
		for (int i = 0; i < n / 2; i++) {
			for (int j = 0; j < (n + 1) / 2; j++) {
				// �ݴ� A �� tmp
				int tmp = matrix[i][j];
				// Ԫ����ת���� A <- D <- C <- B <- tmp
				matrix[i][j] = matrix[n - 1 - j][i];
				matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
				matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
				matrix[j][n - 1 - i] = tmp;
			}
		}
	}
};

���ߣ�Krahets
���ӣ�https://leetcode.cn/problems/rotate-matrix-lcci/solutions/1137482/mian-shi-ti-0107-xuan-zhuan-ju-zhen-yuan-8id6/
��Դ�����ۣ�LeetCode��
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
*/