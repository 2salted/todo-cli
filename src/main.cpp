#include <algorithm>
#include <cstdint>
#include <fstream>
#include <iomanip>
#include <ios>
#include <iostream>
#include <ostream>
#include <string>
#include <tuple>
#include <vector>

using i32 = int32_t;
using std::cerr;
using std::cout;
using std::endl;
using std::getline;
using std::ifstream;
using std::left;
using std::ofstream;
using std::setw;
using std::string;
using std::tuple;
using std::vector;

void printHeader() {
  cout << left << setw(6) << "ID" << setw(10) << "TITLE" << endl;
  cout << string(60, '-') << endl;
  return;
}

void displayTodo(vector<tuple<i32, i32, string>> const &todo) {
  printHeader();
  for (i32 i = 0; i < todo.size(); ++i) {
    i32 id = std::get<0>(todo[i]);
    string title = std::get<2>(todo[i]);
    cout << left << "#" << setw(5) << id << setw(12) << title << endl;
  }
  return;
}

i32 getLatestId() {
  ifstream file(string(getenv("HOME")) + "/.cache/todo-cli/todo.txt");

  if (!file) {
    cerr << "Error: couldn't open file" << endl;
    return 1;
  }
  i32 id = 0, priority = 0;
  string title;
  i32 lastId = 0;

  while (file >> id >> priority) {
    getline(file >> std::ws, title);
    lastId = id;
  }

  file.close();
  return lastId ? lastId + 1 : 1;
}

i32 createTodo(string const &title, i32 const priority) {
  ofstream file(string(getenv("HOME")) + "/.cache/todo-cli/todo.txt",
                std::ios::app);

  if (!file) {
    cerr << "Error: couldn't open file" << endl;
    return -1;
  }
  i32 const id = getLatestId();
  file << id << " " << priority << " " << title << endl;
  file.close();
  return id;
}

vector<tuple<i32, i32, string>> getTodo() {
  vector<tuple<i32, i32, string>> todoList;
  ifstream file(string(getenv("HOME")) + "/.cache/todo-cli/todo.txt");

  if (!file) {
    cerr << "Error: couldn't open file" << endl;
    return todoList;
  }
  i32 id = 0, priority = 0;
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
  // bool idFound = false;
  ifstream file(string(getenv("HOME")) + "/.cache/todo-cli/todo.txt");

  if (!file) {
    cerr << "Error: couldn't open file" << endl;
    return;
  }
  i32 id = 0, priority = 0;
  string title;

  while (file >> id >> priority) {
    getline(file >> std::ws, title);
    if (id != idToRemove) {
      todoList.emplace_back(id, priority, title);
    }
    // if (id == idToRemove) {
    //   idFound = true;
    // }
  }
  file.close();

  // if (!idFound) {
  //   cerr << "#" << id << " doesn't exist" << endl;
  //   return;
  // }

  ofstream outFile(string(getenv("HOME")) + "/.cache/todo-cli/todo.txt",
                   std::ios::trunc);
  if (!outFile) {
    cerr << "Error: couldn't reopen file" << endl;
    return;
  }

  for (const auto &[id, priority, title] : todoList) {
    outFile << id << " " << priority << " " << title << endl;
  }
  outFile.close();
}

int main(i32 argc, char *argv[]) {
  if (argc < 2) {
    cerr << "Error: no command provided" << endl;
    return 1;
  }

  string command = argv[1];

  if (command == "list") {
    vector<tuple<i32, i32, string>> todoList = getTodo();
    displayTodo(todoList);
    return 1;

  } else if (command == "create") {
    if (argc < 4) {
      cerr << "Error: missing title and/or priority" << endl;
      return 1;
    }
    string title = argv[2];
    i32 priority = std::stoi(argv[3]);
    i32 id = createTodo(title, priority);
    cout << "Todo created: " << "#" << id << " " << title << endl;
    return 1;

  } else if (command == "close") {
    if (argc < 3) {
      cerr << "Error: missing id number" << endl;
      return 1;
    }
    i32 id = std::stoi(argv[2]);
    closeTodo(id);
    cout << "Todo closed: " << "#" << id << endl;
    return 1;
  } else if (command == "-v") {
    cout << "Todo\n" << APP_VERSION << endl;
    return 0;
  } else {
    cerr << "Error: command not found" << endl;
  }

  return 0;
}
