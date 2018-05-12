#include <iostream>
#include <cmath>
using namespace std;

// INICIALIZAR FUNCIONES DE DERIVADAS

double dq1dt(double q1, double q2, double p1, double p2);
double dq2dt(double q1, double q2, double p1, double p2);
double dp1dt(double q1, double q2, double p1, double p2, double epsilon);
double dp2dt(double q1, double q2, double p1, double p2, double epsilon);

double dq1dt(double q1, double q2, double p1, double p2){
  return p1;
}
double dq2dt(double q1, double q2, double p1, double p2){
  return p2;
}
double dp1dt(double q1, double q2, double p1, double p2, double epsilon){
  return -(2*q1)/(pow(((4*q1*q1)+(epsilon*epsilon)), 1.5));
}
double dp2dt(double q1, double q2, double p1, double p2, double epsilon){
  double uno = q1-q2;
  double dos = pow((pow(uno,2)+ pow(epsilon,2)/4), 1.5);
  double tres = q1+q2;
  double cuatro = pow((pow(tres, 2) + pow(epsilon,2)/4), 1.5);
  double p2punto = (uno/dos) - ( tres/cuatro);
  return p2punto;
}

// MAIN CON RUNGE KUTTA
int main(){
double dete = 0.006;
double tetotal = 3000;
double a = 1/(2*sqrt(2));
double epsi = 0.1;
double p1inicial = 0;
double q1inicial = a;
double p2inicial = 0;
double q2inicial = -a;

double k1p1 =0;
double k1p2 = 0;
double k1q1 = 0;
double k1q2 = 0;
double k2p1 = 0;
double k2p2 = 0;
double k2q1 = 0;
double k2q2 = 0;
double k3p1 = 0;
double k3p2 = 0;
double k3q1 = 0;
double k3q2 = 0;
double k4p1 = 0;
double k4p2 = 0;
double k4q1 = 0;
double k4q2 = 0;
int i;
double q1nuevo =0;
double q2nuevo =0;
double p1nuevo =0;
double p2nuevo =0;


for(i=0; i<tetotal; ++i){

//K1 PARA LAS CUATRO VARIABLES

k1q1 = dq1dt(q1inicial, q2inicial, p1inicial, p2inicial);
k1q2 = dq2dt(q1inicial, q2inicial, p1inicial, p2inicial);
k1p1 = dp1dt(q1inicial, q2inicial, p1inicial, p2inicial, epsi);
k1p2 = dp2dt(q1inicial, q2inicial, p1inicial, p2inicial, epsi);

//K2 PARA LAS CUATRO VARIABLES

k2q1= dq1dt(q1inicial + (dete/2)*k1q1, q2inicial + (dete/2)*k1q2, p1inicial + (dete/2)*k1p1, p2inicial + (dete/2)*k1p2);
k2q2 = dq2dt(q1inicial + (dete/2)*k1q1, q2inicial + (dete/2)*k1q2, p1inicial + (dete/2)*k1p1, p2inicial + (dete/2)*k1p2);
k2p1 = dp1dt(q1inicial + (dete/2)*k1q1, q2inicial + (dete/2)*k1q2, p1inicial + (dete/2)*k1p1, p2inicial + (dete/2)*k1p2, epsi);
k2p2 = dp2dt(q1inicial + (dete/2)*k1q1, q2inicial + (dete/2)*k1q2, p1inicial + (dete/2)*k1p1, p2inicial + (dete/2)*k1p2, epsi);

//K3 PARA LAA CUATRO VARIABLES

k3q1 = dq1dt(q1inicial + (dete/2)*k2q1, q2inicial + (dete/2)*k2q2, p1inicial + (dete/2)*k2p1, p2inicial + (dete/2)*k2p2);
k3q2 = dq2dt(q1inicial + (dete/2)*k2q1, q2inicial + (dete/2)*k2q2, p1inicial + (dete/2)*k2p1, p2inicial + (dete/2)*k2p2);
k3p1 = dp1dt(q1inicial + (dete/2)*k2q1, q2inicial + (dete/2)*k2q2, p1inicial + (dete/2)*k2p1, p2inicial + (dete/2)*k2p2, epsi);
k3p2 = dp2dt(q1inicial + (dete/2)*k2q1, q2inicial + (dete/2)*k2q2, p1inicial + (dete/2)*k2p1, p2inicial + (dete/2)*k2p2, epsi);

//K4 PARA LAS CUATRO VARIABLES

k4q1 = dq1dt(q1inicial + (dete)*k3q1, q2inicial + (dete)*k3q2, p1inicial + (dete)*k3p1, p2inicial + (dete)*k3p2);
k4q2 = dq2dt(q1inicial + (dete)*k3q1, q2inicial + (dete)*k3q2, p1inicial + (dete)*k3p1, p2inicial + (dete)*k3p2);
k4p1 = dp1dt(q1inicial + (dete)*k3q1, q2inicial + (dete)*k3q2, p1inicial + (dete)*k3p1, p2inicial + (dete)*k3p2, epsi);
k4p2 = dp2dt(q1inicial + (dete)*k3q1, q2inicial + (dete)*k3q2, p1inicial + (dete)*k3p1, p2inicial + (dete)*k3p2, epsi);

//AVANZAR CON RUNGE KUTTA
q1nuevo = q1inicial+(1.0/6.0)*(k1q1 + 2*k2q1 + 2*k3q1 + k4q1)*dete;
q2nuevo = q2inicial+(1.0/6.0)*(k1q2 + 2*k2q2 + 2*k3q2 +k4q2)*dete;
p1nuevo = p1inicial+(1.0/6.0)*(k1p1 + 2*k2p1+ 2*k3p1 + k4p1)*dete;
p2nuevo = p2inicial+(1.0/6.0)*(k1p2 + 2*k2p2 +2*k3p2 + k4p2)*dete;

//REVISAR SIGNO

if(q1inicial*q1nuevo < 0){
cout << q2nuevo << " " << p2nuevo << endl;
}
//PREPARAR SIG ITERACION

q1inicial = q1nuevo;
q2inicial = q2nuevo;
p1inicial = p1nuevo;
p2inicial = p2nuevo;


}

return 0;
}




  
