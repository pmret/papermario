.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel SetPartDispOffset
/* 19A518 8026BC38 27BDFFC0 */  addiu $sp, $sp, -0x40
/* 19A51C 8026BC3C AFB20018 */  sw    $s2, 0x18($sp)
/* 19A520 8026BC40 0080902D */  daddu $s2, $a0, $zero
/* 19A524 8026BC44 AFBF0020 */  sw    $ra, 0x20($sp)
/* 19A528 8026BC48 AFB3001C */  sw    $s3, 0x1c($sp)
/* 19A52C 8026BC4C AFB10014 */  sw    $s1, 0x14($sp)
/* 19A530 8026BC50 AFB00010 */  sw    $s0, 0x10($sp)
/* 19A534 8026BC54 F7B80038 */  sdc1  $f24, 0x38($sp)
/* 19A538 8026BC58 F7B60030 */  sdc1  $f22, 0x30($sp)
/* 19A53C 8026BC5C F7B40028 */  sdc1  $f20, 0x28($sp)
/* 19A540 8026BC60 8E51000C */  lw    $s1, 0xc($s2)
/* 19A544 8026BC64 8E250000 */  lw    $a1, ($s1)
/* 19A548 8026BC68 0C0B1EAF */  jal   get_variable
/* 19A54C 8026BC6C 26310004 */   addiu $s1, $s1, 4
/* 19A550 8026BC70 0040982D */  daddu $s3, $v0, $zero
/* 19A554 8026BC74 2402FF81 */  addiu $v0, $zero, -0x7f
/* 19A558 8026BC78 16620002 */  bne   $s3, $v0, .L8026BC84
/* 19A55C 8026BC7C 00000000 */   nop   
/* 19A560 8026BC80 8E530148 */  lw    $s3, 0x148($s2)
.L8026BC84:
/* 19A564 8026BC84 8E250000 */  lw    $a1, ($s1)
/* 19A568 8026BC88 26310004 */  addiu $s1, $s1, 4
/* 19A56C 8026BC8C 0C0B1EAF */  jal   get_variable
/* 19A570 8026BC90 0240202D */   daddu $a0, $s2, $zero
/* 19A574 8026BC94 8E250000 */  lw    $a1, ($s1)
/* 19A578 8026BC98 26310004 */  addiu $s1, $s1, 4
/* 19A57C 8026BC9C 0240202D */  daddu $a0, $s2, $zero
/* 19A580 8026BCA0 0C0B210B */  jal   get_float_variable
/* 19A584 8026BCA4 0040802D */   daddu $s0, $v0, $zero
/* 19A588 8026BCA8 8E250000 */  lw    $a1, ($s1)
/* 19A58C 8026BCAC 26310004 */  addiu $s1, $s1, 4
/* 19A590 8026BCB0 0240202D */  daddu $a0, $s2, $zero
/* 19A594 8026BCB4 0C0B210B */  jal   get_float_variable
/* 19A598 8026BCB8 46000506 */   mov.s $f20, $f0
/* 19A59C 8026BCBC 0240202D */  daddu $a0, $s2, $zero
/* 19A5A0 8026BCC0 8E250000 */  lw    $a1, ($s1)
/* 19A5A4 8026BCC4 0C0B210B */  jal   get_float_variable
/* 19A5A8 8026BCC8 46000586 */   mov.s $f22, $f0
/* 19A5AC 8026BCCC 0260202D */  daddu $a0, $s3, $zero
/* 19A5B0 8026BCD0 0C09A75B */  jal   get_actor
/* 19A5B4 8026BCD4 46000606 */   mov.s $f24, $f0
/* 19A5B8 8026BCD8 0040202D */  daddu $a0, $v0, $zero
/* 19A5BC 8026BCDC 0C099117 */  jal   get_actor_part
/* 19A5C0 8026BCE0 0200282D */   daddu $a1, $s0, $zero
/* 19A5C4 8026BCE4 0040202D */  daddu $a0, $v0, $zero
/* 19A5C8 8026BCE8 8C820000 */  lw    $v0, ($a0)
/* 19A5CC 8026BCEC 3C030010 */  lui   $v1, 0x10
/* 19A5D0 8026BCF0 00431024 */  and   $v0, $v0, $v1
/* 19A5D4 8026BCF4 1440000D */  bnez  $v0, .L8026BD2C
/* 19A5D8 8026BCF8 00000000 */   nop   
/* 19A5DC 8026BCFC 4600A08D */  trunc.w.s $f2, $f20
/* 19A5E0 8026BD00 44021000 */  mfc1  $v0, $f2
/* 19A5E4 8026BD04 00000000 */  nop   
/* 19A5E8 8026BD08 A4820014 */  sh    $v0, 0x14($a0)
/* 19A5EC 8026BD0C 4600B08D */  trunc.w.s $f2, $f22
/* 19A5F0 8026BD10 44021000 */  mfc1  $v0, $f2
/* 19A5F4 8026BD14 00000000 */  nop   
/* 19A5F8 8026BD18 A4820016 */  sh    $v0, 0x16($a0)
/* 19A5FC 8026BD1C 4600C08D */  trunc.w.s $f2, $f24
/* 19A600 8026BD20 44021000 */  mfc1  $v0, $f2
/* 19A604 8026BD24 0809AF57 */  j     .L8026BD5C
/* 19A608 8026BD28 A4820018 */   sh    $v0, 0x18($a0)

.L8026BD2C:
/* 19A60C 8026BD2C 4600A08D */  trunc.w.s $f2, $f20
/* 19A610 8026BD30 44021000 */  mfc1  $v0, $f2
/* 19A614 8026BD34 00000000 */  nop   
/* 19A618 8026BD38 A482001A */  sh    $v0, 0x1a($a0)
/* 19A61C 8026BD3C 4600B08D */  trunc.w.s $f2, $f22
/* 19A620 8026BD40 44021000 */  mfc1  $v0, $f2
/* 19A624 8026BD44 00000000 */  nop   
/* 19A628 8026BD48 A482001C */  sh    $v0, 0x1c($a0)
/* 19A62C 8026BD4C 4600C08D */  trunc.w.s $f2, $f24
/* 19A630 8026BD50 44021000 */  mfc1  $v0, $f2
/* 19A634 8026BD54 00000000 */  nop   
/* 19A638 8026BD58 A482001E */  sh    $v0, 0x1e($a0)
.L8026BD5C:
/* 19A63C 8026BD5C 8FBF0020 */  lw    $ra, 0x20($sp)
/* 19A640 8026BD60 8FB3001C */  lw    $s3, 0x1c($sp)
/* 19A644 8026BD64 8FB20018 */  lw    $s2, 0x18($sp)
/* 19A648 8026BD68 8FB10014 */  lw    $s1, 0x14($sp)
/* 19A64C 8026BD6C 8FB00010 */  lw    $s0, 0x10($sp)
/* 19A650 8026BD70 D7B80038 */  ldc1  $f24, 0x38($sp)
/* 19A654 8026BD74 D7B60030 */  ldc1  $f22, 0x30($sp)
/* 19A658 8026BD78 D7B40028 */  ldc1  $f20, 0x28($sp)
/* 19A65C 8026BD7C 24020002 */  addiu $v0, $zero, 2
/* 19A660 8026BD80 03E00008 */  jr    $ra
/* 19A664 8026BD84 27BD0040 */   addiu $sp, $sp, 0x40

