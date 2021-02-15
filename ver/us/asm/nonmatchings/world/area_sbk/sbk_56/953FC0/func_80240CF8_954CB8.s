.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240CF8_954CB8
/* 954CB8 80240CF8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 954CBC 80240CFC AFBF0018 */  sw        $ra, 0x18($sp)
/* 954CC0 80240D00 0C00EAD2 */  jal       get_npc_safe
/* 954CC4 80240D04 2404FFFC */   addiu    $a0, $zero, -4
/* 954CC8 80240D08 3C0141F0 */  lui       $at, 0x41f0
/* 954CCC 80240D0C 44810000 */  mtc1      $at, $f0
/* 954CD0 80240D10 C442003C */  lwc1      $f2, 0x3c($v0)
/* 954CD4 80240D14 46001080 */  add.s     $f2, $f2, $f0
/* 954CD8 80240D18 E7A00010 */  swc1      $f0, 0x10($sp)
/* 954CDC 80240D1C 8C450038 */  lw        $a1, 0x38($v0)
/* 954CE0 80240D20 8C470040 */  lw        $a3, 0x40($v0)
/* 954CE4 80240D24 44061000 */  mfc1      $a2, $f2
/* 954CE8 80240D28 0C01BFBC */  jal       func_8006FEF0
/* 954CEC 80240D2C 24040002 */   addiu    $a0, $zero, 2
/* 954CF0 80240D30 8FBF0018 */  lw        $ra, 0x18($sp)
/* 954CF4 80240D34 24020002 */  addiu     $v0, $zero, 2
/* 954CF8 80240D38 03E00008 */  jr        $ra
/* 954CFC 80240D3C 27BD0020 */   addiu    $sp, $sp, 0x20
