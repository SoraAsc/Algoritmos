! main.f90 - TAD_Pilha
! Teste TAD_Pilha
! Autor: Marcos V. Dias Ferreira
! Data: 08/06/2023
program MAIN
    USE Pilha_Module
    IMPLICIT NONE

    TYPE(T_PILHA), POINTER :: p1
    INTEGER :: valor ! Valor retornado do desempilhar

    CALL PilhaCriar(p1)

    PRINT *, "A pilha estah vazia?",PilhaVazia(p1)

    PRINT *, "Adicionando o valor 1 na pilha"
    CALL PilhaEmpilhar(p1, 1)

    PRINT *, "Adicionando o valor 29 na pilha"
    CALL PilhaEmpilhar(p1, 29)

    CALL PilhaDesempilhar(p1, valor)
    WRITE(*,"(A,I0)") "Foi removido da pilha o valor: ", valor

    PRINT *, "A pilha estah vazia?",PilhaVazia(p1)

    CALL PilhaDesalocar(p1)

END PROGRAM

