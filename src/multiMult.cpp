#include "multiMult.h"
#include <maya/MFnNumericAttribute.h>
#include <maya/MGlobal.h>

MTypeId multiMult::id(0x87024);

MObject multiMult::aInput;
MObject multiMult::aOutput;


multiMult::multiMult() {}


multiMult::~multiMult() {}


void* multiMult::creator() { return new multiMult(); }


MStatus multiMult::initialize()
{
    MStatus status;
    MFnNumericAttribute nAttr;

    aInput = nAttr.create("input", "in", MFnNumericData::kFloat, 1.0);
    nAttr.setArray(true);
    nAttr.setWritable(true);
    nAttr.setStorable(true);
    nAttr.setReadable(true);
    nAttr.setKeyable(true);

    aOutput = nAttr.create("output", "out", MFnNumericData::kFloat, 1.0);
    nAttr.setWritable(false);
    nAttr.setStorable(false);

    status = addAttribute(aInput);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    status = addAttribute(aOutput);
    CHECK_MSTATUS_AND_RETURN_IT(status);

    status = attributeAffects(aInput, aOutput);
    CHECK_MSTATUS_AND_RETURN_IT(status);

    return MS::kSuccess;
}


MStatus multiMult::compute(const MPlug& plug, MDataBlock& data)
{
    MStatus status;

    if (plug == aOutput)
    {
        MArrayDataHandle inputArrayH = data.inputArrayValue(aInput, &status);
        CHECK_MSTATUS_AND_RETURN_IT(status);

        unsigned int numInputs = inputArrayH.elementCount(&status);
        CHECK_MSTATUS_AND_RETURN_IT(status);

        float outputValue = 1.0;

        for (unsigned int i = 0; i<numInputs; i++, inputArrayH.next())
        {
            float inputValue = inputArrayH.inputValue(&status).asFloat();
            CHECK_MSTATUS_AND_RETURN_IT(status);

            if (i == 0)
                outputValue = inputValue;
            else
                outputValue *= inputValue;
        }

        MDataHandle outputH = data.outputValue(aOutput);
        outputH.set(outputValue);
        data.setClean(plug);
    }
    else
        return MS::kUnknownParameter;

    return MS::kSuccess;
}
