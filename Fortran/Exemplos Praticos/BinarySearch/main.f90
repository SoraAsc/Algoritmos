! main.f90 - Binary Search
! Gera e busca um elemento no vetor
! Autor: Marcos V. Dias Ferreira
! Data: 10/06/2023
MODULE SORT
    PRIVATE
    PUBLIC :: QUICK_SORT

    CONTAINS

    SUBROUTINE PARTICAO(vetor, esq, dir, pivo_index)
        IMPLICIT NONE
        INTEGER :: vetor(:), temp, pivo, i
        INTEGER, INTENT(IN) :: esq, dir
        INTEGER, INTENT(OUT) :: pivo_index

        pivo = vetor(esq)
        pivo_index = esq

        DO i = esq+1,dir
            IF(vetor(i) <= pivo) THEN
                pivo_index = pivo_index + 1
                temp = vetor(pivo_index)
                vetor(pivo_index) = vetor(i)
                vetor(i) = temp
            END IF
        END DO

        temp = vetor(pivo_index)
        vetor(pivo_index) = vetor(esq)
        vetor(esq) = temp
    END SUBROUTINE

    RECURSIVE SUBROUTINE QUICK_SORT(vetor, esq, dir)
        IMPLICIT NONE
        INTEGER, INTENT(IN) :: vetor(:), esq, dir
        INTEGER :: pivo_index
        ! Continue dividindo o vetor, enquanto houver vetores a esquerda e a direita
        IF(dir > esq) THEN
            CALL PARTICAO(vetor, esq, dir, pivo_index)
            CALL QUICK_SORT(vetor, esq, pivo_index -1)
            CALL QUICK_SORT(vetor, pivo_index + 1, dir)
        END IF
    END SUBROUTINE QUICK_SORT
END MODULE SORT

PROGRAM MAIN
    USE SORT
    IMPLICIT NONE
    INTEGER :: i, valor
    REAL :: valor_aleatorio
    INTEGER, PARAMETER :: n = 40
    INTEGER, DIMENSION(n) :: v

    CALL RANDOM_SEED()
    PRINT *, "Vetor Original"
    DO i=1, n
        CALL RANDOM_NUMBER(valor_aleatorio)
        v(i) = int(valor_aleatorio * 100)
        WRITE(*,"(I0, A)", ADVANCE="NO") v(i), " "
    END DO

    CALL QUICK_SORT(v, 1, SIZE(v))
    PRINT *, NEW_LINE(""),"Vetor Ordenado"
    DO i=1, n
        WRITE(*,"(I0, A)", ADVANCE="NO") v(i), " "
    END DO


    WRITE(*,"(A)", ADVANCE="NO") NEW_LINE(""),"Informe o valor a ser buscado ou -1 para encerrar: "
    READ(*,*) valor
    DO WHILE(valor >= 0)
        IF(BINARY_SEARCH(v,valor)) THEN
            WRITE(*,*) "Valor Encontrado"
        ELSE
            WRITE(*,*) "Valor nao Encontrado"
        END IF
        WRITE(*,"(A)", ADVANCE="NO") "Informe o valor a ser buscado ou -1 para encerrar: "
        READ(*,*) valor
    END DO

    CONTAINS
    LOGICAL FUNCTION BINARY_SEARCH(vetor, search_value) RESULT(encontrou)
        IMPLICIT NONE
        INTEGER, INTENT(IN) :: vetor(:), search_value
        INTEGER :: esq, dir, meio
        esq = 1
        dir = SIZE(vetor)
        encontrou = .FALSE.
        DO WHILE(esq <= dir)
            meio = (esq + dir) / 2
            IF(vetor(meio) == search_value) THEN
                encontrou = .TRUE.
                exit
            ELSE IF(search_value < vetor(meio)) THEN
                dir = meio -1
            ELSE
                esq = meio + 1
            END IF
        END DO
    END FUNCTION BINARY_SEARCH
END PROGRAM MAIN
