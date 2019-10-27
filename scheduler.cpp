#include<iostream>
#include<string>
#include<queue>
#include<utility>
#include<functional>


class UserTask
{
public:
    UserTask(std::uint16_t deadline, std::uint16_t task_size, std::string task_id):m_deadline(deadline),m_task_size(task_size),m_task_id(task_id){
    }
    void print_id(){
        std::cout<< "Running task: " << m_task_id << " Deadline is: " << m_deadline << " Task size is: " << m_task_size << std::endl;
    }
    
    std::uint16_t get_deadline(){
        return m_deadline;
    }
    
    std::uint16_t get_task_size(){
        return m_task_size;
    }

private:
    std::uint16_t m_deadline;
    std::uint16_t m_task_size;
    std::string m_task_id;

};

template<typename T> void print_queue(T& q){
    while(!q.empty()) {
        auto task = q.top();
	task.print_id();
        q.pop();
    }
}

template <typename T>
void populate_queue(T &user_task_queue){
  user_task_queue.push(UserTask(16,208,"ID:0"));
  user_task_queue.push(UserTask(22,20,"ID:1"));
  user_task_queue.push(UserTask(6,200,"ID:2"));
  user_task_queue.push(UserTask(116,21,"ID:3"));
  user_task_queue.push(UserTask(186,10,"ID:4"));
}


// lambda is evaluated at compile time using constexpr
constexpr auto cmp_deadline = [](UserTask left, UserTask right) {
	      return (left.get_deadline()) > (right.get_deadline()); };

constexpr auto cmp_size = [](UserTask left, UserTask right) {
              return (left.get_task_size()) < (right.get_task_size()); };

// so we can provide values to the aliases
// deadline_priority_queue type arranges the values according to the deadline
using deadline_priority_queue = std::priority_queue<UserTask, std::vector<UserTask>, decltype(cmp_deadline)>;
// size_priority_queue arranges the values according to the size
using size_priority_queue = std::priority_queue<UserTask, std::vector<UserTask>, decltype(cmp_size)>;

int main()
{	
  deadline_priority_queue ordered_queue(cmp_deadline); 
  populate_queue<deadline_priority_queue>(ordered_queue);
  print_queue(ordered_queue);
  std::cout << "======================================" << std::endl;
  size_priority_queue ordered_queue_2(cmp_size); 
  populate_queue<size_priority_queue>(ordered_queue_2);
  print_queue(ordered_queue_2);
  return 0;
}
