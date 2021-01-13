.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A2AB8
/* 417848 802A2AB8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 41784C 802A2ABC 24040001 */  addiu     $a0, $zero, 1
/* 417850 802A2AC0 24050005 */  addiu     $a1, $zero, 5
/* 417854 802A2AC4 AFBF0018 */  sw        $ra, 0x18($sp)
/* 417858 802A2AC8 AFB10014 */  sw        $s1, 0x14($sp)
/* 41785C 802A2ACC 0C051F9F */  jal       func_80147E7C
/* 417860 802A2AD0 AFB00010 */   sw       $s0, 0x10($sp)
/* 417864 802A2AD4 3C02802B */  lui       $v0, %hi(D_802AD4A0)
/* 417868 802A2AD8 8C42D4A0 */  lw        $v0, %lo(D_802AD4A0)($v0)
/* 41786C 802A2ADC 54400006 */  bnel      $v0, $zero, .L802A2AF8
/* 417870 802A2AE0 24040004 */   addiu    $a0, $zero, 4
/* 417874 802A2AE4 24040002 */  addiu     $a0, $zero, 2
/* 417878 802A2AE8 0C051F9F */  jal       func_80147E7C
/* 41787C 802A2AEC 24050005 */   addiu    $a1, $zero, 5
/* 417880 802A2AF0 080A8AC1 */  j         .L802A2B04
/* 417884 802A2AF4 24040003 */   addiu    $a0, $zero, 3
.L802A2AF8:
/* 417888 802A2AF8 0C051F9F */  jal       func_80147E7C
/* 41788C 802A2AFC 24050005 */   addiu    $a1, $zero, 5
/* 417890 802A2B00 24040005 */  addiu     $a0, $zero, 5
.L802A2B04:
/* 417894 802A2B04 0C051F9F */  jal       func_80147E7C
/* 417898 802A2B08 24050005 */   addiu    $a1, $zero, 5
/* 41789C 802A2B0C 24040008 */  addiu     $a0, $zero, 8
/* 4178A0 802A2B10 0C051F9F */  jal       func_80147E7C
/* 4178A4 802A2B14 24050001 */   addiu    $a1, $zero, 1
/* 4178A8 802A2B18 3C02802B */  lui       $v0, %hi(D_802AD4A4)
/* 4178AC 802A2B1C 8C42D4A4 */  lw        $v0, %lo(D_802AD4A4)($v0)
/* 4178B0 802A2B20 1840000F */  blez      $v0, .L802A2B60
/* 4178B4 802A2B24 0000802D */   daddu    $s0, $zero, $zero
/* 4178B8 802A2B28 3C11802B */  lui       $s1, %hi(D_802AD128)
/* 4178BC 802A2B2C 2631D128 */  addiu     $s1, $s1, %lo(D_802AD128)
/* 4178C0 802A2B30 240500FF */  addiu     $a1, $zero, 0xff
.L802A2B34:
/* 4178C4 802A2B34 00A0302D */  daddu     $a2, $a1, $zero
/* 4178C8 802A2B38 00A0382D */  daddu     $a3, $a1, $zero
/* 4178CC 802A2B3C 8E240000 */  lw        $a0, ($s1)
/* 4178D0 802A2B40 0C0513BF */  jal       icon_set_tint
/* 4178D4 802A2B44 26310004 */   addiu    $s1, $s1, 4
/* 4178D8 802A2B48 3C02802B */  lui       $v0, %hi(D_802AD4A4)
/* 4178DC 802A2B4C 8C42D4A4 */  lw        $v0, %lo(D_802AD4A4)($v0)
/* 4178E0 802A2B50 26100001 */  addiu     $s0, $s0, 1
/* 4178E4 802A2B54 0202102A */  slt       $v0, $s0, $v0
/* 4178E8 802A2B58 1440FFF6 */  bnez      $v0, .L802A2B34
/* 4178EC 802A2B5C 240500FF */   addiu    $a1, $zero, 0xff
.L802A2B60:
/* 4178F0 802A2B60 240500FF */  addiu     $a1, $zero, 0xff
/* 4178F4 802A2B64 00A0302D */  daddu     $a2, $a1, $zero
/* 4178F8 802A2B68 3C04802B */  lui       $a0, %hi(D_802AD118)
/* 4178FC 802A2B6C 8C84D118 */  lw        $a0, %lo(D_802AD118)($a0)
/* 417900 802A2B70 0C0513BF */  jal       icon_set_tint
/* 417904 802A2B74 00A0382D */   daddu    $a3, $a1, $zero
/* 417908 802A2B78 240500FF */  addiu     $a1, $zero, 0xff
/* 41790C 802A2B7C 00A0302D */  daddu     $a2, $a1, $zero
/* 417910 802A2B80 3C04802B */  lui       $a0, %hi(D_802AD11C)
/* 417914 802A2B84 8C84D11C */  lw        $a0, %lo(D_802AD11C)($a0)
/* 417918 802A2B88 0C0513BF */  jal       icon_set_tint
/* 41791C 802A2B8C 00A0382D */   daddu    $a3, $a1, $zero
/* 417920 802A2B90 240500FF */  addiu     $a1, $zero, 0xff
/* 417924 802A2B94 00A0302D */  daddu     $a2, $a1, $zero
/* 417928 802A2B98 3C04802B */  lui       $a0, %hi(D_802AD120)
/* 41792C 802A2B9C 8C84D120 */  lw        $a0, %lo(D_802AD120)($a0)
/* 417930 802A2BA0 0C0513BF */  jal       icon_set_tint
/* 417934 802A2BA4 00A0382D */   daddu    $a3, $a1, $zero
/* 417938 802A2BA8 240500FF */  addiu     $a1, $zero, 0xff
/* 41793C 802A2BAC 00A0302D */  daddu     $a2, $a1, $zero
/* 417940 802A2BB0 3C04802B */  lui       $a0, %hi(D_802AD188)
/* 417944 802A2BB4 8C84D188 */  lw        $a0, %lo(D_802AD188)($a0)
/* 417948 802A2BB8 0C0513BF */  jal       icon_set_tint
/* 41794C 802A2BBC 00A0382D */   daddu    $a3, $a1, $zero
/* 417950 802A2BC0 3C02802B */  lui       $v0, %hi(D_802AD4A4)
/* 417954 802A2BC4 8C42D4A4 */  lw        $v0, %lo(D_802AD4A4)($v0)
/* 417958 802A2BC8 1840000F */  blez      $v0, .L802A2C08
/* 41795C 802A2BCC 0000802D */   daddu    $s0, $zero, $zero
/* 417960 802A2BD0 3C11802B */  lui       $s1, %hi(D_802AD190)
/* 417964 802A2BD4 2631D190 */  addiu     $s1, $s1, %lo(D_802AD190)
/* 417968 802A2BD8 240500FF */  addiu     $a1, $zero, 0xff
.L802A2BDC:
/* 41796C 802A2BDC 00A0302D */  daddu     $a2, $a1, $zero
/* 417970 802A2BE0 00A0382D */  daddu     $a3, $a1, $zero
/* 417974 802A2BE4 8E240000 */  lw        $a0, ($s1)
/* 417978 802A2BE8 0C0513BF */  jal       icon_set_tint
/* 41797C 802A2BEC 26310004 */   addiu    $s1, $s1, 4
/* 417980 802A2BF0 3C02802B */  lui       $v0, %hi(D_802AD4A4)
/* 417984 802A2BF4 8C42D4A4 */  lw        $v0, %lo(D_802AD4A4)($v0)
/* 417988 802A2BF8 26100001 */  addiu     $s0, $s0, 1
/* 41798C 802A2BFC 0202102A */  slt       $v0, $s0, $v0
/* 417990 802A2C00 1440FFF6 */  bnez      $v0, .L802A2BDC
/* 417994 802A2C04 240500FF */   addiu    $a1, $zero, 0xff
.L802A2C08:
/* 417998 802A2C08 3C04802B */  lui       $a0, %hi(D_802AD118)
/* 41799C 802A2C0C 8C84D118 */  lw        $a0, %lo(D_802AD118)($a0)
/* 4179A0 802A2C10 3C058010 */  lui       $a1, %hi(D_80104A28)
/* 4179A4 802A2C14 24A54A28 */  addiu     $a1, $a1, %lo(D_80104A28)
/* 4179A8 802A2C18 0C0511FF */  jal       set_menu_icon_script
/* 4179AC 802A2C1C 00000000 */   nop
/* 4179B0 802A2C20 8FBF0018 */  lw        $ra, 0x18($sp)
/* 4179B4 802A2C24 8FB10014 */  lw        $s1, 0x14($sp)
/* 4179B8 802A2C28 8FB00010 */  lw        $s0, 0x10($sp)
/* 4179BC 802A2C2C 2402000A */  addiu     $v0, $zero, 0xa
/* 4179C0 802A2C30 3C01802B */  lui       $at, %hi(D_802AD114)
/* 4179C4 802A2C34 A422D114 */  sh        $v0, %lo(D_802AD114)($at)
/* 4179C8 802A2C38 24020001 */  addiu     $v0, $zero, 1
/* 4179CC 802A2C3C 3C01802B */  lui       $at, %hi(D_802AD10F)
/* 4179D0 802A2C40 A022D10F */  sb        $v0, %lo(D_802AD10F)($at)
/* 4179D4 802A2C44 24020014 */  addiu     $v0, $zero, 0x14
/* 4179D8 802A2C48 3C01802B */  lui       $at, %hi(D_802AD108)
/* 4179DC 802A2C4C A022D108 */  sb        $v0, %lo(D_802AD108)($at)
/* 4179E0 802A2C50 03E00008 */  jr        $ra
/* 4179E4 802A2C54 27BD0020 */   addiu    $sp, $sp, 0x20
