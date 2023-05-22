! main.f90 - AreaCilindro
! Um simples programa responsavel por mostrar o uso de variaveis e constantes.
! Autor: Marcos V. Dias Ferreira
! Data: 09/04/2023
PROGRAM Cilindro
    IMPLICIT NONE
    REAL, PARAMETER :: PI = 3.14
    REAL :: raio, areaBase
    raio = 2.0
    areaBase = PI * raio**2
    PRINT *, "A area da base eh:",areaBase
END PROGRAM Cilindro
