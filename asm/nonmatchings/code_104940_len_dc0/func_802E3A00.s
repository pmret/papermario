.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802E3A00
/* 105280 802E3A00 2403000E */  addiu     $v1, $zero, 0xe
/* 105284 802E3A04 9082000A */  lbu       $v0, 0xa($a0)
/* 105288 802E3A08 8C840040 */  lw        $a0, 0x40($a0)
/* 10528C 802E3A0C 1443000C */  bne       $v0, $v1, .L802E3A40
/* 105290 802E3A10 2402000A */   addiu    $v0, $zero, 0xa
/* 105294 802E3A14 84830004 */  lh        $v1, 4($a0)
/* 105298 802E3A18 10620009 */  beq       $v1, $v0, .L802E3A40
/* 10529C 802E3A1C 00000000 */   nop
/* 1052A0 802E3A20 94820006 */  lhu       $v0, 6($a0)
/* 1052A4 802E3A24 2442FFFF */  addiu     $v0, $v0, -1
/* 1052A8 802E3A28 A4820006 */  sh        $v0, 6($a0)
/* 1052AC 802E3A2C 00021400 */  sll       $v0, $v0, 0x10
/* 1052B0 802E3A30 04410003 */  bgez      $v0, .L802E3A40
/* 1052B4 802E3A34 24020001 */   addiu    $v0, $zero, 1
/* 1052B8 802E3A38 A4800006 */  sh        $zero, 6($a0)
/* 1052BC 802E3A3C A4820004 */  sh        $v0, 4($a0)
.L802E3A40:
/* 1052C0 802E3A40 03E00008 */  jr        $ra
/* 1052C4 802E3A44 00000000 */   nop
