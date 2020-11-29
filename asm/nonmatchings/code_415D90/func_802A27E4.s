.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A27E4
/* 417574 802A27E4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 417578 802A27E8 24040001 */  addiu     $a0, $zero, 1
/* 41757C 802A27EC 24050002 */  addiu     $a1, $zero, 2
/* 417580 802A27F0 AFBF0018 */  sw        $ra, 0x18($sp)
/* 417584 802A27F4 AFB10014 */  sw        $s1, 0x14($sp)
/* 417588 802A27F8 0C051F9F */  jal       func_80147E7C
/* 41758C 802A27FC AFB00010 */   sw       $s0, 0x10($sp)
/* 417590 802A2800 3C02802B */  lui       $v0, %hi(D_802AD4A0)
/* 417594 802A2804 8C42D4A0 */  lw        $v0, %lo(D_802AD4A0)($v0)
/* 417598 802A2808 54400006 */  bnel      $v0, $zero, .L802A2824
/* 41759C 802A280C 24040004 */   addiu    $a0, $zero, 4
/* 4175A0 802A2810 24040002 */  addiu     $a0, $zero, 2
/* 4175A4 802A2814 0C051F9F */  jal       func_80147E7C
/* 4175A8 802A2818 0080282D */   daddu    $a1, $a0, $zero
/* 4175AC 802A281C 080A8A0C */  j         .L802A2830
/* 4175B0 802A2820 24040003 */   addiu    $a0, $zero, 3
.L802A2824:
/* 4175B4 802A2824 0C051F9F */  jal       func_80147E7C
/* 4175B8 802A2828 24050002 */   addiu    $a1, $zero, 2
/* 4175BC 802A282C 24040005 */  addiu     $a0, $zero, 5
.L802A2830:
/* 4175C0 802A2830 0C051F9F */  jal       func_80147E7C
/* 4175C4 802A2834 24050002 */   addiu    $a1, $zero, 2
/* 4175C8 802A2838 24040008 */  addiu     $a0, $zero, 8
/* 4175CC 802A283C 0C051F9F */  jal       func_80147E7C
/* 4175D0 802A2840 24050002 */   addiu    $a1, $zero, 2
/* 4175D4 802A2844 3C02802B */  lui       $v0, %hi(D_802AD4A4)
/* 4175D8 802A2848 8C42D4A4 */  lw        $v0, %lo(D_802AD4A4)($v0)
/* 4175DC 802A284C 1840000C */  blez      $v0, .L802A2880
/* 4175E0 802A2850 0000802D */   daddu    $s0, $zero, $zero
/* 4175E4 802A2854 3C11802B */  lui       $s1, %hi(D_802AD128)
/* 4175E8 802A2858 2631D128 */  addiu     $s1, $s1, %lo(D_802AD128)
.L802A285C:
/* 4175EC 802A285C 8E240000 */  lw        $a0, ($s1)
/* 4175F0 802A2860 0C05123D */  jal       free_icon
/* 4175F4 802A2864 26310004 */   addiu    $s1, $s1, 4
/* 4175F8 802A2868 3C02802B */  lui       $v0, %hi(D_802AD4A4)
/* 4175FC 802A286C 8C42D4A4 */  lw        $v0, %lo(D_802AD4A4)($v0)
/* 417600 802A2870 26100001 */  addiu     $s0, $s0, 1
/* 417604 802A2874 0202102A */  slt       $v0, $s0, $v0
/* 417608 802A2878 1440FFF8 */  bnez      $v0, .L802A285C
/* 41760C 802A287C 00000000 */   nop      
.L802A2880:
/* 417610 802A2880 3C04802B */  lui       $a0, %hi(D_802AD118)
/* 417614 802A2884 8C84D118 */  lw        $a0, %lo(D_802AD118)($a0)
/* 417618 802A2888 0C05123D */  jal       free_icon
/* 41761C 802A288C 0000802D */   daddu    $s0, $zero, $zero
/* 417620 802A2890 3C04802B */  lui       $a0, %hi(D_802AD11C)
/* 417624 802A2894 8C84D11C */  lw        $a0, %lo(D_802AD11C)($a0)
/* 417628 802A2898 0C05123D */  jal       free_icon
/* 41762C 802A289C 00000000 */   nop      
/* 417630 802A28A0 3C04802B */  lui       $a0, %hi(D_802AD120)
/* 417634 802A28A4 8C84D120 */  lw        $a0, %lo(D_802AD120)($a0)
/* 417638 802A28A8 0C05123D */  jal       free_icon
/* 41763C 802A28AC 00000000 */   nop      
/* 417640 802A28B0 3C04802B */  lui       $a0, %hi(D_802AD188)
/* 417644 802A28B4 8C84D188 */  lw        $a0, %lo(D_802AD188)($a0)
/* 417648 802A28B8 0C05123D */  jal       free_icon
/* 41764C 802A28BC 00000000 */   nop      
/* 417650 802A28C0 3C02802B */  lui       $v0, %hi(D_802AD4A4)
/* 417654 802A28C4 8C42D4A4 */  lw        $v0, %lo(D_802AD4A4)($v0)
/* 417658 802A28C8 1840000C */  blez      $v0, .L802A28FC
/* 41765C 802A28CC 00000000 */   nop      
/* 417660 802A28D0 3C11802B */  lui       $s1, %hi(D_802AD190)
/* 417664 802A28D4 2631D190 */  addiu     $s1, $s1, %lo(D_802AD190)
.L802A28D8:
/* 417668 802A28D8 8E240000 */  lw        $a0, ($s1)
/* 41766C 802A28DC 0C05123D */  jal       free_icon
/* 417670 802A28E0 26310004 */   addiu    $s1, $s1, 4
/* 417674 802A28E4 3C02802B */  lui       $v0, %hi(D_802AD4A4)
/* 417678 802A28E8 8C42D4A4 */  lw        $v0, %lo(D_802AD4A4)($v0)
/* 41767C 802A28EC 26100001 */  addiu     $s0, $s0, 1
/* 417680 802A28F0 0202102A */  slt       $v0, $s0, $v0
/* 417684 802A28F4 1440FFF8 */  bnez      $v0, .L802A28D8
/* 417688 802A28F8 00000000 */   nop      
.L802A28FC:
/* 41768C 802A28FC 8FBF0018 */  lw        $ra, 0x18($sp)
/* 417690 802A2900 8FB10014 */  lw        $s1, 0x14($sp)
/* 417694 802A2904 8FB00010 */  lw        $s0, 0x10($sp)
/* 417698 802A2908 03E00008 */  jr        $ra
/* 41769C 802A290C 27BD0020 */   addiu    $sp, $sp, 0x20
