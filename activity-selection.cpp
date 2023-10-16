#include<bits/stdc++.h>
using namespace std;

struct Activity
{
    int start;
    int finish;
};

bool compareActivities(const Activity& a, const Activity& b){
    return a.finish < b.finish;
}

void selectActivities(vector<Activity>& activities) {
    sort(activities.begin(), activities.end(), compareActivities);

    int selectedItem = 0;
    cout << "Selected Activities: " << "( " << activities[selectedItem].start << ", " << activities[selectedItem].finish << ") ";

    for(int i=1; i<activities.size(); i++) {
        if(activities[i].start >= activities[selectedItem].finish) {
            selectedItem = i;
            cout << "( " << activities[selectedItem].start << ", " << activities[selectedItem].finish << ") ";
        }
    }
    cout << "\n";
}

int main() {
    vector<Activity> activities = {
        {1, 3}, 
        {2, 5}, 
        {3, 6}, 
        {5, 3}, 
        {6, 8}, 
        {8, 9}
    };

    selectActivities(activities);
}