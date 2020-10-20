.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241450_DDDC80
/* DDDC80 80241450 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* DDDC84 80241454 AFBF0018 */  sw        $ra, 0x18($sp)
/* DDDC88 80241458 0C00EAD2 */  jal       get_npc_safe
/* DDDC8C 8024145C 2404FFFC */   addiu    $a0, $zero, -4
/* DDDC90 80241460 3C0141F0 */  lui       $at, 0x41f0
/* DDDC94 80241464 44810000 */  mtc1      $at, $f0
/* DDDC98 80241468 C442003C */  lwc1      $f2, 0x3c($v0)
/* DDDC9C 8024146C 46001080 */  add.s     $f2, $f2, $f0
/* DDDCA0 80241470 E7A00010 */  swc1      $f0, 0x10($sp)
/* DDDCA4 80241474 8C450038 */  lw        $a1, 0x38($v0)
/* DDDCA8 80241478 8C470040 */  lw        $a3, 0x40($v0)
/* DDDCAC 8024147C 44061000 */  mfc1      $a2, $f2
/* DDDCB0 80241480 0C01BFBC */  jal       func_8006FEF0
/* DDDCB4 80241484 24040004 */   addiu    $a0, $zero, 4
/* DDDCB8 80241488 8FBF0018 */  lw        $ra, 0x18($sp)
/* DDDCBC 8024148C 24020002 */  addiu     $v0, $zero, 2
/* DDDCC0 80241490 03E00008 */  jr        $ra
/* DDDCC4 80241494 27BD0020 */   addiu    $sp, $sp, 0x20
