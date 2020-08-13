.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_802D23F8
/* 0F6DA8 802D23F8 3C038011 */  lui   $v1, 0x8011
/* 0F6DAC 802D23FC 9063F07C */  lbu   $v1, -0xf84($v1)
/* 0F6DB0 802D2400 2C620003 */  sltiu $v0, $v1, 3
/* 0F6DB4 802D2404 1440000D */  bnez  $v0, .L802D243C
/* 0F6DB8 802D2408 00031600 */   sll   $v0, $v1, 0x18
/* 0F6DBC 802D240C 00021E03 */  sra   $v1, $v0, 0x18
/* 0F6DC0 802D2410 2402000A */  addiu $v0, $zero, 0xa
/* 0F6DC4 802D2414 10620009 */  beq   $v1, $v0, .L802D243C
/* 0F6DC8 802D2418 2402000B */   addiu $v0, $zero, 0xb
/* 0F6DCC 802D241C 10620007 */  beq   $v1, $v0, .L802D243C
/* 0F6DD0 802D2420 2402000E */   addiu $v0, $zero, 0xe
/* 0F6DD4 802D2424 10620005 */  beq   $v1, $v0, .L802D243C
/* 0F6DD8 802D2428 24020010 */   addiu $v0, $zero, 0x10
/* 0F6DDC 802D242C 10620003 */  beq   $v1, $v0, .L802D243C
/* 0F6DE0 802D2430 2402001A */   addiu $v0, $zero, 0x1a
/* 0F6DE4 802D2434 14620003 */  bne   $v1, $v0, .L802D2444
/* 0F6DE8 802D2438 00000000 */   nop   
.L802D243C:
/* 0F6DEC 802D243C 03E00008 */  jr    $ra
/* 0F6DF0 802D2440 24020001 */   addiu $v0, $zero, 1

.L802D2444:
/* 0F6DF4 802D2444 03E00008 */  jr    $ra
/* 0F6DF8 802D2448 0000102D */   daddu $v0, $zero, $zero

/* 0F6DFC 802D244C 3C028016 */  lui   $v0, 0x8016
/* 0F6E00 802D2450 8442A552 */  lh    $v0, -0x5aae($v0)
/* 0F6E04 802D2454 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0F6E08 802D2458 04400006 */  bltz  $v0, .L802D2474
/* 0F6E0C 802D245C AFBF0010 */   sw    $ra, 0x10($sp)
/* 0F6E10 802D2460 0C0B48FE */  jal   func_802D23F8
/* 0F6E14 802D2464 00000000 */   nop   
/* 0F6E18 802D2468 0040182D */  daddu $v1, $v0, $zero
/* 0F6E1C 802D246C 14600002 */  bnez  $v1, .L802D2478
/* 0F6E20 802D2470 24020002 */   addiu $v0, $zero, 2
.L802D2474:
/* 0F6E24 802D2474 0000102D */  daddu $v0, $zero, $zero
.L802D2478:
/* 0F6E28 802D2478 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0F6E2C 802D247C 03E00008 */  jr    $ra
/* 0F6E30 802D2480 27BD0018 */   addiu $sp, $sp, 0x18

/* 0F6E34 802D2484 3C028016 */  lui   $v0, 0x8016
/* 0F6E38 802D2488 8442A552 */  lh    $v0, -0x5aae($v0)
/* 0F6E3C 802D248C 00021027 */  nor   $v0, $zero, $v0
/* 0F6E40 802D2490 000217C3 */  sra   $v0, $v0, 0x1f
/* 0F6E44 802D2494 03E00008 */  jr    $ra
/* 0F6E48 802D2498 30420002 */   andi  $v0, $v0, 2

/* 0F6E4C 802D249C 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0F6E50 802D24A0 AFB10014 */  sw    $s1, 0x14($sp)
/* 0F6E54 802D24A4 0080882D */  daddu $s1, $a0, $zero
/* 0F6E58 802D24A8 3C028016 */  lui   $v0, 0x8016
/* 0F6E5C 802D24AC 8442A552 */  lh    $v0, -0x5aae($v0)
/* 0F6E60 802D24B0 AFBF0018 */  sw    $ra, 0x18($sp)
/* 0F6E64 802D24B4 AFB00010 */  sw    $s0, 0x10($sp)
/* 0F6E68 802D24B8 8E30000C */  lw    $s0, 0xc($s1)
/* 0F6E6C 802D24BC 04400004 */  bltz  $v0, .L802D24D0
/* 0F6E70 802D24C0 0000302D */   daddu $a2, $zero, $zero
/* 0F6E74 802D24C4 0C0B48FE */  jal   func_802D23F8
/* 0F6E78 802D24C8 00000000 */   nop   
/* 0F6E7C 802D24CC 0002302B */  sltu  $a2, $zero, $v0
.L802D24D0:
/* 0F6E80 802D24D0 8E050000 */  lw    $a1, ($s0)
/* 0F6E84 802D24D4 0C0B2026 */  jal   set_variable
/* 0F6E88 802D24D8 0220202D */   daddu $a0, $s1, $zero
/* 0F6E8C 802D24DC 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0F6E90 802D24E0 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F6E94 802D24E4 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F6E98 802D24E8 24020002 */  addiu $v0, $zero, 2
/* 0F6E9C 802D24EC 03E00008 */  jr    $ra
/* 0F6EA0 802D24F0 27BD0020 */   addiu $sp, $sp, 0x20

