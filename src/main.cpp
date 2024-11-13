#include <algorithm>
#include <cstdint>
#include <fstream>
#include <ios>
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
  vector<tuple<i32, i32, string>> todoList;
  ifstream file(std::string(std::getenv("HOME")) + "/.cache/todo-cli/todo.txt");
  i32 id, priority;
  string title;

  while (file >> id >> priority) {
    getline(file >> std::ws, title);
    if (id != idToRemove) {
      todoList.emplace_back(id, priority, title);
    }
  }
  file.close();

  ofstream outFile(std::string(std::getenv("HOME")) +
                       "/.cache/todo-cli/todo.txt",
                   std::ios::trunc);
  for (const auto &[id, priority, title] : todoList) {
    outFile << id << " " << priority << " " << title << endl;
  }
  outFile.close();
}

int main() {
  createTodo("Buy groceries", 1, 5);
  createTodo("Study for exam", 2, 8);
  createTodo("Workout", 3, 6);

  std::cout << "To-do list before removal:" << endl;
  vector<tuple<i32, i32, string>> todos = listTodo();
  for (const auto &[id, priority, title] : todos) {
    std::cout << "ID: " << id << ", Priority: " << priority
              << ", Title: " << title << endl;
  }

  i32 idToRemove = 2;
  closeTodo(idToRemove);

  std::cout << "\nTo-do list after removing ID " << idToRemove << ":" << endl;
  todos = listTodo();
  for (const auto &[id, priority, title] : todos) {
    std::cout << "ID: " << id << ", Priority: " << priority
              << ", Title: " << title << endl;
  }

  return 0;
}
