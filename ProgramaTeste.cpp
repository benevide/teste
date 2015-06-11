#pragma config(Sensor, in1,    esq,            sensorLineFollower)
#pragma config(Sensor, in2,    esq0,           sensorLineFollower)
#pragma config(Sensor, in3,    centro,         sensorLineFollower)
#pragma config(Sensor, in4,    dir0,           sensorLineFollower)
#pragma config(Sensor, in5,    dir,            sensorLineFollower)
#pragma config(Sensor, dgtl1,  USmeio,         sensorSONAR_cm)
#pragma config(Sensor, dgtl3,  USesq,          sensorSONAR_cm)
#pragma config(Sensor, dgtl5,  USdir,          sensorSONAR_cm)
#pragma config(Sensor, dgtl11, acel,           sensorDigitalIn)
#pragma config(Motor,  port2,           mesq,          tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port3,           mdir,          tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port4,           garra,         tmotorVex393, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

//#pragma config(Motor,  port2,           dir,           tmotorVex393, PIDControl, encoder, encoderPort, dgtl3, 1000)
//#pragma config(Motor,  port3,           esq,           tmotorVex393, PIDControl, encoder, encoderPort, dgtl3, 1000)
        int esquerda;
        int sensormeio;
        int meioesquerda;
        int meio;
        int meiodireita;
        int direita;
        int vusdir;
        int vusesq;
        int vusmeio;
				int anterior;
				int luz=0;

int max(int a,int b){
if(a>=b) return a;
else return b;
}

int min(int a,int b){
if(a>=b) return b;
else return a;
}

int ajusta(int valor){
    if(valor >2800) return 1;
    if(valor <1950) return 2;
    return 0;
}
void ts_em_frente(){
    motor[mdir]=18;
    motor[mesq]=15;
}
void ts_giro90esq(){

motor[mdir]=25;
motor[mesq]=-25;
wait10Msec(60);
}

void giro90esq(){

motor[mdir]=25;
motor[mesq]=-25;
wait10Msec(45);
}




int ts (){
motor[mesq]=motor[mdir]=20;
wait1Msec(100);
motor[mesq]=motor[mdir]=0;
if(sensorvalue[USesq]<sensorvalue[USdir])ts_giro90esq();
while(1){
while(sensorvalue[USmeio]>=12){
ts_em_frente();
if(sensorvalue[Usesq]<=10){motor[mesq]=motor[mdir]=0;return 0;}
}
giro90dir();
}
}

int desvio(){
    while(min(sensorvalue[Usesq],sensorvalue[Usdir])>=25){
    motor[mesq]=-18;
    motor[mdir]=18;
    }
        motor[mesq]=20;
    motor[mdir]=20;
    wait1Msec(200);
    while(1/*direita<2700*/){
        //direita=SensorValue[dir];
//      while(sensorvalue[Usmeio]<=15){
//                  motor[mesq]=17;
//      motor[mdir]=-17;
//      }
 //       while(sensorvalue[USesq]>=50  ){
 //       motor[mesq]=-17;
 //       motor[mdir]=17;
 //       wait1Msec(100);
 //       motor[mesq]=17;
 //       motor[mdir]=17;
//        direita=SensorValue[USesq];
//        }



        	 esquerda=ajusta(SensorValue[esq]);
           meioesquerda=ajusta(SensorValue[esq0]);
           meio=ajusta(SensorValue[centro]);
      	    meiodireita=ajusta(SensorValue[dir0]);
      		  direita=ajusta(SensorValue[dir]);
					if((esquerda+meio+meiodireita+direita)>=1){motor[mesq]=20;motor[mdir]=0;wait1Msec(100); break;}
    							if(luz==1)break;



        while(min(sensorvalue[Usesq],sensorvalue[Usdir])>=10 ){
        	if(anterior!=1){motor[mesq]=0;motor[mdir]=0;wait1Msec(100);}
            motor[mesq]=21;
            motor[mdir]=13;

              anterior=1;
                      	 esquerda=ajusta(SensorValue[esq]);
           meioesquerda=ajusta(SensorValue[esq0]);
           meio=ajusta(SensorValue[centro]);
      	    meiodireita=ajusta(SensorValue[dir0]);
      		  direita=ajusta(SensorValue[dir]);
					if((esquerda+meio+meiodireita+direita)>=1){motor[mesq]=20;motor[mdir]=0;wait1Msec(100); break;}

                wait1Msec(100);
        }


        while(min(sensorvalue[Usesq],sensorvalue[Usdir])<=10  ){
        	if(anterior!=2){motor[mesq]=0;motor[mdir]=0;wait1Msec(100);}
            motor[mesq]=18;
            motor[mdir]=18;
               anterior=2;

             esquerda=ajusta(SensorValue[esq]);
           meioesquerda=ajusta(SensorValue[esq0]);
           meio=ajusta(SensorValue[centro]);
      	    meiodireita=ajusta(SensorValue[dir0]);
      		  direita=ajusta(SensorValue[dir]);
					if((esquerda+meio+meiodireita+direita)>=1){motor[mesq]=20;motor[mdir]=0;wait1Msec(100); break;}
               wait1Msec(100);
;
        }


    }
}



