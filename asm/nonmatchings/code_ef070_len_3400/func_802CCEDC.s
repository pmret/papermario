.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802CCEDC
/* F188C 802CCEDC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* F1890 802CCEE0 AFB20018 */  sw        $s2, 0x18($sp)
/* F1894 802CCEE4 0080902D */  daddu     $s2, $a0, $zero
/* F1898 802CCEE8 AFBF001C */  sw        $ra, 0x1c($sp)
/* F189C 802CCEEC AFB10014 */  sw        $s1, 0x14($sp)
/* F18A0 802CCEF0 AFB00010 */  sw        $s0, 0x10($sp)
/* F18A4 802CCEF4 8E50000C */  lw        $s0, 0xc($s2)
/* F18A8 802CCEF8 8E050000 */  lw        $a1, ($s0)
/* F18AC 802CCEFC 0C0B1EAF */  jal       get_variable
/* F18B0 802CCF00 26100004 */   addiu    $s0, $s0, 4
/* F18B4 802CCF04 8E050000 */  lw        $a1, ($s0)
/* F18B8 802CCF08 26100004 */  addiu     $s0, $s0, 4
/* F18BC 802CCF0C 0240202D */  daddu     $a0, $s2, $zero
/* F18C0 802CCF10 0C0B1EAF */  jal       get_variable
/* F18C4 802CCF14 0040882D */   daddu    $s1, $v0, $zero
/* F18C8 802CCF18 0240202D */  daddu     $a0, $s2, $zero
/* F18CC 802CCF1C 8E050000 */  lw        $a1, ($s0)
/* F18D0 802CCF20 0C0B1EAF */  jal       get_variable
/* F18D4 802CCF24 0040802D */   daddu    $s0, $v0, $zero
/* F18D8 802CCF28 3C03802E */  lui       $v1, %hi(gAnimatedMeshesPtr)
/* F18DC 802CCF2C 8C63AE30 */  lw        $v1, %lo(gAnimatedMeshesPtr)($v1)
/* F18E0 802CCF30 00118880 */  sll       $s1, $s1, 2
/* F18E4 802CCF34 02238821 */  addu      $s1, $s1, $v1
/* F18E8 802CCF38 8E230000 */  lw        $v1, ($s1)
/* F18EC 802CCF3C 0200282D */  daddu     $a1, $s0, $zero
/* F18F0 802CCF40 8C640000 */  lw        $a0, ($v1)
/* F18F4 802CCF44 0040302D */  daddu     $a2, $v0, $zero
/* F18F8 802CCF48 0C048066 */  jal       func_80120198
/* F18FC 802CCF4C AC650068 */   sw       $a1, 0x68($v1)
/* F1900 802CCF50 8FBF001C */  lw        $ra, 0x1c($sp)
/* F1904 802CCF54 8FB20018 */  lw        $s2, 0x18($sp)
/* F1908 802CCF58 8FB10014 */  lw        $s1, 0x14($sp)
/* F190C 802CCF5C 8FB00010 */  lw        $s0, 0x10($sp)
/* F1910 802CCF60 24020002 */  addiu     $v0, $zero, 2
/* F1914 802CCF64 03E00008 */  jr        $ra
/* F1918 802CCF68 27BD0020 */   addiu    $sp, $sp, 0x20
