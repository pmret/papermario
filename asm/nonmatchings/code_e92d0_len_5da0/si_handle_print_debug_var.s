.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel si_handle_print_debug_var
/* EB7CC 802C6E1C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* EB7D0 802C6E20 0080382D */  daddu     $a3, $a0, $zero
/* EB7D4 802C6E24 AFBF0024 */  sw        $ra, 0x24($sp)
/* EB7D8 802C6E28 AFB20020 */  sw        $s2, 0x20($sp)
/* EB7DC 802C6E2C AFB1001C */  sw        $s1, 0x1c($sp)
/* EB7E0 802C6E30 AFB00018 */  sw        $s0, 0x18($sp)
/* EB7E4 802C6E34 8CE2000C */  lw        $v0, 0xc($a3)
/* EB7E8 802C6E38 8C500000 */  lw        $s0, ($v0)
/* EB7EC 802C6E3C 3C11EFE8 */  lui       $s1, 0xefe8
/* EB7F0 802C6E40 36312080 */  ori       $s1, $s1, 0x2080
/* EB7F4 802C6E44 0230102A */  slt       $v0, $s1, $s0
/* EB7F8 802C6E48 14400007 */  bnez      $v0, .L802C6E68
/* EB7FC 802C6E4C 3C12F2E3 */   lui      $s2, 0xf2e3
/* EB800 802C6E50 3C04802E */  lui       $a0, 0x802e
/* EB804 802C6E54 2484ACA0 */  addiu     $a0, $a0, -0x5360
/* EB808 802C6E58 3C05802E */  lui       $a1, 0x802e
/* EB80C 802C6E5C 24A59D98 */  addiu     $a1, $a1, -0x6268
/* EB810 802C6E60 080B1CDE */  j         .L802C7378
/* EB814 802C6E64 0200302D */   daddu    $a2, $s0, $zero
.L802C6E68:
/* EB818 802C6E68 36521100 */  ori       $s2, $s2, 0x1100
/* EB81C 802C6E6C 0250102A */  slt       $v0, $s2, $s0
/* EB820 802C6E70 1440000D */  bnez      $v0, .L802C6EA8
/* EB824 802C6E74 3C02F414 */   lui      $v0, 0xf414
/* EB828 802C6E78 0C0B1248 */  jal       fixed_var_to_float
/* EB82C 802C6E7C 0200202D */   daddu    $a0, $s0, $zero
/* EB830 802C6E80 3C04802E */  lui       $a0, 0x802e
/* EB834 802C6E84 2484ACA0 */  addiu     $a0, $a0, -0x5360
/* EB838 802C6E88 460000A1 */  cvt.d.s   $f2, $f0
/* EB83C 802C6E8C 44071000 */  mfc1      $a3, $f2
/* EB840 802C6E90 44061800 */  mfc1      $a2, $f3
/* EB844 802C6E94 3C05802E */  lui       $a1, 0x802e
/* EB848 802C6E98 0C01953C */  jal       sprintf
/* EB84C 802C6E9C 24A59DA8 */   addiu    $a1, $a1, -0x6258
/* EB850 802C6EA0 080B1CE0 */  j         .L802C7380
/* EB854 802C6EA4 00000000 */   nop      
.L802C6EA8:
/* EB858 802C6EA8 34423E00 */  ori       $v0, $v0, 0x3e00
/* EB85C 802C6EAC 0050102A */  slt       $v0, $v0, $s0
/* EB860 802C6EB0 14400016 */  bnez      $v0, .L802C6F0C
/* EB864 802C6EB4 3C02F545 */   lui      $v0, 0xf545
/* EB868 802C6EB8 3C020C84 */  lui       $v0, 0xc84
/* EB86C 802C6EBC 34425880 */  ori       $v0, $v0, 0x5880
/* EB870 802C6EC0 02028021 */  addu      $s0, $s0, $v0
/* EB874 802C6EC4 06010002 */  bgez      $s0, .L802C6ED0
/* EB878 802C6EC8 0200182D */   daddu    $v1, $s0, $zero
/* EB87C 802C6ECC 2603001F */  addiu     $v1, $s0, 0x1f
.L802C6ED0:
/* EB880 802C6ED0 00034143 */  sra       $t0, $v1, 5
/* EB884 802C6ED4 0100182D */  daddu     $v1, $t0, $zero
/* EB888 802C6ED8 00031140 */  sll       $v0, $v1, 5
/* EB88C 802C6EDC 02024023 */  subu      $t0, $s0, $v0
/* EB890 802C6EE0 3C04802E */  lui       $a0, 0x802e
/* EB894 802C6EE4 2484ACA0 */  addiu     $a0, $a0, -0x5360
/* EB898 802C6EE8 3C05802E */  lui       $a1, 0x802e
/* EB89C 802C6EEC 24A59DBC */  addiu     $a1, $a1, -0x6244
/* EB8A0 802C6EF0 0200302D */  daddu     $a2, $s0, $zero
/* EB8A4 802C6EF4 00031880 */  sll       $v1, $v1, 2
/* EB8A8 802C6EF8 8CE20140 */  lw        $v0, 0x140($a3)
/* EB8AC 802C6EFC 00621821 */  addu      $v1, $v1, $v0
/* EB8B0 802C6F00 8C620000 */  lw        $v0, ($v1)
/* EB8B4 802C6F04 080B1C7F */  j         .L802C71FC
/* EB8B8 802C6F08 24070001 */   addiu    $a3, $zero, 1
.L802C6F0C:
/* EB8BC 802C6F0C 34426B00 */  ori       $v0, $v0, 0x6b00
/* EB8C0 802C6F10 0050102A */  slt       $v0, $v0, $s0
/* EB8C4 802C6F14 14400021 */  bnez      $v0, .L802C6F9C
/* EB8C8 802C6F18 3C02F676 */   lui      $v0, 0xf676
/* EB8CC 802C6F1C 3C020B53 */  lui       $v0, 0xb53
/* EB8D0 802C6F20 34422B80 */  ori       $v0, $v0, 0x2b80
/* EB8D4 802C6F24 02028021 */  addu      $s0, $s0, $v0
/* EB8D8 802C6F28 8CE3013C */  lw        $v1, 0x13c($a3)
/* EB8DC 802C6F2C 00101080 */  sll       $v0, $s0, 2
/* EB8E0 802C6F30 00431021 */  addu      $v0, $v0, $v1
/* EB8E4 802C6F34 8C470000 */  lw        $a3, ($v0)
/* EB8E8 802C6F38 0227102A */  slt       $v0, $s1, $a3
/* EB8EC 802C6F3C 14400007 */  bnez      $v0, .L802C6F5C
/* EB8F0 802C6F40 0247102A */   slt      $v0, $s2, $a3
/* EB8F4 802C6F44 3C04802E */  lui       $a0, 0x802e
/* EB8F8 802C6F48 2484ACA0 */  addiu     $a0, $a0, -0x5360
/* EB8FC 802C6F4C 3C05802E */  lui       $a1, 0x802e
/* EB900 802C6F50 24A59DCC */  addiu     $a1, $a1, -0x6234
/* EB904 802C6F54 080B1CDE */  j         .L802C7378
/* EB908 802C6F58 00E0302D */   daddu    $a2, $a3, $zero
.L802C6F5C:
/* EB90C 802C6F5C 1440000A */  bnez      $v0, .L802C6F88
/* EB910 802C6F60 00000000 */   nop      
/* EB914 802C6F64 0C0B1248 */  jal       fixed_var_to_float
/* EB918 802C6F68 00E0202D */   daddu    $a0, $a3, $zero
/* EB91C 802C6F6C 46000021 */  cvt.d.s   $f0, $f0
/* EB920 802C6F70 F7A00010 */  sdc1      $f0, 0x10($sp)
/* EB924 802C6F74 3C04802E */  lui       $a0, 0x802e
/* EB928 802C6F78 2484ACA0 */  addiu     $a0, $a0, -0x5360
/* EB92C 802C6F7C 3C05802E */  lui       $a1, 0x802e
/* EB930 802C6F80 080B1CCE */  j         .L802C7338
/* EB934 802C6F84 24A59DDC */   addiu    $a1, $a1, -0x6224
.L802C6F88:
/* EB938 802C6F88 3C04802E */  lui       $a0, 0x802e
/* EB93C 802C6F8C 2484ACA0 */  addiu     $a0, $a0, -0x5360
/* EB940 802C6F90 3C05802E */  lui       $a1, 0x802e
/* EB944 802C6F94 080B1CD6 */  j         .L802C7358
/* EB948 802C6F98 24A59DF0 */   addiu    $a1, $a1, -0x6210
.L802C6F9C:
/* EB94C 802C6F9C 34429800 */  ori       $v0, $v0, 0x9800
/* EB950 802C6FA0 0050102A */  slt       $v0, $v0, $s0
/* EB954 802C6FA4 14400020 */  bnez      $v0, .L802C7028
/* EB958 802C6FA8 3C02F7A7 */   lui      $v0, 0xf7a7
/* EB95C 802C6FAC 3C020A21 */  lui       $v0, 0xa21
/* EB960 802C6FB0 3442FE80 */  ori       $v0, $v0, 0xfe80
/* EB964 802C6FB4 02028021 */  addu      $s0, $s0, $v0
/* EB968 802C6FB8 0C05154E */  jal       get_global_byte
/* EB96C 802C6FBC 0200202D */   daddu    $a0, $s0, $zero
/* EB970 802C6FC0 0040382D */  daddu     $a3, $v0, $zero
/* EB974 802C6FC4 0227102A */  slt       $v0, $s1, $a3
/* EB978 802C6FC8 14400007 */  bnez      $v0, .L802C6FE8
/* EB97C 802C6FCC 0247102A */   slt      $v0, $s2, $a3
/* EB980 802C6FD0 3C04802E */  lui       $a0, 0x802e
/* EB984 802C6FD4 2484ACA0 */  addiu     $a0, $a0, -0x5360
/* EB988 802C6FD8 3C05802E */  lui       $a1, 0x802e
/* EB98C 802C6FDC 24A59E00 */  addiu     $a1, $a1, -0x6200
/* EB990 802C6FE0 080B1CDE */  j         .L802C7378
/* EB994 802C6FE4 00E0302D */   daddu    $a2, $a3, $zero
.L802C6FE8:
/* EB998 802C6FE8 1440000A */  bnez      $v0, .L802C7014
/* EB99C 802C6FEC 00000000 */   nop      
/* EB9A0 802C6FF0 0C0B1248 */  jal       fixed_var_to_float
/* EB9A4 802C6FF4 00E0202D */   daddu    $a0, $a3, $zero
/* EB9A8 802C6FF8 46000021 */  cvt.d.s   $f0, $f0
/* EB9AC 802C6FFC F7A00010 */  sdc1      $f0, 0x10($sp)
/* EB9B0 802C7000 3C04802E */  lui       $a0, 0x802e
/* EB9B4 802C7004 2484ACA0 */  addiu     $a0, $a0, -0x5360
/* EB9B8 802C7008 3C05802E */  lui       $a1, 0x802e
/* EB9BC 802C700C 080B1CCE */  j         .L802C7338
/* EB9C0 802C7010 24A59E10 */   addiu    $a1, $a1, -0x61f0
.L802C7014:
/* EB9C4 802C7014 3C04802E */  lui       $a0, 0x802e
/* EB9C8 802C7018 2484ACA0 */  addiu     $a0, $a0, -0x5360
/* EB9CC 802C701C 3C05802E */  lui       $a1, 0x802e
/* EB9D0 802C7020 080B1CD6 */  j         .L802C7358
/* EB9D4 802C7024 24A59E24 */   addiu    $a1, $a1, -0x61dc
.L802C7028:
/* EB9D8 802C7028 3442C500 */  ori       $v0, $v0, 0xc500
/* EB9DC 802C702C 0050102A */  slt       $v0, $v0, $s0
/* EB9E0 802C7030 14400020 */  bnez      $v0, .L802C70B4
/* EB9E4 802C7034 3C02F8D8 */   lui      $v0, 0xf8d8
/* EB9E8 802C7038 3C0208F0 */  lui       $v0, 0x8f0
/* EB9EC 802C703C 3442D180 */  ori       $v0, $v0, 0xd180
/* EB9F0 802C7040 02028021 */  addu      $s0, $s0, $v0
/* EB9F4 802C7044 0C051594 */  jal       get_area_byte
/* EB9F8 802C7048 0200202D */   daddu    $a0, $s0, $zero
/* EB9FC 802C704C 0040382D */  daddu     $a3, $v0, $zero
/* EBA00 802C7050 0227102A */  slt       $v0, $s1, $a3
/* EBA04 802C7054 14400007 */  bnez      $v0, .L802C7074
/* EBA08 802C7058 0247102A */   slt      $v0, $s2, $a3
/* EBA0C 802C705C 3C04802E */  lui       $a0, 0x802e
/* EBA10 802C7060 2484ACA0 */  addiu     $a0, $a0, -0x5360
/* EBA14 802C7064 3C05802E */  lui       $a1, 0x802e
/* EBA18 802C7068 24A59E34 */  addiu     $a1, $a1, -0x61cc
/* EBA1C 802C706C 080B1CDE */  j         .L802C7378
/* EBA20 802C7070 00E0302D */   daddu    $a2, $a3, $zero
.L802C7074:
/* EBA24 802C7074 1440000A */  bnez      $v0, .L802C70A0
/* EBA28 802C7078 00000000 */   nop      
/* EBA2C 802C707C 0C0B1248 */  jal       fixed_var_to_float
/* EBA30 802C7080 00E0202D */   daddu    $a0, $a3, $zero
/* EBA34 802C7084 46000021 */  cvt.d.s   $f0, $f0
/* EBA38 802C7088 F7A00010 */  sdc1      $f0, 0x10($sp)
/* EBA3C 802C708C 3C04802E */  lui       $a0, 0x802e
/* EBA40 802C7090 2484ACA0 */  addiu     $a0, $a0, -0x5360
/* EBA44 802C7094 3C05802E */  lui       $a1, 0x802e
/* EBA48 802C7098 080B1CCE */  j         .L802C7338
/* EBA4C 802C709C 24A59E44 */   addiu    $a1, $a1, -0x61bc
.L802C70A0:
/* EBA50 802C70A0 3C04802E */  lui       $a0, 0x802e
/* EBA54 802C70A4 2484ACA0 */  addiu     $a0, $a0, -0x5360
/* EBA58 802C70A8 3C05802E */  lui       $a1, 0x802e
/* EBA5C 802C70AC 080B1CD6 */  j         .L802C7358
/* EBA60 802C70B0 24A59E58 */   addiu    $a1, $a1, -0x61a8
.L802C70B4:
/* EBA64 802C70B4 3442F200 */  ori       $v0, $v0, 0xf200
/* EBA68 802C70B8 0050102A */  slt       $v0, $v0, $s0
/* EBA6C 802C70BC 1440000C */  bnez      $v0, .L802C70F0
/* EBA70 802C70C0 3C02FA0A */   lui      $v0, 0xfa0a
/* EBA74 802C70C4 3C0207BF */  lui       $v0, 0x7bf
/* EBA78 802C70C8 3442A480 */  ori       $v0, $v0, 0xa480
/* EBA7C 802C70CC 02028021 */  addu      $s0, $s0, $v0
/* EBA80 802C70D0 0C05152F */  jal       get_global_flag
/* EBA84 802C70D4 0200202D */   daddu    $a0, $s0, $zero
/* EBA88 802C70D8 3C04802E */  lui       $a0, 0x802e
/* EBA8C 802C70DC 2484ACA0 */  addiu     $a0, $a0, -0x5360
/* EBA90 802C70E0 3C05802E */  lui       $a1, 0x802e
/* EBA94 802C70E4 24A59E68 */  addiu     $a1, $a1, -0x6198
/* EBA98 802C70E8 080B1C4A */  j         .L802C7128
/* EBA9C 802C70EC 0200302D */   daddu    $a2, $s0, $zero
.L802C70F0:
/* EBAA0 802C70F0 34421F00 */  ori       $v0, $v0, 0x1f00
/* EBAA4 802C70F4 0050102A */  slt       $v0, $v0, $s0
/* EBAA8 802C70F8 1440000F */  bnez      $v0, .L802C7138
/* EBAAC 802C70FC 3C02FB3B */   lui      $v0, 0xfb3b
/* EBAB0 802C7100 3C02068E */  lui       $v0, 0x68e
/* EBAB4 802C7104 34427780 */  ori       $v0, $v0, 0x7780
/* EBAB8 802C7108 02028021 */  addu      $s0, $s0, $v0
/* EBABC 802C710C 0C05157C */  jal       get_area_flag
/* EBAC0 802C7110 0200202D */   daddu    $a0, $s0, $zero
/* EBAC4 802C7114 3C04802E */  lui       $a0, 0x802e
/* EBAC8 802C7118 2484ACA0 */  addiu     $a0, $a0, -0x5360
/* EBACC 802C711C 3C05802E */  lui       $a1, 0x802e
/* EBAD0 802C7120 24A59E78 */  addiu     $a1, $a1, -0x6188
/* EBAD4 802C7124 0200302D */  daddu     $a2, $s0, $zero
.L802C7128:
/* EBAD8 802C7128 0C01953C */  jal       sprintf
/* EBADC 802C712C 0040382D */   daddu    $a3, $v0, $zero
/* EBAE0 802C7130 080B1CE0 */  j         .L802C7380
/* EBAE4 802C7134 00000000 */   nop      
.L802C7138:
/* EBAE8 802C7138 34424C00 */  ori       $v0, $v0, 0x4c00
/* EBAEC 802C713C 0050102A */  slt       $v0, $v0, $s0
/* EBAF0 802C7140 14400017 */  bnez      $v0, .L802C71A0
/* EBAF4 802C7144 3C02FC6C */   lui      $v0, 0xfc6c
/* EBAF8 802C7148 3C02055D */  lui       $v0, 0x55d
/* EBAFC 802C714C 34424A80 */  ori       $v0, $v0, 0x4a80
/* EBB00 802C7150 02028021 */  addu      $s0, $s0, $v0
/* EBB04 802C7154 06010002 */  bgez      $s0, .L802C7160
/* EBB08 802C7158 0200182D */   daddu    $v1, $s0, $zero
/* EBB0C 802C715C 2603001F */  addiu     $v1, $s0, 0x1f
.L802C7160:
/* EBB10 802C7160 00034143 */  sra       $t0, $v1, 5
/* EBB14 802C7164 0100182D */  daddu     $v1, $t0, $zero
/* EBB18 802C7168 00031140 */  sll       $v0, $v1, 5
/* EBB1C 802C716C 02024023 */  subu      $t0, $s0, $v0
/* EBB20 802C7170 3C04802E */  lui       $a0, 0x802e
/* EBB24 802C7174 2484ACA0 */  addiu     $a0, $a0, -0x5360
/* EBB28 802C7178 3C05802E */  lui       $a1, 0x802e
/* EBB2C 802C717C 24A59E88 */  addiu     $a1, $a1, -0x6178
/* EBB30 802C7180 0200302D */  daddu     $a2, $s0, $zero
/* EBB34 802C7184 00031880 */  sll       $v1, $v1, 2
/* EBB38 802C7188 3C02802E */  lui       $v0, 0x802e
/* EBB3C 802C718C 8C42A480 */  lw        $v0, -0x5b80($v0)
/* EBB40 802C7190 00621821 */  addu      $v1, $v1, $v0
/* EBB44 802C7194 8C620000 */  lw        $v0, ($v1)
/* EBB48 802C7198 080B1C7F */  j         .L802C71FC
/* EBB4C 802C719C 24070001 */   addiu    $a3, $zero, 1
.L802C71A0:
/* EBB50 802C71A0 34427900 */  ori       $v0, $v0, 0x7900
/* EBB54 802C71A4 0050102A */  slt       $v0, $v0, $s0
/* EBB58 802C71A8 14400019 */  bnez      $v0, .L802C7210
/* EBB5C 802C71AC 3C02FD9D */   lui      $v0, 0xfd9d
/* EBB60 802C71B0 3C02042C */  lui       $v0, 0x42c
/* EBB64 802C71B4 34421D80 */  ori       $v0, $v0, 0x1d80
/* EBB68 802C71B8 02028021 */  addu      $s0, $s0, $v0
/* EBB6C 802C71BC 06010002 */  bgez      $s0, .L802C71C8
/* EBB70 802C71C0 0200182D */   daddu    $v1, $s0, $zero
/* EBB74 802C71C4 2603001F */  addiu     $v1, $s0, 0x1f
.L802C71C8:
/* EBB78 802C71C8 00034143 */  sra       $t0, $v1, 5
/* EBB7C 802C71CC 0100182D */  daddu     $v1, $t0, $zero
/* EBB80 802C71D0 00031140 */  sll       $v0, $v1, 5
/* EBB84 802C71D4 02024023 */  subu      $t0, $s0, $v0
/* EBB88 802C71D8 3C04802E */  lui       $a0, 0x802e
/* EBB8C 802C71DC 2484ACA0 */  addiu     $a0, $a0, -0x5360
/* EBB90 802C71E0 3C05802E */  lui       $a1, 0x802e
/* EBB94 802C71E4 24A59E98 */  addiu     $a1, $a1, -0x6168
/* EBB98 802C71E8 0200302D */  daddu     $a2, $s0, $zero
/* EBB9C 802C71EC 00031880 */  sll       $v1, $v1, 2
/* EBBA0 802C71F0 00E31821 */  addu      $v1, $a3, $v1
/* EBBA4 802C71F4 24070001 */  addiu     $a3, $zero, 1
/* EBBA8 802C71F8 8C6200C4 */  lw        $v0, 0xc4($v1)
.L802C71FC:
/* EBBAC 802C71FC 01073804 */  sllv      $a3, $a3, $t0
/* EBBB0 802C7200 0C01953C */  jal       sprintf
/* EBBB4 802C7204 00473824 */   and      $a3, $v0, $a3
/* EBBB8 802C7208 080B1CE0 */  j         .L802C7380
/* EBBBC 802C720C 00000000 */   nop      
.L802C7210:
/* EBBC0 802C7210 3442A600 */  ori       $v0, $v0, 0xa600
/* EBBC4 802C7214 0050102A */  slt       $v0, $v0, $s0
/* EBBC8 802C7218 14400026 */  bnez      $v0, .L802C72B4
/* EBBCC 802C721C 3C02FECE */   lui      $v0, 0xfece
/* EBBD0 802C7220 3C0202FA */  lui       $v0, 0x2fa
/* EBBD4 802C7224 3442F080 */  ori       $v0, $v0, 0xf080
/* EBBD8 802C7228 02028021 */  addu      $s0, $s0, $v0
/* EBBDC 802C722C 3C04EFE8 */  lui       $a0, 0xefe8
/* EBBE0 802C7230 3C03802E */  lui       $v1, 0x802e
/* EBBE4 802C7234 8C63A484 */  lw        $v1, -0x5b7c($v1)
/* EBBE8 802C7238 00101080 */  sll       $v0, $s0, 2
/* EBBEC 802C723C 00431021 */  addu      $v0, $v0, $v1
/* EBBF0 802C7240 8C470000 */  lw        $a3, ($v0)
/* EBBF4 802C7244 34842080 */  ori       $a0, $a0, 0x2080
/* EBBF8 802C7248 0087202A */  slt       $a0, $a0, $a3
/* EBBFC 802C724C 14800007 */  bnez      $a0, .L802C726C
/* EBC00 802C7250 3C02F2E3 */   lui      $v0, 0xf2e3
/* EBC04 802C7254 3C04802E */  lui       $a0, 0x802e
/* EBC08 802C7258 2484ACA0 */  addiu     $a0, $a0, -0x5360
/* EBC0C 802C725C 3C05802E */  lui       $a1, 0x802e
/* EBC10 802C7260 24A59EA8 */  addiu     $a1, $a1, -0x6158
/* EBC14 802C7264 080B1CDE */  j         .L802C7378
/* EBC18 802C7268 00E0302D */   daddu    $a2, $a3, $zero
.L802C726C:
/* EBC1C 802C726C 34421100 */  ori       $v0, $v0, 0x1100
/* EBC20 802C7270 0047102A */  slt       $v0, $v0, $a3
/* EBC24 802C7274 1440000A */  bnez      $v0, .L802C72A0
/* EBC28 802C7278 00000000 */   nop      
/* EBC2C 802C727C 0C0B1248 */  jal       fixed_var_to_float
/* EBC30 802C7280 00E0202D */   daddu    $a0, $a3, $zero
/* EBC34 802C7284 46000021 */  cvt.d.s   $f0, $f0
/* EBC38 802C7288 F7A00010 */  sdc1      $f0, 0x10($sp)
/* EBC3C 802C728C 3C04802E */  lui       $a0, 0x802e
/* EBC40 802C7290 2484ACA0 */  addiu     $a0, $a0, -0x5360
/* EBC44 802C7294 3C05802E */  lui       $a1, 0x802e
/* EBC48 802C7298 080B1CCE */  j         .L802C7338
/* EBC4C 802C729C 24A59EB8 */   addiu    $a1, $a1, -0x6148
.L802C72A0:
/* EBC50 802C72A0 3C04802E */  lui       $a0, 0x802e
/* EBC54 802C72A4 2484ACA0 */  addiu     $a0, $a0, -0x5360
/* EBC58 802C72A8 3C05802E */  lui       $a1, 0x802e
/* EBC5C 802C72AC 080B1CD6 */  j         .L802C7358
/* EBC60 802C72B0 24A59ECC */   addiu    $a1, $a1, -0x6134
.L802C72B4:
/* EBC64 802C72B4 3442D300 */  ori       $v0, $v0, 0xd300
/* EBC68 802C72B8 0050102A */  slt       $v0, $v0, $s0
/* EBC6C 802C72BC 1440002A */  bnez      $v0, .L802C7368
/* EBC70 802C72C0 0200302D */   daddu    $a2, $s0, $zero
/* EBC74 802C72C4 3C0201C9 */  lui       $v0, 0x1c9
/* EBC78 802C72C8 3442C380 */  ori       $v0, $v0, 0xc380
/* EBC7C 802C72CC 02028021 */  addu      $s0, $s0, $v0
/* EBC80 802C72D0 00101080 */  sll       $v0, $s0, 2
/* EBC84 802C72D4 00E21021 */  addu      $v0, $a3, $v0
/* EBC88 802C72D8 8C470084 */  lw        $a3, 0x84($v0)
/* EBC8C 802C72DC 3C02EFE8 */  lui       $v0, 0xefe8
/* EBC90 802C72E0 34422080 */  ori       $v0, $v0, 0x2080
/* EBC94 802C72E4 0047102A */  slt       $v0, $v0, $a3
/* EBC98 802C72E8 14400007 */  bnez      $v0, .L802C7308
/* EBC9C 802C72EC 3C02F2E3 */   lui      $v0, 0xf2e3
/* EBCA0 802C72F0 3C04802E */  lui       $a0, 0x802e
/* EBCA4 802C72F4 2484ACA0 */  addiu     $a0, $a0, -0x5360
/* EBCA8 802C72F8 3C05802E */  lui       $a1, 0x802e
/* EBCAC 802C72FC 24A59EDC */  addiu     $a1, $a1, -0x6124
/* EBCB0 802C7300 080B1CDE */  j         .L802C7378
/* EBCB4 802C7304 00E0302D */   daddu    $a2, $a3, $zero
.L802C7308:
/* EBCB8 802C7308 34421100 */  ori       $v0, $v0, 0x1100
/* EBCBC 802C730C 0047102A */  slt       $v0, $v0, $a3
/* EBCC0 802C7310 1440000D */  bnez      $v0, .L802C7348
/* EBCC4 802C7314 00000000 */   nop      
/* EBCC8 802C7318 0C0B1248 */  jal       fixed_var_to_float
/* EBCCC 802C731C 00E0202D */   daddu    $a0, $a3, $zero
/* EBCD0 802C7320 46000021 */  cvt.d.s   $f0, $f0
/* EBCD4 802C7324 F7A00010 */  sdc1      $f0, 0x10($sp)
/* EBCD8 802C7328 3C04802E */  lui       $a0, 0x802e
/* EBCDC 802C732C 2484ACA0 */  addiu     $a0, $a0, -0x5360
/* EBCE0 802C7330 3C05802E */  lui       $a1, 0x802e
/* EBCE4 802C7334 24A59EEC */  addiu     $a1, $a1, -0x6114
.L802C7338:
/* EBCE8 802C7338 0C01953C */  jal       sprintf
/* EBCEC 802C733C 0200302D */   daddu    $a2, $s0, $zero
/* EBCF0 802C7340 080B1CE0 */  j         .L802C7380
/* EBCF4 802C7344 00000000 */   nop      
.L802C7348:
/* EBCF8 802C7348 3C04802E */  lui       $a0, 0x802e
/* EBCFC 802C734C 2484ACA0 */  addiu     $a0, $a0, -0x5360
/* EBD00 802C7350 3C05802E */  lui       $a1, 0x802e
/* EBD04 802C7354 24A59F00 */  addiu     $a1, $a1, -0x6100
.L802C7358:
/* EBD08 802C7358 0C01953C */  jal       sprintf
/* EBD0C 802C735C 0200302D */   daddu    $a2, $s0, $zero
/* EBD10 802C7360 080B1CE0 */  j         .L802C7380
/* EBD14 802C7364 00000000 */   nop      
.L802C7368:
/* EBD18 802C7368 3C04802E */  lui       $a0, 0x802e
/* EBD1C 802C736C 2484ACA0 */  addiu     $a0, $a0, -0x5360
/* EBD20 802C7370 3C05802E */  lui       $a1, 0x802e
/* EBD24 802C7374 24A59F10 */  addiu     $a1, $a1, -0x60f0
.L802C7378:
/* EBD28 802C7378 0C01953C */  jal       sprintf
/* EBD2C 802C737C 00000000 */   nop      
.L802C7380:
/* EBD30 802C7380 8FBF0024 */  lw        $ra, 0x24($sp)
/* EBD34 802C7384 8FB20020 */  lw        $s2, 0x20($sp)
/* EBD38 802C7388 8FB1001C */  lw        $s1, 0x1c($sp)
/* EBD3C 802C738C 8FB00018 */  lw        $s0, 0x18($sp)
/* EBD40 802C7390 24020002 */  addiu     $v0, $zero, 2
/* EBD44 802C7394 03E00008 */  jr        $ra
/* EBD48 802C7398 27BD0028 */   addiu    $sp, $sp, 0x28
