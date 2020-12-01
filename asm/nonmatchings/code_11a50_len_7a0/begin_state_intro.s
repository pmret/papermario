.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel begin_state_intro
/* 11A50 80036650 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 11A54 80036654 AFB10014 */  sw        $s1, 0x14($sp)
/* 11A58 80036658 3C118007 */  lui       $s1, %hi(gGameStatusPtr)
/* 11A5C 8003665C 2631419C */  addiu     $s1, $s1, %lo(gGameStatusPtr)
/* 11A60 80036660 AFBF0018 */  sw        $ra, 0x18($sp)
/* 11A64 80036664 AFB00010 */  sw        $s0, 0x10($sp)
/* 11A68 80036668 8E220000 */  lw        $v0, ($s1)
/* 11A6C 8003666C 3C013F80 */  lui       $at, 0x3f80
/* 11A70 80036670 44816000 */  mtc1      $at, $f12
/* 11A74 80036674 0C00AFB7 */  jal       set_curtain_scale_goal
/* 11A78 80036678 A04000AC */   sb       $zero, 0xac($v0)
/* 11A7C 8003667C 3C013E99 */  lui       $at, 0x3e99
/* 11A80 80036680 3421999A */  ori       $at, $at, 0x999a
/* 11A84 80036684 44816000 */  mtc1      $at, $f12
/* 11A88 80036688 0C00AFC5 */  jal       set_curtain_fade_goal
/* 11A8C 8003668C 00000000 */   nop
/* 11A90 80036690 8E220000 */  lw        $v0, ($s1)
/* 11A94 80036694 805000A8 */  lb        $s0, 0xa8($v0)
/* 11A98 80036698 12000005 */  beqz      $s0, .L800366B0
/* 11A9C 8003669C 24020001 */   addiu    $v0, $zero, 1
/* 11AA0 800366A0 12020020 */  beq       $s0, $v0, .L80036724
/* 11AA4 800366A4 00000000 */   nop
/* 11AA8 800366A8 0800D9E3 */  j         .L8003678C
/* 11AAC 800366AC 00000000 */   nop
.L800366B0:
/* 11AB0 800366B0 0C00CDF4 */  jal       intro_logos_set_fade_alpha
/* 11AB4 800366B4 0000202D */   daddu    $a0, $zero, $zero
/* 11AB8 800366B8 240200FF */  addiu     $v0, $zero, 0xff
/* 11ABC 800366BC 3C01800A */  lui       $at, %hi(D_800A0954)
/* 11AC0 800366C0 A4220954 */  sh        $v0, %lo(D_800A0954)($at)
/* 11AC4 800366C4 24020010 */  addiu     $v0, $zero, 0x10
/* 11AC8 800366C8 3C01800A */  lui       $at, %hi(D_800A0956)
/* 11ACC 800366CC A4220956 */  sh        $v0, %lo(D_800A0956)($at)
/* 11AD0 800366D0 24020004 */  addiu     $v0, $zero, 4
/* 11AD4 800366D4 3C01800A */  lui       $at, %hi(D_800A0958)
/* 11AD8 800366D8 A4220958 */  sh        $v0, %lo(D_800A0958)($at)
/* 11ADC 800366DC 240200D0 */  addiu     $v0, $zero, 0xd0
/* 11AE0 800366E0 3C01800A */  lui       $at, %hi(D_800A0960)
/* 11AE4 800366E4 AC200960 */  sw        $zero, %lo(D_800A0960)($at)
/* 11AE8 800366E8 3C01800A */  lui       $at, %hi(D_800A095A)
/* 11AEC 800366EC A422095A */  sh        $v0, %lo(D_800A095A)($at)
/* 11AF0 800366F0 3C01800A */  lui       $at, %hi(D_800A095C)
/* 11AF4 800366F4 A422095C */  sh        $v0, %lo(D_800A095C)($at)
/* 11AF8 800366F8 3C01800A */  lui       $at, %hi(D_800A095E)
/* 11AFC 800366FC A422095E */  sh        $v0, %lo(D_800A095E)($at)
/* 11B00 80036700 3C01800A */  lui       $at, %hi(D_800A0964)
/* 11B04 80036704 AC200964 */  sw        $zero, %lo(D_800A0964)($at)
/* 11B08 80036708 8E230000 */  lw        $v1, ($s1)
/* 11B0C 8003670C 24020005 */  addiu     $v0, $zero, 5
/* 11B10 80036710 A4620086 */  sh        $v0, 0x86($v1)
/* 11B14 80036714 A462008C */  sh        $v0, 0x8c($v1)
/* 11B18 80036718 24020003 */  addiu     $v0, $zero, 3
/* 11B1C 8003671C 0800D9FC */  j         .L800367F0
/* 11B20 80036720 A462008E */   sh       $v0, 0x8e($v1)
.L80036724:
/* 11B24 80036724 0C00CDF4 */  jal       intro_logos_set_fade_alpha
/* 11B28 80036728 0000202D */   daddu    $a0, $zero, $zero
/* 11B2C 8003672C 2402000C */  addiu     $v0, $zero, 0xc
/* 11B30 80036730 24040004 */  addiu     $a0, $zero, 4
/* 11B34 80036734 3C01800A */  lui       $at, %hi(D_800A0954)
/* 11B38 80036738 A4200954 */  sh        $zero, %lo(D_800A0954)($at)
/* 11B3C 8003673C 3C01800A */  lui       $at, %hi(D_800A0956)
/* 11B40 80036740 A4220956 */  sh        $v0, %lo(D_800A0956)($at)
/* 11B44 80036744 3C01800A */  lui       $at, %hi(D_800A0958)
/* 11B48 80036748 A4240958 */  sh        $a0, %lo(D_800A0958)($at)
/* 11B4C 8003674C 3C01800A */  lui       $at, %hi(D_800A0960)
/* 11B50 80036750 AC300960 */  sw        $s0, %lo(D_800A0960)($at)
/* 11B54 80036754 3C01800A */  lui       $at, %hi(D_800A095A)
/* 11B58 80036758 A420095A */  sh        $zero, %lo(D_800A095A)($at)
/* 11B5C 8003675C 3C01800A */  lui       $at, %hi(D_800A095C)
/* 11B60 80036760 A420095C */  sh        $zero, %lo(D_800A095C)($at)
/* 11B64 80036764 3C01800A */  lui       $at, %hi(D_800A095E)
/* 11B68 80036768 A420095E */  sh        $zero, %lo(D_800A095E)($at)
/* 11B6C 8003676C 3C01800A */  lui       $at, %hi(D_800A0964)
/* 11B70 80036770 AC200964 */  sw        $zero, %lo(D_800A0964)($at)
/* 11B74 80036774 8E220000 */  lw        $v0, ($s1)
/* 11B78 80036778 24030005 */  addiu     $v1, $zero, 5
/* 11B7C 8003677C A4430086 */  sh        $v1, 0x86($v0)
/* 11B80 80036780 A444008C */  sh        $a0, 0x8c($v0)
/* 11B84 80036784 0800D9FC */  j         .L800367F0
/* 11B88 80036788 A444008E */   sh       $a0, 0x8e($v0)
.L8003678C:
/* 11B8C 8003678C 0C00CDF4 */  jal       intro_logos_set_fade_alpha
/* 11B90 80036790 0000202D */   daddu    $a0, $zero, $zero
/* 11B94 80036794 0C00CDF8 */  jal       intro_logos_set_fade_color
/* 11B98 80036798 240400D0 */   addiu    $a0, $zero, 0xd0
/* 11B9C 8003679C 2402FFFF */  addiu     $v0, $zero, -1
/* 11BA0 800367A0 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* 11BA4 800367A4 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* 11BA8 800367A8 3C048007 */  lui       $a0, %hi(D_800779B0)
/* 11BAC 800367AC 248479B0 */  addiu     $a0, $a0, %lo(D_800779B0)
/* 11BB0 800367B0 A06200A8 */  sb        $v0, 0xa8($v1)
/* 11BB4 800367B4 90820000 */  lbu       $v0, ($a0)
/* 11BB8 800367B8 24030006 */  addiu     $v1, $zero, 6
/* 11BBC 800367BC 3C01800A */  lui       $at, %hi(D_800A0956)
/* 11BC0 800367C0 A4230956 */  sh        $v1, %lo(D_800A0956)($at)
/* 11BC4 800367C4 3C01800A */  lui       $at, %hi(D_800A0958)
/* 11BC8 800367C8 A4230958 */  sh        $v1, %lo(D_800A0958)($at)
/* 11BCC 800367CC 24420001 */  addiu     $v0, $v0, 1
/* 11BD0 800367D0 A0820000 */  sb        $v0, ($a0)
/* 11BD4 800367D4 304200FF */  andi      $v0, $v0, 0xff
/* 11BD8 800367D8 2C420004 */  sltiu     $v0, $v0, 4
/* 11BDC 800367DC 50400001 */  beql      $v0, $zero, .L800367E4
/* 11BE0 800367E0 A0800000 */   sb       $zero, ($a0)
.L800367E4:
/* 11BE4 800367E4 24020003 */  addiu     $v0, $zero, 3
/* 11BE8 800367E8 3C01800A */  lui       $at, %hi(D_800A0964)
/* 11BEC 800367EC AC220964 */  sw        $v0, %lo(D_800A0964)($at)
.L800367F0:
/* 11BF0 800367F0 3C02800A */  lui       $v0, %hi(D_800A0954)
/* 11BF4 800367F4 84420954 */  lh        $v0, %lo(D_800A0954)($v0)
/* 11BF8 800367F8 3C04800A */  lui       $a0, %hi(D_800A0963)
/* 11BFC 800367FC 90840963 */  lbu       $a0, %lo(D_800A0963)($a0)
/* 11C00 80036800 44820000 */  mtc1      $v0, $f0
/* 11C04 80036804 00000000 */  nop
/* 11C08 80036808 46800020 */  cvt.s.w   $f0, $f0
/* 11C0C 8003680C 44050000 */  mfc1      $a1, $f0
/* 11C10 80036810 0C04DF69 */  jal       func_80137DA4
/* 11C14 80036814 00000000 */   nop
/* 11C18 80036818 3C05800A */  lui       $a1, %hi(D_800A095B)
/* 11C1C 8003681C 90A5095B */  lbu       $a1, %lo(D_800A095B)($a1)
/* 11C20 80036820 3C06800A */  lui       $a2, %hi(D_800A095D)
/* 11C24 80036824 90C6095D */  lbu       $a2, %lo(D_800A095D)($a2)
/* 11C28 80036828 3C07800A */  lui       $a3, 0x800a
/* 11C2C 8003682C 90E7095F */  lbu       $a3, 0x95f($a3)
/* 11C30 80036830 0C04DF84 */  jal       func_80137E10
/* 11C34 80036834 24040001 */   addiu    $a0, $zero, 1
/* 11C38 80036838 0C00CE1D */  jal       intro_logos_update_fade
/* 11C3C 8003683C 00000000 */   nop
/* 11C40 80036840 8FBF0018 */  lw        $ra, 0x18($sp)
/* 11C44 80036844 8FB10014 */  lw        $s1, 0x14($sp)
/* 11C48 80036848 8FB00010 */  lw        $s0, 0x10($sp)
/* 11C4C 8003684C 03E00008 */  jr        $ra
/* 11C50 80036850 27BD0020 */   addiu    $sp, $sp, 0x20
