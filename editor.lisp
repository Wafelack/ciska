(load "utils.lisp")
(load "config.lisp")
(load "buffer.lisp")

(defclass editor ()
  ((config
     :initarg :config
     :initform (make-instance 'editor-config)
     :accessor config
     :documentation "The configuration to use with this editor instance.")
   (x
     :initform 0
     :accessor x
     :documentation "Cursor X coordinate.")
   (y
     :initform 0
     :accessor y
     :documentation "Cursor Y coordinate.")
   (mode
     :initform 'normal
     :accessor mode
     :documentation "The currently enabled mode for the editor.")
   (keys-reg
     :initform ""
     :accessor keys-reg
     :documentation "The keys that have been typed and that are not yet used.")
   (op-reg
     :initform NIL
     :accessor op-reg
     :documentation "The current operator.")
   (count-reg
     :initform 0
     :accessor count-reg
     :documentation "Accumulator for the numbers typed, used for movement.")
   (buffers
     :initform (make-array 1 :fill-pointer 0 :initial-element (make-instance 'buffer))
     :accessor buffer
     :documentation "Editor buffers.")
   (current-buffer
     :initform 0
     :accessor current-buffer
     :documentation "Current buffer index.")))

(defun move-cursor (editor newX newY)
  "Move the editor cursor to (newX; newY)."
  (setf (x editor) newX)
  (setf (y editor) newY)
  (cl-ncurses:move newY newX))

(defun new-buffer (editor)
  "Create a new buffer in the editor."
  (vector-push (buffers editor) (make-instance 'buffer)))

(defun init-editor (config)
  "Initialize the screen and create a new editor."
  (init-screen)
  (make-instance 'editor :config config))

(defun add-key (editor key)
  "Push a key on the KEYS-REG."
  (setf (keys-reg editor) 
        (concatenate 'string 
                     (keys-reg editor) 
                     key)))

(defun kill-editor ()
  "Exit the program and reinitialize the screen."
  (cl-ncurses:endwin)
  (exit))
