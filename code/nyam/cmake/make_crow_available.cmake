
macro(make_crow_available)
    FetchContent_Declare(
        Crow
        GIT_REPOSITORY https://github.com/CrowCpp/Crow.git 
        GIT_TAG        v1.3.0
        GIT_SHALLOW    ON)
    FetchContent_MakeAvailable(Crow)
endmacro()
