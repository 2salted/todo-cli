#include <algorithm>
#include <cstdint>
#include <fstream>
#include <ios>
#include <iostream>
#include <optional>
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

i32 getLatestId() {
  ifstream file(string(std::getenv("HOME")) + "/.cache/todo-cli/todo.txt");
  if (!file) {
    return 1;
  }

  i32 id, priority;
  string title;
  i32 lastId;

  while (file >> id >> priority) {
    getline(file >> std::ws, title);
    lastId = id;
  }
  file.close();
  return lastId;
}

void createTodo(string const &title, i32 priority) {
  i32 id;
  ofstream file(string(std::getenv("HOME")) + "/.cache/todo-cli/todo.txt",
                std::ios::app);
  id = getLatestId();
  file << id + 1 << " " << priority << " " << title << endl;
  file.close();
}

vector<tuple<i32, i32, string>> listTodo() {
  vector<tuple<i32, i32, string>> todoList;
  ifstream file(string(std::getenv("HOME")) + "/.cache/todo-cli/todo.txt");
  i32 id, priority;
  string title;
  while (file >> id >> priority) {
    getline(file >> std::ws, title);
    todoList.emplace_back(id, priority, title);
  }
  file.close();
  sort(todoList.begin(), todoList.end(), [](auto const &a, auto const &b) {
    return std::get<1>(a) > std::get<1>(b);
  });
  return todoList;
}

void closeTodo(i32 idToRemove) {
  vector<tuple<i32, i32, string>> todoList;
  ifstream file(string(std::getenv("HOME")) + "/.cache/todo-cli/todo.txt");
  i32 id, priority;
  string title;

  while (file >> id >> priority) {
    getline(file >> std::ws, title);
    if (id != idToRemove) {
      todoList.emplace_back(id, priority, title);
    }
  }
  file.close();

  ofstream outFile(string(std::getenv("HOME")) + "/.cache/todo-cli/todo.txt",
                   std::ios::trunc);
  for (const auto &[id, priority, title] : todoList) {
    outFile << id << " " << priority << " " << title << endl;
  }
  outFile.close();
}

int main() { return 0; }
