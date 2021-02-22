.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8002C370
/* 7770 8002C370 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 7774 8002C374 AFB1001C */  sw        $s1, 0x1c($sp)
/* 7778 8002C378 0080882D */  daddu     $s1, $a0, $zero
/* 777C 8002C37C AFB20020 */  sw        $s2, 0x20($sp)
/* 7780 8002C380 26320020 */  addiu     $s2, $s1, 0x20
/* 7784 8002C384 AFBF0024 */  sw        $ra, 0x24($sp)
/* 7788 8002C388 AFB00018 */  sw        $s0, 0x18($sp)
/* 778C 8002C38C 8E220120 */  lw        $v0, 0x120($s1)
/* 7790 8002C390 24030017 */  addiu     $v1, $zero, 0x17
/* 7794 8002C394 00021082 */  srl       $v0, $v0, 2
/* 7798 8002C398 3042001F */  andi      $v0, $v0, 0x1f
/* 779C 8002C39C 14430002 */  bne       $v0, $v1, .L8002C3A8
/* 77A0 8002C3A0 0040802D */   daddu    $s0, $v0, $zero
/* 77A4 8002C3A4 24100010 */  addiu     $s0, $zero, 0x10
.L8002C3A8:
/* 77A8 8002C3A8 2402001F */  addiu     $v0, $zero, 0x1f
/* 77AC 8002C3AC 52020001 */  beql      $s0, $v0, .L8002C3B4
/* 77B0 8002C3B0 24100011 */   addiu    $s0, $zero, 0x11
.L8002C3B4:
/* 77B4 8002C3B4 0C018628 */  jal       func_800618A0
/* 77B8 8002C3B8 00000000 */   nop
/* 77BC 8002C3BC 24040019 */  addiu     $a0, $zero, 0x19
/* 77C0 8002C3C0 24050014 */  addiu     $a1, $zero, 0x14
/* 77C4 8002C3C4 2406010E */  addiu     $a2, $zero, 0x10e
/* 77C8 8002C3C8 0C00AFDC */  jal       func_8002BF70
/* 77CC 8002C3CC 0080382D */   daddu    $a3, $a0, $zero
/* 77D0 8002C3D0 2404001E */  addiu     $a0, $zero, 0x1e
/* 77D4 8002C3D4 00101080 */  sll       $v0, $s0, 2
/* 77D8 8002C3D8 3C018007 */  lui       $at, %hi(D_80077370)
/* 77DC 8002C3DC 00220821 */  addu      $at, $at, $v0
/* 77E0 8002C3E0 8C227370 */  lw        $v0, %lo(D_80077370)($at)
/* 77E4 8002C3E4 AFA20010 */  sw        $v0, 0x10($sp)
/* 77E8 8002C3E8 8E270014 */  lw        $a3, 0x14($s1)
/* 77EC 8002C3EC 3C06800A */  lui       $a2, %hi(D_80098044)
/* 77F0 8002C3F0 24C68044 */  addiu     $a2, $a2, %lo(D_80098044)
/* 77F4 8002C3F4 0C00B072 */  jal       func_8002C1C8
/* 77F8 8002C3F8 24050019 */   addiu    $a1, $zero, 0x19
/* 77FC 8002C3FC 8E220118 */  lw        $v0, 0x118($s1)
/* 7800 8002C400 2404001E */  addiu     $a0, $zero, 0x1e
/* 7804 8002C404 AFA20010 */  sw        $v0, 0x10($sp)
/* 7808 8002C408 8E220124 */  lw        $v0, 0x124($s1)
/* 780C 8002C40C AFA20014 */  sw        $v0, 0x14($sp)
/* 7810 8002C410 8E27011C */  lw        $a3, 0x11c($s1)
/* 7814 8002C414 3C06800A */  lui       $a2, %hi(D_80098054)
/* 7818 8002C418 24C68054 */  addiu     $a2, $a2, %lo(D_80098054)
/* 781C 8002C41C 0C00B072 */  jal       func_8002C1C8
/* 7820 8002C420 24050023 */   addiu    $a1, $zero, 0x23
/* 7824 8002C424 0C00AFC0 */  jal       func_8002BF00
/* 7828 8002C428 240407D0 */   addiu    $a0, $zero, 0x7d0
/* 782C 8002C42C 0C019CD4 */  jal       func_80067350
/* 7830 8002C430 0000202D */   daddu    $a0, $zero, $zero
/* 7834 8002C434 0C019CEC */  jal       func_800673B0
/* 7838 8002C438 0000202D */   daddu    $a0, $zero, $zero
/* 783C 8002C43C 3C04800A */  lui       $a0, %hi(D_8009C4DC)
/* 7840 8002C440 8C84C4DC */  lw        $a0, %lo(D_8009C4DC)($a0)
/* 7844 8002C444 0C019BFC */  jal       func_80066FF0
/* 7848 8002C448 00000000 */   nop
/* 784C 8002C44C 24040019 */  addiu     $a0, $zero, 0x19
/* 7850 8002C450 2405002D */  addiu     $a1, $zero, 0x2d
/* 7854 8002C454 2406010E */  addiu     $a2, $zero, 0x10e
/* 7858 8002C458 0C00AFDC */  jal       func_8002BF70
/* 785C 8002C45C 240700B9 */   addiu    $a3, $zero, 0xb9
/* 7860 8002C460 8E22002C */  lw        $v0, 0x2c($s1)
/* 7864 8002C464 2404001E */  addiu     $a0, $zero, 0x1e
/* 7868 8002C468 AFA20010 */  sw        $v0, 0x10($sp)
/* 786C 8002C46C 8E220034 */  lw        $v0, 0x34($s1)
/* 7870 8002C470 AFA20014 */  sw        $v0, 0x14($sp)
/* 7874 8002C474 8E270024 */  lw        $a3, 0x24($s1)
/* 7878 8002C478 3C06800A */  lui       $a2, %hi(D_80098074)
/* 787C 8002C47C 24C68074 */  addiu     $a2, $a2, %lo(D_80098074)
/* 7880 8002C480 0C00B072 */  jal       func_8002C1C8
/* 7884 8002C484 24050032 */   addiu    $a1, $zero, 0x32
/* 7888 8002C488 8E220044 */  lw        $v0, 0x44($s1)
/* 788C 8002C48C 2404001E */  addiu     $a0, $zero, 0x1e
/* 7890 8002C490 AFA20010 */  sw        $v0, 0x10($sp)
/* 7894 8002C494 8E22004C */  lw        $v0, 0x4c($s1)
/* 7898 8002C498 AFA20014 */  sw        $v0, 0x14($sp)
/* 789C 8002C49C 8E27003C */  lw        $a3, 0x3c($s1)
/* 78A0 8002C4A0 3C06800A */  lui       $a2, %hi(D_80098094)
/* 78A4 8002C4A4 24C68094 */  addiu     $a2, $a2, %lo(D_80098094)
/* 78A8 8002C4A8 0C00B072 */  jal       func_8002C1C8
/* 78AC 8002C4AC 2405003C */   addiu    $a1, $zero, 0x3c
/* 78B0 8002C4B0 8E22005C */  lw        $v0, 0x5c($s1)
/* 78B4 8002C4B4 2404001E */  addiu     $a0, $zero, 0x1e
/* 78B8 8002C4B8 AFA20010 */  sw        $v0, 0x10($sp)
/* 78BC 8002C4BC 8E220064 */  lw        $v0, 0x64($s1)
/* 78C0 8002C4C0 AFA20014 */  sw        $v0, 0x14($sp)
/* 78C4 8002C4C4 8E270054 */  lw        $a3, 0x54($s1)
/* 78C8 8002C4C8 3C06800A */  lui       $a2, %hi(D_800980B4)
/* 78CC 8002C4CC 24C680B4 */  addiu     $a2, $a2, %lo(D_800980B4)
/* 78D0 8002C4D0 0C00B072 */  jal       func_8002C1C8
/* 78D4 8002C4D4 24050046 */   addiu    $a1, $zero, 0x46
/* 78D8 8002C4D8 8E220074 */  lw        $v0, 0x74($s1)
/* 78DC 8002C4DC 2404001E */  addiu     $a0, $zero, 0x1e
/* 78E0 8002C4E0 AFA20010 */  sw        $v0, 0x10($sp)
/* 78E4 8002C4E4 8E22007C */  lw        $v0, 0x7c($s1)
/* 78E8 8002C4E8 AFA20014 */  sw        $v0, 0x14($sp)
/* 78EC 8002C4EC 8E27006C */  lw        $a3, 0x6c($s1)
/* 78F0 8002C4F0 3C06800A */  lui       $a2, %hi(D_800980D4)
/* 78F4 8002C4F4 24C680D4 */  addiu     $a2, $a2, %lo(D_800980D4)
/* 78F8 8002C4F8 0C00B072 */  jal       func_8002C1C8
/* 78FC 8002C4FC 24050050 */   addiu    $a1, $zero, 0x50
/* 7900 8002C500 8E22008C */  lw        $v0, 0x8c($s1)
/* 7904 8002C504 2404001E */  addiu     $a0, $zero, 0x1e
/* 7908 8002C508 AFA20010 */  sw        $v0, 0x10($sp)
/* 790C 8002C50C 8E220094 */  lw        $v0, 0x94($s1)
/* 7910 8002C510 AFA20014 */  sw        $v0, 0x14($sp)
/* 7914 8002C514 8E270084 */  lw        $a3, 0x84($s1)
/* 7918 8002C518 3C06800A */  lui       $a2, %hi(D_800980F4)
/* 791C 8002C51C 24C680F4 */  addiu     $a2, $a2, %lo(D_800980F4)
/* 7920 8002C520 0C00B072 */  jal       func_8002C1C8
/* 7924 8002C524 2405005A */   addiu    $a1, $zero, 0x5a
/* 7928 8002C528 8E2200A4 */  lw        $v0, 0xa4($s1)
/* 792C 8002C52C 2404001E */  addiu     $a0, $zero, 0x1e
/* 7930 8002C530 AFA20010 */  sw        $v0, 0x10($sp)
/* 7934 8002C534 8E2200AC */  lw        $v0, 0xac($s1)
/* 7938 8002C538 AFA20014 */  sw        $v0, 0x14($sp)
/* 793C 8002C53C 8E27009C */  lw        $a3, 0x9c($s1)
/* 7940 8002C540 3C06800A */  lui       $a2, %hi(D_80098114)
/* 7944 8002C544 24C68114 */  addiu     $a2, $a2, %lo(D_80098114)
/* 7948 8002C548 0C00B072 */  jal       func_8002C1C8
/* 794C 8002C54C 24050064 */   addiu    $a1, $zero, 0x64
/* 7950 8002C550 8E2200BC */  lw        $v0, 0xbc($s1)
/* 7954 8002C554 2404001E */  addiu     $a0, $zero, 0x1e
/* 7958 8002C558 AFA20010 */  sw        $v0, 0x10($sp)
/* 795C 8002C55C 8E2200C4 */  lw        $v0, 0xc4($s1)
/* 7960 8002C560 AFA20014 */  sw        $v0, 0x14($sp)
/* 7964 8002C564 8E2700B4 */  lw        $a3, 0xb4($s1)
/* 7968 8002C568 3C06800A */  lui       $a2, %hi(D_80098134)
/* 796C 8002C56C 24C68134 */  addiu     $a2, $a2, %lo(D_80098134)
/* 7970 8002C570 0C00B072 */  jal       func_8002C1C8
/* 7974 8002C574 2405006E */   addiu    $a1, $zero, 0x6e
/* 7978 8002C578 8E2200D4 */  lw        $v0, 0xd4($s1)
/* 797C 8002C57C 2404001E */  addiu     $a0, $zero, 0x1e
/* 7980 8002C580 AFA20010 */  sw        $v0, 0x10($sp)
/* 7984 8002C584 8E2200DC */  lw        $v0, 0xdc($s1)
/* 7988 8002C588 AFA20014 */  sw        $v0, 0x14($sp)
/* 798C 8002C58C 8E2700CC */  lw        $a3, 0xcc($s1)
/* 7990 8002C590 3C06800A */  lui       $a2, %hi(D_80098154)
/* 7994 8002C594 24C68154 */  addiu     $a2, $a2, %lo(D_80098154)
/* 7998 8002C598 0C00B072 */  jal       func_8002C1C8
/* 799C 8002C59C 24050078 */   addiu    $a1, $zero, 0x78
/* 79A0 8002C5A0 8E2200EC */  lw        $v0, 0xec($s1)
/* 79A4 8002C5A4 2404001E */  addiu     $a0, $zero, 0x1e
/* 79A8 8002C5A8 AFA20010 */  sw        $v0, 0x10($sp)
/* 79AC 8002C5AC 8E2200F4 */  lw        $v0, 0xf4($s1)
/* 79B0 8002C5B0 AFA20014 */  sw        $v0, 0x14($sp)
/* 79B4 8002C5B4 8E2700E4 */  lw        $a3, 0xe4($s1)
/* 79B8 8002C5B8 3C06800A */  lui       $a2, %hi(D_80098174)
/* 79BC 8002C5BC 24C68174 */  addiu     $a2, $a2, %lo(D_80098174)
/* 79C0 8002C5C0 0C00B072 */  jal       func_8002C1C8
/* 79C4 8002C5C4 24050082 */   addiu    $a1, $zero, 0x82
/* 79C8 8002C5C8 2404001E */  addiu     $a0, $zero, 0x1e
/* 79CC 8002C5CC 8E220104 */  lw        $v0, 0x104($s1)
/* 79D0 8002C5D0 AFA20010 */  sw        $v0, 0x10($sp)
/* 79D4 8002C5D4 8E2700FC */  lw        $a3, 0xfc($s1)
/* 79D8 8002C5D8 3C06800A */  lui       $a2, %hi(D_80098194)
/* 79DC 8002C5DC 24C68194 */  addiu     $a2, $a2, %lo(D_80098194)
/* 79E0 8002C5E0 0C00B072 */  jal       func_8002C1C8
/* 79E4 8002C5E4 2405008C */   addiu    $a1, $zero, 0x8c
/* 79E8 8002C5E8 8E24012C */  lw        $a0, 0x12c($s1)
/* 79EC 8002C5EC 0C00B0B9 */  jal       func_8002C2E4
/* 79F0 8002C5F0 00000000 */   nop
/* 79F4 8002C5F4 2404001E */  addiu     $a0, $zero, 0x1e
/* 79F8 8002C5F8 240500AA */  addiu     $a1, $zero, 0xaa
/* 79FC 8002C5FC 0000302D */  daddu     $a2, $zero, $zero
/* 7A00 8002C600 0C00B09E */  jal       func_8002C278
/* 7A04 8002C604 26270134 */   addiu    $a3, $s1, 0x134
/* 7A08 8002C608 24040078 */  addiu     $a0, $zero, 0x78
/* 7A0C 8002C60C 240500AA */  addiu     $a1, $zero, 0xaa
/* 7A10 8002C610 24060002 */  addiu     $a2, $zero, 2
/* 7A14 8002C614 0C00B09E */  jal       func_8002C278
/* 7A18 8002C618 2627013C */   addiu    $a3, $s1, 0x13c
/* 7A1C 8002C61C 240400D2 */  addiu     $a0, $zero, 0xd2
/* 7A20 8002C620 240500AA */  addiu     $a1, $zero, 0xaa
/* 7A24 8002C624 24060004 */  addiu     $a2, $zero, 4
/* 7A28 8002C628 0C00B09E */  jal       func_8002C278
/* 7A2C 8002C62C 26270144 */   addiu    $a3, $s1, 0x144
/* 7A30 8002C630 2404001E */  addiu     $a0, $zero, 0x1e
/* 7A34 8002C634 240500B4 */  addiu     $a1, $zero, 0xb4
/* 7A38 8002C638 24060006 */  addiu     $a2, $zero, 6
/* 7A3C 8002C63C 0C00B09E */  jal       func_8002C278
/* 7A40 8002C640 2627014C */   addiu    $a3, $s1, 0x14c
/* 7A44 8002C644 24040078 */  addiu     $a0, $zero, 0x78
/* 7A48 8002C648 240500B4 */  addiu     $a1, $zero, 0xb4
/* 7A4C 8002C64C 24060008 */  addiu     $a2, $zero, 8
/* 7A50 8002C650 0C00B09E */  jal       func_8002C278
/* 7A54 8002C654 26270154 */   addiu    $a3, $s1, 0x154
/* 7A58 8002C658 240400D2 */  addiu     $a0, $zero, 0xd2
/* 7A5C 8002C65C 240500B4 */  addiu     $a1, $zero, 0xb4
/* 7A60 8002C660 2406000A */  addiu     $a2, $zero, 0xa
/* 7A64 8002C664 0C00B09E */  jal       func_8002C278
/* 7A68 8002C668 2627015C */   addiu    $a3, $s1, 0x15c
/* 7A6C 8002C66C 2404001E */  addiu     $a0, $zero, 0x1e
/* 7A70 8002C670 240500BE */  addiu     $a1, $zero, 0xbe
/* 7A74 8002C674 2406000C */  addiu     $a2, $zero, 0xc
/* 7A78 8002C678 0C00B09E */  jal       func_8002C278
/* 7A7C 8002C67C 26270164 */   addiu    $a3, $s1, 0x164
/* 7A80 8002C680 24040078 */  addiu     $a0, $zero, 0x78
/* 7A84 8002C684 240500BE */  addiu     $a1, $zero, 0xbe
/* 7A88 8002C688 2406000E */  addiu     $a2, $zero, 0xe
/* 7A8C 8002C68C 0C00B09E */  jal       func_8002C278
/* 7A90 8002C690 2627016C */   addiu    $a3, $s1, 0x16c
/* 7A94 8002C694 240400D2 */  addiu     $a0, $zero, 0xd2
/* 7A98 8002C698 240500BE */  addiu     $a1, $zero, 0xbe
/* 7A9C 8002C69C 24060010 */  addiu     $a2, $zero, 0x10
/* 7AA0 8002C6A0 0C00B09E */  jal       func_8002C278
/* 7AA4 8002C6A4 26270174 */   addiu    $a3, $s1, 0x174
/* 7AA8 8002C6A8 2404001E */  addiu     $a0, $zero, 0x1e
/* 7AAC 8002C6AC 240500C8 */  addiu     $a1, $zero, 0xc8
/* 7AB0 8002C6B0 24060012 */  addiu     $a2, $zero, 0x12
/* 7AB4 8002C6B4 0C00B09E */  jal       func_8002C278
/* 7AB8 8002C6B8 2627017C */   addiu    $a3, $s1, 0x17c
/* 7ABC 8002C6BC 24040078 */  addiu     $a0, $zero, 0x78
/* 7AC0 8002C6C0 240500C8 */  addiu     $a1, $zero, 0xc8
/* 7AC4 8002C6C4 24060014 */  addiu     $a2, $zero, 0x14
/* 7AC8 8002C6C8 0C00B09E */  jal       func_8002C278
/* 7ACC 8002C6CC 26270184 */   addiu    $a3, $s1, 0x184
/* 7AD0 8002C6D0 240400D2 */  addiu     $a0, $zero, 0xd2
/* 7AD4 8002C6D4 240500C8 */  addiu     $a1, $zero, 0xc8
/* 7AD8 8002C6D8 24060016 */  addiu     $a2, $zero, 0x16
/* 7ADC 8002C6DC 0C00B09E */  jal       func_8002C278
/* 7AE0 8002C6E0 2627018C */   addiu    $a3, $s1, 0x18c
/* 7AE4 8002C6E4 2404001E */  addiu     $a0, $zero, 0x1e
/* 7AE8 8002C6E8 240500D2 */  addiu     $a1, $zero, 0xd2
/* 7AEC 8002C6EC 24060018 */  addiu     $a2, $zero, 0x18
/* 7AF0 8002C6F0 0C00B09E */  jal       func_8002C278
/* 7AF4 8002C6F4 26270194 */   addiu    $a3, $s1, 0x194
/* 7AF8 8002C6F8 24040078 */  addiu     $a0, $zero, 0x78
/* 7AFC 8002C6FC 240500D2 */  addiu     $a1, $zero, 0xd2
/* 7B00 8002C700 2406001A */  addiu     $a2, $zero, 0x1a
/* 7B04 8002C704 0C00B09E */  jal       func_8002C278
/* 7B08 8002C708 2627019C */   addiu    $a3, $s1, 0x19c
/* 7B0C 8002C70C 240400D2 */  addiu     $a0, $zero, 0xd2
/* 7B10 8002C710 0080282D */  daddu     $a1, $a0, $zero
/* 7B14 8002C714 2406001C */  addiu     $a2, $zero, 0x1c
/* 7B18 8002C718 0C00B09E */  jal       func_8002C278
/* 7B1C 8002C71C 262701A4 */   addiu    $a3, $s1, 0x1a4
/* 7B20 8002C720 2404001E */  addiu     $a0, $zero, 0x1e
/* 7B24 8002C724 240500DC */  addiu     $a1, $zero, 0xdc
/* 7B28 8002C728 0080302D */  daddu     $a2, $a0, $zero
/* 7B2C 8002C72C 0C00B09E */  jal       func_8002C278
/* 7B30 8002C730 262701AC */   addiu    $a3, $s1, 0x1ac
/* 7B34 8002C734 0C00AFC0 */  jal       func_8002BF00
/* 7B38 8002C738 240401F4 */   addiu    $a0, $zero, 0x1f4
/* 7B3C 8002C73C 240400D2 */  addiu     $a0, $zero, 0xd2
/* 7B40 8002C740 8E4200FC */  lw        $v0, 0xfc($s2)
/* 7B44 8002C744 8C470000 */  lw        $a3, ($v0)
/* 7B48 8002C748 3C06800A */  lui       $a2, %hi(D_800981A8)
/* 7B4C 8002C74C 24C681A8 */  addiu     $a2, $a2, %lo(D_800981A8)
/* 7B50 8002C750 0C00B072 */  jal       func_8002C1C8
/* 7B54 8002C754 2405008C */   addiu    $a1, $zero, 0x8c
/* 7B58 8002C758 8FBF0024 */  lw        $ra, 0x24($sp)
/* 7B5C 8002C75C 8FB20020 */  lw        $s2, 0x20($sp)
/* 7B60 8002C760 8FB1001C */  lw        $s1, 0x1c($sp)
/* 7B64 8002C764 8FB00018 */  lw        $s0, 0x18($sp)
/* 7B68 8002C768 03E00008 */  jr        $ra
/* 7B6C 8002C76C 27BD0028 */   addiu    $sp, $sp, 0x28
