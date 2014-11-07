(define (toPentagonal n) (/ (* n (- (* 3 n) 1)) 2))
(define (isPentagonal? p)
  (let ((s (sqrt (+ (* 24 p) 1))))
    (and (integer? s) (= (modulo (inexact->exact s) 6) 5))))
(define (magic j k)
  (let* ((pj (toPentagonal j)) (pk (toPentagonal k)) (d (- pj pk)))
       (if (and (isPentagonal? d) (isPentagonal? (+ pj pk))) d
           (if (< k j) (magic j (+ k 1)) (magic (+ j 1) 1)))))
(define (euler44) (magic 1 1))