(defun iscntrl (ch)
  "Check if character code corresponds to a control character."
  (< ch 32))

(defun isdigit (ch)
  "Check if the character code corresponds to a digit."
  (and (> ch 47) (< ch 58)))

(defun controlize (ch)
  "Make a character a control character."
  (logand ch 31))

(defun character-name (ch)
  "Get the editorish name of a character."
  (cond
    ((= 10 ch) "RET")
    ((= 27 ch) "ESC")
    ((= 32 ch) "SPC")
    ((iscntrl ch) (format NIL "^~C" (code-char (+ 64 ch))))
    (T (format NIL "~C" (code-char ch)))))

(defun init-screen ()
  "Initialize the curses interface."
  (cl-ncurses:initscr)
  (cl-ncurses:cbreak)
  (cl-ncurses:noecho))
