#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

void menu() {

		printf("\
            ___     ___       ________      ____  ____    ___      ___  \n\
           |###    |###      |########     |#### |####   |###     |###  \n\
            |###  |###       |########      |##   |##     |##     |##   \n\
            |####|####       |##            |#### |##     |##     |##   \n\
            |## ###|##       |########      |##|##|##     |##     |##   \n\
            |##  # |##       |########      |## |####     |##     |##   \n\
            |##    |##       |##            |##  |###     |##     |##   \n\
            |##    |##       |########      |##   |##      |##   |##    \n\
           |####  |####      |########     |#### |####      |######     \n\
           -------------------------------------------------------------\n\
                   Aperte enter para iniciar o jogo da Forca: \n\
           -------------------------------------------------------------\n");


    getchar();
}

/*As palavras do arquivo de texto são extraídas e registradas numa matriz[100][100].*/
void registro_palavras(char matriz[][100]) {
    FILE *arquivo;
    arquivo = fopen("palavras.txt", "r");/*Abertura do arquivo.*/

    if (arquivo == NULL) {
        printf("Ocorreu um erro ao tentar abrir o arquivo.\n");
    }

    int numPalavras = 0;
    while (numPalavras < 100 && fscanf(arquivo, "%s", matriz[numPalavras]) == 1) {
        numPalavras++;
    }

    fclose(arquivo);
    
    return;
}
  
/*função de sorteio.*/
int sorteio(){
	srand(time(NULL));
	int a = rand()%100;
	return a;
}

/*Função que substitui a dica pelas letras acertadas nas devidas posições.*/
void subst(char word[], const char letrasAcertadas[],char dica[100]) {
    int size = strlen(word),i;
    for (i = 0; i <= size; i++) {
		if (word[i] != ' ' && strchr(letrasAcertadas, word[i]) == NULL) {
			dica[i]='_';
        } else {
            dica[i]=word[i];
        }
    }
    printf("Palavra: %s\n",dica);
}

/*Função que verifica apenas se o usuário acertou ou errou a letra, me retornando ao final.*/
 int verify(char a,const char b[]){
	int c, j, size;
    size = strlen(b);
    for (c = 0; c < size; c++) {
        if (a == b[c]) {
            j=1;
            break;
        }
        else{
        	j=0;
		}
    }
    return j;
}

/*Função que retorna uma string com as devidas posições das letras digitadas corretamente.*/
char* rastreador_pos(char digitado, const char palavraOriginal[],int numAcertos) {
    int size = strlen(palavraOriginal);
    int i = 0;
    char* pos = malloc((size + 1) * sizeof(char));

    for (i = 0; i < size; i++) {
        if (digitado == palavraOriginal[i]) {
            pos[numAcertos] = i;
            numAcertos++;
        }
    }

    pos[numAcertos] = '\0';
    pos = realloc(pos, (numAcertos + 1) * sizeof(char));

    return pos;
}

/*Função de limpeza de página.*/
void close(){     
    system("cls"); 
}

/*Função de apresentação dos cenários possíveis no jogo.*/
void letreiro(int num){
  if(num==6){
	printf("------------------------------------------------------------\n");
	printf("              VOCE TEM %d CHANCES DE ACERTAR!                \n",num);
	printf("------------------------------------------------------------\n");
    }
    else if(num<6 && num>0){
   	printf("------------------------------------------------------------\n");
	printf("                   RESTAM %d CHANCES.                        \n",num);
	printf("------------------------------------------------------------\n");
	}
}

/*Função especifica para o caso de derrota do usuario.*/
void perdedor(const char a[]){
	int i;
	char palavra_upper[strlen(a) + 1];
    
    for (i = 0; i < strlen(a); i++) {
        palavra_upper[i] = toupper(a[i]);
    }
    palavra_upper[i] = '\0';
    
    printf("------------------------------------------------------------\n");
    printf("        VOCE ERROU =( A PALAVRA ERA %s!            \n", palavra_upper);
    printf("------------------------------------------------------------\n");
}

