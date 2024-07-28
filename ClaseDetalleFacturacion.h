#ifndef CLASEDETALLEFACTURACION_H_INCLUDED
#define CLASEDETALLEFACTURACION_H_INCLUDED

class DetalleFacturacion{
private:
    int numeroDeDetalleFactura;
    Fecha fechaActualD;
    char nombreDFacturacion[30];
    char apellidoDFacturacion[30];
    int numeroDDNI;
    float totalD;
    int cantServiciosD;
    int precioServicio;
    int idServicio;
    char nombreServicio[30];
    int cantidad;
    bool estado;
public:
    DetalleFacturacion(int numeroDeDetalleFact=0, int idServ=0, float pre=0, int cantS=0, const char *ns="", bool est=false,
                       Fecha f=0, const char *n="", const char *a="", const char *nS="NONE" ,int dni=0, float tot=0, int cant=0){
        numeroDeDetalleFactura=numeroDeDetalleFact;
        fechaActualD=f;
        strcpy(nombreDFacturacion,n);
        strcpy(apellidoDFacturacion,a);
        numeroDDNI=dni;
        totalD=tot;
        cantServiciosD=cantS;
        cantidad=cant;
        precioServicio=pre;
        idServicio=idServ;
        strcpy(nombreServicio,nS);
        estado=est;

    }
    /// sets
    void setNumeroDeDetalleFactura(int nDF){numeroDeDetalleFactura=nDF;}
    void setNombreDetalle(const char *n){strcpy(nombreDFacturacion,n);}
    void setApellidoDetalle(const char *a){strcpy(apellidoDFacturacion,a);}
    void setDNID(int d){numeroDDNI=d;}
    void setFechaActualD(Fecha f){fechaActualD=f;}
    void setIDServicio(int idS){idServicio=idS;}
    void setPrecioServicio(float pS){precioServicio=pS;}
    void setNombreServicio(const char *nS){strcpy(nombreServicio,nS);}
    void setCantidad(int c){cantidad=c;}
    void setCantS(int cS){cantServiciosD=cS;}
    void setTotal(float t){totalD=t;}
    void setEstado(bool e){estado=e;}
    /// gets
    int getNumeroDeDetalleFactura(){return numeroDeDetalleFactura;}
    const char *getNombreDetalle(){return nombreDFacturacion;}
    const char *getApellidoDetalle(){return apellidoDFacturacion;}
    const char *getNombreServicio(){return nombreServicio;}
    int getDNID(){return numeroDDNI;}
    Fecha getFechaActualD(){return fechaActualD;}
    int getIDServicio(){return idServicio;}
    float getPrecioServicio(){return precioServicio;}
    int getCantidad(){return cantidad;}
    int getCantS(){return cantServiciosD;}
    float getTotal(){return totalD;}
    bool getEstado(){return estado;}

    void MostrarDetalleFactura(){
        if(estado==true){
            cout<<endl;
            cout<<"NUMERO DE FACTURA: "<<numeroDeDetalleFactura<<'\t'<<'\t'<<'\t'<<'\t'<<'\t'<<'\t';
            cout<<"FECHA: ";
            fechaActualD.Mostrar();
            cout<<"--------------------------------------------------------------------------------------------"<<endl;
            cout<<"CLIENTE: "<<nombreDFacturacion<<" "<<apellidoDFacturacion<<endl;
            cout<<"DNI: "<<numeroDDNI<<endl<<endl;
            cout<<"ID PRODUCTO "<<'\t'<<'\t';
            cout<<"DESCRIPCION "<<'\t'<<'\t';
            cout<<"CANTIDAD "<<'\t';
            cout<<"PRECIO X UNI "<<'\t'<<endl<<endl;
        }
    }

    void mostrarServiciosDF(){
        if(estado==true){
            cout<<idServicio<<'\t'<<'\t'<<'\t';
            cout<<nombreServicio<<'\t'<<'\t';
            cout<<"x"<<cantidad<<'\t'<<'\t';
            cout<<precioServicio<<endl<<endl;
        }

    }

    void mostrarTotal(){
        cout<<'\t'<<'\t'<<'\t'<<'\t'<<'\t'<<'\t'<<'\t'<<" TOTAL: "<<totalD<<endl<<endl;
    }
};

#endif // CLASEDETALLEFACTURACION_H_INCLUDED
