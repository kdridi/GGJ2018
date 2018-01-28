//
//  Utils.hpp
//  myproject
//
//  Created by Karim DRIDI on 27/01/2018.
//

#ifndef Utils_hpp
#define Utils_hpp

#include <string>

#include "json.hpp"

namespace utils
{
    std::string getFullPath(std::string path);
    nlohmann::json& getRoomInformations(std::string name);
}

#endif /* Utils_hpp */
