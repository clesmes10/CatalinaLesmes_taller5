#include <iostream>
#include <fstream>
#include <cmath>
using namespace std; 
 
//FUNCION MAIN QUE HACE TODO
int main(int argc, char const *argv[])
{
    int a;
    int b;
    int c;
    int ELE = 5;
    double hache = 5/512;
    int ene = 513;
    float dequis = 5.0/ene;
    int enecua = ene*ene;
    int enet = 2*enecua;
    int ENE= 2*enecua;
    float VP[ene][ene][2];
    int equiscero = (ene*(2.5-1.0)/5.0);
    int equis = (ene*(2.0)/5.0);
    int yecero = (ene*(2.5-0.5)/5.0);
    int ye = (ene*(1.0)/5.0);
    
 
    //INICIALIZA EN CEROS
    for (a = 0; a < ene; ++a){
        for (b = 0; b < ene; ++b){
            VP[a][b][0] = 0.0; 
            VP[a][b][1] = 0.0; 
        }
    }
    
    //SE ASIGNAN VALORES
    for (a = 0; a < ene; ++a){
        if (a==yecero){
            for (b= equiscero; b < equiscero+equis; ++b){
	      //ARRIBA
                VP[a][b][0] = 50.0; 
            }
        }
	else if(a==yecero+ye){
            for (b = equiscero; b < equiscero+equis; ++b){
	      //ABAJO
                VP[a][b][0] = -50.0;
            }
        }
    }   
 
    //SE RELAJA SISTEMA
    for (c = 0; c < ENE/50; ++c){
        for (a = 0; a < ene; ++a){
            for (b = 0; b < ene; ++b){
                if(a!=0 & a!=ene-1 & b!=0 & b!=ene-1){
                VP[a][b][1] = (VP[a+1][b][0] + VP[a-1][b][0] + VP[a][b+1][0] + VP[a][b-1][0])*0.25;
                }
            }
        }
 
	//SE REASIGNAN CONDICIONES, ACUALIZAN Y SE ASIGNAN VALORES 
        for (a = 0; a< ene; ++a){
            for (b= 0; b < ene; ++b){
	      VP[a][b][0] = VP[a][b][1];
            }
 
            if (a==yecero){
                for (b = equiscero; b < equiscero+equis; ++b){
                    VP[a][b][0] = 50;
                }
            }
	    else if(a==yecero+ye){
                for (b = equiscero; b < equiscero+equis; ++b){
                    VP[a][b][0] = -50;
                }
            }
        }   
    }
 
 
    //SALIDA DE DATOS
    ofstream plaquitasparalelas("placas.txt");
 
    for (a= 0; a < ene; ++a){
        for (b = 0; b < ene; ++b){
            plaquitasparalelas << VP[a][b][1] << " "; 
        }
    }
    plaquitasparalelas << "\n";
 
    //CAMPO ELECTRICO PARA X
    for (a= 0; a < ene; ++a){
        for (b = 0; b < ene; ++b){
            if (a!=0 & a!=ene-1 & b != 0 & b !=ene-1){
                plaquitasparalelas << -1.0*(VP[a][b+1][0]-VP[a][b][0])/dequis << " ";
            }
	    else{
                plaquitasparalelas << 0.0 << " ";
            }
        }
    }
    plaquitasparalelas << "\n";
 
    //CAMPO ELECTRICO PARA Y
    for (a = 0; a < ene; ++a){
        for (b = 0; b < ene; ++b){
            if (a!=0 & a!=ene-1 & b != 0 & b !=ene-1){
                plaquitasparalelas << -1.0*(VP[a+1][b][0]-VP[a][b][0])/dequis << " ";
            }
	    else{
                plaquitasparalelas << 0.0 << " ";
            }
        }
    }
    plaquitasparalelas << "\n";
 

    
    return 0;
}
