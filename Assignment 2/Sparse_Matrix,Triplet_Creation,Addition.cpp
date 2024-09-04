#include<iostream>
using namespace std;

int calc_size(int** a,int rows, int cols)
{
    int s=0;
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            if(a[i][j]!=0)
            {
                s++;
            }
        }
    }
    return s;
}

void generateTripletMatrix(int** a, int rows, int cols, int **t, int &size) 
{

    t[0][0] = rows;
    t[0][1] = cols;
    t[0][2] = size;

    int k = 1;
    // Traverse the matrix and store the row, col, and non-zero value in the triplet matrix
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(a[i][j] != 0) {
                // Store in the triplet matrix
                t[k][0] = i;
                t[k][1] = j;
                t[k][2] = a[i][j];
                k++;
            }
        }
    }
}

void printTriplet(int** t, int size)
{
    cout << "Row Col Val" << endl;
    for(int i = 0; i <= size; i++) {
        for(int j = 0; j < 3; j++) {
            cout << t[i][j] << "   ";
        }
        cout << endl;
    }
}

int** addTriplet(int** t1, int** t2)
{
    int size1=t1[0][2];
    int size2=t2[0][2];
    int maxsize=size1+size2;
    int i=1,j=1,k=1;
    //Three pointers for t1,t2 and resultant matrix
    //The resultant matrix can be of max size size1+size2
    int rows=t1[0][0];
    int cols=t1[0][1];
    //Allocate memory to resultant triplet
    int** t3=new int*[maxsize+1];
    for(int n=0;n<=maxsize;n++)
    {
        t3[n]=new int[3];
    }
    //Now apply the loop that compares the row and column
    while(i<=size1 && j<=size2)
    {
        //First condition if ith row is smaller than jth row or if they are equal but col is smaller in i, then copy i to k
        if(t1[i][0]<t2[j][0] || (t1[i][0]==t2[j][0] && t1[i][1]<t2[j][1]))
        {
            //copy the i values to k
            t3[k][0]=t1[i][0];
            t3[k][1]=t1[i][1];
            t3[k][2]=t1[i][2];
            k++;
            i++;
        }
        //Same case but for j
        else if(t1[i][0]>t2[j][0] || (t1[i][0]==t2[j][0] && t1[i][1]>t2[j][1]))
        {
            //copy the j values to k
            t3[k][0]=t2[j][0];
            t3[k][1]=t2[j][1];
            t3[k][2]=t2[j][2];
            k++;
            j++;
        }
        //If both i and j are equal, then add their values and store in k
        else
        {
            t3[k][0]=t1[i][0];
            t3[k][1]=t1[i][1];
            t3[k][2]=t1[i][2]+t2[j][2];
            i++;
            j++;
            k++;
        }
    }
    //Another possibility is that either of triplets becomes empty, then simply start the loop and copy the elements from remaining matrix
    //if t2 became empty, j value would be size2+1,while i was still lesser that size1,copy from t1
    while(i<=size1)
    {
        t3[k][0]=t1[i][0];
        t3[k][1]=t1[i][1];
        t3[k][2]=t1[i][2];
        k++;
        i++;
    }
    while(j<=size2)
    {
        t3[k][0]=t2[j][0];
        t3[k][1]=t2[j][1];
        t3[k][2]=t2[j][2];
        k++;
        j++;
    }
    //At the end of copying, the value of k would be the size of our matrix since some spaces could be left in matrix
    int size3=k-1;
    t3[0][0]=rows;
    t3[0][1]=cols;
    t3[0][2]=size3;

    return t3;
}
int main() 
{
    // Initialize the sparse matrix
    int a[5][4] = {{0, 0, 2, 0}, {0, 0, 0, 4}, {0, 0, 0, 0}, {0, 0, 7, 0}, {0, 0, 0, 8}};
    int cols=sizeof(a[0])/sizeof(int);
    int rows=sizeof(a)/(sizeof(int)*cols);

    // Convert 2D array to pointer array
    int** a_ptr = new int*[rows];
    for (int i = 0; i < rows; i++) {
        a_ptr[i] = a[i];
    }

    // Calculate the size of the triplet matrix
    int size=calc_size(a_ptr,rows,cols);

    // Allocate memory for the triplet matrix
    int** t = new int*[size + 1];
    for(int i = 0; i < size + 1; i++) {
        t[i] = new int[3];
    }

    // Generate the triplet matrix
    generateTripletMatrix(a_ptr, rows, cols, t, size);

    // Print the triplet matrix
    // printTriplet(t,size);

    //-------------------------------------------------------------
    //Addition of Sparse Matrices
    //Creating 2 Sparse Matrices
    int A[4][3]={{0,1,3},{2,0,0},{0,0,1},{0,-5,2}};
    int B[4][3]={{1,0,6},{5,0,0},{2,0,0},{0,3,0}};
    rows=4;
    cols=3;
    // Convert 2D array to pointer array
    int** A_ptr = new int*[rows];
    for (int i = 0; i < rows; i++) {
        A_ptr[i] = A[i];
    }
    int** B_ptr = new int*[rows];
    for (int i = 0; i < rows; i++) {
        B_ptr[i] = B[i];
    }
    int size1=calc_size(A_ptr,rows,cols);
    int size2=calc_size(B_ptr,rows,cols);

    int** t1 = new int*[size1 + 1];
    for(int i = 0; i < size1 + 1; i++) {
        t1[i] = new int[3];
    }
    int** t2 = new int*[size2 + 1];
    for(int i = 0; i < size2 + 1; i++) {
        t2[i] = new int[3];
    }
    //Generate the triplet Matrices of A and B
    generateTripletMatrix(A_ptr,rows,cols,t1,size1);
    generateTripletMatrix(B_ptr,rows,cols,t2,size2);
    // printTriplet(t1,size1);
    // printTriplet(t2,size2);
    //Now the triplets of A and B Matrices are successfully generated i.e. t1 and t2
    int**t3=addTriplet(t1,t2);
    int size3=t3[0][2];
    printTriplet(t3,size3);
    return 0;
}
