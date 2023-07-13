.set noat      /* allow manual use of $at */
.set noreorder /* don't insert nops after branches */

glabel func_800004A0
/* 10A0 800004A0 27BDFFE8 */  addiu      $sp, $sp, -0x18
/* 10A4 800004A4 AFBF0014 */  sw         $ra, 0x14($sp)
/* 10A8 800004A8 AFBE0010 */  sw         $fp, 0x10($sp)
/* 10AC 800004AC 0C000100 */  jal        func_80000400
/* 10B0 800004B0 03A0F021 */   addu      $fp, $sp, $zero
.L800004B4:
/* 10B4 800004B4 3C028000 */  lui        $v0, %hi(D_80000500)
/* 10B8 800004B8 8C420500 */  lw         $v0, %lo(D_80000500)($v0)
/* 10BC 800004BC 24430001 */  addiu      $v1, $v0, 0x1
/* 10C0 800004C0 3C018000 */  lui        $at, %hi(D_80000500)
/* 10C4 800004C4 AC230500 */  sw         $v1, %lo(D_80000500)($at)
/* 10C8 800004C8 3C028000 */  lui        $v0, %hi(D_80000500)
/* 10CC 800004CC 8C420500 */  lw         $v0, %lo(D_80000500)($v0)
/* 10D0 800004D0 0800012D */  j          .L800004B4
/* 10D4 800004D4 00000000 */   nop
/* 10D8 800004D8 03C0E821 */  addu       $sp, $fp, $zero
/* 10DC 800004DC 8FBF0014 */  lw         $ra, 0x14($sp)
/* 10E0 800004E0 8FBE0010 */  lw         $fp, 0x10($sp)
/* 10E4 800004E4 03E00008 */  jr         $ra
/* 10E8 800004E8 27BD0018 */   addiu     $sp, $sp, 0x18
/* 10EC 800004EC 00000000 */  nop
.size func_800004A0, . - func_800004A0
