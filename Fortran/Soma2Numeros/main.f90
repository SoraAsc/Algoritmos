! main.f90 - Soma de Dois Numeros
! Soma de dois numeros com subroutine
! Autor: Marcos V. Dias Ferreira
! Data: 16/05/2023
PROGRAM Main
    IMPLICIT NONE
    CALL SOMA2NUM(21,9)
    CALL SOMA2NUM(14,-4)
END PROGRAM Main

SUBROUTINE SOMA2NUM(n1,n2)
    INTEGER :: n1, n2
    WRITE(*, "(A,I3,A,I3,A,I3)") "Soma de ",n1," + ",n2," = ",n1+n2
END SUBROUTINE


