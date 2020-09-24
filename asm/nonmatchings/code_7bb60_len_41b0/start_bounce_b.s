.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel start_bounce_b
/* 7F53C 800E608C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 7F540 800E6090 AFBF0010 */  sw        $ra, 0x10($sp)
/* 7F544 800E6094 0C039769 */  jal       set_action_state
/* 7F548 800E6098 24040004 */   addiu    $a0, $zero, 4
/* 7F54C 800E609C 3C048011 */  lui       $a0, 0x8011
/* 7F550 800E60A0 2484EFC8 */  addiu     $a0, $a0, -0x1038
/* 7F554 800E60A4 3C014100 */  lui       $at, 0x4100
/* 7F558 800E60A8 44810000 */  mtc1      $at, $f0
/* 7F55C 800E60AC 3C01BF80 */  lui       $at, 0xbf80
/* 7F560 800E60B0 44811000 */  mtc1      $at, $f2
/* 7F564 800E60B4 8C820000 */  lw        $v0, ($a0)
/* 7F568 800E60B8 3C030080 */  lui       $v1, 0x80
/* 7F56C 800E60BC AC800078 */  sw        $zero, 0x78($a0)
/* 7F570 800E60C0 AC80007C */  sw        $zero, 0x7c($a0)
/* 7F574 800E60C4 00431025 */  or        $v0, $v0, $v1
/* 7F578 800E60C8 E4800070 */  swc1      $f0, 0x70($a0)
/* 7F57C 800E60CC E4820074 */  swc1      $f2, 0x74($a0)
/* 7F580 800E60D0 AC820000 */  sw        $v0, ($a0)
/* 7F584 800E60D4 8FBF0010 */  lw        $ra, 0x10($sp)
/* 7F588 800E60D8 03E00008 */  jr        $ra
/* 7F58C 800E60DC 27BD0018 */   addiu    $sp, $sp, 0x18
