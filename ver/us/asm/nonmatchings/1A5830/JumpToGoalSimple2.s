.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel JumpToGoalSimple2
/* 1A7D00 80279420 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* 1A7D04 80279424 AFB20020 */  sw        $s2, 0x20($sp)
/* 1A7D08 80279428 0080902D */  daddu     $s2, $a0, $zero
/* 1A7D0C 8027942C AFBF0024 */  sw        $ra, 0x24($sp)
/* 1A7D10 80279430 AFB1001C */  sw        $s1, 0x1c($sp)
/* 1A7D14 80279434 AFB00018 */  sw        $s0, 0x18($sp)
/* 1A7D18 80279438 F7BE0050 */  sdc1      $f30, 0x50($sp)
/* 1A7D1C 8027943C F7BC0048 */  sdc1      $f28, 0x48($sp)
/* 1A7D20 80279440 F7BA0040 */  sdc1      $f26, 0x40($sp)
/* 1A7D24 80279444 F7B80038 */  sdc1      $f24, 0x38($sp)
/* 1A7D28 80279448 F7B60030 */  sdc1      $f22, 0x30($sp)
/* 1A7D2C 8027944C F7B40028 */  sdc1      $f20, 0x28($sp)
/* 1A7D30 80279450 8E51000C */  lw        $s1, 0xc($s2)
/* 1A7D34 80279454 54A00001 */  bnel      $a1, $zero, .L8027945C
/* 1A7D38 80279458 AE400070 */   sw       $zero, 0x70($s2)
.L8027945C:
/* 1A7D3C 8027945C 8E420070 */  lw        $v0, 0x70($s2)
/* 1A7D40 80279460 14400073 */  bnez      $v0, .L80279630
/* 1A7D44 80279464 00000000 */   nop
/* 1A7D48 80279468 8E250000 */  lw        $a1, ($s1)
/* 1A7D4C 8027946C 26310004 */  addiu     $s1, $s1, 4
/* 1A7D50 80279470 0C0B1EAF */  jal       evt_get_variable
/* 1A7D54 80279474 0240202D */   daddu    $a0, $s2, $zero
/* 1A7D58 80279478 0040202D */  daddu     $a0, $v0, $zero
/* 1A7D5C 8027947C 2402FF81 */  addiu     $v0, $zero, -0x7f
/* 1A7D60 80279480 14820002 */  bne       $a0, $v0, .L8027948C
/* 1A7D64 80279484 00000000 */   nop
/* 1A7D68 80279488 8E440148 */  lw        $a0, 0x148($s2)
.L8027948C:
/* 1A7D6C 8027948C 0C09A75B */  jal       get_actor
/* 1A7D70 80279490 00000000 */   nop
/* 1A7D74 80279494 0040802D */  daddu     $s0, $v0, $zero
/* 1A7D78 80279498 AE500074 */  sw        $s0, 0x74($s2)
/* 1A7D7C 8027949C 8E250000 */  lw        $a1, ($s1)
/* 1A7D80 802794A0 0C0B1EAF */  jal       evt_get_variable
/* 1A7D84 802794A4 0240202D */   daddu    $a0, $s2, $zero
/* 1A7D88 802794A8 C6000148 */  lwc1      $f0, 0x148($s0)
/* 1A7D8C 802794AC C61A0018 */  lwc1      $f26, 0x18($s0)
/* 1A7D90 802794B0 C61C0020 */  lwc1      $f28, 0x20($s0)
/* 1A7D94 802794B4 C614014C */  lwc1      $f20, 0x14c($s0)
/* 1A7D98 802794B8 C618001C */  lwc1      $f24, 0x1c($s0)
/* 1A7D9C 802794BC 2611000C */  addiu     $s1, $s0, 0xc
/* 1A7DA0 802794C0 A6020070 */  sh        $v0, 0x70($s0)
/* 1A7DA4 802794C4 E6000010 */  swc1      $f0, 0x10($s0)
/* 1A7DA8 802794C8 46000786 */  mov.s     $f30, $f0
/* 1A7DAC 802794CC 4406D000 */  mfc1      $a2, $f26
/* 1A7DB0 802794D0 4407E000 */  mfc1      $a3, $f28
/* 1A7DB4 802794D4 C6000144 */  lwc1      $f0, 0x144($s0)
/* 1A7DB8 802794D8 4600A386 */  mov.s     $f14, $f20
/* 1A7DBC 802794DC E6140014 */  swc1      $f20, 0x14($s0)
/* 1A7DC0 802794E0 E600000C */  swc1      $f0, 0xc($s0)
/* 1A7DC4 802794E4 46000586 */  mov.s     $f22, $f0
/* 1A7DC8 802794E8 0C00A720 */  jal       atan2
/* 1A7DCC 802794EC 4600B306 */   mov.s    $f12, $f22
/* 1A7DD0 802794F0 4600B306 */  mov.s     $f12, $f22
/* 1A7DD4 802794F4 4600A386 */  mov.s     $f14, $f20
/* 1A7DD8 802794F8 4406D000 */  mfc1      $a2, $f26
/* 1A7DDC 802794FC 4407E000 */  mfc1      $a3, $f28
/* 1A7DE0 80279500 4618F781 */  sub.s     $f30, $f30, $f24
/* 1A7DE4 80279504 0C00A7B5 */  jal       dist2D
/* 1A7DE8 80279508 E6000054 */   swc1     $f0, 0x54($s0)
/* 1A7DEC 8027950C 86020070 */  lh        $v0, 0x70($s0)
/* 1A7DF0 80279510 46000106 */  mov.s     $f4, $f0
/* 1A7DF4 80279514 14400012 */  bnez      $v0, .L80279560
/* 1A7DF8 80279518 E6040058 */   swc1     $f4, 0x58($s0)
/* 1A7DFC 8027951C C600004C */  lwc1      $f0, 0x4c($s0)
/* 1A7E00 80279520 C602004C */  lwc1      $f2, 0x4c($s0)
/* 1A7E04 80279524 46002003 */  div.s     $f0, $f4, $f0
/* 1A7E08 80279528 4600028D */  trunc.w.s $f10, $f0
/* 1A7E0C 8027952C 44035000 */  mfc1      $v1, $f10
/* 1A7E10 80279530 00000000 */  nop
/* 1A7E14 80279534 00031400 */  sll       $v0, $v1, 0x10
/* 1A7E18 80279538 00021403 */  sra       $v0, $v0, 0x10
/* 1A7E1C 8027953C 44820000 */  mtc1      $v0, $f0
/* 1A7E20 80279540 00000000 */  nop
/* 1A7E24 80279544 46800020 */  cvt.s.w   $f0, $f0
/* 1A7E28 80279548 46020002 */  mul.s     $f0, $f0, $f2
/* 1A7E2C 8027954C 00000000 */  nop
/* 1A7E30 80279550 46002086 */  mov.s     $f2, $f4
/* 1A7E34 80279554 A6030070 */  sh        $v1, 0x70($s0)
/* 1A7E38 80279558 0809E565 */  j         .L80279594
/* 1A7E3C 8027955C 46001201 */   sub.s    $f8, $f2, $f0
.L80279560:
/* 1A7E40 80279560 44821000 */  mtc1      $v0, $f2
/* 1A7E44 80279564 00000000 */  nop
/* 1A7E48 80279568 468010A0 */  cvt.s.w   $f2, $f2
/* 1A7E4C 8027956C 86020070 */  lh        $v0, 0x70($s0)
/* 1A7E50 80279570 46022083 */  div.s     $f2, $f4, $f2
/* 1A7E54 80279574 44820000 */  mtc1      $v0, $f0
/* 1A7E58 80279578 00000000 */  nop
/* 1A7E5C 8027957C 46800020 */  cvt.s.w   $f0, $f0
/* 1A7E60 80279580 46020002 */  mul.s     $f0, $f0, $f2
/* 1A7E64 80279584 00000000 */  nop
/* 1A7E68 80279588 C6040058 */  lwc1      $f4, 0x58($s0)
/* 1A7E6C 8027958C E602004C */  swc1      $f2, 0x4c($s0)
/* 1A7E70 80279590 46002201 */  sub.s     $f8, $f4, $f0
.L80279594:
/* 1A7E74 80279594 86220064 */  lh        $v0, 0x64($s1)
/* 1A7E78 80279598 14400003 */  bnez      $v0, .L802795A8
/* 1A7E7C 8027959C 00000000 */   nop
/* 1A7E80 802795A0 0809E5BE */  j         .L802796F8
/* 1A7E84 802795A4 24020002 */   addiu    $v0, $zero, 2
.L802795A8:
/* 1A7E88 802795A8 C622003C */  lwc1      $f2, 0x3c($s1)
/* 1A7E8C 802795AC 44823000 */  mtc1      $v0, $f6
/* 1A7E90 802795B0 00000000 */  nop
/* 1A7E94 802795B4 468031A0 */  cvt.s.w   $f6, $f6
/* 1A7E98 802795B8 46061082 */  mul.s     $f2, $f2, $f6
/* 1A7E9C 802795BC 00000000 */  nop
/* 1A7EA0 802795C0 3C013F00 */  lui       $at, 0x3f00
/* 1A7EA4 802795C4 44810000 */  mtc1      $at, $f0
/* 1A7EA8 802795C8 00000000 */  nop
/* 1A7EAC 802795CC 46001082 */  mul.s     $f2, $f2, $f0
/* 1A7EB0 802795D0 00000000 */  nop
/* 1A7EB4 802795D4 86220064 */  lh        $v0, 0x64($s1)
/* 1A7EB8 802795D8 C6240040 */  lwc1      $f4, 0x40($s1)
/* 1A7EBC 802795DC 44820000 */  mtc1      $v0, $f0
/* 1A7EC0 802795E0 00000000 */  nop
/* 1A7EC4 802795E4 46800020 */  cvt.s.w   $f0, $f0
/* 1A7EC8 802795E8 46004003 */  div.s     $f0, $f8, $f0
/* 1A7ECC 802795EC 46002100 */  add.s     $f4, $f4, $f0
/* 1A7ED0 802795F0 4606F183 */  div.s     $f6, $f30, $f6
/* 1A7ED4 802795F4 46061080 */  add.s     $f2, $f2, $f6
/* 1A7ED8 802795F8 E6240040 */  swc1      $f4, 0x40($s1)
/* 1A7EDC 802795FC E6220044 */  swc1      $f2, 0x44($s1)
/* 1A7EE0 80279600 8E0201AC */  lw        $v0, 0x1ac($s0)
/* 1A7EE4 80279604 10400009 */  beqz      $v0, .L8027962C
/* 1A7EE8 80279608 24020001 */   addiu    $v0, $zero, 1
/* 1A7EEC 8027960C C600014C */  lwc1      $f0, 0x14c($s0)
/* 1A7EF0 80279610 E7A00010 */  swc1      $f0, 0x10($sp)
/* 1A7EF4 80279614 8E0401AC */  lw        $a0, 0x1ac($s0)
/* 1A7EF8 80279618 8E060144 */  lw        $a2, 0x144($s0)
/* 1A7EFC 8027961C 8E070148 */  lw        $a3, 0x148($s0)
/* 1A7F00 80279620 0C052757 */  jal       sfx_play_sound_at_position
/* 1A7F04 80279624 0000282D */   daddu    $a1, $zero, $zero
/* 1A7F08 80279628 24020001 */  addiu     $v0, $zero, 1
.L8027962C:
/* 1A7F0C 8027962C AE420070 */  sw        $v0, 0x70($s2)
.L80279630:
/* 1A7F10 80279630 8E500074 */  lw        $s0, 0x74($s2)
/* 1A7F14 80279634 C6000050 */  lwc1      $f0, 0x50($s0)
/* 1A7F18 80279638 C6040010 */  lwc1      $f4, 0x10($s0)
/* 1A7F1C 8027963C 46000086 */  mov.s     $f2, $f0
/* 1A7F20 80279640 46002101 */  sub.s     $f4, $f4, $f0
/* 1A7F24 80279644 C6000048 */  lwc1      $f0, 0x48($s0)
/* 1A7F28 80279648 46001081 */  sub.s     $f2, $f2, $f0
/* 1A7F2C 8027964C 44800000 */  mtc1      $zero, $f0
/* 1A7F30 80279650 2611000C */  addiu     $s1, $s0, 0xc
/* 1A7F34 80279654 E6040010 */  swc1      $f4, 0x10($s0)
/* 1A7F38 80279658 4602003C */  c.lt.s    $f0, $f2
/* 1A7F3C 8027965C 00000000 */  nop
/* 1A7F40 80279660 45000007 */  bc1f      .L80279680
/* 1A7F44 80279664 E6020050 */   swc1     $f2, 0x50($s0)
/* 1A7F48 80279668 C602001C */  lwc1      $f2, 0x1c($s0)
/* 1A7F4C 8027966C 46002006 */  mov.s     $f0, $f4
/* 1A7F50 80279670 4600103C */  c.lt.s    $f2, $f0
/* 1A7F54 80279674 00000000 */  nop
/* 1A7F58 80279678 45030001 */  bc1tl     .L80279680
/* 1A7F5C 8027967C E6020010 */   swc1     $f2, 0x10($s0)
.L80279680:
/* 1A7F60 80279680 8E250040 */  lw        $a1, 0x40($s1)
/* 1A7F64 80279684 8E260048 */  lw        $a2, 0x48($s1)
/* 1A7F68 80279688 0C09904A */  jal       add_xz_vec3f
/* 1A7F6C 8027968C 0220202D */   daddu    $a0, $s1, $zero
/* 1A7F70 80279690 C6200000 */  lwc1      $f0, ($s1)
/* 1A7F74 80279694 E6000144 */  swc1      $f0, 0x144($s0)
/* 1A7F78 80279698 C6200004 */  lwc1      $f0, 4($s1)
/* 1A7F7C 8027969C E6000148 */  swc1      $f0, 0x148($s0)
/* 1A7F80 802796A0 C6200008 */  lwc1      $f0, 8($s1)
/* 1A7F84 802796A4 E600014C */  swc1      $f0, 0x14c($s0)
/* 1A7F88 802796A8 96220064 */  lhu       $v0, 0x64($s1)
/* 1A7F8C 802796AC 2442FFFF */  addiu     $v0, $v0, -1
/* 1A7F90 802796B0 A6220064 */  sh        $v0, 0x64($s1)
/* 1A7F94 802796B4 00021400 */  sll       $v0, $v0, 0x10
/* 1A7F98 802796B8 1C40000F */  bgtz      $v0, .L802796F8
/* 1A7F9C 802796BC 0000102D */   daddu    $v0, $zero, $zero
/* 1A7FA0 802796C0 C6200048 */  lwc1      $f0, 0x48($s1)
/* 1A7FA4 802796C4 E7A00010 */  swc1      $f0, 0x10($sp)
/* 1A7FA8 802796C8 8E25000C */  lw        $a1, 0xc($s1)
/* 1A7FAC 802796CC 8E260010 */  lw        $a2, 0x10($s1)
/* 1A7FB0 802796D0 8E270014 */  lw        $a3, 0x14($s1)
/* 1A7FB4 802796D4 0C0990BC */  jal       play_movement_dust_effects
/* 1A7FB8 802796D8 24040002 */   addiu    $a0, $zero, 2
/* 1A7FBC 802796DC C620000C */  lwc1      $f0, 0xc($s1)
/* 1A7FC0 802796E0 E6000144 */  swc1      $f0, 0x144($s0)
/* 1A7FC4 802796E4 C6200010 */  lwc1      $f0, 0x10($s1)
/* 1A7FC8 802796E8 E6000148 */  swc1      $f0, 0x148($s0)
/* 1A7FCC 802796EC C6200014 */  lwc1      $f0, 0x14($s1)
/* 1A7FD0 802796F0 24020001 */  addiu     $v0, $zero, 1
/* 1A7FD4 802796F4 E600014C */  swc1      $f0, 0x14c($s0)
.L802796F8:
/* 1A7FD8 802796F8 8FBF0024 */  lw        $ra, 0x24($sp)
/* 1A7FDC 802796FC 8FB20020 */  lw        $s2, 0x20($sp)
/* 1A7FE0 80279700 8FB1001C */  lw        $s1, 0x1c($sp)
/* 1A7FE4 80279704 8FB00018 */  lw        $s0, 0x18($sp)
/* 1A7FE8 80279708 D7BE0050 */  ldc1      $f30, 0x50($sp)
/* 1A7FEC 8027970C D7BC0048 */  ldc1      $f28, 0x48($sp)
/* 1A7FF0 80279710 D7BA0040 */  ldc1      $f26, 0x40($sp)
/* 1A7FF4 80279714 D7B80038 */  ldc1      $f24, 0x38($sp)
/* 1A7FF8 80279718 D7B60030 */  ldc1      $f22, 0x30($sp)
/* 1A7FFC 8027971C D7B40028 */  ldc1      $f20, 0x28($sp)
/* 1A8000 80279720 03E00008 */  jr        $ra
/* 1A8004 80279724 27BD0058 */   addiu    $sp, $sp, 0x58
