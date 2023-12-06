#
# ENSICAEN
# 6 Boulevard Maréchal Juin
# F-14050 Caen Cedex
#
# Examples from the course "Software development tools"
# Exemplier du cours "Outils de développement logiciel" (ODL)
#
# Chapter "The make command" / Chapitre "Commande make"
#
# Copyright (C) 1995-2023 Alain Lebret (alain.lebret@ensicaen.fr)
#

#
# A root Makefile to manage sub-projects
#

# Names of the sub-projects
PROJECTS = project1 project2 project3

# A function to execute a command in each sub-project
define do_for_each_project
	@for dir in $(PROJECTS); do \
		echo "Execution of '$1' in $$dir"; \
		$(MAKE) -C $$dir $1; \
	done
endef

# Default targets
.PHONY: all tests clean distclean

all:
	$(call do_for_each_project,all)

tests:
	$(call do_for_each_project,tests)

clean:
	$(call do_for_each_project,clean)

distclean:
	$(call do_for_each_project,distclean)
