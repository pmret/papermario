.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E0010000
/* 32C7A0 E0010000 27BDFF48 */  addiu     $sp, $sp, -0xb8
/* 32C7A4 E0010004 F7B400A8 */  sdc1      $f20, 0xa8($sp)
/* 32C7A8 E0010008 4480A000 */  mtc1      $zero, $f20
/* 32C7AC E001000C F7B600B0 */  sdc1      $f22, 0xb0($sp)
/* 32C7B0 E0010010 3C013F80 */  lui       $at, 0x3f80
/* 32C7B4 E0010014 4481B000 */  mtc1      $at, $f22
/* 32C7B8 E0010018 AFB1009C */  sw        $s1, 0x9c($sp)
/* 32C7BC E001001C 0080882D */  daddu     $s1, $a0, $zero
/* 32C7C0 E0010020 AFBF00A0 */  sw        $ra, 0xa0($sp)
/* 32C7C4 E0010024 AFB00098 */  sw        $s0, 0x98($sp)
/* 32C7C8 E0010028 E7B40010 */  swc1      $f20, 0x10($sp)
/* 32C7CC E001002C 8E250024 */  lw        $a1, 0x24($s1)
/* 32C7D0 E0010030 4406B000 */  mfc1      $a2, $f22
/* 32C7D4 E0010034 4407A000 */  mfc1      $a3, $f20
/* 32C7D8 E0010038 0C080104 */  jal       shim_guRotateF
/* 32C7DC E001003C 27A40018 */   addiu    $a0, $sp, 0x18
/* 32C7E0 E0010040 27B00058 */  addiu     $s0, $sp, 0x58
/* 32C7E4 E0010044 E7B60010 */  swc1      $f22, 0x10($sp)
/* 32C7E8 E0010048 8E25002C */  lw        $a1, 0x2c($s1)
/* 32C7EC E001004C 4406A000 */  mfc1      $a2, $f20
/* 32C7F0 E0010050 4407A000 */  mfc1      $a3, $f20
/* 32C7F4 E0010054 0C080104 */  jal       shim_guRotateF
/* 32C7F8 E0010058 0200202D */   daddu    $a0, $s0, $zero
/* 32C7FC E001005C 0200202D */  daddu     $a0, $s0, $zero
/* 32C800 E0010060 27A50018 */  addiu     $a1, $sp, 0x18
/* 32C804 E0010064 0C080114 */  jal       shim_guMtxCatF
/* 32C808 E0010068 00A0302D */   daddu    $a2, $a1, $zero
/* 32C80C E001006C E7B40010 */  swc1      $f20, 0x10($sp)
/* 32C810 E0010070 8E250028 */  lw        $a1, 0x28($s1)
/* 32C814 E0010074 4406A000 */  mfc1      $a2, $f20
/* 32C818 E0010078 4407B000 */  mfc1      $a3, $f22
/* 32C81C E001007C 0C080104 */  jal       shim_guRotateF
/* 32C820 E0010080 0200202D */   daddu    $a0, $s0, $zero
/* 32C824 E0010084 27A40018 */  addiu     $a0, $sp, 0x18
/* 32C828 E0010088 0200282D */  daddu     $a1, $s0, $zero
/* 32C82C E001008C 0C080114 */  jal       shim_guMtxCatF
/* 32C830 E0010090 0080302D */   daddu    $a2, $a0, $zero
/* 32C834 E0010094 8E250018 */  lw        $a1, 0x18($s1)
/* 32C838 E0010098 8E26001C */  lw        $a2, 0x1c($s1)
/* 32C83C E001009C 8E270020 */  lw        $a3, 0x20($s1)
/* 32C840 E00100A0 0C080110 */  jal       shim_guScaleF
/* 32C844 E00100A4 0200202D */   daddu    $a0, $s0, $zero
/* 32C848 E00100A8 0200202D */  daddu     $a0, $s0, $zero
/* 32C84C E00100AC 27A50018 */  addiu     $a1, $sp, 0x18
/* 32C850 E00100B0 0C080114 */  jal       shim_guMtxCatF
/* 32C854 E00100B4 00A0302D */   daddu    $a2, $a1, $zero
/* 32C858 E00100B8 8E25000C */  lw        $a1, 0xc($s1)
/* 32C85C E00100BC 8E260010 */  lw        $a2, 0x10($s1)
/* 32C860 E00100C0 8E270014 */  lw        $a3, 0x14($s1)
/* 32C864 E00100C4 0C080108 */  jal       shim_guTranslateF
/* 32C868 E00100C8 0200202D */   daddu    $a0, $s0, $zero
/* 32C86C E00100CC 27A40018 */  addiu     $a0, $sp, 0x18
/* 32C870 E00100D0 0200282D */  daddu     $a1, $s0, $zero
/* 32C874 E00100D4 0C080114 */  jal       shim_guMtxCatF
/* 32C878 E00100D8 0080302D */   daddu    $a2, $a0, $zero
/* 32C87C E00100DC 27A40018 */  addiu     $a0, $sp, 0x18
/* 32C880 E00100E0 0C080118 */  jal       shim_guMtxF2L
/* 32C884 E00100E4 26250030 */   addiu    $a1, $s1, 0x30
/* 32C888 E00100E8 8FBF00A0 */  lw        $ra, 0xa0($sp)
/* 32C88C E00100EC 8FB1009C */  lw        $s1, 0x9c($sp)
/* 32C890 E00100F0 8FB00098 */  lw        $s0, 0x98($sp)
/* 32C894 E00100F4 D7B600B0 */  ldc1      $f22, 0xb0($sp)
/* 32C898 E00100F8 D7B400A8 */  ldc1      $f20, 0xa8($sp)
/* 32C89C E00100FC 03E00008 */  jr        $ra
/* 32C8A0 E0010100 27BD00B8 */   addiu    $sp, $sp, 0xb8
