! main.f90 - GUESS NUMBER
! Um simples joguinho, de adivinhar um numero
! Autor: Marcos V. Dias Ferreira
! Data: 10/06/2023
PROGRAM MAIN
    IMPLICIT NONE
    ! n eh o numero escolhido aleatoriamente
    ! minNum o intervalo minimo selecionado pelo jogador
    ! maxNum o intervalo maximo selecionado pelo jogador
    ! nEscolhido eh o numero escolhido pelo jogador
    ! tentativas eh o numero de tentativas feitas ate achar o numero certo
    INTEGER :: n, minNum, maxNum, nEscolhido, tentativas
    REAL :: numeroAleatorio ! Variavel temporaria para conter o random number

    WRITE(*, "(A)", ADVANCE="NO") "Informe o intervalo min e maximo: "
    READ(*, *) minNum, maxNum

    ! caso o usuario informe um intervalo invalido
    IF(minNum >= maxNum) THEN
        maxNum = minNum + 100
    END IF

    CALL RANDOM_SEED()
    CALL RANDOM_NUMBER(numeroAleatorio)
    n = minNum + int(numeroAleatorio * (maxNum - minNum) )

    tentativas = 0
    DO WHILE (.TRUE.)
        WRITE(*, "(A)", ADVANCE="NO") "Informe o numero: "
        READ(*, *) nEscolhido
        tentativas = tentativas + 1
        IF (nEscolhido .LT. n) THEN
            WRITE(*,"(A)") "Pense em um numero maior"
        ELSE IF(nEscolhido .GT. n) THEN
            WRITE(*,"(A)") "Pense em um numero menor"
        ELSE
            WRITE(*,"(A,I0,A,I0,A)") "Parabens Voce acertou o numero ", nEscolhido, " com ", tentativas, " tentativas"
            EXIT
        END IF
    END DO
END PROGRAM MAIN

