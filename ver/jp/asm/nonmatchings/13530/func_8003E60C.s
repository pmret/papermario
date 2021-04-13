.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8003E60C
/* 19A0C 8003E60C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 19A10 8003E610 AFB00010 */  sw        $s0, 0x10($sp)
/* 19A14 8003E614 0080802D */  daddu     $s0, $a0, $zero
/* 19A18 8003E618 AFBF0018 */  sw        $ra, 0x18($sp)
/* 19A1C 8003E61C AFB10014 */  sw        $s1, 0x14($sp)
/* 19A20 8003E620 8E02003C */  lw        $v0, 0x3c($s0)
/* 19A24 8003E624 10400004 */  beqz      $v0, .L8003E638
/* 19A28 8003E628 00A0882D */   daddu    $s1, $a1, $zero
/* 19A2C 8003E62C 8C440144 */  lw        $a0, 0x144($v0)
/* 19A30 8003E630 0C0B102B */  jal       func_802C40AC
/* 19A34 8003E634 00000000 */   nop
.L8003E638:
/* 19A38 8003E638 0220202D */  daddu     $a0, $s1, $zero
/* 19A3C 8003E63C 2405000A */  addiu     $a1, $zero, 0xa
/* 19A40 8003E640 0000302D */  daddu     $a2, $zero, $zero
/* 19A44 8003E644 0C0B0CF8 */  jal       func_802C33E0
/* 19A48 8003E648 AE040024 */   sw       $a0, 0x24($s0)
/* 19A4C 8003E64C 0040182D */  daddu     $v1, $v0, $zero
/* 19A50 8003E650 AE03003C */  sw        $v1, 0x3c($s0)
/* 19A54 8003E654 8C620144 */  lw        $v0, 0x144($v1)
/* 19A58 8003E658 AE020054 */  sw        $v0, 0x54($s0)
/* 19A5C 8003E65C AC700148 */  sw        $s0, 0x148($v1)
/* 19A60 8003E660 8FBF0018 */  lw        $ra, 0x18($sp)
/* 19A64 8003E664 8FB10014 */  lw        $s1, 0x14($sp)
/* 19A68 8003E668 8FB00010 */  lw        $s0, 0x10($sp)
/* 19A6C 8003E66C 03E00008 */  jr        $ra
/* 19A70 8003E670 27BD0020 */   addiu    $sp, $sp, 0x20
