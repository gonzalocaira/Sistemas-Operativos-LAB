#include <iostream>
#define MAX 50

using namespace std;

void paginacion(){
  cout<<"\t:::::::::PAGINACION:::::::::\n\n";
  int page[MAX],i,n,f,ps,off,pno;
  cout<<"\tIngresa el numero de paginas en la memoria "<<endl;
  cin>>n;
  cout<<"\tIngresa el tamaño de las paginas"<<endl;
  cin>>ps;
  cout<<"\tIngresa el numero de marcos "<<endl;
  cin>>f;
  for (int i=0;i<n;i++){
    page[i]=-1;
  }
  cout<<"\tEntrar en la tabla de páginas"<<endl;
  cout<<"\tIngrese el marco-numero como -1 si esa página no está presente en ningún marco"<<endl;
  cout<<"\n\tpage-no\tframe-no\n-------\t-------"<<endl;
  for(i=0;i<n;i++)
  {
  cout<<i<< "   ";
  cin>>page[i];
  }
  cout<<"\tIntroduzca la dirección lógica (es decir, página-numero y desplazamiento)"<<endl;
  cin>>pno>>off;
  if(page[pno]==-1){
    cout<<"\tLa página requerida no está disponible en ninguno de los marcos."<<endl;
  }
  else{
    cout<<"\tDirección física (es decir, marco numero y desplazamiento) "<<endl;
    cout<<page[pno]<<"  "<<off<<endl;
  }

}
