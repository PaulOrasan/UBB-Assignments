; lab 1 a)
; inserare_aux(l: lista liniara, e: atom, poz: intreg)
; Insereaza intr-o lista liniara valoarea elementului e dupa elementele de pe pozitii pare
; Returneaza lista obtinuta in urma inserarii sau NIL daca e vida
; Model matematic: inserare_aux(l1..ln, e, poz) = 	{ O, daca n = 0 }
;													{ l1 U inserare_aux(l2...ln, e, poz + 1), daca poz e impar }
;													{ l1 U e U inserare_aux (l2...ln, e, poz + 1), altfel }
(defun inserare_aux(l e poz)
	(cond
		; daca l e vida
		((null l) ())
		; daca pozitia e impara nu adaug e
		((equal (mod poz 2) 1) (cons (car l) (inserare_aux (cdr l) e (+ poz 1))))
		; altfel adaug e
		(t(cons (car l) (cons e (inserare_aux (cdr l) e (+ poz 1)))))
	)
)

; inserare(l: lista liniara, e: atom)
; Insereaza intr-o lista liniara valoarea elementului e dupa elementele de pe pozitii pare
; Model matematic: inserare(l1...ln, e) = { inserare_aux(l1...ln, e, 1) }
; Returneaza lista liniara obtinuta in urma inserarii sau NIL daca e vida
; Teste:
; (inserare '(1 2 3 4) 7)
; (inserare '(1 2 3 4 5 6 7 8 9 10 11 12) 23)
; (inserare '() 12)
; (inserare '(1) 7)
(defun inserare(l e)
	(inserare_aux l e 1)
)

; lab 1 b)
; spargeLista(l: lista neliniara)
; Transforma o lista neliniara in lista tuturor atomilor continuti in lista luati in ordine inversa
; Returneaza lista liniara obtinuta in urma spargerii listei neliniare l sau NIL daca l e vida
; Model matematic: spargeLista(l1...ln) = 	{ O, daca n = 0 }
;											{ spargeLista(l2...ln) U l1, daca l1 e atom }
;											{ spargeLista(l2...ln) U spargeLista(l1), daca l1 e lista }
; Teste:
; (spargeLista '(1 2 3 4))
; (spargeLista '(1 (2 3) 4)
; (spargeLista '(A (B (C (D (E F G) H) I) J) K))
; (spargeLista '(1))
; (spargeLista '())
(defun spargeLista(l)
	(cond
		; daca l e vida
		((null l) ())
		; daca l1 e atom adaug l1 la finalul rezultatului
		((atom (car l)) (append (spargeLista (cdr l)) (list (car l))))
		; altfel adaug rezultatul spargerii listei l1 la rest
		(t(append (spargeLista (cdr l)) (spargeLista (car l))))
	)
)

; lab 1 c)
; cmmdc(a: intreg, b: intreg)
; Gaseste cel mai mare divizor comun intre doua numere
; Returneaza valoarea cmmdc-ului.
; Model matematic: cmmdc(a, b) = 	{ a, daca b = 0 }
;									{ b, daca a = 0 sau a%b = 0 }
;									{ cmmdc(b, a%b), altfel }
(defun cmmdc(a b)
	(cond
		((equal a 0) b)
		((equal b 0) a)
		((equal (mod a b) 0) b)
		(t(cmmdc b (mod a b)))
	)
)

; cmmdcLista(l: lista neliniara)
; Gaseste cel mai mare divizor comun intre toate numerele continute intr-o lista 
; Returneaza valoarea cmmdc-ului total.
; Model matematic: cmmdcLista(l1..ln) = { 0, daca n = 0 }
;										{ cmmdc(l1, cmmdcLista(l2..ln), daca l1 e numar }
;										{ cmmdc(cmmdcLista(l1), cmmdcLista(l2...ln)), altfel }
; Teste:
; (cmmdcLista '(4 8 12 20 36))
; (cmmdcLista '(4 6 9))
; (cmmdcLista '(20 40 140 25 3))
; (cmmdcLista '(1))
; (cmmdcLista '())
(defun cmmdcLista(l)
	(cond
		; daca l e vida
		((null l) 0)
		; daca l1 e numar il folosesc pentru cmmdc
		((numberp (car l)) (cmmdc (car l) (cmmdcLista (cdr l))))
		; altfel fac cmmdc intre lista l1 si restul listei
		(t (cmmdc (cmmdcLista (car l)) (cmmdcLista (cdr l))))
	)
)

; lab 1 d)
; numarAparitii(l: lista neliniara, e: element)
; Gaseste numarul total de aparitii al elementului e in lista l1
; Returneaza numarul respectiv
; Model matematic: numarAparitii(l1..ln, e) = 	{ 0, daca n = 0}
;												{ 1 + numarAparitii(l2..ln), daca l1 e atom si l1 = e }
;												{ numarAparitii(l2..ln), daca l1 e atom si l1 != e }
;												{ numarAparitii(l1) + numarAparitii(l2..ln), altfel }
; Teste:
; (numarAparitii '(1 2 3 4 2) 2)
; (numarAparitii '(1 (2 3 (1) 1) 4 1) 1)
; (numarAparitii '(1 (2 (3 (4 2)))) 5)
; (numarAparitii '() 2)
(defun numarAparitii(l e)
	(cond
		; daca l e vida
		((null l) 0)
		; daca car l e atom si egal cu e il numaram 
		((and (atom (car l)) (equal (car l) e)) (+ 1 (numarAparitii (cdr l) e)))
		; daca car l e atom inseamna ca nu e egal cu e si trecem mai departe
		((atom (car l)) (numarAparitii (cdr l) e))
		; altfel car l e lista si parcurgem sublista
		(t(+ (numarAparitii (car l) e) (numarAparitii (cdr l) e)))
	)
)
		