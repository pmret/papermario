.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel osEPiWriteIo
/* 3C160 80060D60 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 3C164 80060D64 AFB00010 */  sw        $s0, 0x10($sp)
/* 3C168 80060D68 00808021 */  addu      $s0, $a0, $zero
/* 3C16C 80060D6C AFB10014 */  sw        $s1, 0x14($sp)
/* 3C170 80060D70 00A08821 */  addu      $s1, $a1, $zero
/* 3C174 80060D74 AFB20018 */  sw        $s2, 0x18($sp)
/* 3C178 80060D78 AFBF001C */  sw        $ra, 0x1c($sp)
/* 3C17C 80060D7C 0C018529 */  jal       osPiGetAccess
/* 3C180 80060D80 00C09021 */   addu     $s2, $a2, $zero
/* 3C184 80060D84 02002021 */  addu      $a0, $s0, $zero
/* 3C188 80060D88 02202821 */  addu      $a1, $s1, $zero
/* 3C18C 80060D8C 0C01ADB8 */  jal       osEPiRawWriteIo
/* 3C190 80060D90 02403021 */   addu     $a2, $s2, $zero
/* 3C194 80060D94 0C018544 */  jal       osPiRelAccess
/* 3C198 80060D98 00408021 */   addu     $s0, $v0, $zero
/* 3C19C 80060D9C 02001021 */  addu      $v0, $s0, $zero
/* 3C1A0 80060DA0 8FBF001C */  lw        $ra, 0x1c($sp)
/* 3C1A4 80060DA4 8FB20018 */  lw        $s2, 0x18($sp)
/* 3C1A8 80060DA8 8FB10014 */  lw        $s1, 0x14($sp)
/* 3C1AC 80060DAC 8FB00010 */  lw        $s0, 0x10($sp)
/* 3C1B0 80060DB0 03E00008 */  jr        $ra
/* 3C1B4 80060DB4 27BD0020 */   addiu    $sp, $sp, 0x20
/* 3C1B8 80060DB8 00000000 */  nop
/* 3C1BC 80060DBC 00000000 */  nop