/* 0F6EA4 802D24F4 3C028011 */  lui   $v0, 0x8011
/* 0F6EA8 802D24F8 8442EFDA */  lh    $v0, -0x1026($v0)
/* 0F6EAC 802D24FC 2C420001 */  sltiu $v0, $v0, 1
/* 0F6EB0 802D2500 03E00008 */  jr    $ra
/* 0F6EB4 802D2504 00021040 */   sll   $v0, $v0, 1

/* 0F6EB8 802D2508 3C028011 */  lui   $v0, 0x8011
/* 0F6EBC 802D250C 8C42EFC8 */  lw    $v0, -0x1038($v0)
/* 0F6EC0 802D2510 30422000 */  andi  $v0, $v0, 0x2000
/* 0F6EC4 802D2514 2C420001 */  sltiu $v0, $v0, 1
/* 0F6EC8 802D2518 03E00008 */  jr    $ra
/* 0F6ECC 802D251C 00021040 */   sll   $v0, $v0, 1

/* 0F6ED0 802D2520 27BDFFC0 */  addiu $sp, $sp, -0x40
/* 0F6ED4 802D2524 AFB40030 */  sw    $s4, 0x30($sp)
/* 0F6ED8 802D2528 0080A02D */  daddu $s4, $a0, $zero
/* 0F6EDC 802D252C AFBF0038 */  sw    $ra, 0x38($sp)
/* 0F6EE0 802D2530 AFB50034 */  sw    $s5, 0x34($sp)
/* 0F6EE4 802D2534 AFB3002C */  sw    $s3, 0x2c($sp)
/* 0F6EE8 802D2538 AFB20028 */  sw    $s2, 0x28($sp)
/* 0F6EEC 802D253C AFB10024 */  sw    $s1, 0x24($sp)
/* 0F6EF0 802D2540 AFB00020 */  sw    $s0, 0x20($sp)
/* 0F6EF4 802D2544 8E90000C */  lw    $s0, 0xc($s4)
/* 0F6EF8 802D2548 8E150000 */  lw    $s5, ($s0)
/* 0F6EFC 802D254C 26100004 */  addiu $s0, $s0, 4
/* 0F6F00 802D2550 8E050000 */  lw    $a1, ($s0)
/* 0F6F04 802D2554 0C0B1EAF */  jal   get_variable
/* 0F6F08 802D2558 26100004 */   addiu $s0, $s0, 4
/* 0F6F0C 802D255C 02A0202D */  daddu $a0, $s5, $zero
/* 0F6F10 802D2560 0000282D */  daddu $a1, $zero, $zero
/* 0F6F14 802D2564 00A0302D */  daddu $a2, $a1, $zero
/* 0F6F18 802D2568 00A0382D */  daddu $a3, $a1, $zero
/* 0F6F1C 802D256C 0040882D */  daddu $s1, $v0, $zero
/* 0F6F20 802D2570 AFA00010 */  sw    $zero, 0x10($sp)
/* 0F6F24 802D2574 AFA00014 */  sw    $zero, 0x14($sp)
/* 0F6F28 802D2578 0C0B77FE */  jal   func_802DDFF8
/* 0F6F2C 802D257C AFA00018 */   sw    $zero, 0x18($sp)
/* 0F6F30 802D2580 3C128011 */  lui   $s2, 0x8011
/* 0F6F34 802D2584 2652EFC8 */  addiu $s2, $s2, -0x1038
/* 0F6F38 802D2588 2E22000E */  sltiu $v0, $s1, 0xe
/* 0F6F3C 802D258C 104000AB */  beqz  $v0, .L802D283C
/* 0F6F40 802D2590 00111080 */   sll   $v0, $s1, 2
/* 0F6F44 802D2594 3C01802E */  lui   $at, 0x802e
/* 0F6F48 802D2598 00220821 */  addu  $at, $at, $v0
/* 0F6F4C 802D259C 8C22A208 */  lw    $v0, -0x5df8($at)
/* 0F6F50 802D25A0 00400008 */  jr    $v0
/* 0F6F54 802D25A4 00000000 */   nop   
/* 0F6F58 802D25A8 02A0202D */  daddu $a0, $s5, $zero
/* 0F6F5C 802D25AC 0000282D */  daddu $a1, $zero, $zero
/* 0F6F60 802D25B0 00A0302D */  daddu $a2, $a1, $zero
/* 0F6F64 802D25B4 00A0382D */  daddu $a3, $a1, $zero
/* 0F6F68 802D25B8 3C03802E */  lui   $v1, 0x802e
/* 0F6F6C 802D25BC 9463B5B0 */  lhu   $v1, -0x4a50($v1)
/* 0F6F70 802D25C0 2402000D */  addiu $v0, $zero, 0xd
/* 0F6F74 802D25C4 A24200BE */  sb    $v0, 0xbe($s2)
/* 0F6F78 802D25C8 AFA00010 */  sw    $zero, 0x10($sp)
/* 0F6F7C 802D25CC 080B4A0C */  j     .L802D2830
/* 0F6F80 802D25D0 AFA00014 */   sw    $zero, 0x14($sp)

