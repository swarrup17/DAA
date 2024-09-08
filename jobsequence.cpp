#include <algorithm>
#include <iostream>
using namespace std;

struct Job {
  char id;    // Job ID
  int dead;   // Deadline of job
  int profit; // Profit if job is done before or on deadline
};

bool comparison(Job a, Job b) {
  return (a.profit > b.profit); // Sorting jobs based on profit in decreasing order
}

void printJobScheduling(Job arr[], int n) {

  // Sort all jobs according to decreasing order of profit
  sort(arr, arr + n, comparison);

  int result[n]; // To store result (sequence of jobs)
  bool slot[n];  // To keep track of free time slots

  // Initialize all slots to be free
  for (int i = 0; i < n; i++)
    slot[i] = false;

  cout << "Steps for job scheduling:" << endl;

  // Iterate through all given jobs
  for (int i = 0; i < n; i++) {
    cout << "Considering job " << arr[i].id << " with profit " << arr[i].profit << " and deadline " << arr[i].dead << endl;

    // Find a free slot for this job (starting from the last possible slot)
    for (int j = min(n, arr[i].dead) - 1; j >= 0; j--) {
      if (slot[j] == false) {  // Free slot found
        result[j] = i;  // Add this job to the result
        slot[j] = true; // Mark this slot as occupied
        cout << "Job " << arr[i].id << " is scheduled at slot " << j + 1 << endl;
        break;
      } else {
        cout << "Slot " << j + 1 << " is already occupied." << endl;
      }
    }
    cout << endl;
  }

  // Print the final job sequence
  cout << "Final job sequence: ";
  for (int i = 0; i < n; i++) {
    if (slot[i])
      cout << arr[result[i]].id << " ";
  }
  cout << endl;
}

int main() {
  // Job array
  Job arr[] = {
      {'a', 4, 120}, {'b', 2, 85}, {'c', 3, 55}, {'d', 1, 75}, {'e', 3, 60}};

  int n = sizeof(arr) / sizeof(arr[0]);
  cout << "Following is the maximum profit sequence of jobs: " << endl;
  printJobScheduling(arr, n);
  return 0;
}
