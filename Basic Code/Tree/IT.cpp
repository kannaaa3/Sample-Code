#include <bits/stdc++.h>
using namespace std;

const int kn = 2e5 + 5;

int n, q, T, pos, val;
int it[kn*4];

void upd(int id, int l, int r, int pos, int val)
{
	if(l==r)
	{
		it[id] = val;
		return;
	}
	int mid = (l+r)>>1;
	if(pos<=mid) upd(id<<1,l,mid,pos,val);
	else upd((id<<1)|1,mid+1,r,pos,val);
	it[id] = it[id<<1] + it[(id<<1)|1];
}

int get(int id, int l, int r, int L, int R)
{
	if(r<L||l>R) return 0;
	if(l>=L && r<=R) return it[id];
	int mid = (l+r)>>1;
	return get(id<<1,l,mid,L,R) + get((id<<1)|1,mid+1,r,L,R);
}

int main()
{
	cin >> n >> q;
	while(q--)
	{
		cin >> T >> pos >> val;
		if(T==1) upd(1,1,n,pos,val);
		else cout << get(1,1,n,pos,val) << endl;
	}
}