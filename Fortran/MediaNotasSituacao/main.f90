! main.f90 - Media Notas Situacao
! Um simples programa responsavel por calcular a media e mostrar se o aluno esta aprovado ou nao.
! Autor: Marcos V. Dias Ferreira
! Data: 22/04/2023
PROGRAM MediaNotasSituacao
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
    WRITE(*, '(a, f0.2)', ADVANCE = "no") "O aluno com media = ", media

    IF (media >= 6.0) THEN
        WRITE(*,*) "esta Aprovado"
    ELSE
        WRITE(*,*) "esta Reprovado"
    END IF

END PROGRAM
