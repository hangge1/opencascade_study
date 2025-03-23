//#include <vtkAutoInit.h>


//VTK_MODULE_INIT(vtkRenderingStyle)
//VTK_MODULE_INIT(vtkRenderingOpenGL2)

//#define vtkRenderingCore_AUTOINIT 1(vtkRenderingStyle)
//#define vtkRenderingCore_AUTOINIT 1(vtkRenderingOpenGL2)

//#define vtkRenderingCore_AUTOINIT 3(vtkInteractionStyle,vtkRenderingFreeType,vtkRenderingOpenGL2)

#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkInteractorStyleTrackballCamera.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkPolyDataMapper.h>



#include <BRepPrimAPI_MakeBox.hxx>
#include <IVtkTools_ShapeDataSource.hxx>

int main()
{
    BRepPrimAPI_MakeBox mkBox(1., 2., 3.);
    const TopoDS_Shape& shape = mkBox.Shape();

    vtkNew<vtkRenderWindow> renwin;
    vtkNew<vtkRenderer> ren;
    renwin->AddRenderer(ren);
    renwin->SetWindowName("TestOCC");

    vtkNew<vtkRenderWindowInteractor> interactor;
    vtkNew<vtkInteractorStyleTrackballCamera> style;
    interactor->SetInteractorStyle(style);
    interactor->SetRenderWindow(renwin);

    //Domain Data(TopoDS_Shape) -> vtkPolyData -> mapeer -> actor
    
    vtkNew<IVtkTools_ShapeDataSource> occSource;
    occSource->SetShape(new IVtkOCC_Shape(shape));

    vtkNew<vtkPolyDataMapper> mapper;
    mapper->SetInputConnection(occSource->GetOutputPort());

    vtkNew<vtkActor> actor;
    actor->SetMapper(mapper);
    ren->AddActor(actor);



    renwin->Render();
    interactor->Start();

    return 0;
}
