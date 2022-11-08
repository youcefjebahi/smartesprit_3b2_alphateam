## Process this file with automake to produce Makefile.in

INCLUDES = \
	-DPACKAGE_DATA_DIR=\""$(datadir)"\" \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)/locale"\" \
	@PACKAGE_CFLAGS@

bin_PROGRAMS = smartesprit

smartesprit_SOURCES = \
	main.c \
	support.c support.h \
	interface.c interface.h \
	callbacks.c callbacks.h \
	tree.c tree.h \
	CRUD.c CRUD.h \
	etudiants.c etudiants.h

smartesprit_LDADD = @PACKAGE_LIBS@ $(INTLLIBS)

