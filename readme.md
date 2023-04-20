QMK map for Kinesis Essential modded to use Raspberry Pi Pico.  The thumb pad traces are cut and rewired in order to have a simple 12x6 grid.  I am currently not using the membrane function keys as I have a layer that I am more comfortable using.

There two additional rows for adding additional keys eventually.

Most of the configuration is in the info.json at the root level.

To build, clone into an existing qmk branch, and copy into  qmk_firmware/keyboards/handwired/frankinesis.
qmk compile -kb handwired/frankinesis -km default
then copy to the keyboard after plugging it in while pressing the bootsel button on the pico.  

After the first install, because of Boot Magic, you can press the + button while plugging in the keyboard cable to get into boot mode.


