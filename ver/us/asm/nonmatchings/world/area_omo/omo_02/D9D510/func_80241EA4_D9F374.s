.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241EA4_D9F374
/* D9F374 80241EA4 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* D9F378 80241EA8 AFB7004C */  sw        $s7, 0x4c($sp)
/* D9F37C 80241EAC 0080B82D */  daddu     $s7, $a0, $zero
/* D9F380 80241EB0 AFB10034 */  sw        $s1, 0x34($sp)
/* D9F384 80241EB4 00A0882D */  daddu     $s1, $a1, $zero
/* D9F388 80241EB8 AFBF0050 */  sw        $ra, 0x50($sp)
/* D9F38C 80241EBC AFB60048 */  sw        $s6, 0x48($sp)
/* D9F390 80241EC0 AFB50044 */  sw        $s5, 0x44($sp)
/* D9F394 80241EC4 AFB40040 */  sw        $s4, 0x40($sp)
/* D9F398 80241EC8 AFB3003C */  sw        $s3, 0x3c($sp)
/* D9F39C 80241ECC AFB20038 */  sw        $s2, 0x38($sp)
/* D9F3A0 80241ED0 AFB00030 */  sw        $s0, 0x30($sp)
/* D9F3A4 80241ED4 8EF30148 */  lw        $s3, 0x148($s7)
/* D9F3A8 80241ED8 86640008 */  lh        $a0, 8($s3)
/* D9F3AC 80241EDC 8EF0000C */  lw        $s0, 0xc($s7)
/* D9F3B0 80241EE0 0C00FB5A */  jal       get_enemy_safe
/* D9F3B4 80241EE4 0000B02D */   daddu    $s6, $zero, $zero
/* D9F3B8 80241EE8 10400131 */  beqz      $v0, .L802423B0
/* D9F3BC 80241EEC 24020005 */   addiu    $v0, $zero, 5
/* D9F3C0 80241EF0 8E63006C */  lw        $v1, 0x6c($s3)
/* D9F3C4 80241EF4 1062012F */  beq       $v1, $v0, .L802423B4
/* D9F3C8 80241EF8 0000102D */   daddu    $v0, $zero, $zero
/* D9F3CC 80241EFC 8E050000 */  lw        $a1, ($s0)
/* D9F3D0 80241F00 0C0B1EAF */  jal       get_variable
/* D9F3D4 80241F04 02E0202D */   daddu    $a0, $s7, $zero
/* D9F3D8 80241F08 86640008 */  lh        $a0, 8($s3)
/* D9F3DC 80241F0C 0C00EABB */  jal       get_npc_unsafe
/* D9F3E0 80241F10 0040A82D */   daddu    $s5, $v0, $zero
/* D9F3E4 80241F14 8E630070 */  lw        $v1, 0x70($s3)
/* D9F3E8 80241F18 30630002 */  andi      $v1, $v1, 2
/* D9F3EC 80241F1C 10600008 */  beqz      $v1, .L80241F40
/* D9F3F0 80241F20 0040902D */   daddu    $s2, $v0, $zero
/* D9F3F4 80241F24 964200A8 */  lhu       $v0, 0xa8($s2)
/* D9F3F8 80241F28 00021400 */  sll       $v0, $v0, 0x10
/* D9F3FC 80241F2C 00021C03 */  sra       $v1, $v0, 0x10
/* D9F400 80241F30 000217C2 */  srl       $v0, $v0, 0x1f
/* D9F404 80241F34 00621821 */  addu      $v1, $v1, $v0
/* D9F408 80241F38 00031843 */  sra       $v1, $v1, 1
/* D9F40C 80241F3C A24300AB */  sb        $v1, 0xab($s2)
.L80241F40:
/* D9F410 80241F40 16200005 */  bnez      $s1, .L80241F58
/* D9F414 80241F44 3C030004 */   lui      $v1, 4
/* D9F418 80241F48 8E6200B0 */  lw        $v0, 0xb0($s3)
/* D9F41C 80241F4C 30420004 */  andi      $v0, $v0, 4
/* D9F420 80241F50 10400019 */  beqz      $v0, .L80241FB8
/* D9F424 80241F54 00000000 */   nop
.L80241F58:
/* D9F428 80241F58 34630102 */  ori       $v1, $v1, 0x102
/* D9F42C 80241F5C AEE00070 */  sw        $zero, 0x70($s7)
/* D9F430 80241F60 8E420000 */  lw        $v0, ($s2)
/* D9F434 80241F64 0240202D */  daddu     $a0, $s2, $zero
/* D9F438 80241F68 A640008E */  sh        $zero, 0x8e($s2)
/* D9F43C 80241F6C 00431025 */  or        $v0, $v0, $v1
/* D9F440 80241F70 0C00EAFF */  jal       disable_npc_shadow
/* D9F444 80241F74 AE420000 */   sw       $v0, ($s2)
/* D9F448 80241F78 3C041F30 */  lui       $a0, 0x1f30
/* D9F44C 80241F7C 8E420000 */  lw        $v0, ($s2)
/* D9F450 80241F80 2403F7FF */  addiu     $v1, $zero, -0x801
/* D9F454 80241F84 00431024 */  and       $v0, $v0, $v1
/* D9F458 80241F88 AE420000 */  sw        $v0, ($s2)
/* D9F45C 80241F8C 8E620000 */  lw        $v0, ($s3)
/* D9F460 80241F90 8E6300B0 */  lw        $v1, 0xb0($s3)
/* D9F464 80241F94 34840040 */  ori       $a0, $a0, 0x40
/* D9F468 80241F98 AE60006C */  sw        $zero, 0x6c($s3)
/* D9F46C 80241F9C 00441025 */  or        $v0, $v0, $a0
/* D9F470 80241FA0 AE620000 */  sw        $v0, ($s3)
/* D9F474 80241FA4 30620004 */  andi      $v0, $v1, 4
/* D9F478 80241FA8 10400003 */  beqz      $v0, .L80241FB8
/* D9F47C 80241FAC 2402FFFB */   addiu    $v0, $zero, -5
/* D9F480 80241FB0 00621024 */  and       $v0, $v1, $v0
/* D9F484 80241FB4 AE6200B0 */  sw        $v0, 0xb0($s3)
.L80241FB8:
/* D9F488 80241FB8 8EE30070 */  lw        $v1, 0x70($s7)
/* D9F48C 80241FBC 24100001 */  addiu     $s0, $zero, 1
/* D9F490 80241FC0 10700012 */  beq       $v1, $s0, .L8024200C
/* D9F494 80241FC4 28620002 */   slti     $v0, $v1, 2
/* D9F498 80241FC8 10400005 */  beqz      $v0, .L80241FE0
/* D9F49C 80241FCC 24020002 */   addiu    $v0, $zero, 2
/* D9F4A0 80241FD0 10600007 */  beqz      $v1, .L80241FF0
/* D9F4A4 80241FD4 0000102D */   daddu    $v0, $zero, $zero
/* D9F4A8 80241FD8 080908ED */  j         .L802423B4
/* D9F4AC 80241FDC 00000000 */   nop
.L80241FE0:
/* D9F4B0 80241FE0 1062005B */  beq       $v1, $v0, .L80242150
/* D9F4B4 80241FE4 0000102D */   daddu    $v0, $zero, $zero
/* D9F4B8 80241FE8 080908ED */  j         .L802423B4
/* D9F4BC 80241FEC 00000000 */   nop
.L80241FF0:
/* D9F4C0 80241FF0 8E420000 */  lw        $v0, ($s2)
/* D9F4C4 80241FF4 0240202D */  daddu     $a0, $s2, $zero
/* D9F4C8 80241FF8 34420002 */  ori       $v0, $v0, 2
/* D9F4CC 80241FFC 0C00EAFF */  jal       disable_npc_shadow
/* D9F4D0 80242000 AE420000 */   sw       $v0, ($s2)
/* D9F4D4 80242004 AE60006C */  sw        $zero, 0x6c($s3)
/* D9F4D8 80242008 AEF00070 */  sw        $s0, 0x70($s7)
.L8024200C:
/* D9F4DC 8024200C 8E74006C */  lw        $s4, 0x6c($s3)
/* D9F4E0 80242010 24020001 */  addiu     $v0, $zero, 1
/* D9F4E4 80242014 168200E7 */  bne       $s4, $v0, .L802423B4
/* D9F4E8 80242018 0000102D */   daddu    $v0, $zero, $zero
/* D9F4EC 8024201C 8E64007C */  lw        $a0, 0x7c($s3)
/* D9F4F0 80242020 24110002 */  addiu     $s1, $zero, 2
/* D9F4F4 80242024 0C00EABB */  jal       get_npc_unsafe
/* D9F4F8 80242028 AE71006C */   sw       $s1, 0x6c($s3)
/* D9F4FC 8024202C 0040802D */  daddu     $s0, $v0, $zero
/* D9F500 80242030 C6000038 */  lwc1      $f0, 0x38($s0)
/* D9F504 80242034 E6400038 */  swc1      $f0, 0x38($s2)
/* D9F508 80242038 C6000040 */  lwc1      $f0, 0x40($s0)
/* D9F50C 8024203C E6400040 */  swc1      $f0, 0x40($s2)
/* D9F510 80242040 C6020034 */  lwc1      $f2, 0x34($s0)
/* D9F514 80242044 3C014387 */  lui       $at, 0x4387
/* D9F518 80242048 44810000 */  mtc1      $at, $f0
/* D9F51C 8024204C 26440038 */  addiu     $a0, $s2, 0x38
/* D9F520 80242050 46020001 */  sub.s     $f0, $f0, $f2
/* D9F524 80242054 C6680078 */  lwc1      $f8, 0x78($s3)
/* D9F528 80242058 46804220 */  cvt.s.w   $f8, $f8
/* D9F52C 8024205C 44064000 */  mfc1      $a2, $f8
/* D9F530 80242060 44070000 */  mfc1      $a3, $f0
/* D9F534 80242064 0C00A7E7 */  jal       add_vec2D_polar
/* D9F538 80242068 26450040 */   addiu    $a1, $s2, 0x40
/* D9F53C 8024206C C600003C */  lwc1      $f0, 0x3c($s0)
/* D9F540 80242070 C6620074 */  lwc1      $f2, 0x74($s3)
/* D9F544 80242074 468010A0 */  cvt.s.w   $f2, $f2
/* D9F548 80242078 46020000 */  add.s     $f0, $f0, $f2
/* D9F54C 8024207C E640003C */  swc1      $f0, 0x3c($s2)
/* D9F550 80242080 A2740007 */  sb        $s4, 7($s3)
/* D9F554 80242084 C6400038 */  lwc1      $f0, 0x38($s2)
/* D9F558 80242088 4600020D */  trunc.w.s $f8, $f0
/* D9F55C 8024208C 44024000 */  mfc1      $v0, $f8
/* D9F560 80242090 00000000 */  nop
/* D9F564 80242094 A6620010 */  sh        $v0, 0x10($s3)
/* D9F568 80242098 C640003C */  lwc1      $f0, 0x3c($s2)
/* D9F56C 8024209C 4600020D */  trunc.w.s $f8, $f0
/* D9F570 802420A0 44024000 */  mfc1      $v0, $f8
/* D9F574 802420A4 00000000 */  nop
/* D9F578 802420A8 A6620012 */  sh        $v0, 0x12($s3)
/* D9F57C 802420AC C6400040 */  lwc1      $f0, 0x40($s2)
/* D9F580 802420B0 4600020D */  trunc.w.s $f8, $f0
/* D9F584 802420B4 44024000 */  mfc1      $v0, $f8
/* D9F588 802420B8 00000000 */  nop
/* D9F58C 802420BC A6620014 */  sh        $v0, 0x14($s3)
/* D9F590 802420C0 AE400044 */  sw        $zero, 0x44($s2)
/* D9F594 802420C4 AE400048 */  sw        $zero, 0x48($s2)
/* D9F598 802420C8 AE40004C */  sw        $zero, 0x4c($s2)
/* D9F59C 802420CC C6A00000 */  lwc1      $f0, ($s5)
/* D9F5A0 802420D0 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* D9F5A4 802420D4 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* D9F5A8 802420D8 C64C0038 */  lwc1      $f12, 0x38($s2)
/* D9F5AC 802420DC C64E0040 */  lwc1      $f14, 0x40($s2)
/* D9F5B0 802420E0 E6400018 */  swc1      $f0, 0x18($s2)
/* D9F5B4 802420E4 8C460028 */  lw        $a2, 0x28($v0)
/* D9F5B8 802420E8 0C00A720 */  jal       atan2
/* D9F5BC 802420EC 8C470030 */   lw       $a3, 0x30($v0)
/* D9F5C0 802420F0 E640000C */  swc1      $f0, 0xc($s2)
/* D9F5C4 802420F4 C6A0000C */  lwc1      $f0, 0xc($s5)
/* D9F5C8 802420F8 8E420000 */  lw        $v0, ($s2)
/* D9F5CC 802420FC 0240202D */  daddu     $a0, $s2, $zero
/* D9F5D0 80242100 E640001C */  swc1      $f0, 0x1c($s2)
/* D9F5D4 80242104 C6A00010 */  lwc1      $f0, 0x10($s5)
/* D9F5D8 80242108 2403FFFD */  addiu     $v1, $zero, -3
/* D9F5DC 8024210C E6400014 */  swc1      $f0, 0x14($s2)
/* D9F5E0 80242110 C600003C */  lwc1      $f0, 0x3c($s0)
/* D9F5E4 80242114 00431024 */  and       $v0, $v0, $v1
/* D9F5E8 80242118 AE420000 */  sw        $v0, ($s2)
/* D9F5EC 8024211C 0C00EAE8 */  jal       enable_npc_shadow
/* D9F5F0 80242120 E6400064 */   swc1     $f0, 0x64($s2)
/* D9F5F4 80242124 8E420000 */  lw        $v0, ($s2)
/* D9F5F8 80242128 3C03E0FF */  lui       $v1, 0xe0ff
/* D9F5FC 8024212C 34420800 */  ori       $v0, $v0, 0x800
/* D9F600 80242130 AE420000 */  sw        $v0, ($s2)
/* D9F604 80242134 8E620000 */  lw        $v0, ($s3)
/* D9F608 80242138 3463FFFF */  ori       $v1, $v1, 0xffff
/* D9F60C 8024213C 00431024 */  and       $v0, $v0, $v1
/* D9F610 80242140 AE620000 */  sw        $v0, ($s3)
/* D9F614 80242144 2402005A */  addiu     $v0, $zero, 0x5a
/* D9F618 80242148 A642008E */  sh        $v0, 0x8e($s2)
/* D9F61C 8024214C AEF10070 */  sw        $s1, 0x70($s7)
.L80242150:
/* D9F620 80242150 0000202D */  daddu     $a0, $zero, $zero
/* D9F624 80242154 27B00020 */  addiu     $s0, $sp, 0x20
/* D9F628 80242158 864200A8 */  lh        $v0, 0xa8($s2)
/* D9F62C 8024215C 3C013FE0 */  lui       $at, 0x3fe0
/* D9F630 80242160 44810800 */  mtc1      $at, $f1
/* D9F634 80242164 44800000 */  mtc1      $zero, $f0
/* D9F638 80242168 44821000 */  mtc1      $v0, $f2
/* D9F63C 8024216C 00000000 */  nop
/* D9F640 80242170 468010A1 */  cvt.d.w   $f2, $f2
/* D9F644 80242174 46201082 */  mul.d     $f2, $f2, $f0
/* D9F648 80242178 00000000 */  nop
/* D9F64C 8024217C 0200282D */  daddu     $a1, $s0, $zero
/* D9F650 80242180 C6440038 */  lwc1      $f4, 0x38($s2)
/* D9F654 80242184 C640003C */  lwc1      $f0, 0x3c($s2)
/* D9F658 80242188 27B10024 */  addiu     $s1, $sp, 0x24
/* D9F65C 8024218C E7A40020 */  swc1      $f4, 0x20($sp)
/* D9F660 80242190 C6440040 */  lwc1      $f4, 0x40($s2)
/* D9F664 80242194 46000021 */  cvt.d.s   $f0, $f0
/* D9F668 80242198 46220000 */  add.d     $f0, $f0, $f2
/* D9F66C 8024219C E7A40028 */  swc1      $f4, 0x28($sp)
/* D9F670 802421A0 C6420018 */  lwc1      $f2, 0x18($s2)
/* D9F674 802421A4 46200020 */  cvt.s.d   $f0, $f0
/* D9F678 802421A8 E7A00024 */  swc1      $f0, 0x24($sp)
/* D9F67C 802421AC E7A20010 */  swc1      $f2, 0x10($sp)
/* D9F680 802421B0 C640000C */  lwc1      $f0, 0xc($s2)
/* D9F684 802421B4 0220302D */  daddu     $a2, $s1, $zero
/* D9F688 802421B8 E7A00014 */  swc1      $f0, 0x14($sp)
/* D9F68C 802421BC 864200A6 */  lh        $v0, 0xa6($s2)
/* D9F690 802421C0 27B40028 */  addiu     $s4, $sp, 0x28
/* D9F694 802421C4 44820000 */  mtc1      $v0, $f0
/* D9F698 802421C8 00000000 */  nop
/* D9F69C 802421CC 46800020 */  cvt.s.w   $f0, $f0
/* D9F6A0 802421D0 E7A00018 */  swc1      $f0, 0x18($sp)
/* D9F6A4 802421D4 864200A8 */  lh        $v0, 0xa8($s2)
/* D9F6A8 802421D8 0280382D */  daddu     $a3, $s4, $zero
/* D9F6AC 802421DC 44820000 */  mtc1      $v0, $f0
/* D9F6B0 802421E0 00000000 */  nop
/* D9F6B4 802421E4 46800020 */  cvt.s.w   $f0, $f0
/* D9F6B8 802421E8 0C0376B9 */  jal       npc_test_move_taller_with_slipping
/* D9F6BC 802421EC E7A0001C */   swc1     $f0, 0x1c($sp)
/* D9F6C0 802421F0 54400001 */  bnel      $v0, $zero, .L802421F8
/* D9F6C4 802421F4 24160001 */   addiu    $s6, $zero, 1
.L802421F8:
/* D9F6C8 802421F8 0200282D */  daddu     $a1, $s0, $zero
/* D9F6CC 802421FC 0220302D */  daddu     $a2, $s1, $zero
/* D9F6D0 80242200 C6400038 */  lwc1      $f0, 0x38($s2)
/* D9F6D4 80242204 C642003C */  lwc1      $f2, 0x3c($s2)
/* D9F6D8 80242208 C6440040 */  lwc1      $f4, 0x40($s2)
/* D9F6DC 8024220C 3C01447A */  lui       $at, 0x447a
/* D9F6E0 80242210 44813000 */  mtc1      $at, $f6
/* D9F6E4 80242214 27A2002C */  addiu     $v0, $sp, 0x2c
/* D9F6E8 80242218 E7A00020 */  swc1      $f0, 0x20($sp)
/* D9F6EC 8024221C E7A20024 */  swc1      $f2, 0x24($sp)
/* D9F6F0 80242220 E7A40028 */  swc1      $f4, 0x28($sp)
/* D9F6F4 80242224 E7A6002C */  swc1      $f6, 0x2c($sp)
/* D9F6F8 80242228 AFA20010 */  sw        $v0, 0x10($sp)
/* D9F6FC 8024222C 8E440080 */  lw        $a0, 0x80($s2)
/* D9F700 80242230 0C0372DF */  jal       npc_raycast_down_sides
/* D9F704 80242234 0280382D */   daddu    $a3, $s4, $zero
/* D9F708 80242238 10400019 */  beqz      $v0, .L802422A0
/* D9F70C 8024223C 00000000 */   nop
/* D9F710 80242240 C640001C */  lwc1      $f0, 0x1c($s2)
/* D9F714 80242244 C7A2002C */  lwc1      $f2, 0x2c($sp)
/* D9F718 80242248 46000005 */  abs.s     $f0, $f0
/* D9F71C 8024224C 4600103C */  c.lt.s    $f2, $f0
/* D9F720 80242250 00000000 */  nop
/* D9F724 80242254 45000012 */  bc1f      .L802422A0
/* D9F728 80242258 00000000 */   nop
/* D9F72C 8024225C C7A40024 */  lwc1      $f4, 0x24($sp)
/* D9F730 80242260 C6400064 */  lwc1      $f0, 0x64($s2)
/* D9F734 80242264 46002001 */  sub.s     $f0, $f4, $f0
/* D9F738 80242268 3C014034 */  lui       $at, 0x4034
/* D9F73C 8024226C 44811800 */  mtc1      $at, $f3
/* D9F740 80242270 44801000 */  mtc1      $zero, $f2
/* D9F744 80242274 46000005 */  abs.s     $f0, $f0
/* D9F748 80242278 46000021 */  cvt.d.s   $f0, $f0
/* D9F74C 8024227C 4622003C */  c.lt.d    $f0, $f2
/* D9F750 80242280 00000000 */  nop
/* D9F754 80242284 45000006 */  bc1f      .L802422A0
/* D9F758 80242288 0240202D */   daddu    $a0, $s2, $zero
/* D9F75C 8024228C 8E450018 */  lw        $a1, 0x18($s2)
/* D9F760 80242290 8E46000C */  lw        $a2, 0xc($s2)
/* D9F764 80242294 2416000A */  addiu     $s6, $zero, 0xa
/* D9F768 80242298 0C00EA95 */  jal       npc_move_heading
/* D9F76C 8024229C E644003C */   swc1     $f4, 0x3c($s2)
.L802422A0:
/* D9F770 802422A0 C7A0002C */  lwc1      $f0, 0x2c($sp)
/* D9F774 802422A4 3C013FF0 */  lui       $at, 0x3ff0
/* D9F778 802422A8 44811800 */  mtc1      $at, $f3
/* D9F77C 802422AC 44801000 */  mtc1      $zero, $f2
/* D9F780 802422B0 46000021 */  cvt.d.s   $f0, $f0
/* D9F784 802422B4 4622003C */  c.lt.d    $f0, $f2
/* D9F788 802422B8 00000000 */  nop
/* D9F78C 802422BC 45030001 */  bc1tl     .L802422C4
/* D9F790 802422C0 2416000B */   addiu    $s6, $zero, 0xb
.L802422C4:
/* D9F794 802422C4 9642008E */  lhu       $v0, 0x8e($s2)
/* D9F798 802422C8 2442FFFF */  addiu     $v0, $v0, -1
/* D9F79C 802422CC A642008E */  sh        $v0, 0x8e($s2)
/* D9F7A0 802422D0 00021400 */  sll       $v0, $v0, 0x10
/* D9F7A4 802422D4 58400001 */  blezl     $v0, .L802422DC
/* D9F7A8 802422D8 24160014 */   addiu    $s6, $zero, 0x14
.L802422DC:
/* D9F7AC 802422DC 56C00019 */  bnel      $s6, $zero, .L80242344
/* D9F7B0 802422E0 AFA00010 */   sw       $zero, 0x10($sp)
/* D9F7B4 802422E4 8E620070 */  lw        $v0, 0x70($s3)
/* D9F7B8 802422E8 30420001 */  andi      $v0, $v0, 1
/* D9F7BC 802422EC 10400009 */  beqz      $v0, .L80242314
/* D9F7C0 802422F0 00000000 */   nop
/* D9F7C4 802422F4 C640004C */  lwc1      $f0, 0x4c($s2)
/* D9F7C8 802422F8 3C014044 */  lui       $at, 0x4044
/* D9F7CC 802422FC 44811800 */  mtc1      $at, $f3
/* D9F7D0 80242300 44801000 */  mtc1      $zero, $f2
/* D9F7D4 80242304 46000021 */  cvt.d.s   $f0, $f0
/* D9F7D8 80242308 46220000 */  add.d     $f0, $f0, $f2
/* D9F7DC 8024230C 46200020 */  cvt.s.d   $f0, $f0
/* D9F7E0 80242310 E640004C */  swc1      $f0, 0x4c($s2)
.L80242314:
/* D9F7E4 80242314 8E450018 */  lw        $a1, 0x18($s2)
/* D9F7E8 80242318 8E46000C */  lw        $a2, 0xc($s2)
/* D9F7EC 8024231C 0C00EA95 */  jal       npc_move_heading
/* D9F7F0 80242320 0240202D */   daddu    $a0, $s2, $zero
/* D9F7F4 80242324 C644003C */  lwc1      $f4, 0x3c($s2)
/* D9F7F8 80242328 C640001C */  lwc1      $f0, 0x1c($s2)
/* D9F7FC 8024232C 46002100 */  add.s     $f4, $f4, $f0
/* D9F800 80242330 C6420014 */  lwc1      $f2, 0x14($s2)
/* D9F804 80242334 46020001 */  sub.s     $f0, $f0, $f2
/* D9F808 80242338 E644003C */  swc1      $f4, 0x3c($s2)
/* D9F80C 8024233C 080908EC */  j         .L802423B0
/* D9F810 80242340 E640001C */   swc1     $f0, 0x1c($s2)
.L80242344:
/* D9F814 80242344 AFA00014 */  sw        $zero, 0x14($sp)
/* D9F818 80242348 8E450038 */  lw        $a1, 0x38($s2)
/* D9F81C 8024234C 8E46003C */  lw        $a2, 0x3c($s2)
/* D9F820 80242350 8E470040 */  lw        $a3, 0x40($s2)
/* D9F824 80242354 0C01BECC */  jal       fx_walk
/* D9F828 80242358 24040002 */   addiu    $a0, $zero, 2
/* D9F82C 8024235C 3C01C47A */  lui       $at, 0xc47a
/* D9F830 80242360 44810000 */  mtc1      $at, $f0
/* D9F834 80242364 AE60006C */  sw        $zero, 0x6c($s3)
/* D9F838 80242368 8E420000 */  lw        $v0, ($s2)
/* D9F83C 8024236C 0240202D */  daddu     $a0, $s2, $zero
/* D9F840 80242370 AE400038 */  sw        $zero, 0x38($s2)
/* D9F844 80242374 AE400040 */  sw        $zero, 0x40($s2)
/* D9F848 80242378 AE40001C */  sw        $zero, 0x1c($s2)
/* D9F84C 8024237C 34420002 */  ori       $v0, $v0, 2
/* D9F850 80242380 E640003C */  swc1      $f0, 0x3c($s2)
/* D9F854 80242384 0C00EAFF */  jal       disable_npc_shadow
/* D9F858 80242388 AE420000 */   sw       $v0, ($s2)
/* D9F85C 8024238C 8E420000 */  lw        $v0, ($s2)
/* D9F860 80242390 2403F7FF */  addiu     $v1, $zero, -0x801
/* D9F864 80242394 00431024 */  and       $v0, $v0, $v1
/* D9F868 80242398 AE420000 */  sw        $v0, ($s2)
/* D9F86C 8024239C 8E620000 */  lw        $v0, ($s3)
/* D9F870 802423A0 3C031F00 */  lui       $v1, 0x1f00
/* D9F874 802423A4 00431025 */  or        $v0, $v0, $v1
/* D9F878 802423A8 AE620000 */  sw        $v0, ($s3)
/* D9F87C 802423AC AEE00070 */  sw        $zero, 0x70($s7)
.L802423B0:
/* D9F880 802423B0 0000102D */  daddu     $v0, $zero, $zero
.L802423B4:
/* D9F884 802423B4 8FBF0050 */  lw        $ra, 0x50($sp)
/* D9F888 802423B8 8FB7004C */  lw        $s7, 0x4c($sp)
/* D9F88C 802423BC 8FB60048 */  lw        $s6, 0x48($sp)
/* D9F890 802423C0 8FB50044 */  lw        $s5, 0x44($sp)
/* D9F894 802423C4 8FB40040 */  lw        $s4, 0x40($sp)
/* D9F898 802423C8 8FB3003C */  lw        $s3, 0x3c($sp)
/* D9F89C 802423CC 8FB20038 */  lw        $s2, 0x38($sp)
/* D9F8A0 802423D0 8FB10034 */  lw        $s1, 0x34($sp)
/* D9F8A4 802423D4 8FB00030 */  lw        $s0, 0x30($sp)
/* D9F8A8 802423D8 03E00008 */  jr        $ra
/* D9F8AC 802423DC 27BD0058 */   addiu    $sp, $sp, 0x58
