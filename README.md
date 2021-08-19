# SM Pixel Art Creator
#### First of all I want to give full credit to wingcomstriker405 for the original design, and for some code on the image proccessing proccessing part. His repo can be found [here](https://github.com/wingcomstriker405/PixelArtBlueprintGenerator).
---
This is mostly a learning experience for me, so any criticism on the code is welcome.
As well as suggestions.

I'm planning on doing a styled implementation in the future, but I still have yet to learn a lot until I can make that.

## Usage
- Download the latest release, or build the project yourself (steps written bellow, not recommended).
- Open the exe file.
- Select the image you want to convert.
- Specify the width and height. (I wouldn't recommend more than around 256x256-512x512, as Scrap Mechanic has a limit on builds)
- Click generate, and wait for it to complete.
- (Re)start your game. As far as I know, for some reason, SM only loads the blueprint when the game starts, if someone knows a solution, or a way in which you don't have to restart the game, please tell me

## Building
I would not recommend you do this at all, but I'm gonna make this section anyways.
I used QT Creator (version 4.15.2) with QT6 and MSVC 2019 to make, and compile this.
Steps:
- Download and compile OpenCV
- Open the project in QT Creator.
- Replace the corresponding paths' in the .pro pointing to the OpenCV libraries.
- Select the build button in the bottom left corner.
- Run MSVC's windeployqt.exe on the compiled exe file.
- Copy the DLLs for the mentioned OpenCV libs next to the exe.
- Done.
It's quite a long process, so as I said, I don't recommend doing it.

## Contact
Discord: diniamo#6987
