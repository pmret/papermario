.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80238298_6F6118
/* 6F6118 80238298 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 6F611C 8023829C AFB60028 */  sw        $s6, 0x28($sp)
/* 6F6120 802382A0 3C16800E */  lui       $s6, %hi(gBattleStatus+0xDC)
/* 6F6124 802382A4 8ED6C14C */  lw        $s6, %lo(gBattleStatus+0xDC)($s6)
/* 6F6128 802382A8 AFBE0030 */  sw        $fp, 0x30($sp)
/* 6F612C 802382AC 0080F02D */  daddu     $fp, $a0, $zero
/* 6F6130 802382B0 AFB40020 */  sw        $s4, 0x20($sp)
/* 6F6134 802382B4 0000A02D */  daddu     $s4, $zero, $zero
/* 6F6138 802382B8 AFB50024 */  sw        $s5, 0x24($sp)
/* 6F613C 802382BC 0280A82D */  daddu     $s5, $s4, $zero
/* 6F6140 802382C0 AFBF0034 */  sw        $ra, 0x34($sp)
/* 6F6144 802382C4 AFB7002C */  sw        $s7, 0x2c($sp)
/* 6F6148 802382C8 AFB3001C */  sw        $s3, 0x1c($sp)
/* 6F614C 802382CC AFB20018 */  sw        $s2, 0x18($sp)
/* 6F6150 802382D0 AFB10014 */  sw        $s1, 0x14($sp)
/* 6F6154 802382D4 AFB00010 */  sw        $s0, 0x10($sp)
/* 6F6158 802382D8 82C2040C */  lb        $v0, 0x40c($s6)
/* 6F615C 802382DC 1840001E */  blez      $v0, .L80238358
/* 6F6160 802382E0 0280982D */   daddu    $s3, $s4, $zero
/* 6F6164 802382E4 2417000E */  addiu     $s7, $zero, 0xe
/* 6F6168 802382E8 02C0902D */  daddu     $s2, $s6, $zero
.L802382EC:
/* 6F616C 802382EC 0C09A75B */  jal       get_actor
/* 6F6170 802382F0 8644022C */   lh       $a0, 0x22c($s2)
/* 6F6174 802382F4 0040802D */  daddu     $s0, $v0, $zero
/* 6F6178 802382F8 8645022E */  lh        $a1, 0x22e($s2)
/* 6F617C 802382FC 0C099117 */  jal       get_actor_part
/* 6F6180 80238300 0200202D */   daddu    $a0, $s0, $zero
/* 6F6184 80238304 24050004 */  addiu     $a1, $zero, 4
/* 6F6188 80238308 8E04020C */  lw        $a0, 0x20c($s0)
/* 6F618C 8023830C 0C0997A6 */  jal       lookup_status_chance
/* 6F6190 80238310 0040882D */   daddu    $s1, $v0, $zero
/* 6F6194 80238314 82030218 */  lb        $v1, 0x218($s0)
/* 6F6198 80238318 14770002 */  bne       $v1, $s7, .L80238324
/* 6F619C 8023831C 0040202D */   daddu    $a0, $v0, $zero
/* 6F61A0 80238320 0000202D */  daddu     $a0, $zero, $zero
.L80238324:
/* 6F61A4 80238324 8E22007C */  lw        $v0, 0x7c($s1)
/* 6F61A8 80238328 30420020 */  andi      $v0, $v0, 0x20
/* 6F61AC 8023832C 54400001 */  bnel      $v0, $zero, .L80238334
/* 6F61B0 80238330 0000202D */   daddu    $a0, $zero, $zero
.L80238334:
/* 6F61B4 80238334 18800003 */  blez      $a0, .L80238344
/* 6F61B8 80238338 00000000 */   nop
/* 6F61BC 8023833C 02649821 */  addu      $s3, $s3, $a0
/* 6F61C0 80238340 26940001 */  addiu     $s4, $s4, 1
.L80238344:
/* 6F61C4 80238344 82C2040C */  lb        $v0, 0x40c($s6)
/* 6F61C8 80238348 26B50001 */  addiu     $s5, $s5, 1
/* 6F61CC 8023834C 02A2102A */  slt       $v0, $s5, $v0
/* 6F61D0 80238350 1440FFE6 */  bnez      $v0, .L802382EC
/* 6F61D4 80238354 26520014 */   addiu    $s2, $s2, 0x14
.L80238358:
/* 6F61D8 80238358 5A80000C */  blezl     $s4, .L8023838C
/* 6F61DC 8023835C AFC00084 */   sw       $zero, 0x84($fp)
/* 6F61E0 80238360 16800002 */  bnez      $s4, .L8023836C
/* 6F61E4 80238364 0274001A */   div      $zero, $s3, $s4
/* 6F61E8 80238368 0007000D */  break     7
.L8023836C:
/* 6F61EC 8023836C 2401FFFF */   addiu    $at, $zero, -1
/* 6F61F0 80238370 16810004 */  bne       $s4, $at, .L80238384
/* 6F61F4 80238374 3C018000 */   lui      $at, 0x8000
/* 6F61F8 80238378 16610002 */  bne       $s3, $at, .L80238384
/* 6F61FC 8023837C 00000000 */   nop
/* 6F6200 80238380 0006000D */  break     6
.L80238384:
/* 6F6204 80238384 00001012 */   mflo     $v0
/* 6F6208 80238388 AFC20084 */  sw        $v0, 0x84($fp)
.L8023838C:
/* 6F620C 8023838C 8FBF0034 */  lw        $ra, 0x34($sp)
/* 6F6210 80238390 8FBE0030 */  lw        $fp, 0x30($sp)
/* 6F6214 80238394 8FB7002C */  lw        $s7, 0x2c($sp)
/* 6F6218 80238398 8FB60028 */  lw        $s6, 0x28($sp)
/* 6F621C 8023839C 8FB50024 */  lw        $s5, 0x24($sp)
/* 6F6220 802383A0 8FB40020 */  lw        $s4, 0x20($sp)
/* 6F6224 802383A4 8FB3001C */  lw        $s3, 0x1c($sp)
/* 6F6228 802383A8 8FB20018 */  lw        $s2, 0x18($sp)
/* 6F622C 802383AC 8FB10014 */  lw        $s1, 0x14($sp)
/* 6F6230 802383B0 8FB00010 */  lw        $s0, 0x10($sp)
/* 6F6234 802383B4 24020002 */  addiu     $v0, $zero, 2
/* 6F6238 802383B8 03E00008 */  jr        $ra
/* 6F623C 802383BC 27BD0038 */   addiu    $sp, $sp, 0x38