/* 0F6F84 802D25D4 2402000D */  addiu $v0, $zero, 0xd
/* 0F6F88 802D25D8 A24200BE */  sb    $v0, 0xbe($s2)
/* 0F6F8C 802D25DC 02A0202D */  daddu $a0, $s5, $zero
/* 0F6F90 802D25E0 0220282D */  daddu $a1, $s1, $zero
/* 0F6F94 802D25E4 0000302D */  daddu $a2, $zero, $zero
/* 0F6F98 802D25E8 3C02802E */  lui   $v0, 0x802e
/* 0F6F9C 802D25EC 9442B5B0 */  lhu   $v0, -0x4a50($v0)
/* 0F6FA0 802D25F0 00C0382D */  daddu $a3, $a2, $zero
/* 0F6FA4 802D25F4 AFA00010 */  sw    $zero, 0x10($sp)
/* 0F6FA8 802D25F8 AFA00014 */  sw    $zero, 0x14($sp)
/* 0F6FAC 802D25FC 080B4A0D */  j     .L802D2834
/* 0F6FB0 802D2600 AFA20018 */   sw    $v0, 0x18($sp)

/* 0F6FB4 802D2604 2402000D */  addiu $v0, $zero, 0xd
/* 0F6FB8 802D2608 A24200BE */  sb    $v0, 0xbe($s2)
/* 0F6FBC 802D260C 8E050000 */  lw    $a1, ($s0)
/* 0F6FC0 802D2610 26100004 */  addiu $s0, $s0, 4
/* 0F6FC4 802D2614 0C0B1EAF */  jal   get_variable
/* 0F6FC8 802D2618 0280202D */   daddu $a0, $s4, $zero
/* 0F6FCC 802D261C 0040982D */  daddu $s3, $v0, $zero
/* 0F6FD0 802D2620 8E050000 */  lw    $a1, ($s0)
/* 0F6FD4 802D2624 26100004 */  addiu $s0, $s0, 4
/* 0F6FD8 802D2628 0C0B1EAF */  jal   get_variable
/* 0F6FDC 802D262C 0280202D */   daddu $a0, $s4, $zero
/* 0F6FE0 802D2630 0040902D */  daddu $s2, $v0, $zero
/* 0F6FE4 802D2634 8E050000 */  lw    $a1, ($s0)
/* 0F6FE8 802D2638 0C0B1EAF */  jal   get_variable
/* 0F6FEC 802D263C 0280202D */   daddu $a0, $s4, $zero
/* 0F6FF0 802D2640 02A0202D */  daddu $a0, $s5, $zero
/* 0F6FF4 802D2644 24050004 */  addiu $a1, $zero, 4
/* 0F6FF8 802D2648 0260302D */  daddu $a2, $s3, $zero
/* 0F6FFC 802D264C 3C03802E */  lui   $v1, 0x802e
/* 0F7000 802D2650 9463B5B0 */  lhu   $v1, -0x4a50($v1)
/* 0F7004 802D2654 0240382D */  daddu $a3, $s2, $zero
/* 0F7008 802D2658 AFA20010 */  sw    $v0, 0x10($sp)
/* 0F700C 802D265C 080B4A0C */  j     .L802D2830
/* 0F7010 802D2660 AFA00014 */   sw    $zero, 0x14($sp)

