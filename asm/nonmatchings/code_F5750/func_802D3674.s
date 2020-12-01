.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802D3674
/* F8024 802D3674 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* F8028 802D3678 AFB10014 */  sw        $s1, 0x14($sp)
/* F802C 802D367C 0080882D */  daddu     $s1, $a0, $zero
/* F8030 802D3680 AFBF0018 */  sw        $ra, 0x18($sp)
/* F8034 802D3684 AFB00010 */  sw        $s0, 0x10($sp)
/* F8038 802D3688 8E30000C */  lw        $s0, 0xc($s1)
/* F803C 802D368C 8E050000 */  lw        $a1, ($s0)
/* F8040 802D3690 0C0B1EAF */  jal       get_variable
/* F8044 802D3694 26100004 */   addiu    $s0, $s0, 4
/* F8048 802D3698 0220202D */  daddu     $a0, $s1, $zero
/* F804C 802D369C 8E050000 */  lw        $a1, ($s0)
/* F8050 802D36A0 0C0B1EAF */  jal       get_variable
/* F8054 802D36A4 0040802D */   daddu    $s0, $v0, $zero
/* F8058 802D36A8 3C03802E */  lui       $v1, %hi(D_802DB7C0)
/* F805C 802D36AC 8C63B7C0 */  lw        $v1, %lo(D_802DB7C0)($v1)
/* F8060 802D36B0 00108080 */  sll       $s0, $s0, 2
/* F8064 802D36B4 02038021 */  addu      $s0, $s0, $v1
/* F8068 802D36B8 8E030000 */  lw        $v1, ($s0)
/* F806C 802D36BC 8C640000 */  lw        $a0, ($v1)
/* F8070 802D36C0 0C048B5F */  jal       func_80122D7C
/* F8074 802D36C4 0040282D */   daddu    $a1, $v0, $zero
/* F8078 802D36C8 8FBF0018 */  lw        $ra, 0x18($sp)
/* F807C 802D36CC 8FB10014 */  lw        $s1, 0x14($sp)
/* F8080 802D36D0 8FB00010 */  lw        $s0, 0x10($sp)
/* F8084 802D36D4 24020002 */  addiu     $v0, $zero, 2
/* F8088 802D36D8 03E00008 */  jr        $ra
/* F808C 802D36DC 27BD0020 */   addiu    $sp, $sp, 0x20
