#include <stdio.h>
#include <list.h>
#include <string.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct aluno_ {
    char nome[30];
    int matricula;
    float cpf;
} Aluno;

int cmpAlunoNome(void *a, void *b){
    Aluno *pa; char *pb;
    pa = (Aluno *) a;
    pb = (char *) b;
    if ( strcmp(pa->nome, pb) == 0 ) {
        return TRUE;
    } else{
        return FALSE;
    }
} //fim de cmpAlunoNome

int cmpAlunoMatricula(void *a, void *b ){
    Aluno *pa; int *pb;
    pa = (Aluno *) a;
    pb = (int *)b;
    if (pa->matricula == *pb) {
        return TRUE;
    } else {
        return FALSE;
    }
} //fim de cmpAlunoMatricula

int cmpAlunoCpf(void *a, void *b) {
    Aluno *pa; float *pb;
    pa = (Aluno *) a;
    pb = (float *) b;
    if (pa->cpf == *pb) {
        return TRUE;
    } else{
        return FALSE;
    }
} //fim de cmpAlunoCpf

void checaEntrada(int scanfResult){
    if( scanfResult != 1){
        int c;
        do {
            c = getchar();
        } while(c != '\n' && c != EOF);
    }
} //fim de checaEntrada

int inserirComSpec(SLList *lista, Aluno *aluno, int AntesApos) {
    char nome[30]; void* ptrNome;
    int matricula; void* ptrMatricula;
    float cpf; void* ptrCpf;
    int loop = TRUE; int escolhaMenu;
    void *escolhaTipoCmp;
    while (loop) {
        escolhaMenu = 0;
        printf("\nEscolha uma das opcoes a seguir: \n");
        printf("\t1.Buscar por Nome;\n"
               "\t2.Buscar por Matricula;\n"
               "\t3.Buscar por CPF;\n");

        checaEntrada(scanf("%d", &escolhaMenu));
        int (*pointerToCmpNome) (void *, void *)= &cmpAlunoNome;
        int (*pointerToCmpMatricula) (void *, void *)= &cmpAlunoMatricula;
        int (*pointerToCmpCPF) (void *, void *)= &cmpAlunoCpf;

        switch (escolhaMenu) {
            case (1):
                escolhaTipoCmp = pointerToCmpNome;
                printf("\nInforme o nome do aluno especificado: \n");
                checaEntrada(scanf("%s", (&nome)));
                ptrNome = &nome;
                if(AntesApos == -1){
                    return sllInsertBeforeSpec(lista, ptrNome, escolhaTipoCmp, aluno);
                } else {
                    return sllInsertAfterSpec(lista, ptrNome, escolhaTipoCmp, aluno);
                }
            case (2):
                escolhaTipoCmp = pointerToCmpMatricula;
                printf("\nInforme a matricula do aluno especificado: \n");
                checaEntrada(scanf("%d", (&matricula)));
                ptrMatricula = &matricula;
                if(AntesApos == -1){
                    return sllInsertBeforeSpec(lista, ptrMatricula, escolhaTipoCmp, aluno);
                } else {
                    return sllInsertAfterSpec(lista, ptrMatricula, escolhaTipoCmp, aluno);
                }
            case (3):
                escolhaTipoCmp = pointerToCmpCPF;
                printf("\nInforme o CPF do aluno especificado: \n");
                checaEntrada(scanf("%f", (&cpf)));
                ptrCpf = &cpf;
                if(AntesApos == -1){
                    return sllInsertBeforeSpec(lista, ptrCpf, escolhaTipoCmp, aluno);
                } else {
                    return sllInsertAfterSpec(lista, ptrCpf, escolhaTipoCmp, aluno);
                }
            default:
                printf("Insira um valor valido. \n");
                break;
        }
    }
    return 0;
}

