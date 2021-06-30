.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel snd_SEFCmd_0A_EndLoop
/* 28530 8004D130 90A2008C */  lbu       $v0, 0x8c($a1)
/* 28534 8004D134 10400005 */  beqz      $v0, .L8004D14C
/* 28538 8004D138 2442FFFF */   addiu    $v0, $v0, -1
/* 2853C 8004D13C A0A2008C */  sb        $v0, 0x8c($a1)
/* 28540 8004D140 304200FF */  andi      $v0, $v0, 0xff
/* 28544 8004D144 10400003 */  beqz      $v0, .L8004D154
/* 28548 8004D148 00000000 */   nop
.L8004D14C:
/* 2854C 8004D14C 8CA20088 */  lw        $v0, 0x88($a1)
/* 28550 8004D150 ACA20000 */  sw        $v0, ($a1)
.L8004D154:
/* 28554 8004D154 03E00008 */  jr        $ra
/* 28558 8004D158 00000000 */   nop
