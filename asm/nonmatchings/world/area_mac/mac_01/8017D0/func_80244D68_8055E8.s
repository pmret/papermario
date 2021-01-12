.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80244D68_8055E8
/* 8055E8 80244D68 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8055EC 80244D6C AFBF0010 */  sw        $ra, 0x10($sp)
/* 8055F0 80244D70 0000202D */  daddu     $a0, $zero, $zero
/* 8055F4 80244D74 3C05F840 */  lui       $a1, 0xf840
/* 8055F8 80244D78 0C0B1EAF */  jal       get_variable
/* 8055FC 80244D7C 34A55C84 */   ori      $a1, $a1, 0x5c84
/* 805600 80244D80 14400008 */  bnez      $v0, .L80244DA4
/* 805604 80244D84 0000202D */   daddu    $a0, $zero, $zero
/* 805608 80244D88 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 80560C 80244D8C 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 805610 80244D90 8C420140 */  lw        $v0, 0x140($v0)
/* 805614 80244D94 8C440000 */  lw        $a0, ($v0)
/* 805618 80244D98 0C04D052 */  jal       set_item_entity_flags
/* 80561C 80244D9C 24050040 */   addiu    $a1, $zero, 0x40
/* 805620 80244DA0 0000202D */  daddu     $a0, $zero, $zero
.L80244DA4:
/* 805624 80244DA4 3C05F840 */  lui       $a1, 0xf840
/* 805628 80244DA8 0C0B1EAF */  jal       get_variable
/* 80562C 80244DAC 34A55C85 */   ori      $a1, $a1, 0x5c85
/* 805630 80244DB0 14400008 */  bnez      $v0, .L80244DD4
/* 805634 80244DB4 0000202D */   daddu    $a0, $zero, $zero
/* 805638 80244DB8 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 80563C 80244DBC 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 805640 80244DC0 8C420140 */  lw        $v0, 0x140($v0)
/* 805644 80244DC4 8C440010 */  lw        $a0, 0x10($v0)
/* 805648 80244DC8 0C04D052 */  jal       set_item_entity_flags
/* 80564C 80244DCC 24050040 */   addiu    $a1, $zero, 0x40
/* 805650 80244DD0 0000202D */  daddu     $a0, $zero, $zero
.L80244DD4:
/* 805654 80244DD4 3C05F840 */  lui       $a1, 0xf840
/* 805658 80244DD8 0C0B1EAF */  jal       get_variable
/* 80565C 80244DDC 34A55C86 */   ori      $a1, $a1, 0x5c86
/* 805660 80244DE0 14400007 */  bnez      $v0, .L80244E00
/* 805664 80244DE4 00000000 */   nop
/* 805668 80244DE8 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 80566C 80244DEC 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 805670 80244DF0 8C420140 */  lw        $v0, 0x140($v0)
/* 805674 80244DF4 8C440020 */  lw        $a0, 0x20($v0)
/* 805678 80244DF8 0C04D052 */  jal       set_item_entity_flags
/* 80567C 80244DFC 24050040 */   addiu    $a1, $zero, 0x40
.L80244E00:
/* 805680 80244E00 8FBF0010 */  lw        $ra, 0x10($sp)
/* 805684 80244E04 24020002 */  addiu     $v0, $zero, 2
/* 805688 80244E08 03E00008 */  jr        $ra
/* 80568C 80244E0C 27BD0018 */   addiu    $sp, $sp, 0x18
