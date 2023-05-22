! main.f90 - PessoaEndereco
! Uso de TYPE referenciando outro com o INCLUDE
! Autor: Marcos V. Dias Ferreira
! Data: 06/05/2023
PROGRAM PessoaEndProgram
    USE Pessoa_Module
    IMPLICIT NONE
    TYPE(T_Pessoa) :: pessoa_1

    pessoa_1%nome = "Pedro"
    pessoa_1%idade = 29
    pessoa_1%peso = 100
    pessoa_1%endereco%cidade = "Campos Dos Goytacazes"
    pessoa_1%endereco%rua = "Santo Antonio"
    pessoa_1%endereco%numero = 205

    WRITE(*,"(A,2A,I2,A,F6.2,A)") "Ola ",TRIM(pessoa_1%nome), &
    & " atualmente voce tem ",pessoa_1%idade," anos e pesa ",pessoa_1%peso," kg."

    WRITE(*,"(5A,I3)") "Residente de ",TRIM(pessoa_1%endereco%cidade), " na rua ", &
    & TRIM(pessoa_1%endereco%rua), " numero ", pessoa_1%endereco%numero

END PROGRAM PessoaEndProgram

