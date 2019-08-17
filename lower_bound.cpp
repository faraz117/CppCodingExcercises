#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
#include <chrono>
#include <functional>

using namespace std;


void process_query(std::vector<uint32_t> const &elements , std::vector<uint32_t> const &val){
    for(auto const &values:val){
        // print yes with index if the number is present
        auto index = std::lower_bound(elements.begin(), elements.end(),values); 
        // print no with the index of number next smallest number greater than that number
        if(*index == values){
            std::cout << "Yes " << index  - elements.begin() + 1 << std::endl;
        }else{
            std::cout << "No " << index - elements.begin() + 1 << std::endl;
        }
    }
}

void process_query_no_reference(std::vector<uint32_t> elements , std::vector<uint32_t> const val){
    for(auto values:val){
        // print yes with index if the number is present
        auto index = std::lower_bound(elements.begin(), elements.end(),values); 
        // print no with the index of number next smallest number greater than that number
        if(*index == values){
            std::cout << "Yes " << index  - elements.begin() + 1 << std::endl;
        }else{
            std::cout << "No " << index - elements.begin() + 1 << std::endl;
        }
    }
}


void time_this(std::string name , std::function<void(std::vector<uint32_t> ,std::vector<uint32_t>)> process_query , std::vector<uint32_t> elements , std::vector<uint32_t> queries){
    auto t1 = std::chrono::high_resolution_clock::now();
    process_query(elements, queries);
    auto t2 = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
    std::cout << name << " " << duration << std::endl;
    
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    std::string const horizontal_ruler = "=============================================";
    uint32_t num_of_elements = 0;
    uint32_t num_of_queries = 0;
    std::vector<uint32_t> elements;
    std::vector<uint32_t> queries;
    std::cout << "Please enter the number of elements in the storage" << std::endl;
    std::cout << horizontal_ruler << std::endl;
    std::cin >> num_of_elements;
    for(int i = 0; i < num_of_elements ; i++){
     uint32_t input;
     std::cin >> input;
     elements.push_back(input);
    }
    std::cout << "Please enter the number of queries that you would like to process" << std::endl;
    std::cout << horizontal_ruler << std::endl;
    std::cin >> num_of_queries;
    for(int i = 0; i < num_of_queries ; i++){
        std::cout << "Please enter a number that you want to know exists or else return its lower bound" << std::endl;
        uint32_t query_val;
        std::cin >> query_val;
        queries.push_back(query_val);
    }
    
    time_this("With references",process_query,elements,queries);
    time_this("Without references",process_query_no_reference,elements,queries);
    
}
