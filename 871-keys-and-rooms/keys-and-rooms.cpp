class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int> q;
        q.push(0);
        vector<bool> v(rooms.size(), false);
        while(!q.empty()) {
            int x = q.front();
            q.pop();
            v[x] = true;
            for(int a : rooms[x]) {
                if(!v[a])
                    q.push(a);
            }
        }
        for(int i=0; i != v.size(); i++) {
            if(!v[i]) return false;
        }
        return true;
    }
};