; maxim(a : intreg, b : intreg)
; Gaseste maximul dintre doua numere
; Returneaza valoarea maximului
; Model matematic: maxim(a, b) = { a, daca a > b }
;								 { b, altfel }
; Teste:
; (maxim 2 3) 
; (maxim 9 7)
(defun maxim(a b)
	(cond
		((> a b) a)
		(t b)
	)
)

; adancime(arb: lista neliniara)
; Gaseste adancimea unui arbore binar pe reprezentarea a doua
; Returneaza valoarea adancimii
; Model matematic: adancime(l1l2...ln) = { 0, daca n = 0 } (arbore vid)
;										 { 1, daca n = 1 }
;										 { 1 + adancime(l2), daca n = 2 }
;										 { 1 + maxim(adancime(l2), adancime(l3), daca n = 3 }
; Teste:
; (adancime '(A (B) (C (D) (E))))
; (adancime '(A (B (C) (D (E))) (F (G (H) (I (J) (K))) (L (M (N (O))) (P (Q) (R))))))
; (adancime '(A))
; (adancime '())
(defun adancime(arb)
	;(write arb)
	;(terpri)
	(cond
		((null arb) 0)
		((null (cdr arb)) 1)
		((null (cddr arb)) (+ 1 (adancime (car (cdr arb)))))
		(t (+ 1 (maxim (adancime (car (cdr arb))) (adancime (car (cddr arb))))))
	)
)

; esteEchilibrat(arb: lista neliniara)
; Gaseste daca un arbore binar pe reprezentarea a doua este echilibrat
; Returneaza t daca e echilibrat si NIL altfel
;											{ t, daca n = 0 }
; Model matematic: esteEchilibrat(l1l2l3) = { esteEchilibrat(l2) ^ esteEchilibrat(l3), daca |adancime(l2) - adancime(l3)| <= 1 }
; 											{ nil, altfel }
; Teste:
; (esteEchilibratSubarbori '(A (B) (C (D) (E)))) = true
; (esteEchilibratSubarbori '(A)) = true
; (esteEchilibratSubarbori '(A (B (C)))) = false
; (esteEchilibratSubarbori '(A (B (C) (D)) (E (F (G (H) (I)) (J)) (K (L) (M))))) = false
; (esteEchilibratSubarbori '()) = true
(defun esteEchilibratSubarbori(arb)
	(cond 
		((null arb) t)
		((and (esteEchilibratSubarbori (car (cdr arb))) (esteEchilibratSubarbori (car (cddr arb))) (<= (abs (- (adancime (car (cdr arb))) (adancime (car (cddr arb))))) 1)) t)
		(t ())
	)
)