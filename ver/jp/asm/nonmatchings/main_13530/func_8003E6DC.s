.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8003E6DC
/* 19ADC 8003E6DC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 19AE0 8003E6E0 AFB00010 */  sw        $s0, 0x10($sp)
/* 19AE4 8003E6E4 0080802D */  daddu     $s0, $a0, $zero
/* 19AE8 8003E6E8 AFBF0018 */  sw        $ra, 0x18($sp)
/* 19AEC 8003E6EC AFB10014 */  sw        $s1, 0x14($sp)
/* 19AF0 8003E6F0 8E020038 */  lw        $v0, 0x38($s0)
/* 19AF4 8003E6F4 10400004 */  beqz      $v0, .L8003E708
/* 19AF8 8003E6F8 00A0882D */   daddu    $s1, $a1, $zero
/* 19AFC 8003E6FC 8C440144 */  lw        $a0, 0x144($v0)
/* 19B00 8003E700 0C0B102B */  jal       func_802C40AC
/* 19B04 8003E704 00000000 */   nop
.L8003E708:
/* 19B08 8003E708 0220202D */  daddu     $a0, $s1, $zero
/* 19B0C 8003E70C 2405000A */  addiu     $a1, $zero, 0xa
/* 19B10 8003E710 0000302D */  daddu     $a2, $zero, $zero
/* 19B14 8003E714 0C0B0CF8 */  jal       func_802C33E0
/* 19B18 8003E718 AE040020 */   sw       $a0, 0x20($s0)
/* 19B1C 8003E71C 0040182D */  daddu     $v1, $v0, $zero
/* 19B20 8003E720 AE030038 */  sw        $v1, 0x38($s0)
/* 19B24 8003E724 8C620144 */  lw        $v0, 0x144($v1)
/* 19B28 8003E728 AE020050 */  sw        $v0, 0x50($s0)
/* 19B2C 8003E72C AC700148 */  sw        $s0, 0x148($v1)
/* 19B30 8003E730 8FBF0018 */  lw        $ra, 0x18($sp)
/* 19B34 8003E734 8FB10014 */  lw        $s1, 0x14($sp)
/* 19B38 8003E738 8FB00010 */  lw        $s0, 0x10($sp)
/* 19B3C 8003E73C 03E00008 */  jr        $ra
/* 19B40 8003E740 27BD0020 */   addiu    $sp, $sp, 0x20
