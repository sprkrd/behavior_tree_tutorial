
macro(make_btcpp_available)
    FetchContent_Declare(BehaviorTree.CPP
        GIT_REPOSITORY https://github.com/BehaviorTree/BehaviorTree.CPP 
        GIT_TAG        4.8.4
        GIT_SHALLOW    ON)
    set(BTCPP_SQLITE_LOGGING OFF)
    set(BUILD_TESTING OFF)
    set(BTCPP_EXAMPLES OFF) 
    FetchContent_MakeAvailable(BehaviorTree.CPP)
endmacro()

