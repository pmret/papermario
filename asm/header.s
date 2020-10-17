.section .header, "a"

.word 0x80371240 /* PI PSD Domain 1 register */
.word 0x0000000F /* Clockrate setting */
.word 0x80125C00 /* Entrypoint address */
.word 0x0000144B /* Revision */
.word 0x65EEE53A /* Checksum 1 */
.word 0xED7D733C /* Checksum 2 */
.word 0x00000000 /* Unknown 1 */
.word 0x00000000 /* Unknown 2 */
.ascii "PAPER MARIO         " /* Internal ROM name */
.word 0x00000000 /* Unknown 3 */
.word 0x0000004E /* Cartridge */
.ascii "MQ" /* Cartridge ID */
.ascii "E" /* Country code */
.byte 00 /* Version */
