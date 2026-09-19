class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board)
    {
        if(board.empty())
        return false;
        
        int bsz = board.size();
        vector<set<int>> row(bsz);
        vector<set<int>> colum(bsz);
        vector<set<int>> box(bsz);
        
        

        for(int i=0;i<board.size();i++)
        {
            int sz = board[i].size()/3;
            for(int j=0;j<board[i].size();j++)
            {
                if(board[i][j]=='.')
                continue;

                int csz = board[i].size()/3;

                int key = board[i][j]-'0';

                if(row[i].find(key)!=row[i].end() || colum[j].find(key)!=colum[j].end())
                return false;
                else
                {
                    row[i].insert(key);
                    colum[j].insert(key);
                }

                int ii = i/sz;
                int jj = j/csz;
                int bposition = (ii*sz)+jj;

                if(box[bposition].find(key)!=box[bposition].end())
                return false;
                else
                box[bposition].insert(key);
            }
        }
        
        return true;
    }
};
