.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802424D0
/* C87F80 802424D0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C87F84 802424D4 AFBF0010 */  sw        $ra, 0x10($sp)
/* C87F88 802424D8 0C00EAD2 */  jal       get_npc_safe
/* C87F8C 802424DC 8C84014C */   lw       $a0, 0x14c($a0)
/* C87F90 802424E0 3C038011 */  lui       $v1, %hi(gPlayerStatus)
/* C87F94 802424E4 2463EFC8 */  addiu     $v1, $v1, %lo(gPlayerStatus)
/* C87F98 802424E8 C44C0038 */  lwc1      $f12, 0x38($v0)
/* C87F9C 802424EC C44E0040 */  lwc1      $f14, 0x40($v0)
/* C87FA0 802424F0 8C660028 */  lw        $a2, 0x28($v1)
/* C87FA4 802424F4 0C00A7B5 */  jal       dist2D
/* C87FA8 802424F8 8C670030 */   lw       $a3, 0x30($v1)
/* C87FAC 802424FC 3C014248 */  lui       $at, 0x4248
/* C87FB0 80242500 44811000 */  mtc1      $at, $f2
/* C87FB4 80242504 00000000 */  nop       
/* C87FB8 80242508 4602003C */  c.lt.s    $f0, $f2
/* C87FBC 8024250C 00000000 */  nop       
/* C87FC0 80242510 45010002 */  bc1t      .L8024251C
/* C87FC4 80242514 24020002 */   addiu    $v0, $zero, 2
/* C87FC8 80242518 0000102D */  daddu     $v0, $zero, $zero
.L8024251C:
/* C87FCC 8024251C 8FBF0010 */  lw        $ra, 0x10($sp)
/* C87FD0 80242520 03E00008 */  jr        $ra
/* C87FD4 80242524 27BD0018 */   addiu    $sp, $sp, 0x18
