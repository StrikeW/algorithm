#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    static bool cmp(pair<bool,string>& a,pair<bool,string>& b){
        return a.second < b.second;
    };
public:
    unordered_map<string,vector<pair<bool,string> > > helper_map;
    bool dfs(int curr_lv,int max_lv,vector<string>& output){
        if(curr_lv==max_lv){
            return true;
        }
        string last_place=output[output.size()-1];
        vector<pair<bool,string> >& vec=helper_map[last_place];
        for(int i=0;i<vec.size();i++){
            if(!vec[i].first){
                vec[i].first=true;
                output.push_back(vec[i].second);
                bool ret=dfs(curr_lv+1,max_lv,output);
                if(!ret){
                    output.pop_back();
                    vec[i].first=false;
                } else {
                    return true;
                }
            }
        }
        return false;
    }
    vector<string> findItinerary(vector<pair<string, string> > tickets) {
        helper_map.clear();
        for(int i=0;i<tickets.size();i++){
            helper_map[tickets[i].first].push_back(pair<bool,string>(false,tickets[i].second));
        }
        unordered_map<string,vector<pair<bool,string> > >::iterator iter;
        for(iter=helper_map.begin();iter!=helper_map.end();iter++){
            sort(iter->second.begin(),iter->second.end(),cmp);
        }
        vector<string> output;
        output.push_back("JFK");
        dfs(0,tickets.size(),output);
        for(int i=0;i<output.size();i++){
            cout<<output[i]<<endl;
        }
        return output;
    }
};
int main(){
    Solution s;
    vector<pair<string, string> > tickets;
    tickets.push_back(pair<string, string>("JFK","SFO"));
    tickets.push_back(pair<string, string>("JFK","ATL"));
    tickets.push_back(pair<string, string>("SFO","ATL"));
    tickets.push_back(pair<string, string>("ATL","JFK"));
    tickets.push_back(pair<string, string>("ATL","SFO"));

    s.findItinerary(tickets);

}
