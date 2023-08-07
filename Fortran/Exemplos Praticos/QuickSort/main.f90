! main.f90 - Quick Sort
! Gera e Ordenada um vetor com o Quick Sort
! Autor: Marcos V. Dias Ferreira
! Data: 08/06/2023
MODULE SORT
    PRIVATE
    PUBLIC :: QUICK_SORT

    CONTAINS

    SUBROUTINE PARTICAO(vetor, esq, dir, pivo_index)
        IMPLICIT NONE
        REAL :: vetor(:), temp, pivo
        INTEGER :: i
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
        REAL, INTENT(IN) :: vetor(:)
        INTEGER :: esq, dir, pivo_index
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
    INTEGER :: i
    INTEGER, PARAMETER :: n = 40
    REAL, ALLOCATABLE :: v(:)

    ALLOCATE(v(n))

    CALL RANDOM_SEED()
    CALL RANDOM_NUMBER(v)
    v = FLOOR(v * 100)
    PRINT *, "Vetor Original"

    DO i=1, n
        WRITE(*,"(F4.1, A)", ADVANCE="NO") v(i), " "
        !IF (MOD(i,5) == 0 ) PRINT *, "Linha", (i/5)
    END DO

    CALL QUICK_SORT(v, 1, SIZE(v))

    PRINT *, NEW_LINE(""),NEW_LINE(""), "Vetor Ordenado"
    DO i=1, n
        WRITE(*,"(F4.1, A)", ADVANCE="NO") v(i), " "
        !IF (MOD(i,5) == 0 ) PRINT *, "Linha", (i/5)
    END DO

    DEALLOCATE(v)
END PROGRAM MAIN

