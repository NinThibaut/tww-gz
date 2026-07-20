#include "menu.h"

enum MemfilesIndex {
    MEMFILE_SLOT_INDEX,
    MEMFILE_SAVE_INDEX,
    MEMFILE_LOAD_INDEX,
    MEMFILE_DELETE_INDEX,

    MEMFILE_INDEX_COUNT,
};

struct PermanantData {
    Cursor cursor;
    u8 memfileIndex = 1;
};

class MemfilesMenu : public Menu {
public:
    MemfilesMenu(PermanantData&);
    virtual ~MemfilesMenu();
    virtual void draw();

private:
    Line lines[MEMFILE_INDEX_COUNT];
    u8* l_fileNo;
};