/*Função especifica para o caso vencedor.*/
void vencedor(const char a[]) {
    int i;
    char palavra_upper[strlen(a) + 1];
    
    for (i = 0; i < strlen(a); i++) {
        palavra_upper[i] = toupper(a[i]);
    }
    palavra_upper[i] = '\0';
    
    printf("------------------------------------------------------------\n");
    printf("        PARABENS! VOCE ACERTOU! A PALAVRA ERA %s!            \n", palavra_upper);
    printf("------------------------------------------------------------\n");
    printf("                                                           \n"); 
    printf("                          ######                            \n");
    printf("                         #      #                           \n");
    printf("                        #  o  o  #                          \n");
    printf("                        #        #                          \n");
    printf("                        #  \\__/  #                          \n");
    printf("                      o  #      #  o                       \n");
    printf("                       #  ######  #                        \n");
    printf("                        #   ##   #                         \n");
    printf("                         #  ##  #                           \n");
    printf("                           ####                             \n");
    printf("                            ##                             \n");
    printf("                            ##                             \n");
    printf("                            ##                             \n");
    printf("                            ##                             \n");
    printf("                           #  #                              \n");
    printf("                          #    #                            \n");
    printf("                         #      #                           \n");
    printf("                        #        #                          \n");
    printf("                       o          o                         \n");
}

