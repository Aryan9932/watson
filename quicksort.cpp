#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

int comparisons = 0;
int swaps = 0;

int partition(vector<int>& a, int low, int high) {
    int pivot = a[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        comparisons++;

        if (a[j] <= pivot) {
            i++;
            swap(a[i], a[j]);
            swaps++;
        }
    }

    swap(a[i + 1], a[high]);
    swaps++;

    return i + 1;
}

int randomizedPartition(vector<int>& a, int low, int high) {
    int randomIndex = low + rand() % (high - low + 1);

    swap(a[randomIndex], a[high]);
    swaps++;

    return partition(a, low, high);
}

void quickSort(vector<int>& a, int low, int high) {
    if (low < high) {
        int p = partition(a, low, high);
        quickSort(a, low, p - 1);
        quickSort(a, p + 1, high);
    }
}

void randomizedQuickSort(vector<int>& a, int low, int high) {
    if (low < high) {
        int p = randomizedPartition(a, low, high);
        randomizedQuickSort(a, low, p - 1);
        randomizedQuickSort(a, p + 1, high);
    }
}

void display(vector<int>& a) {
    for (int x : a)
        cout << x << " ";
    cout << endl;
}

int main() {
    srand(time(0));

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> a(n);

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> b = a;

    comparisons = swaps = 0;
    quickSort(a, 0, n - 1);

    int normalComparisons = comparisons;
    int normalSwaps = swaps;

    comparisons = swaps = 0;
    randomizedQuickSort(b, 0, n - 1);

    cout << "\nDeterministic Quick Sort:\n";
    display(a);
    cout << "Comparisons: " << normalComparisons << endl;
    cout << "Swaps: " << normalSwaps << endl;

    cout << "\nRandomized Quick Sort:\n";
    display(b);
    cout << "Comparisons: " << comparisons << endl;
    cout << "Swaps: " << swaps << endl;

    return 0;
}