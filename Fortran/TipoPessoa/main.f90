! main.f90 - BeneficioPessoaTipo
! Um programa responsavel por induzir se uma pessoa esta abta ou nao a receber um beneficio pelo seu tipo
! Autor: Marcos V. Dias Ferreira
! Data: 22/04/2023
PROGRAM BeneficioPessoaTipo
    IMPLICIT NONE
    CHARACTER(LEN = 2) :: tipoPessoa
    PRINT *, "Pessoa Fisica - F | Pessoa Juridica - J"
    WRITE(*, "(A)", ADVANCE = "NO") "Insira que tipo de pessoa voce e: "
    READ(*, *) tipoPessoa
    SELECT CASE (tipoPessoa)
        CASE ("F")
            PRINT *, "Voce tem direito ao beneficio"
        CASE DEFAULT
            PRINT *, "Desculpa, mas voce nao tem direito a esse beneficio"
    END SELECT
END PROGRAM

