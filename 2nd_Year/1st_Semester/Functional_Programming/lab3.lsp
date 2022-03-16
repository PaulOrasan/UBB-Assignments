; 4. Sa se construiasca o functie care intoarce suma atomilor numerici dintr-o lista, 
; de la orice nivel.
; suma(l : lista eterogena)
; Calculeaza suma atomilor numerici indiferent de nivelul in care se afla in lista la
; Model  matematic:
; suma(l) = { l, daca l e numar }
;		  = { 0, daca l e atom si nu e numar }
;		  = { Σ suma(lk), k = 1,n daca l = l1l2...ln }
; Teste:
; (suma '(1 (a 2 (c 0 3) (d 4) 5))) = 15
; (suma '()) = 0
; (suma '(a b c 2 d)) = 2
; (suma '(a (b (c (+ d) e (f)) g) h (i (j k)))) = 0
(defun suma(l)
	(cond
		((numberp l) l)
		((atom l) 0)
		(t (apply #'+ (mapcar #'suma l)))
	)
)
