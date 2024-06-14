class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int cnt = 0;
        vector<int> vis(flowerbed.size(), 0);
        if(flowerbed.size() == 1){
            if(flowerbed[0] == 0){
                if( n <= 1) {
                    return true;
                }
                else return false;
            }
            else {
                if( n == 0) return true;
                else return false;
            }
        }
        else{
            for(int i=0; i != flowerbed.size(); i++) {
                if(vis[i]) continue;
                if(flowerbed[i] == 1){
                    vis[i] = 1;
                    continue;
                }
                else{
                    if(i == 0){
                        if(flowerbed[i+1] != 1){
                            vis[i] = 1;
                            cnt++;
                        }
                        
                    }
                    else if(i == flowerbed.size() - 1) {
                        if(flowerbed[i-1] == 0 and !vis[i-1]) {
                            vis[i-1] = 1;
                            vis[i] = 1;
                            cnt++;
                        }
                    }
                    else {
                        if(flowerbed[i-1] == 0 and !vis[i-1] 
                            and flowerbed[i+1] != 1){
                            vis[i-1] = 1;
                            vis[i] = 1;
                            cnt++;
                        }
                    }
                }
            }
        }
        
        if(cnt >= n){
            return true;
        }
        else{
            return false;
        }
    }
};