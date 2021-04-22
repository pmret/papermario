.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004D6BC
/* 28ABC 8004D6BC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 28AC0 8004D6C0 AFB10014 */  sw        $s1, 0x14($sp)
/* 28AC4 8004D6C4 0080882D */  daddu     $s1, $a0, $zero
/* 28AC8 8004D6C8 AFB00010 */  sw        $s0, 0x10($sp)
/* 28ACC 8004D6CC 0000802D */  daddu     $s0, $zero, $zero
/* 28AD0 8004D6D0 1220000D */  beqz      $s1, .L8004D708
/* 28AD4 8004D6D4 AFBF0018 */   sw       $ra, 0x18($sp)
/* 28AD8 8004D6D8 0C013511 */  jal       func_8004D444
/* 28ADC 8004D6DC 00000000 */   nop
/* 28AE0 8004D6E0 0040202D */  daddu     $a0, $v0, $zero
/* 28AE4 8004D6E4 50800009 */  beql      $a0, $zero, .L8004D70C
/* 28AE8 8004D6E8 24100002 */   addiu    $s0, $zero, 2
/* 28AEC 8004D6EC 8C82001C */  lw        $v0, 0x1c($a0)
/* 28AF0 8004D6F0 16220007 */  bne       $s1, $v0, .L8004D710
/* 28AF4 8004D6F4 0200102D */   daddu    $v0, $s0, $zero
/* 28AF8 8004D6F8 0C0135D6 */  jal       func_8004D758
/* 28AFC 8004D6FC 00000000 */   nop
/* 28B00 8004D700 080135C4 */  j         .L8004D710
/* 28B04 8004D704 0200102D */   daddu    $v0, $s0, $zero
.L8004D708:
/* 28B08 8004D708 24100003 */  addiu     $s0, $zero, 3
.L8004D70C:
/* 28B0C 8004D70C 0200102D */  daddu     $v0, $s0, $zero
.L8004D710:
/* 28B10 8004D710 8FBF0018 */  lw        $ra, 0x18($sp)
/* 28B14 8004D714 8FB10014 */  lw        $s1, 0x14($sp)
/* 28B18 8004D718 8FB00010 */  lw        $s0, 0x10($sp)
/* 28B1C 8004D71C 03E00008 */  jr        $ra
/* 28B20 8004D720 27BD0020 */   addiu    $sp, $sp, 0x20
