! main.f90 - AreaCilindro
! Um simples programa responsavel por mostrar o case-insensitive.
! Autor: Marcos V. Dias Ferreira
! Data: 09/04/2023
PROGRAM Cilindro
    IMPLICIT NONE
    REAL, PARAMETER :: PI = 3.14
    !INTEGER, PARAMETER :: pi = 3 !Aponta um erro pela duplicidade do nome.
    REAL :: raio, areaBase
    raio = 2.0
    areaBase = pi * raio**2 ! Vai reconhecer o PI acima normalmente
    PRINT *, "A area da base eh:",areaBase
END PROGRAM Cilindro
