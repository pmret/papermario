.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800334C0
/* E8C0 800334C0 3C058007 */  lui       $a1, %hi(gGameStatusPtr)
/* E8C4 800334C4 8CA5417C */  lw        $a1, %lo(gGameStatusPtr)($a1)
/* E8C8 800334C8 240600FF */  addiu     $a2, $zero, 0xff
/* E8CC 800334CC 84A200B6 */  lh        $v0, 0xb6($a1)
/* E8D0 800334D0 94A300B6 */  lhu       $v1, 0xb6($a1)
/* E8D4 800334D4 14460003 */  bne       $v0, $a2, .L800334E4
/* E8D8 800334D8 00641021 */   addu     $v0, $v1, $a0
/* E8DC 800334DC 03E00008 */  jr        $ra
/* E8E0 800334E0 24020001 */   addiu    $v0, $zero, 1
.L800334E4:
/* E8E4 800334E4 A4A200B6 */  sh        $v0, 0xb6($a1)
/* E8E8 800334E8 00021400 */  sll       $v0, $v0, 0x10
/* E8EC 800334EC 00021403 */  sra       $v0, $v0, 0x10
/* E8F0 800334F0 28420100 */  slti      $v0, $v0, 0x100
/* E8F4 800334F4 50400001 */  beql      $v0, $zero, .L800334FC
/* E8F8 800334F8 A4A600B6 */   sh       $a2, 0xb6($a1)
.L800334FC:
/* E8FC 800334FC 03E00008 */  jr        $ra
/* E900 80033500 0000102D */   daddu    $v0, $zero, $zero
