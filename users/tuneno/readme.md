# Cryptor1 Userspace

### Keyboards
- OLKB Planck Rev. 6
    - MT3 Godspeed, Lubed YOK Polar Panda Switches
    - Keymap [here](https://github.com/Cryptor1/qmk_firmware/tree/master/keyboards/planck/keymaps/cryptor1)
- OLKB Preonic Rev. 3
    - SA Carbon, Lubed Gateron Yellows
    - Keymap [here](https://github.com/Cryptor1/qmk_firmware/tree/master/keyboards/preonic/keymaps/cryptor1)
- Keeb.io Iris Rev. 4
    - MT3 dev/tty, Lubed MX Silent Blacks
    - Keymap [here](https://github.com/Cryptor1/qmk_firmware/tree/master/keyboards/keebio/iris/keymaps/cryptor1)

### Files

The goal was to build a common userspace that can house keymap 'chunks' that can be maintained and flashed to various my keyboards (above). This userspace contains separate files for:
- Shared keymap 'chunks' that can be maintained in this userspace and flashed to multiple keyboards
    - Goal is to have the same keymap across 3 different, ortholinear keyboards
- Various macros
- Encoder functions:
    - single encoder functions for Planck and Preonic
    - dual encoder functions for Iris
- Tap Dance functions
- Shared config, rules.mk, and layers
