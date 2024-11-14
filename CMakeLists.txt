cmake_minimum_required(VERSION 3.10)

# Project name
project(todo-cli VERSION 0.1.1)

# Define C++ standard
set(CMAKE_CXX_STANDARD 17)

# Add executable
add_executable(todo-cli src/main.cpp)

target_compile_definitions(todo-cli PRIVATE APP_VERSION="${PROJECT_VERSION}")

# Include directories (optional)
# include_directories(${PROJECT_SOURCE_DIR}/include)

# Link libraries (optional)
# target_link_libraries(MyExecutable ${PROJECT_SOURCE_DIR}/lib/my_library.a)

