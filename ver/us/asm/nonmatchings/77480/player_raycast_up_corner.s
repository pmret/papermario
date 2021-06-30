.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel player_raycast_up_corner
/* 77EB8 800DEA08 27BDFF58 */  addiu     $sp, $sp, -0xa8
/* 77EBC 800DEA0C AFB30064 */  sw        $s3, 0x64($sp)
/* 77EC0 800DEA10 0080982D */  daddu     $s3, $a0, $zero
/* 77EC4 800DEA14 AFB40068 */  sw        $s4, 0x68($sp)
/* 77EC8 800DEA18 00A0A02D */  daddu     $s4, $a1, $zero
/* 77ECC 800DEA1C AFB5006C */  sw        $s5, 0x6c($sp)
/* 77ED0 800DEA20 00C0A82D */  daddu     $s5, $a2, $zero
/* 77ED4 800DEA24 AFB20060 */  sw        $s2, 0x60($sp)
/* 77ED8 800DEA28 00E0902D */  daddu     $s2, $a3, $zero
/* 77EDC 800DEA2C AFB1005C */  sw        $s1, 0x5c($sp)
/* 77EE0 800DEA30 2411FFFF */  addiu     $s1, $zero, -1
/* 77EE4 800DEA34 3C040001 */  lui       $a0, 1
/* 77EE8 800DEA38 AFBF0070 */  sw        $ra, 0x70($sp)
/* 77EEC 800DEA3C AFB00058 */  sw        $s0, 0x58($sp)
/* 77EF0 800DEA40 F7BE00A0 */  sdc1      $f30, 0xa0($sp)
/* 77EF4 800DEA44 F7BC0098 */  sdc1      $f28, 0x98($sp)
/* 77EF8 800DEA48 F7BA0090 */  sdc1      $f26, 0x90($sp)
/* 77EFC 800DEA4C F7B80088 */  sdc1      $f24, 0x88($sp)
/* 77F00 800DEA50 F7B60080 */  sdc1      $f22, 0x80($sp)
/* 77F04 800DEA54 F7B40078 */  sdc1      $f20, 0x78($sp)
/* 77F08 800DEA58 C6780000 */  lwc1      $f24, ($s3)
/* 77F0C 800DEA5C C6960000 */  lwc1      $f22, ($s4)
/* 77F10 800DEA60 C6B40000 */  lwc1      $f20, ($s5)
/* 77F14 800DEA64 C6400000 */  lwc1      $f0, ($s2)
/* 77F18 800DEA68 3C013F80 */  lui       $at, 0x3f80
/* 77F1C 800DEA6C 44811000 */  mtc1      $at, $f2
/* 77F20 800DEA70 4406B000 */  mfc1      $a2, $f22
/* 77F24 800DEA74 4407A000 */  mfc1      $a3, $f20
/* 77F28 800DEA78 4405C000 */  mfc1      $a1, $f24
/* 77F2C 800DEA7C 27A20038 */  addiu     $v0, $sp, 0x38
/* 77F30 800DEA80 E7A00044 */  swc1      $f0, 0x44($sp)
/* 77F34 800DEA84 AFA2001C */  sw        $v0, 0x1c($sp)
/* 77F38 800DEA88 27A2003C */  addiu     $v0, $sp, 0x3c
/* 77F3C 800DEA8C AFA20020 */  sw        $v0, 0x20($sp)
/* 77F40 800DEA90 27A20040 */  addiu     $v0, $sp, 0x40
/* 77F44 800DEA94 AFA20024 */  sw        $v0, 0x24($sp)
/* 77F48 800DEA98 27A20044 */  addiu     $v0, $sp, 0x44
/* 77F4C 800DEA9C AFA20028 */  sw        $v0, 0x28($sp)
/* 77F50 800DEAA0 27A20048 */  addiu     $v0, $sp, 0x48
/* 77F54 800DEAA4 AFA2002C */  sw        $v0, 0x2c($sp)
/* 77F58 800DEAA8 27A2004C */  addiu     $v0, $sp, 0x4c
/* 77F5C 800DEAAC AFA20030 */  sw        $v0, 0x30($sp)
/* 77F60 800DEAB0 27A20050 */  addiu     $v0, $sp, 0x50
/* 77F64 800DEAB4 AFA00010 */  sw        $zero, 0x10($sp)
/* 77F68 800DEAB8 E7A20014 */  swc1      $f2, 0x14($sp)
/* 77F6C 800DEABC AFA00018 */  sw        $zero, 0x18($sp)
/* 77F70 800DEAC0 0C017334 */  jal       test_ray_colliders
/* 77F74 800DEAC4 AFA20034 */   sw       $v0, 0x34($sp)
/* 77F78 800DEAC8 0040802D */  daddu     $s0, $v0, $zero
/* 77F7C 800DEACC 4600C686 */  mov.s     $f26, $f24
/* 77F80 800DEAD0 4600B706 */  mov.s     $f28, $f22
/* 77F84 800DEAD4 0600000C */  bltz      $s0, .L800DEB08
/* 77F88 800DEAD8 4600A786 */   mov.s    $f30, $f20
/* 77F8C 800DEADC C6400000 */  lwc1      $f0, ($s2)
/* 77F90 800DEAE0 C7A20044 */  lwc1      $f2, 0x44($sp)
/* 77F94 800DEAE4 4600103C */  c.lt.s    $f2, $f0
/* 77F98 800DEAE8 00000000 */  nop
/* 77F9C 800DEAEC 45020007 */  bc1fl     .L800DEB0C
/* 77FA0 800DEAF0 4600D606 */   mov.s    $f24, $f26
/* 77FA4 800DEAF4 0200882D */  daddu     $s1, $s0, $zero
/* 77FA8 800DEAF8 E6420000 */  swc1      $f2, ($s2)
/* 77FAC 800DEAFC E6780000 */  swc1      $f24, ($s3)
/* 77FB0 800DEB00 E6960000 */  swc1      $f22, ($s4)
/* 77FB4 800DEB04 E6B40000 */  swc1      $f20, ($s5)
.L800DEB08:
/* 77FB8 800DEB08 4600D606 */  mov.s     $f24, $f26
.L800DEB0C:
/* 77FBC 800DEB0C 4600E586 */  mov.s     $f22, $f28
/* 77FC0 800DEB10 3C014120 */  lui       $at, 0x4120
/* 77FC4 800DEB14 44811000 */  mtc1      $at, $f2
/* 77FC8 800DEB18 44802000 */  mtc1      $zero, $f4
/* 77FCC 800DEB1C 3C013F80 */  lui       $at, 0x3f80
/* 77FD0 800DEB20 44810000 */  mtc1      $at, $f0
/* 77FD4 800DEB24 27A20038 */  addiu     $v0, $sp, 0x38
/* 77FD8 800DEB28 E7A20044 */  swc1      $f2, 0x44($sp)
/* 77FDC 800DEB2C AFA20018 */  sw        $v0, 0x18($sp)
/* 77FE0 800DEB30 27A2003C */  addiu     $v0, $sp, 0x3c
/* 77FE4 800DEB34 AFA2001C */  sw        $v0, 0x1c($sp)
/* 77FE8 800DEB38 27A20040 */  addiu     $v0, $sp, 0x40
/* 77FEC 800DEB3C AFA20020 */  sw        $v0, 0x20($sp)
/* 77FF0 800DEB40 27A20044 */  addiu     $v0, $sp, 0x44
/* 77FF4 800DEB44 AFA20024 */  sw        $v0, 0x24($sp)
/* 77FF8 800DEB48 27A20048 */  addiu     $v0, $sp, 0x48
/* 77FFC 800DEB4C AFA20028 */  sw        $v0, 0x28($sp)
/* 78000 800DEB50 27A2004C */  addiu     $v0, $sp, 0x4c
/* 78004 800DEB54 AFA2002C */  sw        $v0, 0x2c($sp)
/* 78008 800DEB58 27A20050 */  addiu     $v0, $sp, 0x50
/* 7800C 800DEB5C E7A00010 */  swc1      $f0, 0x10($sp)
/* 78010 800DEB60 E7A40014 */  swc1      $f4, 0x14($sp)
/* 78014 800DEB64 AFA20030 */  sw        $v0, 0x30($sp)
/* 78018 800DEB68 8EA60000 */  lw        $a2, ($s5)
/* 7801C 800DEB6C 44072000 */  mfc1      $a3, $f4
/* 78020 800DEB70 C66C0000 */  lwc1      $f12, ($s3)
/* 78024 800DEB74 C68E0000 */  lwc1      $f14, ($s4)
/* 78028 800DEB78 0C017512 */  jal       test_ray_entities
/* 7802C 800DEB7C 4600F506 */   mov.s    $f20, $f30
/* 78030 800DEB80 0040802D */  daddu     $s0, $v0, $zero
/* 78034 800DEB84 06000010 */  bltz      $s0, .L800DEBC8
/* 78038 800DEB88 0220102D */   daddu    $v0, $s1, $zero
/* 7803C 800DEB8C C6420000 */  lwc1      $f2, ($s2)
/* 78040 800DEB90 C7A00044 */  lwc1      $f0, 0x44($sp)
/* 78044 800DEB94 4602003C */  c.lt.s    $f0, $f2
/* 78048 800DEB98 00000000 */  nop
/* 7804C 800DEB9C 4500000A */  bc1f      .L800DEBC8
/* 78050 800DEBA0 00000000 */   nop
/* 78054 800DEBA4 0C04417A */  jal       get_entity_by_index
/* 78058 800DEBA8 0200202D */   daddu    $a0, $s0, $zero
/* 7805C 800DEBAC C7A00044 */  lwc1      $f0, 0x44($sp)
/* 78060 800DEBB0 36114000 */  ori       $s1, $s0, 0x4000
/* 78064 800DEBB4 E6400000 */  swc1      $f0, ($s2)
/* 78068 800DEBB8 E6780000 */  swc1      $f24, ($s3)
/* 7806C 800DEBBC E6960000 */  swc1      $f22, ($s4)
/* 78070 800DEBC0 E6B40000 */  swc1      $f20, ($s5)
/* 78074 800DEBC4 0220102D */  daddu     $v0, $s1, $zero
.L800DEBC8:
/* 78078 800DEBC8 8FBF0070 */  lw        $ra, 0x70($sp)
/* 7807C 800DEBCC 8FB5006C */  lw        $s5, 0x6c($sp)
/* 78080 800DEBD0 8FB40068 */  lw        $s4, 0x68($sp)
/* 78084 800DEBD4 8FB30064 */  lw        $s3, 0x64($sp)
/* 78088 800DEBD8 8FB20060 */  lw        $s2, 0x60($sp)
/* 7808C 800DEBDC 8FB1005C */  lw        $s1, 0x5c($sp)
/* 78090 800DEBE0 8FB00058 */  lw        $s0, 0x58($sp)
/* 78094 800DEBE4 D7BE00A0 */  ldc1      $f30, 0xa0($sp)
/* 78098 800DEBE8 D7BC0098 */  ldc1      $f28, 0x98($sp)
/* 7809C 800DEBEC D7BA0090 */  ldc1      $f26, 0x90($sp)
/* 780A0 800DEBF0 D7B80088 */  ldc1      $f24, 0x88($sp)
/* 780A4 800DEBF4 D7B60080 */  ldc1      $f22, 0x80($sp)
/* 780A8 800DEBF8 D7B40078 */  ldc1      $f20, 0x78($sp)
/* 780AC 800DEBFC 03E00008 */  jr        $ra
/* 780B0 800DEC00 27BD00A8 */   addiu    $sp, $sp, 0xa8
