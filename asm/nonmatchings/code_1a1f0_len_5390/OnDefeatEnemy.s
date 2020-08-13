.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel OnDefeatEnemy
/* 01A980 8003F580 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 01A984 8003F584 AFB20028 */  sw    $s2, 0x28($sp)
/* 01A988 8003F588 0080902D */  daddu $s2, $a0, $zero
/* 01A98C 8003F58C AFBF0030 */  sw    $ra, 0x30($sp)
/* 01A990 8003F590 AFB3002C */  sw    $s3, 0x2c($sp)
/* 01A994 8003F594 AFB10024 */  sw    $s1, 0x24($sp)
/* 01A998 8003F598 AFB00020 */  sw    $s0, 0x20($sp)
/* 01A99C 8003F59C 8E530148 */  lw    $s3, 0x148($s2)
/* 01A9A0 8003F5A0 86640008 */  lh    $a0, 8($s3)
/* 01A9A4 8003F5A4 0C00EABB */  jal   get_npc_unsafe
/* 01A9A8 8003F5A8 00A0802D */   daddu $s0, $a1, $zero
/* 01A9AC 8003F5AC 12000004 */  beqz  $s0, .L8003F5C0
/* 01A9B0 8003F5B0 0040882D */   daddu $s1, $v0, $zero
/* 01A9B4 8003F5B4 24020014 */  addiu $v0, $zero, 0x14
/* 01A9B8 8003F5B8 AE400070 */  sw    $zero, 0x70($s2)
/* 01A9BC 8003F5BC AE420074 */  sw    $v0, 0x74($s2)
.L8003F5C0:
/* 01A9C0 8003F5C0 8E420074 */  lw    $v0, 0x74($s2)
/* 01A9C4 8003F5C4 30420001 */  andi  $v0, $v0, 1
/* 01A9C8 8003F5C8 10400004 */  beqz  $v0, .L8003F5DC
/* 01A9CC 8003F5CC 2403FFFD */   addiu $v1, $zero, -3
/* 01A9D0 8003F5D0 8E220000 */  lw    $v0, ($s1)
/* 01A9D4 8003F5D4 0800FD79 */  j     .L8003F5E4
/* 01A9D8 8003F5D8 00431024 */   and   $v0, $v0, $v1

