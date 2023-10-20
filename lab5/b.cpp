#include <iostream>
#include <vector>
using namespace std;

struct MaxHeap{
    vector<int> heap;
    int parent(int i){return (i - 1)/2;}
    int left(int i){return 2*i + 1;}
    int right(int i){return 2*i + 2;}
    void insert(int val){
        heap.push_back(val);
        int i = heap.size() - 1;
        while(i != 0 && heap[parent(i)] < heap[i]){
            swap(heap[parent(i)], heap[i]);
            i = parent(i);
        }
    }
    void heapify(int i){
        int l = left(i), r = right(i), smallest = i;
        if(l < heap.size() && heap[l] > heap[i]) smallest = l;
        if(r < heap.size() && heap[r] > heap[smallest]) smallest = r;
        if(smallest != i){
            swap(heap[i], heap[smallest]);
            heapify(smallest);
        }
    }
    int extractMax(){
        if(heap.size() == 0) return 0;
        if(heap.size() == 1){
            int root = heap[0];
            heap.pop_back();
            return root;
        }
        int root = heap[0];
        heap[0] = heap[heap.size() - 1];
        heap.pop_back();
        heapify(0);
        return root;

    }
    int rocks(){
        int weight;
        while(heap.size() > 1){
            int y = extractMax();
            int x = extractMax();
            if(x != y){insert(y - x);}
        }
        if(heap.size() == 1){return heap[0];}
        else if(heap.size() == 0){return 0;}
    }
};

int main(){
    int n;
    cin >> n;
    MaxHeap heap;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        heap.insert(x);
    }
    cout << heap.rocks();
    return 0;
}