/* 0F7014 802D2664 2402000D */  addiu $v0, $zero, 0xd
/* 0F7018 802D2668 A24200BE */  sb    $v0, 0xbe($s2)
/* 0F701C 802D266C 8E050000 */  lw    $a1, ($s0)
/* 0F7020 802D2670 26100004 */  addiu $s0, $s0, 4
/* 0F7024 802D2674 0C0B1EAF */  jal   get_variable
/* 0F7028 802D2678 0280202D */   daddu $a0, $s4, $zero
/* 0F702C 802D267C 0040982D */  daddu $s3, $v0, $zero
/* 0F7030 802D2680 8E050000 */  lw    $a1, ($s0)
/* 0F7034 802D2684 26100004 */  addiu $s0, $s0, 4
/* 0F7038 802D2688 0C0B1EAF */  jal   get_variable
/* 0F703C 802D268C 0280202D */   daddu $a0, $s4, $zero
/* 0F7040 802D2690 0040902D */  daddu $s2, $v0, $zero
/* 0F7044 802D2694 8E050000 */  lw    $a1, ($s0)
/* 0F7048 802D2698 0C0B1EAF */  jal   get_variable
/* 0F704C 802D269C 0280202D */   daddu $a0, $s4, $zero
/* 0F7050 802D26A0 02A0202D */  daddu $a0, $s5, $zero
/* 0F7054 802D26A4 24050006 */  addiu $a1, $zero, 6
/* 0F7058 802D26A8 0260302D */  daddu $a2, $s3, $zero
/* 0F705C 802D26AC 3C03802E */  lui   $v1, 0x802e
/* 0F7060 802D26B0 9463B5B0 */  lhu   $v1, -0x4a50($v1)
/* 0F7064 802D26B4 0240382D */  daddu $a3, $s2, $zero
/* 0F7068 802D26B8 AFA20010 */  sw    $v0, 0x10($sp)
/* 0F706C 802D26BC 080B4A0B */  j     .L802D282C
/* 0F7070 802D26C0 240200FF */   addiu $v0, $zero, 0xff

/* 0F7074 802D26C4 24020016 */  addiu $v0, $zero, 0x16
/* 0F7078 802D26C8 A24200BE */  sb    $v0, 0xbe($s2)
/* 0F707C 802D26CC 8E050000 */  lw    $a1, ($s0)
/* 0F7080 802D26D0 0C0B1EAF */  jal   get_variable
/* 0F7084 802D26D4 0280202D */   daddu $a0, $s4, $zero
/* 0F7088 802D26D8 02A0202D */  daddu $a0, $s5, $zero
/* 0F708C 802D26DC 24050007 */  addiu $a1, $zero, 7
/* 0F7090 802D26E0 240600FF */  addiu $a2, $zero, 0xff
/* 0F7094 802D26E4 00C0382D */  daddu $a3, $a2, $zero
/* 0F7098 802D26E8 3C08802E */  lui   $t0, 0x802e
/* 0F709C 802D26EC 9508B5B0 */  lhu   $t0, -0x4a50($t0)
/* 0F70A0 802D26F0 00C0182D */  daddu $v1, $a2, $zero
/* 0F70A4 802D26F4 AFA30010 */  sw    $v1, 0x10($sp)
/* 0F70A8 802D26F8 AFA20014 */  sw    $v0, 0x14($sp)
/* 0F70AC 802D26FC 080B4A0D */  j     .L802D2834
/* 0F70B0 802D2700 AFA80018 */   sw    $t0, 0x18($sp)

/* 0F70B4 802D2704 24020016 */  addiu $v0, $zero, 0x16
/* 0F70B8 802D2708 A24200BE */  sb    $v0, 0xbe($s2)
/* 0F70BC 802D270C 8E050000 */  lw    $a1, ($s0)
/* 0F70C0 802D2710 26100004 */  addiu $s0, $s0, 4
/* 0F70C4 802D2714 0C0B1EAF */  jal   get_variable
/* 0F70C8 802D2718 0280202D */   daddu $a0, $s4, $zero
/* 0F70CC 802D271C 0040982D */  daddu $s3, $v0, $zero
/* 0F70D0 802D2720 8E050000 */  lw    $a1, ($s0)
/* 0F70D4 802D2724 26100004 */  addiu $s0, $s0, 4
/* 0F70D8 802D2728 0C0B1EAF */  jal   get_variable
/* 0F70DC 802D272C 0280202D */   daddu $a0, $s4, $zero
/* 0F70E0 802D2730 0040902D */  daddu $s2, $v0, $zero
/* 0F70E4 802D2734 8E050000 */  lw    $a1, ($s0)
/* 0F70E8 802D2738 26100004 */  addiu $s0, $s0, 4
/* 0F70EC 802D273C 0C0B1EAF */  jal   get_variable
/* 0F70F0 802D2740 0280202D */   daddu $a0, $s4, $zero
/* 0F70F4 802D2744 0040882D */  daddu $s1, $v0, $zero
/* 0F70F8 802D2748 8E050000 */  lw    $a1, ($s0)
/* 0F70FC 802D274C 0C0B1EAF */  jal   get_variable
/* 0F7100 802D2750 0280202D */   daddu $a0, $s4, $zero
/* 0F7104 802D2754 02A0202D */  daddu $a0, $s5, $zero
/* 0F7108 802D2758 080B4A06 */  j     .L802D2818
/* 0F710C 802D275C 24050008 */   addiu $a1, $zero, 8

