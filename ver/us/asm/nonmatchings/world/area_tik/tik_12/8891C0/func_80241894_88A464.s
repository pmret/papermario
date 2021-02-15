.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241894_88A464
/* 88A464 80241894 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 88A468 80241898 AFBF0018 */  sw        $ra, 0x18($sp)
/* 88A46C 8024189C 0C00EAD2 */  jal       get_npc_safe
/* 88A470 802418A0 2404FFFC */   addiu    $a0, $zero, -4
/* 88A474 802418A4 3C0141F0 */  lui       $at, 0x41f0
/* 88A478 802418A8 44810000 */  mtc1      $at, $f0
/* 88A47C 802418AC C442003C */  lwc1      $f2, 0x3c($v0)
/* 88A480 802418B0 46001080 */  add.s     $f2, $f2, $f0
/* 88A484 802418B4 E7A00010 */  swc1      $f0, 0x10($sp)
/* 88A488 802418B8 8C450038 */  lw        $a1, 0x38($v0)
/* 88A48C 802418BC 8C470040 */  lw        $a3, 0x40($v0)
/* 88A490 802418C0 44061000 */  mfc1      $a2, $f2
/* 88A494 802418C4 0C01BFBC */  jal       func_8006FEF0
/* 88A498 802418C8 24040002 */   addiu    $a0, $zero, 2
/* 88A49C 802418CC 8FBF0018 */  lw        $ra, 0x18($sp)
/* 88A4A0 802418D0 24020002 */  addiu     $v0, $zero, 2
/* 88A4A4 802418D4 03E00008 */  jr        $ra
/* 88A4A8 802418D8 27BD0020 */   addiu    $sp, $sp, 0x20
