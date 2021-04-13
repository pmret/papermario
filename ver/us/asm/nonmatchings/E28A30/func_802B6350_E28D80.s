.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802B6350_E28D80
/* E28D80 802B6350 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* E28D84 802B6354 3C048011 */  lui       $a0, %hi(gPlayerStatus)
/* E28D88 802B6358 2484EFC8 */  addiu     $a0, $a0, %lo(gPlayerStatus)
/* E28D8C 802B635C AFBF0010 */  sw        $ra, 0x10($sp)
/* E28D90 802B6360 8C850000 */  lw        $a1, ($a0)
/* E28D94 802B6364 04A10010 */  bgez      $a1, .L802B63A8
/* E28D98 802B6368 0080302D */   daddu    $a2, $a0, $zero
/* E28D9C 802B636C 3C027FF7 */  lui       $v0, 0x7ff7
/* E28DA0 802B6370 3442FFF1 */  ori       $v0, $v0, 0xfff1
/* E28DA4 802B6374 8C830004 */  lw        $v1, 4($a0)
/* E28DA8 802B6378 00A21024 */  and       $v0, $a1, $v0
/* E28DAC 802B637C AC820000 */  sw        $v0, ($a0)
/* E28DB0 802B6380 A08000B6 */  sb        $zero, 0xb6($a0)
/* E28DB4 802B6384 A4800008 */  sh        $zero, 8($a0)
/* E28DB8 802B6388 A48000C0 */  sh        $zero, 0xc0($a0)
/* E28DBC 802B638C A48000C2 */  sh        $zero, 0xc2($a0)
/* E28DC0 802B6390 AC800054 */  sw        $zero, 0x54($a0)
/* E28DC4 802B6394 30631000 */  andi      $v1, $v1, 0x1000
/* E28DC8 802B6398 1460000B */  bnez      $v1, .L802B63C8
/* E28DCC 802B639C AC80008C */   sw       $zero, 0x8c($a0)
/* E28DD0 802B63A0 24020005 */  addiu     $v0, $zero, 5
/* E28DD4 802B63A4 A4820008 */  sh        $v0, 8($a0)
.L802B63A8:
/* E28DD8 802B63A8 94C20008 */  lhu       $v0, 8($a2)
/* E28DDC 802B63AC 2442FFFF */  addiu     $v0, $v0, -1
/* E28DE0 802B63B0 A4C20008 */  sh        $v0, 8($a2)
/* E28DE4 802B63B4 00021400 */  sll       $v0, $v0, 0x10
/* E28DE8 802B63B8 14400003 */  bnez      $v0, .L802B63C8
/* E28DEC 802B63BC 00000000 */   nop
/* E28DF0 802B63C0 0C039769 */  jal       set_action_state
/* E28DF4 802B63C4 0000202D */   daddu    $a0, $zero, $zero
.L802B63C8:
/* E28DF8 802B63C8 8FBF0010 */  lw        $ra, 0x10($sp)
/* E28DFC 802B63CC 03E00008 */  jr        $ra
/* E28E00 802B63D0 27BD0018 */   addiu    $sp, $sp, 0x18
