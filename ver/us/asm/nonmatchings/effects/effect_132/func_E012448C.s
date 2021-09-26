.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E012448C
/* 412BBC E012448C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 412BC0 E0124490 3C02E012 */  lui       $v0, %hi(func_E01244C4)
/* 412BC4 E0124494 244244C4 */  addiu     $v0, $v0, %lo(func_E01244C4)
/* 412BC8 E0124498 AFA2001C */  sw        $v0, 0x1c($sp)
/* 412BCC E012449C 2402002D */  addiu     $v0, $zero, 0x2d
/* 412BD0 E01244A0 AFA40018 */  sw        $a0, 0x18($sp)
/* 412BD4 E01244A4 27A40010 */  addiu     $a0, $sp, 0x10
/* 412BD8 E01244A8 AFBF0020 */  sw        $ra, 0x20($sp)
/* 412BDC E01244AC AFA00014 */  sw        $zero, 0x14($sp)
/* 412BE0 E01244B0 0C080120 */  jal       shim_queue_render_task
/* 412BE4 E01244B4 AFA20010 */   sw       $v0, 0x10($sp)
/* 412BE8 E01244B8 8FBF0020 */  lw        $ra, 0x20($sp)
/* 412BEC E01244BC 03E00008 */  jr        $ra
/* 412BF0 E01244C0 27BD0028 */   addiu    $sp, $sp, 0x28
