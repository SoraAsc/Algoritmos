! main.f90 - Paralelismo
! Uso de paralelismo
! Autor: Marcos V. Dias Ferreira
! Data: 22/06/2023
PROGRAM Paralelismo
    IMPLICIT NONE
    INTEGER :: i
    INTEGER, PARAMETER :: N = 100000000, CHUNK_SIZE = 10
    REAL :: a(N), b(N), c(N)
    REAL(kind=8) :: start_time, end_time

    ! Inicializar os vetores a e b
    a = 1.0
    b = 2.0
    c = 0.0
    CALL CPU_TIME(start_time)
    ! Iniciar regiao paralela
    !$OMP PARALLEL DEFAULT(SHARED) PRIVATE(i)

        ! Distribuir o loop entre as threads
        !$OMP DO SCHEDULE(DYNAMIC, chunk_size)
            DO i = 1, n
                c(i) = a(i) + b(i)
            END DO
          !Fim do loop paralelo
        !$OMP END DO

    !Fim da regiao paralela
    !$OMP END PARALLEL
    CALL CPU_TIME(end_time)
    PRINT *, "Tempo de Execucao (com paralelismo) eh", (end_time - start_time)

    a = 1.0
    b = 2.0
    c = 0.0
    CALL CPU_TIME(start_time)
    DO i = 1, n
        c(i) = a(i) + b(i)
    END DO
    CALL CPU_TIME(end_time)
    PRINT *, "Tempo de Execucao (sem paralelismo) eh", (end_time - start_time)
END PROGRAM Paralelismo

