// C++ program to demonstrate Range Update
// and Range Queries using BIT
#include <bits/stdc++.h>
using namespace std;

// Returns sum of arr[0..index]. This function assumes
// that the array is preprocessed and partial sums of
// array elements are stored in BITree[]
int getSum(int BITree[], int index)
{
	int sum = 0; // Initialize result

	// index in BITree[] is 1 more than the index in arr[]
	index = index + 1;

	// Traverse ancestors of BITree[index]
	while (index>0)
	{
		// Add current element of BITree to sum
		sum += BITree[index];

		// Move index to parent node in getSum View
		index -= index & (-index);
	}
	return sum;
}

// Updates a node in Binary Index Tree (BITree) at given
// index in BITree. The given value 'val' is added to
// BITree[i] and all of its ancestors in tree.
void updateBIT(int BITree[], int n, int index, int val)
{
	// index in BITree[] is 1 more than the index in arr[]
	index = index + 1;

	// Traverse all ancestors and add 'val'
	while (index <= n)
	{
		// Add 'val' to current node of BI Tree
		BITree[index] += val;

		// Update index to that of parent in update View
		index += index & (-index);
	}
}

// Returns the sum of array from [0, x]
int sum(int x, int BITTree1[], int BITTree2[])
{
	return (getSum(BITTree1, x) * x) - getSum(BITTree2, x);
}


void updateRange(int BITTree1[], int BITTree2[], int n,
				int val, int l, int r)
{
	// Update Both the Binary Index Trees
	// As discussed in the article

	// Update BIT1
	updateBIT(BITTree1,n,l,val);
	updateBIT(BITTree1,n,r+1,-val);

	// Update BIT2
	updateBIT(BITTree2,n,l,val*(l-1));
	updateBIT(BITTree2,n,r+1,-val*r);
}

int rangeSum(int l, int r, int BITTree1[], int BITTree2[])
{
	// Find sum from [0,r] then subtract sum
	// from [0,l-1] in order to find sum from
	// [l,r]
	return sum(r, BITTree1, BITTree2) -
		sum(l-1, BITTree1, BITTree2);
}


int *constructBITree(int n)
{
	// Create and initialize BITree[] as 0
	int *BITree = new int[n+1];
	for (int i=1; i<=n; i++)
		BITree[i] = 0;

	return BITree;
}

// Driver Program to test above function
// int main()
// {
// 	int n = 5;

// 	// Construct two BIT
// 	int *BITTree1, *BITTree2;

// 	// BIT1 to get element at any index
// 	// in the array
// 	BITTree1 = constructBITree(n);

// 	// BIT 2 maintains the extra term
// 	// which needs to be subtracted
// 	BITTree2 = constructBITree(n);

// 	// Add 5 to all the elements from [0,4]
// 	int l = 0 , r = 4 , val = 5;
// 	updateRange(BITTree1,BITTree2,n,val,l,r);

// 	// Add 10 to all the elements from [2,4]
// 	l = 0 , r = 4 , val = 10;
// 	updateRange(BITTree1,BITTree2,n,val,l,r);

// 	// Find sum of all the elements from
// 	// [1,4]
// 	l = 0 , r = 4;
// 	cout << "Sum of elements from [" << l
// 		<< "," << r << "] is ";
// 	cout << rangeSum(l,r,BITTree1,BITTree2) << "\n";

// 	return 0;
// }



void solve(){
    int n,q,aux, tipo, origem, destino, valor,soma = 0;
    scanf("%d %d",&n,&q);
    int v[n];
    int *bitTree1 = constructBITree(n);

    int *bitTree2 = constructBITree(n);
    
    for(int i = 0;i<n;i++){
        scanf("%d",&aux);
        soma+=aux;
        v[i] = aux;
        // updateBIT(bitTree1, n, i, v[i]);
        updateRange(bitTree1, bitTree2, n,aux,i,i);

        // updateRange
    }

    // for(int destino = 0;destino < n;destino++){
    //     printf("%d\n",rangeSum(0, destino, bitTree1, bitTree2));

    // }
    // cout << rangeSum(0,n-1, bitTree1, bitTree2) << "\n";

    for(int i = 0;i<q;i++){
        scanf("%d",&tipo);
        if(tipo == 1){
            scanf("%d", &destino);
            soma = rangeSum(destino, destino, bitTree1, bitTree2);
            printf("%d\n",soma);
            updateRange(bitTree1, bitTree2, n, -soma, destino, destino);

        }else if(tipo == 2){
            scanf("%d %d",&destino, &valor);
            updateRange(bitTree1, bitTree2, n, valor, destino, destino);
        }else{
            scanf("%d %d",&origem, &destino);
            printf("%d\n",rangeSum(origem,destino, bitTree1, bitTree2));
        }
    }


}
//5 5 10 10 10
int main(){
    int n, t=1;
    scanf("%d",&n);
    while(n--){
        printf("Case %d:\n",t);
        t++;
        solve();
    }
}