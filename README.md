# srv_spam
A simple example of a named pipe placed in the /srv directory

For Plan9 and 9Front

Run the command with 1 argument.
It will create a pipe, place one end in /srv/spam,
and when /srv/spam is read, it will endlessly loop 
the string for the arguement it was ran with.

To stop it, delete the /srv/spam file.

Inspired by "man 3 srv"

Have Fun!
