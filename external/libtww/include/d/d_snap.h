#ifndef D_SNAP_H
#define D_SNAP_H

#include "JSystem/J3DGraphBase/J3DPacket.h"
#include "f_op/f_op_actor.h"
#include "addrs.h"

#define l_snap (*(dSnap_packet*)(l_snap_addr))

class dSnap_Obj {
public:
    /* 0x00 */ cXyz mCenter;
    /* 0x0C */ f32 mRadius;
    /* 0x10 */ f32 mHeight;
    /* 0x14 */ fpc_ProcID mActorPID;
    /* 0x18 */ u8 mPhoto;
    /* 0x19 */ u8 field_0x19;
    /* 0x1A */ u8 field_0x1a;
    /* 0x1B */ u8 field_0x1b;
    /* 0x1C */ s16 mCullAngle;
    /* 0x1E */ s16 mAngleY;
    /* 0x20 */ s32 mCapturedPixels;
    /* 0x24 */ f32 mCapturedRatio;
    /* 0x28 */ s16 mMinX;
    /* 0x2A */ s16 mMinY;
    /* 0x2C */ s16 mMaxX;
    /* 0x2E */ s16 mMaxY;
    /* 0x30 */ /* vtable */

public:
    virtual ~dSnap_Obj() {}

    void DebugArea2D() {}
    void GetActor() const {}
    void GetArg() const {}
    void GetDRRatio() {}
    void GetLen(Vec&) const {}
    s16 GetMinX() { return mMinX; }
    s16 GetMinY() { return mMinY; }
    s16 GetMaxX() { return mMaxX; }
    s16 GetMaxY() { return mMaxY; }
    int GetPhoto() const { return mPhoto; }
    void GetPoint() {}
    void SetDRRatio(f32) {}
    void SetPoint(s32) {}
    void drawCamRange() {}

};

static_assert(sizeof(dSnap_Obj) == 0x34);

class dSnap_RegistObjElm {
public:
    /* 0x00 */ dSnap_Obj m_obj;
    /* 0x34 */ f32 field_0x34;
    /* 0x38 */ /* vtable */

public:
    virtual ~dSnap_RegistObjElm() {}
    
};  // Size: 0x3C

class dSnap_packet : public J3DPacket {
public:
    virtual ~dSnap_packet() {}

    void DebugDraw() {}
    int GetResult() { return mResult; }
    u8 GetResultDetail() { return mResultDetail; }

    /* 0x010 */ int field_0x10;
    /* 0x014 */ int field_0x14;
    /* 0x018 */ dSnap_RegistObjElm m_tbl[0x3F];
    /* 0xEDC */ int mFlag;
    /* 0xEE0 */ int mResult;
    /* 0xEE4 */ u8 mResultDetail;

    static int (dSnap_packet::*m_judge_tbl[])();
};


inline void dSnap_AlphaClearDebug() {}
inline void dSnap_FigChkSizeNone(int) {}
inline void dSnap_MatDLDebug() {}
inline void dSnap_project(Vec*, Vec*) {}

#endif /* D_SNAP_H */
