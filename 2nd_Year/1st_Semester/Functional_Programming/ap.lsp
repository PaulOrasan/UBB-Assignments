(defun verificare(arb nod nivel)
	(cond
		((null arb) 0)
		((equal (car arb) nod) 
			(cond
				((equal (mod nivel 2) 0) 1)
				(t 0)
			)
		)
		(t (apply #'+ (mapcar (lambda(v) (verificare v nod (+ 1 nivel))) (cdr arb))))
	)
)

(defun verificareNodNivelPar(arb nod)
	(cond 
		((equal (verificare arb nod 0) 1) t)
		(t nil)
	)
)

(defun eliminaElementAux (el arb)
    (cond
        ((null arb) (list nil))
        ((listp arb) (list (eliminaElement el arb)))
        ((eql arb el) nil)
        (t (list arb))
    )
)

(defun eliminaElement (el arb)
    (mapcan (lambda (subarb) (eliminaElementAux el subarb)) arb)
)

(defun caleaDeLaRadacina(arb nod) 
    (cond 
        ((null arb) nil)
        ((eq (car arb) nod) (list nod))
        (t 
        (mapcan (lambda (subarb) (
                     (lambda (p) (cond (p (cons (car arb) p))))
                        (caleaDeLaRadacina subarb nod)
                ))
                    (cdr arb)
                )
        )
    )
)
