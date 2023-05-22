! main.f90 - Sequencia de Fibonacci
! Programa responsavel por mostrar a sequencia de fibonacci.
! Autor: Marcos V. Dias Ferreira
! Data: 22/04/2023
PROGRAM Fibonacci
    IMPLICIT NONE
    INTEGER :: i = 1,valor = 0, valor_anterior = 1, temp
    INTEGER, PARAMETER ::  N = 47 ! Numero de iteracoes
    WRITE(*, "(I0,A)", ADVANCE="NO") valor, " "
    DO
        temp = valor
        valor = valor + valor_anterior
        valor_anterior = temp
        WRITE(*, "(I0,A)", ADVANCE="NO") valor, " "
        i = i + 1
        IF (i > N .OR. i >= 47 ) EXIT
    END DO
END PROGRAM

