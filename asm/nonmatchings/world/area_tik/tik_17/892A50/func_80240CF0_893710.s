.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel tik_17_UnkPartnerPosFunc
/* 893710 80240CF0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 893714 80240CF4 AFBF0018 */  sw        $ra, 0x18($sp)
/* 893718 80240CF8 0C00EAD2 */  jal       get_npc_safe
/* 89371C 80240CFC 2404FFFC */   addiu    $a0, $zero, -4
/* 893720 80240D00 3C0141F0 */  lui       $at, 0x41f0
/* 893724 80240D04 44810000 */  mtc1      $at, $f0
/* 893728 80240D08 C442003C */  lwc1      $f2, 0x3c($v0)
/* 89372C 80240D0C 46001080 */  add.s     $f2, $f2, $f0
/* 893730 80240D10 E7A00010 */  swc1      $f0, 0x10($sp)
/* 893734 80240D14 8C450038 */  lw        $a1, 0x38($v0)
/* 893738 80240D18 8C470040 */  lw        $a3, 0x40($v0)
/* 89373C 80240D1C 44061000 */  mfc1      $a2, $f2
/* 893740 80240D20 0C01BFBC */  jal       func_8006FEF0
/* 893744 80240D24 24040004 */   addiu    $a0, $zero, 4
/* 893748 80240D28 8FBF0018 */  lw        $ra, 0x18($sp)
/* 89374C 80240D2C 24020002 */  addiu     $v0, $zero, 2
/* 893750 80240D30 03E00008 */  jr        $ra
/* 893754 80240D34 27BD0020 */   addiu    $sp, $sp, 0x20
