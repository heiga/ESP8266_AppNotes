#!/bin/sh
#
# This file was automatically generated.
#
# It can be overwritten by nios2-flash-programmer-generate or nios2-flash-programmer-gui.
#

#
# Converting SOF File: C:\WAT\Quartus\output_files\ECE492_g7_2017w_WAT.sof to: "..\flash/ECE492_g7_2017w_WAT_epcs_flash_controller_0.flash"
#
sof2flash --input="C:/WAT/Quartus/output_files/ECE492_g7_2017w_WAT.sof" --output="../flash/ECE492_g7_2017w_WAT_epcs_flash_controller_0.flash" --epcs 

#
# Programming File: "..\flash/ECE492_g7_2017w_WAT_epcs_flash_controller_0.flash" To Device: epcs_flash_controller_0
#
nios2-flash-programmer "../flash/ECE492_g7_2017w_WAT_epcs_flash_controller_0.flash" --base=0x1009000 --epcs --sidp=0x100A0E0 --id=0x0 --timestamp=1489283459 --device=1 --instance=0 '--cable=USB-Blaster on localhost [USB-0]' --program --erase-all 

#
# Converting ELF File: C:\WAT\Quartus\software\WAT_TEST\WAT_TEST.elf to: "..\flash/WAT_TEST_epcs_flash_controller_0.flash"
#
elf2flash --input="C:/WAT/Quartus/software/WAT_TEST/WAT_TEST.elf" --output="../flash/WAT_TEST_epcs_flash_controller_0.flash" --epcs --after="../flash/ECE492_g7_2017w_WAT_epcs_flash_controller_0.flash" 

#
# Programming File: "..\flash/WAT_TEST_epcs_flash_controller_0.flash" To Device: epcs_flash_controller_0
#
nios2-flash-programmer "../flash/WAT_TEST_epcs_flash_controller_0.flash" --base=0x1009000 --epcs --sidp=0x100A0E0 --id=0x0 --timestamp=1489283459 --device=1 --instance=0 '--cable=USB-Blaster on localhost [USB-0]' --program 

