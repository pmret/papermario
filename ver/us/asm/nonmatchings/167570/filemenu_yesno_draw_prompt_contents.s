.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel jtbl_8024C000
.word L80246E6C_1676CC, L80246F9C_1677FC, L80246FDC_16783C, L80246F00_167760, L802470D4_167934, 0

.section .text

glabel filemenu_yesno_draw_prompt_contents
/* 167684 80246E24 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 167688 80246E28 AFB3002C */  sw        $s3, 0x2c($sp)
/* 16768C 80246E2C 00A0982D */  daddu     $s3, $a1, $zero
/* 167690 80246E30 AFBF0034 */  sw        $ra, 0x34($sp)
/* 167694 80246E34 AFB40030 */  sw        $s4, 0x30($sp)
/* 167698 80246E38 AFB20028 */  sw        $s2, 0x28($sp)
/* 16769C 80246E3C AFB10024 */  sw        $s1, 0x24($sp)
/* 1676A0 80246E40 AFB00020 */  sw        $s0, 0x20($sp)
/* 1676A4 80246E44 80830004 */  lb        $v1, 4($a0)
/* 1676A8 80246E48 2C620005 */  sltiu     $v0, $v1, 5
/* 1676AC 80246E4C 104000CA */  beqz      $v0, .L80247178
/* 1676B0 80246E50 00C0A02D */   daddu    $s4, $a2, $zero
/* 1676B4 80246E54 00031080 */  sll       $v0, $v1, 2
/* 1676B8 80246E58 3C018025 */  lui       $at, %hi(jtbl_8024C000)
/* 1676BC 80246E5C 00220821 */  addu      $at, $at, $v0
/* 1676C0 80246E60 8C22C000 */  lw        $v0, %lo(jtbl_8024C000)($at)
/* 1676C4 80246E64 00400008 */  jr        $v0
/* 1676C8 80246E68 00000000 */   nop
glabel L80246E6C_1676CC
/* 1676CC 80246E6C 0C0926A9 */  jal       filemenu_get_menu_message
/* 1676D0 80246E70 24040010 */   addiu    $a0, $zero, 0x10
/* 1676D4 80246E74 0040202D */  daddu     $a0, $v0, $zero
/* 1676D8 80246E78 2665000A */  addiu     $a1, $s3, 0xa
/* 1676DC 80246E7C 26900004 */  addiu     $s0, $s4, 4
/* 1676E0 80246E80 0200302D */  daddu     $a2, $s0, $zero
/* 1676E4 80246E84 240700FF */  addiu     $a3, $zero, 0xff
/* 1676E8 80246E88 AFA00010 */  sw        $zero, 0x10($sp)
/* 1676EC 80246E8C 0C09265F */  jal       filemenu_draw_message
/* 1676F0 80246E90 AFA00014 */   sw       $zero, 0x14($sp)
/* 1676F4 80246E94 0C0926A9 */  jal       filemenu_get_menu_message
/* 1676F8 80246E98 24040016 */   addiu    $a0, $zero, 0x16
/* 1676FC 80246E9C 0040202D */  daddu     $a0, $v0, $zero
/* 167700 80246EA0 2665003C */  addiu     $a1, $s3, 0x3c
/* 167704 80246EA4 0200302D */  daddu     $a2, $s0, $zero
/* 167708 80246EA8 240700FF */  addiu     $a3, $zero, 0xff
/* 16770C 80246EAC AFA00010 */  sw        $zero, 0x10($sp)
/* 167710 80246EB0 0C09265F */  jal       filemenu_draw_message
/* 167714 80246EB4 AFA00014 */   sw       $zero, 0x14($sp)
/* 167718 80246EB8 26650062 */  addiu     $a1, $s3, 0x62
/* 16771C 80246EBC 26860006 */  addiu     $a2, $s4, 6
/* 167720 80246EC0 3C028025 */  lui       $v0, %hi(D_80249B84)
/* 167724 80246EC4 8C429B84 */  lw        $v0, %lo(D_80249B84)($v0)
/* 167728 80246EC8 0000382D */  daddu     $a3, $zero, $zero
/* 16772C 80246ECC 90440003 */  lbu       $a0, 3($v0)
/* 167730 80246ED0 240200FF */  addiu     $v0, $zero, 0xff
/* 167734 80246ED4 AFA20014 */  sw        $v0, 0x14($sp)
/* 167738 80246ED8 24020003 */  addiu     $v0, $zero, 3
/* 16773C 80246EDC AFA00010 */  sw        $zero, 0x10($sp)
/* 167740 80246EE0 AFA20018 */  sw        $v0, 0x18($sp)
/* 167744 80246EE4 0C049DA7 */  jal       draw_number
/* 167748 80246EE8 24840001 */   addiu    $a0, $a0, 1
/* 16774C 80246EEC 0C0926A9 */  jal       filemenu_get_menu_message
/* 167750 80246EF0 24040021 */   addiu    $a0, $zero, 0x21
/* 167754 80246EF4 0040202D */  daddu     $a0, $v0, $zero
/* 167758 80246EF8 08091C59 */  j         .L80247164
/* 16775C 80246EFC 26650063 */   addiu    $a1, $s3, 0x63
glabel L80246F00_167760
/* 167760 80246F00 0C0926A9 */  jal       filemenu_get_menu_message
/* 167764 80246F04 24040016 */   addiu    $a0, $zero, 0x16
/* 167768 80246F08 0040202D */  daddu     $a0, $v0, $zero
/* 16776C 80246F0C 2671000A */  addiu     $s1, $s3, 0xa
/* 167770 80246F10 0220282D */  daddu     $a1, $s1, $zero
/* 167774 80246F14 26900004 */  addiu     $s0, $s4, 4
/* 167778 80246F18 0200302D */  daddu     $a2, $s0, $zero
/* 16777C 80246F1C 240700FF */  addiu     $a3, $zero, 0xff
/* 167780 80246F20 AFA00010 */  sw        $zero, 0x10($sp)
/* 167784 80246F24 0C09265F */  jal       filemenu_draw_message
/* 167788 80246F28 AFA00014 */   sw       $zero, 0x14($sp)
/* 16778C 80246F2C 26650030 */  addiu     $a1, $s3, 0x30
/* 167790 80246F30 26860006 */  addiu     $a2, $s4, 6
/* 167794 80246F34 3C028025 */  lui       $v0, %hi(D_80249B84)
/* 167798 80246F38 8C429B84 */  lw        $v0, %lo(D_80249B84)($v0)
/* 16779C 80246F3C 0000382D */  daddu     $a3, $zero, $zero
/* 1677A0 80246F40 90440003 */  lbu       $a0, 3($v0)
/* 1677A4 80246F44 240200FF */  addiu     $v0, $zero, 0xff
/* 1677A8 80246F48 AFA20014 */  sw        $v0, 0x14($sp)
/* 1677AC 80246F4C 24020003 */  addiu     $v0, $zero, 3
/* 1677B0 80246F50 AFA00010 */  sw        $zero, 0x10($sp)
/* 1677B4 80246F54 AFA20018 */  sw        $v0, 0x18($sp)
/* 1677B8 80246F58 0C049DA7 */  jal       draw_number
/* 1677BC 80246F5C 24840001 */   addiu    $a0, $a0, 1
/* 1677C0 80246F60 0C0926A9 */  jal       filemenu_get_menu_message
/* 1677C4 80246F64 24040017 */   addiu    $a0, $zero, 0x17
/* 1677C8 80246F68 0040202D */  daddu     $a0, $v0, $zero
/* 1677CC 80246F6C 26650031 */  addiu     $a1, $s3, 0x31
/* 1677D0 80246F70 0200302D */  daddu     $a2, $s0, $zero
/* 1677D4 80246F74 240700FF */  addiu     $a3, $zero, 0xff
/* 1677D8 80246F78 AFA00010 */  sw        $zero, 0x10($sp)
/* 1677DC 80246F7C 0C09265F */  jal       filemenu_draw_message
/* 1677E0 80246F80 AFA00014 */   sw       $zero, 0x14($sp)
/* 1677E4 80246F84 0C0926A9 */  jal       filemenu_get_menu_message
/* 1677E8 80246F88 24040018 */   addiu    $a0, $zero, 0x18
/* 1677EC 80246F8C 0040202D */  daddu     $a0, $v0, $zero
/* 1677F0 80246F90 0220282D */  daddu     $a1, $s1, $zero
/* 1677F4 80246F94 08091C5A */  j         .L80247168
/* 1677F8 80246F98 26860012 */   addiu    $a2, $s4, 0x12
glabel L80246F9C_1677FC
/* 1677FC 80246F9C 0C0926A9 */  jal       filemenu_get_menu_message
/* 167800 80246FA0 24040011 */   addiu    $a0, $zero, 0x11
/* 167804 80246FA4 0040202D */  daddu     $a0, $v0, $zero
/* 167808 80246FA8 2670000A */  addiu     $s0, $s3, 0xa
/* 16780C 80246FAC 0200282D */  daddu     $a1, $s0, $zero
/* 167810 80246FB0 26860004 */  addiu     $a2, $s4, 4
/* 167814 80246FB4 240700FF */  addiu     $a3, $zero, 0xff
/* 167818 80246FB8 AFA00010 */  sw        $zero, 0x10($sp)
/* 16781C 80246FBC 0C09265F */  jal       filemenu_draw_message
/* 167820 80246FC0 AFA00014 */   sw       $zero, 0x14($sp)
/* 167824 80246FC4 0C0926A9 */  jal       filemenu_get_menu_message
/* 167828 80246FC8 24040012 */   addiu    $a0, $zero, 0x12
/* 16782C 80246FCC 0040202D */  daddu     $a0, $v0, $zero
/* 167830 80246FD0 0200282D */  daddu     $a1, $s0, $zero
/* 167834 80246FD4 08091C5A */  j         .L80247168
/* 167838 80246FD8 26860012 */   addiu    $a2, $s4, 0x12
glabel L80246FDC_16783C
/* 16783C 80246FDC 0C0926A9 */  jal       filemenu_get_menu_message
/* 167840 80246FE0 24040013 */   addiu    $a0, $zero, 0x13
/* 167844 80246FE4 0040202D */  daddu     $a0, $v0, $zero
/* 167848 80246FE8 2665000A */  addiu     $a1, $s3, 0xa
/* 16784C 80246FEC 26860006 */  addiu     $a2, $s4, 6
/* 167850 80246FF0 240700FF */  addiu     $a3, $zero, 0xff
/* 167854 80246FF4 AFA00010 */  sw        $zero, 0x10($sp)
/* 167858 80246FF8 0C09265F */  jal       filemenu_draw_message
/* 16785C 80246FFC AFA00014 */   sw       $zero, 0x14($sp)
/* 167860 80247000 24110007 */  addiu     $s1, $zero, 7
/* 167864 80247004 3C048025 */  lui       $a0, %hi(D_8024C110)
/* 167868 80247008 2484C110 */  addiu     $a0, $a0, %lo(D_8024C110)
/* 16786C 8024700C 240300F7 */  addiu     $v1, $zero, 0xf7
/* 167870 80247010 02241021 */  addu      $v0, $s1, $a0
.L80247014:
/* 167874 80247014 90420000 */  lbu       $v0, ($v0)
/* 167878 80247018 14430005 */  bne       $v0, $v1, .L80247030
/* 16787C 8024701C 00111040 */   sll      $v0, $s1, 1
/* 167880 80247020 2631FFFF */  addiu     $s1, $s1, -1
/* 167884 80247024 0621FFFB */  bgez      $s1, .L80247014
/* 167888 80247028 02241021 */   addu     $v0, $s1, $a0
/* 16788C 8024702C 00111040 */  sll       $v0, $s1, 1
.L80247030:
/* 167890 80247030 00511021 */  addu      $v0, $v0, $s1
/* 167894 80247034 00021080 */  sll       $v0, $v0, 2
/* 167898 80247038 00511023 */  subu      $v0, $v0, $s1
/* 16789C 8024703C 24100093 */  addiu     $s0, $zero, 0x93
/* 1678A0 80247040 02028023 */  subu      $s0, $s0, $v0
/* 1678A4 80247044 001017C2 */  srl       $v0, $s0, 0x1f
/* 1678A8 80247048 02028021 */  addu      $s0, $s0, $v0
/* 1678AC 8024704C 00108043 */  sra       $s0, $s0, 1
/* 1678B0 80247050 26310001 */  addiu     $s1, $s1, 1
/* 1678B4 80247054 0220282D */  daddu     $a1, $s1, $zero
/* 1678B8 80247058 02703021 */  addu      $a2, $s3, $s0
/* 1678BC 8024705C 26920016 */  addiu     $s2, $s4, 0x16
/* 1678C0 80247060 0240382D */  daddu     $a3, $s2, $zero
/* 1678C4 80247064 240200FF */  addiu     $v0, $zero, 0xff
/* 1678C8 80247068 AFA20010 */  sw        $v0, 0x10($sp)
/* 1678CC 8024706C 24020008 */  addiu     $v0, $zero, 8
/* 1678D0 80247070 AFA20018 */  sw        $v0, 0x18($sp)
/* 1678D4 80247074 2402000B */  addiu     $v0, $zero, 0xb
/* 1678D8 80247078 AFA00014 */  sw        $zero, 0x14($sp)
/* 1678DC 8024707C 0C0926AE */  jal       filemenu_draw_file_name
/* 1678E0 80247080 AFA2001C */   sw       $v0, 0x1c($sp)
/* 1678E4 80247084 00111040 */  sll       $v0, $s1, 1
/* 1678E8 80247088 00511021 */  addu      $v0, $v0, $s1
/* 1678EC 8024708C 00021080 */  sll       $v0, $v0, 2
/* 1678F0 80247090 00511023 */  subu      $v0, $v0, $s1
/* 1678F4 80247094 02028021 */  addu      $s0, $s0, $v0
/* 1678F8 80247098 0C0926A9 */  jal       filemenu_get_menu_message
/* 1678FC 8024709C 24040014 */   addiu    $a0, $zero, 0x14
/* 167900 802470A0 0040202D */  daddu     $a0, $v0, $zero
/* 167904 802470A4 02702821 */  addu      $a1, $s3, $s0
/* 167908 802470A8 0240302D */  daddu     $a2, $s2, $zero
/* 16790C 802470AC 240700FF */  addiu     $a3, $zero, 0xff
/* 167910 802470B0 AFA00010 */  sw        $zero, 0x10($sp)
/* 167914 802470B4 0C09265F */  jal       filemenu_draw_message
/* 167918 802470B8 AFA00014 */   sw       $zero, 0x14($sp)
/* 16791C 802470BC 0C0926A9 */  jal       filemenu_get_menu_message
/* 167920 802470C0 24040015 */   addiu    $a0, $zero, 0x15
/* 167924 802470C4 0040202D */  daddu     $a0, $v0, $zero
/* 167928 802470C8 26650046 */  addiu     $a1, $s3, 0x46
/* 16792C 802470CC 08091C5A */  j         .L80247168
/* 167930 802470D0 26860026 */   addiu    $a2, $s4, 0x26
glabel L802470D4_167934
/* 167934 802470D4 0C0926A9 */  jal       filemenu_get_menu_message
/* 167938 802470D8 24040019 */   addiu    $a0, $zero, 0x19
/* 16793C 802470DC 0040202D */  daddu     $a0, $v0, $zero
/* 167940 802470E0 2665000A */  addiu     $a1, $s3, 0xa
/* 167944 802470E4 26900004 */  addiu     $s0, $s4, 4
/* 167948 802470E8 0200302D */  daddu     $a2, $s0, $zero
/* 16794C 802470EC 240700FF */  addiu     $a3, $zero, 0xff
/* 167950 802470F0 AFA00010 */  sw        $zero, 0x10($sp)
/* 167954 802470F4 0C09265F */  jal       filemenu_draw_message
/* 167958 802470F8 AFA00014 */   sw       $zero, 0x14($sp)
/* 16795C 802470FC 0C0926A9 */  jal       filemenu_get_menu_message
/* 167960 80247100 24040016 */   addiu    $a0, $zero, 0x16
/* 167964 80247104 0040202D */  daddu     $a0, $v0, $zero
/* 167968 80247108 2665007F */  addiu     $a1, $s3, 0x7f
/* 16796C 8024710C 0200302D */  daddu     $a2, $s0, $zero
/* 167970 80247110 240700FF */  addiu     $a3, $zero, 0xff
/* 167974 80247114 AFA00010 */  sw        $zero, 0x10($sp)
/* 167978 80247118 0C09265F */  jal       filemenu_draw_message
/* 16797C 8024711C AFA00014 */   sw       $zero, 0x14($sp)
/* 167980 80247120 266500A5 */  addiu     $a1, $s3, 0xa5
/* 167984 80247124 26860006 */  addiu     $a2, $s4, 6
/* 167988 80247128 3C028025 */  lui       $v0, %hi(D_80249B84)
/* 16798C 8024712C 8C429B84 */  lw        $v0, %lo(D_80249B84)($v0)
/* 167990 80247130 0000382D */  daddu     $a3, $zero, $zero
/* 167994 80247134 90440003 */  lbu       $a0, 3($v0)
/* 167998 80247138 240200FF */  addiu     $v0, $zero, 0xff
/* 16799C 8024713C AFA20014 */  sw        $v0, 0x14($sp)
/* 1679A0 80247140 24020003 */  addiu     $v0, $zero, 3
/* 1679A4 80247144 AFA00010 */  sw        $zero, 0x10($sp)
/* 1679A8 80247148 AFA20018 */  sw        $v0, 0x18($sp)
/* 1679AC 8024714C 0C049DA7 */  jal       draw_number
/* 1679B0 80247150 24840001 */   addiu    $a0, $a0, 1
/* 1679B4 80247154 0C0926A9 */  jal       filemenu_get_menu_message
/* 1679B8 80247158 24040021 */   addiu    $a0, $zero, 0x21
/* 1679BC 8024715C 0040202D */  daddu     $a0, $v0, $zero
/* 1679C0 80247160 266500A2 */  addiu     $a1, $s3, 0xa2
.L80247164:
/* 1679C4 80247164 0200302D */  daddu     $a2, $s0, $zero
.L80247168:
/* 1679C8 80247168 240700FF */  addiu     $a3, $zero, 0xff
/* 1679CC 8024716C AFA00010 */  sw        $zero, 0x10($sp)
/* 1679D0 80247170 0C09265F */  jal       filemenu_draw_message
/* 1679D4 80247174 AFA00014 */   sw       $zero, 0x14($sp)
.L80247178:
/* 1679D8 80247178 8FBF0034 */  lw        $ra, 0x34($sp)
/* 1679DC 8024717C 8FB40030 */  lw        $s4, 0x30($sp)
/* 1679E0 80247180 8FB3002C */  lw        $s3, 0x2c($sp)
/* 1679E4 80247184 8FB20028 */  lw        $s2, 0x28($sp)
/* 1679E8 80247188 8FB10024 */  lw        $s1, 0x24($sp)
/* 1679EC 8024718C 8FB00020 */  lw        $s0, 0x20($sp)
/* 1679F0 80247190 03E00008 */  jr        $ra
/* 1679F4 80247194 27BD0038 */   addiu    $sp, $sp, 0x38
