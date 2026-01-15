
macro(make_asio_available)
    FetchContent_Declare(
        asio
        GIT_REPOSITORY https://github.com/chriskohlhoff/asio.git
        GIT_TAG        asio-1-36-0
        GIT_SHALLOW    ON)
    FetchContent_MakeAvailable(asio)
    set(asio_ROOT ${asio_SOURCE_DIR}/asio)
endmacro()
