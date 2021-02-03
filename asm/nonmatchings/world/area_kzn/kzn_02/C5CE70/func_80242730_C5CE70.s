.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242730_C5CE70
/* C5CE70 80242730 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* C5CE74 80242734 3C048024 */  lui       $a0, %hi(D_802464A4_C60BE4)
/* C5CE78 80242738 248464A4 */  addiu     $a0, $a0, %lo(D_802464A4_C60BE4)
/* C5CE7C 8024273C AFBF0018 */  sw        $ra, 0x18($sp)
/* C5CE80 80242740 AFB10014 */  sw        $s1, 0x14($sp)
/* C5CE84 80242744 AFB00010 */  sw        $s0, 0x10($sp)
/* C5CE88 80242748 F7B40020 */  sdc1      $f20, 0x20($sp)
/* C5CE8C 8024274C 8C830000 */  lw        $v1, ($a0)
/* C5CE90 80242750 3C118011 */  lui       $s1, %hi(gPlayerStatus)
/* C5CE94 80242754 2631EFC8 */  addiu     $s1, $s1, %lo(gPlayerStatus)
/* C5CE98 80242758 28620003 */  slti      $v0, $v1, 3
/* C5CE9C 8024275C 50400007 */  beql      $v0, $zero, .L8024277C
/* C5CEA0 80242760 24020003 */   addiu    $v0, $zero, 3
/* C5CEA4 80242764 1C60000C */  bgtz      $v1, .L80242798
/* C5CEA8 80242768 24620001 */   addiu    $v0, $v1, 1
/* C5CEAC 8024276C 10600007 */  beqz      $v1, .L8024278C
/* C5CEB0 80242770 0000102D */   daddu    $v0, $zero, $zero
/* C5CEB4 80242774 08090A02 */  j         .L80242808
/* C5CEB8 80242778 00000000 */   nop
.L8024277C:
/* C5CEBC 8024277C 10620008 */  beq       $v1, $v0, .L802427A0
/* C5CEC0 80242780 0000102D */   daddu    $v0, $zero, $zero
/* C5CEC4 80242784 08090A02 */  j         .L80242808
/* C5CEC8 80242788 00000000 */   nop
.L8024278C:
/* C5CECC 8024278C 24020001 */  addiu     $v0, $zero, 1
/* C5CED0 80242790 08090A01 */  j         .L80242804
/* C5CED4 80242794 AC820000 */   sw       $v0, ($a0)
.L80242798:
/* C5CED8 80242798 08090A01 */  j         .L80242804
/* C5CEDC 8024279C AC820000 */   sw       $v0, ($a0)
.L802427A0:
/* C5CEE0 802427A0 3C108011 */  lui       $s0, %hi(D_8010C930)
/* C5CEE4 802427A4 2610C930 */  addiu     $s0, $s0, %lo(D_8010C930)
/* C5CEE8 802427A8 0C03BD17 */  jal       clear_partner_move_history
/* C5CEEC 802427AC 8E040000 */   lw       $a0, ($s0)
/* C5CEF0 802427B0 C6200028 */  lwc1      $f0, 0x28($s1)
/* C5CEF4 802427B4 C6220030 */  lwc1      $f2, 0x30($s1)
/* C5CEF8 802427B8 4600010D */  trunc.w.s $f4, $f0
/* C5CEFC 802427BC 44042000 */  mfc1      $a0, $f4
/* C5CF00 802427C0 4600110D */  trunc.w.s $f4, $f2
/* C5CF04 802427C4 44052000 */  mfc1      $a1, $f4
/* C5CF08 802427C8 0C03BCF0 */  jal       func_800EF3C0
/* C5CF0C 802427CC 00000000 */   nop
/* C5CF10 802427D0 0C03BCF5 */  jal       func_800EF3D4
/* C5CF14 802427D4 0000202D */   daddu    $a0, $zero, $zero
/* C5CF18 802427D8 3C0142B4 */  lui       $at, 0x42b4
/* C5CF1C 802427DC 4481A000 */  mtc1      $at, $f20
/* C5CF20 802427E0 8E040000 */  lw        $a0, ($s0)
/* C5CF24 802427E4 4405A000 */  mfc1      $a1, $f20
/* C5CF28 802427E8 0C00ECD0 */  jal       set_npc_yaw
/* C5CF2C 802427EC 00000000 */   nop
/* C5CF30 802427F0 24020002 */  addiu     $v0, $zero, 2
/* C5CF34 802427F4 E6340080 */  swc1      $f20, 0x80($s1)
/* C5CF38 802427F8 E6340084 */  swc1      $f20, 0x84($s1)
/* C5CF3C 802427FC 08090A02 */  j         .L80242808
/* C5CF40 80242800 AE2000A8 */   sw       $zero, 0xa8($s1)
.L80242804:
/* C5CF44 80242804 0000102D */  daddu     $v0, $zero, $zero
.L80242808:
/* C5CF48 80242808 8FBF0018 */  lw        $ra, 0x18($sp)
/* C5CF4C 8024280C 8FB10014 */  lw        $s1, 0x14($sp)
/* C5CF50 80242810 8FB00010 */  lw        $s0, 0x10($sp)
/* C5CF54 80242814 D7B40020 */  ldc1      $f20, 0x20($sp)
/* C5CF58 80242818 03E00008 */  jr        $ra
/* C5CF5C 8024281C 27BD0028 */   addiu    $sp, $sp, 0x28