.L8003F5DC:
/* 01A9DC 8003F5DC 8E220000 */  lw    $v0, ($s1)
/* 01A9E0 8003F5E0 34420002 */  ori   $v0, $v0, 2
.L8003F5E4:
/* 01A9E4 8003F5E4 AE220000 */  sw    $v0, ($s1)
/* 01A9E8 8003F5E8 8E430074 */  lw    $v1, 0x74($s2)
/* 01A9EC 8003F5EC 2402000F */  addiu $v0, $zero, 0xf
/* 01A9F0 8003F5F0 1462001A */  bne   $v1, $v0, .L8003F65C
/* 01A9F4 8003F5F4 00000000 */   nop   
/* 01A9F8 8003F5F8 0C05272D */  jal   play_sound
/* 01A9FC 8003F5FC 240403E5 */   addiu $a0, $zero, 0x3e5
/* 01AA00 8003F600 962300A8 */  lhu   $v1, 0xa8($s1)
/* 01AA04 8003F604 C624003C */  lwc1  $f4, 0x3c($s1)
/* 01AA08 8003F608 3C01BF80 */  lui   $at, 0xbf80
/* 01AA0C 8003F60C 44811000 */  mtc1  $at, $f2
/* 01AA10 8003F610 2402000A */  addiu $v0, $zero, 0xa
/* 01AA14 8003F614 AFA00010 */  sw    $zero, 0x10($sp)
/* 01AA18 8003F618 AFA00018 */  sw    $zero, 0x18($sp)
/* 01AA1C 8003F61C AFA2001C */  sw    $v0, 0x1c($sp)
/* 01AA20 8003F620 00031C00 */  sll   $v1, $v1, 0x10
/* 01AA24 8003F624 00031403 */  sra   $v0, $v1, 0x10
/* 01AA28 8003F628 00031FC2 */  srl   $v1, $v1, 0x1f
/* 01AA2C 8003F62C 00431021 */  addu  $v0, $v0, $v1
/* 01AA30 8003F630 00021043 */  sra   $v0, $v0, 1
/* 01AA34 8003F634 44820000 */  mtc1  $v0, $f0
/* 01AA38 8003F638 00000000 */  nop   
/* 01AA3C 8003F63C 46800020 */  cvt.s.w $f0, $f0
/* 01AA40 8003F640 46002100 */  add.s $f4, $f4, $f0
/* 01AA44 8003F644 E7A20014 */  swc1  $f2, 0x14($sp)
/* 01AA48 8003F648 8E250038 */  lw    $a1, 0x38($s1)
/* 01AA4C 8003F64C 8E270040 */  lw    $a3, 0x40($s1)
/* 01AA50 8003F650 44062000 */  mfc1  $a2, $f4
/* 01AA54 8003F654 0C01C064 */  jal   func_80070190
/* 01AA58 8003F658 24040001 */   addiu $a0, $zero, 1
.L8003F65C:
/* 01AA5C 8003F65C 8E500074 */  lw    $s0, 0x74($s2)
/* 01AA60 8003F660 2402000A */  addiu $v0, $zero, 0xa
/* 01AA64 8003F664 1602000F */  bne   $s0, $v0, .L8003F6A4
/* 01AA68 8003F668 00000000 */   nop   
/* 01AA6C 8003F66C 3C014120 */  lui   $at, 0x4120
/* 01AA70 8003F670 44811000 */  mtc1  $at, $f2
/* 01AA74 8003F674 C6200040 */  lwc1  $f0, 0x40($s1)
/* 01AA78 8003F678 46020000 */  add.s $f0, $f0, $f2
/* 01AA7C 8003F67C C62E003C */  lwc1  $f14, 0x3c($s1)
/* 01AA80 8003F680 C62C0038 */  lwc1  $f12, 0x38($s1)
/* 01AA84 8003F684 44060000 */  mfc1  $a2, $f0
/* 01AA88 8003F688 0C01BE3C */  jal   func_8006F8F0
/* 01AA8C 8003F68C 46027380 */   add.s $f14, $f14, $f2
/* 01AA90 8003F690 8E420074 */  lw    $v0, 0x74($s2)
/* 01AA94 8003F694 14500005 */  bne   $v0, $s0, .L8003F6AC
/* 01AA98 8003F698 2442FFFF */   addiu $v0, $v0, -1
/* 01AA9C 8003F69C 0C0120A0 */  jal   spawn_drops
/* 01AAA0 8003F6A0 0260202D */   daddu $a0, $s3, $zero
.L8003F6A4:
/* 01AAA4 8003F6A4 8E420074 */  lw    $v0, 0x74($s2)
/* 01AAA8 8003F6A8 2442FFFF */  addiu $v0, $v0, -1
.L8003F6AC:
/* 01AAAC 8003F6AC 10400003 */  beqz  $v0, .L8003F6BC
/* 01AAB0 8003F6B0 AE420074 */   sw    $v0, 0x74($s2)
/* 01AAB4 8003F6B4 0800FDB3 */  j     .L8003F6CC
/* 01AAB8 8003F6B8 0000102D */   daddu $v0, $zero, $zero

.L8003F6BC:
/* 01AABC 8003F6BC 8E230000 */  lw    $v1, ($s1)
/* 01AAC0 8003F6C0 24020001 */  addiu $v0, $zero, 1
/* 01AAC4 8003F6C4 34630002 */  ori   $v1, $v1, 2
/* 01AAC8 8003F6C8 AE230000 */  sw    $v1, ($s1)
.L8003F6CC:
/* 01AACC 8003F6CC 8FBF0030 */  lw    $ra, 0x30($sp)
/* 01AAD0 8003F6D0 8FB3002C */  lw    $s3, 0x2c($sp)
/* 01AAD4 8003F6D4 8FB20028 */  lw    $s2, 0x28($sp)
/* 01AAD8 8003F6D8 8FB10024 */  lw    $s1, 0x24($sp)
/* 01AADC 8003F6DC 8FB00020 */  lw    $s0, 0x20($sp)
/* 01AAE0 8003F6E0 03E00008 */  jr    $ra
/* 01AAE4 8003F6E4 27BD0038 */   addiu $sp, $sp, 0x38

