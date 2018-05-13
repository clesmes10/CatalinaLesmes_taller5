#include <iostream>
#include <cmath>
#include <ctime>
#include <math.h>
using namespace std;

//INICIALIZACION DE FUNCIONES
void condicioninicial(double* uviejito, double* uactual, double* unuevito, double L, double condicion,double dx, double enex);
void iniciemos(double* uviejito, double* uactual, double* unuevito, double constante, double enex);
void progresou(double* uviejito, double* uactual, double* unuevito, double constante, double enex);
void actualizau(double* uviejito, double* uactual, double* unuevito, double enex);
void dameu(double* uactual, double enex, double dx);

void condicioninicial(double* uviejito, double* uactual, double* unuevito, double L, double condicion, double dx, double enex){
  int i;
  for(i=0; i<enex; ++i){
    double equis = i*dx;
    if(equis<condicion){
      uviejito[i] = (equis*1.25)/L;
      uactual[i] = (equis*1.25)/L;
    }
    else{
      uviejito[i] = (5.0-5.0*equis)/L;
      uactual[i] = (5.0 -5.0*equis)/L;
    }
  }
}
void iniciemos(double* uviejito, double* uactual, double* unuevito, double constante, double enex){
  int i;
  for(i=1; 1< enex-1; ++i){
    uactual[i] = 2.0*uviejito[i]+ (1.0/2.0)*constante*(uviejito[i-1]-2.0*uviejito[i]+uviejito[i+1]);
  }
}
void progresou(double* uviejito, double* uactual, double* unuevito, double constante, double enex){
  int i;
  for(i=1; i< enex-1; ++i){
    unuevito[i] = 2.0*uactual[i] - 2.0*uviejito[i] + constante*(uactual[i-1] - 2.0*uactual[i] + uactual[i+1]);
  }
}
void actualizau(double* uviejito, double* uactual, double* unuevito, double enex){
  int i;
  for(i=0; i<enex; ++i){
    uviejito[i] = uactual[i];
    uactual[i] = unuevito[i];
  }
}
void dameu(double* uactual, double enex, double dx){
  int i;
  for(i=0; i<enex; ++i){
    double x = i*dx;
    cout << x << " " << uactual[i] << endl;
  }
}

    
  

//FUNCION MAIN QUE HACE TODO

int main(){
  double te = 40.0;
  double rho = 10.0;
  double ele = 100.0;
  double ce = pow((te/rho),0.5);
  double condicion = 0.8*ele;
  double tmax = 200.0;
  double dete = 0.01;
  double dequis = 0.01;
  int enex = (ele/dequis)+1;
  double enet = (tmax/dete)+1;
  double cons = (pow(ce,2)*pow(dete,2))/(pow(dequis, 2));
  double* uviejito;
  double* uahora;
  double* uadelante;
  uviejito = new double[enex];
  uahora = new double[enex];
  uadelante = new double[enex];
  int t;
  int i;
  
  //CONDICIONES INICIALES

  condicioninicial(uviejito, uahora, uadelante, ele, condicion, dequis, enex);
  
  //RECORRIDO EN TIEMPO
  while(t<tmax){
    for(i=0; i<200; ++i){
      uadelante[0] = 0;
      uadelante[enex-1] = 0;
      uahora[0]= 0;
      uahora[enex-1] = 0;
      iniciemos(uviejito, uahora, uadelante, cons, enex);
      progresou(uviejito, uahora, uadelante, cons, enex);
      actualizau(uviejito, uahora, uadelante, enex);
    }
    t = t+1;
  }
  //IMPRIME
  dameu(uahora, enex, dequis);
  return 0;
}

    
    
 
