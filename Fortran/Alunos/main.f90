! main.f90 - Alunos
! Uso de TYPE em conjunto com vetor
! Autor: Marcos V. Dias Ferreira
! Data: 06/05/2023
PROGRAM MAIN
    IMPLICIT NONE
    TYPE :: T_Alunos
        REAL :: n1,n2,n3,media
    END TYPE T_Alunos
    INTEGER :: i
    INTEGER, PARAMETER :: quant_alunos = 10

    TYPE(T_Alunos), DIMENSION(quant_alunos) :: alunos
    ! OU
    !TYPE(T_Alunos) :: alunos(quant_alunos)

    CALL RANDOM_SEED()

    ! Gerar Valores
    DO i = 1, quant_alunos
        CALL RANDOM_NUMBER(alunos(i)%n1)
        alunos(i)%n1 = alunos(i)%n1 * 10.0
        CALL RANDOM_NUMBER(alunos(i)%n2)
        alunos(i)%n2 = alunos(i)%n2 * 10.0
        CALL RANDOM_NUMBER(alunos(i)%n3)
        alunos(i)%n3 = alunos(i)%n3 * 10.0
        alunos(i)%media = (alunos(i)%n1 + alunos(i)%n2 + alunos(i)%n3) / 3
    END DO

    ! Mostrar Valores
    DO i = 1, quant_alunos
        WRITE(*,"(A,I2,A,F5.2)") "Aluno(",i,") tem uma media de ",alunos(i)%media
    END DO
END PROGRAM MAIN

