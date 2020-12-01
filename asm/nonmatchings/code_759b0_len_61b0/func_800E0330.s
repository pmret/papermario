.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800E0330
/* 797E0 800E0330 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* 797E4 800E0334 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* 797E8 800E0338 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 797EC 800E033C AFBF0010 */  sw        $ra, 0x10($sp)
/* 797F0 800E0340 8C420004 */  lw        $v0, 4($v0)
/* 797F4 800E0344 30420100 */  andi      $v0, $v0, 0x100
/* 797F8 800E0348 10400007 */  beqz      $v0, .L800E0368
/* 797FC 800E034C 00000000 */   nop      
/* 79800 800E0350 3C028011 */  lui       $v0, %hi(D_8010C93C)
/* 79804 800E0354 8C42C93C */  lw        $v0, %lo(D_8010C93C)($v0)
/* 79808 800E0358 10400003 */  beqz      $v0, .L800E0368
/* 7980C 800E035C 00000000 */   nop      
/* 79810 800E0360 0C0ADC00 */  jal       func_802B7000
/* 79814 800E0364 00000000 */   nop      
.L800E0368:
/* 79818 800E0368 8FBF0010 */  lw        $ra, 0x10($sp)
/* 7981C 800E036C 03E00008 */  jr        $ra
/* 79820 800E0370 27BD0018 */   addiu    $sp, $sp, 0x18
