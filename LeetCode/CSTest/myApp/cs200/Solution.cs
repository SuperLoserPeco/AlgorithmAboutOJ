namespace myApp.cs200
{
    public class Solution {
        int num;

        int szX, szY;

        bool[,] vis;

        int[] dx = {0, 0, 1, -1};
        int[] dy = {1, -1, 0, 0};

        bool isOK(int x, int y) {
            return (x >= 0 && x < szX) && (y >= 0 && y < szY);
        }

        void dfs(char[,] grid, int x, int y) {
            if(vis[x, y]) return;
            vis[x, y] = true;
            if(grid[x, y] == '0') return;
            
            for(int i = 0; i < 4; i++) {
                int nx = dx[i] + x; int ny = dy[i] + y;
                if(isOK(nx, ny)) dfs(grid, nx, ny);
            }
        }

        public int NumIslands(char[,] grid) {
            num = 0;
            szX = grid.GetLength(0);
            szY = grid.GetLength(1);
            vis = new bool[szX, szY];

            for(int i = 0; i < szX; i++)
            for(int j = 0; j < szY; j++) {
                vis[i, j] = false;
            }

            for(int i = 0; i < szX; i++)
            for(int j = 0; j < szY; j++) {
                if(!vis[i, j] && grid[i, j] == '1') {
                    num++;
                    dfs(grid, i, j);
                }
            }

            return num;

        }
    }
}