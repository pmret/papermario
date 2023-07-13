.section .data

.word 0x80371240       /* PI BSB Domain 1 register */
.word 0x0000000F       /* Clockrate setting */
.word bootproc         /* Entrypoint address */
.word 0x00001444       /* Revision */
.word 0x00000000       /* Checksum 1 */
.word 0x00000000       /* Checksum 2 */
.word 0x00000000       /* Unknown 1 */
.word 0x00000000       /* Unknown 2 */
.ascii "SPLAT TEST ROM      " /* Internal name */
.word 0x00000000       /* Unknown 3 */
.word 0x0000004E       /* Cartridge */
.ascii "SP"            /* Cartridge ID */
.ascii "E"             /* Country code */
.byte 0x00             /* Version */