/* 0F7110 802D2760 2402000D */  addiu $v0, $zero, 0xd
/* 0F7114 802D2764 A24200BE */  sb    $v0, 0xbe($s2)
/* 0F7118 802D2768 8E050000 */  lw    $a1, ($s0)
/* 0F711C 802D276C 26100004 */  addiu $s0, $s0, 4
/* 0F7120 802D2770 0C0B1EAF */  jal   get_variable
/* 0F7124 802D2774 0280202D */   daddu $a0, $s4, $zero
/* 0F7128 802D2778 0040982D */  daddu $s3, $v0, $zero
/* 0F712C 802D277C 8E050000 */  lw    $a1, ($s0)
/* 0F7130 802D2780 26100004 */  addiu $s0, $s0, 4
/* 0F7134 802D2784 0C0B1EAF */  jal   get_variable
/* 0F7138 802D2788 0280202D */   daddu $a0, $s4, $zero
/* 0F713C 802D278C 0040902D */  daddu $s2, $v0, $zero
/* 0F7140 802D2790 8E050000 */  lw    $a1, ($s0)
/* 0F7144 802D2794 0C0B1EAF */  jal   get_variable
/* 0F7148 802D2798 0280202D */   daddu $a0, $s4, $zero
/* 0F714C 802D279C 02A0202D */  daddu $a0, $s5, $zero
/* 0F7150 802D27A0 24050005 */  addiu $a1, $zero, 5
/* 0F7154 802D27A4 0260302D */  daddu $a2, $s3, $zero
/* 0F7158 802D27A8 3C03802E */  lui   $v1, 0x802e
/* 0F715C 802D27AC 9463B5B0 */  lhu   $v1, -0x4a50($v1)
/* 0F7160 802D27B0 0240382D */  daddu $a3, $s2, $zero
/* 0F7164 802D27B4 AFA20010 */  sw    $v0, 0x10($sp)
/* 0F7168 802D27B8 080B4A0C */  j     .L802D2830
/* 0F716C 802D27BC AFA00014 */   sw    $zero, 0x14($sp)

/* 0F7170 802D27C0 24020016 */  addiu $v0, $zero, 0x16
/* 0F7174 802D27C4 A24200BE */  sb    $v0, 0xbe($s2)
/* 0F7178 802D27C8 8E050000 */  lw    $a1, ($s0)
/* 0F717C 802D27CC 26100004 */  addiu $s0, $s0, 4
/* 0F7180 802D27D0 0C0B1EAF */  jal   get_variable
/* 0F7184 802D27D4 0280202D */   daddu $a0, $s4, $zero
/* 0F7188 802D27D8 0040982D */  daddu $s3, $v0, $zero
/* 0F718C 802D27DC 8E050000 */  lw    $a1, ($s0)
/* 0F7190 802D27E0 26100004 */  addiu $s0, $s0, 4
/* 0F7194 802D27E4 0C0B1EAF */  jal   get_variable
/* 0F7198 802D27E8 0280202D */   daddu $a0, $s4, $zero
/* 0F719C 802D27EC 0040902D */  daddu $s2, $v0, $zero
/* 0F71A0 802D27F0 8E050000 */  lw    $a1, ($s0)
/* 0F71A4 802D27F4 26100004 */  addiu $s0, $s0, 4
/* 0F71A8 802D27F8 0C0B1EAF */  jal   get_variable
/* 0F71AC 802D27FC 0280202D */   daddu $a0, $s4, $zero
/* 0F71B0 802D2800 0040882D */  daddu $s1, $v0, $zero
/* 0F71B4 802D2804 8E050000 */  lw    $a1, ($s0)
/* 0F71B8 802D2808 0C0B1EAF */  jal   get_variable
/* 0F71BC 802D280C 0280202D */   daddu $a0, $s4, $zero
/* 0F71C0 802D2810 02A0202D */  daddu $a0, $s5, $zero
/* 0F71C4 802D2814 2405000D */  addiu $a1, $zero, 0xd
.L802D2818:
/* 0F71C8 802D2818 0260302D */  daddu $a2, $s3, $zero
/* 0F71CC 802D281C 3C03802E */  lui   $v1, 0x802e
/* 0F71D0 802D2820 9463B5B0 */  lhu   $v1, -0x4a50($v1)
/* 0F71D4 802D2824 0240382D */  daddu $a3, $s2, $zero
/* 0F71D8 802D2828 AFB10010 */  sw    $s1, 0x10($sp)
.L802D282C:
/* 0F71DC 802D282C AFA20014 */  sw    $v0, 0x14($sp)
.L802D2830:
/* 0F71E0 802D2830 AFA30018 */  sw    $v1, 0x18($sp)
.L802D2834:
/* 0F71E4 802D2834 0C0B77FE */  jal   func_802DDFF8
/* 0F71E8 802D2838 00000000 */   nop   
.L802D283C:
/* 0F71EC 802D283C 8FBF0038 */  lw    $ra, 0x38($sp)
/* 0F71F0 802D2840 8FB50034 */  lw    $s5, 0x34($sp)
/* 0F71F4 802D2844 8FB40030 */  lw    $s4, 0x30($sp)
/* 0F71F8 802D2848 8FB3002C */  lw    $s3, 0x2c($sp)
/* 0F71FC 802D284C 8FB20028 */  lw    $s2, 0x28($sp)
/* 0F7200 802D2850 8FB10024 */  lw    $s1, 0x24($sp)
/* 0F7204 802D2854 8FB00020 */  lw    $s0, 0x20($sp)
/* 0F7208 802D2858 24020002 */  addiu $v0, $zero, 2
/* 0F720C 802D285C 3C01802E */  lui   $at, 0x802e
/* 0F7210 802D2860 A420B5B0 */  sh    $zero, -0x4a50($at)
/* 0F7214 802D2864 03E00008 */  jr    $ra
/* 0F7218 802D2868 27BD0040 */   addiu $sp, $sp, 0x40

