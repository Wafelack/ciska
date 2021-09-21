(defclass buffer ()
  ((name
     :initarg :name
     :initform "*scratch*"
     :accessor name
     :documentation "The buffer name, may not be unique.")
   (file
     :initform nil
     :accessor file
     :documentation "The file the buffer is linked to.")
   (chidx
     :initform 0
     :accessor chidx
     :documentation "The index of the character under the cursor.")
   (content
     :initform (make-array 0 :fill-pointer 0)
     :accessor content
     :documentation "The buffer content bytes.")))

(defun set-file (buffer fname)
  "Set the file the buffer is linked to and load its content."
  (setf (file buffer) fname)
  (if (probe-file fname)
    (with-open-file (f fname :element-type '(unsigned-byte 8))
      (loop for b = (read-byte f)
            until (byte= b +null+) do (vector-push (content buffer) b)))))
