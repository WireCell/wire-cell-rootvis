#include "WireCellRootVis/CanvasApp.h"
#include "WireCellRootVis/Converters.h"

using namespace WireCell;
using namespace WireCellRootVis;

int main(int argc, char* argv[])
{
    WireCellRootVis::CanvasApp app(argv[0], argc>1);

    Ray r(Point(0,0,0), Point(1,1,1));
    TArrow* ar = arrow(r);
    ar->Draw();
    app.pdf();
    app.run();

    return 0;
}
