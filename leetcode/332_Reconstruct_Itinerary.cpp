#include <iostream>
using namespace std;

class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string> > tickets) {

    }
};
int main(){
    Solution s;
    vector<pair<string, string> > tickets;
    tickets.push_back(pair<string, string>("JFK","SFO"));
    tickets.push_back(pair<string, string>("JFK","ATL"));
    tickets.push_back(pair<string, string>("SFO","ATL"));
    tickets.push_back(pair<string, string>("ATL","JFK"));
    tickets.push_back(pair<string, string>("JFK","SFO"));
    tickets.push_back(pair<string, string>("ATL","SFO"));
    s.findItinerary(tickets);

}
