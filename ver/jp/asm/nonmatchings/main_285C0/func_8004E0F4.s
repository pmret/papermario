.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004E0F4
/* 294F4 8004E0F4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 294F8 8004E0F8 AFB10014 */  sw        $s1, 0x14($sp)
/* 294FC 8004E0FC 0080882D */  daddu     $s1, $a0, $zero
/* 29500 8004E100 AFBF001C */  sw        $ra, 0x1c($sp)
/* 29504 8004E104 AFB20018 */  sw        $s2, 0x18($sp)
/* 29508 8004E108 AFB00010 */  sw        $s0, 0x10($sp)
/* 2950C 8004E10C 9623002C */  lhu       $v1, 0x2c($s1)
/* 29510 8004E110 9622003C */  lhu       $v0, 0x3c($s1)
/* 29514 8004E114 00620018 */  mult      $v1, $v0
/* 29518 8004E118 0000802D */  daddu     $s0, $zero, $zero
/* 2951C 8004E11C 00003812 */  mflo      $a3
/* 29520 8004E120 000793C2 */  srl       $s2, $a3, 0xf
/* 29524 8004E124 02301021 */  addu      $v0, $s1, $s0
.L8004E128:
/* 29528 8004E128 8043004C */  lb        $v1, 0x4c($v0)
/* 2952C 8004E12C 9044004C */  lbu       $a0, 0x4c($v0)
/* 29530 8004E130 04600007 */  bltz      $v1, .L8004E150
/* 29534 8004E134 26100001 */   addiu    $s0, $s0, 1
/* 29538 8004E138 8E260048 */  lw        $a2, 0x48($s1)
/* 2953C 8004E13C 0C014DD2 */  jal       func_80053748
/* 29540 8004E140 3245FFFF */   andi     $a1, $s2, 0xffff
/* 29544 8004E144 2A020004 */  slti      $v0, $s0, 4
/* 29548 8004E148 1440FFF7 */  bnez      $v0, .L8004E128
/* 2954C 8004E14C 02301021 */   addu     $v0, $s1, $s0
.L8004E150:
/* 29550 8004E150 8FBF001C */  lw        $ra, 0x1c($sp)
/* 29554 8004E154 8FB20018 */  lw        $s2, 0x18($sp)
/* 29558 8004E158 8FB10014 */  lw        $s1, 0x14($sp)
/* 2955C 8004E15C 8FB00010 */  lw        $s0, 0x10($sp)
/* 29560 8004E160 03E00008 */  jr        $ra
/* 29564 8004E164 27BD0020 */   addiu    $sp, $sp, 0x20
