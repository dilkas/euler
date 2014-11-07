(define (more-digits? n d)
  (let ((bn (< n 10)) (bd (< d 10)))
    (cond ((not (or bn bd))
           (more-digits? (inexact->exact (/ n 10)) (inexact->exact (/ d 10))))
          ((and bn bd) #f)
          (else bd))))


(define (magic i)
  (cond ((= i 1) (values 3 2 0))
        ((= i 2) (values 7 5 0))
        (else
         (call-with-values (lambda () (magic (- i 1)))
           (lambda (ni1 di1 ci1)
             (let ((ni (+ ni1 (* 2 di1))) (di (+ ni1 di1)))
               (values ni di (+ ci1 (if (more-digits? ni di) 1 0)))))))))


(define (euler57)
  (call-with-values
      (lambda () (magic 1000))
    (lambda (n d c) c)))