#include <algorithm>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <string>
#include <tuple>
#include <vector>

using i32 = int32_t;
using std::endl;
using std::getline;
using std::ifstream;
using std::ofstream;
using std::string;
using std::tuple;
using std::vector;

void createTodo(string const &title, i32 id, i32 priority) {
  ofstream file(std::string(std::getenv("HOME")) + "/.cache/todo-cli/todo.txt",
                std::ios::app);
  file << id << " " << priority << " " << title << endl;
  file.close();
}

vector<tuple<i32, i32, string>> listTodo() {
  vector<tuple<i32, i32, string>> todoList;
  ifstream file("~/.cache/todo-cli/todo.txt");
  while (!file.eof()) {
    i32 id, priority;
    string title;
    file >> id >> priority;
    getline(file >> std::ws, title);
    file.ignore();
    todoList.emplace_back(id, priority, title);
  }
  sort(todoList.begin(), todoList.end(), [](auto const &a, auto const &b) {
    return std::get<1>(a) > std::get<1>(b);
  });
  return todoList;
};

int main() {
  std::cout << "Creating a new todo..." << endl;
  createTodo("you have to do this", 1, 1);
  //
  // std::cout << "Listing todos:" << endl;
  // for (const auto &[id, priority, title] : listTodo()) {
  //   std::cout << "ID: " << id << ", Priority: " << priority
  //             << ", Title: " << title << endl;
  // }
  //
  return 0;
}