void em_frente(){
    motor[mdir]=15;
    motor[mesq]=15;
}

void em_frente_rampa(){
    motor[mdir]=100;
    motor[mesq]=90 ;
}

void curva_esquerda(){
    motor[mesq]=45;
    motor[mdir]=-45;
}


void curva_esquerda_leve(){
    motor[mesq]=25;
    motor[mdir]=0;
}

void curva_direita(){
    motor[mesq]=-45;
    motor[mdir]=45;
}

void curva_direita_leve(){
    motor[mesq]=0;
    motor[mdir]=25;


} void rcurva_esquerda(){
    motor[mesq]=80;
    motor[mdir]=50;
}


void rcurva_esquerda_leve(){
    motor[mesq]=70;
    motor[mdir]=50;
}

void rcurva_direita(){
    motor[mesq]=50;
    motor[mdir]=80;
}

void rcurva_direita_leve(){
    motor[mesq]=50;
    motor[mdir]=70;
}



  void segue_linha_rampa(){

             if(direita ) curva_direita();//leve
            else if(esquerda ) curva_esquerda();//leve
            else if(meio && meioesquerda && (direita+esquerda+meiodireita)==0 ) rcurva_esquerda_leve();
            else if(meio && meiodireita && (direita+esquerda)==0 ) rcurva_direita_leve();
            else if(meio && (direita+esquerda+meiodireita+meioesquerda)==0 ) rem_frente_rampa();
            else if(meiodireita && (meio+direita+esquerda+meioesquerda)==0) rcurva_direita_leve();
        else if(meioesquerda && (direita+esquerda+meiodireita+meio)==0) rcurva_esquerda_leve();

        	else em_frente_rampa();


        						}




 void segue_linha(){

                if(sensorvalue[USmeio]<=15 && sensorvalue[Usmeio]>=2)
                if(sensorvalue[USmeio]<=15 && sensorvalue[Usmeio]>=2) desvio();
                if( ajusta(SensorValue[centro])==2 ){ acha_objeto(); break;}

             if(direita ) curva_direita();//leve
            else if(esquerda ) curva_esquerda();//leve
            else if(meio && meioesquerda && (direita+esquerda+meiodireita)==0 ) curva_esquerda_leve();
            else if(meio && meiodireita && (direita+esquerda)==0 ) curva_direita_leve();
            else if(meio && (direita+esquerda+meiodireita+meioesquerda)==0 ) em_frente();
            else if(meiodireita && (meio+direita+esquerda+meioesquerda)==0) curva_direita_leve();
        else if(meioesquerda && (direita+esquerda+meiodireita+meio)==0) curva_esquerda_leve();

        	else em_frente();


        						}


task main()
{
    while(true){


    				sensormeio=sensorvalue[USmeio];
            esquerda=ajusta(SensorValue[esq]);
            meioesquerda=ajusta(SensorValue[esq0]);
            meio=ajusta(SensorValue[centro]);
            meiodireita=ajusta(SensorValue[dir0]);
            direita=ajusta(SensorValue[dir]);

    			if(sensorvalue[acel]==0)
    			segue_linha_rampa();
    			else segue_linha();




      }
}
