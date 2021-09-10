.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024256C_9B8EEC
/* 9B8EEC 8024256C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 9B8EF0 80242570 0000502D */  daddu     $t2, $zero, $zero
/* 9B8EF4 80242574 3C03800B */  lui       $v1, %hi(gCurrentEncounter)
/* 9B8EF8 80242578 24630F10 */  addiu     $v1, $v1, %lo(gCurrentEncounter)
/* 9B8EFC 8024257C AFBF0010 */  sw        $ra, 0x10($sp)
/* 9B8F00 80242580 8062001C */  lb        $v0, 0x1c($v1)
/* 9B8F04 80242584 8C85000C */  lw        $a1, 0xc($a0)
/* 9B8F08 80242588 18400016 */  blez      $v0, .L802425E4
/* 9B8F0C 8024258C 0140302D */   daddu    $a2, $t2, $zero
/* 9B8F10 80242590 0040582D */  daddu     $t3, $v0, $zero
/* 9B8F14 80242594 0060482D */  daddu     $t1, $v1, $zero
.L80242598:
/* 9B8F18 80242598 8D220028 */  lw        $v0, 0x28($t1)
/* 9B8F1C 8024259C 5040000E */  beql      $v0, $zero, .L802425D8
/* 9B8F20 802425A0 254A0001 */   addiu    $t2, $t2, 1
/* 9B8F24 802425A4 8C430000 */  lw        $v1, ($v0)
/* 9B8F28 802425A8 1860000A */  blez      $v1, .L802425D4
/* 9B8F2C 802425AC 0000382D */   daddu    $a3, $zero, $zero
/* 9B8F30 802425B0 0060402D */  daddu     $t0, $v1, $zero
/* 9B8F34 802425B4 0040182D */  daddu     $v1, $v0, $zero
.L802425B8:
/* 9B8F38 802425B8 8C620004 */  lw        $v0, 4($v1)
/* 9B8F3C 802425BC 54400001 */  bnel      $v0, $zero, .L802425C4
/* 9B8F40 802425C0 24C60001 */   addiu    $a2, $a2, 1
.L802425C4:
/* 9B8F44 802425C4 24E70001 */  addiu     $a3, $a3, 1
/* 9B8F48 802425C8 00E8102A */  slt       $v0, $a3, $t0
/* 9B8F4C 802425CC 1440FFFA */  bnez      $v0, .L802425B8
/* 9B8F50 802425D0 24630004 */   addiu    $v1, $v1, 4
.L802425D4:
/* 9B8F54 802425D4 254A0001 */  addiu     $t2, $t2, 1
.L802425D8:
/* 9B8F58 802425D8 014B102A */  slt       $v0, $t2, $t3
/* 9B8F5C 802425DC 1440FFEE */  bnez      $v0, .L80242598
/* 9B8F60 802425E0 25290004 */   addiu    $t1, $t1, 4
.L802425E4:
/* 9B8F64 802425E4 8CA50000 */  lw        $a1, ($a1)
/* 9B8F68 802425E8 0C0B2026 */  jal       evt_set_variable
/* 9B8F6C 802425EC 00000000 */   nop
/* 9B8F70 802425F0 8FBF0010 */  lw        $ra, 0x10($sp)
/* 9B8F74 802425F4 24020002 */  addiu     $v0, $zero, 2
/* 9B8F78 802425F8 03E00008 */  jr        $ra
/* 9B8F7C 802425FC 27BD0018 */   addiu    $sp, $sp, 0x18
