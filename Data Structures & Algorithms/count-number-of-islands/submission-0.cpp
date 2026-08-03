class Solution {
public:
   void iceland(int i,int j,vector<vector<char>>&grid,vector<vector<int>>&visited)
   {
    if(i<0 || j<0 || i>=grid.size()||j>=grid[0].size())
    return;
    else
    if(grid[i][j]=='0')
    return;
    else
    if(visited[i][j])
    return;

    visited[i][j]=1;

    iceland(i+1,j,grid,visited);
    iceland(i-1,j,grid,visited);
    iceland(i,j+1,grid,visited);
    iceland(i,j-1,grid,visited);

   }
   
    int numIslands(vector<vector<char>>& grid) 
    {
        int n = grid.size();
        int x = grid[0].size();
        vector<vector<int>>visited(n,vector<int>(x,0));

        int count = 0;

        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]=='1' && !visited[i][j])
                {
                    count++;
                    iceland(i,j,grid,visited);
                }
            }
        }
    return count;
        
    }
};
