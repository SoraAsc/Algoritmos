! main.f90 - Valor Absoluto
! Valor Absoluto
! Autor: Marcos V. Dias Ferreira
! Data: 16/05/2023
PROGRAM Main
    IMPLICIT NONE
    WRITE(*,"(A,I2)") "O valor absoluto de -7 eh = ",Valor_Absoluto(-7)
    WRITE(*,"(A,I2)") "O valor absoluto de 5 eh = ",Valor_Absoluto(5)
    CONTAINS
    INTEGER FUNCTION Valor_Absoluto(n) !RESULT(res)
        INTEGER, INTENT(IN) :: n
        IF (n < 0) THEN
            ! res = -n
            Valor_Absoluto = -n
        ELSE
            ! res = n
            Valor_Absoluto = n
        END IF
        RETURN
    END FUNCTION Valor_Absoluto

END PROGRAM Main


