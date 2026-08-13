# Xnote

Xnote is a not-so-advanced editor designed for simplicity, usability, and is beautiful.

## Features

- Simple terminal-based text editing
- Keyboard-driven controls
- Save files with `Ctrl+S`
- Quit with `Ctrl+X`
- Create new lines
- Delete characters
- Insert tabs
- Navigate using the arrow keys
- Basic syntax highlighting
  - Python
  - Ruby
  - C
  - C++
- Runs directly in the terminal
- Supports multiple Linux distributions

## Controls

| Key | Action |
|---|---|
| `Ctrl+S` | Save |
| `Ctrl+X` | Quit |
| `Ctrl+R` | Open Commands |
| `↑` `↓` `←` `→` | Move cursor |
| `Enter` | Create a new line |
| `Backspace` | Delete |
| `Tab` | Insert 4 spaces |

## Packages

Xnote provides packages for multiple Linux distributions.

### Debian / Ubuntu

```bash
sudo dpkg -i xnote_1.0.0_amd64.deb
```

### Fedora / Red Hat

```bash
sudo dnf install ./xnote-1.0.0-1.x86_64.rpm
```

### Arch Linux

```bash
sudo pacman -U ./xnote-1.0.0-1-x86_64.pkg.tar.zst
```

### AppImage

Make the AppImage executable:

```bash
chmod +x Xnote-1.0.0-x86_64.AppImage
```

Run it:

```bash
./Xnote-1.0.0-x86_64.AppImage
```

## Building From Source

### Requirements

- GCC
- Make
- ncurses development libraries
- Git

Clone the repository:

```bash
git clone <YOUR-REPOSITORY-URL>
cd Xnote
```

Build Xnote:

```bash
make
```

Run Xnote:

```bash
./xnote <file>
```

For example:

```bash
./xnote randomtestfile.txt
```

## Tested Platforms

Xnote is currently tested on:

- Ubuntu / Debian
- Fedora / Red Hat
- Arch Linux
- AppImage (Universally)

## Development

Xnote is written in C and uses `ncurses` for its terminal interface.

The project is intentionally kept simple and lightweight.

## Project Structure

```text
Xnote/
├── editor.c
├── editor.h
├── file.c
├── file.h
├── main.c
├── screen.c
├── screen.h
├── Makefile
├── README.md
└── assets/
    └── Xnote-logo.png
```

## License

Xnote is licensed under the GPL-3.0 license.

See `LICENSE` for the full license text.

## About

Xnote is a lightweight terminal text editor focused on keeping things simple.

No huge interface.

No unnecessary complexity.

Just:

```text
Open -> Edit -> Save -> Done.
```

---

Xnote is written in C and built with ncurses.
