! main.f90 - Linear Search
! Gera e busca um elemento no vetor
! Autor: Marcos V. Dias Ferreira
! Data: 08/06/2023
PROGRAM MAIN
    IMPLICIT NONE
    INTEGER :: i, valor
    REAL :: valor_aleatorio
    INTEGER, PARAMETER :: n = 40
    INTEGER, DIMENSION(n) :: v

    CALL RANDOM_SEED()
    PRINT *, "Vetor"
    DO i=1, n
        CALL RANDOM_NUMBER(valor_aleatorio)
        v(i) = int(valor_aleatorio * 100)
        WRITE(*,"(I0, A)", ADVANCE="NO") v(i), " "
    END DO


    WRITE(*,"(A)", ADVANCE="NO") NEW_LINE(""),"Informe o valor a ser buscado ou -1 para encerrar: "
    READ(*,*) valor
    DO WHILE(valor >= 0)
        IF(LINEAR_SEARCH(v,valor)) THEN
            WRITE(*,*) "Valor Encontrado"
        ELSE
            WRITE(*,*) "Valor nao Encontrado"
        END IF
        WRITE(*,"(A)", ADVANCE="NO") "Informe o valor a ser buscado ou -1 para encerrar: "
        READ(*,*) valor
    END DO

    CONTAINS
    LOGICAL FUNCTION LINEAR_SEARCH(vetor, valor) RESULT(encontrou)
        IMPLICIT NONE
        INTEGER, INTENT(IN) :: vetor(:), valor
        INTEGER :: i
        DO i=1,SIZE(vetor)
            IF(vetor(i) == valor) THEN
                encontrou = .TRUE.
                RETURN
            END IF
        END DO
        encontrou = .FALSE.
    END FUNCTION LINEAR_SEARCH
END PROGRAM MAIN

