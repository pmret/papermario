.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240060_BFA100
/* BFA100 80240060 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* BFA104 80240064 AFBF0018 */  sw        $ra, 0x18($sp)
/* BFA108 80240068 0C00FB3A */  jal       get_enemy
/* BFA10C 8024006C 24040006 */   addiu    $a0, $zero, 6
/* BFA110 80240070 84440008 */  lh        $a0, 8($v0)
/* BFA114 80240074 0C00EABB */  jal       get_npc_unsafe
/* BFA118 80240078 00000000 */   nop      
/* BFA11C 8024007C C4400040 */  lwc1      $f0, 0x40($v0)
/* BFA120 80240080 2404032E */  addiu     $a0, $zero, 0x32e
/* BFA124 80240084 E7A00010 */  swc1      $f0, 0x10($sp)
/* BFA128 80240088 8C460038 */  lw        $a2, 0x38($v0)
/* BFA12C 8024008C 8C47003C */  lw        $a3, 0x3c($v0)
/* BFA130 80240090 0C05267B */  jal       func_801499EC
/* BFA134 80240094 0000282D */   daddu    $a1, $zero, $zero
/* BFA138 80240098 8FBF0018 */  lw        $ra, 0x18($sp)
/* BFA13C 8024009C 24020002 */  addiu     $v0, $zero, 2
/* BFA140 802400A0 03E00008 */  jr        $ra
/* BFA144 802400A4 27BD0020 */   addiu    $sp, $sp, 0x20
/* BFA148 802400A8 00000000 */  nop       
/* BFA14C 802400AC 00000000 */  nop       
