.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel jtbl_8029D1F0
.word L80250EEC_17F7CC, L80250EEC_17F7CC, L80250EEC_17F7CC, L80250EEC_17F7CC, L80251010_17F8F0, L80251010_17F8F0, L80251010_17F8F0, L80251010_17F8F0, L80250EEC_17F7CC, L80250EEC_17F7CC, L80250EEC_17F7CC, L80250EEC_17F7CC, L80250EEC_17F7CC, L80250EEC_17F7CC, L80250EEC_17F7CC, L80250EEC_17F7CC, L80250EEC_17F7CC, L80250EEC_17F7CC, L80250EEC_17F7CC, L80250EEC_17F7CC, L80250EEC_17F7CC, L80250EEC_17F7CC, L80250EEC_17F7CC, L80250EEC_17F7CC, L80250EEC_17F7CC, L80250EEC_17F7CC, L80250EEC_17F7CC, L80250EEC_17F7CC, L80250EEC_17F7CC, L80251010_17F8F0, L80251010_17F8F0, L80251010_17F8F0, L80251010_17F8F0, L80251010_17F8F0, L80251010_17F8F0, L80250EEC_17F7CC, L80250EEC_17F7CC, L80250EEC_17F7CC, L80250EEC_17F7CC, L80250EEC_17F7CC, L80250EEC_17F7CC, L80250EEC_17F7CC, L80250EEC_17F7CC, L80250EEC_17F7CC, L80250EEC_17F7CC, L80250EEC_17F7CC, L80251190_17FA70, L80251190_17FA70, L80251190_17FA70, L80251190_17FA70, L80251190_17FA70, L80251190_17FA70, L80251190_17FA70, L80251190_17FA70, L80251190_17FA70, L80251190_17FA70, L80251190_17FA70, L80251190_17FA70, L80251190_17FA70, L80251190_17FA70, L80251190_17FA70, L80251190_17FA70, L80251190_17FA70, L80251190_17FA70, L80251190_17FA70, L80251190_17FA70, L80251190_17FA70, L80250EEC_17F7CC, L80250EEC_17F7CC, L80250EEC_17F7CC, L80250EEC_17F7CC, L80250EEC_17F7CC, L80250EEC_17F7CC, L80250F90_17F870, L80250F90_17F870, L80250F90_17F870, L80250F90_17F870, L80250F90_17F870, L80250F90_17F870, L80250F90_17F870, L80250EEC_17F7CC, L802510C8_17F9A8, L80250EEC_17F7CC, L80250EEC_17F7CC, L80250EEC_17F7CC, 0, 0, 0

.section .text

