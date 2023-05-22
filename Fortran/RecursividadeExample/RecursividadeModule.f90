! Recursividade_Module.f90 - Recursividade Module
! Module Recursividade
! Autor: Marcos V. Dias Ferreira
! Data: 17/05/2023
MODULE Recursividade_Module
    IMPLICIT NONE

    CONTAINS
    RECURSIVE FUNCTION Fatorial(n) result(resultado)
        INTEGER, INTENT(IN) :: n
        INTEGER :: resultado
        IF (n == 0) THEN
            resultado = 1
        ELSE
            resultado = n * fatorial(n-1)
        END IF
    END FUNCTION Fatorial

    RECURSIVE SUBROUTINE Fibonacci(n, resultado)
        IMPLICIT NONE
        INTEGER, INTENT(IN) :: n
        INTEGER :: r1,r2
        INTEGER, INTENT(OUT) :: resultado

        IF(n == 0) THEN
            resultado = 0
        ELSEIF(n == 1) THEN
            resultado = 1
        ELSE

            CALL Fibonacci(n-1, r1)
            CALL Fibonacci(n-2, r2)
            resultado = r1 + r2
        END IF
    END SUBROUTINE Fibonacci
END MODULE Recursividade_Module


