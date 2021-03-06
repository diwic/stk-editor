#ifndef AZTEC_CAMERA_HPP
#define AZTEC_CAMERA_HPP

#include <irrlicht.h>

using namespace irr;
using namespace core;
using namespace scene;

struct Mouse;
struct Keys;
class  Indicator;

class AztecCamera
{
private:
    ICameraSceneNode*       m_cam;

    Mouse*                  m_mouse;
    Keys*                   m_keys;

    Indicator*              m_indicator;

    f32                     m_normal_cd;

    f32                     m_cx, m_cz;

    bool                    m_mmb_move;
    ISceneCollisionManager* m_iscm;

    void                    setOrientation(vector3df dir, vector3df up = vector3df(0, 1, 0));
    void                    setHeight(bool new_indi = false);
    void                    processKeys(f32 dt);
    void                    processMouse(f32 dt);
    void                    moveWithMouse();

public:
    AztecCamera(ICameraSceneNode* c, Mouse* m, Keys* k);
    void animate(f32 dt);

    vector3df               getTransformedXdir();
    vector3df               getTransformedYdir();
    vector3df               getTransformedZdir();

    void                    init(f32 x, f32 z);
    void                    restore();

    ICameraSceneNode*       Cam()                   { return m_cam;                }
    Indicator*              getIndicator()          { return m_indicator;          }
    vector3df               Pos()                   { return m_cam->getPosition(); }
};

#endif
