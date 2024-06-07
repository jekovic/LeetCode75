class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;
        for(const auto& a : asteroids) {
            if(res.size() == 0)
                res.push_back(a);
            else{
                if(a > 0)
                    res.push_back(a);
                else{
                    //음수
                    bool flag = true;
                    while(res.size() != 0) {
                        if(res.back() < 0){
                            res.push_back(a);
                            break;
                        }
                        else{
                            if(res.back() < abs(a)){
                                res.pop_back();
                            }
                            else if(res.back() == abs(a)){
                                res.pop_back();
                                flag = false;
                                break;
                            }
                            else{
                                break;
                            }
                        }
                    }
                    if(res.size() == 0 and flag == true)
                        res.push_back(a);
                }
            }
        }
        return res;
    }
};