add_executable(nyam_full_example main.cpp)
target_link_libraries(nyam_full_example BT::behaviortree_cpp Crow::Crow)
