.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802D2520
/* F6ED0 802D2520 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* F6ED4 802D2524 AFB40030 */  sw        $s4, 0x30($sp)
/* F6ED8 802D2528 0080A02D */  daddu     $s4, $a0, $zero
/* F6EDC 802D252C AFBF0038 */  sw        $ra, 0x38($sp)
/* F6EE0 802D2530 AFB50034 */  sw        $s5, 0x34($sp)
/* F6EE4 802D2534 AFB3002C */  sw        $s3, 0x2c($sp)
/* F6EE8 802D2538 AFB20028 */  sw        $s2, 0x28($sp)
/* F6EEC 802D253C AFB10024 */  sw        $s1, 0x24($sp)
/* F6EF0 802D2540 AFB00020 */  sw        $s0, 0x20($sp)
/* F6EF4 802D2544 8E90000C */  lw        $s0, 0xc($s4)
/* F6EF8 802D2548 8E150000 */  lw        $s5, ($s0)
/* F6EFC 802D254C 26100004 */  addiu     $s0, $s0, 4
/* F6F00 802D2550 8E050000 */  lw        $a1, ($s0)
/* F6F04 802D2554 0C0B1EAF */  jal       get_variable
/* F6F08 802D2558 26100004 */   addiu    $s0, $s0, 4
/* F6F0C 802D255C 02A0202D */  daddu     $a0, $s5, $zero
/* F6F10 802D2560 0000282D */  daddu     $a1, $zero, $zero
/* F6F14 802D2564 00A0302D */  daddu     $a2, $a1, $zero
/* F6F18 802D2568 00A0382D */  daddu     $a3, $a1, $zero
/* F6F1C 802D256C 0040882D */  daddu     $s1, $v0, $zero
/* F6F20 802D2570 AFA00010 */  sw        $zero, 0x10($sp)
/* F6F24 802D2574 AFA00014 */  sw        $zero, 0x14($sp)
/* F6F28 802D2578 0C0B77FE */  jal       func_802DDFF8
/* F6F2C 802D257C AFA00018 */   sw       $zero, 0x18($sp)
/* F6F30 802D2580 3C128011 */  lui       $s2, %hi(gPlayerStatus)
/* F6F34 802D2584 2652EFC8 */  addiu     $s2, $s2, %lo(gPlayerStatus)
/* F6F38 802D2588 2E22000E */  sltiu     $v0, $s1, 0xe
/* F6F3C 802D258C 104000AB */  beqz      $v0, .L802D283C
/* F6F40 802D2590 00111080 */   sll      $v0, $s1, 2
/* F6F44 802D2594 3C01802E */  lui       $at, %hi(D_802DA208)
/* F6F48 802D2598 00220821 */  addu      $at, $at, $v0
/* F6F4C 802D259C 8C22A208 */  lw        $v0, %lo(D_802DA208)($at)
/* F6F50 802D25A0 00400008 */  jr        $v0
/* F6F54 802D25A4 00000000 */   nop      
/* F6F58 802D25A8 02A0202D */  daddu     $a0, $s5, $zero
/* F6F5C 802D25AC 0000282D */  daddu     $a1, $zero, $zero
/* F6F60 802D25B0 00A0302D */  daddu     $a2, $a1, $zero
/* F6F64 802D25B4 00A0382D */  daddu     $a3, $a1, $zero
/* F6F68 802D25B8 3C03802E */  lui       $v1, %hi(D_802DB5B0)
/* F6F6C 802D25BC 9463B5B0 */  lhu       $v1, %lo(D_802DB5B0)($v1)
/* F6F70 802D25C0 2402000D */  addiu     $v0, $zero, 0xd
/* F6F74 802D25C4 A24200BE */  sb        $v0, 0xbe($s2)
/* F6F78 802D25C8 AFA00010 */  sw        $zero, 0x10($sp)
/* F6F7C 802D25CC 080B4A0C */  j         .L802D2830
/* F6F80 802D25D0 AFA00014 */   sw       $zero, 0x14($sp)
/* F6F84 802D25D4 2402000D */  addiu     $v0, $zero, 0xd
/* F6F88 802D25D8 A24200BE */  sb        $v0, 0xbe($s2)
/* F6F8C 802D25DC 02A0202D */  daddu     $a0, $s5, $zero
/* F6F90 802D25E0 0220282D */  daddu     $a1, $s1, $zero
/* F6F94 802D25E4 0000302D */  daddu     $a2, $zero, $zero
/* F6F98 802D25E8 3C02802E */  lui       $v0, %hi(D_802DB5B0)
/* F6F9C 802D25EC 9442B5B0 */  lhu       $v0, %lo(D_802DB5B0)($v0)
/* F6FA0 802D25F0 00C0382D */  daddu     $a3, $a2, $zero
/* F6FA4 802D25F4 AFA00010 */  sw        $zero, 0x10($sp)
/* F6FA8 802D25F8 AFA00014 */  sw        $zero, 0x14($sp)
/* F6FAC 802D25FC 080B4A0D */  j         .L802D2834
/* F6FB0 802D2600 AFA20018 */   sw       $v0, 0x18($sp)
/* F6FB4 802D2604 2402000D */  addiu     $v0, $zero, 0xd
/* F6FB8 802D2608 A24200BE */  sb        $v0, 0xbe($s2)
/* F6FBC 802D260C 8E050000 */  lw        $a1, ($s0)
/* F6FC0 802D2610 26100004 */  addiu     $s0, $s0, 4
/* F6FC4 802D2614 0C0B1EAF */  jal       get_variable
/* F6FC8 802D2618 0280202D */   daddu    $a0, $s4, $zero
/* F6FCC 802D261C 0040982D */  daddu     $s3, $v0, $zero
/* F6FD0 802D2620 8E050000 */  lw        $a1, ($s0)
/* F6FD4 802D2624 26100004 */  addiu     $s0, $s0, 4
/* F6FD8 802D2628 0C0B1EAF */  jal       get_variable
/* F6FDC 802D262C 0280202D */   daddu    $a0, $s4, $zero
/* F6FE0 802D2630 0040902D */  daddu     $s2, $v0, $zero
/* F6FE4 802D2634 8E050000 */  lw        $a1, ($s0)
/* F6FE8 802D2638 0C0B1EAF */  jal       get_variable
/* F6FEC 802D263C 0280202D */   daddu    $a0, $s4, $zero
/* F6FF0 802D2640 02A0202D */  daddu     $a0, $s5, $zero
/* F6FF4 802D2644 24050004 */  addiu     $a1, $zero, 4
/* F6FF8 802D2648 0260302D */  daddu     $a2, $s3, $zero
/* F6FFC 802D264C 3C03802E */  lui       $v1, %hi(D_802DB5B0)
/* F7000 802D2650 9463B5B0 */  lhu       $v1, %lo(D_802DB5B0)($v1)
/* F7004 802D2654 0240382D */  daddu     $a3, $s2, $zero
/* F7008 802D2658 AFA20010 */  sw        $v0, 0x10($sp)
/* F700C 802D265C 080B4A0C */  j         .L802D2830
/* F7010 802D2660 AFA00014 */   sw       $zero, 0x14($sp)
/* F7014 802D2664 2402000D */  addiu     $v0, $zero, 0xd
/* F7018 802D2668 A24200BE */  sb        $v0, 0xbe($s2)
/* F701C 802D266C 8E050000 */  lw        $a1, ($s0)
/* F7020 802D2670 26100004 */  addiu     $s0, $s0, 4
/* F7024 802D2674 0C0B1EAF */  jal       get_variable
/* F7028 802D2678 0280202D */   daddu    $a0, $s4, $zero
/* F702C 802D267C 0040982D */  daddu     $s3, $v0, $zero
/* F7030 802D2680 8E050000 */  lw        $a1, ($s0)
/* F7034 802D2684 26100004 */  addiu     $s0, $s0, 4
/* F7038 802D2688 0C0B1EAF */  jal       get_variable
/* F703C 802D268C 0280202D */   daddu    $a0, $s4, $zero
/* F7040 802D2690 0040902D */  daddu     $s2, $v0, $zero
/* F7044 802D2694 8E050000 */  lw        $a1, ($s0)
/* F7048 802D2698 0C0B1EAF */  jal       get_variable
/* F704C 802D269C 0280202D */   daddu    $a0, $s4, $zero
/* F7050 802D26A0 02A0202D */  daddu     $a0, $s5, $zero
/* F7054 802D26A4 24050006 */  addiu     $a1, $zero, 6
/* F7058 802D26A8 0260302D */  daddu     $a2, $s3, $zero
/* F705C 802D26AC 3C03802E */  lui       $v1, %hi(D_802DB5B0)
/* F7060 802D26B0 9463B5B0 */  lhu       $v1, %lo(D_802DB5B0)($v1)
/* F7064 802D26B4 0240382D */  daddu     $a3, $s2, $zero
/* F7068 802D26B8 AFA20010 */  sw        $v0, 0x10($sp)
/* F706C 802D26BC 080B4A0B */  j         .L802D282C
/* F7070 802D26C0 240200FF */   addiu    $v0, $zero, 0xff
/* F7074 802D26C4 24020016 */  addiu     $v0, $zero, 0x16
/* F7078 802D26C8 A24200BE */  sb        $v0, 0xbe($s2)
/* F707C 802D26CC 8E050000 */  lw        $a1, ($s0)
/* F7080 802D26D0 0C0B1EAF */  jal       get_variable
/* F7084 802D26D4 0280202D */   daddu    $a0, $s4, $zero
/* F7088 802D26D8 02A0202D */  daddu     $a0, $s5, $zero
/* F708C 802D26DC 24050007 */  addiu     $a1, $zero, 7
/* F7090 802D26E0 240600FF */  addiu     $a2, $zero, 0xff
/* F7094 802D26E4 00C0382D */  daddu     $a3, $a2, $zero
/* F7098 802D26E8 3C08802E */  lui       $t0, %hi(D_802DB5B0)
/* F709C 802D26EC 9508B5B0 */  lhu       $t0, %lo(D_802DB5B0)($t0)
/* F70A0 802D26F0 00C0182D */  daddu     $v1, $a2, $zero
/* F70A4 802D26F4 AFA30010 */  sw        $v1, 0x10($sp)
/* F70A8 802D26F8 AFA20014 */  sw        $v0, 0x14($sp)
/* F70AC 802D26FC 080B4A0D */  j         .L802D2834
/* F70B0 802D2700 AFA80018 */   sw       $t0, 0x18($sp)
/* F70B4 802D2704 24020016 */  addiu     $v0, $zero, 0x16
/* F70B8 802D2708 A24200BE */  sb        $v0, 0xbe($s2)
/* F70BC 802D270C 8E050000 */  lw        $a1, ($s0)
/* F70C0 802D2710 26100004 */  addiu     $s0, $s0, 4
/* F70C4 802D2714 0C0B1EAF */  jal       get_variable
/* F70C8 802D2718 0280202D */   daddu    $a0, $s4, $zero
/* F70CC 802D271C 0040982D */  daddu     $s3, $v0, $zero
/* F70D0 802D2720 8E050000 */  lw        $a1, ($s0)
/* F70D4 802D2724 26100004 */  addiu     $s0, $s0, 4
/* F70D8 802D2728 0C0B1EAF */  jal       get_variable
/* F70DC 802D272C 0280202D */   daddu    $a0, $s4, $zero
/* F70E0 802D2730 0040902D */  daddu     $s2, $v0, $zero
/* F70E4 802D2734 8E050000 */  lw        $a1, ($s0)
/* F70E8 802D2738 26100004 */  addiu     $s0, $s0, 4
/* F70EC 802D273C 0C0B1EAF */  jal       get_variable
/* F70F0 802D2740 0280202D */   daddu    $a0, $s4, $zero
/* F70F4 802D2744 0040882D */  daddu     $s1, $v0, $zero
/* F70F8 802D2748 8E050000 */  lw        $a1, ($s0)
/* F70FC 802D274C 0C0B1EAF */  jal       get_variable
/* F7100 802D2750 0280202D */   daddu    $a0, $s4, $zero
/* F7104 802D2754 02A0202D */  daddu     $a0, $s5, $zero
/* F7108 802D2758 080B4A06 */  j         .L802D2818
/* F710C 802D275C 24050008 */   addiu    $a1, $zero, 8
/* F7110 802D2760 2402000D */  addiu     $v0, $zero, 0xd
/* F7114 802D2764 A24200BE */  sb        $v0, 0xbe($s2)
/* F7118 802D2768 8E050000 */  lw        $a1, ($s0)
/* F711C 802D276C 26100004 */  addiu     $s0, $s0, 4
/* F7120 802D2770 0C0B1EAF */  jal       get_variable
/* F7124 802D2774 0280202D */   daddu    $a0, $s4, $zero
/* F7128 802D2778 0040982D */  daddu     $s3, $v0, $zero
/* F712C 802D277C 8E050000 */  lw        $a1, ($s0)
/* F7130 802D2780 26100004 */  addiu     $s0, $s0, 4
/* F7134 802D2784 0C0B1EAF */  jal       get_variable
/* F7138 802D2788 0280202D */   daddu    $a0, $s4, $zero
/* F713C 802D278C 0040902D */  daddu     $s2, $v0, $zero
/* F7140 802D2790 8E050000 */  lw        $a1, ($s0)
/* F7144 802D2794 0C0B1EAF */  jal       get_variable
/* F7148 802D2798 0280202D */   daddu    $a0, $s4, $zero
/* F714C 802D279C 02A0202D */  daddu     $a0, $s5, $zero
/* F7150 802D27A0 24050005 */  addiu     $a1, $zero, 5
/* F7154 802D27A4 0260302D */  daddu     $a2, $s3, $zero
/* F7158 802D27A8 3C03802E */  lui       $v1, %hi(D_802DB5B0)
/* F715C 802D27AC 9463B5B0 */  lhu       $v1, %lo(D_802DB5B0)($v1)
/* F7160 802D27B0 0240382D */  daddu     $a3, $s2, $zero
/* F7164 802D27B4 AFA20010 */  sw        $v0, 0x10($sp)
/* F7168 802D27B8 080B4A0C */  j         .L802D2830
/* F716C 802D27BC AFA00014 */   sw       $zero, 0x14($sp)
/* F7170 802D27C0 24020016 */  addiu     $v0, $zero, 0x16
/* F7174 802D27C4 A24200BE */  sb        $v0, 0xbe($s2)
/* F7178 802D27C8 8E050000 */  lw        $a1, ($s0)
/* F717C 802D27CC 26100004 */  addiu     $s0, $s0, 4
/* F7180 802D27D0 0C0B1EAF */  jal       get_variable
/* F7184 802D27D4 0280202D */   daddu    $a0, $s4, $zero
/* F7188 802D27D8 0040982D */  daddu     $s3, $v0, $zero
/* F718C 802D27DC 8E050000 */  lw        $a1, ($s0)
/* F7190 802D27E0 26100004 */  addiu     $s0, $s0, 4
/* F7194 802D27E4 0C0B1EAF */  jal       get_variable
/* F7198 802D27E8 0280202D */   daddu    $a0, $s4, $zero
/* F719C 802D27EC 0040902D */  daddu     $s2, $v0, $zero
/* F71A0 802D27F0 8E050000 */  lw        $a1, ($s0)
/* F71A4 802D27F4 26100004 */  addiu     $s0, $s0, 4
/* F71A8 802D27F8 0C0B1EAF */  jal       get_variable
/* F71AC 802D27FC 0280202D */   daddu    $a0, $s4, $zero
/* F71B0 802D2800 0040882D */  daddu     $s1, $v0, $zero
/* F71B4 802D2804 8E050000 */  lw        $a1, ($s0)
/* F71B8 802D2808 0C0B1EAF */  jal       get_variable
/* F71BC 802D280C 0280202D */   daddu    $a0, $s4, $zero
/* F71C0 802D2810 02A0202D */  daddu     $a0, $s5, $zero
/* F71C4 802D2814 2405000D */  addiu     $a1, $zero, 0xd
.L802D2818:
/* F71C8 802D2818 0260302D */  daddu     $a2, $s3, $zero
/* F71CC 802D281C 3C03802E */  lui       $v1, %hi(D_802DB5B0)
/* F71D0 802D2820 9463B5B0 */  lhu       $v1, %lo(D_802DB5B0)($v1)
/* F71D4 802D2824 0240382D */  daddu     $a3, $s2, $zero
/* F71D8 802D2828 AFB10010 */  sw        $s1, 0x10($sp)
.L802D282C:
/* F71DC 802D282C AFA20014 */  sw        $v0, 0x14($sp)
.L802D2830:
/* F71E0 802D2830 AFA30018 */  sw        $v1, 0x18($sp)
.L802D2834:
/* F71E4 802D2834 0C0B77FE */  jal       func_802DDFF8
/* F71E8 802D2838 00000000 */   nop      
.L802D283C:
/* F71EC 802D283C 8FBF0038 */  lw        $ra, 0x38($sp)
/* F71F0 802D2840 8FB50034 */  lw        $s5, 0x34($sp)
/* F71F4 802D2844 8FB40030 */  lw        $s4, 0x30($sp)
/* F71F8 802D2848 8FB3002C */  lw        $s3, 0x2c($sp)
/* F71FC 802D284C 8FB20028 */  lw        $s2, 0x28($sp)
/* F7200 802D2850 8FB10024 */  lw        $s1, 0x24($sp)
/* F7204 802D2854 8FB00020 */  lw        $s0, 0x20($sp)
/* F7208 802D2858 24020002 */  addiu     $v0, $zero, 2
/* F720C 802D285C 3C01802E */  lui       $at, %hi(D_802DB5B0)
/* F7210 802D2860 A420B5B0 */  sh        $zero, %lo(D_802DB5B0)($at)
/* F7214 802D2864 03E00008 */  jr        $ra
/* F7218 802D2868 27BD0040 */   addiu    $sp, $sp, 0x40
