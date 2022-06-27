#include<bits/stdc++.h>
using namespace std;
// Matrix Ai has dimension a[i-1] x a[i] for i = 1..n

int MatrixChainMultiplication(int a[], int n)
{
    int m[n][n];
    int i, j, k, L, q;

    for (i=1; i<n; i++)
        m[i][i] = 0;    //number of multiplications are 0(zero) when there is only one matrix

    //Here L is chain length. It varies from length 2 to length n.
    for (L=2; L<n; L++)
    {
        for (i=1; i<n-L+1; i++)
        {
            j = i+L-1;
            m[i][j] = INT_MAX;  //assigning to maximum value

            for (k=i; k<=j-1; k++)
            {
                q = m[i][k] + m[k+1][j] + a[i-1]*a[k]*a[j];
                if (q < m[i][j])
                {
                    m[i][j] = q;    //if number of multiplications found less that number will be updated.
                }
            }
        }
    }

    return m[1][n-1];   //returning the final answer which is M[1][n]

}

int main()
{
    int n,i;
    //Input:Here the dimensions will be entered in the form of array
    cout<<"Enter number of matrices\n";
    cin>>n;

    int arr[n];

    printf("Enter the array elements\n");

    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }


    //Output:Minimum multiplication operations
    cout<<"Minimum number of multiplications is ";
    cout<<MatrixChainMultiplication(arr, n);

    return 0;
}


