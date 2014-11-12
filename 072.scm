; general format: (b i l)
; b - boolean value showing whether the list has been changed
; i - the length of the list
; l - the actual list of ordered fractions
; l = ((n1 d1) (n2 d2) ...)
; ni - numerator
; di - denominator

; maximum denominator
(define max-d 1000000)

; add a new fraction as the second element in the list and recurse
(define (add-new-fraction l)
  ; if the list has less than 2 elements, return it unchanged
  (if (or (null? (cddr l)) (null? (cddadr l)))
      '((car l) (cdar l) (cddar l))
      ; define the new numerator, denominator and recursively call itself on the rest of the list (without the first element)
      (let ((n (+ (cddaaar l) (cddadaar l)))
	    (d (+ (cddaadar l) (cddadadar l)))
	    (tail (add-new-fraction '((car l) (- (cdar l) 1) (cddadr l)))))
	; If the denominator becomes too big, returned the concatinated list, otherwise insert the new element
	(if (> d max-d)
	    '((car tail) (+ (cdar tail) 2) (cons (cddaar l) (cons (cddadar l) (cddar tail))))
	    '(#t (+ (cdar tail) 3) (cons (cddaar l) (cons (cddadar l) (cons (cddaddar l) (cddar tail)))))))))

(define (run l)
  (let ((new-l (add-new-fraction l)))
    ; if there were changes made, call again, otherwise return
    (if (car new-l)
	(run new-l)
	'())))

(define (euler72)
  (cdar (run '((0 1) (1 1)))))

; possible test case
;(add-new-fraction '(#f 2 '((0 1) (1 1))))
