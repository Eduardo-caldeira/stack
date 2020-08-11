#ifndef TAD_PILHA_H_INCLUDED
#define TAD_PILHA_H_INCLUDED

template<typename tipo>
struct TElemento{
    tipo elemento;
    TElemento *down;
};

template<typename tipo>
struct TPilha{
    TElemento<tipo> *top;
};

template<typename tipo>
bool inicializa_pilha(TPilha<tipo> *Pilha){
    Pilha->top = NULL;
    return true;
}

template<typename tipo>
bool PUSH(TPilha<tipo> *Pilha, tipo dado){
    TElemento<tipo> *var;
    var = new TElemento<tipo>;
    var->elemento = dado;
    if(Pilha->top==NULL){///Caso a Pilha esteja vazia
        Pilha->top = var;
        return true;
    }else{
        var->down = Pilha->top;
        Pilha->top= var;
        return true;
    }
}

template<typename tipo>
tipo POP(TPilha<tipo> *Pilha){
    TElemento<tipo> *escravo=Pilha->top;
    tipo retorno;
    if(Pilha->top==NULL){///Se a Pilha etá vazia, não ha algo para remover
        return false;
    }else{
        Pilha->top= Pilha->top->down;
        retorno = escravo->elemento;
        delete escravo;
        return retorno;
    }
}

#endif // TAD_PILHA_H_INCLUDED
