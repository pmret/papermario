.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel IP6_Hdlr
/* 46044 8006AC44 2401DFFF */  addiu     $at, $zero, -0x2001
/* 46048 8006AC48 1000FFF0 */  b         next_interrupt
/* 4604C 8006AC4C 02018024 */   and      $s0, $s0, $at
