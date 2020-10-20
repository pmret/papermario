.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242008
/* CCD318 80242008 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* CCD31C 8024200C AFB10014 */  sw        $s1, 0x14($sp)
/* CCD320 80242010 0080882D */  daddu     $s1, $a0, $zero
/* CCD324 80242014 AFBF0018 */  sw        $ra, 0x18($sp)
/* CCD328 80242018 AFB00010 */  sw        $s0, 0x10($sp)
/* CCD32C 8024201C 8E30000C */  lw        $s0, 0xc($s1)
/* CCD330 80242020 8E050000 */  lw        $a1, ($s0)
/* CCD334 80242024 0C0B1EAF */  jal       get_variable
/* CCD338 80242028 26100004 */   addiu    $s0, $s0, 4
/* CCD33C 8024202C 0C00EAD2 */  jal       get_npc_safe
/* CCD340 80242030 0040202D */   daddu    $a0, $v0, $zero
/* CCD344 80242034 10400005 */  beqz      $v0, .L8024204C
/* CCD348 80242038 00000000 */   nop      
/* CCD34C 8024203C 8E050000 */  lw        $a1, ($s0)
/* CCD350 80242040 844600A8 */  lh        $a2, 0xa8($v0)
/* CCD354 80242044 0C0B2026 */  jal       set_variable
/* CCD358 80242048 0220202D */   daddu    $a0, $s1, $zero
.L8024204C:
/* CCD35C 8024204C 8FBF0018 */  lw        $ra, 0x18($sp)
/* CCD360 80242050 8FB10014 */  lw        $s1, 0x14($sp)
/* CCD364 80242054 8FB00010 */  lw        $s0, 0x10($sp)
/* CCD368 80242058 24020002 */  addiu     $v0, $zero, 2
/* CCD36C 8024205C 03E00008 */  jr        $ra
/* CCD370 80242060 27BD0020 */   addiu    $sp, $sp, 0x20
