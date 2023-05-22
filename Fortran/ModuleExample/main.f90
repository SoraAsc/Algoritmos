! main.f90 - Soma de Dois Numeros e Valor Absoluto
! Uso do Module para as funcoes e rotinas
! Autor: Marcos V. Dias Ferreira
! Data: 16/05/2023
PROGRAM Main
    USE Numero_Module
    IMPLICIT NONE
    CALL SOMA2NUM(21.2,9.6)
    CALL SOMA2NUM(14.0,-4.0)

    num = Valor_Absoluto(-5.02)
    WRITE(*,"(A,F5.2)") "O valor absoluto de -5.02 eh = ",num
END PROGRAM Main
