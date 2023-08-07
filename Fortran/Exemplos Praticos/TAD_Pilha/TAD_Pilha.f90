! TAD_Pilha.f90 - TAD_Pilha
! TAD_Pilha Declaracao
! Autor: Marcos V. Dias Ferreira
! Data: 08/06/2023
MODULE Pilha_Module
    IMPLICIT NONE

    TYPE, PRIVATE :: T_NODE
        INTEGER :: valor
        TYPE(T_NODE), POINTER :: proximo
    END TYPE T_NODE

    TYPE :: T_PILHA
        INTEGER, PRIVATE :: tam = 0 ! Tamanho da Pilha
        TYPE(T_NODE), PRIVATE, POINTER :: top ! Topo da Pilha
    END TYPE T_PILHA

    CONTAINS

    SUBROUTINE PilhaCriar(pilha)
        TYPE(T_PILHA), POINTER, INTENT(OUT) :: pilha
        ALLOCATE(pilha)
        NULLIFY(pilha%top)
        pilha%tam = 0
    END SUBROUTINE PilhaCriar

    FUNCTION PilhaVazia(pilha) result(estahVazio)
        TYPE(T_PILHA), POINTER, INTENT(IN) :: pilha
        LOGICAL :: estahVazio
        estahVazio = pilha%tam == 0
    END FUNCTION

    SUBROUTINE PilhaEmpilhar(pilha, valor)
        TYPE(T_PILHA), POINTER, INTENT(IN) :: pilha
        TYPE(T_NODE), POINTER :: novo_no
        INTEGER, INTENT(IN) :: valor

        ALLOCATE(novo_no)
        novo_no%proximo => pilha%top
        novo_no%valor = valor
        pilha%top => novo_no

        pilha%tam = pilha%tam + 1
    END SUBROUTINE PilhaEmpilhar

    SUBROUTINE PilhaDesempilhar(pilha, valor)
        TYPE(T_PILHA), POINTER, INTENT(IN) :: pilha
        INTEGER, INTENT(OUT) :: valor
        TYPE(T_NODE), POINTER :: temp_no

        IF(PilhaVazia(pilha)) THEN
            PRINT *,"Nao eh possivel desempilhar uma pilha vazia"
            RETURN
        END IF

        temp_no => pilha%top%proximo
        valor = pilha%top%valor
        DEALLOCATE(pilha%top)
        pilha%top => temp_no

        pilha%tam = pilha%tam - 1
    END SUBROUTINE PilhaDesempilhar

    SUBROUTINE PilhaDesalocar(pilha)
        TYPE(T_PILHA), POINTER, INTENT(INOUT) :: pilha
        TYPE(T_NODE), POINTER :: temp_no
        DO WHILE(ASSOCIATED(pilha%top))
            temp_no => pilha%top%proximo
            DEALLOCATE(pilha%top)
            pilha%top => temp_no
        END DO
        DEALLOCATE(pilha)
    END SUBROUTINE PilhaDesalocar

END MODULE Pilha_Module
