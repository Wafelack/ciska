(ql:quickload :cl-ncurses)

(load "utils.lisp")
(load "editor.lisp")
(load "config.lisp")

(defun process-char (ch)
  "Get a character and process it into editor memory."
  (cond
    ((isdigit ch) (let ((digit (- ch 48)))
                    (setf (count-reg *editor*) (+ (* 10 (count-reg *editor*)) digit))))
    ((= (char-code #\q) ch)
     (cl-ncurses:endwin)
     (format t "count-reg : ~D ; keys-reg : '~a'~%" (count-reg *editor*) (keys-reg *editor*))
     (exit))
    (T (add-key *editor* (character-name ch)))))

(defun main ()
  (defvar *editor* (init-editor (make-instance 'editor-config)))

  (loop
    (process-char (cl-ncurses:getch))
    (cl-ncurses:refresh)))
