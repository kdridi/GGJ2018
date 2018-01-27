//
//  Utils.cpp
//  myproject
//
//  Created by Karim DRIDI on 27/01/2018.
//

#include "Utils.hpp"

#include <algorithm>
#include <sstream>

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

std::string utils::getFullPath(std::string path)
{
    static std::string assetsDir;
    
    if (assetsDir.empty())
    {
        std::stringstream ss;
        ss << dirname(__FILE__);
        ss << "/../assets";
        
        assetsDir = ss.str();
    }
    
    std::stringstream ss;
    ss << assetsDir;
    ss << "/";
    ss << path;
    
    return ss.str();
}

