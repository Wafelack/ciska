CCL := sbcl
OUT := ciska
CCOMMAND := "(sb-ext:save-lisp-and-die 										\
				\"$(OUT)\"													\
				:toplevel 'main 											\
				:executable T												\
				:compression (if (member :sb-core-compression *features*) 	\
					T			 											\
					nil))"

all:
	$(CCL) --load main.lisp --eval $(CCOMMAND)

.PHONY: clean
clean:
	rm -f $(OUT)
