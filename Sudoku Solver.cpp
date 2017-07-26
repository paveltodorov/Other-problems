/*
0 0 3 9 0 0 0 0 1
0 2 0 3 0 5 8 0 6
6 0 0 0 0 1 4 0 0
0 0 8 7 0 0 0 0 6
1 0 2 0 0 0 7 0 8
9 0 0 0 0 8 2 0 0
0 0 2 8 0 0 0 0 5
6 0 9 2 0 3 0 1 0
5 0 0 0 0 9 3 0 0

0 0 3 0 2 0 6 0 0
9 0 0 3 0 5 0 0 1
0 0 1 8 0 6 4 0 0
0 0 8 1 0 2 9 0 0
7 0 0 0 0 0 0 0 8
0 0 6 7 0 8 2 0 0
0 0 2 6 0 9 5 0 0
8 0 0 2 0 3 0 0 9
0 0 5 0 1 0 3 0 0

5 7	2 1	8	6	4	3	9
6	9	3	5	4	2	1	8	7
4	8	1	7	3	9	5	6	2
7	3	4	9	1	5	6	2	8
9	1	6	4	2	8	7	5	3
8	2	5	3	6	7	9	4	1
2	5	9	8	7	4	3	1	6
1	4	8	6	9	3	2	7	5
3	6	7	2	5	1	8	9	4

5 7	2 1	8	6	4	3	9
6	9	3	5	4	2	1	8	7
4	8	0	7	3	9	5	6	2
7	3	0	9	1	5	6	2	8
9	1	6	4	2	0	7	5	3
8	2	5	3	6	7	9	4	1
2	5	9	8	7	4	3	1	6
1	4	8	6	9	3	2	7	5
3	6	7	2	5	1	8	9	4

*/

#include<iostream>
using namespace std;
const int SIZE = 9;
int arr[SIZE][SIZE];

void readSudoku()
{
    for(int i = 0;i<SIZE;i++)
        for(int j = 0;j<SIZE;j++)
           cin>>arr[i][j];
}
void printSudoku()
{
    cout<<endl;
    for(int i = 0;i<SIZE;i++)
    {
        for(int j = 0;j<SIZE;j++)
           cout<<arr[i][j]<<" ";
           cout<<endl;
    }
}
void getCandidates(int row,int column,int candidates[9])
{
    int length = 1;
    for(int i = 1;i<=9;i++)
    {
        bool isCandidate = true;
        for(int j = 0;j<9;j++)
        {
            if(arr[row][j] == i || arr[j][column] == i
               ||
               arr[row - row%3 + j/3][column - column%3 + j%3] == i
               )
            {
                isCandidate = false;
                break;
            }
        }

    if(isCandidate == true)
           {
               candidates[length] = i;
               length++;
           }
    }
    candidates[0] = length;
}
bool solveSudoku()
{
bool solved = false;
int row = -1;
int column = -1;
int realCandidates[10];
int length = 15;
for(int i = 0;i<9;i++)
        for(int j = 0;j<9;j++)
         {
             if(arr[i][j] == 0 )
             {
                 int candidates[10];
                 getCandidates(i,j,candidates);
                 if(candidates[0]<length || row == -1 )
                 {
                     length = candidates[0];
                     row = i;
                     column = j;
                     for(int m = 0;m<9;m++)
                     {
                         realCandidates[m] = candidates[m];
                     }
                 }
             }
         }
if(row < 0) {solved = true;}
else
{
    for(int i = 1;i<length ;i++)
    {
        arr[row][column] = realCandidates[i];
        if(solveSudoku() == true)
        {
            solved = true;
            break;
        }
      arr[row][column] = 0;
    }

}
return solved;
}

  int main()
  {
  readSudoku();
  cout<<solveSudoku()<<endl;
  printSudoku();
  int candidates[9];
  getCandidates(3,2,candidates);
  return 0;
  }
