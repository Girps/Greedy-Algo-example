#include<iostream>
#include<set>
#include<unordered_map>
#include<algorithm>
#include<iterator>

int main()
{
    std::set<std::string> final_stations; 

    std::set<std::string> states_needed = {"mt", "wa" , "or" , "id" , "nv" , "ut", "ca" , "az"}; 
    std::unordered_map<std::string, std::set<std::string>> stations; // key{station name} , data{set of states}
    
    stations["kone"] = std::set<std::string>({"id", "nv", "ut"});
    stations["ktwo"] = std::set<std::string>({"wa","id","mt"});
    stations["kthree"] = std::set<std::string>({"or", "nv", "ca"}); 
    stations["kfour"] = std::set<std::string>({"nv","ut"});
    stations["kfive"] = std::set<std::string>({"ca", "az"});

    // until states need set is empty

    while(states_needed.size() > 0)
    { 
        std::string best_station; 
        std::set<std::string> states_covered; 
        // go through every station  and pick one that convers the most uncovered states. 
        for(auto p = stations.begin(); p != stations.end(); ++p)
        {
            std::set<std::string> covered; 
            // get intersection that covers the current element with total 
            std::set_intersection(p->second.begin(), p->second.end(), states_needed.begin(), states_needed.end(), std::inserter(covered,covered.begin())); 
            // check if coverd has more states in it if so thats the new best stations  
            if(covered.size() > states_covered.size())
            {
                best_station = p->first;
                states_covered = covered; 
            }
        }

        std::set<std::string> newSet; 
        // now get the difference 
        std::set_difference(states_needed.begin(), states_needed.end(), states_covered.begin(),states_covered.end(), std::inserter(newSet ,newSet.begin())); 
        states_needed = newSet; 
        final_stations.insert(best_station); 
    }

    auto print = [](const std::set<std::string> &s)
    {
        for(auto p = s.begin(); p != s.end(); ++p)
        {
            std::cout << *p << " "; 
        }
    }; 

    print(final_stations); 



    return 0; 
}