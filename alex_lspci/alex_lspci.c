#include "alex_lspci.h"
#include "stdio.h"
//#include "lib/pci.h"
#include <linux/pci.h>
/*

 As suggested, the user can look at the PCI device list and the devices' configuration registers by reading /proc/bus/pci/devices and /proc/bus/pci/*//*. The former is a text file with (hexadecimal) device information, and the latter are binary files that report a snapshot of the configuration registers of each device, one file per device. 

*/

/*
Urls:

https://www.ibm.com/developerworks/ru/library/l-linux_kernel_50/
http://www.xml.com/ldd/chapter/book/ch15.html#t1
https://www.ibm.com/developerworks/ru/library/l-linux_kernel_51/

*/

int main(int argc, char const *argv[])
{
struct pci_dev *dev = NULL;
    int found;

    if (!pci_present())
    return -ENODEV;

    for (found=0; found < JAIL_MAX_DEV;) {
        dev = pci_find_device(JAIL_VENDOR, JAIL_ID, dev);
        if (!dev) /* no more devices are there */
            break;
        /* do device-specific actions and count the device */
        found += jail_init_one(dev);
    }
  return 0;
}