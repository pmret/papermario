.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241530
/* 8ED350 80241530 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8ED354 80241534 AFBF0010 */  sw        $ra, 0x10($sp)
/* 8ED358 80241538 8C82000C */  lw        $v0, 0xc($a0)
/* 8ED35C 8024153C 3C068011 */  lui       $a2, 0x8011
/* 8ED360 80241540 80C6F2A2 */  lb        $a2, -0xd5e($a2)
/* 8ED364 80241544 0C0B2026 */  jal       set_variable
/* 8ED368 80241548 8C450000 */   lw       $a1, ($v0)
/* 8ED36C 8024154C 0C03AC5A */  jal       func_800EB168
/* 8ED370 80241550 0000202D */   daddu    $a0, $zero, $zero
/* 8ED374 80241554 8FBF0010 */  lw        $ra, 0x10($sp)
/* 8ED378 80241558 24020002 */  addiu     $v0, $zero, 2
/* 8ED37C 8024155C 03E00008 */  jr        $ra
/* 8ED380 80241560 27BD0018 */   addiu    $sp, $sp, 0x18
