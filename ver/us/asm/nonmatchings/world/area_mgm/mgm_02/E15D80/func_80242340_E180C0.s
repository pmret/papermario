.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242340_E180C0
/* E180C0 80242340 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* E180C4 80242344 AFB00010 */  sw        $s0, 0x10($sp)
/* E180C8 80242348 0080802D */  daddu     $s0, $a0, $zero
/* E180CC 8024234C 3C038011 */  lui       $v1, %hi(gPlayerData)
/* E180D0 80242350 2463F290 */  addiu     $v1, $v1, %lo(gPlayerData)
/* E180D4 80242354 10A00005 */  beqz      $a1, .L8024236C
/* E180D8 80242358 AFBF0014 */   sw       $ra, 0x14($sp)
/* E180DC 8024235C 94620336 */  lhu       $v0, 0x336($v1)
/* E180E0 80242360 24420001 */  addiu     $v0, $v0, 1
/* E180E4 80242364 A4620336 */  sh        $v0, 0x336($v1)
/* E180E8 80242368 AE000070 */  sw        $zero, 0x70($s0)
.L8024236C:
/* E180EC 8024236C 0C03A830 */  jal       add_coins
/* E180F0 80242370 2404FFFF */   addiu    $a0, $zero, -1
/* E180F4 80242374 0C05272D */  jal       sfx_play_sound
/* E180F8 80242378 24040211 */   addiu    $a0, $zero, 0x211
/* E180FC 8024237C 8E030070 */  lw        $v1, 0x70($s0)
/* E18100 80242380 24630001 */  addiu     $v1, $v1, 1
/* E18104 80242384 3862000A */  xori      $v0, $v1, 0xa
/* E18108 80242388 2C420001 */  sltiu     $v0, $v0, 1
/* E1810C 8024238C AE030070 */  sw        $v1, 0x70($s0)
/* E18110 80242390 8FBF0014 */  lw        $ra, 0x14($sp)
/* E18114 80242394 8FB00010 */  lw        $s0, 0x10($sp)
/* E18118 80242398 00021040 */  sll       $v0, $v0, 1
/* E1811C 8024239C 03E00008 */  jr        $ra
/* E18120 802423A0 27BD0018 */   addiu    $sp, $sp, 0x18
