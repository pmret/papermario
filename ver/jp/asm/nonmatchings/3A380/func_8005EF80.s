.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8005EF80
.L8005EF80:
/* 3A380 8005EF80 3C02800A */  lui       $v0, %hi(D_8009A5F8)
/* 3A384 8005EF84 8C42A5F8 */  lw        $v0, %lo(D_8009A5F8)($v0)
/* 3A388 8005EF88 1440FFFD */  bnez      $v0, .L8005EF80
/* 3A38C 8005EF8C 00000000 */   nop
/* 3A390 8005EF90 03E00008 */  jr        $ra
/* 3A394 8005EF94 00000000 */   nop
/* 3A398 8005EF98 00000000 */  nop
/* 3A39C 8005EF9C 00000000 */  nop
