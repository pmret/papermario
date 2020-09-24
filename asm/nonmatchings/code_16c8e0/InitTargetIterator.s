.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel InitTargetIterator
/* 19CC34 8026E354 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 19CC38 8026E358 AFBF0010 */  sw        $ra, 0x10($sp)
/* 19CC3C 8026E35C 0C09A75B */  jal       get_actor
/* 19CC40 8026E360 8C840148 */   lw       $a0, 0x148($a0)
/* 19CC44 8026E364 0040202D */  daddu     $a0, $v0, $zero
/* 19CC48 8026E368 80820425 */  lb        $v0, 0x425($a0)
/* 19CC4C 8026E36C 00821021 */  addu      $v0, $a0, $v0
/* 19CC50 8026E370 8043040D */  lb        $v1, 0x40d($v0)
/* 19CC54 8026E374 00031080 */  sll       $v0, $v1, 2
/* 19CC58 8026E378 00431021 */  addu      $v0, $v0, $v1
/* 19CC5C 8026E37C 00021080 */  sll       $v0, $v0, 2
/* 19CC60 8026E380 2442022C */  addiu     $v0, $v0, 0x22c
/* 19CC64 8026E384 00821021 */  addu      $v0, $a0, $v0
/* 19CC68 8026E388 94430000 */  lhu       $v1, ($v0)
/* 19CC6C 8026E38C A4830428 */  sh        $v1, 0x428($a0)
/* 19CC70 8026E390 90430003 */  lbu       $v1, 3($v0)
/* 19CC74 8026E394 A0830426 */  sb        $v1, 0x426($a0)
/* 19CC78 8026E398 8FBF0010 */  lw        $ra, 0x10($sp)
/* 19CC7C 8026E39C 24020002 */  addiu     $v0, $zero, 2
/* 19CC80 8026E3A0 03E00008 */  jr        $ra
/* 19CC84 8026E3A4 27BD0018 */   addiu    $sp, $sp, 0x18
