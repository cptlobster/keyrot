# keyrot
brainrot "keylogger". checks if input string matches some pre-specified internet meme, displays the associated meme in fullscreen, and plays a sound.

## Dependencies

This package requires `feh` and `sox` to be installed to work properly:

```shell
# ubuntu/debian
sudo apt install feh sox libsox-mp3

# arch
sudo pacman -S feh sox libid3tag libmad twolame
```

If your audio files are in MP3 format, you will need to add the following dependencies:

```shell
# ubuntu/debian
sudo apt install libsox-mp3

# arch
sudo pacman -S libid3tag libmad twolame
```

## Usage
Compile using make:

```shell
make all
```

then run:

```shell
./keyrot
```

At this moment, it only works with input in the specified terminal. Still working on properly grabbing all keyboard input from X11/Wayland.