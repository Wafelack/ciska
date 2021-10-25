(require :asdf)

(defsystem "ciska"
  :description "Screen-oriented modal text editor"
  :version "0.1.0"
  :author "Wafelack <wafelack@riseup.net>"
  :licence "GPL-3.0-or-later"
  :depends-on ("cl-ncurses")
  :components ((:file "package")))
