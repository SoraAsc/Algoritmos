! NumeroModule.f90 - Numero Module
! Module armazenando funcoes e variaveis
! Autor: Marcos V. Dias Ferreira
! Data: 16/05/2023
MODULE Numero_Module
    IMPLICIT NONE
    REAL :: num
    CONTAINS
    FUNCTION Valor_Absoluto(n) RESULT(res)
        REAL, INTENT(IN) :: n
        REAL :: res
        IF (n < 0) THEN
            res = -n
        ELSE
            res = n
        END IF
    END FUNCTION Valor_Absoluto

    SUBROUTINE SOMA2NUM(n1,n2)
        REAL :: n1, n2
        WRITE(*, "(A,F5.2,A,F5.2,A,F5.2)") "Soma de ",n1," + ",n2," = ",n1+n2
    END SUBROUTINE

END MODULE Numero_Module

