#ifndef MULTIMULT_H_
#define MULTIMULT_H_

#include <maya/MPxNode.h>


class multiMult : public MPxNode
{
public:
    multiMult();
    virtual ~multiMult();

    static void* creator();
    static MStatus initialize();

    virtual MStatus compute(const MPlug& plug, MDataBlock& data);

public:
    static MTypeId id;
    static MObject aInput;
    static MObject aOutput;
};

#endif