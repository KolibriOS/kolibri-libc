 
#!/bin/bash

set -e

IMG=kolibri.img

if [ ! -e "$IMG" ]; then
    echo "File $IMG does not exist"
    exit
fi

mcopy -D o -i $IMG ../sources/libc.obj ::lib/libc.obj
mcopy -D o -i $IMG test ::test

echo -e "Files added!\r"

qemu-system-i386 -m 256 -boot d -fda kolibri.img -usb -usbdevice tablet -enable-kvm -machine type=pc
