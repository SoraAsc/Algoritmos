! main.f90 - Numero Absoluto generico
! Uso do Module para as funcoes
! Autor: Marcos V. Dias Ferreira
! Data: 16/05/2023
PROGRAM Main
    USE Absolute_Module
    IMPLICIT NONE
    WRITE(*,"(A,I3)") "O valor absoluto de -5 eh = ",Valor_Absoluto(-5)
    WRITE(*,"(A,F5.2)") "O valor absoluto de -5.5 eh = ",Valor_Absoluto(-5.5)
END PROGRAM Main
