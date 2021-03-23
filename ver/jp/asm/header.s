.section .data, "a"

.word 0x80371240       /* PI BSB Domain 1 register */
.word 0x0000000F       /* Clockrate setting */
.word 0x80125C00       /* Entrypoint address */
.word 0x0000144B       /* Revision */
.word 0x3BA7CDDC       /* Checksum 1 */
.word 0x464E52A0       /* Checksum 2 */
.word 0x00000000       /* Unknown 1 */
.word 0x00000000       /* Unknown 2 */
.ascii "MARIO STORY         " /* Internal name */
.word 0x00000000       /* Unknown 3 */
.word 0x0000004E       /* Cartridge */
.ascii "MQ"            /* Cartridge ID */
.ascii "J"             /* Country code */
.byte 0x00             /* Version */
