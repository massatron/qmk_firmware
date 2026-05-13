# xunilpad 

### Arduino Pro Micro Pinout
| rows        | 0   | 1   | 2   | 3   | 4   |
| ----------- | --- | --- | --- | --- | --- |
| arduino pin | 5   | 6   | 7   | 8   | 9   |
| qmk pin     | C6  | D7  | E6  | B4  | B5  |

| columns     | 0   | 1   | 2   | 3   |
| ----------- | --- | --- | --- | --- |
| arduino pin | A3  | A2  | A1  | A0  |
| qmk pin     | F4  | F5  | F6  | F7  |


Make example for this keyboard (after setting up your build environment):

    make handwired/xunilpad:default

Bootmagic is enabled.  Press the key at (0,0) while plugging the keyboard in to jump to bootloader. This is numlock in the default keymap.

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

