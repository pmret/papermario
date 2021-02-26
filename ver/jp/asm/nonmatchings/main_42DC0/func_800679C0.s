.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800679C0
/* 42DC0 800679C0 27BDFF78 */  addiu     $sp, $sp, -0x88
/* 42DC4 800679C4 AFB00060 */  sw        $s0, 0x60($sp)
/* 42DC8 800679C8 8FB00098 */  lw        $s0, 0x98($sp)
/* 42DCC 800679CC AFB10064 */  sw        $s1, 0x64($sp)
/* 42DD0 800679D0 8FB1009C */  lw        $s1, 0x9c($sp)
/* 42DD4 800679D4 AFB20068 */  sw        $s2, 0x68($sp)
/* 42DD8 800679D8 8FB200A0 */  lw        $s2, 0xa0($sp)
/* 42DDC 800679DC F7B40070 */  sdc1      $f20, 0x70($sp)
/* 42DE0 800679E0 4485A000 */  mtc1      $a1, $f20
/* 42DE4 800679E4 00801021 */  addu      $v0, $a0, $zero
/* 42DE8 800679E8 F7B60078 */  sdc1      $f22, 0x78($sp)
/* 42DEC 800679EC 4486B000 */  mtc1      $a2, $f22
/* 42DF0 800679F0 27A40020 */  addiu     $a0, $sp, 0x20
/* 42DF4 800679F4 F7B80080 */  sdc1      $f24, 0x80($sp)
/* 42DF8 800679F8 4487C000 */  mtc1      $a3, $f24
/* 42DFC 800679FC AFBF006C */  sw        $ra, 0x6c($sp)
/* 42E00 80067A00 0C019D58 */  jal       func_80067560
/* 42E04 80067A04 00402821 */   addu     $a1, $v0, $zero
/* 42E08 80067A08 4405A000 */  mfc1      $a1, $f20
/* 42E0C 80067A0C 4406B000 */  mfc1      $a2, $f22
/* 42E10 80067A10 4407C000 */  mfc1      $a3, $f24
/* 42E14 80067A14 27A40020 */  addiu     $a0, $sp, 0x20
/* 42E18 80067A18 AFB00010 */  sw        $s0, 0x10($sp)
/* 42E1C 80067A1C AFB10014 */  sw        $s1, 0x14($sp)
/* 42E20 80067A20 0C019E94 */  jal       func_80067A50
/* 42E24 80067A24 AFB20018 */   sw       $s2, 0x18($sp)
/* 42E28 80067A28 8FBF006C */  lw        $ra, 0x6c($sp)
/* 42E2C 80067A2C 8FB20068 */  lw        $s2, 0x68($sp)
/* 42E30 80067A30 8FB10064 */  lw        $s1, 0x64($sp)
/* 42E34 80067A34 8FB00060 */  lw        $s0, 0x60($sp)
/* 42E38 80067A38 D7B80080 */  ldc1      $f24, 0x80($sp)
/* 42E3C 80067A3C D7B60078 */  ldc1      $f22, 0x78($sp)
/* 42E40 80067A40 D7B40070 */  ldc1      $f20, 0x70($sp)
/* 42E44 80067A44 03E00008 */  jr        $ra
/* 42E48 80067A48 27BD0088 */   addiu    $sp, $sp, 0x88
/* 42E4C 80067A4C 00000000 */  nop
