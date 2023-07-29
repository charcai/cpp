#include<bits/stdc++.h>  
void sudoku(int x);  
int judge(int row,int col,int num);  
int map[9][9];//定义9*9二维数组  
int flag;//  
int i,j;  
void sudoku(int x)  
{  
    int num;  
    if(flag)  
        return;  
    int row=x/9;  
    int col=x%9;  
      
    if(x==81)//x==81说明得出结果并输出  
    {  
        for(i=0;i<9;i++)  
        {  
            for(j=0;j<9;j++)  
                printf("%d ",map[i][j]);  
            printf("\n");  
        }  
        flag=1;  
        return;  
    }  
      
    if(map[row][col]==0)  
    {  
        for(num=1;num<=9;num++)//每一个空格从0开始，判断可以填哪个数字  
        {  
            if(judge(row,col,num))  
            {  
                map[row][col]=num;  
                sudoku(x+1);//递归  
                map[row][col]=0;//出现重复，进行回溯  
            }  
        }  
    }  
    else  
        sudoku(x+1);//递归  
}  
int judge(int row,int col,int num)//判断行，列，3*3是会否出现重复数字，若有，返回0，若无，返回1  
{  
    int r,c;  
    for(r=0;r<9;r++)//判断行  
    {  
        if(map[r][col]==num)  
            return 0;  
    }  
    for(c=0;c<9;c++)//判断列  
    {  
        if(map[row][c]==num)  
            return 0;  
    }  
    int t1=(row/3)*3;//判断3*3方格  
    int t2=(col/3)*3;  
    for(r=t1;r<t1+3;r++)  
    {  
        for(c=t2;c<t2+3;c++)  
            if(map[r][c]==num)  
                return 0;  
    }  
    return 1;  
}  
int main()  
{  
    int i,j; 
  
    flag=0;  
    for(i=0;i<9;i++)  
    {  
        for(j=0;j<9;j++)  
        {  
            scanf("%d",&map[i][j]);  
        }  
    }  
    sudoku(0);  

    return 0;  
}
/*
input:
0 0 5 3 0 0 0 0 0
8 0 0 0 0 0 0 2 0
0 7 0 0 1 0 5 0 0
4 0 0 0 0 5 3 0 0
0 1 0 0 7 0 0 0 6
0 0 3 2 0 0 0 8 0
0 6 0 5 0 0 0 0 9
0 0 4 0 0 0 0 3 0
0 0 0 0 0 9 7 0 0

output:
1 4 5 3 2 7 6 9 8
8 3 9 6 5 4 1 2 7
6 7 2 9 1 8 5 4 3
4 9 6 1 8 5 3 7 2
2 1 8 4 7 3 9 5 6
7 5 3 2 9 6 4 8 1
3 6 7 5 4 2 8 1 9
9 8 4 7 6 1 2 3 5
5 2 1 8 3 9 7 6 4

*/  
