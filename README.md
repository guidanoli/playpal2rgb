# PLAYPAL to RGB converter

The purpose of this tool is to convert raw [PLAYPAL](https://doomwiki.org/wiki/PLAYPAL) files into raw RGB files.
These raw RGB files can then be converted to PNG files with tools like [ImageMagick](https://imagemagick.org/).

## Compilation

In order to build the `playpal2rgb` program, please run the following command.

```sh
make
```

## Usage

Having a raw PLAYPAL file named `framebuffer.raw`, we can convert it into a `framebuffer.png` file in two steps.
First, we convert the PLAYPAL file into a raw RGB file using the `playpal2rgb` tool.
Second, we convert the raw RGB file into a PNG file using the `convert` tool from ImageMagick.
Here, we assume the image is 320 pixels wide and 200 pixels high.

```sh
./playpal2rgb < framebuffer.raw > framebuffer.rgb
convert -depth 8 -size 320x200 framebuffer.rgb framebuffer.png
```

## Example

This repository contains an example PLAYPAL file named `framebuffer.raw`, so that you can test the above pipeline.
The end result should look like the one below.

![Freedoom](./framebuffer.png)
