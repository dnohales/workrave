# Process this file with automake to produce Makefile.in
#
# Copyright (C) 2002, 2003 Rob Caelers & Raymond Penners
#
# $Id$
#

MAINTAINERCLEANFILES =	Makefile.in

noinst_LIBRARIES = 	libworkrave-frontend-common.a

SUBDIRS = 		gnome win32

libworkrave_frontend_common_a_SOURCES = \
			Text.cc \
			SoundPlayer.cc \
			System.cc

EXTRA_DIST = 		$(wildcard *.hh) $(wildcard *.cc) \
			$(wildcard *.c) $(wildcard *.h)  $(wildcard *.icc)

libworkrave_frontend_common_a_CXXFLAGS = \
			-DWORKRAVE_DATADIR="\"${pkgdatadir}\"" \
			-D_XOPEN_SOURCE=600 \
			-W -I. -I../include -Iwin32 -Ignome \
			@WR_COMMON_CFLAGS@ \
			@WR_BACKEND_INCLUDES@ @GNOMEUI_CFLAGS@ @GTK_CFLAGS@ \
			@GLIB_CFLAGS@ \
			-I$(top_srcdir)/src/shared/win32/harpoon/