/* 0F721C 802D286C 8C82000C */  lw    $v0, 0xc($a0)
/* 0F7220 802D2870 8C420000 */  lw    $v0, ($v0)
/* 0F7224 802D2874 3C01802E */  lui   $at, 0x802e
/* 0F7228 802D2878 A422B5B0 */  sh    $v0, -0x4a50($at)
/* 0F722C 802D287C 03E00008 */  jr    $ra
/* 0F7230 802D2880 24020002 */   addiu $v0, $zero, 2

/* 0F7234 802D2884 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 0F7238 802D2888 AFB20018 */  sw    $s2, 0x18($sp)
/* 0F723C 802D288C 0080902D */  daddu $s2, $a0, $zero
/* 0F7240 802D2890 AFB3001C */  sw    $s3, 0x1c($sp)
/* 0F7244 802D2894 3C138011 */  lui   $s3, 0x8011
/* 0F7248 802D2898 2673EFC8 */  addiu $s3, $s3, -0x1038
/* 0F724C 802D289C AFB50024 */  sw    $s5, 0x24($sp)
/* 0F7250 802D28A0 26550074 */  addiu $s5, $s2, 0x74
/* 0F7254 802D28A4 AFB10014 */  sw    $s1, 0x14($sp)
/* 0F7258 802D28A8 26510078 */  addiu $s1, $s2, 0x78
/* 0F725C 802D28AC AFB40020 */  sw    $s4, 0x20($sp)
/* 0F7260 802D28B0 AFBF0028 */  sw    $ra, 0x28($sp)
/* 0F7264 802D28B4 AFB00010 */  sw    $s0, 0x10($sp)
/* 0F7268 802D28B8 F7B40030 */  sdc1  $f20, 0x30($sp)
/* 0F726C 802D28BC 8E50000C */  lw    $s0, 0xc($s2)
/* 0F7270 802D28C0 10A00043 */  beqz  $a1, .L802D29D0
/* 0F7274 802D28C4 2654007C */   addiu $s4, $s2, 0x7c
/* 0F7278 802D28C8 8E050000 */  lw    $a1, ($s0)
/* 0F727C 802D28CC 0C0B210B */  jal   get_float_variable
/* 0F7280 802D28D0 26100004 */   addiu $s0, $s0, 4
/* 0F7284 802D28D4 0240202D */  daddu $a0, $s2, $zero
/* 0F7288 802D28D8 8E050000 */  lw    $a1, ($s0)
/* 0F728C 802D28DC 0C0B210B */  jal   get_float_variable
/* 0F7290 802D28E0 46000506 */   mov.s $f20, $f0
/* 0F7294 802D28E4 3C02802E */  lui   $v0, 0x802e
/* 0F7298 802D28E8 8C429D20 */  lw    $v0, -0x62e0($v0)
/* 0F729C 802D28EC C6620080 */  lwc1  $f2, 0x80($s3)
/* 0F72A0 802D28F0 26100004 */  addiu $s0, $s0, 4
/* 0F72A4 802D28F4 E442000C */  swc1  $f2, 0xc($v0)
/* 0F72A8 802D28F8 E6420074 */  swc1  $f2, 0x74($s2)
/* 0F72AC 802D28FC C66C0028 */  lwc1  $f12, 0x28($s3)
/* 0F72B0 802D2900 46146032 */  c.eq.s $f12, $f20
/* 0F72B4 802D2904 00000000 */  nop   
/* 0F72B8 802D2908 45000006 */  bc1f  .L802D2924
/* 0F72BC 802D290C 46000086 */   mov.s $f2, $f0
/* 0F72C0 802D2910 C6600030 */  lwc1  $f0, 0x30($s3)
/* 0F72C4 802D2914 46020032 */  c.eq.s $f0, $f2
/* 0F72C8 802D2918 00000000 */  nop   
/* 0F72CC 802D291C 45010008 */  bc1t  .L802D2940
/* 0F72D0 802D2920 00000000 */   nop   
.L802D2924:
/* 0F72D4 802D2924 C66E0030 */  lwc1  $f14, 0x30($s3)
/* 0F72D8 802D2928 4406A000 */  mfc1  $a2, $f20
/* 0F72DC 802D292C 44071000 */  mfc1  $a3, $f2
/* 0F72E0 802D2930 0C00A720 */  jal   atan2
/* 0F72E4 802D2934 00000000 */   nop   
/* 0F72E8 802D2938 080B4A51 */  j     .L802D2944
/* 0F72EC 802D293C 46000086 */   mov.s $f2, $f0

