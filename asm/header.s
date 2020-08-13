.section .header, "a"
.byte  0x80, 0x37, 0x12, 0x40 # PI BSD Domain 1 register
.word  0x0000000F # clock rate setting
.word  0x80125C00 # entry point
.word  0x0000144B # release
.word  0x65EEE53A # checksum1
.word  0xED7D733C # checksum2
.word  0x00000000 # unknown
.word  0x00000000 # unknown
.ascii "PAPER MARIO         " # ROM name: 20 bytes
.word  0x00000000 # unknown
.word  0x0000004E # cartridge
.ascii "MQ"       # cartridge ID
.ascii "E"        # country
.byte  0x00       # version

