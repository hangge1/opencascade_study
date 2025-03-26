

#include "Viewer.h"

#include <BRepPrimAPI_MakeBox.hxx>
#include <BRepTools.hxx>

/*
    AIS(Application Interactive Services)
    TKServer.lib

    Visualize

    Vtk  vs AIS

    AIS: 
    1 Performance 
    2 

    Vtk
    1 CAD - Meshes
    2 CAE / FEA
    3 Community
*/

int main(int argc, char** argv)
{
    Viewer viewer(50,50, 500, 500);
    
    TopoDS_Shape shape;
    if (argc > 1)
    {
        BRep_Builder bbuilder;   
        if (!BRepTools::Read(shape, argv[1], bbuilder))
        {
            return -1;
        }
    }

    // Visualize
    viewer << shape;//BRepPrimAPI_MakeBox(10, 20, 30);


    viewer.StartMessageLoop();

    return 0;
}
