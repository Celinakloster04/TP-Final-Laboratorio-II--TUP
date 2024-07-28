#ifndef CLASESERVICIO_H_INCLUDED
#define CLASESERVICIO_H_INCLUDED
void AgregarMASServicios (Fecha fechaServicio, int numeroHC, int numeroEmpleado, const char* observacion);
bool EmpleadoExiste(int numeroEmpleado);
bool HcExiste(int numeroHC);
void listarServicioPorNumeroHC();
bool servicioExiste(int);

class Servicio{
private:
    int numeroHC;
    int idServicio;
    int numeroEmpleado;
    char observacion[100];
    int cant;
    Fecha fechaServicio;
    bool estado=true;
public:
    Servicio(int idserv=0, int c=0, const char *d="ninguno",int  numE=0, Fecha f=Fecha(),bool est=false){
        idServicio=idserv;
        numeroHC=c;
        strcpy(observacion,d);
        numeroEmpleado=numE;
        estado=est;
    }

    void setNumeroHC(int a){numeroHC=a;}
    void setidServicio(int id){idServicio=id;}
    void setObservacion(const char* o){strcpy(observacion,o);}
    void setNumeroEmpleado(int emp){numeroEmpleado=emp;}
    void setFechaServicio(Fecha f){fechaServicio=f;}
    void setEstado(bool e){estado = e;}

    int getNumeroHC(){return numeroHC;}
    int getidServicio(){return idServicio;}
    const char *getObservacion(){return observacion;}
    Fecha getFechaServicio(){return fechaServicio ;}
    int getNumeroEmpelado(){return numeroEmpleado;}
    bool getEstado(){return estado;}


    bool CargarServicio(){
        cout<<"NUMERO DE HISTORIA CLINICA: ";
        cin>>numeroHC;
        if(HcExiste(numeroHC)==false){
            cout <<"NUMERO DE  HISTORIA CLINICA INEXISTENTE "<<endl;
            return false;
        }
        cout<<"INGRESE FECHA DE FACTURACION: "<<endl;
        if(fechaServicio.Cargar()==false){
            return false;
        }
        cout<<"NUMERO DE EMPLEADO: ";
        cin>>numeroEmpleado;
        if(EmpleadoExiste(numeroEmpleado)==false){
            cout <<"NUMERO DE EMPLEADO INEXISTENTE "<<endl;
            return false;
        }
        cout<<"OBSERVACION: ";
        cargarCadena(observacion, 99);
        cout<<"INGRESE ID DEL SERVICIO: ";
        cin>>idServicio;
        if(servicioExiste(idServicio)==false){
            cout<<"SERVICIO INEXISTENTE "<<endl;
            return false;
        }
        estado=true;
        AgregarMASServicios(fechaServicio, numeroHC, numeroEmpleado, observacion);
        return true;
    }

    void CargarServicioSinHcDia(){
        cout<<"INGRESE ID DEL SERVICIO(1 a 38): ";
        cin>>idServicio;
        if(servicioExiste(idServicio)==false){
            cout<<"SERVICIO INEXISTENTE "<<endl;
            return;
        }
        estado=true;
    }

    void MostrarServicio(){
        if(estado==true){
            cout<<"NUMERO DE HISTORIA CLINICA: "<<numeroHC<<endl;
            cout<<"FECHA DEL SERVICIO: ";
            fechaServicio.Mostrar();
            cout<<"NUMERO DE EMPLEADO: "<<numeroEmpleado<<endl;
            cout<<"OBSERVACION: " <<observacion<<endl;
            cout<<"EL ID DEL SERVICIO ES: "<<idServicio<<endl;
            cout<<"CANTIDAD: "<<cant<<endl;
            cout<<endl;
        }
    }
};


bool EmpleadoExiste(int numeroEmpleado){
    ArchivoEmpleado archiEmpleado("Empleados.dat");
    Empleado *vecEmp;
    int tam=archiEmpleado.contarRegistros();

    vecEmp=new Empleado[tam];

    for(int i=0; i<tam; i++){
        vecEmp[i]=archiEmpleado.leerRegistro(i);
    }
    for(int i=0; i<tam; i++){
       if(vecEmp[i].getlegajo()==numeroEmpleado && vecEmp[i].getEstado()==true){
            return true;
            delete []vecEmp;
       }
    }
    return false;
    delete []vecEmp;
}

bool HcExiste(int numeroHC){
    ArchivoMascota archiMascota("Mascotas.dat");
    Mascota obj;
    int  pos=archiMascota.buscarRegistro(numeroHC);
    obj=archiMascota.leerRegistro(pos);
    if(pos <0 || obj.getEstado()==false)     return false;

    else return true;
}

bool servicioExiste(int s){
    ArchivoDescripcionServicio archiDescS("DescripcionServicio.dat");
    int pos=archiDescS.buscarRegistro(s);
    if(pos<0){
        return false;
    }else return true;
}


#endif // CLASESERVICIO_H_INCLUDED
