//
//  FakeSceneA.hpp
//  myproject
//
//  Created by Karim DRIDI on 27/01/2018.
//

#ifndef FakeSceneA_hpp
#define FakeSceneA_hpp

#include "Scene.hpp"

class FakeSceneA : public Scene
{
public:
    virtual void init(Engine& engine);

    virtual ~FakeSceneA();
};

#endif /* FakeSceneA_hpp */
