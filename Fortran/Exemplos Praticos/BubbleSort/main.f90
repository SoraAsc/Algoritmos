! main.f90 - Bubble Sort
! Gera e Ordenada um vetor com o Bubble Sort
! Autor: Marcos V. Dias Ferreira
! Data: 08/06/2023
PROGRAM MAIN
    IMPLICIT NONE
    INTEGER :: i, j
    INTEGER, PARAMETER :: n = 40
    REAL :: temp
    REAL, ALLOCATABLE :: v(:)

    ALLOCATE(v(n))

    CALL RANDOM_SEED()
    CALL RANDOM_NUMBER(v)
    v = FLOOR(v * 100)
    PRINT *, "Vetor Original"

    DO i=1, n
        WRITE(*,"(F4.1, A)", ADVANCE="NO") v(i), " "
        !IF (MOD(i,5) == 0 ) PRINT *, "Linha", (i/5)
    END DO

    DO i=1, n
        DO j=1, n-1
            IF (v(j) > v(j+1)) THEN
                temp = v(j+1)
                v(j+1) = v(j)
                v(j) = temp
            END IF
        END DO
    END DO
    PRINT *, NEW_LINE(""),NEW_LINE(""), "Vetor Ordenado"
    DO i=1, n
        WRITE(*,"(F4.1, A)", ADVANCE="NO") v(i), " "
        !IF (MOD(i,5) == 0 ) PRINT *, "Linha", (i/5)
    END DO

    DEALLOCATE(v)
END PROGRAM MAIN

