! main.f90 - Cores
! Uso de ENUM
! Autor: Marcos V. Dias Ferreira
! Data: 06/05/2023
PROGRAM MAIN
    IMPLICIT NONE
    ENUM, BIND(C)
        ENUMERATOR :: RED = 1, BROWN
        ENUMERATOR :: GREEN
        ENUMERATOR BLUE
        ENUMERATOR :: PINK
    END ENUM


    !INTEGER(KIND = RED) :: cor

    !WRITE(*,*) "A cor atual eh ", KIND(cor)

END PROGRAM MAIN

