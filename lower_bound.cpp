#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


void process_query(std::vector<uint32_t> const &elements , uint32_t const &val){
    // print yes with index if the number is present
    auto index = std::lower_bound(elements.begin(), elements.end(),val); 
    // print no with the index of number next smallest number greater than that number
    if(*index == val){
        std::cout << "Yes " << index  - elements.begin() + 1 << std::endl;
    }else{
        std::cout << "No " << index - elements.begin() + 1 << std::endl;
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    uint32_t num_of_elements = 0;
    uint32_t num_of_queries = 0;
    std::vector<uint32_t> elements;
    std::cin >> num_of_elements;
    for(int i = 0; i < num_of_elements ; i++){
     uint32_t input;
     std::cin >> input;
     elements.push_back(input);
    }
    std::cin >> num_of_queries;
    for(int i = 0; i < num_of_queries ; i++){
        uint32_t query_val;
        std::cin >> query_val;
        process_query(elements, query_val);
    }
}
