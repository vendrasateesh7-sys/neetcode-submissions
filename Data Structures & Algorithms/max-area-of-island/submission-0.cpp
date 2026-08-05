class Solution {
public:

int maxland(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&visited)
{
    int min = 0;

    if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size())
     return 0;
    else
    if(!grid[i][j])
    return 0;
    else
    if(visited[i][j])
    return 0;
    else
    if(!visited[i][j])
    {
        min++;
        visited[i][j]=1;
    } 

    min += maxland(i+1,j,grid,visited);
    min += maxland(i-1,j,grid,visited);
    min += maxland(i,j+1,grid,visited);
    min += maxland(i,j-1,grid,visited);

    return min;
}




    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
        int area = 0;
        vector<vector<int>>visited(grid.size(),vector<int>(grid[0].size(),0));

        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                int total = maxland(i,j,grid,visited);
                area = max(area,total);
            }
        }
        
        return area;
    }
};
