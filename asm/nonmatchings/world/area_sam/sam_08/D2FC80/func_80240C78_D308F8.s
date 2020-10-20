.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240C78_D308F8
/* D308F8 80240C78 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* D308FC 80240C7C AFBF0018 */  sw        $ra, 0x18($sp)
/* D30900 80240C80 0C00EAD2 */  jal       get_npc_safe
/* D30904 80240C84 2404FFFC */   addiu    $a0, $zero, -4
/* D30908 80240C88 3C0141F0 */  lui       $at, 0x41f0
/* D3090C 80240C8C 44810000 */  mtc1      $at, $f0
/* D30910 80240C90 C442003C */  lwc1      $f2, 0x3c($v0)
/* D30914 80240C94 46001080 */  add.s     $f2, $f2, $f0
/* D30918 80240C98 E7A00010 */  swc1      $f0, 0x10($sp)
/* D3091C 80240C9C 8C450038 */  lw        $a1, 0x38($v0)
/* D30920 80240CA0 8C470040 */  lw        $a3, 0x40($v0)
/* D30924 80240CA4 44061000 */  mfc1      $a2, $f2
/* D30928 80240CA8 0C01BFBC */  jal       func_8006FEF0
/* D3092C 80240CAC 24040002 */   addiu    $a0, $zero, 2
/* D30930 80240CB0 8FBF0018 */  lw        $ra, 0x18($sp)
/* D30934 80240CB4 24020002 */  addiu     $v0, $zero, 2
/* D30938 80240CB8 03E00008 */  jr        $ra
/* D3093C 80240CBC 27BD0020 */   addiu    $sp, $sp, 0x20
