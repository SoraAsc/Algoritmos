! main.f90 - TAD Lista Uso
! Uso de Uma lista Basica
! Autor: Marcos V. Dias Ferreira
! Data: 17/05/2023
PROGRAM Main
    USE Lista_Module
    IMPLICIT NONE
    TYPE(T_Lista) :: lista1

    ! Criando a lista
    CALL criarLista(lista1)

    CALL adicionarNaLista(lista1, 5)
    CALL adicionarNaLista(lista1, -8)
    CALL adicionarNaLista(lista1, 29)
    CALL adicionarNaLista(lista1, 58)

    WRITE(*,"(A)") "Os valores da lista"
    CALL mostrarLista(lista1)

    CALL removerDaLista(lista1, 29)
    CALL removerDaLista(lista1, 5)

    WRITE(*,"(A)") "Os valores da lista atualizada"
    CALL mostrarLista(lista1)

    ! Apagando a Lista da memoria
    CALL apagarLista(lista1)

END PROGRAM Main
