# Text_editor
Text editor

# Description
This very simple text editor lets you create, write and save any type of file.
It does not provide auto completion or color coding. You can't use it to re-open
a file but a file created with this text editor can be opened with any other editor.
This is a work in progress, so any changes will be updated in this repository.

# Usage
Compile it with the following line:
gcc -Wall -pedantic -Werror -Wextra editor.h editor.c -o text_editor -lncurses

Run it with the following line:
./text_editor <filename>

# Bugs
As previously mentioned, this text editor cannot re-open a file to make changes.
Another issue is that the exit functionality is implemented using the escape ('\e')
key. This may not work properly in every system. If you're able to find any other
bugs feel free to contact me.

# Author
* [Angel Reyes](angel.reyes.segarra@gmail.com)
* [Github](https://github.com/areyes-hub/text_editor)
