! main.f90 - Pares
! Programa responsavel por mostrar apenas os numeros pares.
! Autor: Marcos V. Dias Ferreira
! Data: 22/04/2023
PROGRAM Pares
    IMPLICIT NONE
    INTEGER :: i
    INTEGER, PARAMETER ::  N = 19
    DO i = 2, N, 2 ! i = 2: Inicializacao, N: Ate quando iterar, 2 Quanto vai pular
        PRINT *, i, " eh par"
    END DO
END PROGRAM

