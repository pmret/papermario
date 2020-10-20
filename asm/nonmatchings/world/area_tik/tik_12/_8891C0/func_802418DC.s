.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802418DC
/* 88A4AC 802418DC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 88A4B0 802418E0 AFBF0018 */  sw        $ra, 0x18($sp)
/* 88A4B4 802418E4 0C00EAD2 */  jal       get_npc_safe
/* 88A4B8 802418E8 2404FFFC */   addiu    $a0, $zero, -4
/* 88A4BC 802418EC 3C0141F0 */  lui       $at, 0x41f0
/* 88A4C0 802418F0 44810000 */  mtc1      $at, $f0
/* 88A4C4 802418F4 C442003C */  lwc1      $f2, 0x3c($v0)
/* 88A4C8 802418F8 46001080 */  add.s     $f2, $f2, $f0
/* 88A4CC 802418FC E7A00010 */  swc1      $f0, 0x10($sp)
/* 88A4D0 80241900 8C450038 */  lw        $a1, 0x38($v0)
/* 88A4D4 80241904 8C470040 */  lw        $a3, 0x40($v0)
/* 88A4D8 80241908 44061000 */  mfc1      $a2, $f2
/* 88A4DC 8024190C 0C01BFBC */  jal       func_8006FEF0
/* 88A4E0 80241910 24040004 */   addiu    $a0, $zero, 4
/* 88A4E4 80241914 8FBF0018 */  lw        $ra, 0x18($sp)
/* 88A4E8 80241918 24020002 */  addiu     $v0, $zero, 2
/* 88A4EC 8024191C 03E00008 */  jr        $ra
/* 88A4F0 80241920 27BD0020 */   addiu    $sp, $sp, 0x20
