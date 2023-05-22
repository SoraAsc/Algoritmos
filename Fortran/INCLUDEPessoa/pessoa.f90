! pessoa.f90 - PessoaEndereco
! Declaracao do TYPE
! Autor: Marcos V. Dias Ferreira
! Data: 06/05/2023
MODULE Pessoa_Module
    IMPLICIT NONE
    TYPE :: T_Endereco
        CHARACTER(len=30) :: cidade
        CHARACTER(len=30) :: rua
        INTEGER :: numero
    END TYPE T_Endereco

    TYPE :: T_Pessoa
        CHARACTER(len=50) :: nome
        INTEGER :: idade
        REAL :: peso
        TYPE(T_Endereco) :: endereco
    END TYPE T_Pessoa
END MODULE Pessoa_Module
