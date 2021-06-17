#include<queue>
#include<list>
#include<iostream>
using namespace std;
#define NUM 26
struct node
{
	int v;
	int w;
	int t;
};
struct cmp {
	
		bool operator()(struct node n1, struct node n2) {
		bool retVal;
		if (n1.w > n2.w)
			return true;
		else if (n1.w < n2.w)
			return false;
		else
		{
			if (n1.t < n2.t)
				return true;
			else if (n1.t > n2.t)
				return false;
			else
			{
				if (n1.v > n2.v)
					return true;
				else if (n1.v < n2.v)
					return false;
				else return false;
			}
		}
	}
};
void print(list<pair<char, int>>& l) {
	list<pair<char, int>>::iterator d;
	for (d = l.begin(); d != l.end(); d++)
	{
		if (d != l.begin())
			cout << " -> ";
		cout << d->first;
	}
	cout << endl;
}
int min(int a, int b)
{
	return a < b ? a : b;
}
void mst(list<struct node>* l, bool flag)
{
	struct node k, t;
	list<struct node>::iterator it;
	list<pair<char, int>> history;
	priority_queue<struct node, vector<struct node>, cmp> pq;
	int tm[NUM] = { 0 };
	int val[NUM] = { 0 };
	int cnt = 1;
	int sum = 0;
	k.v = 'A';
	k.w = 0;
	pq.push(k);
	while (!pq.empty()) {
		do {
			k = pq.top();
			
				pq.pop();
		} while (!pq.empty() && tm[k.v - 'A'] == -1);
		if (tm[k.v - 'A'] != -1)
		{
			history.push_back(pair<char, int>(k.v, k.w));
			print(history);
			t.v = k.v;
			t.w = k.w;
			val[k.v - 'A'] = k.w;
			tm[k.v - 'A'] = -1;
			sum += k.w;
		}
		for (it = l[t.v - 'A'].begin(); it != l[t.v - 'A'].end(); it++)
		{
			k.v = it->v;
			k.w = it->w;
			if (tm[it->v - 'A'] == -1)
				continue;
			else if (tm[it->v - 'A'] == 0)
			{
				k.t = tm[it->v - 'A'] = cnt;
				if (!flag)
					val[it->v - 'A'] = it->w;
				else {
					val[it->v - 'A'] = val[t.v - 'A'] + it->w;
					k.w = val[it->v - 'A'];
				}
				pq.push(k);
			}
			else if (tm[it->v - 'A'] != 0 && val[it->v - 'A'] > it->w)
			{
				k.t = tm[it->v - 'A'] = -cnt;
				if (!flag)
					val[it->v - 'A'] = it->w;
				else {
					val[it->v - 'A'] = min(val[it->v - 'A'], val[t.v -
						'A'] + it->w);
					k.w = val[it->v - 'A'];
				}
				pq.push(k);
			}
		}
		cnt++;
	}
	cout << "합 : " << sum << endl;
}
int main()
{
	list<struct node> l[NUM];
	list<struct node>::iterator it;
	
		char v1, v2;
	int weight;
	int edge;
	struct node k;
	cout << "edge의 갯수 입력: ";
	cin >> edge;
	cout << "v1, v2, weight 입력: " << endl;
	for (int i = 0; i < edge; i++)
	{
		cin >> v1 >> v2 >> weight;
		k.v = v2;
		k.w = weight;
		l[v1 - 'A'].push_back(k);
		k.v = v1;
		l[v2 - 'A'].push_back(k);
	}
	cout << endl;
	cout << "MST 결과" << endl;
	mst(l, 0);
	cout << endl << "SPT 결과" << endl;
	mst(l, 1);
	return 0;
}