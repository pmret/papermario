.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802D3FC8
/* F8978 802D3FC8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* F897C 802D3FCC AFB10014 */  sw        $s1, 0x14($sp)
/* F8980 802D3FD0 0080882D */  daddu     $s1, $a0, $zero
/* F8984 802D3FD4 AFBF0018 */  sw        $ra, 0x18($sp)
/* F8988 802D3FD8 AFB00010 */  sw        $s0, 0x10($sp)
/* F898C 802D3FDC 8E30000C */  lw        $s0, 0xc($s1)
/* F8990 802D3FE0 8E050000 */  lw        $a1, ($s0)
/* F8994 802D3FE4 0C0B1EAF */  jal       get_variable
/* F8998 802D3FE8 26100004 */   addiu    $s0, $s0, 4
/* F899C 802D3FEC 0220202D */  daddu     $a0, $s1, $zero
/* F89A0 802D3FF0 8E050004 */  lw        $a1, 4($s0)
/* F89A4 802D3FF4 8E100000 */  lw        $s0, ($s0)
/* F89A8 802D3FF8 0C0B1EAF */  jal       get_variable
/* F89AC 802D3FFC 0040882D */   daddu    $s1, $v0, $zero
/* F89B0 802D4000 3C03802E */  lui       $v1, %hi(D_802DB7C0)
/* F89B4 802D4004 8C63B7C0 */  lw        $v1, %lo(D_802DB7C0)($v1)
/* F89B8 802D4008 00118880 */  sll       $s1, $s1, 2
/* F89BC 802D400C 02238821 */  addu      $s1, $s1, $v1
/* F89C0 802D4010 10400006 */  beqz      $v0, .L802D402C
/* F89C4 802D4014 8E240000 */   lw       $a0, ($s1)
/* F89C8 802D4018 8C840000 */  lw        $a0, ($a0)
/* F89CC 802D401C 0C048BBA */  jal       func_80122EE8
/* F89D0 802D4020 0200282D */   daddu    $a1, $s0, $zero
/* F89D4 802D4024 080B500E */  j         .L802D4038
/* F89D8 802D4028 00000000 */   nop
.L802D402C:
/* F89DC 802D402C 8C840000 */  lw        $a0, ($a0)
/* F89E0 802D4030 0C048BC9 */  jal       func_80122F24
/* F89E4 802D4034 0200282D */   daddu    $a1, $s0, $zero
.L802D4038:
/* F89E8 802D4038 8FBF0018 */  lw        $ra, 0x18($sp)
/* F89EC 802D403C 8FB10014 */  lw        $s1, 0x14($sp)
/* F89F0 802D4040 8FB00010 */  lw        $s0, 0x10($sp)
/* F89F4 802D4044 24020002 */  addiu     $v0, $zero, 2
/* F89F8 802D4048 03E00008 */  jr        $ra
/* F89FC 802D404C 27BD0020 */   addiu    $sp, $sp, 0x20