void* removerComSpec(SLList *lista, int AntesApos) {
    char nome[30]; void* ptrNome;
    int matricula; void* ptrMatricula;
    float cpf; void* ptrCpf;
    int loop = TRUE; int escolhaMenu;
    void *escolhaTipoCmp;
    while (loop) {
        escolhaMenu = 0;
        printf("\nEscolha uma das opcoes a seguir: \n");
        printf("\t1.Buscar por Nome;\n"
               "\t2.Buscar por Matricula;\n"
               "\t3.Buscar por CPF;\n");

        checaEntrada(scanf("%d", &escolhaMenu));
        int (*pointerToCmpNome) (void *, void *)= &cmpAlunoNome;
        int (*pointerToCmpMatricula) (void *, void *)= &cmpAlunoMatricula;
        int (*pointerToCmpCPF) (void *, void *)= &cmpAlunoCpf;

        switch (escolhaMenu) {
            case (1):
                escolhaTipoCmp = pointerToCmpNome;
                printf("\nInforme o nome do aluno especificado: \n");
                checaEntrada(scanf("%s", (&nome)));
                ptrNome = &nome;
                if(AntesApos == -1){
                    return sllRemoveBeforeSpec(lista, ptrNome, escolhaTipoCmp);
                } else if(AntesApos == 1){
                    return sllRemoveAfterSpec(lista, ptrNome, escolhaTipoCmp);
                } else{
                    return sllRemoveSpec(lista, ptrNome, escolhaTipoCmp);
                }

            case (2):
                escolhaTipoCmp = pointerToCmpMatricula;
                printf("\nInforme a matricula do aluno especificado: \n");
                checaEntrada(scanf("%d", (&matricula)));
                ptrMatricula = &matricula;
                if(AntesApos == -1){
                    return sllRemoveBeforeSpec(lista, ptrMatricula, escolhaTipoCmp);
                } else if(AntesApos == 1) {
                    return sllRemoveAfterSpec(lista, ptrMatricula, escolhaTipoCmp);
                } else {
                    return sllRemoveSpec(lista, ptrMatricula, escolhaTipoCmp);
                }

            case (3):
                escolhaTipoCmp = pointerToCmpCPF;
                printf("\nInforme a matricula do aluno especificado: \n");
                checaEntrada(scanf("%f", (&cpf)));
                ptrCpf = &cpf;
                if(AntesApos == -1){
                    return sllRemoveBeforeSpec(lista, ptrCpf, escolhaTipoCmp);
                } else if(AntesApos == 1) {
                    return sllRemoveAfterSpec(lista, ptrCpf, escolhaTipoCmp);
                } else{
                    return sllRemoveSpec(lista, ptrCpf, escolhaTipoCmp);
                }
            default:
                printf("Insira um valor valido. \n");
                break;
        }
    }
    return NULL;
}

void sllEsvaziar(SLList *lista){
    Aluno *a = (Aluno *) sllRemoveFirst(lista);
    while ( a != NULL ) {
        a = (Aluno *) sllRemoveFirst(lista);
    }
} //fim de sllEsvaziar

