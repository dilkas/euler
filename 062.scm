(define (num->list num)
  (if (< num 10)
      (list num)
      (append (num->list (floor (/ num 10)))
	      (list (- num (* 10 (floor (/ num 10))))))))


(define (list->num list)
  (if (null? list)
      0
      (+ (car list) (* 10 (list->num (cdr list))))))


(define (create-basic-permutation n)
  (list->num (sort (num->list n) <)))


(define (update l)
  (cons (+ 1 (car l))))


(define ht (make-hash-table))


(define (magic cube)
  (let ((basic-permutation (create-basic-permutation cube)))
    (if (hash-table-exists? ht basic-permutation)
	(let ((element (hash-table-ref ht basic-permutation)))
	  (if (< (car element) 4)
	      (hash-table-set! ht basic-permutation (cons
						     (+ 1 (car element))
						     (min cube (cdr element))))
	      (list (min cube (cdr element)))))
	(hash-table-set! ht basic-permutation (cons 1 cube)))))


(define (cycle n)
  (let ((result (magic (expt n 3))))
    (if (list? result)
	result
	(cycle (+ 1 n)))))


(define (euler62)
  (cycle 1))