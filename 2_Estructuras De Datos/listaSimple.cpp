#include <iostream>
using namespace std;

class nodo { // Constructores
   public:
   	
   	
nodo(int v)//6  nodo(string)  nodo(int x
    {
       valor = v;
       siguiente = NULL;
    }

nodo(int v, nodo  *signodo)    // nodo(nodo *signodo,int v)
    {
       valor = v;
       siguiente = signodo;
    }




   private:
    int valor;                                 
    nodo *siguiente;// Clase Autoreferencia
    
        
   friend class lista;
};

typedef nodo *pnodo; //Alias  

//void no retorna nada
//bool retorna False o True
//int retorna entero
class lista 
{
   public:
    lista() { primero =  NULL; }//constructor
    ~lista();//destructor
    
    void InsertarInicio(int v);//No retornan nada
    void InsertarFinal(int v);
    void InsertarPos (int v, int pos);
    bool ListaVacia() { return primero == NULL; } //retorna True o False
    void Mostrar();//imprimir
    void BorrarFinal();
    void BorrarInicio();
    void borrarPosicion(int pos);
    void Sumanum(int num);
    int largoLista();// retorno un valor numerico
    void Promedio(int num);
    
    
   private:
    pnodo primero;
   
};

lista::~lista()
{
   nodo *aux;
   
   while(primero) {
      aux = primero;
      primero = primero->siguiente;
      delete aux;
   }
   primero= NULL;
}

int lista::largoLista(){
    int cont=0;

    pnodo aux= primero;
    if(ListaVacia()){
        return cont;
    }else{
        while(aux!=NULL){
        aux=aux->siguiente;
        cont++;
    }
    return cont;
    cout<< endl;
    }
    
}

void lista::InsertarInicio(int v)//6
{
   if (ListaVacia())
   {
   
     primero = new nodo(v);//6
     
   }
   else
   {
     //primera forma
     // primero=new nodo (v,primero);   
  
    //segunda forma
    pnodo nuevo=new nodo(v);//1
    nuevo->siguiente=primero;//2
    primero=nuevo;
     
    
    
     
   }
}
 
void lista::InsertarFinal(int v)//76
{
   if (ListaVacia())
     primero = new nodo(v);
   else
      { 
      //primera forma
	    pnodo aux = primero; while ( aux->siguiente != NULL) aux= aux->siguiente;  aux->siguiente=new nodo(v);
       
       //segunda forma 
      /* pnodo aux = primero;
        while ( aux->siguiente != NULL)
         aux= aux->siguiente;
        pnodo nuevo=new nodo(v);
        aux->siguiente=nuevo;*/
      }    
}


void lista::InsertarPos(int v,int pos)
{
   if (ListaVacia())
     primero = new nodo(v);
   else{
        if(pos <=1)
		{
        	//OPcion1
          pnodo nuevo = new nodo(v);
          nuevo->siguiente= primero;
          primero= nuevo;     
          //OPcion 2
          //InsertarInicio(v);
        }      
        else{
             nodo *aux= primero;
             int i =2;
             while((i != pos )&&(aux->siguiente!= NULL)){
                   i++;
                   aux=aux->siguiente;
             }
             pnodo nuevo= new nodo(v);
             nuevo->siguiente=aux->siguiente;
             aux->siguiente=nuevo;
             
        }
        }
}
      
void lista::BorrarFinal()
{
    if (ListaVacia()){
     cout << "No hay elementos en la lista:" << endl;
    
   }else{
        
        if (primero->siguiente == NULL) 
		{   pnodo temp=primero;
		    primero= NULL;
		    delete temp;;
            }
			 else {

                pnodo aux = primero;
                while (aux->siguiente->siguiente != NULL) {
                    aux = aux->siguiente;

                }
                
              pnodo temp = aux->siguiente;
              aux->siguiente= NULL;

                
                delete temp;
            }
        }
}

void lista::BorrarInicio()
{
    if (ListaVacia()){
     cout << "No hay elementos en la lista:" << endl;
    
   }else{
        if (primero->siguiente == NULL) 
		{   pnodo temp=primero;
		    primero= NULL;
		    delete temp;
        } 
		else 
		{

                pnodo aux = primero;
                primero=primero->siguiente;                
                delete aux;
        }
        }
}



void lista:: borrarPosicion(int pos){
     if(ListaVacia()){
              cout << "Lista vacia" <<endl;
    }else{
         if((pos>largoLista())||(pos<0)){
        cout << "Error en posicion" << endl;
        }else{
        if(pos==1)
		{
        /*	pnodo temp=primero;
        	primero=primero->siguiente;
        	delete temp;*/
			BorrarInicio();
        }
		else{
          int cont=2;
            pnodo aux=  primero;
            while(cont<pos){
             aux=aux->siguiente;
             cont++;
            }
            pnodo temp=aux->siguiente;
            aux->siguiente=aux->siguiente->siguiente;
            delete temp;
            }
        }
     }

}
 

