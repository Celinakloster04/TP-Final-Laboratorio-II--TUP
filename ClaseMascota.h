#ifndef CLASEMASCOTA_H_INCLUDED
#define CLASEMASCOTA_H_INCLUDED

bool chequeoFecha(Fecha fecha);
bool generoAnimal(const char* genero);

class Mascota{
private:
    int dni;
    int numeroHC;
    char nombreMascota[30];
    char genero[10];
    int tipoAnimal;
    char raza[30];
    char color[30];
    char talla[30];
    float peso;
    Fecha fechaNacimiento;
    bool estado;

public:
    Mascota(int dni_=0, int hc=0, const char *nM="ninguno", const char *g="ninguno",int tA=0, const char *r="ninguno",
            const char *c="ninguno", const char *ta_="ninguno", float pe=0, Fecha f=Fecha(), bool est=false){
        dni=dni_;
        numeroHC=hc;
        strcpy(nombreMascota,nM);
        strcpy(genero,g);
        tipoAnimal=tA;
        strcpy(raza,r);
        strcpy(color,c);
        strcpy(talla,ta_);
        peso=pe;
        fechaNacimiento=f;
        estado=est;
    }


    void setNumeroHC(int a){numeroHC=a;}
    void setNombreMascota(const char *a){strcpy(nombreMascota,a);}
    void setGenero(const char *g){strcpy(genero,g);}
    void setTipoAnimal(int a){tipoAnimal=a;}
    void setRaza(const char *a){strcpy(raza,a);}
    void setColor(const char *a){strcpy(color,a);}
    void setTalla(const char *a){strcpy(talla,a);}
    void setPeso(float a){peso=a;}
    void setFechaNacimiento(Fecha f){fechaNacimiento=f;}
    void setEstado(bool e){estado=e;}
    void setDNI(int a){dni=a;}


    int getNumeroHC(){return numeroHC;}
    const char *getNombreMascota(){return nombreMascota;}
    const char *getGenero(){return genero;}
    int getTipoAnimal(){return tipoAnimal;}
    const char *getRaza(){return raza;}
    const char *getColor(){return color;}
    float getPeso(){return peso;}
    Fecha getFechaNacimiento(){return fechaNacimiento;}
    bool getEstado(){return estado;}
    const char *getTalla(){return talla;}
    int getDNI(){return dni;}


    bool CargarMascotaSinDni(){
        cout<<"INGRESE EL NOMBRE DE LA MASCOTA: "<<endl;
        cargarCadena(nombreMascota,29);
        cout<<"INGRESE EL GENERO : Macho - Hembra "<<endl;
        cargarCadena(genero, 9);
        if(generoAnimal(genero)==false){
            cout<<"GENERO INCORRECTO"<<endl;
             cout<<"INGRESE EL GENERO : Macho - Hembra "<<endl;
             cargarCadena(genero, 9);
           if(generoAnimal(genero)==false){
            return false;
           }
        }
        cout<<"INGRESE EL TIPO DE ANIMAL 1:CAN - 2:FELINO - 3:ROEDOR - 4:AVE - 5:REPTIL: "<<endl;
        cin>>tipoAnimal;
        if(tipoAnimal<1||tipoAnimal>5){
            cout<<"EL TIPO DE ANIMAL INGRESADO ES INCORRECTO "<<endl;
            return false;
        }
        cout<<"RAZA: "<<endl;
        cargarCadena(raza,29);
        cout<<"COLOR: "<<endl;
        cargarCadena(color, 29);
        cout<<"TALLA: "<<endl;
        cargarCadena(talla, 29);
        cout<<"PESO: "<<endl;
        cin>>peso;
        cout << "INGRESE FECHA NACIMIENTO"<<endl;
        if(fechaNacimiento.Cargar()==false){
            return false;
            estado=false;
        }
        estado=true;
        return true;
    }

    void MostrarMascota(){
        if(estado==true){
            cout<<"DNI DEL PROPIETARIO: "<<dni<<endl;
            cout<<"NUMERO DE HISTORIA CLINICA: "<<numeroHC<<endl;
            cout<<"NOMBRE: "<<nombreMascota<<endl;
            cout<<"GENERO :"<<genero<<endl;
            cout<<"TIPO DE ANIMAL: "<<tipoAnimal<<endl;
            cout<<"RAZA: "<<raza<<endl;
            cout<<"COLOR: "<<color<<endl;
            cout<<"TALLA: "<<talla<<endl;
            cout<<"PESO: "<<peso<<endl;
            cout<<"FECHA DE NACIMIENTO "<<endl;
            fechaNacimiento.Mostrar();
            cout<<endl;
        }
    }
};

bool chequeoFecha(Fecha fecha){
    time_t rawtime;
    struct tm * fechaActual;
    time ( &rawtime );
    fechaActual = localtime ( &rawtime );
    if (fecha.getAnio() > (fechaActual->tm_year + 1900)){
        return false;
    }
    if (fecha.getAnio() == fechaActual->tm_year + 1900){
        if (fecha.getMes() > fechaActual->tm_mon + 1){
            return false;
        }
        if (fecha.getMes() == fechaActual->tm_mon + 1 && fecha.getDia() > fechaActual->tm_mday){
            return false;
        }
    }
    return true;
}

bool generoAnimal(const char* generodelanimal){
    if(strcmp(generodelanimal,"Macho")==0||strcmp(generodelanimal,"macho")==0||strcmp(generodelanimal,"Hembra")==0||strcmp(generodelanimal,"hembra")==0){
        return true;
    }else{
        return false;
    }
}

#endif // CLASEMASCOTA_H_INCLUDED
