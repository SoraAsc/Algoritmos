! main.f90 - Paridade de um Numero
! Programa responsavel por dizer se um numero eh par ou impar.
! Autor: Marcos V. Dias Ferreira
! Data: 22/04/2023
PROGRAM ParidadeNumero
    IMPLICIT NONE
    INTEGER :: i
    INTEGER, PARAMETER ::  N = 20
    DO i = 1, N
        IF (MOD(i, 2) == 0) THEN
            PRINT *, i, " eh par"
        ELSE
            PRINT *, i, " eh impar"
        END IF
    END DO
END PROGRAM

