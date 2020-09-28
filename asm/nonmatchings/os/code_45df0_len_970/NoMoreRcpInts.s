.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel NoMoreRcpInts
/* 46230 8006AE30 2401FBFF */  addiu     $at, $zero, -0x401
/* 46234 8006AE34 1000FF75 */  b         next_interrupt
/* 46238 8006AE38 02018024 */   and      $s0, $s0, $at
