! Operacoes.f90 - Calculadora
! Operacoes da Calculadora
! Autor: Marcos V. Dias Ferreira
! Data: 10/06/2023
MODULE ModuleOperacoes
    IMPLICIT NONE

    CONTAINS

    ! Mostra todas as opcoes disponiveis
    SUBROUTINE MostrarOpcoes()
        WRITE(*,"(A)") "---------------- Opcoes Disponiveis ----------------"
        WRITE(*, "(A)") "1) Listar Opcoes"
        WRITE(*, "(A)") "2) Adicao"
        WRITE(*, "(A)") "3) Subtracao"
        WRITE(*, "(A)") "4) Multiplicacao"
        WRITE(*, "(A)") "5) Divisao"
        WRITE(*, "(A)") "6) Binario"
        WRITE(*, "(A)") "7) Segundo Grau"
        WRITE(*, "(A)") "8) Limpar Terminal"
        WRITE(*,"(A)") "-----------------------------------------------------"
    END SUBROUTINE MostrarOpcoes

    ! Soma dois numeros reais
    REAL FUNCTION Adicao(n1, n2)
        REAL, INTENT(IN) :: n1, n2
        Adicao = n1+n2
    END FUNCTION Adicao

    ! Subtrai dois numeros reais
    REAL FUNCTION Subtracao(n1, n2)
        REAL, INTENT(IN) :: n1, n2
        Subtracao = n1-n2
    END FUNCTION Subtracao

    ! Multiplica dois numeros reais
    REAL FUNCTION Multiplicacao(n1, n2)
        REAL, INTENT(IN) :: n1, n2
        Multiplicacao = n1*n2
    END FUNCTION Multiplicacao

    ! Divide dois numeros reais
    REAL FUNCTION Divisao(n1, n2)
        REAL, INTENT(IN) :: n1, n2
        Divisao = n1/n2
    END FUNCTION Divisao

    ! Converte um numero inteiro na sua versao em binario
    CHARACTER(LEN=50) FUNCTION Binario(n)
        INTEGER, INTENT(IN) :: n
        CHARACTER(LEN=50) :: binarioString, binarioStringReversa
        INTEGER :: i, j, resto, numero
        binarioString = ""
        binarioStringReversa = ""
        numero = n
        i = 1 ! Contador da posicao atual da string
        DO WHILE(numero > 0)
            resto = MOD(numero, 2)
            numero = numero / 2
            ! Os valores numericos da tabela ASCII comecam em 48
            ! ou seja ao somar o resto 1 ou 2, por 48, temos as posicoes
            ! 48 = 0 e 49 = 1
            binarioString(i:i) = char(resto + 48)
            i = i + 1
        END DO

        j = 1
        DO i = len_trim(binarioString), 1, -1
            binarioStringReversa(j:j) = binarioString(i:i)
            j = j + 1
        END DO

        Binario = binarioStringReversa

    END FUNCTION Binario

    ! Descobre as raizes de uma funcao do segundo grau
    SUBROUTINE SegundoGrau(a, b, c)
        REAL, INTENT(IN) :: a, b, c
        REAL x1, x2, delta

        WRITE(*,"(F0.1,A,F0.1,A,F0.1)") a,"x^2 + ",b,"x + ",c

        delta = b**2 - 4*a*c

        IF (delta > 0) THEN
            x1 = (-b + sqrt(delta)) / (2*a)
            x2 = (-b - sqrt(delta)) / (2*a)
            WRITE(*,"(A,F0.2,A,F0.2)") "x1 = ",x1, " e x2 = ",x2
        ELSE IF(delta == 0) THEN
            x1 = (-b + sqrt(delta)) / (2*a)
            WRITE(*,"(A,F0.2,A,F0.2)") "x1 = ",x1, " e x2 = ",x1
        ELSE
            WRITE(*, "(A)") "Nao ha raizes reais."
        END IF
    END SUBROUTINE SegundoGrau

    ! Limpa o Terminal, depende do S.O
    SUBROUTINE LimparTerminal()
        character(len=100) :: command
        command = "cls"
        !command = "clear" ! se for linux
        call execute_command_line(command)
    END SUBROUTINE LimparTerminal

END MODULE ModuleOperacoes
