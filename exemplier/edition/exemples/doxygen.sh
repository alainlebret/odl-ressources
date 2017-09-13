doxygen -g
emacs Doxyfile
mv Doxyfile maconfig
doxygen maconfig
firefox index.html &