.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel player_enter_blue_pipe
/* 10A54C 802E8CCC 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 10A550 802E8CD0 AFBF0020 */  sw    $ra, 0x20($sp)
/* 10A554 802E8CD4 8C850040 */  lw    $a1, 0x40($a0)
/* 10A558 802E8CD8 3C040001 */  lui   $a0, 1
/* 10A55C 802E8CDC 34840002 */  ori   $a0, $a0, 2
/* 10A560 802E8CE0 3C038007 */  lui   $v1, 0x8007
/* 10A564 802E8CE4 8C637410 */  lw    $v1, 0x7410($v1)
/* 10A568 802E8CE8 3C014334 */  lui   $at, 0x4334
/* 10A56C 802E8CEC 44811000 */  mtc1  $at, $f2
/* 10A570 802E8CF0 00031080 */  sll   $v0, $v1, 2
/* 10A574 802E8CF4 00431021 */  addu  $v0, $v0, $v1
/* 10A578 802E8CF8 00021080 */  sll   $v0, $v0, 2
/* 10A57C 802E8CFC 00431023 */  subu  $v0, $v0, $v1
/* 10A580 802E8D00 000218C0 */  sll   $v1, $v0, 3
/* 10A584 802E8D04 00431021 */  addu  $v0, $v0, $v1
/* 10A588 802E8D08 000210C0 */  sll   $v0, $v0, 3
/* 10A58C 802E8D0C 3C01800B */  lui   $at, 0x800b
/* 10A590 802E8D10 00220821 */  addu  $at, $at, $v0
/* 10A594 802E8D14 C4201DEC */  lwc1  $f0, 0x1dec($at)
/* 10A598 802E8D18 24060002 */  addiu $a2, $zero, 2
/* 10A59C 802E8D1C 46020000 */  add.s $f0, $f0, $f2
/* 10A5A0 802E8D20 3C038011 */  lui   $v1, 0x8011
/* 10A5A4 802E8D24 2463EFC8 */  addiu $v1, $v1, -0x1038
/* 10A5A8 802E8D28 24020019 */  addiu $v0, $zero, 0x19
/* 10A5AC 802E8D2C E4600080 */  swc1  $f0, 0x80($v1)
/* 10A5B0 802E8D30 ACA20004 */  sw    $v0, 4($a1)
/* 10A5B4 802E8D34 2402000D */  addiu $v0, $zero, 0xd
/* 10A5B8 802E8D38 A06200BE */  sb    $v0, 0xbe($v1)
/* 10A5BC 802E8D3C 24020001 */  addiu $v0, $zero, 1
/* 10A5C0 802E8D40 24050005 */  addiu $a1, $zero, 5
/* 10A5C4 802E8D44 0040382D */  daddu $a3, $v0, $zero
/* 10A5C8 802E8D48 AFA20010 */  sw    $v0, 0x10($sp)
/* 10A5CC 802E8D4C AFA00014 */  sw    $zero, 0x14($sp)
/* 10A5D0 802E8D50 0C0B77FE */  jal   func_802DDFF8
/* 10A5D4 802E8D54 AFA00018 */   sw    $zero, 0x18($sp)
/* 10A5D8 802E8D58 0C05272D */  jal   play_sound
/* 10A5DC 802E8D5C 24040163 */   addiu $a0, $zero, 0x163
/* 10A5E0 802E8D60 0C038039 */  jal   disable_player_shadow
/* 10A5E4 802E8D64 00000000 */   nop   
/* 10A5E8 802E8D68 8FBF0020 */  lw    $ra, 0x20($sp)
/* 10A5EC 802E8D6C 03E00008 */  jr    $ra
/* 10A5F0 802E8D70 27BD0028 */   addiu $sp, $sp, 0x28

