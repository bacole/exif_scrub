# Exif Scrubber

Exif Scrubber is a program for removing exif metadat from JPEG images.

## Installation

```bash
git clone https://github.com/bacole/exif_scrub
cd exif_scrub
make
```

## Usage

A JPEG image file or a directory containing JPEG images that the user desires to have exif metadata removed from should be passed as the first argument. There are several options that can be set.

```
-bu backs up target images
-o [PATH] gives the program a path or directory to write the scrubbed images to, does not modify the original images in this case
-v prints information about the number of changes made to each image
```