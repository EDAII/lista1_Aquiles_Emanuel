#include<stdio.h>
int divide(int tam) {
	int i;
	if(tam%2==0) {
		i=tam/2;
	}
	else {
		i=(tam-1)/2;
	}
	return i;
}
int divide2(int tam){
      int i;
      if(tam%2==0){
           i=tam/2;
      }
      else{
          i=(tam+1)/2;
      }
      return i;
}
void insertionSort(int* v, int tam) {
	int i, j, aux = 0;

	for (i=1; i<tam; i++) {
		aux = v[i];
		j = i - 1;
		while (j >= 0 && v[j] > aux) {
			v[j + 1] = v[j];
			j = j - 1;
		}
		v[j + 1] = aux;
	}

	return v;

}


void troca(int* vet){
      if(vet[0]>vet[1]){
          int temp;
          temp=vet[0];
          vet[0]=vet[1];
          vet[1]=temp;
        }  
      return vet;  
 } 
void sheelsort1(int* v ,  int gap, int i){
        int *vet;
        vet=(int*)malloc(2*sizeof(int));
        int pos1=i+gap;
        printf(" a posição 1 do subvetor é %d\n",pos1);
        vet[0]=v[i];
        vet[1]=v[pos1];  
        if(v[pos1]>v[i]){
          troca(vet);
        }
        v[pos1]=vet[1];
        v[i]=vet[0];
        free(vet)
        
}
void sheelsort(int* v ,  int gap, int i){
        int *vet;
        vet=(int*)malloc(2*sizeof(int));
        int pos1=i+gap;
        printf(" a posição 1 do subvetor é %d",pos1);
        vet[0]=v[i];
        vet[1]=v[pos1]; 
        insertionSort(vet,2);   
        v[i]=vet[0];
        v[pos1]=vet[1];
        free(vet) ;  
        return v ; 
	
}
void sheelsortmaior1(int *v, int gap, int i,int tamsheel){// aplicada depois da primeira rodada
        int *vet;
        vet=(int*)malloc(tamsheel*sizeof(int));
        int pos1=i+gap;
        printf(" a posição 1 do subvetor é %d\n",pos1);
        int i2;
        for(i2=0;i2<=tamsheel;i2++){ 
          vet[i2]=v[i2*gap+i];   
        };
        insertionSort(vet,tamsheel);
        for(i2=0;i2<=tamsheel;i2++){
            v[i2*gap+i]=vet[i2];
        };
        free(vet) ;  
        return v ; 
}

   
int main(int argc, char const *argv[])
{         
	int i, *v, tam,valor_vetor, busca,resultado;
        int gap;
	printf("insira o tamanho do vetor \n");
	scanf("%d",&tam);
	v = (int *) malloc(tam * sizeof(int));
                      
	for(i=0;i<tam;i++){
		printf("insira o valor do vetor na posicao %d \n",i);
		scanf("%d",&valor_vetor);
		v[i] = valor_vetor;
	}
             
        gap=divide(tam);
        printf("este e o gap:%d", gap);
        int isheel;  
        int tamsheel;
        if(tam%gap==0){
          tamsheel=tam/gap;
        }   
        for(isheel=0;isheel<gap;isheel++){
           sheelsort1(v,gap,isheel);
        }
        gap=divide(gap);
        for(i=0;i<tam;i++){
		printf("posicao do vetor: %d valor do vetor: %d \n",i,v[i]);
	}
        printf("o segundo gap é :%d", gap); 
        if(tam%gap==0){ 
          tamsheel=tam/gap;
        }else{
          tamsheel=tamsheel-(tam%gap);
          tamsheel=tam/gap; 
        }   
        for(isheel=0;isheel<gap;isheel++){
          sheelsortmaior1(v,gap,isheel,tamsheel);
        }      
        // o trecho a seguir é para debugar o que ja foi feito
	for(i=0;i<tam;i++){
		printf("posicao do vetor: %d valor do vetor: %d \n",i,v[i]);
	}
        gap=divide(gap);
        printf("o terceiro gap é :%d", gap); 
        if(tam%gap==0){ 
          tamsheel=tam/gap;
        }else{
          tamsheel=tamsheel-(tam%gap);
          tamsheel=tam/gap; 
        }   
        for(isheel=0;isheel<gap;isheel++){
          sheelsortmaior1(v,gap,isheel,tamsheel);
        }      
        gap= divide(tam);
        printf("%d",gap);
        int ishell;   
        sheelsort(v, gap,0);
        int tamshell;
        if(tam%gap==0){
          tamshell=tam/gap;
        }   
        for(ishell=0;ishell<tamshell;ishell++){
           sheelsort(v,gap,ishell);
        }       

        // o trecho a seguir é para debugar o que ja foi feito
	for(i=0;i<tam;i++){
		printf("posicao do vetor: %d valor do vetor: %d \n",i,v[i]);
	}
        free (v);
	return 0;
}

