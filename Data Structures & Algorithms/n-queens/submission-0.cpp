class Solution {
public:
    
    bool issafe(int r,int c,vector<string>&board)
    {
        if(board.empty())
        return false;

        for(int i=r-1;i>=0;i--)
        {
            if(board[i][c]=='Q')
            return false;
        }

        for(int i=r-1,j=c-1;i>=0 && j>=0 ;i--,j--)
        {
            if(board[i][j]=='Q')
            return false;
        }

        for(int i=r-1,j=c+1; i>=0 && j<board[0].size();i--,j++)
        {
            if(board[i][j]=='Q')
            return false;
        }

        return true;
    }
    
    void queen(vector<string>&board,vector<vector<string>>&ans,int r,int c)
    {
       if(board.empty())
       return;

       if(r==board.size())
       {
        ans.push_back(board);
        return;
       }

       for(int i=0;i<board.size();i++)
       {
        if(issafe(r,i,board))
        {
          board[r][i]='Q';
          queen(board,ans,r+1,0);
          board[r][i]='.';
        }

       }
      return;
    }

    vector<vector<string>> solveNQueens(int n) 
    {

        vector<string> board(n,string(n,'.'));
        vector<vector<string>>ans;
        int r = 0;
        int c = 0;

        queen(board,ans,r,c);

        return ans;
        
    }
};
