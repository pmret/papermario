.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E0018000
/* 32F580 E0018000 27BDFF58 */  addiu     $sp, $sp, -0xa8
/* 32F584 E0018004 AFB00098 */  sw        $s0, 0x98($sp)
/* 32F588 E0018008 0080802D */  daddu     $s0, $a0, $zero
/* 32F58C E001800C AFBF00A0 */  sw        $ra, 0xa0($sp)
/* 32F590 E0018010 AFB1009C */  sw        $s1, 0x9c($sp)
/* 32F594 E0018014 8E05000C */  lw        $a1, 0xc($s0)
/* 32F598 E0018018 8E060010 */  lw        $a2, 0x10($s0)
/* 32F59C E001801C 8E070014 */  lw        $a3, 0x14($s0)
/* 32F5A0 E0018020 0C080108 */  jal       func_E0200420
/* 32F5A4 E0018024 27A40018 */   addiu    $a0, $sp, 0x18
/* 32F5A8 E0018028 3C073F80 */  lui       $a3, 0x3f80
/* 32F5AC E001802C 44800000 */  mtc1      $zero, $f0
/* 32F5B0 E0018030 27B10058 */  addiu     $s1, $sp, 0x58
/* 32F5B4 E0018034 E7A00010 */  swc1      $f0, 0x10($sp)
/* 32F5B8 E0018038 8E050028 */  lw        $a1, 0x28($s0)
/* 32F5BC E001803C 44060000 */  mfc1      $a2, $f0
/* 32F5C0 E0018040 0C080104 */  jal       func_E0200410
/* 32F5C4 E0018044 0220202D */   daddu    $a0, $s1, $zero
/* 32F5C8 E0018048 0220202D */  daddu     $a0, $s1, $zero
/* 32F5CC E001804C 27A50018 */  addiu     $a1, $sp, 0x18
/* 32F5D0 E0018050 0C080114 */  jal       func_E0200450
/* 32F5D4 E0018054 00A0302D */   daddu    $a2, $a1, $zero
/* 32F5D8 E0018058 27A40018 */  addiu     $a0, $sp, 0x18
/* 32F5DC E001805C 0C080118 */  jal       func_E0200460
/* 32F5E0 E0018060 26050030 */   addiu    $a1, $s0, 0x30
/* 32F5E4 E0018064 8FBF00A0 */  lw        $ra, 0xa0($sp)
/* 32F5E8 E0018068 8FB1009C */  lw        $s1, 0x9c($sp)
/* 32F5EC E001806C 8FB00098 */  lw        $s0, 0x98($sp)
/* 32F5F0 E0018070 03E00008 */  jr        $ra
/* 32F5F4 E0018074 27BD00A8 */   addiu    $sp, $sp, 0xa8
