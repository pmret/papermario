.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8006B340
/* 46740 8006B340 3C0A8009 */  lui       $t2, %hi(D_80095890)
/* 46744 8006B344 254A5890 */  addiu     $t2, $t2, %lo(D_80095890)
/* 46748 8006B348 8D4B0000 */  lw        $t3, ($t2)
/* 4674C 8006B34C 316BFF00 */  andi      $t3, $t3, 0xff00
/* 46750 8006B350 40086000 */  mfc0      $t0, $12
/* 46754 8006B354 2401FFFE */  addiu     $at, $zero, -2
/* 46758 8006B358 01014824 */  and       $t1, $t0, $at
/* 4675C 8006B35C 40896000 */  mtc0      $t1, $12
/* 46760 8006B360 31020001 */  andi      $v0, $t0, 1
/* 46764 8006B364 8D480000 */  lw        $t0, ($t2)
/* 46768 8006B368 3108FF00 */  andi      $t0, $t0, 0xff00
/* 4676C 8006B36C 110B000E */  beq       $t0, $t3, .L8006B3A8
/* 46770 8006B370 3C0A8009 */   lui      $t2, %hi(D_80094640)
/* 46774 8006B374 254A4640 */  addiu     $t2, $t2, %lo(D_80094640)
/* 46778 8006B378 8D490118 */  lw        $t1, 0x118($t2)
/* 4677C 8006B37C 312AFF00 */  andi      $t2, $t1, 0xff00
/* 46780 8006B380 01485024 */  and       $t2, $t2, $t0
/* 46784 8006B384 3C01FFFF */  lui       $at, 0xffff
/* 46788 8006B388 342100FF */  ori       $at, $at, 0xff
/* 4678C 8006B38C 01214824 */  and       $t1, $t1, $at
/* 46790 8006B390 012A4825 */  or        $t1, $t1, $t2
/* 46794 8006B394 2401FFFE */  addiu     $at, $zero, -2
/* 46798 8006B398 01214824 */  and       $t1, $t1, $at
/* 4679C 8006B39C 40896000 */  mtc0      $t1, $12
/* 467A0 8006B3A0 00000000 */  nop
/* 467A4 8006B3A4 00000000 */  nop
.L8006B3A8:
/* 467A8 8006B3A8 03E00008 */  jr        $ra
/* 467AC 8006B3AC 00000000 */   nop
