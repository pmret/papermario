.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240D40_954D00
/* 954D00 80240D40 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 954D04 80240D44 AFBF0018 */  sw        $ra, 0x18($sp)
/* 954D08 80240D48 0C00EAD2 */  jal       get_npc_safe
/* 954D0C 80240D4C 2404FFFC */   addiu    $a0, $zero, -4
/* 954D10 80240D50 3C0141F0 */  lui       $at, 0x41f0
/* 954D14 80240D54 44810000 */  mtc1      $at, $f0
/* 954D18 80240D58 C442003C */  lwc1      $f2, 0x3c($v0)
/* 954D1C 80240D5C 46001080 */  add.s     $f2, $f2, $f0
/* 954D20 80240D60 E7A00010 */  swc1      $f0, 0x10($sp)
/* 954D24 80240D64 8C450038 */  lw        $a1, 0x38($v0)
/* 954D28 80240D68 8C470040 */  lw        $a3, 0x40($v0)
/* 954D2C 80240D6C 44061000 */  mfc1      $a2, $f2
/* 954D30 80240D70 0C01BFBC */  jal       func_8006FEF0
/* 954D34 80240D74 24040004 */   addiu    $a0, $zero, 4
/* 954D38 80240D78 8FBF0018 */  lw        $ra, 0x18($sp)
/* 954D3C 80240D7C 24020002 */  addiu     $v0, $zero, 2
/* 954D40 80240D80 03E00008 */  jr        $ra
/* 954D44 80240D84 27BD0020 */   addiu    $sp, $sp, 0x20
