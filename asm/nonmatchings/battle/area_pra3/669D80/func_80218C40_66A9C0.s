.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218C40_66A9C0
/* 66A9C0 80218C40 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 66A9C4 80218C44 AFBF0024 */  sw        $ra, 0x24($sp)
/* 66A9C8 80218C48 AFB20020 */  sw        $s2, 0x20($sp)
/* 66A9CC 80218C4C AFB1001C */  sw        $s1, 0x1c($sp)
/* 66A9D0 80218C50 AFB00018 */  sw        $s0, 0x18($sp)
/* 66A9D4 80218C54 8C840148 */  lw        $a0, 0x148($a0)
/* 66A9D8 80218C58 0C09A75B */  jal       get_actor
/* 66A9DC 80218C5C 00A0802D */   daddu    $s0, $a1, $zero
/* 66A9E0 80218C60 0040882D */  daddu     $s1, $v0, $zero
/* 66A9E4 80218C64 12000007 */  beqz      $s0, .L80218C84
/* 66A9E8 80218C68 2632000C */   addiu    $s2, $s1, 0xc
/* 66A9EC 80218C6C C6200144 */  lwc1      $f0, 0x144($s1)
/* 66A9F0 80218C70 C6220148 */  lwc1      $f2, 0x148($s1)
/* 66A9F4 80218C74 C624014C */  lwc1      $f4, 0x14c($s1)
/* 66A9F8 80218C78 E620000C */  swc1      $f0, 0xc($s1)
/* 66A9FC 80218C7C E6220010 */  swc1      $f2, 0x10($s1)
/* 66AA00 80218C80 E6240014 */  swc1      $f4, 0x14($s1)
.L80218C84:
/* 66AA04 80218C84 8E25004C */  lw        $a1, 0x4c($s1)
/* 66AA08 80218C88 8E260054 */  lw        $a2, 0x54($s1)
/* 66AA0C 80218C8C 0C09904A */  jal       add_xz_vec3f
/* 66AA10 80218C90 0240202D */   daddu    $a0, $s2, $zero
/* 66AA14 80218C94 C622004C */  lwc1      $f2, 0x4c($s1)
/* 66AA18 80218C98 3C014080 */  lui       $at, 0x4080
/* 66AA1C 80218C9C 44810000 */  mtc1      $at, $f0
/* 66AA20 80218CA0 00000000 */  nop
/* 66AA24 80218CA4 4600103C */  c.lt.s    $f2, $f0
/* 66AA28 80218CA8 00000000 */  nop
/* 66AA2C 80218CAC 45000007 */  bc1f      .L80218CCC
/* 66AA30 80218CB0 0000202D */   daddu    $a0, $zero, $zero
/* 66AA34 80218CB4 C6200054 */  lwc1      $f0, 0x54($s1)
/* 66AA38 80218CB8 E7A00010 */  swc1      $f0, 0x10($sp)
/* 66AA3C 80218CBC 8E25000C */  lw        $a1, 0xc($s1)
/* 66AA40 80218CC0 8E260010 */  lw        $a2, 0x10($s1)
/* 66AA44 80218CC4 08086339 */  j         .L80218CE4
/* 66AA48 80218CC8 8E270014 */   lw       $a3, 0x14($s1)
.L80218CCC:
/* 66AA4C 80218CCC C6200054 */  lwc1      $f0, 0x54($s1)
/* 66AA50 80218CD0 E7A00010 */  swc1      $f0, 0x10($sp)
/* 66AA54 80218CD4 8E25000C */  lw        $a1, 0xc($s1)
/* 66AA58 80218CD8 8E260010 */  lw        $a2, 0x10($s1)
/* 66AA5C 80218CDC 8E270014 */  lw        $a3, 0x14($s1)
/* 66AA60 80218CE0 24040001 */  addiu     $a0, $zero, 1
.L80218CE4:
/* 66AA64 80218CE4 0C0990BC */  jal       play_movement_dust_effects
/* 66AA68 80218CE8 00000000 */   nop
/* 66AA6C 80218CEC C6400040 */  lwc1      $f0, 0x40($s2)
/* 66AA70 80218CF0 3C013FF8 */  lui       $at, 0x3ff8
/* 66AA74 80218CF4 44811800 */  mtc1      $at, $f3
/* 66AA78 80218CF8 44801000 */  mtc1      $zero, $f2
/* 66AA7C 80218CFC 46000021 */  cvt.d.s   $f0, $f0
/* 66AA80 80218D00 46220003 */  div.d     $f0, $f0, $f2
/* 66AA84 80218D04 C6420000 */  lwc1      $f2, ($s2)
/* 66AA88 80218D08 46200020 */  cvt.s.d   $f0, $f0
/* 66AA8C 80218D0C E6400040 */  swc1      $f0, 0x40($s2)
/* 66AA90 80218D10 E6220144 */  swc1      $f2, 0x144($s1)
/* 66AA94 80218D14 C6400004 */  lwc1      $f0, 4($s2)
/* 66AA98 80218D18 E6200148 */  swc1      $f0, 0x148($s1)
/* 66AA9C 80218D1C C6400008 */  lwc1      $f0, 8($s2)
/* 66AAA0 80218D20 E620014C */  swc1      $f0, 0x14c($s1)
/* 66AAA4 80218D24 C6400040 */  lwc1      $f0, 0x40($s2)
/* 66AAA8 80218D28 3C013FF0 */  lui       $at, 0x3ff0
/* 66AAAC 80218D2C 44811800 */  mtc1      $at, $f3
/* 66AAB0 80218D30 44801000 */  mtc1      $zero, $f2
/* 66AAB4 80218D34 46000021 */  cvt.d.s   $f0, $f0
/* 66AAB8 80218D38 4622003C */  c.lt.d    $f0, $f2
/* 66AABC 80218D3C 00000000 */  nop
/* 66AAC0 80218D40 45010002 */  bc1t      .L80218D4C
/* 66AAC4 80218D44 24020002 */   addiu    $v0, $zero, 2
/* 66AAC8 80218D48 0000102D */  daddu     $v0, $zero, $zero
.L80218D4C:
/* 66AACC 80218D4C 8FBF0024 */  lw        $ra, 0x24($sp)
/* 66AAD0 80218D50 8FB20020 */  lw        $s2, 0x20($sp)
/* 66AAD4 80218D54 8FB1001C */  lw        $s1, 0x1c($sp)
/* 66AAD8 80218D58 8FB00018 */  lw        $s0, 0x18($sp)
/* 66AADC 80218D5C 03E00008 */  jr        $ra
/* 66AAE0 80218D60 27BD0028 */   addiu    $sp, $sp, 0x28
