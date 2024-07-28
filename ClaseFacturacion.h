#ifndef CLASEFACTURACION_H_INCLUDED
#define CLASEFACTURACION_H_INCLUDED

class Facturacion{
private:
    int numeroHC;
    int numeroDeFactura;
    Fecha fechaActual;
    char nombreFacturacion[30];
    char apellidoFacturacion[30];
    int numeroDNI;
    float total;
    int empleado;
    int cantServicios;
    bool estado;
public:
    Facturacion(int numFact=0, Fecha f=0, const char *n=" ", const char *a="",int dni=0, float tot=0, int emp=0, int canS=0,
                int hc=0,bool est=false){
        numeroDeFactura=numFact;
        numeroHC=hc;
        fechaActual=f;
        strcpy(nombreFacturacion,n);
        strcpy(apellidoFacturacion,a);
        numeroDNI=dni;
        total=tot;
        cantServicios=canS;
        empleado=emp;
        estado=est;
    }
    /// sets
    void setNumeroHC(int HC){numeroHC=HC;}
    void setNumeroDeFactura(int nF){numeroDeFactura=nF;}
    void setFechaActual (Fecha f){fechaActual=f;}
    void setNombreFacturacion (const char *n){strcpy(nombreFacturacion,n);}
    void setApellidoFacturacion (const char *a){strcpy(apellidoFacturacion,a);}
    void setNumeroDni (int dni){numeroDNI=dni;}
    void setTotal (float t){total=t;}
    void setCantServicios (int cS){cantServicios=cS;}
    void setEmpleado (int e){empleado=e;}
    void setEstado (bool est){estado=est;}
    /// gets
    int getNumeroHC(){return numeroHC;}
    int getNumeroDeFactura(){return numeroDeFactura;}
    Fecha getFechaActual(){return fechaActual;}
    const char *getNombreFacturacion(){return nombreFacturacion;}
    const char *getApellidoFacturacion(){return apellidoFacturacion;}
    int getNumeroDNI(){return numeroDNI;}
    float getTotal(){return total;}
    int getCantServicios(){return cantServicios;}
    int getEmpleado(){return empleado;}
    bool getEstado(){return estado;}


    void MostrarFactura(){
        if(estado==true){
            cout<<"NUMERO DE FACTURA: "<<numeroDeFactura<<'\t'<<'\t';
            cout<<"FECHA: ";
            fechaActual.Mostrar();
            cout<<"---------------------------------------------------"<<endl;
            cout<<"CLIENTE: "<<nombreFacturacion<<" "<<apellidoFacturacion<<'\t'<<'\t';
            cout<<"DNI: "<<numeroDNI<<endl;
            cout<<"EMPLEADO: "<<empleado<<endl;
            cout<<"CANTIDAD DE SERVICIOS: "<<cantServicios<<'\t';
            cout<<"TOTAL: "<<total<<endl;
            cout<<"****************************************************"<<endl;
        }
    }
};


#endif // CLASEFACTURACION_H_INCLUDED
