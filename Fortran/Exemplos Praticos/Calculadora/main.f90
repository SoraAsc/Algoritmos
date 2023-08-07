! main.f90 - Calculadora
! calculadora Teste
! Autor: Marcos V. Dias Ferreira
! Data: 10/06/2023
PROGRAM MAIN
    USE ModuleOperacoes
    IMPLICIT NONE
    INTEGER :: opcao ! Opcao de calculo escolhido
    REAL :: n1, n2, n3 !numeros usados para operacoes basicas
    INTEGER :: n ! numero usado para conversoes

    CALL MostrarOpcoes()
    DO WHILE (.TRUE.)
        WRITE(*, "(A)", ADVANCE="NO") "Escolha uma das opcoes: "

        READ(*, *) opcao
        SELECT CASE (opcao)
            CASE (1)
                CALL MostrarOpcoes()
            CASE (2)
                WRITE(*, "(A)", ADVANCE="NO") "Digite dois numeros: "
                READ(*, *) n1, n2
                WRITE(*, '(F0.2, A, F0.2, A, F0.2)') n1, " + ", n2, " = ", Adicao(n1,n2)
            CASE (3)
                WRITE(*, "(A)", ADVANCE="NO") "Digite dois numeros: "
                READ(*, *) n1, n2
                WRITE(*, '(F0.2, A, F0.2, A, F0.2)') n1, " - ", n2, " = ", Subtracao(n1,n2)
            CASE (4)
                WRITE(*, "(A)", ADVANCE="NO") "Digite dois numeros: "
                READ(*, *) n1, n2
                WRITE(*, '(F0.2, A, F0.2, A, F0.2)') n1, " x ", n2, " = ", Multiplicacao(n1,n2)
            CASE (5)
                WRITE(*, "(A)", ADVANCE="NO") "Digite dois numeros: "
                READ(*, *) n1, n2
                WRITE(*, '(F0.2, A, F0.2, A, F0.2)') n1, " ÷ ", n2, " = ", Divisao(n1,n2)
            CASE (6)
                WRITE(*, "(A)", ADVANCE="NO") "Digite o numero inteiro: "
                READ(*, *) n
                WRITE(*,"(A)") Binario(n)
            CASE (7)
                WRITE(*, "(A)", ADVANCE="NO") "Digite o valor dos numeros (A B C): "
                READ(*, *) n1, n2, n3
                CALL SegundoGrau(n1, n2, n3)
            CASE (8)
                CALL LimparTerminal()
                CALL MostrarOpcoes()
            CASE DEFAULT
                EXIT
        END SELECT
    END DO
END PROGRAM MAIN

