! main.f90 - Media Notas
! Um simples programa responsavel por mostrar o uso da entrada e saida de dados.
! Autor: Marcos V. Dias Ferreira
! Data: 21/04/2023
PROGRAM MediaNotas
    IMPLICIT NONE
    REAL :: n1, n2, n3, n4, media
    WRITE(*,"(a)", ADVANCE="no") "Primeira nota: "
    READ(*, *) n1
    PRINT "(a,$)", "Segunda nota: "
    READ(*, *) n2
    WRITE(*,"(a)", ADVANCE="no") "Terceira nota: "
    READ(*, *) n3
    WRITE(*,"(a)", ADVANCE="no") "Ultima nota: "
    READ(*, *) n4
    media = (n1 + n2 + n3 + n4) / 4
    WRITE(*, '(a, f0.2)') "A media do aluno eh = ", media
END PROGRAM

