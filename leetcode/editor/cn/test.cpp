#include<iostream>
#include<string>
#include<vector>
using namespace std;
void removeSubfolders(vector<string>const& folders){
    for(auto it = folders.begin(); it != folders.end(); it++){
        for(auto it2 = it+1; it2 != folders.end(); it2++){
            if((*it).find(*it2) != -1)  folders.remove(it2);
            else if((*it2).find(*it))   folders.remove(it);
        }
    }
}
int main(){

    return 0;
}