.L802D2940:
/* 0F72F0 802D2940 C6620080 */  lwc1  $f2, 0x80($s3)
.L802D2944:
/* 0F72F4 802D2944 C6A00000 */  lwc1  $f0, ($s5)
/* 0F72F8 802D2948 46001001 */  sub.s $f0, $f2, $f0
/* 0F72FC 802D294C E6200000 */  swc1  $f0, ($s1)
/* 0F7300 802D2950 8E050000 */  lw    $a1, ($s0)
/* 0F7304 802D2954 0C0B1EAF */  jal   get_variable
/* 0F7308 802D2958 0240202D */   daddu $a0, $s2, $zero
/* 0F730C 802D295C AE820000 */  sw    $v0, ($s4)
/* 0F7310 802D2960 3C02802E */  lui   $v0, 0x802e
/* 0F7314 802D2964 8C429D20 */  lw    $v0, -0x62e0($v0)
/* 0F7318 802D2968 3C01C334 */  lui   $at, 0xc334
/* 0F731C 802D296C 44810000 */  mtc1  $at, $f0
/* 0F7320 802D2970 A440008E */  sh    $zero, 0x8e($v0)
/* 0F7324 802D2974 C6220000 */  lwc1  $f2, ($s1)
/* 0F7328 802D2978 4600103C */  c.lt.s $f2, $f0
/* 0F732C 802D297C 00000000 */  nop   
/* 0F7330 802D2980 45000007 */  bc1f  .L802D29A0
/* 0F7334 802D2984 00000000 */   nop   
/* 0F7338 802D2988 3C0143B4 */  lui   $at, 0x43b4
/* 0F733C 802D298C 44810000 */  mtc1  $at, $f0
/* 0F7340 802D2990 00000000 */  nop   
/* 0F7344 802D2994 46001000 */  add.s $f0, $f2, $f0
/* 0F7348 802D2998 E6200000 */  swc1  $f0, ($s1)
/* 0F734C 802D299C C6220000 */  lwc1  $f2, ($s1)
.L802D29A0:
/* 0F7350 802D29A0 3C014334 */  lui   $at, 0x4334
/* 0F7354 802D29A4 44810000 */  mtc1  $at, $f0
/* 0F7358 802D29A8 00000000 */  nop   
/* 0F735C 802D29AC 4602003C */  c.lt.s $f0, $f2
/* 0F7360 802D29B0 00000000 */  nop   
/* 0F7364 802D29B4 45000006 */  bc1f  .L802D29D0
/* 0F7368 802D29B8 00000000 */   nop   
/* 0F736C 802D29BC 3C0143B4 */  lui   $at, 0x43b4
/* 0F7370 802D29C0 44810000 */  mtc1  $at, $f0
/* 0F7374 802D29C4 00000000 */  nop   
/* 0F7378 802D29C8 46001001 */  sub.s $f0, $f2, $f0
/* 0F737C 802D29CC E6200000 */  swc1  $f0, ($s1)
.L802D29D0:
/* 0F7380 802D29D0 8E820000 */  lw    $v0, ($s4)
/* 0F7384 802D29D4 1C40000E */  bgtz  $v0, .L802D2A10
/* 0F7388 802D29D8 00000000 */   nop   
/* 0F738C 802D29DC 3C10802E */  lui   $s0, 0x802e
/* 0F7390 802D29E0 26109D20 */  addiu $s0, $s0, -0x62e0
/* 0F7394 802D29E4 8E020000 */  lw    $v0, ($s0)
/* 0F7398 802D29E8 C6200000 */  lwc1  $f0, ($s1)
/* 0F739C 802D29EC C44C000C */  lwc1  $f12, 0xc($v0)
/* 0F73A0 802D29F0 46006300 */  add.s $f12, $f12, $f0
/* 0F73A4 802D29F4 0C00A6C9 */  jal   clamp_angle
/* 0F73A8 802D29F8 E44C000C */   swc1  $f12, 0xc($v0)
/* 0F73AC 802D29FC 8E030000 */  lw    $v1, ($s0)
/* 0F73B0 802D2A00 24020002 */  addiu $v0, $zero, 2
/* 0F73B4 802D2A04 E460000C */  swc1  $f0, 0xc($v1)
/* 0F73B8 802D2A08 080B4AA0 */  j     .L802D2A80
/* 0F73BC 802D2A0C E6600080 */   swc1  $f0, 0x80($s3)

