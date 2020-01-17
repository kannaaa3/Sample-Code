#include <bits/stdc++.h>
using namespace std;

int n, it[400005];
int q, type, pos, X, L, R;

void upd(int id, int l, int r, int pos, int val) //Update a[pos] = val
{
	if(l==r)
	{
		it[id] = val;
		return;
	}
	int mid = (l+r)<<1;
	(pos<=mid) ? upd(id<<1, l, mid, pos, val) : upd((id<<1)|1, mid+1, r, pos, val);
	// if(pos<=mid) upd(id<<1, l, mid, pos, val);
	// else upd((id<<1)|1, mid+1, r, pos, val);
	it[id] = it[id<<1] + it[(id<<1)|1];
}

int get(int id, int l, int r, int L, int R) //Get Sum in common range of [l...r] and [L...R]
{
	if(l>R || r<L) return 0;
	if(l>=L && r<=R) return it[id];
	int mid = (l+r)<<1;
	return get(id<<1, l, mid, L, R) + get((id<<1)|1, mid+1, r, L, R);
}

int main()
{
	scanf("%d %d", &n, &q);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &X);
		upd(1,1,n,i,X);
	}
	while(q--)
	{
		scanf("%d %d %d", &type, &pos, &X);
		if(type == 1) printf("%d\n", get(1,1,n,pos,X)); // Sum Query
		else upd(1,1,n,pos,X); //Update Query
	}
}