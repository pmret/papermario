.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel osPiGetCmdQueue
/* 046950 8006B550 3C038009 */  lui   $v1, 0x8009
/* 046954 8006B554 8C633D50 */  lw    $v1, 0x3d50($v1)
/* 046958 8006B558 10600003 */  beqz  $v1, .L8006B568
/* 04695C 8006B55C 00001021 */   addu  $v0, $zero, $zero
/* 046960 8006B560 3C028009 */  lui   $v0, 0x8009
/* 046964 8006B564 8C423D58 */  lw    $v0, 0x3d58($v0)
.L8006B568:
/* 046968 8006B568 03E00008 */  jr    $ra
/* 04696C 8006B56C 00000000 */   nop   

