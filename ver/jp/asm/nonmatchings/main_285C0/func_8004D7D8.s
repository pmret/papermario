.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004D7D8
/* 28BD8 8004D7D8 8C82001C */  lw        $v0, 0x1c($a0)
/* 28BDC 8004D7DC 10400005 */  beqz      $v0, .L8004D7F4
/* 28BE0 8004D7E0 0000102D */   daddu    $v0, $zero, $zero
/* 28BE4 8004D7E4 90830221 */  lbu       $v1, 0x221($a0)
/* 28BE8 8004D7E8 14600002 */  bnez      $v1, .L8004D7F4
/* 28BEC 8004D7EC 24020001 */   addiu    $v0, $zero, 1
/* 28BF0 8004D7F0 0000102D */  daddu     $v0, $zero, $zero
.L8004D7F4:
/* 28BF4 8004D7F4 03E00008 */  jr        $ra
/* 28BF8 8004D7F8 00000000 */   nop
