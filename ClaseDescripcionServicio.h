#ifndef CLASEDESCRIPCIONSERVICIO_H_INCLUDED
#define CLASEDESCRIPCIONSERVICIO_H_INCLUDED

class DescripcionServicio{
private:
    int idServicio;
    char descripcion[50];
    float precio;
    bool estado=true;
public:
    DescripcionServicio(int id=0, const char* desc="no hay descripcion",float prec=0, bool est=false){
        idServicio=id;
        strcpy(descripcion,desc);
        precio=prec;
        estado=est;
    }

    void setidservicio(int id){idServicio=id;}
    void setdescripcion(const char* descr){strcpy(descripcion,descr);}
    void setprecio(float pre){precio=pre;}
    void setEstado(bool e){estado = e;}

    int getidservicio(){return idServicio;}
    const char* getdescripcion(){return descripcion;}
    float getprecio(){return precio;}
    bool getEstado(){return estado;}

     bool CargarDescripcionServicio(){
        cout<<"INGRESE EL ID DEL SERVICIO"<<endl;
        cin>>idServicio;
        if(idServicio<0){
            cout<<"NUMERO SERVICIO INVALIDO "<<endl;
            return false;
    }
        cout<<"INGRESE LA DESCRIPCION"<<endl;
        cargarCadena(descripcion,49);
        cout<<"INGRESE EL PRECIO DEL SERVICIO"<<endl;
        cin>>precio;
        if(precio<1){
           cout<<"PRECIO NO VALIDO "<<endl;
          return false;
        }
        estado=true;
        return true;
    }

     void MostrarDescripcionServicio(){
        if(estado==true){
            cout<<"EL ID DEL SERVICIO ES: "<<idServicio<<endl;
            cout<<"LA DESCRIPCION DEL SERVICIO ES : "<<descripcion<<endl;
            cout<<"EL PRECIO DEL SERVICIO ES : "<<precio<<endl;
        }
    }
};

#endif // CLASEDESCRIPCIONSERVICIO_H_INCLUDED
