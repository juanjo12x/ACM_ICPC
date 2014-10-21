#include <iostream>
#include <cstdio>

using namespace std;

bool isLeap(int anho){
    if(anho%4==0){
        if(anho%100==0 && anho%400 != 0){
            return false;
        }else{
            return true;
        }
    }
    return false;
}

int main(){
    
    int anho, mes, dia;
    while(scanf("%d-%d-%d",&anho,&mes,&dia)!= EOF){
        int cuenta = 11;
        for(int i = 1600; i < anho;i+=100){
            if(!isLeap(i)){
                cuenta++;
            }
        }
       // cout << cuenta<<endl;
        if(!isLeap(anho) && anho % 100 == 0){
            if(mes >= 3 ){
                cuenta++;
            }
            if( (dia==29 && mes ==2)){
                dia = 1;
                mes = 3;
            }
        }
        
        
        
        int meses[] = {31,28,31,30,31,30,31,31,30,31,30,31};
        int mesesb[] = {31,29,31,30,31,30,31,31,30,31,30,31};
       // cout << cuenta << endl;
        for(int j = 0; j < cuenta; j++){
            if(isLeap(anho)){
                if(dia+1 > mesesb[mes-1]){
                    dia=1; 
                     if(mes+1>12){
                        mes=1;
                        anho++;
                        
                    }else{
                        mes++;
                    }
                }else{
                    dia++;                    
                    
                }
                
            }else{
                if(dia+1 > meses[mes-1]){
                    dia=1; 
                     if(mes+1>12){
                        mes=1;
                        anho++;
                        
                    }else{
                        mes++;
                    }
                }else{
                    dia++;                    
                    
                } 
            }   
       
        }  
        
        cout << anho <<"-";
        if(mes <=9){
            cout << "0"<<mes<<"-";
        }else{
            cout << mes<<"-";
        }
        if(dia <= 9){
            cout << "0"<<dia<<endl;
        }else{
            cout << dia << endl;
        }
        
        
        
    
    }
    return 0;
    

}
