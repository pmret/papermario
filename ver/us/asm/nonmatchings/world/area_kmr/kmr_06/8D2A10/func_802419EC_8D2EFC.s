.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802419EC_8D2EFC
/* 8D2EFC 802419EC 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 8D2F00 802419F0 AFB10014 */  sw        $s1, 0x14($sp)
/* 8D2F04 802419F4 0080882D */  daddu     $s1, $a0, $zero
/* 8D2F08 802419F8 AFBF0018 */  sw        $ra, 0x18($sp)
/* 8D2F0C 802419FC AFB00010 */  sw        $s0, 0x10($sp)
/* 8D2F10 80241A00 F7B60028 */  sdc1      $f22, 0x28($sp)
/* 8D2F14 80241A04 F7B40020 */  sdc1      $f20, 0x20($sp)
/* 8D2F18 80241A08 8E30000C */  lw        $s0, 0xc($s1)
/* 8D2F1C 80241A0C 8E050000 */  lw        $a1, ($s0)
/* 8D2F20 80241A10 0C0B210B */  jal       evt_get_float_variable
/* 8D2F24 80241A14 26100004 */   addiu    $s0, $s0, 4
/* 8D2F28 80241A18 0220202D */  daddu     $a0, $s1, $zero
/* 8D2F2C 80241A1C 8E050000 */  lw        $a1, ($s0)
/* 8D2F30 80241A20 0C0B210B */  jal       evt_get_float_variable
/* 8D2F34 80241A24 46000586 */   mov.s    $f22, $f0
/* 8D2F38 80241A28 0220202D */  daddu     $a0, $s1, $zero
/* 8D2F3C 80241A2C 3C05FD05 */  lui       $a1, 0xfd05
/* 8D2F40 80241A30 34A50F8A */  ori       $a1, $a1, 0xf8a
/* 8D2F44 80241A34 0C0B1EAF */  jal       get_variable
/* 8D2F48 80241A38 46000506 */   mov.s    $f20, $f0
/* 8D2F4C 80241A3C 0040182D */  daddu     $v1, $v0, $zero
/* 8D2F50 80241A40 E4760014 */  swc1      $f22, 0x14($v1)
/* 8D2F54 80241A44 E4740018 */  swc1      $f20, 0x18($v1)
/* 8D2F58 80241A48 8FBF0018 */  lw        $ra, 0x18($sp)
/* 8D2F5C 80241A4C 8FB10014 */  lw        $s1, 0x14($sp)
/* 8D2F60 80241A50 8FB00010 */  lw        $s0, 0x10($sp)
/* 8D2F64 80241A54 D7B60028 */  ldc1      $f22, 0x28($sp)
/* 8D2F68 80241A58 D7B40020 */  ldc1      $f20, 0x20($sp)
/* 8D2F6C 80241A5C 24020002 */  addiu     $v0, $zero, 2
/* 8D2F70 80241A60 03E00008 */  jr        $ra
/* 8D2F74 80241A64 27BD0030 */   addiu    $sp, $sp, 0x30
