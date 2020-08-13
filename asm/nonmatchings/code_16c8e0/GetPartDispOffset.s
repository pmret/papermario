.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel GetPartDispOffset
/* 19A3C8 8026BAE8 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 19A3CC 8026BAEC AFB20018 */  sw    $s2, 0x18($sp)
/* 19A3D0 8026BAF0 0080902D */  daddu $s2, $a0, $zero
/* 19A3D4 8026BAF4 AFBF0024 */  sw    $ra, 0x24($sp)
/* 19A3D8 8026BAF8 AFB40020 */  sw    $s4, 0x20($sp)
/* 19A3DC 8026BAFC AFB3001C */  sw    $s3, 0x1c($sp)
/* 19A3E0 8026BB00 AFB10014 */  sw    $s1, 0x14($sp)
/* 19A3E4 8026BB04 AFB00010 */  sw    $s0, 0x10($sp)
/* 19A3E8 8026BB08 F7B60030 */  sdc1  $f22, 0x30($sp)
/* 19A3EC 8026BB0C F7B40028 */  sdc1  $f20, 0x28($sp)
/* 19A3F0 8026BB10 8E51000C */  lw    $s1, 0xc($s2)
/* 19A3F4 8026BB14 8E250000 */  lw    $a1, ($s1)
/* 19A3F8 8026BB18 0C0B1EAF */  jal   get_variable
/* 19A3FC 8026BB1C 26310004 */   addiu $s1, $s1, 4
/* 19A400 8026BB20 0040802D */  daddu $s0, $v0, $zero
/* 19A404 8026BB24 2402FF81 */  addiu $v0, $zero, -0x7f
/* 19A408 8026BB28 16020002 */  bne   $s0, $v0, .L8026BB34
/* 19A40C 8026BB2C 00000000 */   nop   
/* 19A410 8026BB30 8E500148 */  lw    $s0, 0x148($s2)
.L8026BB34:
/* 19A414 8026BB34 8E250000 */  lw    $a1, ($s1)
/* 19A418 8026BB38 26310004 */  addiu $s1, $s1, 4
/* 19A41C 8026BB3C 0C0B1EAF */  jal   get_variable
/* 19A420 8026BB40 0240202D */   daddu $a0, $s2, $zero
/* 19A424 8026BB44 8E330000 */  lw    $s3, ($s1)
/* 19A428 8026BB48 26310004 */  addiu $s1, $s1, 4
/* 19A42C 8026BB4C 0200202D */  daddu $a0, $s0, $zero
/* 19A430 8026BB50 8E340000 */  lw    $s4, ($s1)
/* 19A434 8026BB54 8E310004 */  lw    $s1, 4($s1)
/* 19A438 8026BB58 0C09A75B */  jal   get_actor
/* 19A43C 8026BB5C 0040802D */   daddu $s0, $v0, $zero
/* 19A440 8026BB60 0040202D */  daddu $a0, $v0, $zero
/* 19A444 8026BB64 0C099117 */  jal   get_actor_part
/* 19A448 8026BB68 0200282D */   daddu $a1, $s0, $zero
/* 19A44C 8026BB6C 0040202D */  daddu $a0, $v0, $zero
/* 19A450 8026BB70 8C820000 */  lw    $v0, ($a0)
/* 19A454 8026BB74 3C030010 */  lui   $v1, 0x10
/* 19A458 8026BB78 00431024 */  and   $v0, $v0, $v1
/* 19A45C 8026BB7C 14400008 */  bnez  $v0, .L8026BBA0
/* 19A460 8026BB80 00000000 */   nop   
/* 19A464 8026BB84 84820014 */  lh    $v0, 0x14($a0)
/* 19A468 8026BB88 84830018 */  lh    $v1, 0x18($a0)
/* 19A46C 8026BB8C 44820000 */  mtc1  $v0, $f0
/* 19A470 8026BB90 00000000 */  nop   
/* 19A474 8026BB94 46800020 */  cvt.s.w $f0, $f0
/* 19A478 8026BB98 0809AEEE */  j     .L8026BBB8
/* 19A47C 8026BB9C 84820016 */   lh    $v0, 0x16($a0)

.L8026BBA0:
/* 19A480 8026BBA0 8482001A */  lh    $v0, 0x1a($a0)
/* 19A484 8026BBA4 8483001E */  lh    $v1, 0x1e($a0)
/* 19A488 8026BBA8 44820000 */  mtc1  $v0, $f0
/* 19A48C 8026BBAC 00000000 */  nop   
/* 19A490 8026BBB0 46800020 */  cvt.s.w $f0, $f0
/* 19A494 8026BBB4 8482001C */  lh    $v0, 0x1c($a0)
.L8026BBB8:
/* 19A498 8026BBB8 4483B000 */  mtc1  $v1, $f22
/* 19A49C 8026BBBC 00000000 */  nop   
/* 19A4A0 8026BBC0 4680B5A0 */  cvt.s.w $f22, $f22
/* 19A4A4 8026BBC4 4482A000 */  mtc1  $v0, $f20
/* 19A4A8 8026BBC8 00000000 */  nop   
/* 19A4AC 8026BBCC 4680A520 */  cvt.s.w $f20, $f20
/* 19A4B0 8026BBD0 0240202D */  daddu $a0, $s2, $zero
/* 19A4B4 8026BBD4 4600008D */  trunc.w.s $f2, $f0
/* 19A4B8 8026BBD8 44061000 */  mfc1  $a2, $f2
/* 19A4BC 8026BBDC 0C0B2026 */  jal   set_variable
/* 19A4C0 8026BBE0 0260282D */   daddu $a1, $s3, $zero
/* 19A4C4 8026BBE4 0240202D */  daddu $a0, $s2, $zero
/* 19A4C8 8026BBE8 4600A08D */  trunc.w.s $f2, $f20
/* 19A4CC 8026BBEC 44061000 */  mfc1  $a2, $f2
/* 19A4D0 8026BBF0 0C0B2026 */  jal   set_variable
/* 19A4D4 8026BBF4 0280282D */   daddu $a1, $s4, $zero
/* 19A4D8 8026BBF8 0240202D */  daddu $a0, $s2, $zero
/* 19A4DC 8026BBFC 4600B08D */  trunc.w.s $f2, $f22
/* 19A4E0 8026BC00 44061000 */  mfc1  $a2, $f2
/* 19A4E4 8026BC04 0C0B2026 */  jal   set_variable
/* 19A4E8 8026BC08 0220282D */   daddu $a1, $s1, $zero
/* 19A4EC 8026BC0C 8FBF0024 */  lw    $ra, 0x24($sp)
/* 19A4F0 8026BC10 8FB40020 */  lw    $s4, 0x20($sp)
/* 19A4F4 8026BC14 8FB3001C */  lw    $s3, 0x1c($sp)
/* 19A4F8 8026BC18 8FB20018 */  lw    $s2, 0x18($sp)
/* 19A4FC 8026BC1C 8FB10014 */  lw    $s1, 0x14($sp)
/* 19A500 8026BC20 8FB00010 */  lw    $s0, 0x10($sp)
/* 19A504 8026BC24 D7B60030 */  ldc1  $f22, 0x30($sp)
/* 19A508 8026BC28 D7B40028 */  ldc1  $f20, 0x28($sp)
/* 19A50C 8026BC2C 24020002 */  addiu $v0, $zero, 2
/* 19A510 8026BC30 03E00008 */  jr    $ra
/* 19A514 8026BC34 27BD0038 */   addiu $sp, $sp, 0x38

