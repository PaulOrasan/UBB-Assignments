(defun suma(l)
 ; forma COND – forma condițională: permite ramificarea prelucrărilor
 (cond
 ((null l) 0)
 ; NUMBERP – returnează T dacă argumentul e număr
 ((numberp (car l)) (+ (car l) (suma (cdr l))))
 (t (suma (cdr l)))
 )
)