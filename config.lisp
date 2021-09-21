(load "motions.lisp")
(load "operators.lisp")
(load "keybindings.lisp")

(defclass editor-config ()
  ((motions
     :initform (default-motions)
     :accessor motions
     :documentation "The list of MOTIONs (i.e. moves and selections) enabled by this config.")
   (operators
     :initform (default-operators)
     :accessor operators
     :documentation "The list of OPERATORs (e.g. delete) enabled by this config.")
   (keybindings
     :initform (default-keybindings)
     :accessor keybindings
     :documentation "The list of KEYBINDINGs enabled by this config.")))
