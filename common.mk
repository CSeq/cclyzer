# For debugging
QUIET       := @


# Unix tools
INSTALL     := install
MKDIR       := mkdir -p
SED         := sed
RM          := rm -f
MV          := mv
M4          := m4
CXX         := g++

# Other tools
factgen.exe := csv-generation


#--------------------
# Directory Tree
#--------------------

DATADIR      = $(LEVEL)/data
OUTDIR       = $(LEVEL)/build
DESTDIR     ?= $(LEVEL)
SAMPLEDIR   ?= $(LEVEL)/etc/sample-data

INSTALL_BIN  = $(DESTDIR)/bin
INSTALL_LIB  = $(DESTDIR)/lib


#---------------------------------------------------
# Template to create destination directory
#
# Usage:
#   $(eval $(call create-destdir, module-name))
#---------------------------------------------------

define create-destdir
$1.outdir = $(OUTDIR)/$1

$$($1.outdir): | $(OUTDIR)
	$(MKDIR) $$@

endef


# Create build root-directory

$(OUTDIR):
	$(MKDIR) $@
