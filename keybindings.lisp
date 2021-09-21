(defclass keybinding ()
  ((mode
     :initarg :mode
     :initform 'normal
     :accessor mode
     :documentation "The mode in which the keybinding is valid.")
   (text
     :initarg :text
     :initform ""
     :accessor text
     :documentation "The combination of keys for the keybinding.")
   (binding
     :initarg :binding
     :initform NIL
     :accessor binding
     :documentation "The LISP code to evaluate if the keybinding is triggered.")))

(defun default-keybindings ()
  "The defaults keybindings (i.e. keys bound to a function)."
  NIL)
