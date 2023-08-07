! main.f90 - Graph Big O Notation
! Mostra um grafico da escala da complexidade dos algoritmos em funcao do tempo
! Autor: Marcos V. Dias Ferreira
! Data: 08/06/2023
PROGRAM MAIN
    IMPLICIT NONE
    INTEGER :: i, n = 60
    REAL x, y1, y2, y3, y4, y5
    ! y1 - Constante | y2 - Logaritma | y3 - Linear | y4 - Quadratica | y5 - Exponencial

    ! Abre o arquivo  na porta 10, com o nome data.txt e com o unknown, define que caso o arquivo exista
    ! ele ira sobrescrever, se nao vai apenas criar
    OPEN(UNIT=10, FILE='data.txt', STATUS='unknown')

    ! Gera os pontos do eixo x do grafico, junto com sua funcao
    y1 = 1.0
    DO i = 1, n
        x = i*0.1
        y2 = MAX(1.0, LOG(x)) ! Previne um valor, menor que 1
        y3 = MAX(1.0, x) ! Previne um valor, menor que 1
        y4 = MAX(1.0, x**2) ! Previne um valor, menor que 1
        y5 = 2**x
        ! Escreve essas informacoes no arquivo data.txt
        WRITE(10, *) x, y1, y2, y3, y4, y5
    END DO

    ! Fecha o arquivo na porta 10
    CLOSE(10)

    ! Call GNUPLOT to plot the graph
    CALL SYSTEM('gnuplot -persist -e "set term wxt enhanced; set mouse; plot &
        & ''data.txt'' using 1:2 with lines title ''Constante (1)'' lc rgb ''red'', &
        & ''data.txt'' using 1:3 with lines title ''Logaritma (logn)'' lc rgb ''blue'', &
        & ''data.txt'' using 1:4 with lines title ''Linear (n)'' lc rgb ''green'', &
        & ''data.txt'' using 1:5 with lines title ''Quadratica (n^2)'' lc rgb ''orange'', &
        & ''data.txt'' using 1:6 with lines title ''Exponencial (2^n)'' lc rgb ''purple''"')

END PROGRAM MAIN

