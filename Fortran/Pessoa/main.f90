! main.f90 - Pessoa
! Uso do TYPE
! Autor: Marcos V. Dias Ferreira
! Data: 06/05/2023
PROGRAM Pessoa
    IMPLICIT NONE

    TYPE :: T_Pessoa
        CHARACTER(len=50) :: nome
        INTEGER :: idade
        REAL :: peso
    END TYPE T_Pessoa

    TYPE(T_Pessoa) :: pessoa_1

    pessoa_1%nome = 'Pedro'
    pessoa_1%idade = 29
    pessoa_1%peso = 100

    WRITE(*,"(A,2A,I2,A,F6.2,A)") "Ola ",TRIM(pessoa_1%nome), &
    & " atualmente voce tem ",pessoa_1%idade," anos e pesa ",pessoa_1%peso," kg."
END PROGRAM Pessoa

