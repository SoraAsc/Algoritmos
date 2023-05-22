! main.f90 - Vetor
! Programa responsavel por criar e mostrar os elementos de um vetor.
! Autor: Marcos V. Dias Ferreira
! Data: 22/04/2023
PROGRAM Vetor
    IMPLICIT NONE
    REAL :: v(10)
    INTEGER :: i = 1
    INTEGER, PARAMETER :: N = 10
    CALL RANDOM_SEED()
    DO WHILE(i<=N)
        CALL RANDOM_NUMBER(v(i))
        i = i + 1
    END DO
    WRITE(*, '(5F6.2)') (v(i), i = 1, N)
END PROGRAM

