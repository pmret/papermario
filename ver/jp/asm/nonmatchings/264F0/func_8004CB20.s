.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004CB20
/* 27F20 8004CB20 8CA20000 */  lw        $v0, ($a1)
/* 27F24 8004CB24 90430000 */  lbu       $v1, ($v0)
/* 27F28 8004CB28 24420001 */  addiu     $v0, $v0, 1
/* 27F2C 8004CB2C ACA20000 */  sw        $v0, ($a1)
/* 27F30 8004CB30 A4A3005C */  sh        $v1, 0x5c($a1)
/* 27F34 8004CB34 84A2005C */  lh        $v0, 0x5c($a1)
/* 27F38 8004CB38 10400003 */  beqz      $v0, .L8004CB48
/* 27F3C 8004CB3C 00031200 */   sll      $v0, $v1, 8
/* 27F40 8004CB40 344200FF */  ori       $v0, $v0, 0xff
/* 27F44 8004CB44 A4A2005C */  sh        $v0, 0x5c($a1)
.L8004CB48:
/* 27F48 8004CB48 24020001 */  addiu     $v0, $zero, 1
/* 27F4C 8004CB4C 03E00008 */  jr        $ra
/* 27F50 8004CB50 A0A20055 */   sb       $v0, 0x55($a1)