.L802D2A10:
/* 0F73C0 802D2A10 3C10802E */  lui   $s0, 0x802e
/* 0F73C4 802D2A14 26109D20 */  addiu $s0, $s0, -0x62e0
/* 0F73C8 802D2A18 8E030000 */  lw    $v1, ($s0)
/* 0F73CC 802D2A1C 9462008E */  lhu   $v0, 0x8e($v1)
/* 0F73D0 802D2A20 24420001 */  addiu $v0, $v0, 1
/* 0F73D4 802D2A24 A462008E */  sh    $v0, 0x8e($v1)
/* 0F73D8 802D2A28 00021400 */  sll   $v0, $v0, 0x10
/* 0F73DC 802D2A2C 00021403 */  sra   $v0, $v0, 0x10
/* 0F73E0 802D2A30 C6200000 */  lwc1  $f0, ($s1)
/* 0F73E4 802D2A34 44821000 */  mtc1  $v0, $f2
/* 0F73E8 802D2A38 00000000 */  nop   
/* 0F73EC 802D2A3C 468010A0 */  cvt.s.w $f2, $f2
/* 0F73F0 802D2A40 46020002 */  mul.s $f0, $f0, $f2
/* 0F73F4 802D2A44 00000000 */  nop   
/* 0F73F8 802D2A48 C6AC0000 */  lwc1  $f12, ($s5)
/* 0F73FC 802D2A4C C6820000 */  lwc1  $f2, ($s4)
/* 0F7400 802D2A50 468010A0 */  cvt.s.w $f2, $f2
/* 0F7404 802D2A54 46020003 */  div.s $f0, $f0, $f2
/* 0F7408 802D2A58 46006300 */  add.s $f12, $f12, $f0
/* 0F740C 802D2A5C 0C00A6C9 */  jal   clamp_angle
/* 0F7410 802D2A60 E46C000C */   swc1  $f12, 0xc($v1)
/* 0F7414 802D2A64 8E020000 */  lw    $v0, ($s0)
/* 0F7418 802D2A68 E440000C */  swc1  $f0, 0xc($v0)
/* 0F741C 802D2A6C E6600080 */  swc1  $f0, 0x80($s3)
/* 0F7420 802D2A70 8442008E */  lh    $v0, 0x8e($v0)
/* 0F7424 802D2A74 8E830000 */  lw    $v1, ($s4)
/* 0F7428 802D2A78 0043102A */  slt   $v0, $v0, $v1
/* 0F742C 802D2A7C 38420001 */  xori  $v0, $v0, 1
.L802D2A80:
/* 0F7430 802D2A80 8FBF0028 */  lw    $ra, 0x28($sp)
/* 0F7434 802D2A84 8FB50024 */  lw    $s5, 0x24($sp)
/* 0F7438 802D2A88 8FB40020 */  lw    $s4, 0x20($sp)
/* 0F743C 802D2A8C 8FB3001C */  lw    $s3, 0x1c($sp)
/* 0F7440 802D2A90 8FB20018 */  lw    $s2, 0x18($sp)
/* 0F7444 802D2A94 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F7448 802D2A98 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F744C 802D2A9C D7B40030 */  ldc1  $f20, 0x30($sp)
/* 0F7450 802D2AA0 03E00008 */  jr    $ra
/* 0F7454 802D2AA4 27BD0038 */   addiu $sp, $sp, 0x38

