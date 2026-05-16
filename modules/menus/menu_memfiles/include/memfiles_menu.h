#include "menu.h"

enum MemfilesIndex {
    MEMFILE_SLOT_INDEX,
    MEMFILE_SAVE_INDEX,
    MEMFILE_LOAD_INDEX,
    MEMFILE_DELETE_INDEX,

    MEMFILE_INDEX_COUNT,
};

class MemfilesMenu : public Menu {
public:
    MemfilesMenu(Cursor&);
    virtual ~MemfilesMenu();
    virtual void draw();

private:
    Line lines[MEMFILE_INDEX_COUNT];
};