.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241754_D19F34
/* D19F34 80241754 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* D19F38 80241758 AFB20038 */  sw        $s2, 0x38($sp)
/* D19F3C 8024175C 0080902D */  daddu     $s2, $a0, $zero
/* D19F40 80241760 AFBF0048 */  sw        $ra, 0x48($sp)
/* D19F44 80241764 AFB50044 */  sw        $s5, 0x44($sp)
/* D19F48 80241768 AFB40040 */  sw        $s4, 0x40($sp)
/* D19F4C 8024176C AFB3003C */  sw        $s3, 0x3c($sp)
/* D19F50 80241770 AFB10034 */  sw        $s1, 0x34($sp)
/* D19F54 80241774 AFB00030 */  sw        $s0, 0x30($sp)
/* D19F58 80241778 8E510148 */  lw        $s1, 0x148($s2)
/* D19F5C 8024177C 86240008 */  lh        $a0, 8($s1)
/* D19F60 80241780 0C00EABB */  jal       get_npc_unsafe
/* D19F64 80241784 00A0802D */   daddu    $s0, $a1, $zero
/* D19F68 80241788 8E43000C */  lw        $v1, 0xc($s2)
/* D19F6C 8024178C 0240202D */  daddu     $a0, $s2, $zero
/* D19F70 80241790 8C650000 */  lw        $a1, ($v1)
/* D19F74 80241794 0C0B1EAF */  jal       evt_get_variable
/* D19F78 80241798 0040A82D */   daddu    $s5, $v0, $zero
/* D19F7C 8024179C AFA00010 */  sw        $zero, 0x10($sp)
/* D19F80 802417A0 8E2300D0 */  lw        $v1, 0xd0($s1)
/* D19F84 802417A4 8C630030 */  lw        $v1, 0x30($v1)
/* D19F88 802417A8 AFA30014 */  sw        $v1, 0x14($sp)
/* D19F8C 802417AC 8E2300D0 */  lw        $v1, 0xd0($s1)
/* D19F90 802417B0 8C63001C */  lw        $v1, 0x1c($v1)
/* D19F94 802417B4 AFA30018 */  sw        $v1, 0x18($sp)
/* D19F98 802417B8 8E2300D0 */  lw        $v1, 0xd0($s1)
/* D19F9C 802417BC 8C630024 */  lw        $v1, 0x24($v1)
/* D19FA0 802417C0 AFA3001C */  sw        $v1, 0x1c($sp)
/* D19FA4 802417C4 8E2300D0 */  lw        $v1, 0xd0($s1)
/* D19FA8 802417C8 8C630028 */  lw        $v1, 0x28($v1)
/* D19FAC 802417CC 27B40010 */  addiu     $s4, $sp, 0x10
/* D19FB0 802417D0 AFA30020 */  sw        $v1, 0x20($sp)
/* D19FB4 802417D4 8E2300D0 */  lw        $v1, 0xd0($s1)
/* D19FB8 802417D8 3C014348 */  lui       $at, 0x4348
/* D19FBC 802417DC 44810000 */  mtc1      $at, $f0
/* D19FC0 802417E0 8C63002C */  lw        $v1, 0x2c($v1)
/* D19FC4 802417E4 0040982D */  daddu     $s3, $v0, $zero
/* D19FC8 802417E8 E7A00028 */  swc1      $f0, 0x28($sp)
/* D19FCC 802417EC A7A0002C */  sh        $zero, 0x2c($sp)
/* D19FD0 802417F0 16000005 */  bnez      $s0, .L80241808
/* D19FD4 802417F4 AFA30024 */   sw       $v1, 0x24($sp)
/* D19FD8 802417F8 8E2200B0 */  lw        $v0, 0xb0($s1)
/* D19FDC 802417FC 30420004 */  andi      $v0, $v0, 4
/* D19FE0 80241800 10400011 */  beqz      $v0, .L80241848
/* D19FE4 80241804 00000000 */   nop
.L80241808:
/* D19FE8 80241808 AE400070 */  sw        $zero, 0x70($s2)
/* D19FEC 8024180C A6A0008E */  sh        $zero, 0x8e($s5)
/* D19FF0 80241810 8E2200CC */  lw        $v0, 0xcc($s1)
/* D19FF4 80241814 8C420000 */  lw        $v0, ($v0)
/* D19FF8 80241818 AEA20028 */  sw        $v0, 0x28($s5)
/* D19FFC 8024181C 8E2200B0 */  lw        $v0, 0xb0($s1)
/* D1A000 80241820 30420004 */  andi      $v0, $v0, 4
/* D1A004 80241824 10400008 */  beqz      $v0, .L80241848
/* D1A008 80241828 AE20006C */   sw       $zero, 0x6c($s1)
/* D1A00C 8024182C 24020063 */  addiu     $v0, $zero, 0x63
/* D1A010 80241830 AE420070 */  sw        $v0, 0x70($s2)
/* D1A014 80241834 AE400074 */  sw        $zero, 0x74($s2)
/* D1A018 80241838 8E2200B0 */  lw        $v0, 0xb0($s1)
/* D1A01C 8024183C 2403FFFB */  addiu     $v1, $zero, -5
/* D1A020 80241840 00431024 */  and       $v0, $v0, $v1
/* D1A024 80241844 AE2200B0 */  sw        $v0, 0xb0($s1)
.L80241848:
/* D1A028 80241848 8E430070 */  lw        $v1, 0x70($s2)
/* D1A02C 8024184C 2410000B */  addiu     $s0, $zero, 0xb
/* D1A030 80241850 1070002A */  beq       $v1, $s0, .L802418FC
/* D1A034 80241854 2862000C */   slti     $v0, $v1, 0xc
/* D1A038 80241858 1040000D */  beqz      $v0, .L80241890
/* D1A03C 8024185C 24020001 */   addiu    $v0, $zero, 1
/* D1A040 80241860 1062001A */  beq       $v1, $v0, .L802418CC
/* D1A044 80241864 28620002 */   slti     $v0, $v1, 2
/* D1A048 80241868 10400005 */  beqz      $v0, .L80241880
/* D1A04C 8024186C 2402000A */   addiu    $v0, $zero, 0xa
/* D1A050 80241870 10600013 */  beqz      $v1, .L802418C0
/* D1A054 80241874 0240202D */   daddu    $a0, $s2, $zero
/* D1A058 80241878 0809065F */  j         .L8024197C
/* D1A05C 8024187C 00000000 */   nop
.L80241880:
/* D1A060 80241880 10620018 */  beq       $v1, $v0, .L802418E4
/* D1A064 80241884 0240202D */   daddu    $a0, $s2, $zero
/* D1A068 80241888 0809065F */  j         .L8024197C
/* D1A06C 8024188C 00000000 */   nop
.L80241890:
/* D1A070 80241890 2402000D */  addiu     $v0, $zero, 0xd
/* D1A074 80241894 10620029 */  beq       $v1, $v0, .L8024193C
/* D1A078 80241898 0062102A */   slt      $v0, $v1, $v0
/* D1A07C 8024189C 14400020 */  bnez      $v0, .L80241920
/* D1A080 802418A0 0240202D */   daddu    $a0, $s2, $zero
/* D1A084 802418A4 2402000E */  addiu     $v0, $zero, 0xe
/* D1A088 802418A8 1062002D */  beq       $v1, $v0, .L80241960
/* D1A08C 802418AC 24020063 */   addiu    $v0, $zero, 0x63
/* D1A090 802418B0 10620030 */  beq       $v1, $v0, .L80241974
/* D1A094 802418B4 00000000 */   nop
/* D1A098 802418B8 0809065F */  j         .L8024197C
/* D1A09C 802418BC 00000000 */   nop
.L802418C0:
/* D1A0A0 802418C0 0260282D */  daddu     $a1, $s3, $zero
/* D1A0A4 802418C4 0C090234 */  jal       func_802408D0_D190B0
/* D1A0A8 802418C8 0280302D */   daddu    $a2, $s4, $zero
.L802418CC:
/* D1A0AC 802418CC 0240202D */  daddu     $a0, $s2, $zero
/* D1A0B0 802418D0 0260282D */  daddu     $a1, $s3, $zero
/* D1A0B4 802418D4 0C09024F */  jal       func_8024093C_D1911C
/* D1A0B8 802418D8 0280302D */   daddu    $a2, $s4, $zero
/* D1A0BC 802418DC 0809065F */  j         .L8024197C
/* D1A0C0 802418E0 00000000 */   nop
.L802418E4:
/* D1A0C4 802418E4 0260282D */  daddu     $a1, $s3, $zero
/* D1A0C8 802418E8 0C09028E */  jal       func_80240A38_D19218
/* D1A0CC 802418EC 0280302D */   daddu    $a2, $s4, $zero
/* D1A0D0 802418F0 8E420070 */  lw        $v0, 0x70($s2)
/* D1A0D4 802418F4 14500021 */  bne       $v0, $s0, .L8024197C
/* D1A0D8 802418F8 00000000 */   nop
.L802418FC:
/* D1A0DC 802418FC 0240202D */  daddu     $a0, $s2, $zero
/* D1A0E0 80241900 0260282D */  daddu     $a1, $s3, $zero
/* D1A0E4 80241904 0C09051E */  jal       sam_05_UnkNpcDurationFlagFunc3
/* D1A0E8 80241908 0280302D */   daddu    $a2, $s4, $zero
/* D1A0EC 8024190C 8E430070 */  lw        $v1, 0x70($s2)
/* D1A0F0 80241910 2402000C */  addiu     $v0, $zero, 0xc
/* D1A0F4 80241914 14620019 */  bne       $v1, $v0, .L8024197C
/* D1A0F8 80241918 00000000 */   nop
/* D1A0FC 8024191C 0240202D */  daddu     $a0, $s2, $zero
.L80241920:
/* D1A100 80241920 0260282D */  daddu     $a1, $s3, $zero
/* D1A104 80241924 0C090542 */  jal       func_80241508_D19CE8
/* D1A108 80241928 0280302D */   daddu    $a2, $s4, $zero
/* D1A10C 8024192C 8E430070 */  lw        $v1, 0x70($s2)
/* D1A110 80241930 2402000D */  addiu     $v0, $zero, 0xd
/* D1A114 80241934 14620011 */  bne       $v1, $v0, .L8024197C
/* D1A118 80241938 00000000 */   nop
.L8024193C:
/* D1A11C 8024193C 0240202D */  daddu     $a0, $s2, $zero
/* D1A120 80241940 0260282D */  daddu     $a1, $s3, $zero
/* D1A124 80241944 0C090582 */  jal       sam_05_UnkNpcDurationFlagFunc2
/* D1A128 80241948 0280302D */   daddu    $a2, $s4, $zero
/* D1A12C 8024194C 8E430070 */  lw        $v1, 0x70($s2)
/* D1A130 80241950 2402000E */  addiu     $v0, $zero, 0xe
/* D1A134 80241954 14620009 */  bne       $v1, $v0, .L8024197C
/* D1A138 80241958 00000000 */   nop
/* D1A13C 8024195C 0240202D */  daddu     $a0, $s2, $zero
.L80241960:
/* D1A140 80241960 0260282D */  daddu     $a1, $s3, $zero
/* D1A144 80241964 0C09059A */  jal       sam_05_UnkNpcAIFunc30
/* D1A148 80241968 0280302D */   daddu    $a2, $s4, $zero
/* D1A14C 8024196C 0809065F */  j         .L8024197C
/* D1A150 80241970 00000000 */   nop
.L80241974:
/* D1A154 80241974 0C0129CF */  jal       func_8004A73C
/* D1A158 80241978 0240202D */   daddu    $a0, $s2, $zero
.L8024197C:
/* D1A15C 8024197C 8FBF0048 */  lw        $ra, 0x48($sp)
/* D1A160 80241980 8FB50044 */  lw        $s5, 0x44($sp)
/* D1A164 80241984 8FB40040 */  lw        $s4, 0x40($sp)
/* D1A168 80241988 8FB3003C */  lw        $s3, 0x3c($sp)
/* D1A16C 8024198C 8FB20038 */  lw        $s2, 0x38($sp)
/* D1A170 80241990 8FB10034 */  lw        $s1, 0x34($sp)
/* D1A174 80241994 8FB00030 */  lw        $s0, 0x30($sp)
/* D1A178 80241998 0000102D */  daddu     $v0, $zero, $zero
/* D1A17C 8024199C 03E00008 */  jr        $ra
/* D1A180 802419A0 27BD0050 */   addiu    $sp, $sp, 0x50