/* 10A5F4 802E8D74 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 10A5F8 802E8D78 3C058011 */  lui   $a1, 0x8011
/* 10A5FC 802E8D7C 24A5EFC8 */  addiu $a1, $a1, -0x1038
/* 10A600 802E8D80 AFBF0024 */  sw    $ra, 0x24($sp)
/* 10A604 802E8D84 AFB00020 */  sw    $s0, 0x20($sp)
/* 10A608 802E8D88 C4A0002C */  lwc1  $f0, 0x2c($a1)
/* 10A60C 802E8D8C 3C013F80 */  lui   $at, 0x3f80
/* 10A610 802E8D90 44811000 */  mtc1  $at, $f2
/* 10A614 802E8D94 0080802D */  daddu $s0, $a0, $zero
/* 10A618 802E8D98 46020001 */  sub.s $f0, $f0, $f2
/* 10A61C 802E8D9C 8E030040 */  lw    $v1, 0x40($s0)
/* 10A620 802E8DA0 E4A0002C */  swc1  $f0, 0x2c($a1)
/* 10A624 802E8DA4 8C620004 */  lw    $v0, 4($v1)
/* 10A628 802E8DA8 2442FFFF */  addiu $v0, $v0, -1
/* 10A62C 802E8DAC AC620004 */  sw    $v0, 4($v1)
/* 10A630 802E8DB0 2403FFFF */  addiu $v1, $zero, -1
/* 10A634 802E8DB4 14430012 */  bne   $v0, $v1, .L802E8E00
/* 10A638 802E8DB8 2402000D */   addiu $v0, $zero, 0xd
/* 10A63C 802E8DBC 3C040001 */  lui   $a0, 1
/* 10A640 802E8DC0 34840002 */  ori   $a0, $a0, 2
/* 10A644 802E8DC4 C4A0002C */  lwc1  $f0, 0x2c($a1)
/* 10A648 802E8DC8 3C014248 */  lui   $at, 0x4248
/* 10A64C 802E8DCC 44811000 */  mtc1  $at, $f2
/* 10A650 802E8DD0 A0A200BE */  sb    $v0, 0xbe($a1)
/* 10A654 802E8DD4 AFA00010 */  sw    $zero, 0x10($sp)
/* 10A658 802E8DD8 46020001 */  sub.s $f0, $f0, $f2
/* 10A65C 802E8DDC AFA00014 */  sw    $zero, 0x14($sp)
/* 10A660 802E8DE0 AFA00018 */  sw    $zero, 0x18($sp)
/* 10A664 802E8DE4 E4A0002C */  swc1  $f0, 0x2c($a1)
/* 10A668 802E8DE8 0000282D */  daddu $a1, $zero, $zero
/* 10A66C 802E8DEC 00A0302D */  daddu $a2, $a1, $zero
/* 10A670 802E8DF0 0C0B77FE */  jal   func_802DDFF8
/* 10A674 802E8DF4 00A0382D */   daddu $a3, $a1, $zero
/* 10A678 802E8DF8 0C043F5A */  jal   func_8010FD68
/* 10A67C 802E8DFC 0200202D */   daddu $a0, $s0, $zero
.L802E8E00:
/* 10A680 802E8E00 8FBF0024 */  lw    $ra, 0x24($sp)
/* 10A684 802E8E04 8FB00020 */  lw    $s0, 0x20($sp)
/* 10A688 802E8E08 03E00008 */  jr    $ra
/* 10A68C 802E8E0C 27BD0028 */   addiu $sp, $sp, 0x28

/* 10A690 802E8E10 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 10A694 802E8E14 3C05800A */  lui   $a1, 0x800a
/* 10A698 802E8E18 24A5A650 */  addiu $a1, $a1, -0x59b0
/* 10A69C 802E8E1C 2406FFBF */  addiu $a2, $zero, -0x41
/* 10A6A0 802E8E20 AFBF0010 */  sw    $ra, 0x10($sp)
/* 10A6A4 802E8E24 8C830040 */  lw    $v1, 0x40($a0)
/* 10A6A8 802E8E28 8CA20000 */  lw    $v0, ($a1)
/* 10A6AC 802E8E2C 8C630010 */  lw    $v1, 0x10($v1)
/* 10A6B0 802E8E30 00461024 */  and   $v0, $v0, $a2
/* 10A6B4 802E8E34 ACA20000 */  sw    $v0, ($a1)
/* 10A6B8 802E8E38 0C04419E */  jal   func_80110678
/* 10A6BC 802E8E3C AC830028 */   sw    $v1, 0x28($a0)
/* 10A6C0 802E8E40 8FBF0010 */  lw    $ra, 0x10($sp)
/* 10A6C4 802E8E44 03E00008 */  jr    $ra
/* 10A6C8 802E8E48 27BD0018 */   addiu $sp, $sp, 0x18

