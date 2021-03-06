Oil Deposits(http://acm.hdu.edu.cn/showproblem.php?pid=1241)

Time Limit: 2000/1000 MS (Java/Others)    Memory Limit: 65536/32768 K (Java/Others)
Total Submission(s): 30284    Accepted Submission(s): 17531


Problem Description
The GeoSurvComp geologic survey company is responsible for detecting underground oil deposits. GeoSurvComp works with one large rectangular region of land at a time, and creates a grid that divides the land into numerous square plots. It then analyzes each plot separately, using sensing equipment to determine whether or not the plot contains oil. A plot containing oil is called a pocket. If two pockets are adjacent, then they are part of the same oil deposit. Oil deposits can be quite large and may contain numerous pockets. Your job is to determine how many different oil deposits are contained in a grid. 
 

Input
The input file contains one or more grids. Each grid begins with a line containing m and n, the number of rows and columns in the grid, separated by a single space. If m = 0 it signals the end of the input; otherwise 1 <= m <= 100 and 1 <= n <= 100. Following this are m lines of n characters each (not counting the end-of-line characters). Each character corresponds to one plot, and is either `*', representing the absence of oil, or `@', representing an oil pocket.
 

Output
For each grid, output the number of distinct oil deposits. Two different pockets are part of the same oil deposit if they are adjacent horizontally, vertically, or diagonally. An oil deposit will not contain more than 100 pockets.
 

Sample Input
1 1
*
3 5
*@*@*
**@**
*@*@*
1 8
@@****@*
5 5 
****@
*@@*@
*@**@
@@@*@
@@**@
0 0 
 

Sample Output
0
1
2
2




//简单DFS:
#include <stdio.h>
#include <string.h>
#define N 110
int dirx[8] = {0, 0, 1, 1, 1, -1, -1, -1};
int diry[8] = {1, -1, 1, 0, -1, 1, 0, -1};
char map[N][N];
int vis[N][N];
int n, m, flag, cnt, nowx, nowy, nextx, nexty;
void DFS(int nowx, int nowy)
{
    for(int i = 0; i < 8; i++)
    {
        nextx = nowx + dirx[i];
        nexty = nowy + diry[i];
        if(nextx<0 || nextx>=n || nexty<0 || nexty>=m)
        {
            continue;
        }
        if(vis[nextx][nexty])
        {
            continue;
        }
        else
        {
            vis[nextx][nexty] = 1;
            DFS(nextx, nexty);
        }
    }
}
int main()
{
    while(~scanf("%d%d", &n, &m))
    {
        if(n == 0 && m == 0)
        {
            return 0;
        }
        memset(vis, 0, sizeof(vis));
        for(int i = 0; i < n; i++)
        {
            scanf("%s", map[i]);
            for(int j = 0; j < m; j++)
            {
                if(map[i][j] == '*')
                {
                    vis[i][j] = 1;
                }
                if(map[i][j] == '@')
                {
                    nowx = i;
                    nowy = j;
                }
            }
        }
        cnt = 0;
        while(1)
        {
            flag = 0;
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < m; j++)
                {
                    if(vis[i][j] == 0)
                    {
                        flag = 1;
                        nowx = i;
                        nowy = j;
                    }
                }
            }
            if(flag == 0)
            {
                break;
            }
            vis[nowx][nowy] = 1;
            DFS(nowx, nowy);
            cnt++;
        }
        printf("%d\n", cnt);
    }
    return 0;
}





