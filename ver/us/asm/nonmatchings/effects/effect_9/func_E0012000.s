.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E0012000
/* 32DD10 E0012000 27BDFF48 */  addiu     $sp, $sp, -0xb8
/* 32DD14 E0012004 F7B400A8 */  sdc1      $f20, 0xa8($sp)
/* 32DD18 E0012008 4480A000 */  mtc1      $zero, $f20
/* 32DD1C E001200C F7B600B0 */  sdc1      $f22, 0xb0($sp)
/* 32DD20 E0012010 3C013F80 */  lui       $at, 0x3f80
/* 32DD24 E0012014 4481B000 */  mtc1      $at, $f22
/* 32DD28 E0012018 AFB1009C */  sw        $s1, 0x9c($sp)
/* 32DD2C E001201C 0080882D */  daddu     $s1, $a0, $zero
/* 32DD30 E0012020 AFBF00A0 */  sw        $ra, 0xa0($sp)
/* 32DD34 E0012024 AFB00098 */  sw        $s0, 0x98($sp)
/* 32DD38 E0012028 E7B40010 */  swc1      $f20, 0x10($sp)
/* 32DD3C E001202C 8E250024 */  lw        $a1, 0x24($s1)
/* 32DD40 E0012030 4406B000 */  mfc1      $a2, $f22
/* 32DD44 E0012034 4407A000 */  mfc1      $a3, $f20
/* 32DD48 E0012038 0C080104 */  jal       shim_guRotateF
/* 32DD4C E001203C 27A40018 */   addiu    $a0, $sp, 0x18
/* 32DD50 E0012040 27B00058 */  addiu     $s0, $sp, 0x58
/* 32DD54 E0012044 E7B60010 */  swc1      $f22, 0x10($sp)
/* 32DD58 E0012048 8E25002C */  lw        $a1, 0x2c($s1)
/* 32DD5C E001204C 4406A000 */  mfc1      $a2, $f20
/* 32DD60 E0012050 4407A000 */  mfc1      $a3, $f20
/* 32DD64 E0012054 0C080104 */  jal       shim_guRotateF
/* 32DD68 E0012058 0200202D */   daddu    $a0, $s0, $zero
/* 32DD6C E001205C 0200202D */  daddu     $a0, $s0, $zero
/* 32DD70 E0012060 27A50018 */  addiu     $a1, $sp, 0x18
/* 32DD74 E0012064 0C080114 */  jal       shim_guMtxCatF
/* 32DD78 E0012068 00A0302D */   daddu    $a2, $a1, $zero
/* 32DD7C E001206C E7B40010 */  swc1      $f20, 0x10($sp)
/* 32DD80 E0012070 8E250028 */  lw        $a1, 0x28($s1)
/* 32DD84 E0012074 4406A000 */  mfc1      $a2, $f20
/* 32DD88 E0012078 4407B000 */  mfc1      $a3, $f22
/* 32DD8C E001207C 0C080104 */  jal       shim_guRotateF
/* 32DD90 E0012080 0200202D */   daddu    $a0, $s0, $zero
/* 32DD94 E0012084 27A40018 */  addiu     $a0, $sp, 0x18
/* 32DD98 E0012088 0200282D */  daddu     $a1, $s0, $zero
/* 32DD9C E001208C 0C080114 */  jal       shim_guMtxCatF
/* 32DDA0 E0012090 0080302D */   daddu    $a2, $a0, $zero
/* 32DDA4 E0012094 8E250018 */  lw        $a1, 0x18($s1)
/* 32DDA8 E0012098 8E26001C */  lw        $a2, 0x1c($s1)
/* 32DDAC E001209C 8E270020 */  lw        $a3, 0x20($s1)
/* 32DDB0 E00120A0 0C080110 */  jal       shim_guScaleF
/* 32DDB4 E00120A4 0200202D */   daddu    $a0, $s0, $zero
/* 32DDB8 E00120A8 0200202D */  daddu     $a0, $s0, $zero
/* 32DDBC E00120AC 27A50018 */  addiu     $a1, $sp, 0x18
/* 32DDC0 E00120B0 0C080114 */  jal       shim_guMtxCatF
/* 32DDC4 E00120B4 00A0302D */   daddu    $a2, $a1, $zero
/* 32DDC8 E00120B8 8E25000C */  lw        $a1, 0xc($s1)
/* 32DDCC E00120BC 8E260010 */  lw        $a2, 0x10($s1)
/* 32DDD0 E00120C0 8E270014 */  lw        $a3, 0x14($s1)
/* 32DDD4 E00120C4 0C080108 */  jal       shim_guTranslateF
/* 32DDD8 E00120C8 0200202D */   daddu    $a0, $s0, $zero
/* 32DDDC E00120CC 27A40018 */  addiu     $a0, $sp, 0x18
/* 32DDE0 E00120D0 0200282D */  daddu     $a1, $s0, $zero
/* 32DDE4 E00120D4 0C080114 */  jal       shim_guMtxCatF
/* 32DDE8 E00120D8 0080302D */   daddu    $a2, $a0, $zero
/* 32DDEC E00120DC 27A40018 */  addiu     $a0, $sp, 0x18
/* 32DDF0 E00120E0 0C080118 */  jal       shim_guMtxF2L
/* 32DDF4 E00120E4 26250030 */   addiu    $a1, $s1, 0x30
/* 32DDF8 E00120E8 8FBF00A0 */  lw        $ra, 0xa0($sp)
/* 32DDFC E00120EC 8FB1009C */  lw        $s1, 0x9c($sp)
/* 32DE00 E00120F0 8FB00098 */  lw        $s0, 0x98($sp)
/* 32DE04 E00120F4 D7B600B0 */  ldc1      $f22, 0xb0($sp)
/* 32DE08 E00120F8 D7B400A8 */  ldc1      $f20, 0xa8($sp)
/* 32DE0C E00120FC 03E00008 */  jr        $ra
/* 32DE10 E0012100 27BD00B8 */   addiu    $sp, $sp, 0xb8
