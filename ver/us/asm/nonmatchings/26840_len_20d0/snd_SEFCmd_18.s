.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel snd_SEFCmd_18
/* 287F8 8004D3F8 8CA20000 */  lw        $v0, ($a1)
/* 287FC 8004D3FC 90430000 */  lbu       $v1, ($v0)
/* 28800 8004D400 24420001 */  addiu     $v0, $v0, 1
/* 28804 8004D404 ACA20000 */  sw        $v0, ($a1)
/* 28808 8004D408 A4A3005E */  sh        $v1, 0x5e($a1)
/* 2880C 8004D40C 84A2005E */  lh        $v0, 0x5e($a1)
/* 28810 8004D410 10400003 */  beqz      $v0, .L8004D420
/* 28814 8004D414 00031200 */   sll      $v0, $v1, 8
/* 28818 8004D418 344200FF */  ori       $v0, $v0, 0xff
/* 2881C 8004D41C A4A2005E */  sh        $v0, 0x5e($a1)
.L8004D420:
/* 28820 8004D420 03E00008 */  jr        $ra
/* 28824 8004D424 00000000 */   nop
