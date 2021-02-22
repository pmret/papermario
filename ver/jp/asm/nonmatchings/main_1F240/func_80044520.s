.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80044520
/* 1F920 80044520 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 1F924 80044524 AFB00010 */  sw        $s0, 0x10($sp)
/* 1F928 80044528 0080802D */  daddu     $s0, $a0, $zero
/* 1F92C 8004452C AFBF0014 */  sw        $ra, 0x14($sp)
/* 1F930 80044530 8E02000C */  lw        $v0, 0xc($s0)
/* 1F934 80044534 0C0B1EAF */  jal       func_802C7ABC
/* 1F938 80044538 8C450000 */   lw       $a1, ($v0)
/* 1F93C 8004453C 0200202D */  daddu     $a0, $s0, $zero
/* 1F940 80044540 0C0110DD */  jal       func_80044374
/* 1F944 80044544 0040282D */   daddu    $a1, $v0, $zero
/* 1F948 80044548 8FBF0014 */  lw        $ra, 0x14($sp)
/* 1F94C 8004454C 8FB00010 */  lw        $s0, 0x10($sp)
/* 1F950 80044550 24020001 */  addiu     $v0, $zero, 1
/* 1F954 80044554 03E00008 */  jr        $ra
/* 1F958 80044558 27BD0018 */   addiu    $sp, $sp, 0x18
