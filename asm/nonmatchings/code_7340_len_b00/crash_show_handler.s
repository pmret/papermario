.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel crash_show_handler
/* 77B0 8002C3B0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 77B4 8002C3B4 AFB1001C */  sw        $s1, 0x1c($sp)
/* 77B8 8002C3B8 0080882D */  daddu     $s1, $a0, $zero
/* 77BC 8002C3BC AFB20020 */  sw        $s2, 0x20($sp)
/* 77C0 8002C3C0 26320020 */  addiu     $s2, $s1, 0x20
/* 77C4 8002C3C4 AFBF0024 */  sw        $ra, 0x24($sp)
/* 77C8 8002C3C8 AFB00018 */  sw        $s0, 0x18($sp)
/* 77CC 8002C3CC 8E220120 */  lw        $v0, 0x120($s1)
/* 77D0 8002C3D0 24030017 */  addiu     $v1, $zero, 0x17
/* 77D4 8002C3D4 00021082 */  srl       $v0, $v0, 2
/* 77D8 8002C3D8 3042001F */  andi      $v0, $v0, 0x1f
/* 77DC 8002C3DC 14430002 */  bne       $v0, $v1, .L8002C3E8
/* 77E0 8002C3E0 0040802D */   daddu    $s0, $v0, $zero
/* 77E4 8002C3E4 24100010 */  addiu     $s0, $zero, 0x10
.L8002C3E8:
/* 77E8 8002C3E8 2402001F */  addiu     $v0, $zero, 0x1f
/* 77EC 8002C3EC 52020001 */  beql      $s0, $v0, .L8002C3F4
/* 77F0 8002C3F0 24100011 */   addiu    $s0, $zero, 0x11
.L8002C3F4:
/* 77F4 8002C3F4 0C018634 */  jal       osWritebackDCacheAll
/* 77F8 8002C3F8 00000000 */   nop      
/* 77FC 8002C3FC 24040019 */  addiu     $a0, $zero, 0x19
/* 7800 8002C400 24050014 */  addiu     $a1, $zero, 0x14
/* 7804 8002C404 2406010E */  addiu     $a2, $zero, 0x10e
/* 7808 8002C408 0C00AFEC */  jal       func_8002BFB0
/* 780C 8002C40C 0080382D */   daddu    $a3, $a0, $zero
/* 7810 8002C410 2404001E */  addiu     $a0, $zero, 0x1e
/* 7814 8002C414 00101080 */  sll       $v0, $s0, 2
/* 7818 8002C418 3C018007 */  lui       $at, %hi(D_80077390)
/* 781C 8002C41C 00220821 */  addu      $at, $at, $v0
/* 7820 8002C420 8C227390 */  lw        $v0, %lo(D_80077390)($at)
/* 7824 8002C424 AFA20010 */  sw        $v0, 0x10($sp)
/* 7828 8002C428 8E270014 */  lw        $a3, 0x14($s1)
/* 782C 8002C42C 3C06800A */  lui       $a2, %hi(D_80098064)
/* 7830 8002C430 24C68064 */  addiu     $a2, $a2, %lo(D_80098064)
/* 7834 8002C434 0C00B082 */  jal       crash_printf_string
/* 7838 8002C438 24050019 */   addiu    $a1, $zero, 0x19
/* 783C 8002C43C 8E220118 */  lw        $v0, 0x118($s1)
/* 7840 8002C440 2404001E */  addiu     $a0, $zero, 0x1e
/* 7844 8002C444 AFA20010 */  sw        $v0, 0x10($sp)
/* 7848 8002C448 8E220124 */  lw        $v0, 0x124($s1)
/* 784C 8002C44C AFA20014 */  sw        $v0, 0x14($sp)
/* 7850 8002C450 8E27011C */  lw        $a3, 0x11c($s1)
/* 7854 8002C454 3C06800A */  lui       $a2, %hi(D_80098074)
/* 7858 8002C458 24C68074 */  addiu     $a2, $a2, %lo(D_80098074)
/* 785C 8002C45C 0C00B082 */  jal       crash_printf_string
/* 7860 8002C460 24050023 */   addiu    $a1, $zero, 0x23
/* 7864 8002C464 0C00AFD0 */  jal       crash_delay_msec
/* 7868 8002C468 240407D0 */   addiu    $a0, $zero, 0x7d0
/* 786C 8002C46C 0C019CE0 */  jal       osViBlack
/* 7870 8002C470 0000202D */   daddu    $a0, $zero, $zero
/* 7874 8002C474 0C019CF8 */  jal       osViRepeatLine
/* 7878 8002C478 0000202D */   daddu    $a0, $zero, $zero
/* 787C 8002C47C 3C04800A */  lui       $a0, %hi(D_8009C4FC)
/* 7880 8002C480 8C84C4FC */  lw        $a0, %lo(D_8009C4FC)($a0)
/* 7884 8002C484 0C019C08 */  jal       osViSwapBuffer
/* 7888 8002C488 00000000 */   nop      
/* 788C 8002C48C 24040019 */  addiu     $a0, $zero, 0x19
/* 7890 8002C490 2405002D */  addiu     $a1, $zero, 0x2d
/* 7894 8002C494 2406010E */  addiu     $a2, $zero, 0x10e
/* 7898 8002C498 0C00AFEC */  jal       func_8002BFB0
/* 789C 8002C49C 240700B9 */   addiu    $a3, $zero, 0xb9
/* 78A0 8002C4A0 8E22002C */  lw        $v0, 0x2c($s1)
/* 78A4 8002C4A4 2404001E */  addiu     $a0, $zero, 0x1e
/* 78A8 8002C4A8 AFA20010 */  sw        $v0, 0x10($sp)
/* 78AC 8002C4AC 8E220034 */  lw        $v0, 0x34($s1)
/* 78B0 8002C4B0 AFA20014 */  sw        $v0, 0x14($sp)
/* 78B4 8002C4B4 8E270024 */  lw        $a3, 0x24($s1)
/* 78B8 8002C4B8 3C06800A */  lui       $a2, %hi(D_80098094)
/* 78BC 8002C4BC 24C68094 */  addiu     $a2, $a2, %lo(D_80098094)
/* 78C0 8002C4C0 0C00B082 */  jal       crash_printf_string
/* 78C4 8002C4C4 24050032 */   addiu    $a1, $zero, 0x32
/* 78C8 8002C4C8 8E220044 */  lw        $v0, 0x44($s1)
/* 78CC 8002C4CC 2404001E */  addiu     $a0, $zero, 0x1e
/* 78D0 8002C4D0 AFA20010 */  sw        $v0, 0x10($sp)
/* 78D4 8002C4D4 8E22004C */  lw        $v0, 0x4c($s1)
/* 78D8 8002C4D8 AFA20014 */  sw        $v0, 0x14($sp)
/* 78DC 8002C4DC 8E27003C */  lw        $a3, 0x3c($s1)
/* 78E0 8002C4E0 3C06800A */  lui       $a2, %hi(D_800980B4)
/* 78E4 8002C4E4 24C680B4 */  addiu     $a2, $a2, %lo(D_800980B4)
/* 78E8 8002C4E8 0C00B082 */  jal       crash_printf_string
/* 78EC 8002C4EC 2405003C */   addiu    $a1, $zero, 0x3c
/* 78F0 8002C4F0 8E22005C */  lw        $v0, 0x5c($s1)
/* 78F4 8002C4F4 2404001E */  addiu     $a0, $zero, 0x1e
/* 78F8 8002C4F8 AFA20010 */  sw        $v0, 0x10($sp)
/* 78FC 8002C4FC 8E220064 */  lw        $v0, 0x64($s1)
/* 7900 8002C500 AFA20014 */  sw        $v0, 0x14($sp)
/* 7904 8002C504 8E270054 */  lw        $a3, 0x54($s1)
/* 7908 8002C508 3C06800A */  lui       $a2, %hi(D_800980D4)
/* 790C 8002C50C 24C680D4 */  addiu     $a2, $a2, %lo(D_800980D4)
/* 7910 8002C510 0C00B082 */  jal       crash_printf_string
/* 7914 8002C514 24050046 */   addiu    $a1, $zero, 0x46
/* 7918 8002C518 8E220074 */  lw        $v0, 0x74($s1)
/* 791C 8002C51C 2404001E */  addiu     $a0, $zero, 0x1e
/* 7920 8002C520 AFA20010 */  sw        $v0, 0x10($sp)
/* 7924 8002C524 8E22007C */  lw        $v0, 0x7c($s1)
/* 7928 8002C528 AFA20014 */  sw        $v0, 0x14($sp)
/* 792C 8002C52C 8E27006C */  lw        $a3, 0x6c($s1)
/* 7930 8002C530 3C06800A */  lui       $a2, %hi(D_800980F4)
/* 7934 8002C534 24C680F4 */  addiu     $a2, $a2, %lo(D_800980F4)
/* 7938 8002C538 0C00B082 */  jal       crash_printf_string
/* 793C 8002C53C 24050050 */   addiu    $a1, $zero, 0x50
/* 7940 8002C540 8E22008C */  lw        $v0, 0x8c($s1)
/* 7944 8002C544 2404001E */  addiu     $a0, $zero, 0x1e
/* 7948 8002C548 AFA20010 */  sw        $v0, 0x10($sp)
/* 794C 8002C54C 8E220094 */  lw        $v0, 0x94($s1)
/* 7950 8002C550 AFA20014 */  sw        $v0, 0x14($sp)
/* 7954 8002C554 8E270084 */  lw        $a3, 0x84($s1)
/* 7958 8002C558 3C06800A */  lui       $a2, %hi(D_80098114)
/* 795C 8002C55C 24C68114 */  addiu     $a2, $a2, %lo(D_80098114)
/* 7960 8002C560 0C00B082 */  jal       crash_printf_string
/* 7964 8002C564 2405005A */   addiu    $a1, $zero, 0x5a
/* 7968 8002C568 8E2200A4 */  lw        $v0, 0xa4($s1)
/* 796C 8002C56C 2404001E */  addiu     $a0, $zero, 0x1e
/* 7970 8002C570 AFA20010 */  sw        $v0, 0x10($sp)
/* 7974 8002C574 8E2200AC */  lw        $v0, 0xac($s1)
/* 7978 8002C578 AFA20014 */  sw        $v0, 0x14($sp)
/* 797C 8002C57C 8E27009C */  lw        $a3, 0x9c($s1)
/* 7980 8002C580 3C06800A */  lui       $a2, %hi(D_80098134)
/* 7984 8002C584 24C68134 */  addiu     $a2, $a2, %lo(D_80098134)
/* 7988 8002C588 0C00B082 */  jal       crash_printf_string
/* 798C 8002C58C 24050064 */   addiu    $a1, $zero, 0x64
/* 7990 8002C590 8E2200BC */  lw        $v0, 0xbc($s1)
/* 7994 8002C594 2404001E */  addiu     $a0, $zero, 0x1e
/* 7998 8002C598 AFA20010 */  sw        $v0, 0x10($sp)
/* 799C 8002C59C 8E2200C4 */  lw        $v0, 0xc4($s1)
/* 79A0 8002C5A0 AFA20014 */  sw        $v0, 0x14($sp)
/* 79A4 8002C5A4 8E2700B4 */  lw        $a3, 0xb4($s1)
/* 79A8 8002C5A8 3C06800A */  lui       $a2, %hi(D_80098154)
/* 79AC 8002C5AC 24C68154 */  addiu     $a2, $a2, %lo(D_80098154)
/* 79B0 8002C5B0 0C00B082 */  jal       crash_printf_string
/* 79B4 8002C5B4 2405006E */   addiu    $a1, $zero, 0x6e
/* 79B8 8002C5B8 8E2200D4 */  lw        $v0, 0xd4($s1)
/* 79BC 8002C5BC 2404001E */  addiu     $a0, $zero, 0x1e
/* 79C0 8002C5C0 AFA20010 */  sw        $v0, 0x10($sp)
/* 79C4 8002C5C4 8E2200DC */  lw        $v0, 0xdc($s1)
/* 79C8 8002C5C8 AFA20014 */  sw        $v0, 0x14($sp)
/* 79CC 8002C5CC 8E2700CC */  lw        $a3, 0xcc($s1)
/* 79D0 8002C5D0 3C06800A */  lui       $a2, %hi(D_80098174)
/* 79D4 8002C5D4 24C68174 */  addiu     $a2, $a2, %lo(D_80098174)
/* 79D8 8002C5D8 0C00B082 */  jal       crash_printf_string
/* 79DC 8002C5DC 24050078 */   addiu    $a1, $zero, 0x78
/* 79E0 8002C5E0 8E2200EC */  lw        $v0, 0xec($s1)
/* 79E4 8002C5E4 2404001E */  addiu     $a0, $zero, 0x1e
/* 79E8 8002C5E8 AFA20010 */  sw        $v0, 0x10($sp)
/* 79EC 8002C5EC 8E2200F4 */  lw        $v0, 0xf4($s1)
/* 79F0 8002C5F0 AFA20014 */  sw        $v0, 0x14($sp)
/* 79F4 8002C5F4 8E2700E4 */  lw        $a3, 0xe4($s1)
/* 79F8 8002C5F8 3C06800A */  lui       $a2, %hi(D_80098194)
/* 79FC 8002C5FC 24C68194 */  addiu     $a2, $a2, %lo(D_80098194)
/* 7A00 8002C600 0C00B082 */  jal       crash_printf_string
/* 7A04 8002C604 24050082 */   addiu    $a1, $zero, 0x82
/* 7A08 8002C608 2404001E */  addiu     $a0, $zero, 0x1e
/* 7A0C 8002C60C 8E220104 */  lw        $v0, 0x104($s1)
/* 7A10 8002C610 AFA20010 */  sw        $v0, 0x10($sp)
/* 7A14 8002C614 8E2700FC */  lw        $a3, 0xfc($s1)
/* 7A18 8002C618 3C06800A */  lui       $a2, %hi(D_800981B4)
/* 7A1C 8002C61C 24C681B4 */  addiu     $a2, $a2, %lo(D_800981B4)
/* 7A20 8002C620 0C00B082 */  jal       crash_printf_string
/* 7A24 8002C624 2405008C */   addiu    $a1, $zero, 0x8c
/* 7A28 8002C628 8E24012C */  lw        $a0, 0x12c($s1)
/* 7A2C 8002C62C 0C00B0C9 */  jal       func_8002C324
/* 7A30 8002C630 00000000 */   nop      
/* 7A34 8002C634 2404001E */  addiu     $a0, $zero, 0x1e
/* 7A38 8002C638 240500AA */  addiu     $a1, $zero, 0xaa
/* 7A3C 8002C63C 0000302D */  daddu     $a2, $zero, $zero
/* 7A40 8002C640 0C00B0AE */  jal       crash_print_fpr
/* 7A44 8002C644 26270134 */   addiu    $a3, $s1, 0x134
/* 7A48 8002C648 24040078 */  addiu     $a0, $zero, 0x78
/* 7A4C 8002C64C 240500AA */  addiu     $a1, $zero, 0xaa
/* 7A50 8002C650 24060002 */  addiu     $a2, $zero, 2
/* 7A54 8002C654 0C00B0AE */  jal       crash_print_fpr
/* 7A58 8002C658 2627013C */   addiu    $a3, $s1, 0x13c
/* 7A5C 8002C65C 240400D2 */  addiu     $a0, $zero, 0xd2
/* 7A60 8002C660 240500AA */  addiu     $a1, $zero, 0xaa
/* 7A64 8002C664 24060004 */  addiu     $a2, $zero, 4
/* 7A68 8002C668 0C00B0AE */  jal       crash_print_fpr
/* 7A6C 8002C66C 26270144 */   addiu    $a3, $s1, 0x144
/* 7A70 8002C670 2404001E */  addiu     $a0, $zero, 0x1e
/* 7A74 8002C674 240500B4 */  addiu     $a1, $zero, 0xb4
/* 7A78 8002C678 24060006 */  addiu     $a2, $zero, 6
/* 7A7C 8002C67C 0C00B0AE */  jal       crash_print_fpr
/* 7A80 8002C680 2627014C */   addiu    $a3, $s1, 0x14c
/* 7A84 8002C684 24040078 */  addiu     $a0, $zero, 0x78
/* 7A88 8002C688 240500B4 */  addiu     $a1, $zero, 0xb4
/* 7A8C 8002C68C 24060008 */  addiu     $a2, $zero, 8
/* 7A90 8002C690 0C00B0AE */  jal       crash_print_fpr
/* 7A94 8002C694 26270154 */   addiu    $a3, $s1, 0x154
/* 7A98 8002C698 240400D2 */  addiu     $a0, $zero, 0xd2
/* 7A9C 8002C69C 240500B4 */  addiu     $a1, $zero, 0xb4
/* 7AA0 8002C6A0 2406000A */  addiu     $a2, $zero, 0xa
/* 7AA4 8002C6A4 0C00B0AE */  jal       crash_print_fpr
/* 7AA8 8002C6A8 2627015C */   addiu    $a3, $s1, 0x15c
/* 7AAC 8002C6AC 2404001E */  addiu     $a0, $zero, 0x1e
/* 7AB0 8002C6B0 240500BE */  addiu     $a1, $zero, 0xbe
/* 7AB4 8002C6B4 2406000C */  addiu     $a2, $zero, 0xc
/* 7AB8 8002C6B8 0C00B0AE */  jal       crash_print_fpr
/* 7ABC 8002C6BC 26270164 */   addiu    $a3, $s1, 0x164
/* 7AC0 8002C6C0 24040078 */  addiu     $a0, $zero, 0x78
/* 7AC4 8002C6C4 240500BE */  addiu     $a1, $zero, 0xbe
/* 7AC8 8002C6C8 2406000E */  addiu     $a2, $zero, 0xe
/* 7ACC 8002C6CC 0C00B0AE */  jal       crash_print_fpr
/* 7AD0 8002C6D0 2627016C */   addiu    $a3, $s1, 0x16c
/* 7AD4 8002C6D4 240400D2 */  addiu     $a0, $zero, 0xd2
/* 7AD8 8002C6D8 240500BE */  addiu     $a1, $zero, 0xbe
/* 7ADC 8002C6DC 24060010 */  addiu     $a2, $zero, 0x10
/* 7AE0 8002C6E0 0C00B0AE */  jal       crash_print_fpr
/* 7AE4 8002C6E4 26270174 */   addiu    $a3, $s1, 0x174
/* 7AE8 8002C6E8 2404001E */  addiu     $a0, $zero, 0x1e
/* 7AEC 8002C6EC 240500C8 */  addiu     $a1, $zero, 0xc8
/* 7AF0 8002C6F0 24060012 */  addiu     $a2, $zero, 0x12
/* 7AF4 8002C6F4 0C00B0AE */  jal       crash_print_fpr
/* 7AF8 8002C6F8 2627017C */   addiu    $a3, $s1, 0x17c
/* 7AFC 8002C6FC 24040078 */  addiu     $a0, $zero, 0x78
/* 7B00 8002C700 240500C8 */  addiu     $a1, $zero, 0xc8
/* 7B04 8002C704 24060014 */  addiu     $a2, $zero, 0x14
/* 7B08 8002C708 0C00B0AE */  jal       crash_print_fpr
/* 7B0C 8002C70C 26270184 */   addiu    $a3, $s1, 0x184
/* 7B10 8002C710 240400D2 */  addiu     $a0, $zero, 0xd2
/* 7B14 8002C714 240500C8 */  addiu     $a1, $zero, 0xc8
/* 7B18 8002C718 24060016 */  addiu     $a2, $zero, 0x16
/* 7B1C 8002C71C 0C00B0AE */  jal       crash_print_fpr
/* 7B20 8002C720 2627018C */   addiu    $a3, $s1, 0x18c
/* 7B24 8002C724 2404001E */  addiu     $a0, $zero, 0x1e
/* 7B28 8002C728 240500D2 */  addiu     $a1, $zero, 0xd2
/* 7B2C 8002C72C 24060018 */  addiu     $a2, $zero, 0x18
/* 7B30 8002C730 0C00B0AE */  jal       crash_print_fpr
/* 7B34 8002C734 26270194 */   addiu    $a3, $s1, 0x194
/* 7B38 8002C738 24040078 */  addiu     $a0, $zero, 0x78
/* 7B3C 8002C73C 240500D2 */  addiu     $a1, $zero, 0xd2
/* 7B40 8002C740 2406001A */  addiu     $a2, $zero, 0x1a
/* 7B44 8002C744 0C00B0AE */  jal       crash_print_fpr
/* 7B48 8002C748 2627019C */   addiu    $a3, $s1, 0x19c
/* 7B4C 8002C74C 240400D2 */  addiu     $a0, $zero, 0xd2
/* 7B50 8002C750 0080282D */  daddu     $a1, $a0, $zero
/* 7B54 8002C754 2406001C */  addiu     $a2, $zero, 0x1c
/* 7B58 8002C758 0C00B0AE */  jal       crash_print_fpr
/* 7B5C 8002C75C 262701A4 */   addiu    $a3, $s1, 0x1a4
/* 7B60 8002C760 2404001E */  addiu     $a0, $zero, 0x1e
/* 7B64 8002C764 240500DC */  addiu     $a1, $zero, 0xdc
/* 7B68 8002C768 0080302D */  daddu     $a2, $a0, $zero
/* 7B6C 8002C76C 0C00B0AE */  jal       crash_print_fpr
/* 7B70 8002C770 262701AC */   addiu    $a3, $s1, 0x1ac
/* 7B74 8002C774 0C00AFD0 */  jal       crash_delay_msec
/* 7B78 8002C778 240401F4 */   addiu    $a0, $zero, 0x1f4
/* 7B7C 8002C77C 240400D2 */  addiu     $a0, $zero, 0xd2
/* 7B80 8002C780 8E4200FC */  lw        $v0, 0xfc($s2)
/* 7B84 8002C784 8C470000 */  lw        $a3, ($v0)
/* 7B88 8002C788 3C06800A */  lui       $a2, %hi(D_800981C8)
/* 7B8C 8002C78C 24C681C8 */  addiu     $a2, $a2, %lo(D_800981C8)
/* 7B90 8002C790 0C00B082 */  jal       crash_printf_string
/* 7B94 8002C794 2405008C */   addiu    $a1, $zero, 0x8c
/* 7B98 8002C798 8FBF0024 */  lw        $ra, 0x24($sp)
/* 7B9C 8002C79C 8FB20020 */  lw        $s2, 0x20($sp)
/* 7BA0 8002C7A0 8FB1001C */  lw        $s1, 0x1c($sp)
/* 7BA4 8002C7A4 8FB00018 */  lw        $s0, 0x18($sp)
/* 7BA8 8002C7A8 03E00008 */  jr        $ra
/* 7BAC 8002C7AC 27BD0028 */   addiu    $sp, $sp, 0x28