/*Função do boneco mostrado em casos de jogo.*/
void boneco(int num){
	
	switch(num){
    case 0:
    printf("#################################                           \n");
    printf("                            ##                              \n"); 
    printf("                          ######                            \n");
    printf("                         #      #                           \n");
    printf("                        #  X  X  #                          \n");
    printf("                        #   __   #                          \n");
    printf("                        #  /  \\  #                          \n");
    printf("                         #      #                           \n");
    printf("                          ######                            \n");
    printf("                           /##\\                             \n");
    printf("                           \\##/                             \n");
    printf("                           ####                             \n");
    printf("                          # ## #                            \n");
    printf("                         #  ##  #                           \n");
    printf("                        #   ##   #                          \n");
    printf("                       o    ##    o                         \n");
    printf("                           #  #                             \n");
    printf("                          #    #                            \n");
    printf("                         #      #                           \n");
    printf("                        #        #                          \n");
    printf("                       o          o                         \n");
	break;
	
	case 1:
    printf("#################################                            \n");
    printf("                            ##                              \n"); 
    printf("                          ######                            \n");
    printf("                         #      #                           \n");
    printf("                        #  o  o  #                          \n");
    printf("                        #        #                          \n");
    printf("                        #  \\__/  #                          \n");
    printf("                         #      #                           \n");
    printf("                          ######                            \n");
    printf("                           /##\\                             \n");
    printf("                           \\##/                             \n");
    printf("                           ####                             \n");
    printf("                          # ## #                            \n");
    printf("                         #  ##  #                           \n");
    printf("                        #   ##   #                          \n");
    printf("                       o    ##    o                         \n");
    printf("                           #                               \n");
    printf("                          #                                \n");
    printf("                         #                                 \n");
    printf("                        #                                  \n");
    printf("                       o                                   \n");
	break;
	
	case 2:
    printf(" ################################                              \n");
    printf("                            ##                              \n"); 
    printf("                          ######                            \n");
    printf("                         #      #                           \n");
    printf("                        #  o  o  #                          \n");
    printf("                        #        #                          \n");
    printf("                        #  \\__/  #                          \n");
    printf("                         #      #                           \n");
    printf("                          ######                            \n");
    printf("                           /##\\                             \n");
    printf("                           \\##/                             \n");
    printf("                           ####                             \n");
    printf("                          # ## #                            \n");
    printf("                         #  ##  #                           \n");
    printf("                        #   ##   #                          \n");
    printf("                       o    ##    o                         \n\n\n\n\n\n");
   
    break;
    
    case 3:
    printf(" ################################                              \n");
    printf("                            ##                              \n"); 
    printf("                          ######                            \n");
    printf("                         #      #                           \n");
    printf("                        #  o  o  #                          \n");
    printf("                        #        #                          \n");
    printf("                        #  \\__/  #                          \n");
    printf("                         #      #                           \n");
    printf("                          ######                            \n");
    printf("                           /##\\                             \n");
    printf("                           \\##/                             \n");
    printf("                           ###                             \n");
    printf("                          # ##                             \n");
    printf("                         #  ##                             \n");
    printf("                        #   ##                             \n");
    printf("                       o    ##                             \n\n\n\n\n\n");
    	
    break;
    
    case 4:
    printf(" ################################                              \n");
    printf("                            ##                              \n"); 
    printf("                          ######                            \n");
    printf("                         #      #                           \n");
    printf("                        #  o  o  #                          \n");
    printf("                        #        #                          \n");
    printf("                        #  \\__/  #                          \n");
    printf("                         #      #                           \n");
    printf("                          ######                            \n");
    printf("                           /##\\                             \n");
    printf("                           \\##/                             \n");
    printf("                            ##                             \n");
    printf("                            ##                             \n");
    printf("                            ##                             \n");
    printf("                            ##                             \n");
    printf("                            ##                             \n\n\n\n\n\n");
    
	break;
	
	case 5:
	printf(" ################################                           \n");
    printf("                            ##                              \n"); 
    printf("                          ######                            \n");
    printf("                         #      #                           \n");
    printf("                        #  o  o  #                          \n");
    printf("                        #        #                          \n");
    printf("                        #  \\__/  #                         \n");
    printf("                         #      #                           \n");
    printf("                          ######    \n\n\n\n\n\n\n\n\n\n\n\n\n");
    
	
	break;
	
	case 6:
	printf(" ################################                           \n");
    printf("                            ##                              \n"); 
    printf("                            ##      \n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    	
	break;	
}
}

/*Mecanismos do jogo propriamente dito.*/
void jogo_da_forca() {
    char forca[100][100];
    int palavra;

    registro_palavras(forca);
    palavra = sorteio();

    close();
  
    int tamanho = strlen(forca[palavra]), k;
    int chances = 6, numAcertos = 0, tentativas = 0, repeticao = 0, acertou_errou = 0;
    char certas[tamanho], tentadas[26], digitado,segredo[100];
    
    memset(certas, 0, sizeof(certas));
    
    while (chances > 0) {
         if (repeticao == 0) {
    	/*Parte Ilustrativa:*/
        letreiro(chances);                               /* >Aqui, é chamado o letreiro que informa as chances restantes do jogador. */
        boneco(chances);                                 /* >Aqui, é chamado o boneco que ilustra a situação atual em funçaão do numero de chances. */
        
                                    
            if (acertou_errou == 1) {                    /* >Aqui são mostradas informações para que, apenas se não. */
                printf("Voce acertou a letra!\n");       /*  existirem repetições, o jogador seja informado da sua situação. */
                printf("As letras tentadas foram: ");
                for (k = 0; k < tentativas; k++) {
                    printf("%c ", tentadas[k]);
                }
                printf("\n\n");
            } else if (acertou_errou == 0 && chances == 6) {
                for (k = 0; k < tentativas; k++) {
                    printf("%c ", tentadas[k]);
                }
                printf("\n\n");
            } else {
                printf("Voce errou a letra. Tente outra vez.\n");
                printf("As letras tentadas foram: ");
                for (k = 0; k < tentativas; k++) {
                    printf("%c ", tentadas[k]);
                }
                printf("\n\n");
            }	
                                                            
        } else {
		    close();  
		    letreiro(chances);
			boneco(chances);                      /* >Caso contrário, será informado, que a letra digitada, foi repetida.*/
			printf("As letras tentadas foram: ");
			for (k = 0; k < tentativas; k++) {
                    printf("%c ", tentadas[k]);
                }
                printf("\n");
            printf("A letra ja foi tentada previamente, digite outra.\n\n");
        }
        
        /*Parte de substituição de letras nas devidas posições*/
        subst(forca[palavra],certas, segredo);
        
        /*Caso de vitória: */
        if (strcmp(segredo,forca[palavra])==0) {
        close();
        vencedor(forca[palavra]);
        break;
       }
        
        /*Aqui o usuário interage com a máquina, digitando uma letra do alfabeto*/
        printf("Digite uma letra: \n");
        scanf(" %c", &digitado);
        
        /*Parte de lógica condicional do programa*/
        repeticao = 0;                             /* >O jogo precisa começar com essa atribuição para garantir que se uma letra digitada */
                                                   /*  for repetida, essa condição não seja passada para a próxima letra. */
        int z; /*Variável de iteração*/
		for (z = 0; z < tentativas; z++) {         /* >Aqui é executado um loop procurando nas letras tentadas, uma repetição. */
            if (digitado == tentadas[z]) {         /* >Se esse for o caso, atribui-se 1, à variável "Repeticao" e o loop quebra.*/
                repeticao = 1;                     /* >Se não for, a variável continua zero, e, portanto, a mecânica flui. */ 
                break;
            }
        }
        
        if (repeticao == 1) {                      /* >Se houver repetição, é chamada uma função de limpeza de página e o loop reinicia. */
            close;
            continue;
        }

        tentadas[tentativas] = digitado;           /* >Em não ocorrendo repetição, invariavelmente o loop atribui a letra digitada a uma */
        tentativas++;                              /*  posição correspondente ao número de tentativas até o momento do vetor "tentadas". */

		char* posicoes = rastreador_pos(digitado, forca[palavra],numAcertos); /* >Em seguida é chamada a função de rastreio de posição, retornando um */
        acertou_errou = verify(digitado, forca[palavra]);   /* >Aqui é verificado qual o status da letra, se certa ou se errada. */                                                                   /*  char posições que possui as posições das letras digitas corretamente*/

        if (acertou_errou == 1) {
        int i, j;
         for (i = 0, j = 0; i < tamanho; i++) {            /* >Itera-se a condição para que as letras digitadas corretamente */       
            if (i == posicoes[j]) {                        /*  sejam colocadas na string "certas" de maneira que à medida que */
                char letra[2] = { digitado, '\0' };        /*  a posicão i, seja condizente com a posição da letra correta */
                strcat(certas, letra);                     /*  dentro da string "posicoes". */
                j++;
                }
            }
        }                                                   
    
		else {
          chances--;                                        /* >Aqui se aplica uma condição, para que, o jogador, perca chances, */
        }                                                   /*  caso nenhuma condição for satisfeita.*/
      close();
}
    
    /*Caso específico de derrota:*/
    if (chances == 0) {
        perdedor(forca[palavra]);
        boneco(0);
    }
}

/*Execução do código em forma de funções organizadas previamente.*/
int main(){
	char ctn;
    int i;
    
    menu();  /*Abertura do Menu.*/
	 
    for(i=0;i<1;i++){
    jogo_da_forca(); /* >O jogo é chamado*/
      
    int j;
	for(j=0;j<1;j++){
    printf("\nDeseja continuar jogando?(s/n)");/* >Interação com o usuário para loop de continuidade.*/
    scanf(" %c",&ctn);
    
    if(ctn=='s'){   /* >Loop para interagir com o usuário para a continuação ou não do jogo. */
    i--;	
    }
    else if(ctn!='s' && ctn!='n') {
  	close();
    printf("Letra invalida. Apenas s ou n.");
	j--;	
	}  
	else{
		system("exit");
	}
  }
}
    return 0;
}
