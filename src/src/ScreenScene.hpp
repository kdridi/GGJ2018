//
//  ScreenScene.hpp
//  myproject
//
//  Created by Karim DRIDI on 28/01/2018.
//

#ifndef ScreenScene_hpp
#define ScreenScene_hpp

#include "Scene.hpp"

class ScreenScene : public Scene
{
public:
    ScreenScene(Engine& engine, int id);
    
    virtual void init();
    virtual void showNext();
private:
    int id;
};

#endif /* ScreenScene_hpp */
