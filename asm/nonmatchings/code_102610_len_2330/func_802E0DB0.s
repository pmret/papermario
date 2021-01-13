.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802E0DB0
/* 102630 802E0DB0 90820006 */  lbu       $v0, 6($a0)
/* 102634 802E0DB4 30420004 */  andi      $v0, $v0, 4
/* 102638 802E0DB8 10400007 */  beqz      $v0, .L802E0DD8
/* 10263C 802E0DBC 0000102D */   daddu    $v0, $zero, $zero
/* 102640 802E0DC0 3C038011 */  lui       $v1, %hi(gPlayerStatus)
/* 102644 802E0DC4 8C63EFC8 */  lw        $v1, %lo(gPlayerStatus)($v1)
/* 102648 802E0DC8 30630002 */  andi      $v1, $v1, 2
/* 10264C 802E0DCC 14600002 */  bnez      $v1, .L802E0DD8
/* 102650 802E0DD0 24020001 */   addiu    $v0, $zero, 1
/* 102654 802E0DD4 0000102D */  daddu     $v0, $zero, $zero
.L802E0DD8:
/* 102658 802E0DD8 03E00008 */  jr        $ra
/* 10265C 802E0DDC 00000000 */   nop
