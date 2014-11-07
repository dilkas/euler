(define following (make-hash-table))


(define starts (make-hash-table))


(define (setup-starts)
  (let ((a (hash-table-set! starts 1 '(1035 45)))
	(b (hash-table-set! starts 2 '(1024 32)))
	(c (hash-table-set! starts 3 '(1001 26)))
	(d (hash-table-set! starts 4 '(1035 23)))
	(e (hash-table-set! starts 5 '(1071 21)))
	(f (hash-table-set! starts 6 '(1045 19))))
    1))


(define (generate-numbers-of-type p n type)
  (if (< p 10000)
      (cons (cons p (list type)) (generate-numbers-of-type (+ p (* type n) 1) (+ n 1) type))
      '()))


(define (generate-all-numbers type)
  (if (< type 7)
      (let ((start (hash-table-ref starts type)))
	(append (generate-numbers-of-type (car start) (cadr start) type)
		(generate-all-numbers (+ type 1))))
      '()))


(define (add-following a b)
  (if (and (equal? (remainder (car a) 100) (/ (car b) 100))
	   (not (equal? (cdr a) (cdr b))))
      (if (hash-table-exists? following a)
	  (hash-table-set! following a (cons b (hash-table-ref following a)))
	  (hash-table-set! following a (list b)))
      '()))


(define (add-to-following e l t)
  (if (null? l)
      '()
      (add-to-following e (cdr l) (add-following e (car l)))))


(define (different-types? a b)
  (not (equal? (cdr a) (cdr b))))


(define (cycle? a b)
  (equal? (remainder (car a) 100) (/ (car b) 100)))


(define (all-types-different? e l)
  (if (null? l)
      #t
      (and (different-types? e (car l))
	   (all-types-different? e (cdr l)))))


(define (acceptable e l)
  (and (cycle? e (car l))
       (all-types-different e l)))


(define (magic l f t)
  (if (null? l)
      '()
      (magic (cdr l) f (add-to-following (car l) f t))))


(define (even-more-magic l p)
  (if (null? l)
      l
      (let ((s (car l)) (e (car p)))
	(if (acceptable e s p)
	    (even-more-magic (hash-table-ref following s) (cons s p))
	    (even-more-magic (cdr l) p)))))


(define (more-magic l t)
  (let* ((e (car l))
	 (r (even-more-magic (hash-table-ref following e) (list e))))
    (if (null? r)
	(more-magic (cdr l) t)
	r))


(define (euler61)
  (let ((numbers (generate-all-numbers (setup-starts))))
    (more-magic (hash-table-keys following) (magic numbers numbers '()))))