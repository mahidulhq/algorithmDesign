#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Structure to represent an activity
struct Activity {
    int start;
    int finish;
};

// Comparison function to sort activities by finish time
bool compare(Activity a, Activity b) {
    return a.finish < b.finish;
}

int main() {
    int n,c = 0;
    cout << "Enter number of activities: ";
    cin >> n;

    vector<Activity> activities(n);
    cout << "Enter start and finish time of each activity:\n";
    for (int i = 0; i < n; i++) {
        cin >> activities[i].start >> activities[i].finish;
    }

    // Sort activities by their finish time
    sort(activities.begin(), activities.end(), compare);

    cout << "\nSelected activities are:\n";

    // The first activity always gets selected
    int lastFinish = activities[0].finish;
    cout << "(" << activities[0].start << ", " << activities[0].finish << ")\n";

    // Consider the rest of the activities
    for (int i = 1; i < n; i++) {
        if (activities[i].start >= lastFinish) {
            cout << "(" << activities[i].start << ", " << activities[i].finish << ")\n";
            lastFinish = activities[i].finish;
            c++;

        }
    }
    cout << "Total no. of activity selected: " << c+1 << "\n";

    return 0;
}

