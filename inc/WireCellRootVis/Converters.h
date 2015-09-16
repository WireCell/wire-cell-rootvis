#ifndef WIRECELLROOTVIS_CONVERTERS
#define WIRECELLROOTVIS_CONVERTERS

#include "WireCellIface/IDepo.h"
#include "WireCellUtil/Point.h"

#include "TPolyMarker3D.h"

#include "TArrow.h"

namespace WireCellRootVis {

    /** Return a new TPolyMarker3D made from depositions. 
     */
    TPolyMarker3D* polymarker3d(const WireCell::IDepoVector& depos,
				int color=1, int marker = 6);
    
    TArrow* arrow(const WireCell::Ray& ray, int color=1);

    
}

#endif
