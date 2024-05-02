# PLAYPAL to RGB converter

![Freedoom](./framebuffer.png)

The purpose of this tool is to convert raw [PLAYPAL](https://doomwiki.org/wiki/PLAYPAL) files into raw RGB files.
These raw RGB files can then be converted into PNG files with tools like [ImageMagick](https://imagemagick.org/).

## Compilation

```sh
make
```

## Usage

The tool takes the path of a palette file as argument, reads the image in PLAYPAL format from `stdin` and writes out the image in RGB format to `stdout`.
This output can be piped to the `convert` tool from ImageMagick to produce an output file in PNG format.

```sh
./playpal2rgb palette.raw < framebuffer.raw | convert -depth 8 -size 320x200 rgb:- framebuffer.png
```

## Input format

The input to the `playpal2rgb` tool should be in PLAYPAL format, where each byte encodes the index of the color in the PLAYPAL table.
The PLAYPAL table should be provided in a palette file, which also has a specific format.

## Output format

The output of the `playpal2rgb` tool is in RGB format, where...

- R is 8 bits for the red component;
- G is 8 bits for the green component;
- B is 8 bits for the blue component.

... and it has the following memory layout.

```
+------------+-----+-------+-------+
| byte index | 3*n | 3*n+1 | 3*n+2 |
+------------+-----+-------+-------+
| data       | R   | G     | B     |
+------------+-----+-------+-------+
```

## Palette format

The palette is assumed to be written in RBGX format, where...

- R is 8 bits for the red component;
- G is 8 bits for the green component;
- B is 8 bits for the blue component;
- X is 8 bits for padding (unused).

The palette should be written to a binary file of 1024 bytes with the following memory layout.

```
+------------+-----+-------+-------+-------+
| byte index | 4*n | 4*n+1 | 4*n+2 | 4*n+3 |
+------------+-----+-------+-------+-------+
| data       | R   | G     | B     | X     |
+------------+-----+-------+-------+-------+
```
