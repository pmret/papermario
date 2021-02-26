.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8003E674
/* 19A74 8003E674 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 19A78 8003E678 AFB00010 */  sw        $s0, 0x10($sp)
/* 19A7C 8003E67C 0080802D */  daddu     $s0, $a0, $zero
/* 19A80 8003E680 AFBF0018 */  sw        $ra, 0x18($sp)
/* 19A84 8003E684 AFB10014 */  sw        $s1, 0x14($sp)
/* 19A88 8003E688 8E020044 */  lw        $v0, 0x44($s0)
/* 19A8C 8003E68C 10400004 */  beqz      $v0, .L8003E6A0
/* 19A90 8003E690 00A0882D */   daddu    $s1, $a1, $zero
/* 19A94 8003E694 8C440144 */  lw        $a0, 0x144($v0)
/* 19A98 8003E698 0C0B102B */  jal       func_802C40AC
/* 19A9C 8003E69C 00000000 */   nop
.L8003E6A0:
/* 19AA0 8003E6A0 0220202D */  daddu     $a0, $s1, $zero
/* 19AA4 8003E6A4 2405000A */  addiu     $a1, $zero, 0xa
/* 19AA8 8003E6A8 0000302D */  daddu     $a2, $zero, $zero
/* 19AAC 8003E6AC 0C0B0CF8 */  jal       func_802C33E0
/* 19AB0 8003E6B0 AE04002C */   sw       $a0, 0x2c($s0)
/* 19AB4 8003E6B4 0040182D */  daddu     $v1, $v0, $zero
/* 19AB8 8003E6B8 AE030044 */  sw        $v1, 0x44($s0)
/* 19ABC 8003E6BC 8C620144 */  lw        $v0, 0x144($v1)
/* 19AC0 8003E6C0 AE02005C */  sw        $v0, 0x5c($s0)
/* 19AC4 8003E6C4 AC700148 */  sw        $s0, 0x148($v1)
/* 19AC8 8003E6C8 8FBF0018 */  lw        $ra, 0x18($sp)
/* 19ACC 8003E6CC 8FB10014 */  lw        $s1, 0x14($sp)
/* 19AD0 8003E6D0 8FB00010 */  lw        $s0, 0x10($sp)
/* 19AD4 8003E6D4 03E00008 */  jr        $ra
/* 19AD8 8003E6D8 27BD0020 */   addiu    $sp, $sp, 0x20
