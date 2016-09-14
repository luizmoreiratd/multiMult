#include "multiMult.h"
#include <maya/MFnPlugin.h>


// Standard plugin register and deregister functions
MStatus initializePlugin(MObject obj)
{
    MStatus status;
    MString version("0.1.0");

    MFnPlugin fnPlugin(obj, "Luiz Philippe Moreira", version.asChar(), "Any");

    status = fnPlugin.registerNode("multiMult",
                                   multiMult::id,
                                   multiMult::creator,
                                   multiMult::initialize);
    CHECK_MSTATUS_AND_RETURN_IT(status);

    cerr << "multiMult: " << version << endl;

    return MS::kSuccess;
}


MStatus uninitializePlugin(MObject obj)
{
    MStatus status;
    MFnPlugin plugin(obj);

    status = plugin.deregisterNode(multiMult::id);
    CHECK_MSTATUS_AND_RETURN_IT(status);

    return status;
}