.section .data

.word 0x80371240       /* PI BSB Domain 1 register */
.word 0x0000000F       /* Clockrate setting */
.word 0x80025C00       /* Entrypoint address */
.word 0x0000144C       /* Revision */
.word 0x00000000       /* Checksum 1 */
.word 0x00000000       /* Checksum 2 */
.word 0x00000000       /* Unknown 1 */
.word 0x00000000       /* Unknown 2 */
.ascii "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0" /* Internal name */
.word 0x00000000       /* Unknown 3 */
.word 0x00000000       /* Cartridge */
.ascii "\0\0"          /* Cartridge ID */
.ascii "\0"            /* Country code */
.byte 0x00             /* Version */
