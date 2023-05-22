! main.f90 - Ponteiros
! Uso de Ponteiro
! Autor: Marcos V. Dias Ferreira
! Data: 07/05/2023
PROGRAM MAIN
    IMPLICIT NONE
    INTEGER :: status
    INTEGER, TARGET :: x = 10
    INTEGER, POINTER :: ptrS, ptrD1(:)
    REAL, POINTER :: ptrD2(:,:)
    ptrS => x

    ! Alocando um vetor de inteiros 5x1
    ALLOCATE(ptrD1(5))

    ! Alocando uma matriz de REAL 10x10
    ALLOCATE(ptrD2(10,10),stat = status)

    IF(status /= 0) THEN
        WRITE(*,*) "Erro na alocacao da memoria"
        STOP
    END IF

    WRITE(*,"(I2)") ptrS

    ! Removendo da memoria o espaco alocado no ponteiro D1
    DEALLOCATE(ptrD1)
    ! Removendo da memoria o espaco alocado no ponteiro D2
    DEALLOCATE(ptrD2)
END PROGRAM MAIN

