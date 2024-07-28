#ifndef ARCHIVODESCRIPCIONSERVICIO_H_INCLUDED
#define ARCHIVODESCRIPCIONSERVICIO_H_INCLUDED

class ArchivoDescripcionServicio{
private:
    char nombre[30];
public:
    ArchivoDescripcionServicio(const char *_nombre){
    strcpy(nombre,_nombre);
    }
    void altaDescripcionServicio(){
        DescripcionServicio obj;
        obj.CargarDescripcionServicio();
        int pos=buscarRegistro(obj.getidservicio());

        if(pos != -1){
            cout<<"YA EXISTE UN SERVICIO IGUAL EN EL ARCHIVO "<<endl;
            obj.setEstado(false);
        }else if(obj.getEstado()==true){
            grabarRegistro(obj);
            cout<<"SE GRABO EL REGISTRO CORRECTAMENTE"<<endl;

        }else{
            cout<<"NO SE PUDO GRABAR EL REGISTRO"<<endl;

        }
    }

     void grabarRegistro(DescripcionServicio obj){
        FILE *p;
        p=fopen(nombre, "ab");
        if(p==NULL){
            cout<<"ERROR DE ARCHIVO "<<endl;
            return;
        }
        fwrite(&obj, sizeof (DescripcionServicio), 1, p);
        fclose(p);
    }

    int buscarRegistro(int num){
        DescripcionServicio obj;
        int cant=contarRegistros();

        for(int i=0; i<cant; i++){
            obj = leerRegistro(i);
            if(obj.getidservicio()==num){
                return i;
            }
        }
        return -1;
    }


    DescripcionServicio leerRegistro(int pos){
        DescripcionServicio obj;
        FILE *p;
        p=fopen(nombre,"rb");
        if(p==NULL){
            cout<<"ERROR DE ARCHIVO "<<endl;
            obj.setidservicio(-2);
            return obj;
        }
        fseek(p, pos * sizeof(DescripcionServicio), 0);
        fread(&obj, sizeof (DescripcionServicio), 1, p);
        fclose(p);
        return obj;
    }

    int contarRegistros(){
        FILE *p;
        p=fopen(nombre,"rb");

        if(p==NULL){

            return -1;
        }
        fseek(p, 0, 2);
        int cantBytes = ftell(p);
        fclose(p);
        int registro;
        registro= cantBytes/sizeof(DescripcionServicio);

        return registro;
    }

    void modificarRegistro(DescripcionServicio obj, int pos){
        FILE *p;
        p=fopen(nombre, "rb+");
        if(p==NULL){
            cout<<"ERROR DE ARCHIVO"<<endl;
            return;
        }
        fseek(p, pos * sizeof (DescripcionServicio) , 0);
        fwrite(&obj, sizeof (DescripcionServicio), 1, p);
        fclose(p);
    }


    void listardescripcion(){
        DescripcionServicio obj;
        int cant=contarRegistros();

        for(int i=0; i<cant; i++){
            obj =leerRegistro(i);
            obj.MostrarDescripcionServicio();
       if(obj.getEstado()==true)
            cout<<endl;
        }
    }


    void modificarPrecioServicio(){
        int id;
        cout<<"INGRESE EL ID QUE DESEA MODIFICAR: ";
        cin>>id;
        int pos=buscarRegistro(id);
        if(pos<0){
            cout<<"EL ID INGRESADO NO EXISTE EN EL ARCHIVO"<<endl;
            system("pause");
            return;
        }

        DescripcionServicio obj;
        obj = leerRegistro(pos);
        float nuevoprecio;
        cout<<"INGRESE EL NUEVO PRECIO DEL ID INGRESADO: ";
        cin>>nuevoprecio;
        if(nuevoprecio>0){
            obj.setprecio(nuevoprecio);
            modificarRegistro(obj, pos);
            cout<<"EL NUEVO PRECIO DEL FUE MODIFICADO CORRECTAMENTE :-)"<<endl;
                system("pause");
        } else {
            cout<<"PRECIO INCOHERENTE! "<<endl;
            system("pause");
            return;
        }
    }


    bool RealizarCopiaSeguridad(const char *nombreAr="DescripcionServicios.bkp"){
        FILE *pBackup;
        DescripcionServicio obj;

        pBackup = fopen(nombreAr,"wb");
        if( pBackup == NULL){
            cout<<"ERROR DE ARCHIVO"<<endl;
            return false;
        }
        int cantReg = contarRegistros();
        for(int i=0;i<cantReg;i++){
              obj=leerRegistro(i);
                fwrite(&obj, sizeof (DescripcionServicio), 1, pBackup);
        }
        fclose(pBackup);

        return true;
    }

    bool restaurarArchivoConBackup(){
        FILE *p;
        DescripcionServicio obj;
        ArchivoDescripcionServicio archiBackup("DescripcionServicios.bkp");

        int cantReg = archiBackup.contarRegistros();

        p = fopen(nombre,"wb");
        if(p== NULL){
            return false;
        }

        for(int i=0;i<cantReg;i++){
                obj=archiBackup.leerRegistro(i);
                fwrite(&obj, sizeof (DescripcionServicio), 1, p);
        }
        fclose(p);
        return true;
    }


};


#endif // ARCHIVODESCRIPCIONSERVICIO_H_INCLUDED
