macro(make_asio_available)
    FetchContent_Declare(
        asio
        GIT_REPOSITORY https://github.com/chriskohlhoff/asio.git
        GIT_TAG        asio-1-36-0
        GIT_SHALLOW    ON)
    FetchContent_MakeAvailable(asio)
    set(asio_ROOT ${asio_SOURCE_DIR}/asio)
endmacro()

macro(make_crow_available)
    FetchContent_Declare(
        Crow
        GIT_REPOSITORY https://github.com/CrowCpp/Crow.git 
        GIT_TAG        v1.3.0
        GIT_SHALLOW    ON)
    FetchContent_MakeAvailable(Crow)
endmacro()

macro(make_btcpp_available)
    FetchContent_Declare(BehaviorTree.CPP
        GIT_REPOSITORY https://github.com/BehaviorTree/BehaviorTree.CPP 
        GIT_TAG        4.8.4
        GIT_SHALLOW    ON)
	set(BTCPP_SHARED_LIBS OFF)
    set(BTCPP_SQLITE_LOGGING OFF)
    set(BUILD_TESTING OFF)
    set(BTCPP_EXAMPLES OFF) 
    FetchContent_MakeAvailable(BehaviorTree.CPP)
endmacro()

macro(make_zeromq_available)
    FetchContent_Declare(zeromq
        GIT_REPOSITORY https://github.com/zeromq/libzmq.git
        GIT_TAG        v4.3.5
        GIT_SHALLOW    ON)
    set(ZMQ_BUILD_TESTS OFF CACHE BOOL "" FORCE)
	set(ZMQ_BUILD_STATIC ON CACHE BOOL "" FORCE)
	set(ZMQ_BUILD_SHARED OFF CACHE BOOL "" FORCE)
	set(ZMQ_ENABLE_DRAFTS OFF CACHE BOOL "" FORCE)
	set(ZMQ_BUILD_TESTS OFF CACHE BOOL "" FORCE)
	set(ZMQ_ENABLE_CPACK OFF CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(zeromq)
	list(PREPEND CMAKE_PREFIX_PATH ${zeromq_BINARY_DIR})
endmacro()
