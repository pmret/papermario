.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802402A0_8DA3A0
/* 8DA3A0 802402A0 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* 8DA3A4 802402A4 AFB1001C */  sw        $s1, 0x1c($sp)
/* 8DA3A8 802402A8 0080882D */  daddu     $s1, $a0, $zero
/* 8DA3AC 802402AC AFBF0020 */  sw        $ra, 0x20($sp)
/* 8DA3B0 802402B0 AFB00018 */  sw        $s0, 0x18($sp)
/* 8DA3B4 802402B4 F7B80038 */  sdc1      $f24, 0x38($sp)
/* 8DA3B8 802402B8 F7B60030 */  sdc1      $f22, 0x30($sp)
/* 8DA3BC 802402BC F7B40028 */  sdc1      $f20, 0x28($sp)
/* 8DA3C0 802402C0 8E30000C */  lw        $s0, 0xc($s1)
/* 8DA3C4 802402C4 8E050000 */  lw        $a1, ($s0)
/* 8DA3C8 802402C8 0C0B210B */  jal       get_float_variable
/* 8DA3CC 802402CC 26100004 */   addiu    $s0, $s0, 4
/* 8DA3D0 802402D0 8E050000 */  lw        $a1, ($s0)
/* 8DA3D4 802402D4 26100004 */  addiu     $s0, $s0, 4
/* 8DA3D8 802402D8 0220202D */  daddu     $a0, $s1, $zero
/* 8DA3DC 802402DC 0C0B210B */  jal       get_float_variable
/* 8DA3E0 802402E0 46000606 */   mov.s    $f24, $f0
/* 8DA3E4 802402E4 8E050000 */  lw        $a1, ($s0)
/* 8DA3E8 802402E8 26100004 */  addiu     $s0, $s0, 4
/* 8DA3EC 802402EC 0220202D */  daddu     $a0, $s1, $zero
/* 8DA3F0 802402F0 0C0B210B */  jal       get_float_variable
/* 8DA3F4 802402F4 46000586 */   mov.s    $f22, $f0
/* 8DA3F8 802402F8 0220202D */  daddu     $a0, $s1, $zero
/* 8DA3FC 802402FC 8E050000 */  lw        $a1, ($s0)
/* 8DA400 80240300 0C0B1EAF */  jal       get_variable
/* 8DA404 80240304 46000506 */   mov.s    $f20, $f0
/* 8DA408 80240308 4405C000 */  mfc1      $a1, $f24
/* 8DA40C 8024030C 4406B000 */  mfc1      $a2, $f22
/* 8DA410 80240310 4407A000 */  mfc1      $a3, $f20
/* 8DA414 80240314 0000202D */  daddu     $a0, $zero, $zero
/* 8DA418 80240318 0C01C094 */  jal       func_80070250
/* 8DA41C 8024031C AFA20010 */   sw       $v0, 0x10($sp)
/* 8DA420 80240320 8FBF0020 */  lw        $ra, 0x20($sp)
/* 8DA424 80240324 8FB1001C */  lw        $s1, 0x1c($sp)
/* 8DA428 80240328 8FB00018 */  lw        $s0, 0x18($sp)
/* 8DA42C 8024032C D7B80038 */  ldc1      $f24, 0x38($sp)
/* 8DA430 80240330 D7B60030 */  ldc1      $f22, 0x30($sp)
/* 8DA434 80240334 D7B40028 */  ldc1      $f20, 0x28($sp)
/* 8DA438 80240338 24020002 */  addiu     $v0, $zero, 2
/* 8DA43C 8024033C 03E00008 */  jr        $ra
/* 8DA440 80240340 27BD0040 */   addiu    $sp, $sp, 0x40
