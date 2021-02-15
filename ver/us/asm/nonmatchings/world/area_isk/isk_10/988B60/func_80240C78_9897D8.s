.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240C78_9897D8
/* 9897D8 80240C78 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 9897DC 80240C7C AFBF0018 */  sw        $ra, 0x18($sp)
/* 9897E0 80240C80 0C00EAD2 */  jal       get_npc_safe
/* 9897E4 80240C84 2404FFFC */   addiu    $a0, $zero, -4
/* 9897E8 80240C88 3C0141F0 */  lui       $at, 0x41f0
/* 9897EC 80240C8C 44810000 */  mtc1      $at, $f0
/* 9897F0 80240C90 C442003C */  lwc1      $f2, 0x3c($v0)
/* 9897F4 80240C94 46001080 */  add.s     $f2, $f2, $f0
/* 9897F8 80240C98 E7A00010 */  swc1      $f0, 0x10($sp)
/* 9897FC 80240C9C 8C450038 */  lw        $a1, 0x38($v0)
/* 989800 80240CA0 8C470040 */  lw        $a3, 0x40($v0)
/* 989804 80240CA4 44061000 */  mfc1      $a2, $f2
/* 989808 80240CA8 0C01BFBC */  jal       func_8006FEF0
/* 98980C 80240CAC 24040002 */   addiu    $a0, $zero, 2
/* 989810 80240CB0 8FBF0018 */  lw        $ra, 0x18($sp)
/* 989814 80240CB4 24020002 */  addiu     $v0, $zero, 2
/* 989818 80240CB8 03E00008 */  jr        $ra
/* 98981C 80240CBC 27BD0020 */   addiu    $sp, $sp, 0x20
