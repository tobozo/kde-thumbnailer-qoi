# kde-thumbnailer-qoi

kde-thumbnailer-qoi is a KDE thumbnailer plugin for [QOI](https://github.com/phoboslab/qoi) image files (e.g. Dolphin)

<img src="https://user-images.githubusercontent.com/1893754/152891089-51517b9c-fca1-4d3b-a6ff-32728fbf1e13.png" />


## Prerequisites

- Plasma 5.x
- KDE 5.x
- Qt 5.x


## Building


 - Debian/Ubuntu dependencies: `build-essential extra-cmake-modules gettext libgsf-1-dev libkf5crash-dev kinit-dev libkf5globalaccel-dev libkf5kio-dev libkf5archive-dev libkf5config-dev libkdecorations2-dev libqt5x11extras5-dev qtdeclarative5-dev libkf5guiaddons-dev libkf5configwidgets-dev libkf5windowsystem-dev libkf5coreaddons-dev`

 - Arch dependencies: `cmake extra-cmake-modules libgsf`

```sh
    git clone https://github.com/tobozo/kde-thumbnailer-qoi
    cd kde-thumbnailer-qoi
    git submodule update --init --recursive
    mkdir build
    cd build
    cmake ..
    make
    sudo make install
```

Variant for Ubuntu:

```sh
    cmake ../ -DXDG_DATA_DIRS=/usr/local/share -DXDG_CONFIG_DIRS=/usr/local/etc/xdg -DQT_PLUGIN_PATH=/usr/local/lib/x86_64-linux-gnu/plugins -DQML2_IMPORT_PATH=/usr/local/lib/x86_64-linux-gnu/qml
```

## Troubleshooting:

Some check points if the thumbnail isn't displayed:

- `image/x-qoi` should be present in /etc/mime.types
- `image/x-qoi` should be listed in KDE file association
- The `Quite OK Image Format` plugin is present and enabled in Dolphin


## Credits

- https://github.com/phoboslab/qoi
