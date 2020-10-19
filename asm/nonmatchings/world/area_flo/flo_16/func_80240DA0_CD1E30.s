.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240DA0_CD2BD0
/* CD2BD0 80240DA0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* CD2BD4 80240DA4 AFBF0018 */  sw        $ra, 0x18($sp)
/* CD2BD8 80240DA8 0C00EAD2 */  jal       get_npc_safe
/* CD2BDC 80240DAC 2404FFFC */   addiu    $a0, $zero, -4
/* CD2BE0 80240DB0 3C0141F0 */  lui       $at, 0x41f0
/* CD2BE4 80240DB4 44810000 */  mtc1      $at, $f0
/* CD2BE8 80240DB8 C442003C */  lwc1      $f2, 0x3c($v0)
/* CD2BEC 80240DBC 46001080 */  add.s     $f2, $f2, $f0
/* CD2BF0 80240DC0 E7A00010 */  swc1      $f0, 0x10($sp)
/* CD2BF4 80240DC4 8C450038 */  lw        $a1, 0x38($v0)
/* CD2BF8 80240DC8 8C470040 */  lw        $a3, 0x40($v0)
/* CD2BFC 80240DCC 44061000 */  mfc1      $a2, $f2
/* CD2C00 80240DD0 0C01BFBC */  jal       func_8006FEF0
/* CD2C04 80240DD4 24040004 */   addiu    $a0, $zero, 4
/* CD2C08 80240DD8 8FBF0018 */  lw        $ra, 0x18($sp)
/* CD2C0C 80240DDC 24020002 */  addiu     $v0, $zero, 2
/* CD2C10 80240DE0 03E00008 */  jr        $ra
/* CD2C14 80240DE4 27BD0020 */   addiu    $sp, $sp, 0x20
