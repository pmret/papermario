.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8013A9C8
/* D10C8 8013A9C8 AC800064 */  sw        $zero, 0x64($a0)
/* D10CC 8013A9CC AC800068 */  sw        $zero, 0x68($a0)
/* D10D0 8013A9D0 AC80006C */  sw        $zero, 0x6c($a0)
/* D10D4 8013A9D4 AC800070 */  sw        $zero, 0x70($a0)
/* D10D8 8013A9D8 AC800074 */  sw        $zero, 0x74($a0)
/* D10DC 8013A9DC AC80005C */  sw        $zero, 0x5c($a0)
/* D10E0 8013A9E0 03E00008 */  jr        $ra
/* D10E4 8013A9E4 A4800060 */   sh       $zero, 0x60($a0)
