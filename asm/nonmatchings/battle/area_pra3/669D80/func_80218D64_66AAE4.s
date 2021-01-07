.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218D64_66AAE4
/* 66AAE4 80218D64 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 66AAE8 80218D68 AFBF0024 */  sw        $ra, 0x24($sp)
/* 66AAEC 80218D6C AFB20020 */  sw        $s2, 0x20($sp)
/* 66AAF0 80218D70 AFB1001C */  sw        $s1, 0x1c($sp)
/* 66AAF4 80218D74 AFB00018 */  sw        $s0, 0x18($sp)
/* 66AAF8 80218D78 8C840148 */  lw        $a0, 0x148($a0)
/* 66AAFC 80218D7C 0C09A75B */  jal       get_actor
/* 66AB00 80218D80 00A0802D */   daddu    $s0, $a1, $zero
/* 66AB04 80218D84 0040882D */  daddu     $s1, $v0, $zero
/* 66AB08 80218D88 12000007 */  beqz      $s0, .L80218DA8
/* 66AB0C 80218D8C 2632000C */   addiu    $s2, $s1, 0xc
/* 66AB10 80218D90 C6200144 */  lwc1      $f0, 0x144($s1)
/* 66AB14 80218D94 C6220148 */  lwc1      $f2, 0x148($s1)
/* 66AB18 80218D98 C624014C */  lwc1      $f4, 0x14c($s1)
/* 66AB1C 80218D9C E620000C */  swc1      $f0, 0xc($s1)
/* 66AB20 80218DA0 E6220010 */  swc1      $f2, 0x10($s1)
/* 66AB24 80218DA4 E6240014 */  swc1      $f4, 0x14($s1)
.L80218DA8:
/* 66AB28 80218DA8 8E25004C */  lw        $a1, 0x4c($s1)
/* 66AB2C 80218DAC 8E260054 */  lw        $a2, 0x54($s1)
/* 66AB30 80218DB0 0C09904A */  jal       add_xz_vec3f
/* 66AB34 80218DB4 0240202D */   daddu    $a0, $s2, $zero
/* 66AB38 80218DB8 C622004C */  lwc1      $f2, 0x4c($s1)
/* 66AB3C 80218DBC 3C014080 */  lui       $at, 0x4080
/* 66AB40 80218DC0 44810000 */  mtc1      $at, $f0
/* 66AB44 80218DC4 00000000 */  nop       
/* 66AB48 80218DC8 4600103C */  c.lt.s    $f2, $f0
/* 66AB4C 80218DCC 00000000 */  nop       
/* 66AB50 80218DD0 45000007 */  bc1f      .L80218DF0
/* 66AB54 80218DD4 0000202D */   daddu    $a0, $zero, $zero
/* 66AB58 80218DD8 C6200054 */  lwc1      $f0, 0x54($s1)
/* 66AB5C 80218DDC E7A00010 */  swc1      $f0, 0x10($sp)
/* 66AB60 80218DE0 8E25000C */  lw        $a1, 0xc($s1)
/* 66AB64 80218DE4 8E260010 */  lw        $a2, 0x10($s1)
/* 66AB68 80218DE8 08086382 */  j         .L80218E08
/* 66AB6C 80218DEC 8E270014 */   lw       $a3, 0x14($s1)
.L80218DF0:
/* 66AB70 80218DF0 C6200054 */  lwc1      $f0, 0x54($s1)
/* 66AB74 80218DF4 E7A00010 */  swc1      $f0, 0x10($sp)
/* 66AB78 80218DF8 8E25000C */  lw        $a1, 0xc($s1)
/* 66AB7C 80218DFC 8E260010 */  lw        $a2, 0x10($s1)
/* 66AB80 80218E00 8E270014 */  lw        $a3, 0x14($s1)
/* 66AB84 80218E04 24040001 */  addiu     $a0, $zero, 1
.L80218E08:
/* 66AB88 80218E08 0C0990BC */  jal       play_movement_dust_effects
/* 66AB8C 80218E0C 00000000 */   nop      
/* 66AB90 80218E10 C6400040 */  lwc1      $f0, 0x40($s2)
/* 66AB94 80218E14 3C013FF8 */  lui       $at, 0x3ff8
/* 66AB98 80218E18 44811800 */  mtc1      $at, $f3
/* 66AB9C 80218E1C 44801000 */  mtc1      $zero, $f2
/* 66ABA0 80218E20 46000021 */  cvt.d.s   $f0, $f0
/* 66ABA4 80218E24 46220003 */  div.d     $f0, $f0, $f2
/* 66ABA8 80218E28 C6420000 */  lwc1      $f2, ($s2)
/* 66ABAC 80218E2C 46200020 */  cvt.s.d   $f0, $f0
/* 66ABB0 80218E30 E6400040 */  swc1      $f0, 0x40($s2)
/* 66ABB4 80218E34 E6220144 */  swc1      $f2, 0x144($s1)
/* 66ABB8 80218E38 C6400004 */  lwc1      $f0, 4($s2)
/* 66ABBC 80218E3C E6200148 */  swc1      $f0, 0x148($s1)
/* 66ABC0 80218E40 C6400008 */  lwc1      $f0, 8($s2)
/* 66ABC4 80218E44 E620014C */  swc1      $f0, 0x14c($s1)
/* 66ABC8 80218E48 C6400040 */  lwc1      $f0, 0x40($s2)
/* 66ABCC 80218E4C 3C013FF0 */  lui       $at, 0x3ff0
/* 66ABD0 80218E50 44811800 */  mtc1      $at, $f3
/* 66ABD4 80218E54 44801000 */  mtc1      $zero, $f2
/* 66ABD8 80218E58 46000021 */  cvt.d.s   $f0, $f0
/* 66ABDC 80218E5C 4622003C */  c.lt.d    $f0, $f2
/* 66ABE0 80218E60 00000000 */  nop       
/* 66ABE4 80218E64 45010002 */  bc1t      .L80218E70
/* 66ABE8 80218E68 24020002 */   addiu    $v0, $zero, 2
/* 66ABEC 80218E6C 0000102D */  daddu     $v0, $zero, $zero
.L80218E70:
/* 66ABF0 80218E70 8FBF0024 */  lw        $ra, 0x24($sp)
/* 66ABF4 80218E74 8FB20020 */  lw        $s2, 0x20($sp)
/* 66ABF8 80218E78 8FB1001C */  lw        $s1, 0x1c($sp)
/* 66ABFC 80218E7C 8FB00018 */  lw        $s0, 0x18($sp)
/* 66AC00 80218E80 03E00008 */  jr        $ra
/* 66AC04 80218E84 27BD0028 */   addiu    $sp, $sp, 0x28
