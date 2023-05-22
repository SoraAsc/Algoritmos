! AbsolutoModule.f90 - Generico do Numero Absoluto
! Module Absoluto
! Autor: Marcos V. Dias Ferreira
! Data: 16/05/2023
MODULE Absolute_Module
    IMPLICIT NONE

    INTERFACE Valor_Absoluto
        MODULE PROCEDURE Valor_Absoluto_REAL, Valor_Absoluto_INTEGER
    END INTERFACE

    CONTAINS
    REAL FUNCTION Valor_Absoluto_REAL(n)
        REAL, INTENT(IN) :: n
        IF (n < 0) THEN
            Valor_Absoluto_REAL = -n
        ELSE
            Valor_Absoluto_REAL = n
        END IF
    END FUNCTION Valor_Absoluto_REAL

    FUNCTION Valor_Absoluto_INTEGER(n) RESULT(res)
        INTEGER, INTENT(IN) :: n
        INTEGER :: res
        IF (n < 0) THEN
            res = -n
        ELSE
            res = n
        END IF
    END FUNCTION Valor_Absoluto_INTEGER
END MODULE Absolute_Module