void lista::Mostrar()
{
   nodo *aux;
   if (primero== NULL)
       cout << "No hay elementos AQUI";
   else
   {
   
       
   		aux = primero;
		while(aux) 
		{
		    cout << aux->valor << "-> ";
		    aux = aux->siguiente;
		}
		cout << endl;
   }
}


 void lista::Sumanum(int num)//23456 2+3+4+5+6=20
{
   if (num == 0)
      cout << "Suma igual a 0";
   else
   {
   
       while (num!=0)//23456 si 2345si 234si 23si 2si 0x
       {
	   
	     int temp=num%10; //6 5 4 3 2
		 InsertarInicio(temp);//2->3->4->5->6->null
		 num=num/10;//2345 234 23 2 0
       }          //                aux
      int suma=0; //2->3->4->5->6->null
      //suma=0
      pnodo aux=primero; 
      while(aux !=NULL)
      {
      	suma=suma+aux->valor;//0+2=2 2+3=5 5+4=9  9+5=14 14+6=20
      	aux=aux->siguiente;
	  }
	  cout<<suma<<endl;//20
   }
	
}


void lista::Promedio(int num)//23456 2+3+4+5+6=20
{
   if (num == 0)
      cout << "Suma igual a 0";
   else
   {
       
       while (num!=0)//23456 si 2345si 234si 23si 2si 0x
       {
	   
	     int temp=num%10; //6 5 4 3 2
		 InsertarInicio(temp);//2->3->4->5->6->null
		 num=num/10;//2345 234 23 2 0
       }          //                aux
      int suma=0; //2->3->4->5->6->null
      //suma=0
      pnodo aux=primero; 
      while(aux !=NULL)
      {
      	suma=suma+aux->valor;//0+2=2 2+3=5 5+4=9  9+5=14 14+6=20
      	aux=aux->siguiente;
	  }
	  int larg=largoLista();
	  cout<<suma/larg<<endl;//20
   }
	
}



int main()
{
   lista L1,L2;//instancia null null valor defaul no tiene nada y evita basura
   
    
 
   cout<< "***************************************************************************************"<<endl;
   L1.InsertarInicio(10);    //20->1265->10->2->3->10   20->1265->10->2->10
   L1.InsertarInicio(6); 
   L1.InsertarFinal(8);
   L1.Mostrar();
   /*L1.InsertarInicio(2);
   L1.Mostrar();
   cout<<endl;
   L1.InsertarInicio(10);
   L1.Mostrar();
   L1.InsertarInicio(1265);
   L1.Mostrar();
   L1.InsertarInicio(20);
   L1.Mostrar();
   L1.borrarPosicion(5);
   L1.Mostrar();
   cout<<endl;
   L2.Sumanum(23456);
    cout<<endl;
    L2.Promedio(23456);
  // L1.BorrarInicio();
   //L1.Mostrar();
 // L1.BorrarFinal();
  // L1.Mostrar();
  /* L1.InsertarFinal(24);
   L1.Mostrar();
   L1.InsertarPos(1479,1);
   L1.Mostrar();*/
   
  // L1.BorrarFinal();*/
   //L1.Mostrar();
  // cout << Lista.largoLista();
   
 /*  Lista.InsertarFinal(11);
   Lista.InsertarPos(5, 1);
   Lista.InsertarPos(6, 4);*/

   /*Lista.InsertarInicio(30);
   Lista.InsertarInicio(1);   
   Lista.InsertarFinal(5);
   Lista.InsertarPos(1, 3);*/
//   Lista.Mostrar();
 //  Lista.borrarPosicion(4);
  // Lista.Mostrar();
 /*  Lista.BorrarInicio();
      Lista.Mostrar();
   Lista.BorrarFinal();
      Lista.Mostrar();
   Lista.borrarPosicion(3);
   Lista.Mostrar();
  

   cout << "Lista de elementos:" << endl;
   Lista.Primero();
   Lista.Primero();
   Lista.Ultimo();
  
   Lista.BorrarFinal();
   //Lista.Borrar(15);
  // Lista.Borrar(45);
   //Lista.Borrar(30);
   //Lista.Borrar(40);
   
   Lista.Mostrar();
   Lista.~lista();
   Lista.Mostrar();*/
 //  Lista.~lista();
   cin.get();//es pausa
   return 0;
}
