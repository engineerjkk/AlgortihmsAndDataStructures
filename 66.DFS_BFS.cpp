#include<iostream>
#include<queue>
#include<stack>
#include<vector>
using namespace std;
#define VERTEX 80
#define SET 'A'
int visited[VERTEX] = { 0 };
void List(vector<vector<int>> v);
int findPath(vector<int> v);
void DFS(stack<int> s, vector<vector<int>> v, int start);
void BFS(queue<int> q, vector<vector<int>> v, int start);
int main()
{
	vector<vector<int>> vsList;
	queue<int> q;
	stack<int> s;
	int nV, nE;
	cout << "1-1. vertex 입력:";
	cin >> nV;
	cout << "1-2. Edge 입력:" << endl;
	
		for (int i = 0; i < nV; i++)
		{
			vector<int> vList;
			vsList.push_back(vList);
		}
	char a, b;
	while (1)
	{
		cin >> a >> b;
		if (cin.eof()) break;
		vsList[a - SET].insert(vsList[a - SET].begin(), b - SET);
		vsList[b - SET].insert(vsList[b - SET].begin(), a - SET);
	}
	cout << endl;
	List(vsList);
	cout << endl << "3. DFS 운행 결과" << endl;
	DFS(s, vsList, 'A');
	for (int i = 0; i < VERTEX; i++)
		visited[i] = 0;
	cout << endl << "4. BFS 운행 결과" << endl;
	BFS(q, vsList, 'A');
	return 0;
}
void List(vector<vector<int>> v)
{
	cout << "2. 연결리스트" << endl;
	for (int i = 0; i < v.size(); i++)
	{
		cout << (char)(i + SET) << " ";
		for (int j = 0; j < v[i].size(); j++)
			cout << (char)(v[i][j] + SET) << " ";
		cout << endl;
	}
	cout << endl << endl;
}
int findPath(vector<int> v)
{
	int retVal = -1;
	for (int i = 0; i < v.size(); i++)
	{
		if (!visited[v[i]])
		{
			retVal = v[i];
			visited[v[i]] = 1;
			break;
		}
	}
	return retVal;
}

void DFS(stack<int> s, vector<vector<int>> v, int start)
{
	int next = 0;
	int cnt = 1;
	vector<char> dfs;
	s.push(start - SET);
	dfs.push_back((char)start);
	visited[start - SET] = 1;
	while (!s.empty())
	{
		next = findPath(v[s.top()]);
		if (next == -1)
		{
			s.pop();
			continue;
		}
		dfs.push_back((char)(next + SET));
		s.push(next);
	}
	for (int i = 0; i < dfs.size(); i++)
		cout << dfs[i] << " ";
	cout << endl << endl;
}
void BFS(queue<int> q, vector<vector<int>> v, int start)
{
	int cur = 0;
	int next = 0;
	int cnt = 1;
	vector<char> bfs;
	visited[start - SET] = 1;
	q.push(start - SET);
	while (!q.empty())
	{
		cur = next = q.front();
		q.pop();
		bfs.push_back((char)(next + SET));
		while ((next = findPath(v[cur])) != -1)
		{
			q.push(next);
		}
	}
	for (int i = 0; i < bfs.size(); i++)
		cout << bfs[i] << " ";
	cout << endl;
}