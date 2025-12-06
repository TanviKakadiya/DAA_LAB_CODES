#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Activity {
    int start, finish;
};

bool cmp(Activity a, Activity b) {
    return a.finish < b.finish;
}

void activitySelection(vector<Activity>& activities) {
    sort(activities.begin(), activities.end(), cmp);
    
    int n = activities.size();
    vector<int> selected;
    
    selected.push_back(0); // Select the first activity by default
    
    for (int i = 1; i < n; i++) {
        if (activities[i].start >= activities[selected.back()].finish) {
            selected.push_back(i);
        }
    }
    
    cout << "Maximum number of activities selected: " << selected.size() << endl;
    cout << "Selected activities (Start - Finish):" << endl;
    for (auto idx : selected)
        cout << activities[idx].start << " - " << activities[idx].finish << endl;
}

int main() {
    int n;
    cout << "Enter number of activities: ";
    cin >> n;
    
    vector<Activity> activities(n);
    cout << "Enter start time and finish time for each activity:\n";
    for (int i = 0; i < n; i++) {
        cin >> activities[i].start >> activities[i].finish;
    }
    
    activitySelection(activities);
    
    return 0;
}
