## custom package
    mkdir -p ~/<ws_name>/src/<package_dir_name>
    cd <ws_name>/src
    catkin_create_pkg <package_dir_name> <dependency 1: std_msgs> <d2: roscpp> <d3: rospy>

## copy custom_packages to ws
    cp -r <package_location> ~/<ws_name>/src/<package_dir_name>
    
## edit cmake
    sudo nano <package_dir_name>/CMakeLists.txt

#### add to CMakelist.txt(cpp)
> include_directories(include ${catkin_INCLUDE_DIRS})
>
> add_executable(talker src/<package>.cpp)  
> target_link_libraries(<package> ${catkin_LIBRARIES})  
> add_dependencies(<package> <package_dir_name>_generate_messages_cpp)

#### add to CMakelist.txt(python)
    
> catkin_install_python(PROGRAMS    
>     (<name of the file>).py  
>     DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}) 
    

## running new packages
    cd <ws_name>
    catkin_make
    source <ws_name>/devel/setup.zsh
    rosrun <package_dir_name> <package>
