//
//  Utils.cpp
//  myproject
//
//  Created by Karim DRIDI on 27/01/2018.
//

#include "Utils.hpp"

#include <algorithm>
#include <sstream>
#include <fstream>
#include <map>

static std::string GetCurrentWorkingDir(void);
#ifdef NDEBUG

#include <stdio.h>

#ifdef WINDOWS_VERSION
#   include <direct.h>
#   define GetCurrentDir _getcwd
#else
#   include <unistd.h>
#   define GetCurrentDir getcwd
#endif

#include<iostream>

static std::string GetCurrentWorkingDir(void) {
    char buff[FILENAME_MAX];
    GetCurrentDir( buff, FILENAME_MAX );
    std::string current_working_dir(buff);
    
    std::stringstream ss;
    ss << current_working_dir;
    ss << "/assets";
    
    std::cout << ">>>>[" << ss.str() << "]<<<<" << std::endl;
    
    return ss.str();
}

#else

static std::string dirname(const std::string & path);

std::string dirname(const std::string & path)
{
    if(path == "")
    {
        return std::string("");
    }
#if defined (WIN32)
    char del('\\');
#else
    char del('/');
#endif
    // http://stackoverflow.com/questions/5077693/dirnamephp-similar-function-in-c
    std::string::const_reverse_iterator last_slash =
    std::find(
              path.rbegin(),
              path.rend(),del);
    if( last_slash == path.rend() )
    {
        // No slashes found
        return std::string(".");
    }else if(1 == (last_slash.base() - path.begin()))
    {
        // Slash is first char
        return std::string(&del);
    }else if(path.end() == last_slash.base() )
    {
        // Slash is last char
        std::string redo = std::string(path.begin(),path.end()-1);
        return dirname(redo);
    }
    return std::string(path.begin(),last_slash.base()-1);
}

static std::string GetCurrentWorkingDir(void)
{
    std::stringstream ss;
    ss << dirname(__FILE__);
    ss << "/../assets";
    return ss.str();
}

#endif

std::string utils::getFullPath(std::string path)
{
    static std::string assetsDir;
    
    if (assetsDir.empty())
        assetsDir = GetCurrentWorkingDir();

    std::stringstream ss;
    ss << assetsDir;
    ss << "/";
    ss << path;
    
    return ss.str();
}

nlohmann::json& utils::getRoomInformations(std::string name)
{
    static std::map<std::string, nlohmann::json> files;
    
    if (files.find(name) == files.end())
    {
        std::stringstream ss;
        ss << "rooms/" << name << ".json";
        
        std::ifstream i(getFullPath(ss.str()));
        i >> files[name];
    }
    
    return files[name];
}