int main (void) {
    SLList *lista;
    int escolhaMenu, escolhaDoUsuario;
    int listaFoiCriada = FALSE;

    int loop = TRUE;
    while (loop) {
        escolhaMenu = 0;
        printf("\nEscolha uma das opcoes a seguir: \n");
        printf("\t1.Criar lista;\n"
               "\t2.Destruir lista;\n"
               "\t3.Adicionar aluno;\n"
               "\t4.Remover aluno;\n"
               "\t5.Buscar aluno;\n"
               "\t6.Listar alunos;\n"
               "\t7.Esvaziar lista;\n"
               "\t8.Sair.\n");


        checaEntrada(scanf("%d", &escolhaMenu));

        switch (escolhaMenu) {
            case (1):
                if (listaFoiCriada) {
                    printf("A lista ja foi criada, destrua-a antes de criar uma nova.\n");
                } else {
                    lista = sllCreate();
                    if (lista == NULL) {
                        printf("Nao foi possivel criar a lista. \n");
                    } else {
                        printf("Lista criada com sucesso. \n");
                        listaFoiCriada = TRUE;
                    }
                }
                break;

            case (2):
                if (listaFoiCriada) {
                    if (sllDestroy(lista)) {
                        printf("Lista destruida com sucesso.\n");
                        listaFoiCriada = FALSE;
                    } else {
                        printf("Nao foi possivel destruir a lista. Ha elementos dentro dela.\n");
                    }
                } else {
                    printf("Nao ha uma lista criada.\n");
                }
                break;

            case (3):
                if (listaFoiCriada) {
                    int escolhaInsercao, loopInsercao = TRUE;
                    Aluno *aluno;
                    aluno = (Aluno *) malloc(sizeof(Aluno));
                    if (aluno != NULL) {
                        printf("Informe o nome do(a) aluno(a) a ser inserido(a): \n");
                        checaEntrada(scanf("%s", (aluno->nome)));
                        printf("Informe o numero de matricula do(a) aluno(a) a ser inserido(a): \n");
                        checaEntrada(scanf("%d", &(aluno->matricula)));
                        printf("Informe o CPF do(a) aluno(a) a ser inserido(a) no formato XXXXXXXXX.XX: \n");
                        checaEntrada(scanf("%f", &(aluno->cpf)));


                        while (loopInsercao) {
                            escolhaInsercao = 0;
                            printf("Informe o tipo de insercao: \n");
                            printf("\t1.Inserir no Inicio;\n"
                                   "\t2.Inserir no Final;\n"
                                   "\t3.Inserir apos o especificado;\n"
                                   "\t4.Inserir antes do especificado;\n");
                            checaEntrada(scanf("%d", &escolhaInsercao));
                            switch (escolhaInsercao) {
                                case (1):
                                    sllInsertAsFirst(lista, aluno);
                                    printf("Aluno inserido com sucesso.");
                                    loopInsercao = 0;
                                    break;
                                case (2):
                                    sllInsertAsLast(lista, aluno);
                                    printf("Aluno inserido com sucesso.");
                                    loopInsercao = 0;
                                    break;
                                case (3):
                                    if(sllIsEmpty(lista)){
                                        printf("A lista esta vazia, nao foi possivel adicionar o aluno. \n");
                                    } else{
                                        if (inserirComSpec(lista, aluno, 1)) {
                                            printf("Aluno inserido com sucesso.");
                                        } else {
                                            printf("Nao foi possivel adicionar o aluno.");
                                        }
                                    }
                                    loopInsercao = 0;
                                    break;
                                case (4):
                                    if(sllIsEmpty(lista)){
                                        printf("A lista esta vazia, nao foi possivel adicionar o aluno. \n");
                                    } else {
                                        if (inserirComSpec(lista, aluno, -1)) {
                                            printf("Aluno inserido com sucesso.");
                                        } else {
                                            printf("Nao foi possivel adicionar o aluno.");
                                        }
                                    }
                                    loopInsercao = 0;
                                    break;
                                default:
                                    printf("Informe um valor valido");
                            }
                        }
                    }
                } else {
                    printf("Nao ha uma lista criada.\n");
                }
                break;
            case (4):
                if (listaFoiCriada) {
                    int escolhaRemocao, loopRemocao = TRUE;
                        while (loopRemocao) {
                            escolhaRemocao = 0;
                            printf("Informe o tipo de remocao: \n");
                            printf("\t1.Remover no Inicio;\n"
                                   "\t2.Remover no Final;\n"
                                   "\t3.Remover apos o especificado;\n"
                                   "\t4.Remover antes do especificado;\n"
                                   "\t5.Remover especificado.\n");

                            checaEntrada(scanf("%d", &escolhaRemocao));
                            switch (escolhaRemocao) {
                                case (1):
                                    if(sllIsEmpty(lista)){
                                        printf("A lista esta vazia, nao foi possivel remover o aluno. \n");
                                    } else {
                                        sllRemoveFirst(lista);
                                        printf("Aluno removido com sucesso.");
                                        loopRemocao = 0;
                                    }
                                    break;
                                case (2):
                                    if(sllIsEmpty(lista)){
                                        printf("A lista esta vazia, nao foi possivel remover o aluno. \n");
                                    } else {
                                        sllRemoveLast(lista);
                                        printf("Aluno removido com sucesso.");
                                        loopRemocao = 0;
                                    }
                                    break;
                                case (3):
                                    if(sllIsEmpty(lista)){
                                        printf("A lista esta vazia, nao foi possivel remover o aluno. \n");
                                    } else {
                                        if(removerComSpec(lista, 1) != NULL) {
                                            printf("Aluno removido com sucesso.");
                                        } else {
                                            printf("Nao foi possivel remover o aluno.");
                                        }
                                    }
                                    loopRemocao = 0;
                                    break;
                                case (4):
                                    if(sllIsEmpty(lista)){
                                        printf("A lista esta vazia, nao foi possivel remover o aluno. \n");
                                    } else {
                                        if (removerComSpec(lista, -1)!= NULL) {
                                            printf("Aluno removido com sucesso.");
                                        } else {
                                            printf("Nao foi possivel remover o aluno.");
                                        }
                                    }

                                    loopRemocao = 0;
                                    break;
                                case (5):
                                    if(sllIsEmpty(lista)){
                                        printf("A lista esta vazia, nao foi possivel remover o aluno. \n");
                                    } else {
                                        if (removerComSpec(lista, 0)!= NULL) {
                                            printf("Aluno removido com sucesso.");
                                        } else {
                                            printf("Nao foi possivel remover o aluno.");
                                        }
                                    }
                                    loopRemocao = 0;
                                    break;
                                default:
                                    printf("Informe um valor valido");
                            }
                        }
                } else {
                    printf("Nao ha uma lista criada.\n");
                }
                break;

            case (5):
                if (listaFoiCriada) {
                    Aluno *alunoBuscado;
                    int chaveInt;
                    float chaveFloat;
                    char chaveString[30];
                    int loopBusca = 1;
                    printf("\nBuscar por: (1) Nome; (2) Matricula; (3) CPF\n");
                    checaEntrada(scanf("%d", &escolhaDoUsuario));
                    while (loopBusca) {
                        switch (escolhaDoUsuario) {
                            case 1:
                                printf("Insira o nome do(a) aluno(a) a ser buscado(a). \n");
                                checaEntrada(scanf("%s", &chaveString));
                                char *pString = chaveString;
                                alunoBuscado = sllQuery(lista, pString, cmpAlunoNome);
                                escolhaDoUsuario = 0;
                                loopBusca = 0;
                                break;
                            case 2:
                                printf("Insira a matricula do(a) aluno(a) a ser buscado(a). \n");
                                checaEntrada(scanf("%d", &chaveInt));
                                int *pInt = &chaveInt;
                                alunoBuscado = sllQuery(lista, pInt, cmpAlunoMatricula);
                                escolhaDoUsuario = 0;
                                loopBusca = 0;
                                break;
                            case 3:
                                printf("Insira o CPF do(a) aluno(a) a ser buscado(a) no formato XXXXXXXXX.XX: \n");
                                checaEntrada(scanf("%f", &chaveFloat));
                                float *pFloat = &chaveFloat;
                                alunoBuscado = sllQuery(lista, pFloat, cmpAlunoCpf);
                                escolhaDoUsuario = 0;
                                loopBusca = 0;
                                break;
                            default:
                                printf("Insira um valor valido \n");
                                escolhaDoUsuario = 0;
                        }
                    }

                    if (alunoBuscado != NULL) {
                        printf("O(a) aluno(a) %s esta na lista.\n", alunoBuscado->nome);
                    } else {
                        printf("O(a) aluno nao esta na lista.\n");
                    }
                } else {
                    printf("Nao ha uma lista criada.\n");
                }
            break;

            case (6):
                if (listaFoiCriada) {
                    if (!sllIsEmpty(lista)) {
                        Aluno *a;
                        for(int i = 0; i<sllLength(lista);i++){
                            a = sllRemoveFirst(lista);
                            printf(" Aluno(a): %s ; Numero de Matricula: %d; CPF: %.2f; \n", a->nome, a->matricula, a->cpf);
                            sllInsertAsLast(lista, a);
                        }

                    } else {
                        printf("Nao ha alunos na lista.\n");
                    }
                } else {
                    printf("Nao ha uma lista criada.\n");
                }
                break;

            case (7):
                if (listaFoiCriada) {
                    sllEsvaziar(lista);
                    printf("Lista esvaziada com sucesso.\n");
                } else {
                    printf("Nao ha uma lista criada.\n");
                }
            break;

            case (8):
                if (listaFoiCriada) {
                    sllEsvaziar(lista);
                    sllDestroy(lista);
                    loop = FALSE;
                } else {
                    loop = FALSE;
                }
            break;

            default:
                printf("Informe um valor valido! \n");
            }
        }
    return 0;
}
