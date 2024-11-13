#include <algorithm>
#include <cstdint>
#include <fstream>
#include <ios>
#include <iostream>
#include <limits>
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
  ifstream file(std::string(std::getenv("HOME")) + "/.cache/todo-cli/todo.txt");
  i32 id, priority;
  string title;
  while (file >> id >> priority) {
    getline(file >> std::ws, title);
    todoList.emplace_back(id, priority, title);
  }
  sort(todoList.begin(), todoList.end(), [](auto const &a, auto const &b) {
    return std::get<1>(a) > std::get<1>(b);
  });
  return todoList;
}

void closeTodo(i32 idToRemove) {
  ifstream file(std::string(std::getenv("HOME")) + "/.cache/todo-cli/todo.txt");
  i32 id;
  while (file >> id) {
    file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (id == idToRemove) {
    }
  }
}

int main() {
  vector<tuple<i32, i32, string>> todos = listTodo();
  for (const auto &[id, priority, title] : todos) {
    std::cout << "ID: " << id << ", Priority: " << priority
              << ", Title: " << title << endl;
  }
  return 0;
}
