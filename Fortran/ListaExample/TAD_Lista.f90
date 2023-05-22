! TAD_Lista.f90 - TAD_Lista
! TAD_Lista declaracao
! Autor: Marcos V. Dias Ferreira
! Data: 17/05/2023
MODULE Lista_Module

    IMPLICIT NONE

    PRIVATE ! Faz todos os conteudos privados por padrao
    ! Define quais metodos variaveis, estruturas ou funcoes podem ser acessados fora desse modulo
    PUBLIC :: T_Lista, criarLista, apagarLista, adicionarNaLista, removerDaLista, mostrarLista
    TYPE :: T_Node
        INTEGER :: valor
        TYPE(T_Node), POINTER :: proximo
    END TYPE T_Node

    TYPE :: T_Lista
        INTEGER :: tam = 0 ! Tamanho da Lista
        TYPE(T_Node), POINTER :: inicio
        !TYPE(T_Node), POINTER :: fim
    END TYPE T_Lista

    CONTAINS
    ! Cria uma nova lista
    SUBROUTINE criarLista(l)
        TYPE(T_Lista), INTENT(INOUT) :: l
        l%tam = 0
        NULLIFY(l%inicio)
        !NULLIFY(l%fim)
    END SUBROUTINE criarLista

    ! Adiciona um elemento no final da lista
    SUBROUTINE adicionarNaLista(l, valor)
        TYPE(T_Lista), INTENT(INOUT) :: l
        TYPE(T_Node), POINTER :: no_Auxiliar, no_Auxiliar_Anterior, no_Auxiliar_Temporario
        INTEGER, INTENT(IN) :: valor
        INTEGER :: status1
        ! Caso onde a lista nao foi iniciada
        IF (l%tam == 0) THEN
            ALLOCATE(l%inicio, stat = status1)
            IF (status1 == 0) THEN
                l%inicio%valor = valor
                NULLIFY(l%inicio%proximo)
                !l%fim => l%inicio
                l%tam = l%tam + 1
            ELSE
                WRITE(*,*) "Falha na alocacao"
            END IF
        ELSE
            no_Auxiliar_Anterior => l%inicio
            no_Auxiliar => l%inicio%proximo
            DO WHILE(ASSOCIATED(no_Auxiliar))
                no_Auxiliar_Temporario => no_Auxiliar
                no_Auxiliar => no_Auxiliar%proximo
                no_Auxiliar_Anterior => no_Auxiliar_Temporario
            END DO
            ALLOCATE(no_Auxiliar, stat = status1)
            no_Auxiliar_Anterior%proximo => no_Auxiliar
            no_Auxiliar%valor = valor
            !l%fim => no_Auxiliar
            NULLIFY(no_Auxiliar%proximo)
            l%tam = l%tam + 1
        END IF
    END SUBROUTINE adicionarNaLista


    SUBROUTINE removerDaLista(l, valor)
        TYPE(T_Lista), INTENT(INOUT) :: l
        TYPE(T_Node), POINTER :: no_Auxiliar, no_Auxiliar_Anterior, no_Auxiliar_Temporario
        INTEGER, INTENT(IN) :: valor

        IF (ASSOCIATED(l%inicio) .AND. l%inicio%valor == valor ) THEN
            no_Auxiliar => l%inicio
            l%inicio => l%inicio%proximo
            DEALLOCATE(no_Auxiliar)
            RETURN
        END IF

        IF (l%tam > 0) THEN
            no_Auxiliar_Anterior => l%inicio
            no_Auxiliar => l%inicio
            DO WHILE(ASSOCIATED(no_Auxiliar%proximo) .AND. no_Auxiliar%valor .NE. valor)
                no_Auxiliar_Temporario => no_Auxiliar
                no_Auxiliar => no_Auxiliar%proximo
                no_Auxiliar_Anterior => no_Auxiliar_Temporario
            END DO
            IF (ASSOCIATED(no_Auxiliar) .AND. no_Auxiliar%valor == valor) THEN
                no_Auxiliar_Anterior%proximo => no_Auxiliar%proximo
                !IF (ASSOCIATED(no_Auxiliar, l%fim)) THEN
                    !l%fim => no_Auxiliar_Anterior
                !END IF
                DEALLOCATE(no_Auxiliar)
                l%tam = l%tam-1
            END IF
        ELSE
            WRITE(*,"(A)") "A lista estah vazia"
        END IF
    END SUBROUTINE removerDaLista

    SUBROUTINE mostrarLista(l)
        TYPE(T_Lista), INTENT(INOUT) :: l
        TYPE(T_Node), POINTER :: no_Auxiliar
        no_Auxiliar => l%inicio
        WRITE(*,"(A)") "------------------------LISTA------------------------"
        DO WHILE(ASSOCIATED(no_Auxiliar))
            WRITE(*,"(I0,A)", ADVANCE="NO") no_Auxiliar%valor, " "
            no_Auxiliar => no_Auxiliar%proximo
        END DO
        WRITE(*,*) ""
        WRITE(*,"(A)") "------------------------FIM LISTA------------------------"
    END SUBROUTINE mostrarLista

    SUBROUTINE apagarLista(l)
        TYPE(T_Lista), INTENT(INOUT) :: l
        CALL apagarNode(l%inicio)
        !IF (ASSOCIATED(l%inicio)) THEN
            !DEALLOCATE(l%inicio)
        !END IF
        !IF (ASSOCIATED(l%fim)) THEN
            !DEALLOCATE(l%fim)
        !END IF
    END SUBROUTINE apagarLista

    RECURSIVE SUBROUTINE apagarNode(no)
        TYPE(T_Node), POINTER :: no
        IF (ASSOCIATED(no%proximo)) THEN
            CALL apagarNode(no%proximo)
        END IF
        DEALLOCATE(no)
    END SUBROUTINE apagarNode

END MODULE Lista_Module

