

#include "Viewer.h"

#include <BRepPrimAPI_MakeBox.hxx>
#include <BRepTools.hxx>
#include <IGESControl_Reader.hxx>


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
    
  
    IGESControl_Reader reader;
    IFSelect_ReturnStatus status = reader.ReadFile("C:\\Users\\hangdada\\Desktop\\test.iges");
    if (status != IFSelect_RetDone) {
        std::cerr << "无法读取IGES文件" << std::endl;
        return 1;
    }

    reader.TransferRoots();
    TopoDS_Shape shape = reader.OneShape();

    // Visualize
    viewer << shape;//BRepPrimAPI_MakeBox(10, 20, 30);


    viewer.StartMessageLoop();

    return 0;
}
