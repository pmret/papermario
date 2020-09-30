.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel IP7_Hdlr
/* 46050 8006AC50 2401BFFF */  addiu     $at, $zero, -0x4001
/* 46054 8006AC54 1000FFED */  b         next_interrupt
/* 46058 8006AC58 02018024 */   and      $s0, $s0, $at
