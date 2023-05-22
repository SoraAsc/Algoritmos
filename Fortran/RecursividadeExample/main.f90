! main.f90 - Recursividade
! Uso de funcoes recursivas
! Autor: Marcos V. Dias Ferreira
! Data: 17/05/2023
PROGRAM Main
    USE Recursividade_Module
    IMPLICIT NONE
    INTEGER, PARAMETER :: n = 12
    INTEGER :: resultado_fibo = 0
    CALL Fibonacci(n, resultado_fibo)
    WRITE(*,"(A,I0,A,I0)") "O Fatorial de ",n," eh = ",Fatorial(n)
    WRITE(*,"(A,I0,A,I0)") "O Fibonacci de ",n," eh = ",resultado_fibo
END PROGRAM Main
