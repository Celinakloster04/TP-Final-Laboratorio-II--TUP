#ifndef CLASEPROPIETARIO_H_INCLUDED
#define CLASEPROPIETARIO_H_INCLUDED
bool propietarioExiste(int);


class Propietario: public Mascota{
private:
    int DNI;
    char nombrePropietario[30];
    char apellido[30];
    int telefono;
    bool estado;

public:
    Propietario(int dni=0, const char *nP=" ", const char *aP=" ", int t=0, int nHC=0, bool est=false){
        DNI=dni;
        strcpy(nombrePropietario,nP);
        strcpy(apellido,aP);
        telefono=t;
        estado=est;
    }

    void setDNI(int a){DNI=a;}
    void setNombrePropietario(const char * a){strcpy(nombrePropietario,a);}
    void setApellido(const char * a){strcpy(apellido,a);}
    void setTelefono(int a){telefono=a;}
    void setEstado(bool e){estado=e;}

    int getDNI(){return DNI;}
    const char* getNombrePropietario(){return nombrePropietario;}
    const char* getApellido(){return apellido;}
    int getTelefono(){return telefono;}
    bool getEstado(){return estado;}

    bool CargarPropietario(){
        cout<<"DNI: ";
        cin>>DNI;
        if(DNI<=5000000 || DNI>70000000){
            cout<<"DOCUMENTO INEXISTENTE"<<endl;
            return false;
        }
        cout<<"NOMBRE: ";
        cargarCadena(nombrePropietario,29);
        cout<<"APELLIDO: ";
        cargarCadena(apellido,29);
        cout<<"TELEFONO: ";
        cin>>telefono;
        estado=true;

        return true;
    }

    void agregarMascota(int dni){
        ArchivoMascota archiMascota("Mascotas.dat");
        archiMascota.altaMascota(dni);
    }

    void MostrarPropietario(){
        if(estado==true){
            cout<<endl;
            cout<<"DNI: "<<DNI<<endl;
            cout<<"NOMBRE DEL PROPIETARIO:"<<nombrePropietario<<endl;
            cout<<"APELLIDO DEL PROPIETARIO: "<<apellido<<endl;
            cout<<"TELEFONO: "<<telefono<<endl;
        }
    }
};



#endif // CLASEPROPIETARIO_H_INCLUDED
