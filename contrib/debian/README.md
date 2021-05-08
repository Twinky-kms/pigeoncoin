
Debian
====================
This directory contains files used to package pigeoncoind/pigeoncoin-qt
for Debian-based Linux systems. If you compile pigeoncoind/pigeoncoin-qt yourself, there are some useful files here.

## pigeoncoin: URI support ##


pigeoncoin-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install pigeoncoin-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your pigeoncoin-qt binary to `/usr/bin`
and the `../../share/pixmaps/pigeoncoin128.png` to `/usr/share/pixmaps`

pigeoncoin-qt.protocol (KDE)

