#ifndef TOOLBAR_HPP
#define TOOLBAR_HPP

#include "editor.hpp"
#include <string>

class ToolBar
{
private:

    // toolbar button id-s:
    enum ToolboxButtonIndex
    {
        TBI_NEW,
        TBI_OPEN,
        TBI_SAVE,
        TBI_SAVE_AS,
        TBI_REDO,
        TBI_UNDO,
        TBI_CAM_1,
        TBI_CAM_2,
        TBI_SELECT,
        TBI_MOVE,
        TBI_ROTATE,
        TBI_DELETE,
        TBI_GRID_ON_OFF,
        TBI_GRID_INC,
        TBI_GRID_DEC,
        TBI_TRY,
        TBI_SETTINGS,
        TBI_EXIT
    };

    // private variables:

    static ToolBar* m_toolbar;

    IGUIToolBar*    m_bar;
    IGUIButton*     m_buttons[18];

    // private functions:

    void            init(unsigned int screen_x);
    ITexture*       loadImg(const char* file_path);
    void            buttonInit(unsigned int ix, ToolboxButtonIndex TBI, 
                    const char* file_path, const wchar_t* text);
    ToolBar() {};

public:
    static ToolBar* getToolBar(unsigned int screen_x = 1024);
    void reallocate(unsigned int screen_x);
};

#endif