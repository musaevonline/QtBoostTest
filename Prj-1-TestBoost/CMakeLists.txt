cmake_minimum_required(VERSION 2.8)

project(Project-1-TestBoost)
find_package(Boost COMPONENTS system thread REQUIRED)

add_executable(Client client.cpp)
target_link_libraries(Client  ${Boost_LIBRARIES})

add_executable(Server server.cpp)
target_link_libraries(Server  ${Boost_LIBRARIES})
