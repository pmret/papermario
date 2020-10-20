.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241340
/* 887700 80241340 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 887704 80241344 AFBF0018 */  sw        $ra, 0x18($sp)
/* 887708 80241348 0C00EAD2 */  jal       get_npc_safe
/* 88770C 8024134C 2404FFFC */   addiu    $a0, $zero, -4
/* 887710 80241350 3C0141F0 */  lui       $at, 0x41f0
/* 887714 80241354 44810000 */  mtc1      $at, $f0
/* 887718 80241358 C442003C */  lwc1      $f2, 0x3c($v0)
/* 88771C 8024135C 46001080 */  add.s     $f2, $f2, $f0
/* 887720 80241360 E7A00010 */  swc1      $f0, 0x10($sp)
/* 887724 80241364 8C450038 */  lw        $a1, 0x38($v0)
/* 887728 80241368 8C470040 */  lw        $a3, 0x40($v0)
/* 88772C 8024136C 44061000 */  mfc1      $a2, $f2
/* 887730 80241370 0C01BFBC */  jal       func_8006FEF0
/* 887734 80241374 24040004 */   addiu    $a0, $zero, 4
/* 887738 80241378 8FBF0018 */  lw        $ra, 0x18($sp)
/* 88773C 8024137C 24020002 */  addiu     $v0, $zero, 2
/* 887740 80241380 03E00008 */  jr        $ra
/* 887744 80241384 27BD0020 */   addiu    $sp, $sp, 0x20
