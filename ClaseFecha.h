#ifndef CLASEFECHA_H_INCLUDED
#define CLASEFECHA_H_INCLUDED

class Fecha{
private:
    int dia, mes, anio;
public:
    Fecha(int d=0, int m=0, int a=0){
        dia=d;
        mes=m;
        anio=a;
    }
    bool esAnterior(const Fecha& otraFecha) const{
        if (anio < otraFecha.anio){
            return true;
        }
        else if (anio == otraFecha.anio){
            if (mes < otraFecha.mes){
                return true;
            }
            else if (mes == otraFecha.mes){
                return dia < otraFecha.dia;
            }
        }
        return false;
    }

    bool Cargar(){

        cout<<"DIA: ";
        cin>>dia;
        if(dia<=0||dia>=32){
            cout<<"DIA INVALIDO "<<endl;
           return false;
        }
        cout<<"MES: ";
        cin>>mes;
        if(mes<=0||mes>=13){
            cout<<"MES INVALIDO "<<endl;
            return false;
        }
        cout<<"ANIO: ";
        cin>>anio;
        if(anio<=1920||anio>=2025){
            cout<<"ANIO INVALIDO "<<endl;
            return false;
        }
        return true;
    }

    void Mostrar(){
        cout<<dia<<"/"<<mes<<"/"<<anio<<endl;
    }
    ///sets
    void setDia(int x){if(x>0 && x<32)dia=x;}
    void setMes(int x){if(x>0 && x<13)mes=x;}
    void setAnio(int x){anio=x;}
    ///gets
    int getDia(){return dia;}
    int getMes(){return mes;}
    int getAnio(){return anio;}

    bool operator==(const Fecha& fec){
        if(dia!=fec.dia)return false;
        if(mes!=fec.mes)return false;
        if(anio!=fec.anio)return false;
        return true;
    }
};


#endif // CLASEFECHA_H_INCLUDED
