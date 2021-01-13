.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802E3A48
/* 1052C8 802E3A48 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 1052CC 802E3A4C AFB00018 */  sw        $s0, 0x18($sp)
/* 1052D0 802E3A50 0080802D */  daddu     $s0, $a0, $zero
/* 1052D4 802E3A54 AFBF0020 */  sw        $ra, 0x20($sp)
/* 1052D8 802E3A58 AFB1001C */  sw        $s1, 0x1c($sp)
/* 1052DC 802E3A5C 92020006 */  lbu       $v0, 6($s0)
/* 1052E0 802E3A60 8E110040 */  lw        $s1, 0x40($s0)
/* 1052E4 802E3A64 30420080 */  andi      $v0, $v0, 0x80
/* 1052E8 802E3A68 10400005 */  beqz      $v0, .L802E3A80
/* 1052EC 802E3A6C 00000000 */   nop
/* 1052F0 802E3A70 0C043F5A */  jal       func_8010FD68
/* 1052F4 802E3A74 00000000 */   nop
/* 1052F8 802E3A78 080B8EBD */  j         .L802E3AF4
/* 1052FC 802E3A7C 00000000 */   nop
.L802E3A80:
/* 105300 802E3A80 0C0B8E80 */  jal       func_802E3A00
/* 105304 802E3A84 0200202D */   daddu    $a0, $s0, $zero
/* 105308 802E3A88 0C0B8D94 */  jal       func_802E3650
/* 10530C 802E3A8C 0200202D */   daddu    $a0, $s0, $zero
/* 105310 802E3A90 82220003 */  lb        $v0, 3($s1)
/* 105314 802E3A94 10400017 */  beqz      $v0, .L802E3AF4
/* 105318 802E3A98 3C028000 */   lui      $v0, 0x8000
/* 10531C 802E3A9C 3C04802F */  lui       $a0, %hi(D_802EA07C)
/* 105320 802E3AA0 2484A07C */  addiu     $a0, $a0, %lo(D_802EA07C)
/* 105324 802E3AA4 C6020048 */  lwc1      $f2, 0x48($s0)
/* 105328 802E3AA8 C604004C */  lwc1      $f4, 0x4c($s0)
/* 10532C 802E3AAC C6060050 */  lwc1      $f6, 0x50($s0)
/* 105330 802E3AB0 C6000064 */  lwc1      $f0, 0x64($s0)
/* 105334 802E3AB4 AFA20014 */  sw        $v0, 0x14($sp)
/* 105338 802E3AB8 4600020D */  trunc.w.s $f8, $f0
/* 10533C 802E3ABC E7A80010 */  swc1      $f8, 0x10($sp)
/* 105340 802E3AC0 4600120D */  trunc.w.s $f8, $f2
/* 105344 802E3AC4 44054000 */  mfc1      $a1, $f8
/* 105348 802E3AC8 4600220D */  trunc.w.s $f8, $f4
/* 10534C 802E3ACC 44064000 */  mfc1      $a2, $f8
/* 105350 802E3AD0 4600320D */  trunc.w.s $f8, $f6
/* 105354 802E3AD4 44074000 */  mfc1      $a3, $f8
/* 105358 802E3AD8 0C044631 */  jal       create_entity
/* 10535C 802E3ADC 00000000 */   nop
/* 105360 802E3AE0 3C032000 */  lui       $v1, 0x2000
/* 105364 802E3AE4 8E020000 */  lw        $v0, ($s0)
/* 105368 802E3AE8 34630020 */  ori       $v1, $v1, 0x20
/* 10536C 802E3AEC 00431025 */  or        $v0, $v0, $v1
/* 105370 802E3AF0 AE020000 */  sw        $v0, ($s0)
.L802E3AF4:
/* 105374 802E3AF4 8FBF0020 */  lw        $ra, 0x20($sp)
/* 105378 802E3AF8 8FB1001C */  lw        $s1, 0x1c($sp)
/* 10537C 802E3AFC 8FB00018 */  lw        $s0, 0x18($sp)
/* 105380 802E3B00 03E00008 */  jr        $ra
/* 105384 802E3B04 27BD0028 */   addiu    $sp, $sp, 0x28
