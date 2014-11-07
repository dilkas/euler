;; (define (magic n d)
;;   (if (> d 1)
;;       (let ((a (/ n d)))
;;         (+ (if (and (> a (/ 1 3)) (< a (/ 1 2))) 1 0)
;;            (if (> n 1) (magic (- n 1) d) (magic n (- d 1)))))))

(define (magic n d)
  (let ((f (/ n d)))
    (cond
     ((= d 1234) 0)
     ((>= f (/ 1 2)) (magic 1 (+ 1 d)))
     ((> f (/ 1 3)) (+ 1 (magic (+ 1 n) d)))
     (else (magic (+ 1 n) d)))))


(define (euler73)
  (magic 1 2))