glabel btl_show_message_popup
/* 17F784 80250EA4 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* 17F788 80250EA8 AFB30034 */  sw        $s3, 0x34($sp)
/* 17F78C 80250EAC 0080982D */  daddu     $s3, $a0, $zero
/* 17F790 80250EB0 AFBF003C */  sw        $ra, 0x3c($sp)
/* 17F794 80250EB4 AFB40038 */  sw        $s4, 0x38($sp)
/* 17F798 80250EB8 AFB20030 */  sw        $s2, 0x30($sp)
/* 17F79C 80250EBC AFB1002C */  sw        $s1, 0x2c($sp)
/* 17F7A0 80250EC0 AFB00028 */  sw        $s0, 0x28($sp)
/* 17F7A4 80250EC4 86630012 */  lh        $v1, 0x12($s3)
/* 17F7A8 80250EC8 2C620055 */  sltiu     $v0, $v1, 0x55
/* 17F7AC 80250ECC 104000F1 */  beqz      $v0, .L80251294
/* 17F7B0 80250ED0 24140050 */   addiu    $s4, $zero, 0x50
/* 17F7B4 80250ED4 00031080 */  sll       $v0, $v1, 2
/* 17F7B8 80250ED8 3C01802A */  lui       $at, %hi(jtbl_8029D1F0)
/* 17F7BC 80250EDC 00220821 */  addu      $at, $at, $v0
/* 17F7C0 80250EE0 8C22D1F0 */  lw        $v0, %lo(jtbl_8029D1F0)($at)
/* 17F7C4 80250EE4 00400008 */  jr        $v0
/* 17F7C8 80250EE8 00000000 */   nop
glabel L80250EEC_17F7CC
/* 17F7CC 80250EEC 82620017 */  lb        $v0, 0x17($s3)
/* 17F7D0 80250EF0 104000E8 */  beqz      $v0, .L80251294
/* 17F7D4 80250EF4 0000282D */   daddu    $a1, $zero, $zero
/* 17F7D8 80250EF8 86620012 */  lh        $v0, 0x12($s3)
/* 17F7DC 80250EFC A2600017 */  sb        $zero, 0x17($s3)
/* 17F7E0 80250F00 00021080 */  sll       $v0, $v0, 2
/* 17F7E4 80250F04 3C108028 */  lui       $s0, %hi(bMessages)
/* 17F7E8 80250F08 02028021 */  addu      $s0, $s0, $v0
/* 17F7EC 80250F0C 8E103770 */  lw        $s0, %lo(bMessages)($s0)
/* 17F7F0 80250F10 0C04991D */  jal       get_string_width
/* 17F7F4 80250F14 0200202D */   daddu    $a0, $s0, $zero
/* 17F7F8 80250F18 2447001E */  addiu     $a3, $v0, 0x1e
/* 17F7FC 80250F1C 000717C2 */  srl       $v0, $a3, 0x1f
/* 17F800 80250F20 00E21021 */  addu      $v0, $a3, $v0
/* 17F804 80250F24 00021043 */  sra       $v0, $v0, 1
/* 17F808 80250F28 240300A0 */  addiu     $v1, $zero, 0xa0
/* 17F80C 80250F2C 00628823 */  subu      $s1, $v1, $v0
/* 17F810 80250F30 00E0902D */  daddu     $s2, $a3, $zero
/* 17F814 80250F34 0C04992C */  jal       get_string_lines
/* 17F818 80250F38 0200202D */   daddu    $a0, $s0, $zero
/* 17F81C 80250F3C 2442FFFF */  addiu     $v0, $v0, -1
/* 17F820 80250F40 24040009 */  addiu     $a0, $zero, 9
/* 17F824 80250F44 0220282D */  daddu     $a1, $s1, $zero
/* 17F828 80250F48 0280302D */  daddu     $a2, $s4, $zero
/* 17F82C 80250F4C 00021040 */  sll       $v0, $v0, 1
/* 17F830 80250F50 0240382D */  daddu     $a3, $s2, $zero
/* 17F834 80250F54 3C088028 */  lui       $t0, %hi(D_802835D0)
/* 17F838 80250F58 01024021 */  addu      $t0, $t0, $v0
/* 17F83C 80250F5C 850835D0 */  lh        $t0, %lo(D_802835D0)($t0)
/* 17F840 80250F60 3C028025 */  lui       $v0, %hi(func_80250818)
/* 17F844 80250F64 24420818 */  addiu     $v0, $v0, %lo(func_80250818)
/* 17F848 80250F68 AFA20018 */  sw        $v0, 0x18($sp)
/* 17F84C 80250F6C 2402FFFF */  addiu     $v0, $zero, -1
/* 17F850 80250F70 AFA00014 */  sw        $zero, 0x14($sp)
/* 17F854 80250F74 AFB3001C */  sw        $s3, 0x1c($sp)
/* 17F858 80250F78 AFA20020 */  sw        $v0, 0x20($sp)
/* 17F85C 80250F7C 0C051F32 */  jal       set_window_properties
/* 17F860 80250F80 AFA80010 */   sw       $t0, 0x10($sp)
/* 17F864 80250F84 24040009 */  addiu     $a0, $zero, 9
/* 17F868 80250F88 080944A3 */  j         .L8025128C
/* 17F86C 80250F8C 24050001 */   addiu    $a1, $zero, 1
glabel L80250F90_17F870
/* 17F870 80250F90 82620017 */  lb        $v0, 0x17($s3)
/* 17F874 80250F94 104000BF */  beqz      $v0, .L80251294
/* 17F878 80250F98 00000000 */   nop
/* 17F87C 80250F9C 86620012 */  lh        $v0, 0x12($s3)
/* 17F880 80250FA0 A2600017 */  sb        $zero, 0x17($s3)
/* 17F884 80250FA4 00021080 */  sll       $v0, $v0, 2
/* 17F888 80250FA8 3C048028 */  lui       $a0, %hi(bMessages)
/* 17F88C 80250FAC 00822021 */  addu      $a0, $a0, $v0
/* 17F890 80250FB0 8C843770 */  lw        $a0, %lo(bMessages)($a0)
/* 17F894 80250FB4 0C04991D */  jal       get_string_width
/* 17F898 80250FB8 0000282D */   daddu    $a1, $zero, $zero
/* 17F89C 80250FBC 24470037 */  addiu     $a3, $v0, 0x37
/* 17F8A0 80250FC0 24080028 */  addiu     $t0, $zero, 0x28
/* 17F8A4 80250FC4 24040009 */  addiu     $a0, $zero, 9
/* 17F8A8 80250FC8 00072FC2 */  srl       $a1, $a3, 0x1f
/* 17F8AC 80250FCC 00E52821 */  addu      $a1, $a3, $a1
/* 17F8B0 80250FD0 00052843 */  sra       $a1, $a1, 1
/* 17F8B4 80250FD4 240200A0 */  addiu     $v0, $zero, 0xa0
/* 17F8B8 80250FD8 00452823 */  subu      $a1, $v0, $a1
/* 17F8BC 80250FDC 0280302D */  daddu     $a2, $s4, $zero
/* 17F8C0 80250FE0 3C028025 */  lui       $v0, %hi(func_80250818)
/* 17F8C4 80250FE4 24420818 */  addiu     $v0, $v0, %lo(func_80250818)
/* 17F8C8 80250FE8 AFA20018 */  sw        $v0, 0x18($sp)
/* 17F8CC 80250FEC 2402FFFF */  addiu     $v0, $zero, -1
/* 17F8D0 80250FF0 AFA80010 */  sw        $t0, 0x10($sp)
/* 17F8D4 80250FF4 AFA00014 */  sw        $zero, 0x14($sp)
/* 17F8D8 80250FF8 AFB3001C */  sw        $s3, 0x1c($sp)
/* 17F8DC 80250FFC 0C051F32 */  jal       set_window_properties
/* 17F8E0 80251000 AFA20020 */   sw       $v0, 0x20($sp)
/* 17F8E4 80251004 24040009 */  addiu     $a0, $zero, 9
/* 17F8E8 80251008 080944A3 */  j         .L8025128C
/* 17F8EC 8025100C 24050001 */   addiu    $a1, $zero, 1
glabel L80251010_17F8F0
/* 17F8F0 80251010 82620017 */  lb        $v0, 0x17($s3)
/* 17F8F4 80251014 1040009F */  beqz      $v0, .L80251294
/* 17F8F8 80251018 00000000 */   nop
/* 17F8FC 8025101C 86620012 */  lh        $v0, 0x12($s3)
/* 17F900 80251020 A2600017 */  sb        $zero, 0x17($s3)
/* 17F904 80251024 3C04802A */  lui       $a0, %hi(D_8029F640)
/* 17F908 80251028 8484F640 */  lh        $a0, %lo(D_8029F640)($a0)
/* 17F90C 8025102C 00021080 */  sll       $v0, $v0, 2
/* 17F910 80251030 3C108028 */  lui       $s0, %hi(bMessages)
/* 17F914 80251034 02028021 */  addu      $s0, $s0, $v0
/* 17F918 80251038 8E103770 */  lw        $s0, %lo(bMessages)($s0)
/* 17F91C 8025103C 0C0496FA */  jal       set_message_value
/* 17F920 80251040 0000282D */   daddu    $a1, $zero, $zero
/* 17F924 80251044 0000282D */  daddu     $a1, $zero, $zero
/* 17F928 80251048 0C04991D */  jal       get_string_width
/* 17F92C 8025104C 0200202D */   daddu    $a0, $s0, $zero
/* 17F930 80251050 2447001F */  addiu     $a3, $v0, 0x1f
/* 17F934 80251054 000717C2 */  srl       $v0, $a3, 0x1f
/* 17F938 80251058 00E21021 */  addu      $v0, $a3, $v0
/* 17F93C 8025105C 00021043 */  sra       $v0, $v0, 1
/* 17F940 80251060 240300A0 */  addiu     $v1, $zero, 0xa0
/* 17F944 80251064 00628823 */  subu      $s1, $v1, $v0
/* 17F948 80251068 00E0902D */  daddu     $s2, $a3, $zero
/* 17F94C 8025106C 0C04992C */  jal       get_string_lines
/* 17F950 80251070 0200202D */   daddu    $a0, $s0, $zero
/* 17F954 80251074 2442FFFF */  addiu     $v0, $v0, -1
/* 17F958 80251078 24040009 */  addiu     $a0, $zero, 9
/* 17F95C 8025107C 0220282D */  daddu     $a1, $s1, $zero
/* 17F960 80251080 0280302D */  daddu     $a2, $s4, $zero
/* 17F964 80251084 00021040 */  sll       $v0, $v0, 1
/* 17F968 80251088 0240382D */  daddu     $a3, $s2, $zero
/* 17F96C 8025108C 3C088028 */  lui       $t0, %hi(D_802835D0)
/* 17F970 80251090 01024021 */  addu      $t0, $t0, $v0
/* 17F974 80251094 850835D0 */  lh        $t0, %lo(D_802835D0)($t0)
/* 17F978 80251098 3C028025 */  lui       $v0, %hi(func_80250818)
/* 17F97C 8025109C 24420818 */  addiu     $v0, $v0, %lo(func_80250818)
/* 17F980 802510A0 AFA20018 */  sw        $v0, 0x18($sp)
/* 17F984 802510A4 2402FFFF */  addiu     $v0, $zero, -1
/* 17F988 802510A8 AFA00014 */  sw        $zero, 0x14($sp)
/* 17F98C 802510AC AFB3001C */  sw        $s3, 0x1c($sp)
/* 17F990 802510B0 AFA20020 */  sw        $v0, 0x20($sp)
/* 17F994 802510B4 0C051F32 */  jal       set_window_properties
/* 17F998 802510B8 AFA80010 */   sw       $t0, 0x10($sp)
/* 17F99C 802510BC 24040009 */  addiu     $a0, $zero, 9
/* 17F9A0 802510C0 080944A3 */  j         .L8025128C
/* 17F9A4 802510C4 24050001 */   addiu    $a1, $zero, 1
glabel L802510C8_17F9A8
/* 17F9A8 802510C8 82620017 */  lb        $v0, 0x17($s3)
/* 17F9AC 802510CC 10400071 */  beqz      $v0, .L80251294
/* 17F9B0 802510D0 00000000 */   nop
/* 17F9B4 802510D4 A2600017 */  sb        $zero, 0x17($s3)
/* 17F9B8 802510D8 3C03802A */  lui       $v1, %hi(D_8029F640)
/* 17F9BC 802510DC 8463F640 */  lh        $v1, %lo(D_8029F640)($v1)
/* 17F9C0 802510E0 86620012 */  lh        $v0, 0x12($s3)
/* 17F9C4 802510E4 00031880 */  sll       $v1, $v1, 2
/* 17F9C8 802510E8 00021080 */  sll       $v0, $v0, 2
/* 17F9CC 802510EC 3C048028 */  lui       $a0, %hi(bActorMessages)
/* 17F9D0 802510F0 00832021 */  addu      $a0, $a0, $v1
/* 17F9D4 802510F4 8C8438C4 */  lw        $a0, %lo(bActorMessages)($a0)
/* 17F9D8 802510F8 3C108028 */  lui       $s0, %hi(bMessages)
/* 17F9DC 802510FC 02028021 */  addu      $s0, $s0, $v0
/* 17F9E0 80251100 8E103770 */  lw        $s0, %lo(bMessages)($s0)
/* 17F9E4 80251104 0C0496CF */  jal       set_message_string
/* 17F9E8 80251108 0000282D */   daddu    $a1, $zero, $zero
/* 17F9EC 8025110C 0200202D */  daddu     $a0, $s0, $zero
/* 17F9F0 80251110 0C04991D */  jal       get_string_width
/* 17F9F4 80251114 0000282D */   daddu    $a1, $zero, $zero
/* 17F9F8 80251118 2447001F */  addiu     $a3, $v0, 0x1f
/* 17F9FC 8025111C 000717C2 */  srl       $v0, $a3, 0x1f
/* 17FA00 80251120 00E21021 */  addu      $v0, $a3, $v0
/* 17FA04 80251124 00021043 */  sra       $v0, $v0, 1
/* 17FA08 80251128 240300A0 */  addiu     $v1, $zero, 0xa0
/* 17FA0C 8025112C 00628823 */  subu      $s1, $v1, $v0
/* 17FA10 80251130 00E0902D */  daddu     $s2, $a3, $zero
/* 17FA14 80251134 0C04992C */  jal       get_string_lines
/* 17FA18 80251138 0200202D */   daddu    $a0, $s0, $zero
/* 17FA1C 8025113C 2442FFFF */  addiu     $v0, $v0, -1
/* 17FA20 80251140 24040009 */  addiu     $a0, $zero, 9
/* 17FA24 80251144 0220282D */  daddu     $a1, $s1, $zero
/* 17FA28 80251148 0280302D */  daddu     $a2, $s4, $zero
/* 17FA2C 8025114C 00021040 */  sll       $v0, $v0, 1
/* 17FA30 80251150 0240382D */  daddu     $a3, $s2, $zero
/* 17FA34 80251154 3C088028 */  lui       $t0, %hi(D_802835D0)
/* 17FA38 80251158 01024021 */  addu      $t0, $t0, $v0
/* 17FA3C 8025115C 850835D0 */  lh        $t0, %lo(D_802835D0)($t0)
/* 17FA40 80251160 3C028025 */  lui       $v0, %hi(func_80250818)
/* 17FA44 80251164 24420818 */  addiu     $v0, $v0, %lo(func_80250818)
/* 17FA48 80251168 AFA20018 */  sw        $v0, 0x18($sp)
/* 17FA4C 8025116C 2402FFFF */  addiu     $v0, $zero, -1
/* 17FA50 80251170 AFA00014 */  sw        $zero, 0x14($sp)
/* 17FA54 80251174 AFB3001C */  sw        $s3, 0x1c($sp)
/* 17FA58 80251178 AFA20020 */  sw        $v0, 0x20($sp)
/* 17FA5C 8025117C 0C051F32 */  jal       set_window_properties
/* 17FA60 80251180 AFA80010 */   sw       $t0, 0x10($sp)
/* 17FA64 80251184 24040009 */  addiu     $a0, $zero, 9
/* 17FA68 80251188 080944A3 */  j         .L8025128C
/* 17FA6C 8025118C 24050001 */   addiu    $a1, $zero, 1
glabel L80251190_17FA70
/* 17FA70 80251190 82620017 */  lb        $v0, 0x17($s3)
/* 17FA74 80251194 1040003F */  beqz      $v0, .L80251294
/* 17FA78 80251198 0000282D */   daddu    $a1, $zero, $zero
/* 17FA7C 8025119C 86620012 */  lh        $v0, 0x12($s3)
/* 17FA80 802511A0 A2600017 */  sb        $zero, 0x17($s3)
/* 17FA84 802511A4 00021080 */  sll       $v0, $v0, 2
/* 17FA88 802511A8 3C108028 */  lui       $s0, %hi(bMessages)
/* 17FA8C 802511AC 02028021 */  addu      $s0, $s0, $v0
/* 17FA90 802511B0 8E103770 */  lw        $s0, %lo(bMessages)($s0)
/* 17FA94 802511B4 241400C0 */  addiu     $s4, $zero, 0xc0
/* 17FA98 802511B8 0C04991D */  jal       get_string_width
/* 17FA9C 802511BC 0200202D */   daddu    $a0, $s0, $zero
/* 17FAA0 802511C0 2447001F */  addiu     $a3, $v0, 0x1f
/* 17FAA4 802511C4 000717C2 */  srl       $v0, $a3, 0x1f
/* 17FAA8 802511C8 00E21021 */  addu      $v0, $a3, $v0
/* 17FAAC 802511CC 00021043 */  sra       $v0, $v0, 1
/* 17FAB0 802511D0 240300A0 */  addiu     $v1, $zero, 0xa0
/* 17FAB4 802511D4 00628823 */  subu      $s1, $v1, $v0
/* 17FAB8 802511D8 00E0902D */  daddu     $s2, $a3, $zero
/* 17FABC 802511DC 0C04992C */  jal       get_string_lines
/* 17FAC0 802511E0 0200202D */   daddu    $a0, $s0, $zero
/* 17FAC4 802511E4 2442FFFF */  addiu     $v0, $v0, -1
/* 17FAC8 802511E8 00021840 */  sll       $v1, $v0, 1
/* 17FACC 802511EC 2410003B */  addiu     $s0, $zero, 0x3b
/* 17FAD0 802511F0 86620012 */  lh        $v0, 0x12($s3)
/* 17FAD4 802511F4 3C088028 */  lui       $t0, %hi(D_802835D0)
/* 17FAD8 802511F8 01034021 */  addu      $t0, $t0, $v1
/* 17FADC 802511FC 850835D0 */  lh        $t0, %lo(D_802835D0)($t0)
/* 17FAE0 80251200 14500005 */  bne       $v0, $s0, .L80251218
/* 17FAE4 80251204 24040009 */   addiu    $a0, $zero, 9
/* 17FAE8 80251208 24140078 */  addiu     $s4, $zero, 0x78
/* 17FAEC 8025120C 24020001 */  addiu     $v0, $zero, 1
/* 17FAF0 80251210 3C01802A */  lui       $at, %hi(D_8029F64C)
/* 17FAF4 80251214 A422F64C */  sh        $v0, %lo(D_8029F64C)($at)
.L80251218:
/* 17FAF8 80251218 0220282D */  daddu     $a1, $s1, $zero
/* 17FAFC 8025121C 0240382D */  daddu     $a3, $s2, $zero
/* 17FB00 80251220 3C018028 */  lui       $at, %hi(D_802835D8)
/* 17FB04 80251224 00230821 */  addu      $at, $at, $v1
/* 17FB08 80251228 942335D8 */  lhu       $v1, %lo(D_802835D8)($at)
/* 17FB0C 8025122C 3C028025 */  lui       $v0, %hi(func_80250818)
/* 17FB10 80251230 24420818 */  addiu     $v0, $v0, %lo(func_80250818)
/* 17FB14 80251234 AFA20018 */  sw        $v0, 0x18($sp)
/* 17FB18 80251238 2402FFFF */  addiu     $v0, $zero, -1
/* 17FB1C 8025123C AFA20020 */  sw        $v0, 0x20($sp)
/* 17FB20 80251240 00141400 */  sll       $v0, $s4, 0x10
/* 17FB24 80251244 00021403 */  sra       $v0, $v0, 0x10
/* 17FB28 80251248 3C01802A */  lui       $at, %hi(D_8029F64E)
/* 17FB2C 8025124C A434F64E */  sh        $s4, %lo(D_8029F64E)($at)
/* 17FB30 80251250 AFA80010 */  sw        $t0, 0x10($sp)
/* 17FB34 80251254 AFA00014 */  sw        $zero, 0x14($sp)
/* 17FB38 80251258 AFB3001C */  sw        $s3, 0x1c($sp)
/* 17FB3C 8025125C 00033400 */  sll       $a2, $v1, 0x10
/* 17FB40 80251260 00063403 */  sra       $a2, $a2, 0x10
/* 17FB44 80251264 3C01802A */  lui       $at, %hi(D_8029F650)
/* 17FB48 80251268 A423F650 */  sh        $v1, %lo(D_8029F650)($at)
/* 17FB4C 8025126C 0C051F32 */  jal       set_window_properties
/* 17FB50 80251270 00463021 */   addu     $a2, $v0, $a2
/* 17FB54 80251274 86620012 */  lh        $v0, 0x12($s3)
/* 17FB58 80251278 14500003 */  bne       $v0, $s0, .L80251288
/* 17FB5C 8025127C 24040009 */   addiu    $a0, $zero, 9
/* 17FB60 80251280 080944A3 */  j         .L8025128C
/* 17FB64 80251284 24050001 */   addiu    $a1, $zero, 1
.L80251288:
/* 17FB68 80251288 24050008 */  addiu     $a1, $zero, 8
.L8025128C:
/* 17FB6C 8025128C 0C051F9F */  jal       set_window_update
/* 17FB70 80251290 00000000 */   nop
.L80251294:
/* 17FB74 80251294 8FBF003C */  lw        $ra, 0x3c($sp)
/* 17FB78 80251298 8FB40038 */  lw        $s4, 0x38($sp)
/* 17FB7C 8025129C 8FB30034 */  lw        $s3, 0x34($sp)
/* 17FB80 802512A0 8FB20030 */  lw        $s2, 0x30($sp)
/* 17FB84 802512A4 8FB1002C */  lw        $s1, 0x2c($sp)
/* 17FB88 802512A8 8FB00028 */  lw        $s0, 0x28($sp)
/* 17FB8C 802512AC 03E00008 */  jr        $ra
/* 17FB90 802512B0 27BD0040 */   addiu    $sp, $sp, 0x40
