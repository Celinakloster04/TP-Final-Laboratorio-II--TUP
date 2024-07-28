#ifndef CLASEEMPLEADO_H_INCLUDED
#define CLASEEMPLEADO_H_INCLUDED


class Empleado{
private:
    int legajoEmpleado;
    char nombreyApellidoEmpleado[30];
    char especialidad[30];
    bool estado=true;
public:
    Empleado(int legajo=0, const char *nombyap="ninguno",const char *espec="ninguno", bool est=false){
        legajoEmpleado=legajo;
        strcpy(nombreyApellidoEmpleado,nombyap);
        strcpy(especialidad,espec);
        estado=est;
    }

    void setlegajo(int legajo){legajoEmpleado=legajo;}
    void setnombreyApellido(const char* nomYap){strcpy(nombreyApellidoEmpleado,nomYap);}
    void setespecialidad(const char* esp){strcpy(especialidad,esp);}
    void setEstado(bool e){estado = e;}

    int getlegajo(){return legajoEmpleado;}
    const char* getnombreyApellido(){return nombreyApellidoEmpleado;}
    const char* getespecialidad(){return especialidad;}
    bool getEstado(){return estado;}

     bool CargarEmpleado(){
        cout<<"INGRESE NOMBRE Y APELLIDO DEL EMPLEADO"<<endl;
        cargarCadena(nombreyApellidoEmpleado,29);
        cout<<"INGRESE ESPECIALIDAD"<<endl;
        cargarCadena(especialidad,29);
        estado=true;
        return true;
    }

     void MostrarEmpleado(){
        if(estado==true){
            cout<<"LEGAJO: "<<legajoEmpleado<<endl;
            cout<<"NOMBRE Y APELLIDO DEL EMPLEADO: "<<nombreyApellidoEmpleado<<endl;
            cout<<"ESPECIALIDAD: "<<especialidad<<endl;
        }
    }
};

#endif // CLASEEMPLEADO_H_INCLUDED
