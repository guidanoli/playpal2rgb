# PLAYPAL to RGB converter

![Freedoom](./framebuffer.png)

The purpose of this tool is to convert raw [PLAYPAL](https://doomwiki.org/wiki/PLAYPAL) files into raw RGB files.
These raw RGB files can then be converted into PNG files with tools like [ImageMagick](https://imagemagick.org/).

## Compilation

```sh
make
```

## Usage

```sh
./playpal2rgb < framebuffer.raw > framebuffer.rgb
convert -depth 8 -size 320x200 framebuffer.rgb framebuffer.png
```
