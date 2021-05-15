.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel render_menu_icons
/* D9DB4 801436B4 27BDFAE0 */  addiu     $sp, $sp, -0x520
/* D9DB8 801436B8 AFBF051C */  sw        $ra, 0x51c($sp)
/* D9DBC 801436BC AFB20518 */  sw        $s2, 0x518($sp)
/* D9DC0 801436C0 AFB10514 */  sw        $s1, 0x514($sp)
/* D9DC4 801436C4 AFB00510 */  sw        $s0, 0x510($sp)
/* D9DC8 801436C8 3C03800A */  lui       $v1, %hi(gCurrentCamID)
/* D9DCC 801436CC 8463A634 */  lh        $v1, %lo(gCurrentCamID)($v1)
/* D9DD0 801436D0 24020003 */  addiu     $v0, $zero, 3
/* D9DD4 801436D4 146200AB */  bne       $v1, $v0, .L80143984
/* D9DD8 801436D8 0000902D */   daddu    $s2, $zero, $zero
/* D9DDC 801436DC 0240882D */  daddu     $s1, $s2, $zero
/* D9DE0 801436E0 3C091020 */  lui       $t1, 0x1020
/* D9DE4 801436E4 3C080001 */  lui       $t0, 1
/* D9DE8 801436E8 3C074000 */  lui       $a3, 0x4000
/* D9DEC 801436EC 3C068015 */  lui       $a2, %hi(gHudElementList)
/* D9DF0 801436F0 8CC67960 */  lw        $a2, %lo(gHudElementList)($a2)
/* D9DF4 801436F4 27A50010 */  addiu     $a1, $sp, 0x10
.L801436F8:
/* D9DF8 801436F8 8CC40000 */  lw        $a0, ($a2)
/* D9DFC 801436FC 5080001D */  beql      $a0, $zero, .L80143774
/* D9E00 80143700 26310001 */   addiu    $s1, $s1, 1
/* D9E04 80143704 8C830000 */  lw        $v1, ($a0)
/* D9E08 80143708 5060001A */  beql      $v1, $zero, .L80143774
/* D9E0C 8014370C 26310001 */   addiu    $s1, $s1, 1
/* D9E10 80143710 30620002 */  andi      $v0, $v1, 2
/* D9E14 80143714 54400017 */  bnel      $v0, $zero, .L80143774
/* D9E18 80143718 26310001 */   addiu    $s1, $s1, 1
/* D9E1C 8014371C 00691024 */  and       $v0, $v1, $t1
/* D9E20 80143720 54400014 */  bnel      $v0, $zero, .L80143774
/* D9E24 80143724 26310001 */   addiu    $s1, $s1, 1
/* D9E28 80143728 00681024 */  and       $v0, $v1, $t0
/* D9E2C 8014372C 50400011 */  beql      $v0, $zero, .L80143774
/* D9E30 80143730 26310001 */   addiu    $s1, $s1, 1
/* D9E34 80143734 00671024 */  and       $v0, $v1, $a3
/* D9E38 80143738 5440000E */  bnel      $v0, $zero, .L80143774
/* D9E3C 8014373C 26310001 */   addiu    $s1, $s1, 1
/* D9E40 80143740 30620040 */  andi      $v0, $v1, 0x40
/* D9E44 80143744 5440000B */  bnel      $v0, $zero, .L80143774
/* D9E48 80143748 26310001 */   addiu    $s1, $s1, 1
/* D9E4C 8014374C 80820045 */  lb        $v0, 0x45($a0)
/* D9E50 80143750 04420008 */  bltzl     $v0, .L80143774
/* D9E54 80143754 26310001 */   addiu    $s1, $s1, 1
/* D9E58 80143758 30620080 */  andi      $v0, $v1, 0x80
/* D9E5C 8014375C 54400005 */  bnel      $v0, $zero, .L80143774
/* D9E60 80143760 26310001 */   addiu    $s1, $s1, 1
/* D9E64 80143764 ACB10000 */  sw        $s1, ($a1)
/* D9E68 80143768 24A50004 */  addiu     $a1, $a1, 4
/* D9E6C 8014376C 26520001 */  addiu     $s2, $s2, 1
/* D9E70 80143770 26310001 */  addiu     $s1, $s1, 1
.L80143774:
/* D9E74 80143774 2A220140 */  slti      $v0, $s1, 0x140
/* D9E78 80143778 1440FFDF */  bnez      $v0, .L801436F8
/* D9E7C 8014377C 24C60004 */   addiu    $a2, $a2, 4
/* D9E80 80143780 1240007E */  beqz      $s2, .L8014397C
/* D9E84 80143784 2642FFFF */   addiu    $v0, $s2, -1
/* D9E88 80143788 18400024 */  blez      $v0, .L8014381C
/* D9E8C 8014378C 0000882D */   daddu    $s1, $zero, $zero
/* D9E90 80143790 3C0C8015 */  lui       $t4, %hi(gHudElementList)
/* D9E94 80143794 258C7960 */  addiu     $t4, $t4, %lo(gHudElementList)
/* D9E98 80143798 27AB0010 */  addiu     $t3, $sp, 0x10
/* D9E9C 8014379C 0160502D */  daddu     $t2, $t3, $zero
.L801437A0:
/* D9EA0 801437A0 26240001 */  addiu     $a0, $s1, 1
/* D9EA4 801437A4 0092102A */  slt       $v0, $a0, $s2
/* D9EA8 801437A8 50400018 */  beql      $v0, $zero, .L8014380C
/* D9EAC 801437AC 26310001 */   addiu    $s1, $s1, 1
/* D9EB0 801437B0 0140482D */  daddu     $t1, $t2, $zero
/* D9EB4 801437B4 8D880000 */  lw        $t0, ($t4)
/* D9EB8 801437B8 00041080 */  sll       $v0, $a0, 2
/* D9EBC 801437BC 004B2821 */  addu      $a1, $v0, $t3
.L801437C0:
/* D9EC0 801437C0 8D270000 */  lw        $a3, ($t1)
/* D9EC4 801437C4 8CA60000 */  lw        $a2, ($a1)
/* D9EC8 801437C8 00071080 */  sll       $v0, $a3, 2
/* D9ECC 801437CC 00481021 */  addu      $v0, $v0, $t0
/* D9ED0 801437D0 8C430000 */  lw        $v1, ($v0)
/* D9ED4 801437D4 00061080 */  sll       $v0, $a2, 2
/* D9ED8 801437D8 00481021 */  addu      $v0, $v0, $t0
/* D9EDC 801437DC 8C420000 */  lw        $v0, ($v0)
/* D9EE0 801437E0 80630044 */  lb        $v1, 0x44($v1)
/* D9EE4 801437E4 80420044 */  lb        $v0, 0x44($v0)
/* D9EE8 801437E8 0062182A */  slt       $v1, $v1, $v0
/* D9EEC 801437EC 10600003 */  beqz      $v1, .L801437FC
/* D9EF0 801437F0 24840001 */   addiu    $a0, $a0, 1
/* D9EF4 801437F4 AD260000 */  sw        $a2, ($t1)
/* D9EF8 801437F8 ACA70000 */  sw        $a3, ($a1)
.L801437FC:
/* D9EFC 801437FC 0092102A */  slt       $v0, $a0, $s2
/* D9F00 80143800 1440FFEF */  bnez      $v0, .L801437C0
/* D9F04 80143804 24A50004 */   addiu    $a1, $a1, 4
/* D9F08 80143808 26310001 */  addiu     $s1, $s1, 1
.L8014380C:
/* D9F0C 8014380C 2642FFFF */  addiu     $v0, $s2, -1
/* D9F10 80143810 0222102A */  slt       $v0, $s1, $v0
/* D9F14 80143814 1440FFE2 */  bnez      $v0, .L801437A0
/* D9F18 80143818 254A0004 */   addiu    $t2, $t2, 4
.L8014381C:
/* D9F1C 8014381C 3C06ED03 */  lui       $a2, 0xed03
/* D9F20 80143820 34C60050 */  ori       $a2, $a2, 0x50
/* D9F24 80143824 3C04004D */  lui       $a0, 0x4d
/* D9F28 80143828 34840370 */  ori       $a0, $a0, 0x370
/* D9F2C 8014382C 3C07D9C0 */  lui       $a3, 0xd9c0
/* D9F30 80143830 34E7F9FA */  ori       $a3, $a3, 0xf9fa
/* D9F34 80143834 3C09D9FF */  lui       $t1, 0xd9ff
/* D9F38 80143838 3529FFFF */  ori       $t1, $t1, 0xffff
/* D9F3C 8014383C 3C080022 */  lui       $t0, 0x22
/* D9F40 80143840 35080005 */  ori       $t0, $t0, 5
/* D9F44 80143844 3C0ADC08 */  lui       $t2, 0xdc08
/* D9F48 80143848 354A060A */  ori       $t2, $t2, 0x60a
/* D9F4C 8014384C 3C0BDC08 */  lui       $t3, 0xdc08
/* D9F50 80143850 356B090A */  ori       $t3, $t3, 0x90a
/* D9F54 80143854 3C0CD700 */  lui       $t4, 0xd700
/* D9F58 80143858 358C0002 */  ori       $t4, $t4, 2
/* D9F5C 8014385C 3C0DE200 */  lui       $t5, 0xe200
/* D9F60 80143860 35AD1E01 */  ori       $t5, $t5, 0x1e01
/* D9F64 80143864 3C0FE300 */  lui       $t7, 0xe300
/* D9F68 80143868 35EF0A11 */  ori       $t7, $t7, 0xa11
/* D9F6C 8014386C 3C0E0008 */  lui       $t6, 8
/* D9F70 80143870 35CE2CF0 */  ori       $t6, $t6, 0x2cf0
/* D9F74 80143874 3C05800A */  lui       $a1, %hi(gMasterGfxPos)
/* D9F78 80143878 24A5A66C */  addiu     $a1, $a1, %lo(gMasterGfxPos)
/* D9F7C 8014387C 8CA20000 */  lw        $v0, ($a1)
/* D9F80 80143880 0000882D */  daddu     $s1, $zero, $zero
/* D9F84 80143884 0040182D */  daddu     $v1, $v0, $zero
/* D9F88 80143888 24420008 */  addiu     $v0, $v0, 8
/* D9F8C 8014388C ACA20000 */  sw        $v0, ($a1)
/* D9F90 80143890 AC660000 */  sw        $a2, ($v1)
/* D9F94 80143894 AC640004 */  sw        $a0, 4($v1)
/* D9F98 80143898 24430008 */  addiu     $v1, $v0, 8
/* D9F9C 8014389C ACA30000 */  sw        $v1, ($a1)
/* D9FA0 801438A0 3C03E700 */  lui       $v1, 0xe700
/* D9FA4 801438A4 AC430000 */  sw        $v1, ($v0)
/* D9FA8 801438A8 24430010 */  addiu     $v1, $v0, 0x10
/* D9FAC 801438AC AC400004 */  sw        $zero, 4($v0)
/* D9FB0 801438B0 ACA30000 */  sw        $v1, ($a1)
/* D9FB4 801438B4 24430018 */  addiu     $v1, $v0, 0x18
/* D9FB8 801438B8 AC470008 */  sw        $a3, 8($v0)
/* D9FBC 801438BC AC40000C */  sw        $zero, 0xc($v0)
/* D9FC0 801438C0 ACA30000 */  sw        $v1, ($a1)
/* D9FC4 801438C4 24430020 */  addiu     $v1, $v0, 0x20
/* D9FC8 801438C8 AC490010 */  sw        $t1, 0x10($v0)
/* D9FCC 801438CC AC480014 */  sw        $t0, 0x14($v0)
/* D9FD0 801438D0 ACA30000 */  sw        $v1, ($a1)
/* D9FD4 801438D4 3C03DB02 */  lui       $v1, 0xdb02
/* D9FD8 801438D8 AC430018 */  sw        $v1, 0x18($v0)
/* D9FDC 801438DC 24030018 */  addiu     $v1, $zero, 0x18
/* D9FE0 801438E0 AC43001C */  sw        $v1, 0x1c($v0)
/* D9FE4 801438E4 24430028 */  addiu     $v1, $v0, 0x28
/* D9FE8 801438E8 3C048015 */  lui       $a0, %hi(D_8014F110)
/* D9FEC 801438EC 2484F110 */  addiu     $a0, $a0, %lo(D_8014F110)
/* D9FF0 801438F0 ACA30000 */  sw        $v1, ($a1)
/* D9FF4 801438F4 24430030 */  addiu     $v1, $v0, 0x30
/* D9FF8 801438F8 AC440024 */  sw        $a0, 0x24($v0)
/* D9FFC 801438FC 2484FFF8 */  addiu     $a0, $a0, -8
/* DA000 80143900 AC4A0020 */  sw        $t2, 0x20($v0)
/* DA004 80143904 ACA30000 */  sw        $v1, ($a1)
/* DA008 80143908 24430038 */  addiu     $v1, $v0, 0x38
/* DA00C 8014390C AC4B0028 */  sw        $t3, 0x28($v0)
/* DA010 80143910 AC44002C */  sw        $a0, 0x2c($v0)
/* DA014 80143914 ACA30000 */  sw        $v1, ($a1)
/* DA018 80143918 2403FFFF */  addiu     $v1, $zero, -1
/* DA01C 8014391C AC430034 */  sw        $v1, 0x34($v0)
/* DA020 80143920 24430040 */  addiu     $v1, $v0, 0x40
/* DA024 80143924 AC4C0030 */  sw        $t4, 0x30($v0)
/* DA028 80143928 ACA30000 */  sw        $v1, ($a1)
/* DA02C 8014392C 24430048 */  addiu     $v1, $v0, 0x48
/* DA030 80143930 AC4D0038 */  sw        $t5, 0x38($v0)
/* DA034 80143934 AC40003C */  sw        $zero, 0x3c($v0)
/* DA038 80143938 ACA30000 */  sw        $v1, ($a1)
/* DA03C 8014393C AC4F0040 */  sw        $t7, 0x40($v0)
/* DA040 80143940 1A40000E */  blez      $s2, .L8014397C
/* DA044 80143944 AC4E0044 */   sw       $t6, 0x44($v0)
/* DA048 80143948 27B00010 */  addiu     $s0, $sp, 0x10
.L8014394C:
/* DA04C 8014394C 8E020000 */  lw        $v0, ($s0)
/* DA050 80143950 26100004 */  addiu     $s0, $s0, 4
/* DA054 80143954 3C038015 */  lui       $v1, %hi(gHudElementList)
/* DA058 80143958 8C637960 */  lw        $v1, %lo(gHudElementList)($v1)
/* DA05C 8014395C 00021080 */  sll       $v0, $v0, 2
/* DA060 80143960 00431021 */  addu      $v0, $v0, $v1
/* DA064 80143964 8C440000 */  lw        $a0, ($v0)
/* DA068 80143968 0C050AFF */  jal       render_menu_icon
/* DA06C 8014396C 26310001 */   addiu    $s1, $s1, 1
/* DA070 80143970 0232102A */  slt       $v0, $s1, $s2
/* DA074 80143974 1440FFF5 */  bnez      $v0, .L8014394C
/* DA078 80143978 00000000 */   nop
.L8014397C:
/* DA07C 8014397C 3C03800A */  lui       $v1, %hi(gCurrentCamID)
/* DA080 80143980 8463A634 */  lh        $v1, %lo(gCurrentCamID)($v1)
.L80143984:
/* DA084 80143984 24020001 */  addiu     $v0, $zero, 1
/* DA088 80143988 146200A9 */  bne       $v1, $v0, .L80143C30
/* DA08C 8014398C 0000902D */   daddu    $s2, $zero, $zero
/* DA090 80143990 0240882D */  daddu     $s1, $s2, $zero
/* DA094 80143994 3C091020 */  lui       $t1, 0x1020
/* DA098 80143998 3C080001 */  lui       $t0, 1
/* DA09C 8014399C 3C074000 */  lui       $a3, 0x4000
/* DA0A0 801439A0 3C068015 */  lui       $a2, %hi(gHudElementList)
/* DA0A4 801439A4 8CC67960 */  lw        $a2, %lo(gHudElementList)($a2)
/* DA0A8 801439A8 27A50010 */  addiu     $a1, $sp, 0x10
.L801439AC:
/* DA0AC 801439AC 8CC40000 */  lw        $a0, ($a2)
/* DA0B0 801439B0 5080001D */  beql      $a0, $zero, .L80143A28
/* DA0B4 801439B4 26310001 */   addiu    $s1, $s1, 1
/* DA0B8 801439B8 8C830000 */  lw        $v1, ($a0)
/* DA0BC 801439BC 5060001A */  beql      $v1, $zero, .L80143A28
/* DA0C0 801439C0 26310001 */   addiu    $s1, $s1, 1
/* DA0C4 801439C4 30620002 */  andi      $v0, $v1, 2
/* DA0C8 801439C8 54400017 */  bnel      $v0, $zero, .L80143A28
/* DA0CC 801439CC 26310001 */   addiu    $s1, $s1, 1
/* DA0D0 801439D0 00691024 */  and       $v0, $v1, $t1
/* DA0D4 801439D4 54400014 */  bnel      $v0, $zero, .L80143A28
/* DA0D8 801439D8 26310001 */   addiu    $s1, $s1, 1
/* DA0DC 801439DC 00681024 */  and       $v0, $v1, $t0
/* DA0E0 801439E0 50400011 */  beql      $v0, $zero, .L80143A28
/* DA0E4 801439E4 26310001 */   addiu    $s1, $s1, 1
/* DA0E8 801439E8 00671024 */  and       $v0, $v1, $a3
/* DA0EC 801439EC 5040000E */  beql      $v0, $zero, .L80143A28
/* DA0F0 801439F0 26310001 */   addiu    $s1, $s1, 1
/* DA0F4 801439F4 30620040 */  andi      $v0, $v1, 0x40
/* DA0F8 801439F8 5440000B */  bnel      $v0, $zero, .L80143A28
/* DA0FC 801439FC 26310001 */   addiu    $s1, $s1, 1
/* DA100 80143A00 80820045 */  lb        $v0, 0x45($a0)
/* DA104 80143A04 04420008 */  bltzl     $v0, .L80143A28
/* DA108 80143A08 26310001 */   addiu    $s1, $s1, 1
/* DA10C 80143A0C 30620080 */  andi      $v0, $v1, 0x80
/* DA110 80143A10 54400005 */  bnel      $v0, $zero, .L80143A28
/* DA114 80143A14 26310001 */   addiu    $s1, $s1, 1
/* DA118 80143A18 ACB10000 */  sw        $s1, ($a1)
/* DA11C 80143A1C 24A50004 */  addiu     $a1, $a1, 4
/* DA120 80143A20 26520001 */  addiu     $s2, $s2, 1
/* DA124 80143A24 26310001 */  addiu     $s1, $s1, 1
.L80143A28:
/* DA128 80143A28 2A220140 */  slti      $v0, $s1, 0x140
/* DA12C 80143A2C 1440FFDF */  bnez      $v0, .L801439AC
/* DA130 80143A30 24C60004 */   addiu    $a2, $a2, 4
/* DA134 80143A34 1240007E */  beqz      $s2, .L80143C30
/* DA138 80143A38 2642FFFF */   addiu    $v0, $s2, -1
/* DA13C 80143A3C 18400024 */  blez      $v0, .L80143AD0
/* DA140 80143A40 0000882D */   daddu    $s1, $zero, $zero
/* DA144 80143A44 3C0C8015 */  lui       $t4, %hi(gHudElementList)
/* DA148 80143A48 258C7960 */  addiu     $t4, $t4, %lo(gHudElementList)
/* DA14C 80143A4C 27AB0010 */  addiu     $t3, $sp, 0x10
/* DA150 80143A50 0160502D */  daddu     $t2, $t3, $zero
.L80143A54:
/* DA154 80143A54 26240001 */  addiu     $a0, $s1, 1
/* DA158 80143A58 0092102A */  slt       $v0, $a0, $s2
/* DA15C 80143A5C 50400018 */  beql      $v0, $zero, .L80143AC0
/* DA160 80143A60 26310001 */   addiu    $s1, $s1, 1
/* DA164 80143A64 0140482D */  daddu     $t1, $t2, $zero
/* DA168 80143A68 8D880000 */  lw        $t0, ($t4)
/* DA16C 80143A6C 00041080 */  sll       $v0, $a0, 2
/* DA170 80143A70 004B2821 */  addu      $a1, $v0, $t3
.L80143A74:
/* DA174 80143A74 8D270000 */  lw        $a3, ($t1)
/* DA178 80143A78 8CA60000 */  lw        $a2, ($a1)
/* DA17C 80143A7C 00071080 */  sll       $v0, $a3, 2
/* DA180 80143A80 00481021 */  addu      $v0, $v0, $t0
/* DA184 80143A84 8C430000 */  lw        $v1, ($v0)
/* DA188 80143A88 00061080 */  sll       $v0, $a2, 2
/* DA18C 80143A8C 00481021 */  addu      $v0, $v0, $t0
/* DA190 80143A90 8C420000 */  lw        $v0, ($v0)
/* DA194 80143A94 80630044 */  lb        $v1, 0x44($v1)
/* DA198 80143A98 80420044 */  lb        $v0, 0x44($v0)
/* DA19C 80143A9C 0062182A */  slt       $v1, $v1, $v0
/* DA1A0 80143AA0 10600003 */  beqz      $v1, .L80143AB0
/* DA1A4 80143AA4 24840001 */   addiu    $a0, $a0, 1
/* DA1A8 80143AA8 AD260000 */  sw        $a2, ($t1)
/* DA1AC 80143AAC ACA70000 */  sw        $a3, ($a1)
.L80143AB0:
/* DA1B0 80143AB0 0092102A */  slt       $v0, $a0, $s2
/* DA1B4 80143AB4 1440FFEF */  bnez      $v0, .L80143A74
/* DA1B8 80143AB8 24A50004 */   addiu    $a1, $a1, 4
/* DA1BC 80143ABC 26310001 */  addiu     $s1, $s1, 1
.L80143AC0:
/* DA1C0 80143AC0 2642FFFF */  addiu     $v0, $s2, -1
/* DA1C4 80143AC4 0222102A */  slt       $v0, $s1, $v0
/* DA1C8 80143AC8 1440FFE2 */  bnez      $v0, .L80143A54
/* DA1CC 80143ACC 254A0004 */   addiu    $t2, $t2, 4
.L80143AD0:
/* DA1D0 80143AD0 3C06ED03 */  lui       $a2, 0xed03
/* DA1D4 80143AD4 34C60050 */  ori       $a2, $a2, 0x50
/* DA1D8 80143AD8 3C04004D */  lui       $a0, 0x4d
/* DA1DC 80143ADC 34840370 */  ori       $a0, $a0, 0x370
/* DA1E0 80143AE0 3C07D9C0 */  lui       $a3, 0xd9c0
/* DA1E4 80143AE4 34E7F9FA */  ori       $a3, $a3, 0xf9fa
/* DA1E8 80143AE8 3C09D9FF */  lui       $t1, 0xd9ff
/* DA1EC 80143AEC 3529FFFF */  ori       $t1, $t1, 0xffff
/* DA1F0 80143AF0 3C080022 */  lui       $t0, 0x22
/* DA1F4 80143AF4 35080005 */  ori       $t0, $t0, 5
/* DA1F8 80143AF8 3C0ADC08 */  lui       $t2, 0xdc08
/* DA1FC 80143AFC 354A060A */  ori       $t2, $t2, 0x60a
/* DA200 80143B00 3C0BDC08 */  lui       $t3, 0xdc08
/* DA204 80143B04 356B090A */  ori       $t3, $t3, 0x90a
/* DA208 80143B08 3C0CD700 */  lui       $t4, 0xd700
/* DA20C 80143B0C 358C0002 */  ori       $t4, $t4, 2
/* DA210 80143B10 3C0DE200 */  lui       $t5, 0xe200
/* DA214 80143B14 35AD1E01 */  ori       $t5, $t5, 0x1e01
/* DA218 80143B18 3C0FE300 */  lui       $t7, 0xe300
/* DA21C 80143B1C 35EF0A11 */  ori       $t7, $t7, 0xa11
/* DA220 80143B20 3C0E0008 */  lui       $t6, 8
/* DA224 80143B24 35CE2CF0 */  ori       $t6, $t6, 0x2cf0
/* DA228 80143B28 3C05800A */  lui       $a1, %hi(gMasterGfxPos)
/* DA22C 80143B2C 24A5A66C */  addiu     $a1, $a1, %lo(gMasterGfxPos)
/* DA230 80143B30 8CA20000 */  lw        $v0, ($a1)
/* DA234 80143B34 0000882D */  daddu     $s1, $zero, $zero
/* DA238 80143B38 0040182D */  daddu     $v1, $v0, $zero
/* DA23C 80143B3C 24420008 */  addiu     $v0, $v0, 8
/* DA240 80143B40 ACA20000 */  sw        $v0, ($a1)
/* DA244 80143B44 AC660000 */  sw        $a2, ($v1)
/* DA248 80143B48 AC640004 */  sw        $a0, 4($v1)
/* DA24C 80143B4C 24430008 */  addiu     $v1, $v0, 8
/* DA250 80143B50 ACA30000 */  sw        $v1, ($a1)
/* DA254 80143B54 3C03E700 */  lui       $v1, 0xe700
/* DA258 80143B58 AC430000 */  sw        $v1, ($v0)
/* DA25C 80143B5C 24430010 */  addiu     $v1, $v0, 0x10
/* DA260 80143B60 AC400004 */  sw        $zero, 4($v0)
/* DA264 80143B64 ACA30000 */  sw        $v1, ($a1)
/* DA268 80143B68 24430018 */  addiu     $v1, $v0, 0x18
/* DA26C 80143B6C AC470008 */  sw        $a3, 8($v0)
/* DA270 80143B70 AC40000C */  sw        $zero, 0xc($v0)
/* DA274 80143B74 ACA30000 */  sw        $v1, ($a1)
/* DA278 80143B78 24430020 */  addiu     $v1, $v0, 0x20
/* DA27C 80143B7C AC490010 */  sw        $t1, 0x10($v0)
/* DA280 80143B80 AC480014 */  sw        $t0, 0x14($v0)
/* DA284 80143B84 ACA30000 */  sw        $v1, ($a1)
/* DA288 80143B88 3C03DB02 */  lui       $v1, 0xdb02
/* DA28C 80143B8C AC430018 */  sw        $v1, 0x18($v0)
/* DA290 80143B90 24030018 */  addiu     $v1, $zero, 0x18
/* DA294 80143B94 AC43001C */  sw        $v1, 0x1c($v0)
/* DA298 80143B98 24430028 */  addiu     $v1, $v0, 0x28
/* DA29C 80143B9C 3C048015 */  lui       $a0, %hi(D_8014F110)
/* DA2A0 80143BA0 2484F110 */  addiu     $a0, $a0, %lo(D_8014F110)
/* DA2A4 80143BA4 ACA30000 */  sw        $v1, ($a1)
/* DA2A8 80143BA8 24430030 */  addiu     $v1, $v0, 0x30
/* DA2AC 80143BAC AC440024 */  sw        $a0, 0x24($v0)
/* DA2B0 80143BB0 2484FFF8 */  addiu     $a0, $a0, -8
/* DA2B4 80143BB4 AC4A0020 */  sw        $t2, 0x20($v0)
/* DA2B8 80143BB8 ACA30000 */  sw        $v1, ($a1)
/* DA2BC 80143BBC 24430038 */  addiu     $v1, $v0, 0x38
/* DA2C0 80143BC0 AC4B0028 */  sw        $t3, 0x28($v0)
/* DA2C4 80143BC4 AC44002C */  sw        $a0, 0x2c($v0)
/* DA2C8 80143BC8 ACA30000 */  sw        $v1, ($a1)
/* DA2CC 80143BCC 2403FFFF */  addiu     $v1, $zero, -1
/* DA2D0 80143BD0 AC430034 */  sw        $v1, 0x34($v0)
/* DA2D4 80143BD4 24430040 */  addiu     $v1, $v0, 0x40
/* DA2D8 80143BD8 AC4C0030 */  sw        $t4, 0x30($v0)
/* DA2DC 80143BDC ACA30000 */  sw        $v1, ($a1)
/* DA2E0 80143BE0 24430048 */  addiu     $v1, $v0, 0x48
/* DA2E4 80143BE4 AC4D0038 */  sw        $t5, 0x38($v0)
/* DA2E8 80143BE8 AC40003C */  sw        $zero, 0x3c($v0)
/* DA2EC 80143BEC ACA30000 */  sw        $v1, ($a1)
/* DA2F0 80143BF0 AC4F0040 */  sw        $t7, 0x40($v0)
/* DA2F4 80143BF4 1A40000E */  blez      $s2, .L80143C30
/* DA2F8 80143BF8 AC4E0044 */   sw       $t6, 0x44($v0)
/* DA2FC 80143BFC 27B00010 */  addiu     $s0, $sp, 0x10
.L80143C00:
/* DA300 80143C00 8E020000 */  lw        $v0, ($s0)
/* DA304 80143C04 26100004 */  addiu     $s0, $s0, 4
/* DA308 80143C08 3C038015 */  lui       $v1, %hi(gHudElementList)
/* DA30C 80143C0C 8C637960 */  lw        $v1, %lo(gHudElementList)($v1)
/* DA310 80143C10 00021080 */  sll       $v0, $v0, 2
/* DA314 80143C14 00431021 */  addu      $v0, $v0, $v1
/* DA318 80143C18 8C440000 */  lw        $a0, ($v0)
/* DA31C 80143C1C 0C050AFF */  jal       render_menu_icon
/* DA320 80143C20 26310001 */   addiu    $s1, $s1, 1
/* DA324 80143C24 0232102A */  slt       $v0, $s1, $s2
/* DA328 80143C28 1440FFF5 */  bnez      $v0, .L80143C00
/* DA32C 80143C2C 00000000 */   nop
.L80143C30:
/* DA330 80143C30 8FBF051C */  lw        $ra, 0x51c($sp)
/* DA334 80143C34 8FB20518 */  lw        $s2, 0x518($sp)
/* DA338 80143C38 8FB10514 */  lw        $s1, 0x514($sp)
/* DA33C 80143C3C 8FB00510 */  lw        $s0, 0x510($sp)
/* DA340 80143C40 03E00008 */  jr        $ra
/* DA344 80143C44 27BD0520 */   addiu    $sp, $sp, 0x520
