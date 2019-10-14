//#include <bits/stdc++.h>
#include <unordered_set>
#include <queue>
#include <iostream>
//using namespace std;

int page_faults(int pages[], int num_pages, int capacity) {

    std::unordered_set<int> set;
    std::queue<int> indexes;

    int page_faults = 0;
    int hits = 0;

    for(int i = 0; i < num_pages; i++) {

        if(set.size() < capacity) {

            if(set.find(pages[i]) != set.end()) {
                
                set.insert(pages[i]);
                page_faults++;

                indexes.push(pages[i]);
            }

        } else {

            if(set.find(pages[i]) == set.end()) {

                int val = indexes.front();
                indexes.pop();
                set.erase(val);

                set.insert(pages[i]);
                indexes.push(pages[i]);

                hits++;
            }
        }
    }

    std::cout << "Page faults: " << page_faults << std::endl;

    if(page_faults != 0) {
        return hits / page_faults;
    }

    return hits;
    
}

int main(int argc, const char** argv) {

    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 
                   2, 3, 0, 3, 2}; 

    int n = sizeof(pages) / sizeof(pages[0]); 
    int capacity = 4; 

    std::cout << "Hit ratio is : " << page_faults(pages, n, capacity) << std::endl; 
    return 0; 

}