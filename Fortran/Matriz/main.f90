! main.f90 - Matriz
! Programa responsavel por criar e mostrar os elementos de uma matriz MxN.
! Autor: Marcos V. Dias Ferreira
! Data: 22/04/2023
PROGRAM ExemploMatriz
    IMPLICIT NONE
    INTEGER, PARAMETER :: M = 5, N = 3
    REAL :: matriz_dados(M, N)
    INTEGER :: i, j
    CALL RANDOM_SEED()

    DO i = 1, M
        DO j = 1, N
            CALL RANDOM_NUMBER(matriz_dados(i,j))
        END DO
    END DO

    DO i = 1, M
        DO j = 1, N
            WRITE(*, '(A,I0,A,I0,A,F5.2)', ADVANCE = "NO") " MATRIZ[",i,",",j,"] = ", matriz_dados(i, j)
        END DO
        WRITE(*, *)
    END DO
END PROGRAM ExemploMatriz

