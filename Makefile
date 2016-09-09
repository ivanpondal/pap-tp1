ENTREGABLE=pap-tp1.tar.gz
FILES=latex/informe.pdf src

.PHONY: all clean

all: $(ENTREGABLE)

clean:
	rm -f $(ENTREGABLE)
	$(MAKE) clean -C latex
	$(MAKE) clean -C src

$(ENTREGABLE):
	$(MAKE) -C latex
	tar -cvzf $(ENTREGABLE) $(FILES)
