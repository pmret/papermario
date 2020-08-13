.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel SetObjScale
/* 0F829C 802D38EC 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 0F82A0 802D38F0 AFB20018 */  sw    $s2, 0x18($sp)
/* 0F82A4 802D38F4 0080902D */  daddu $s2, $a0, $zero
/* 0F82A8 802D38F8 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0F82AC 802D38FC AFB10014 */  sw    $s1, 0x14($sp)
/* 0F82B0 802D3900 AFB00010 */  sw    $s0, 0x10($sp)
/* 0F82B4 802D3904 F7B60028 */  sdc1  $f22, 0x28($sp)
/* 0F82B8 802D3908 F7B40020 */  sdc1  $f20, 0x20($sp)
/* 0F82BC 802D390C 8E50000C */  lw    $s0, 0xc($s2)
/* 0F82C0 802D3910 8E050000 */  lw    $a1, ($s0)
/* 0F82C4 802D3914 0C0B1EAF */  jal   get_variable
/* 0F82C8 802D3918 26100004 */   addiu $s0, $s0, 4
/* 0F82CC 802D391C 8E050000 */  lw    $a1, ($s0)
/* 0F82D0 802D3920 26100004 */  addiu $s0, $s0, 4
/* 0F82D4 802D3924 0240202D */  daddu $a0, $s2, $zero
/* 0F82D8 802D3928 0C0B210B */  jal   get_float_variable
/* 0F82DC 802D392C 0040882D */   daddu $s1, $v0, $zero
/* 0F82E0 802D3930 8E050000 */  lw    $a1, ($s0)
/* 0F82E4 802D3934 26100004 */  addiu $s0, $s0, 4
/* 0F82E8 802D3938 0240202D */  daddu $a0, $s2, $zero
/* 0F82EC 802D393C 0C0B210B */  jal   get_float_variable
/* 0F82F0 802D3940 46000586 */   mov.s $f22, $f0
/* 0F82F4 802D3944 0240202D */  daddu $a0, $s2, $zero
/* 0F82F8 802D3948 8E050000 */  lw    $a1, ($s0)
/* 0F82FC 802D394C 0C0B210B */  jal   get_float_variable
/* 0F8300 802D3950 46000506 */   mov.s $f20, $f0
/* 0F8304 802D3954 3C02802E */  lui   $v0, 0x802e
/* 0F8308 802D3958 8C42B7C0 */  lw    $v0, -0x4840($v0)
/* 0F830C 802D395C 00118880 */  sll   $s1, $s1, 2
/* 0F8310 802D3960 02228821 */  addu  $s1, $s1, $v0
/* 0F8314 802D3964 8E230000 */  lw    $v1, ($s1)
/* 0F8318 802D3968 E476001C */  swc1  $f22, 0x1c($v1)
/* 0F831C 802D396C E4740020 */  swc1  $f20, 0x20($v1)
/* 0F8320 802D3970 E4600024 */  swc1  $f0, 0x24($v1)
/* 0F8324 802D3974 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0F8328 802D3978 8FB20018 */  lw    $s2, 0x18($sp)
/* 0F832C 802D397C 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F8330 802D3980 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F8334 802D3984 D7B60028 */  ldc1  $f22, 0x28($sp)
/* 0F8338 802D3988 D7B40020 */  ldc1  $f20, 0x20($sp)
/* 0F833C 802D398C 24020002 */  addiu $v0, $zero, 2
/* 0F8340 802D3990 03E00008 */  jr    $ra
/* 0F8344 802D3994 27BD0030 */   addiu $sp, $sp, 0x30

/* 0F8348 802D3998 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0F834C 802D399C AFB10014 */  sw    $s1, 0x14($sp)
/* 0F8350 802D39A0 0080882D */  daddu $s1, $a0, $zero
/* 0F8354 802D39A4 AFBF0018 */  sw    $ra, 0x18($sp)
/* 0F8358 802D39A8 AFB00010 */  sw    $s0, 0x10($sp)
/* 0F835C 802D39AC 8E30000C */  lw    $s0, 0xc($s1)
/* 0F8360 802D39B0 8E050000 */  lw    $a1, ($s0)
/* 0F8364 802D39B4 0C0B1EAF */  jal   get_variable
/* 0F8368 802D39B8 26100004 */   addiu $s0, $s0, 4
/* 0F836C 802D39BC 0220202D */  daddu $a0, $s1, $zero
/* 0F8370 802D39C0 8E050000 */  lw    $a1, ($s0)
/* 0F8374 802D39C4 0C0B210B */  jal   get_float_variable
/* 0F8378 802D39C8 0040802D */   daddu $s0, $v0, $zero
/* 0F837C 802D39CC 3C02802E */  lui   $v0, 0x802e
/* 0F8380 802D39D0 8C42B7C0 */  lw    $v0, -0x4840($v0)
/* 0F8384 802D39D4 00108080 */  sll   $s0, $s0, 2
/* 0F8388 802D39D8 02028021 */  addu  $s0, $s0, $v0
/* 0F838C 802D39DC 8E030000 */  lw    $v1, ($s0)
/* 0F8390 802D39E0 E460003C */  swc1  $f0, 0x3c($v1)
/* 0F8394 802D39E4 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0F8398 802D39E8 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F839C 802D39EC 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F83A0 802D39F0 24020002 */  addiu $v0, $zero, 2
/* 0F83A4 802D39F4 03E00008 */  jr    $ra
/* 0F83A8 802D39F8 27BD0020 */   addiu $sp, $sp, 0x20

