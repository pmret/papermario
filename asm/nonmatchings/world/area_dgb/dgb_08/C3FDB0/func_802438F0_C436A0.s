.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802438F0_C436A0
/* C436A0 802438F0 27BDFFA0 */  addiu     $sp, $sp, -0x60
/* C436A4 802438F4 AFB40050 */  sw        $s4, 0x50($sp)
/* C436A8 802438F8 0080A02D */  daddu     $s4, $a0, $zero
/* C436AC 802438FC AFBF0058 */  sw        $ra, 0x58($sp)
/* C436B0 80243900 AFB50054 */  sw        $s5, 0x54($sp)
/* C436B4 80243904 AFB3004C */  sw        $s3, 0x4c($sp)
/* C436B8 80243908 AFB20048 */  sw        $s2, 0x48($sp)
/* C436BC 8024390C AFB10044 */  sw        $s1, 0x44($sp)
/* C436C0 80243910 AFB00040 */  sw        $s0, 0x40($sp)
/* C436C4 80243914 8E920148 */  lw        $s2, 0x148($s4)
/* C436C8 80243918 86440008 */  lh        $a0, 8($s2)
/* C436CC 8024391C 0C00EABB */  jal       get_npc_unsafe
/* C436D0 80243920 00A0802D */   daddu    $s0, $a1, $zero
/* C436D4 80243924 8E83000C */  lw        $v1, 0xc($s4)
/* C436D8 80243928 0280202D */  daddu     $a0, $s4, $zero
/* C436DC 8024392C 8C650000 */  lw        $a1, ($v1)
/* C436E0 80243930 0C0B1EAF */  jal       get_variable
/* C436E4 80243934 0040A82D */   daddu    $s5, $v0, $zero
/* C436E8 80243938 AFA00020 */  sw        $zero, 0x20($sp)
/* C436EC 8024393C 8E4300D0 */  lw        $v1, 0xd0($s2)
/* C436F0 80243940 8C630030 */  lw        $v1, 0x30($v1)
/* C436F4 80243944 AFA30024 */  sw        $v1, 0x24($sp)
/* C436F8 80243948 8E4300D0 */  lw        $v1, 0xd0($s2)
/* C436FC 8024394C 8C63001C */  lw        $v1, 0x1c($v1)
/* C43700 80243950 AFA30028 */  sw        $v1, 0x28($sp)
/* C43704 80243954 8E4300D0 */  lw        $v1, 0xd0($s2)
/* C43708 80243958 8C630024 */  lw        $v1, 0x24($v1)
/* C4370C 8024395C AFA3002C */  sw        $v1, 0x2c($sp)
/* C43710 80243960 8E4300D0 */  lw        $v1, 0xd0($s2)
/* C43714 80243964 8C630028 */  lw        $v1, 0x28($v1)
/* C43718 80243968 27B30020 */  addiu     $s3, $sp, 0x20
/* C4371C 8024396C AFA30030 */  sw        $v1, 0x30($sp)
/* C43720 80243970 8E4300D0 */  lw        $v1, 0xd0($s2)
/* C43724 80243974 3C0142FA */  lui       $at, 0x42fa
/* C43728 80243978 44810000 */  mtc1      $at, $f0
/* C4372C 8024397C 8C63002C */  lw        $v1, 0x2c($v1)
/* C43730 80243980 0040882D */  daddu     $s1, $v0, $zero
/* C43734 80243984 E7A00038 */  swc1      $f0, 0x38($sp)
/* C43738 80243988 A7A0003C */  sh        $zero, 0x3c($sp)
/* C4373C 8024398C 12000007 */  beqz      $s0, .L802439AC
/* C43740 80243990 AFA30034 */   sw       $v1, 0x34($sp)
/* C43744 80243994 AE800070 */  sw        $zero, 0x70($s4)
/* C43748 80243998 02A0202D */  daddu     $a0, $s5, $zero
/* C4374C 8024399C 0240282D */  daddu     $a1, $s2, $zero
/* C43750 802439A0 0280302D */  daddu     $a2, $s4, $zero
/* C43754 802439A4 0C090A52 */  jal       func_80242948_C426F8
/* C43758 802439A8 0220382D */   daddu    $a3, $s1, $zero
.L802439AC:
/* C4375C 802439AC 8E830070 */  lw        $v1, 0x70($s4)
/* C43760 802439B0 2C620020 */  sltiu     $v0, $v1, 0x20
/* C43764 802439B4 10400060 */  beqz      $v0, .L80243B38
/* C43768 802439B8 00031080 */   sll      $v0, $v1, 2
/* C4376C 802439BC 3C018024 */  lui       $at, 0x8024
/* C43770 802439C0 00220821 */  addu      $at, $at, $v0
/* C43774 802439C4 8C226DA0 */  lw        $v0, 0x6da0($at)
/* C43778 802439C8 00400008 */  jr        $v0
/* C4377C 802439CC 00000000 */   nop      
/* C43780 802439D0 0280202D */  daddu     $a0, $s4, $zero
/* C43784 802439D4 0220282D */  daddu     $a1, $s1, $zero
/* C43788 802439D8 0C0905D8 */  jal       func_80241760_C41510
/* C4378C 802439DC 0260302D */   daddu    $a2, $s3, $zero
/* C43790 802439E0 0000282D */  daddu     $a1, $zero, $zero
/* C43794 802439E4 00A0302D */  daddu     $a2, $a1, $zero
/* C43798 802439E8 AFA00010 */  sw        $zero, 0x10($sp)
/* C4379C 802439EC AFA00014 */  sw        $zero, 0x14($sp)
/* C437A0 802439F0 AFA00018 */  sw        $zero, 0x18($sp)
/* C437A4 802439F4 8EA40024 */  lw        $a0, 0x24($s5)
/* C437A8 802439F8 0C0B7A25 */  jal       func_802DE894
/* C437AC 802439FC 00A0382D */   daddu    $a3, $a1, $zero
/* C437B0 80243A00 0280202D */  daddu     $a0, $s4, $zero
/* C437B4 80243A04 0220282D */  daddu     $a1, $s1, $zero
/* C437B8 80243A08 0C090644 */  jal       func_80241910_C416C0
/* C437BC 80243A0C 0260302D */   daddu    $a2, $s3, $zero
/* C437C0 80243A10 08090E8E */  j         .L80243A38
/* C437C4 80243A14 00000000 */   nop      
/* C437C8 80243A18 0280202D */  daddu     $a0, $s4, $zero
/* C437CC 80243A1C 0220282D */  daddu     $a1, $s1, $zero
/* C437D0 80243A20 0C0907CE */  jal       func_80241F38_C41CE8
/* C437D4 80243A24 0260302D */   daddu    $a2, $s3, $zero
/* C437D8 80243A28 0280202D */  daddu     $a0, $s4, $zero
/* C437DC 80243A2C 0220282D */  daddu     $a1, $s1, $zero
/* C437E0 80243A30 0C0907FE */  jal       func_80241FF8_C41DA8
/* C437E4 80243A34 0260302D */   daddu    $a2, $s3, $zero
.L80243A38:
/* C437E8 80243A38 8E830070 */  lw        $v1, 0x70($s4)
/* C437EC 80243A3C 2402000C */  addiu     $v0, $zero, 0xc
/* C437F0 80243A40 1462003D */  bne       $v1, $v0, .L80243B38
/* C437F4 80243A44 24020006 */   addiu    $v0, $zero, 6
/* C437F8 80243A48 08090ECE */  j         .L80243B38
/* C437FC 80243A4C A6A2008E */   sh       $v0, 0x8e($s5)
/* C43800 80243A50 0280202D */  daddu     $a0, $s4, $zero
/* C43804 80243A54 0220282D */  daddu     $a1, $s1, $zero
/* C43808 80243A58 0C090B16 */  jal       func_80242C58_C42A08
/* C4380C 80243A5C 0260302D */   daddu    $a2, $s3, $zero
/* C43810 80243A60 8E830070 */  lw        $v1, 0x70($s4)
/* C43814 80243A64 2402000D */  addiu     $v0, $zero, 0xd
/* C43818 80243A68 14620033 */  bne       $v1, $v0, .L80243B38
/* C4381C 80243A6C 00000000 */   nop      
/* C43820 80243A70 0280202D */  daddu     $a0, $s4, $zero
/* C43824 80243A74 0220282D */  daddu     $a1, $s1, $zero
/* C43828 80243A78 0C090B6C */  jal       func_80242DB0_C42B60
/* C4382C 80243A7C 0260302D */   daddu    $a2, $s3, $zero
/* C43830 80243A80 08090ECE */  j         .L80243B38
/* C43834 80243A84 00000000 */   nop      
/* C43838 80243A88 0280202D */  daddu     $a0, $s4, $zero
/* C4383C 80243A8C 0220282D */  daddu     $a1, $s1, $zero
/* C43840 80243A90 0C090BAD */  jal       func_80242EB4_C42C64
/* C43844 80243A94 0260302D */   daddu    $a2, $s3, $zero
/* C43848 80243A98 8E830070 */  lw        $v1, 0x70($s4)
/* C4384C 80243A9C 2402000F */  addiu     $v0, $zero, 0xf
/* C43850 80243AA0 14620025 */  bne       $v1, $v0, .L80243B38
/* C43854 80243AA4 00000000 */   nop      
/* C43858 80243AA8 0280202D */  daddu     $a0, $s4, $zero
/* C4385C 80243AAC 0220282D */  daddu     $a1, $s1, $zero
/* C43860 80243AB0 0C090BE5 */  jal       func_80242F94_C42D44
/* C43864 80243AB4 0260302D */   daddu    $a2, $s3, $zero
/* C43868 80243AB8 08090ECE */  j         .L80243B38
/* C4386C 80243ABC 00000000 */   nop      
/* C43870 80243AC0 0280202D */  daddu     $a0, $s4, $zero
/* C43874 80243AC4 0220282D */  daddu     $a1, $s1, $zero
/* C43878 80243AC8 0C090C8C */  jal       func_80243230_C42FE0
/* C4387C 80243ACC 0260302D */   daddu    $a2, $s3, $zero
/* C43880 80243AD0 0280202D */  daddu     $a0, $s4, $zero
/* C43884 80243AD4 0220282D */  daddu     $a1, $s1, $zero
/* C43888 80243AD8 0C090CBA */  jal       func_802432E8_C43098
/* C4388C 80243ADC 0260302D */   daddu    $a2, $s3, $zero
/* C43890 80243AE0 08090ECE */  j         .L80243B38
/* C43894 80243AE4 00000000 */   nop      
/* C43898 80243AE8 0280202D */  daddu     $a0, $s4, $zero
/* C4389C 80243AEC 0220282D */  daddu     $a1, $s1, $zero
/* C438A0 80243AF0 0C090D1A */  jal       func_80243468_C43218
/* C438A4 80243AF4 0260302D */   daddu    $a2, $s3, $zero
/* C438A8 80243AF8 08090ECE */  j         .L80243B38
/* C438AC 80243AFC 00000000 */   nop      
/* C438B0 80243B00 0280202D */  daddu     $a0, $s4, $zero
/* C438B4 80243B04 0220282D */  daddu     $a1, $s1, $zero
/* C438B8 80243B08 0C090D2C */  jal       func_802434B0_C43260
/* C438BC 80243B0C 0260302D */   daddu    $a2, $s3, $zero
/* C438C0 80243B10 08090ECE */  j         .L80243B38
/* C438C4 80243B14 00000000 */   nop      
/* C438C8 80243B18 0280202D */  daddu     $a0, $s4, $zero
/* C438CC 80243B1C 0220282D */  daddu     $a1, $s1, $zero
/* C438D0 80243B20 0C090D4C */  jal       func_80243530_C432E0
/* C438D4 80243B24 0260302D */   daddu    $a2, $s3, $zero
/* C438D8 80243B28 0280202D */  daddu     $a0, $s4, $zero
/* C438DC 80243B2C 0220282D */  daddu     $a1, $s1, $zero
/* C438E0 80243B30 0C090D76 */  jal       func_802435D8_C43388
/* C438E4 80243B34 0260302D */   daddu    $a2, $s3, $zero
.L80243B38:
/* C438E8 80243B38 8E820070 */  lw        $v0, 0x70($s4)
/* C438EC 80243B3C 8FBF0058 */  lw        $ra, 0x58($sp)
/* C438F0 80243B40 8FB50054 */  lw        $s5, 0x54($sp)
/* C438F4 80243B44 8FB40050 */  lw        $s4, 0x50($sp)
/* C438F8 80243B48 8FB3004C */  lw        $s3, 0x4c($sp)
/* C438FC 80243B4C 8FB20048 */  lw        $s2, 0x48($sp)
/* C43900 80243B50 8FB10044 */  lw        $s1, 0x44($sp)
/* C43904 80243B54 8FB00040 */  lw        $s0, 0x40($sp)
/* C43908 80243B58 38420064 */  xori      $v0, $v0, 0x64
/* C4390C 80243B5C 2C420001 */  sltiu     $v0, $v0, 1
/* C43910 80243B60 00021040 */  sll       $v0, $v0, 1
/* C43914 80243B64 03E00008 */  jr        $ra
/* C43918 80243B68 27BD0060 */   addiu    $sp, $sp, 0x60
