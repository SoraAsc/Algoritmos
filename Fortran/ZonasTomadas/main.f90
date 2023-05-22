! main.f90 - Zonas Tomadas
! Uso de TYPE em conjunto com matriz
! Autor: Marcos V. Dias Ferreira
! Data: 06/05/2023
PROGRAM MAIN
    IMPLICIT NONE

    TYPE :: T_CELULA
        LOGICAL :: zonaTomada
    END TYPE T_CELULA

    INTEGER :: i,j
    REAL :: prob
    INTEGER, PARAMETER :: N = 4, M = 4

    ! Bidimensional
    TYPE(T_CELULA) :: matriz(N,M)
    !TYPE(T_CELULA), DIMENSION(N,M) :: matriz

    ! Multidimensional
    !TYPE(T_CELULA) :: matriz(N,M,4,9) ! etc...
    !TYPE(T_CELULA), DIMENSION(N,M,4,9) :: matriz

    CALL RANDOM_SEED()

    DO i=1, N
        DO j=1, M
            CALL RANDOM_NUMBER(prob)
            IF (prob >= 0.5) then
                matriz(i,j)%zonaTomada = .TRUE.
            ELSE
                matriz(i,j)%zonaTomada = .FALSE.
            END IF
        END DO
    END DO

    WRITE(*,"(17A)") ("-",i = 1, M*4 + 1)

    DO i=1, N
        WRITE(*,"(A1)", ADVANCE = "NO") "|"
        DO j=1, M
            CALL RANDOM_NUMBER(prob)
            IF (matriz(i,j)%zonaTomada .EQV. .TRUE.) THEN
                WRITE(*,"(A4)", ADVANCE = "NO") " T |"
            ELSE
                WRITE(*,"(A4)", ADVANCE = "NO") "   |"
            END IF
        END DO
        WRITE(*,*)
        WRITE(*,"(A)") REPEAT("-", M*4 + 1)
    END DO

END PROGRAM MAIN

