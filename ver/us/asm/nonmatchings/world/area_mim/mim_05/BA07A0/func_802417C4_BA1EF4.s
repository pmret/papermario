.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802417C4_BA1EF4
/* BA1EF4 802417C4 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* BA1EF8 802417C8 AFB20038 */  sw        $s2, 0x38($sp)
/* BA1EFC 802417CC 0080902D */  daddu     $s2, $a0, $zero
/* BA1F00 802417D0 AFBF0048 */  sw        $ra, 0x48($sp)
/* BA1F04 802417D4 AFB50044 */  sw        $s5, 0x44($sp)
/* BA1F08 802417D8 AFB40040 */  sw        $s4, 0x40($sp)
/* BA1F0C 802417DC AFB3003C */  sw        $s3, 0x3c($sp)
/* BA1F10 802417E0 AFB10034 */  sw        $s1, 0x34($sp)
/* BA1F14 802417E4 AFB00030 */  sw        $s0, 0x30($sp)
/* BA1F18 802417E8 8E510148 */  lw        $s1, 0x148($s2)
/* BA1F1C 802417EC 86240008 */  lh        $a0, 8($s1)
/* BA1F20 802417F0 0C00EABB */  jal       get_npc_unsafe
/* BA1F24 802417F4 00A0802D */   daddu    $s0, $a1, $zero
/* BA1F28 802417F8 8E43000C */  lw        $v1, 0xc($s2)
/* BA1F2C 802417FC 0240202D */  daddu     $a0, $s2, $zero
/* BA1F30 80241800 8C650000 */  lw        $a1, ($v1)
/* BA1F34 80241804 0C0B1EAF */  jal       evt_get_variable
/* BA1F38 80241808 0040A82D */   daddu    $s5, $v0, $zero
/* BA1F3C 8024180C AFA00010 */  sw        $zero, 0x10($sp)
/* BA1F40 80241810 8E2300D0 */  lw        $v1, 0xd0($s1)
/* BA1F44 80241814 8C630030 */  lw        $v1, 0x30($v1)
/* BA1F48 80241818 AFA30014 */  sw        $v1, 0x14($sp)
/* BA1F4C 8024181C 8E2300D0 */  lw        $v1, 0xd0($s1)
/* BA1F50 80241820 8C63001C */  lw        $v1, 0x1c($v1)
/* BA1F54 80241824 AFA30018 */  sw        $v1, 0x18($sp)
/* BA1F58 80241828 8E2300D0 */  lw        $v1, 0xd0($s1)
/* BA1F5C 8024182C 8C630024 */  lw        $v1, 0x24($v1)
/* BA1F60 80241830 AFA3001C */  sw        $v1, 0x1c($sp)
/* BA1F64 80241834 8E2300D0 */  lw        $v1, 0xd0($s1)
/* BA1F68 80241838 8C630028 */  lw        $v1, 0x28($v1)
/* BA1F6C 8024183C 27B40010 */  addiu     $s4, $sp, 0x10
/* BA1F70 80241840 AFA30020 */  sw        $v1, 0x20($sp)
/* BA1F74 80241844 8E2300D0 */  lw        $v1, 0xd0($s1)
/* BA1F78 80241848 3C014348 */  lui       $at, 0x4348
/* BA1F7C 8024184C 44810000 */  mtc1      $at, $f0
/* BA1F80 80241850 8C63002C */  lw        $v1, 0x2c($v1)
/* BA1F84 80241854 0040982D */  daddu     $s3, $v0, $zero
/* BA1F88 80241858 E7A00028 */  swc1      $f0, 0x28($sp)
/* BA1F8C 8024185C A7A0002C */  sh        $zero, 0x2c($sp)
/* BA1F90 80241860 16000005 */  bnez      $s0, .L80241878
/* BA1F94 80241864 AFA30024 */   sw       $v1, 0x24($sp)
/* BA1F98 80241868 8E2200B0 */  lw        $v0, 0xb0($s1)
/* BA1F9C 8024186C 30420004 */  andi      $v0, $v0, 4
/* BA1FA0 80241870 10400011 */  beqz      $v0, .L802418B8
/* BA1FA4 80241874 00000000 */   nop
.L80241878:
/* BA1FA8 80241878 AE400070 */  sw        $zero, 0x70($s2)
/* BA1FAC 8024187C A6A0008E */  sh        $zero, 0x8e($s5)
/* BA1FB0 80241880 8E2200CC */  lw        $v0, 0xcc($s1)
/* BA1FB4 80241884 8C420000 */  lw        $v0, ($v0)
/* BA1FB8 80241888 AEA20028 */  sw        $v0, 0x28($s5)
/* BA1FBC 8024188C 8E2200B0 */  lw        $v0, 0xb0($s1)
/* BA1FC0 80241890 30420004 */  andi      $v0, $v0, 4
/* BA1FC4 80241894 10400008 */  beqz      $v0, .L802418B8
/* BA1FC8 80241898 AE20006C */   sw       $zero, 0x6c($s1)
/* BA1FCC 8024189C 24020063 */  addiu     $v0, $zero, 0x63
/* BA1FD0 802418A0 AE420070 */  sw        $v0, 0x70($s2)
/* BA1FD4 802418A4 AE400074 */  sw        $zero, 0x74($s2)
/* BA1FD8 802418A8 8E2200B0 */  lw        $v0, 0xb0($s1)
/* BA1FDC 802418AC 2403FFFB */  addiu     $v1, $zero, -5
/* BA1FE0 802418B0 00431024 */  and       $v0, $v0, $v1
/* BA1FE4 802418B4 AE2200B0 */  sw        $v0, 0xb0($s1)
.L802418B8:
/* BA1FE8 802418B8 8E430070 */  lw        $v1, 0x70($s2)
/* BA1FEC 802418BC 2410000B */  addiu     $s0, $zero, 0xb
/* BA1FF0 802418C0 1070002A */  beq       $v1, $s0, .L8024196C
/* BA1FF4 802418C4 2862000C */   slti     $v0, $v1, 0xc
/* BA1FF8 802418C8 1040000D */  beqz      $v0, .L80241900
/* BA1FFC 802418CC 24020001 */   addiu    $v0, $zero, 1
/* BA2000 802418D0 1062001A */  beq       $v1, $v0, .L8024193C
/* BA2004 802418D4 28620002 */   slti     $v0, $v1, 2
/* BA2008 802418D8 10400005 */  beqz      $v0, .L802418F0
/* BA200C 802418DC 2402000A */   addiu    $v0, $zero, 0xa
/* BA2010 802418E0 10600013 */  beqz      $v1, .L80241930
/* BA2014 802418E4 0240202D */   daddu    $a0, $s2, $zero
/* BA2018 802418E8 0809067B */  j         .L802419EC
/* BA201C 802418EC 00000000 */   nop
.L802418F0:
/* BA2020 802418F0 10620018 */  beq       $v1, $v0, .L80241954
/* BA2024 802418F4 0240202D */   daddu    $a0, $s2, $zero
/* BA2028 802418F8 0809067B */  j         .L802419EC
/* BA202C 802418FC 00000000 */   nop
.L80241900:
/* BA2030 80241900 2402000D */  addiu     $v0, $zero, 0xd
/* BA2034 80241904 10620029 */  beq       $v1, $v0, .L802419AC
/* BA2038 80241908 0062102A */   slt      $v0, $v1, $v0
/* BA203C 8024190C 14400020 */  bnez      $v0, .L80241990
/* BA2040 80241910 0240202D */   daddu    $a0, $s2, $zero
/* BA2044 80241914 2402000E */  addiu     $v0, $zero, 0xe
/* BA2048 80241918 1062002D */  beq       $v1, $v0, .L802419D0
/* BA204C 8024191C 24020063 */   addiu    $v0, $zero, 0x63
/* BA2050 80241920 10620030 */  beq       $v1, $v0, .L802419E4
/* BA2054 80241924 00000000 */   nop
/* BA2058 80241928 0809067B */  j         .L802419EC
/* BA205C 8024192C 00000000 */   nop
.L80241930:
/* BA2060 80241930 0260282D */  daddu     $a1, $s3, $zero
/* BA2064 80241934 0C090250 */  jal       mim_05_UnkNpcAIFunc31
/* BA2068 80241938 0280302D */   daddu    $a2, $s4, $zero
.L8024193C:
/* BA206C 8024193C 0240202D */  daddu     $a0, $s2, $zero
/* BA2070 80241940 0260282D */  daddu     $a1, $s3, $zero
/* BA2074 80241944 0C09026B */  jal       mim_05_UnkNpcAIFunc32
/* BA2078 80241948 0280302D */   daddu    $a2, $s4, $zero
/* BA207C 8024194C 0809067B */  j         .L802419EC
/* BA2080 80241950 00000000 */   nop
.L80241954:
/* BA2084 80241954 0260282D */  daddu     $a1, $s3, $zero
/* BA2088 80241958 0C0902AA */  jal       btl_restore_world_cameras_BA11D8
/* BA208C 8024195C 0280302D */   daddu    $a2, $s4, $zero
/* BA2090 80241960 8E420070 */  lw        $v0, 0x70($s2)
/* BA2094 80241964 14500021 */  bne       $v0, $s0, .L802419EC
/* BA2098 80241968 00000000 */   nop
.L8024196C:
/* BA209C 8024196C 0240202D */  daddu     $a0, $s2, $zero
/* BA20A0 80241970 0260282D */  daddu     $a1, $s3, $zero
/* BA20A4 80241974 0C09053A */  jal       mim_05_UnkNpcDurationFlagFunc3
/* BA20A8 80241978 0280302D */   daddu    $a2, $s4, $zero
/* BA20AC 8024197C 8E430070 */  lw        $v1, 0x70($s2)
/* BA20B0 80241980 2402000C */  addiu     $v0, $zero, 0xc
/* BA20B4 80241984 14620019 */  bne       $v1, $v0, .L802419EC
/* BA20B8 80241988 00000000 */   nop
/* BA20BC 8024198C 0240202D */  daddu     $a0, $s2, $zero
.L80241990:
/* BA20C0 80241990 0260282D */  daddu     $a1, $s3, $zero
/* BA20C4 80241994 0C09055E */  jal       mim_05_UnkNpcAIFunc33
/* BA20C8 80241998 0280302D */   daddu    $a2, $s4, $zero
/* BA20CC 8024199C 8E430070 */  lw        $v1, 0x70($s2)
/* BA20D0 802419A0 2402000D */  addiu     $v0, $zero, 0xd
/* BA20D4 802419A4 14620011 */  bne       $v1, $v0, .L802419EC
/* BA20D8 802419A8 00000000 */   nop
.L802419AC:
/* BA20DC 802419AC 0240202D */  daddu     $a0, $s2, $zero
/* BA20E0 802419B0 0260282D */  daddu     $a1, $s3, $zero
/* BA20E4 802419B4 0C09059E */  jal       mim_05_UnkNpcDurationFlagFunc2
/* BA20E8 802419B8 0280302D */   daddu    $a2, $s4, $zero
/* BA20EC 802419BC 8E430070 */  lw        $v1, 0x70($s2)
/* BA20F0 802419C0 2402000E */  addiu     $v0, $zero, 0xe
/* BA20F4 802419C4 14620009 */  bne       $v1, $v0, .L802419EC
/* BA20F8 802419C8 00000000 */   nop
/* BA20FC 802419CC 0240202D */  daddu     $a0, $s2, $zero
.L802419D0:
/* BA2100 802419D0 0260282D */  daddu     $a1, $s3, $zero
/* BA2104 802419D4 0C0905B6 */  jal       mim_05_UnkNpcAIFunc30
/* BA2108 802419D8 0280302D */   daddu    $a2, $s4, $zero
/* BA210C 802419DC 0809067B */  j         .L802419EC
/* BA2110 802419E0 00000000 */   nop
.L802419E4:
/* BA2114 802419E4 0C0129CF */  jal       func_8004A73C
/* BA2118 802419E8 0240202D */   daddu    $a0, $s2, $zero
.L802419EC:
/* BA211C 802419EC 8FBF0048 */  lw        $ra, 0x48($sp)
/* BA2120 802419F0 8FB50044 */  lw        $s5, 0x44($sp)
/* BA2124 802419F4 8FB40040 */  lw        $s4, 0x40($sp)
/* BA2128 802419F8 8FB3003C */  lw        $s3, 0x3c($sp)
/* BA212C 802419FC 8FB20038 */  lw        $s2, 0x38($sp)
/* BA2130 80241A00 8FB10034 */  lw        $s1, 0x34($sp)
/* BA2134 80241A04 8FB00030 */  lw        $s0, 0x30($sp)
/* BA2138 80241A08 0000102D */  daddu     $v0, $zero, $zero
/* BA213C 80241A0C 03E00008 */  jr        $ra
/* BA2140 80241A10 27BD0050 */   addiu    $sp, $sp, 0x50
/* BA2144 80241A14 00000000 */  nop
/* BA2148 80241A18 00000000 */  nop
/* BA214C 80241A1C 00000000 */  nop
