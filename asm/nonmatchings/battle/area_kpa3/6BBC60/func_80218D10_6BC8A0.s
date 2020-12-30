.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218D10_6BC8A0
/* 6BC8A0 80218D10 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 6BC8A4 80218D14 AFBF0024 */  sw        $ra, 0x24($sp)
/* 6BC8A8 80218D18 AFB20020 */  sw        $s2, 0x20($sp)
/* 6BC8AC 80218D1C AFB1001C */  sw        $s1, 0x1c($sp)
/* 6BC8B0 80218D20 AFB00018 */  sw        $s0, 0x18($sp)
/* 6BC8B4 80218D24 8C840148 */  lw        $a0, 0x148($a0)
/* 6BC8B8 80218D28 0C09A75B */  jal       get_actor
/* 6BC8BC 80218D2C 00A0802D */   daddu    $s0, $a1, $zero
/* 6BC8C0 80218D30 0040882D */  daddu     $s1, $v0, $zero
/* 6BC8C4 80218D34 12000007 */  beqz      $s0, .L80218D54
/* 6BC8C8 80218D38 2632000C */   addiu    $s2, $s1, 0xc
/* 6BC8CC 80218D3C C6200144 */  lwc1      $f0, 0x144($s1)
/* 6BC8D0 80218D40 C6220148 */  lwc1      $f2, 0x148($s1)
/* 6BC8D4 80218D44 C624014C */  lwc1      $f4, 0x14c($s1)
/* 6BC8D8 80218D48 E620000C */  swc1      $f0, 0xc($s1)
/* 6BC8DC 80218D4C E6220010 */  swc1      $f2, 0x10($s1)
/* 6BC8E0 80218D50 E6240014 */  swc1      $f4, 0x14($s1)
.L80218D54:
/* 6BC8E4 80218D54 8E25004C */  lw        $a1, 0x4c($s1)
/* 6BC8E8 80218D58 8E260054 */  lw        $a2, 0x54($s1)
/* 6BC8EC 80218D5C 0C09904A */  jal       add_xz_vec3f
/* 6BC8F0 80218D60 0240202D */   daddu    $a0, $s2, $zero
/* 6BC8F4 80218D64 C622004C */  lwc1      $f2, 0x4c($s1)
/* 6BC8F8 80218D68 3C014080 */  lui       $at, 0x4080
/* 6BC8FC 80218D6C 44810000 */  mtc1      $at, $f0
/* 6BC900 80218D70 00000000 */  nop       
/* 6BC904 80218D74 4600103C */  c.lt.s    $f2, $f0
/* 6BC908 80218D78 00000000 */  nop       
/* 6BC90C 80218D7C 45000007 */  bc1f      .L80218D9C
/* 6BC910 80218D80 0000202D */   daddu    $a0, $zero, $zero
/* 6BC914 80218D84 C6200054 */  lwc1      $f0, 0x54($s1)
/* 6BC918 80218D88 E7A00010 */  swc1      $f0, 0x10($sp)
/* 6BC91C 80218D8C 8E25000C */  lw        $a1, 0xc($s1)
/* 6BC920 80218D90 8E260010 */  lw        $a2, 0x10($s1)
/* 6BC924 80218D94 0808636D */  j         .L80218DB4
/* 6BC928 80218D98 8E270014 */   lw       $a3, 0x14($s1)
.L80218D9C:
/* 6BC92C 80218D9C C6200054 */  lwc1      $f0, 0x54($s1)
/* 6BC930 80218DA0 E7A00010 */  swc1      $f0, 0x10($sp)
/* 6BC934 80218DA4 8E25000C */  lw        $a1, 0xc($s1)
/* 6BC938 80218DA8 8E260010 */  lw        $a2, 0x10($s1)
/* 6BC93C 80218DAC 8E270014 */  lw        $a3, 0x14($s1)
/* 6BC940 80218DB0 24040001 */  addiu     $a0, $zero, 1
.L80218DB4:
/* 6BC944 80218DB4 0C0990BC */  jal       play_movement_dust_effects
/* 6BC948 80218DB8 00000000 */   nop      
/* 6BC94C 80218DBC C6400040 */  lwc1      $f0, 0x40($s2)
/* 6BC950 80218DC0 3C013FF8 */  lui       $at, 0x3ff8
/* 6BC954 80218DC4 44811800 */  mtc1      $at, $f3
/* 6BC958 80218DC8 44801000 */  mtc1      $zero, $f2
/* 6BC95C 80218DCC 46000021 */  cvt.d.s   $f0, $f0
/* 6BC960 80218DD0 46220003 */  div.d     $f0, $f0, $f2
/* 6BC964 80218DD4 C6420000 */  lwc1      $f2, ($s2)
/* 6BC968 80218DD8 46200020 */  cvt.s.d   $f0, $f0
/* 6BC96C 80218DDC E6400040 */  swc1      $f0, 0x40($s2)
/* 6BC970 80218DE0 E6220144 */  swc1      $f2, 0x144($s1)
/* 6BC974 80218DE4 C6400004 */  lwc1      $f0, 4($s2)
/* 6BC978 80218DE8 E6200148 */  swc1      $f0, 0x148($s1)
/* 6BC97C 80218DEC C6400008 */  lwc1      $f0, 8($s2)
/* 6BC980 80218DF0 E620014C */  swc1      $f0, 0x14c($s1)
/* 6BC984 80218DF4 C6400040 */  lwc1      $f0, 0x40($s2)
/* 6BC988 80218DF8 3C013FF0 */  lui       $at, 0x3ff0
/* 6BC98C 80218DFC 44811800 */  mtc1      $at, $f3
/* 6BC990 80218E00 44801000 */  mtc1      $zero, $f2
/* 6BC994 80218E04 46000021 */  cvt.d.s   $f0, $f0
/* 6BC998 80218E08 4622003C */  c.lt.d    $f0, $f2
/* 6BC99C 80218E0C 00000000 */  nop       
/* 6BC9A0 80218E10 45010002 */  bc1t      .L80218E1C
/* 6BC9A4 80218E14 24020002 */   addiu    $v0, $zero, 2
/* 6BC9A8 80218E18 0000102D */  daddu     $v0, $zero, $zero
.L80218E1C:
/* 6BC9AC 80218E1C 8FBF0024 */  lw        $ra, 0x24($sp)
/* 6BC9B0 80218E20 8FB20020 */  lw        $s2, 0x20($sp)
/* 6BC9B4 80218E24 8FB1001C */  lw        $s1, 0x1c($sp)
/* 6BC9B8 80218E28 8FB00018 */  lw        $s0, 0x18($sp)
/* 6BC9BC 80218E2C 03E00008 */  jr        $ra
/* 6BC9C0 80218E30 27BD0028 */   addiu    $sp, $sp, 0x28
