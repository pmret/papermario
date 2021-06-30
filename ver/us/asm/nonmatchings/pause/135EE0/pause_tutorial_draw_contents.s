.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel pause_tutorial_draw_contents
/* 136B34 802437F4 27BDFEE0 */  addiu     $sp, $sp, -0x120
/* 136B38 802437F8 0000202D */  daddu     $a0, $zero, $zero
/* 136B3C 802437FC AFA50124 */  sw        $a1, 0x124($sp)
/* 136B40 80243800 3C05F840 */  lui       $a1, 0xf840
/* 136B44 80243804 34A55BDE */  ori       $a1, $a1, 0x5bde
/* 136B48 80243808 AFBF00FC */  sw        $ra, 0xfc($sp)
/* 136B4C 8024380C AFBE00F8 */  sw        $fp, 0xf8($sp)
/* 136B50 80243810 AFB700F4 */  sw        $s7, 0xf4($sp)
/* 136B54 80243814 AFB600F0 */  sw        $s6, 0xf0($sp)
/* 136B58 80243818 AFB500EC */  sw        $s5, 0xec($sp)
/* 136B5C 8024381C AFB400E8 */  sw        $s4, 0xe8($sp)
/* 136B60 80243820 AFB300E4 */  sw        $s3, 0xe4($sp)
/* 136B64 80243824 AFB200E0 */  sw        $s2, 0xe0($sp)
/* 136B68 80243828 AFB100DC */  sw        $s1, 0xdc($sp)
/* 136B6C 8024382C AFB000D8 */  sw        $s0, 0xd8($sp)
/* 136B70 80243830 F7BA0118 */  sdc1      $f26, 0x118($sp)
/* 136B74 80243834 F7B80110 */  sdc1      $f24, 0x110($sp)
/* 136B78 80243838 F7B60108 */  sdc1      $f22, 0x108($sp)
/* 136B7C 8024383C F7B40100 */  sdc1      $f20, 0x100($sp)
/* 136B80 80243840 AFA60128 */  sw        $a2, 0x128($sp)
/* 136B84 80243844 0C0B1EAF */  jal       get_variable
/* 136B88 80243848 AFA7012C */   sw       $a3, 0x12c($sp)
/* 136B8C 8024384C 104001F4 */  beqz      $v0, .L80244020
/* 136B90 80243850 3C08E300 */   lui      $t0, 0xe300
/* 136B94 80243854 35080A01 */  ori       $t0, $t0, 0xa01
/* 136B98 80243858 3C0BE200 */  lui       $t3, 0xe200
/* 136B9C 8024385C 356B001C */  ori       $t3, $t3, 0x1c
/* 136BA0 80243860 3C090050 */  lui       $t1, 0x50
/* 136BA4 80243864 35294340 */  ori       $t1, $t1, 0x4340
/* 136BA8 80243868 3C0CFCFF */  lui       $t4, 0xfcff
/* 136BAC 8024386C 358CFFFF */  ori       $t4, $t4, 0xffff
/* 136BB0 80243870 3C0AFFFD */  lui       $t2, 0xfffd
/* 136BB4 80243874 354AF6FB */  ori       $t2, $t2, 0xf6fb
/* 136BB8 80243878 3C0D3737 */  lui       $t5, 0x3737
/* 136BBC 8024387C 35AD37FF */  ori       $t5, $t5, 0x37ff
/* 136BC0 80243880 3C140001 */  lui       $s4, 1
/* 136BC4 80243884 36941630 */  ori       $s4, $s4, 0x1630
/* 136BC8 80243888 0000B82D */  daddu     $s7, $zero, $zero
/* 136BCC 8024388C 27B50068 */  addiu     $s5, $sp, 0x68
/* 136BD0 80243890 3C028007 */  lui       $v0, %hi(gMatrixListPos)
/* 136BD4 80243894 244241F0 */  addiu     $v0, $v0, %lo(gMatrixListPos)
/* 136BD8 80243898 0040F02D */  daddu     $fp, $v0, $zero
/* 136BDC 8024389C 3C02800A */  lui       $v0, %hi(gMasterGfxPos)
/* 136BE0 802438A0 2442A66C */  addiu     $v0, $v0, %lo(gMasterGfxPos)
/* 136BE4 802438A4 0040B02D */  daddu     $s6, $v0, $zero
/* 136BE8 802438A8 3C12FA00 */  lui       $s2, 0xfa00
/* 136BEC 802438AC 8FAE0124 */  lw        $t6, 0x124($sp)
/* 136BF0 802438B0 8FAF0128 */  lw        $t7, 0x128($sp)
/* 136BF4 802438B4 3C013F4C */  lui       $at, 0x3f4c
/* 136BF8 802438B8 3421CCCD */  ori       $at, $at, 0xcccd
/* 136BFC 802438BC 4481D000 */  mtc1      $at, $f26
/* 136C00 802438C0 3C014334 */  lui       $at, 0x4334
/* 136C04 802438C4 4481C000 */  mtc1      $at, $f24
/* 136C08 802438C8 000E9880 */  sll       $s3, $t6, 2
/* 136C0C 802438CC 000F2880 */  sll       $a1, $t7, 2
/* 136C10 802438D0 8FAF012C */  lw        $t7, 0x12c($sp)
/* 136C14 802438D4 0260202D */  daddu     $a0, $s3, $zero
/* 136C18 802438D8 01CF8821 */  addu      $s1, $t6, $t7
/* 136C1C 802438DC 00118880 */  sll       $s1, $s1, 2
/* 136C20 802438E0 0220302D */  daddu     $a2, $s1, $zero
/* 136C24 802438E4 3C0F0001 */  lui       $t7, 1
/* 136C28 802438E8 8FAE0128 */  lw        $t6, 0x128($sp)
/* 136C2C 802438EC 35EF1630 */  ori       $t7, $t7, 0x1630
/* 136C30 802438F0 AFAF00D0 */  sw        $t7, 0xd0($sp)
/* 136C34 802438F4 8EC20000 */  lw        $v0, ($s6)
/* 136C38 802438F8 25D0000C */  addiu     $s0, $t6, 0xc
/* 136C3C 802438FC 00108080 */  sll       $s0, $s0, 2
/* 136C40 80243900 0200382D */  daddu     $a3, $s0, $zero
/* 136C44 80243904 0040182D */  daddu     $v1, $v0, $zero
/* 136C48 80243908 24420008 */  addiu     $v0, $v0, 8
/* 136C4C 8024390C AEC20000 */  sw        $v0, ($s6)
/* 136C50 80243910 AC680000 */  sw        $t0, ($v1)
/* 136C54 80243914 AC600004 */  sw        $zero, 4($v1)
/* 136C58 80243918 24430008 */  addiu     $v1, $v0, 8
/* 136C5C 8024391C AEC30000 */  sw        $v1, ($s6)
/* 136C60 80243920 24430010 */  addiu     $v1, $v0, 0x10
/* 136C64 80243924 AC4B0000 */  sw        $t3, ($v0)
/* 136C68 80243928 AC490004 */  sw        $t1, 4($v0)
/* 136C6C 8024392C AEC30000 */  sw        $v1, ($s6)
/* 136C70 80243930 24430018 */  addiu     $v1, $v0, 0x18
/* 136C74 80243934 AC4C0008 */  sw        $t4, 8($v0)
/* 136C78 80243938 AC4A000C */  sw        $t2, 0xc($v0)
/* 136C7C 8024393C AEC30000 */  sw        $v1, ($s6)
/* 136C80 80243940 AC520010 */  sw        $s2, 0x10($v0)
/* 136C84 80243944 AC4D0014 */  sw        $t5, 0x14($v0)
/* 136C88 80243948 AFA00010 */  sw        $zero, 0x10($sp)
/* 136C8C 8024394C AFA00014 */  sw        $zero, 0x14($sp)
/* 136C90 80243950 AFA00018 */  sw        $zero, 0x18($sp)
/* 136C94 80243954 AFA0001C */  sw        $zero, 0x1c($sp)
/* 136C98 80243958 0C091216 */  jal       pause_draw_rect
/* 136C9C 8024395C AFA00020 */   sw       $zero, 0x20($sp)
/* 136CA0 80243960 3C08B9B9 */  lui       $t0, 0xb9b9
/* 136CA4 80243964 3508B9FF */  ori       $t0, $t0, 0xb9ff
/* 136CA8 80243968 0260202D */  daddu     $a0, $s3, $zero
/* 136CAC 8024396C 0200282D */  daddu     $a1, $s0, $zero
/* 136CB0 80243970 0220302D */  daddu     $a2, $s1, $zero
/* 136CB4 80243974 3C10E700 */  lui       $s0, 0xe700
/* 136CB8 80243978 8FAE0128 */  lw        $t6, 0x128($sp)
/* 136CBC 8024397C 8FAF0130 */  lw        $t7, 0x130($sp)
/* 136CC0 80243980 44800000 */  mtc1      $zero, $f0
/* 136CC4 80243984 8EC20000 */  lw        $v0, ($s6)
/* 136CC8 80243988 01CF3821 */  addu      $a3, $t6, $t7
/* 136CCC 8024398C 00073880 */  sll       $a3, $a3, 2
/* 136CD0 80243990 46000506 */  mov.s     $f20, $f0
/* 136CD4 80243994 0040182D */  daddu     $v1, $v0, $zero
/* 136CD8 80243998 3C013F80 */  lui       $at, 0x3f80
/* 136CDC 8024399C 44810000 */  mtc1      $at, $f0
/* 136CE0 802439A0 24420008 */  addiu     $v0, $v0, 8
/* 136CE4 802439A4 AEC20000 */  sw        $v0, ($s6)
/* 136CE8 802439A8 AC700000 */  sw        $s0, ($v1)
/* 136CEC 802439AC AC600004 */  sw        $zero, 4($v1)
/* 136CF0 802439B0 24430008 */  addiu     $v1, $v0, 8
/* 136CF4 802439B4 AEC30000 */  sw        $v1, ($s6)
/* 136CF8 802439B8 AC520000 */  sw        $s2, ($v0)
/* 136CFC 802439BC AC480004 */  sw        $t0, 4($v0)
/* 136D00 802439C0 AFA00010 */  sw        $zero, 0x10($sp)
/* 136D04 802439C4 AFA00014 */  sw        $zero, 0x14($sp)
/* 136D08 802439C8 AFA00018 */  sw        $zero, 0x18($sp)
/* 136D0C 802439CC AFA0001C */  sw        $zero, 0x1c($sp)
/* 136D10 802439D0 AFA00020 */  sw        $zero, 0x20($sp)
/* 136D14 802439D4 0C091216 */  jal       pause_draw_rect
/* 136D18 802439D8 46000586 */   mov.s    $f22, $f0
/* 136D1C 802439DC 3C08DC08 */  lui       $t0, 0xdc08
/* 136D20 802439E0 35080008 */  ori       $t0, $t0, 8
/* 136D24 802439E4 27A40028 */  addiu     $a0, $sp, 0x28
/* 136D28 802439E8 8EC30000 */  lw        $v1, ($s6)
/* 136D2C 802439EC 4405A000 */  mfc1      $a1, $f20
/* 136D30 802439F0 3C0643A0 */  lui       $a2, 0x43a0
/* 136D34 802439F4 3C074370 */  lui       $a3, 0x4370
/* 136D38 802439F8 3C01C2C8 */  lui       $at, 0xc2c8
/* 136D3C 802439FC 44810000 */  mtc1      $at, $f0
/* 136D40 80243A00 3C0142C8 */  lui       $at, 0x42c8
/* 136D44 80243A04 44811000 */  mtc1      $at, $f2
/* 136D48 80243A08 0060102D */  daddu     $v0, $v1, $zero
/* 136D4C 80243A0C 24630008 */  addiu     $v1, $v1, 8
/* 136D50 80243A10 AEC30000 */  sw        $v1, ($s6)
/* 136D54 80243A14 AC500000 */  sw        $s0, ($v0)
/* 136D58 80243A18 AC400004 */  sw        $zero, 4($v0)
/* 136D5C 80243A1C 24620008 */  addiu     $v0, $v1, 8
/* 136D60 80243A20 AEC20000 */  sw        $v0, ($s6)
/* 136D64 80243A24 3C028025 */  lui       $v0, %hi(D_8024F100)
/* 136D68 80243A28 2442F100 */  addiu     $v0, $v0, %lo(D_8024F100)
/* 136D6C 80243A2C AC680000 */  sw        $t0, ($v1)
/* 136D70 80243A30 AC620004 */  sw        $v0, 4($v1)
/* 136D74 80243A34 E7B40010 */  swc1      $f20, 0x10($sp)
/* 136D78 80243A38 E7A00014 */  swc1      $f0, 0x14($sp)
/* 136D7C 80243A3C E7A20018 */  swc1      $f2, 0x18($sp)
/* 136D80 80243A40 0C018E44 */  jal       guOrthoF
/* 136D84 80243A44 E7B6001C */   swc1     $f22, 0x1c($sp)
/* 136D88 80243A48 27A40028 */  addiu     $a0, $sp, 0x28
/* 136D8C 80243A4C 97C50000 */  lhu       $a1, ($fp)
/* 136D90 80243A50 3C02800A */  lui       $v0, %hi(gDisplayContext)
/* 136D94 80243A54 8C42A674 */  lw        $v0, %lo(gDisplayContext)($v0)
/* 136D98 80243A58 00052980 */  sll       $a1, $a1, 6
/* 136D9C 80243A5C 00B42821 */  addu      $a1, $a1, $s4
/* 136DA0 80243A60 0C019D40 */  jal       guMtxF2L
/* 136DA4 80243A64 00452821 */   addu     $a1, $v0, $a1
/* 136DA8 80243A68 3C04DA38 */  lui       $a0, 0xda38
/* 136DAC 80243A6C 34840007 */  ori       $a0, $a0, 7
/* 136DB0 80243A70 8EC30000 */  lw        $v1, ($s6)
/* 136DB4 80243A74 97C20000 */  lhu       $v0, ($fp)
/* 136DB8 80243A78 0060282D */  daddu     $a1, $v1, $zero
/* 136DBC 80243A7C 24630008 */  addiu     $v1, $v1, 8
/* 136DC0 80243A80 AEC30000 */  sw        $v1, ($s6)
/* 136DC4 80243A84 24430001 */  addiu     $v1, $v0, 1
/* 136DC8 80243A88 3042FFFF */  andi      $v0, $v0, 0xffff
/* 136DCC 80243A8C 00021180 */  sll       $v0, $v0, 6
/* 136DD0 80243A90 ACA40000 */  sw        $a0, ($a1)
/* 136DD4 80243A94 A7C30000 */  sh        $v1, ($fp)
/* 136DD8 80243A98 3C03800A */  lui       $v1, %hi(gDisplayContext)
/* 136DDC 80243A9C 8C63A674 */  lw        $v1, %lo(gDisplayContext)($v1)
/* 136DE0 80243AA0 00541021 */  addu      $v0, $v0, $s4
/* 136DE4 80243AA4 00621821 */  addu      $v1, $v1, $v0
/* 136DE8 80243AA8 ACA30004 */  sw        $v1, 4($a1)
.L80243AAC:
/* 136DEC 80243AAC 12E00005 */  beqz      $s7, .L80243AC4
/* 136DF0 80243AB0 24020001 */   addiu    $v0, $zero, 1
/* 136DF4 80243AB4 12E2000B */  beq       $s7, $v0, .L80243AE4
/* 136DF8 80243AB8 27A40028 */   addiu    $a0, $sp, 0x28
/* 136DFC 80243ABC 08090EC0 */  j         .L80243B00
/* 136E00 80243AC0 00000000 */   nop
.L80243AC4:
/* 136E04 80243AC4 27A40028 */  addiu     $a0, $sp, 0x28
/* 136E08 80243AC8 3C054220 */  lui       $a1, 0x4220
/* 136E0C 80243ACC 3C06435F */  lui       $a2, 0x435f
/* 136E10 80243AD0 0C019E40 */  jal       guTranslateF
/* 136E14 80243AD4 0000382D */   daddu    $a3, $zero, $zero
/* 136E18 80243AD8 3C05BF4C */  lui       $a1, 0xbf4c
/* 136E1C 80243ADC 08090EC5 */  j         .L80243B14
/* 136E20 80243AE0 34A5CCCD */   ori      $a1, $a1, 0xcccd
.L80243AE4:
/* 136E24 80243AE4 3C054270 */  lui       $a1, 0x4270
/* 136E28 80243AE8 3C06435F */  lui       $a2, 0x435f
/* 136E2C 80243AEC 0C019E40 */  jal       guTranslateF
/* 136E30 80243AF0 0000382D */   daddu    $a3, $zero, $zero
/* 136E34 80243AF4 3C05BF4C */  lui       $a1, 0xbf4c
/* 136E38 80243AF8 08090EC5 */  j         .L80243B14
/* 136E3C 80243AFC 34A5CCCD */   ori      $a1, $a1, 0xcccd
.L80243B00:
/* 136E40 80243B00 3C05438C */  lui       $a1, 0x438c
/* 136E44 80243B04 3C06435F */  lui       $a2, 0x435f
/* 136E48 80243B08 0C019E40 */  jal       guTranslateF
/* 136E4C 80243B0C 0000382D */   daddu    $a3, $zero, $zero
/* 136E50 80243B10 4405D000 */  mfc1      $a1, $f26
.L80243B14:
/* 136E54 80243B14 3C063F4C */  lui       $a2, 0x3f4c
/* 136E58 80243B18 34C6CCCD */  ori       $a2, $a2, 0xcccd
/* 136E5C 80243B1C 3C073F80 */  lui       $a3, 0x3f80
/* 136E60 80243B20 0C019DF0 */  jal       guScaleF
/* 136E64 80243B24 02A0202D */   daddu    $a0, $s5, $zero
/* 136E68 80243B28 02A0202D */  daddu     $a0, $s5, $zero
/* 136E6C 80243B2C 27A50028 */  addiu     $a1, $sp, 0x28
/* 136E70 80243B30 0C019D80 */  jal       guMtxCatF
/* 136E74 80243B34 00A0302D */   daddu    $a2, $a1, $zero
/* 136E78 80243B38 4405C000 */  mfc1      $a1, $f24
/* 136E7C 80243B3C 4406A000 */  mfc1      $a2, $f20
/* 136E80 80243B40 4407A000 */  mfc1      $a3, $f20
/* 136E84 80243B44 02A0202D */  daddu     $a0, $s5, $zero
/* 136E88 80243B48 0C019EC8 */  jal       guRotateF
/* 136E8C 80243B4C E7B60010 */   swc1     $f22, 0x10($sp)
/* 136E90 80243B50 02A0202D */  daddu     $a0, $s5, $zero
/* 136E94 80243B54 27A50028 */  addiu     $a1, $sp, 0x28
/* 136E98 80243B58 0C019D80 */  jal       guMtxCatF
/* 136E9C 80243B5C 00A0302D */   daddu    $a2, $a1, $zero
/* 136EA0 80243B60 4405C000 */  mfc1      $a1, $f24
/* 136EA4 80243B64 4406A000 */  mfc1      $a2, $f20
/* 136EA8 80243B68 4407B000 */  mfc1      $a3, $f22
/* 136EAC 80243B6C 02A0202D */  daddu     $a0, $s5, $zero
/* 136EB0 80243B70 0C019EC8 */  jal       guRotateF
/* 136EB4 80243B74 E7B40010 */   swc1     $f20, 0x10($sp)
/* 136EB8 80243B78 02A0202D */  daddu     $a0, $s5, $zero
/* 136EBC 80243B7C 27A50028 */  addiu     $a1, $sp, 0x28
/* 136EC0 80243B80 0C019D80 */  jal       guMtxCatF
/* 136EC4 80243B84 00A0302D */   daddu    $a2, $a1, $zero
/* 136EC8 80243B88 27A40028 */  addiu     $a0, $sp, 0x28
/* 136ECC 80243B8C 97C50000 */  lhu       $a1, ($fp)
/* 136ED0 80243B90 3C02800A */  lui       $v0, %hi(gDisplayContext)
/* 136ED4 80243B94 8C42A674 */  lw        $v0, %lo(gDisplayContext)($v0)
/* 136ED8 80243B98 8FAE00D0 */  lw        $t6, 0xd0($sp)
/* 136EDC 80243B9C 00052980 */  sll       $a1, $a1, 6
/* 136EE0 80243BA0 00AE2821 */  addu      $a1, $a1, $t6
/* 136EE4 80243BA4 0C019D40 */  jal       guMtxF2L
/* 136EE8 80243BA8 00452821 */   addu     $a1, $v0, $a1
/* 136EEC 80243BAC 3C02DA38 */  lui       $v0, 0xda38
/* 136EF0 80243BB0 34420002 */  ori       $v0, $v0, 2
/* 136EF4 80243BB4 24050006 */  addiu     $a1, $zero, 6
/* 136EF8 80243BB8 240600FF */  addiu     $a2, $zero, 0xff
/* 136EFC 80243BBC 00C0382D */  daddu     $a3, $a2, $zero
/* 136F00 80243BC0 00178080 */  sll       $s0, $s7, 2
/* 136F04 80243BC4 26F70001 */  addiu     $s7, $s7, 1
/* 136F08 80243BC8 8EC80000 */  lw        $t0, ($s6)
/* 136F0C 80243BCC 97C90000 */  lhu       $t1, ($fp)
/* 136F10 80243BD0 3C03800A */  lui       $v1, %hi(gDisplayContext)
/* 136F14 80243BD4 8C63A674 */  lw        $v1, %lo(gDisplayContext)($v1)
/* 136F18 80243BD8 0100202D */  daddu     $a0, $t0, $zero
/* 136F1C 80243BDC AC820000 */  sw        $v0, ($a0)
/* 136F20 80243BE0 3122FFFF */  andi      $v0, $t1, 0xffff
/* 136F24 80243BE4 00A21004 */  sllv      $v0, $v0, $a1
/* 136F28 80243BE8 8FAF00D0 */  lw        $t7, 0xd0($sp)
/* 136F2C 80243BEC 25080008 */  addiu     $t0, $t0, 8
/* 136F30 80243BF0 004F1021 */  addu      $v0, $v0, $t7
/* 136F34 80243BF4 00621821 */  addu      $v1, $v1, $v0
/* 136F38 80243BF8 00C0102D */  daddu     $v0, $a2, $zero
/* 136F3C 80243BFC AC830004 */  sw        $v1, 4($a0)
/* 136F40 80243C00 240E0040 */  addiu     $t6, $zero, 0x40
/* 136F44 80243C04 AFA20010 */  sw        $v0, 0x10($sp)
/* 136F48 80243C08 AFA20014 */  sw        $v0, 0x14($sp)
/* 136F4C 80243C0C 3C028027 */  lui       $v0, %hi(D_8027011C)
/* 136F50 80243C10 2442011C */  addiu     $v0, $v0, %lo(D_8027011C)
/* 136F54 80243C14 02028021 */  addu      $s0, $s0, $v0
/* 136F58 80243C18 AFAE0018 */  sw        $t6, 0x18($sp)
/* 136F5C 80243C1C 8E040000 */  lw        $a0, ($s0)
/* 136F60 80243C20 25290001 */  addiu     $t1, $t1, 1
/* 136F64 80243C24 AEC80000 */  sw        $t0, ($s6)
/* 136F68 80243C28 0C0B7A25 */  jal       func_802DE894
/* 136F6C 80243C2C A7C90000 */   sh       $t1, ($fp)
/* 136F70 80243C30 0000282D */  daddu     $a1, $zero, $zero
/* 136F74 80243C34 00A0302D */  daddu     $a2, $a1, $zero
/* 136F78 80243C38 27A20028 */  addiu     $v0, $sp, 0x28
/* 136F7C 80243C3C AFA20010 */  sw        $v0, 0x10($sp)
/* 136F80 80243C40 8E040000 */  lw        $a0, ($s0)
/* 136F84 80243C44 0C0B78F6 */  jal       spr_draw_npc_sprite
/* 136F88 80243C48 00A0382D */   daddu    $a3, $a1, $zero
/* 136F8C 80243C4C 3C04D838 */  lui       $a0, 0xd838
/* 136F90 80243C50 8EC20000 */  lw        $v0, ($s6)
/* 136F94 80243C54 34840002 */  ori       $a0, $a0, 2
/* 136F98 80243C58 0040182D */  daddu     $v1, $v0, $zero
/* 136F9C 80243C5C 24420008 */  addiu     $v0, $v0, 8
/* 136FA0 80243C60 240F0040 */  addiu     $t7, $zero, 0x40
/* 136FA4 80243C64 AEC20000 */  sw        $v0, ($s6)
/* 136FA8 80243C68 2AE20003 */  slti      $v0, $s7, 3
/* 136FAC 80243C6C AC640000 */  sw        $a0, ($v1)
/* 136FB0 80243C70 1440FF8E */  bnez      $v0, .L80243AAC
/* 136FB4 80243C74 AC6F0004 */   sw       $t7, 4($v1)
/* 136FB8 80243C78 0C093BA0 */  jal       pause_get_menu_string
/* 136FBC 80243C7C 24040001 */   addiu    $a0, $zero, 1
/* 136FC0 80243C80 0040202D */  daddu     $a0, $v0, $zero
/* 136FC4 80243C84 27A500A8 */  addiu     $a1, $sp, 0xa8
/* 136FC8 80243C88 27A600AC */  addiu     $a2, $sp, 0xac
/* 136FCC 80243C8C 27A700B0 */  addiu     $a3, $sp, 0xb0
/* 136FD0 80243C90 27A200B4 */  addiu     $v0, $sp, 0xb4
/* 136FD4 80243C94 AFA20010 */  sw        $v0, 0x10($sp)
/* 136FD8 80243C98 27A200B8 */  addiu     $v0, $sp, 0xb8
/* 136FDC 80243C9C 24140001 */  addiu     $s4, $zero, 1
/* 136FE0 80243CA0 AFA20014 */  sw        $v0, 0x14($sp)
/* 136FE4 80243CA4 AFA00018 */  sw        $zero, 0x18($sp)
/* 136FE8 80243CA8 0C0497DA */  jal       get_string_properties
/* 136FEC 80243CAC AFB4001C */   sw       $s4, 0x1c($sp)
/* 136FF0 80243CB0 8FB000AC */  lw        $s0, 0xac($sp)
/* 136FF4 80243CB4 8FAE012C */  lw        $t6, 0x12c($sp)
/* 136FF8 80243CB8 0280202D */  daddu     $a0, $s4, $zero
/* 136FFC 80243CBC 01D08023 */  subu      $s0, $t6, $s0
/* 137000 80243CC0 0C093BA0 */  jal       pause_get_menu_string
/* 137004 80243CC4 02908007 */   srav     $s0, $s0, $s4
/* 137008 80243CC8 0040202D */  daddu     $a0, $v0, $zero
/* 13700C 80243CCC 8FAF0124 */  lw        $t7, 0x124($sp)
/* 137010 80243CD0 8FA60128 */  lw        $a2, 0x128($sp)
/* 137014 80243CD4 240700FF */  addiu     $a3, $zero, 0xff
/* 137018 80243CD8 AFA00010 */  sw        $zero, 0x10($sp)
/* 13701C 80243CDC AFB40014 */  sw        $s4, 0x14($sp)
/* 137020 80243CE0 0C04993B */  jal       draw_string
/* 137024 80243CE4 01F02821 */   addu     $a1, $t7, $s0
/* 137028 80243CE8 3C158025 */  lui       $s5, %hi(D_8024F018)
/* 13702C 80243CEC 26B5F018 */  addiu     $s5, $s5, %lo(D_8024F018)
/* 137030 80243CF0 8EA20000 */  lw        $v0, ($s5)
/* 137034 80243CF4 3C138025 */  lui       $s3, %hi(D_8024F110)
/* 137038 80243CF8 2673F110 */  addiu     $s3, $s3, %lo(D_8024F110)
/* 13703C 80243CFC 000220C0 */  sll       $a0, $v0, 3
/* 137040 80243D00 00822021 */  addu      $a0, $a0, $v0
/* 137044 80243D04 00042080 */  sll       $a0, $a0, 2
/* 137048 80243D08 00822023 */  subu      $a0, $a0, $v0
/* 13704C 80243D0C 8E620000 */  lw        $v0, ($s3)
/* 137050 80243D10 00042080 */  sll       $a0, $a0, 2
/* 137054 80243D14 0C090D06 */  jal       pause_interp_text_scroll
/* 137058 80243D18 00822023 */   subu     $a0, $a0, $v0
/* 13705C 80243D1C 3C08800A */  lui       $t0, %hi(gMasterGfxPos)
/* 137060 80243D20 2508A66C */  addiu     $t0, $t0, %lo(gMasterGfxPos)
/* 137064 80243D24 8D060000 */  lw        $a2, ($t0)
/* 137068 80243D28 8FAE0124 */  lw        $t6, 0x124($sp)
/* 13706C 80243D2C 3C014080 */  lui       $at, 0x4080
/* 137070 80243D30 44812000 */  mtc1      $at, $f4
/* 137074 80243D34 8FAF0128 */  lw        $t7, 0x128($sp)
/* 137078 80243D38 01D41821 */  addu      $v1, $t6, $s4
/* 13707C 80243D3C 44831000 */  mtc1      $v1, $f2
/* 137080 80243D40 00000000 */  nop
/* 137084 80243D44 468010A0 */  cvt.s.w   $f2, $f2
/* 137088 80243D48 00C0382D */  daddu     $a3, $a2, $zero
/* 13708C 80243D4C 46041082 */  mul.s     $f2, $f2, $f4
/* 137090 80243D50 00000000 */  nop
/* 137094 80243D54 01F41821 */  addu      $v1, $t7, $s4
/* 137098 80243D58 44830000 */  mtc1      $v1, $f0
/* 13709C 80243D5C 00000000 */  nop
/* 1370A0 80243D60 46800020 */  cvt.s.w   $f0, $f0
/* 1370A4 80243D64 24C60008 */  addiu     $a2, $a2, 8
/* 1370A8 80243D68 3C03ED00 */  lui       $v1, 0xed00
/* 1370AC 80243D6C 46040002 */  mul.s     $f0, $f0, $f4
/* 1370B0 80243D70 00000000 */  nop
/* 1370B4 80243D74 8FAF0124 */  lw        $t7, 0x124($sp)
/* 1370B8 80243D78 4600118D */  trunc.w.s $f6, $f2
/* 1370BC 80243D7C 44043000 */  mfc1      $a0, $f6
/* 1370C0 80243D80 00000000 */  nop
/* 1370C4 80243D84 30840FFF */  andi      $a0, $a0, 0xfff
/* 1370C8 80243D88 00042300 */  sll       $a0, $a0, 0xc
/* 1370CC 80243D8C 4600018D */  trunc.w.s $f6, $f0
/* 1370D0 80243D90 44053000 */  mfc1      $a1, $f6
/* 1370D4 80243D94 00000000 */  nop
/* 1370D8 80243D98 30A50FFF */  andi      $a1, $a1, 0xfff
/* 1370DC 80243D9C 8FAE012C */  lw        $t6, 0x12c($sp)
/* 1370E0 80243DA0 00A32825 */  or        $a1, $a1, $v1
/* 1370E4 80243DA4 01EE1821 */  addu      $v1, $t7, $t6
/* 1370E8 80243DA8 2463FFFF */  addiu     $v1, $v1, -1
/* 1370EC 80243DAC 44831000 */  mtc1      $v1, $f2
/* 1370F0 80243DB0 00000000 */  nop
/* 1370F4 80243DB4 468010A0 */  cvt.s.w   $f2, $f2
/* 1370F8 80243DB8 46041082 */  mul.s     $f2, $f2, $f4
/* 1370FC 80243DBC 00000000 */  nop
/* 137100 80243DC0 8FAF0128 */  lw        $t7, 0x128($sp)
/* 137104 80243DC4 8FAE0130 */  lw        $t6, 0x130($sp)
/* 137108 80243DC8 00852025 */  or        $a0, $a0, $a1
/* 13710C 80243DCC 01EE1821 */  addu      $v1, $t7, $t6
/* 137110 80243DD0 2463FFFF */  addiu     $v1, $v1, -1
/* 137114 80243DD4 44830000 */  mtc1      $v1, $f0
/* 137118 80243DD8 00000000 */  nop
/* 13711C 80243DDC 46800020 */  cvt.s.w   $f0, $f0
/* 137120 80243DE0 46040002 */  mul.s     $f0, $f0, $f4
/* 137124 80243DE4 00000000 */  nop
/* 137128 80243DE8 ACE40000 */  sw        $a0, ($a3)
/* 13712C 80243DEC 4600118D */  trunc.w.s $f6, $f2
/* 137130 80243DF0 44033000 */  mfc1      $v1, $f6
/* 137134 80243DF4 00000000 */  nop
/* 137138 80243DF8 30630FFF */  andi      $v1, $v1, 0xfff
/* 13713C 80243DFC 00031B00 */  sll       $v1, $v1, 0xc
/* 137140 80243E00 4600018D */  trunc.w.s $f6, $f0
/* 137144 80243E04 44043000 */  mfc1      $a0, $f6
/* 137148 80243E08 00000000 */  nop
/* 13714C 80243E0C 30840FFF */  andi      $a0, $a0, 0xfff
/* 137150 80243E10 00641825 */  or        $v1, $v1, $a0
/* 137154 80243E14 ACE30004 */  sw        $v1, 4($a3)
/* 137158 80243E18 8EB20000 */  lw        $s2, ($s5)
/* 13715C 80243E1C 3C038025 */  lui       $v1, %hi(D_8024F03C)
/* 137160 80243E20 2463F03C */  addiu     $v1, $v1, %lo(D_8024F03C)
/* 137164 80243E24 00128880 */  sll       $s1, $s2, 2
/* 137168 80243E28 02238821 */  addu      $s1, $s1, $v1
/* 13716C 80243E2C 8E630000 */  lw        $v1, ($s3)
/* 137170 80243E30 8E240000 */  lw        $a0, ($s1)
/* 137174 80243E34 00621821 */  addu      $v1, $v1, $v0
/* 137178 80243E38 AE630000 */  sw        $v1, ($s3)
/* 13717C 80243E3C 0C093BA0 */  jal       pause_get_menu_string
/* 137180 80243E40 AD060000 */   sw       $a2, ($t0)
/* 137184 80243E44 0040202D */  daddu     $a0, $v0, $zero
/* 137188 80243E48 27A500BC */  addiu     $a1, $sp, 0xbc
/* 13718C 80243E4C 27A600C0 */  addiu     $a2, $sp, 0xc0
/* 137190 80243E50 27A700C4 */  addiu     $a3, $sp, 0xc4
/* 137194 80243E54 27A200C8 */  addiu     $v0, $sp, 0xc8
/* 137198 80243E58 AFA20010 */  sw        $v0, 0x10($sp)
/* 13719C 80243E5C 27A200CC */  addiu     $v0, $sp, 0xcc
/* 1371A0 80243E60 AFA20014 */  sw        $v0, 0x14($sp)
/* 1371A4 80243E64 AFA00018 */  sw        $zero, 0x18($sp)
/* 1371A8 80243E68 0C0497DA */  jal       get_string_properties
/* 1371AC 80243E6C AFB4001C */   sw       $s4, 0x1c($sp)
/* 1371B0 80243E70 8FB000C0 */  lw        $s0, 0xc0($sp)
/* 1371B4 80243E74 8FAF012C */  lw        $t7, 0x12c($sp)
/* 1371B8 80243E78 8E240000 */  lw        $a0, ($s1)
/* 1371BC 80243E7C 01F08023 */  subu      $s0, $t7, $s0
/* 1371C0 80243E80 0C093BA0 */  jal       pause_get_menu_string
/* 1371C4 80243E84 02908007 */   srav     $s0, $s0, $s4
/* 1371C8 80243E88 0040202D */  daddu     $a0, $v0, $zero
/* 1371CC 80243E8C 240700FF */  addiu     $a3, $zero, 0xff
/* 1371D0 80243E90 2416000A */  addiu     $s6, $zero, 0xa
/* 1371D4 80243E94 001230C0 */  sll       $a2, $s2, 3
/* 1371D8 80243E98 00D23021 */  addu      $a2, $a2, $s2
/* 1371DC 80243E9C 00063080 */  sll       $a2, $a2, 2
/* 1371E0 80243EA0 00D23023 */  subu      $a2, $a2, $s2
/* 1371E4 80243EA4 00063080 */  sll       $a2, $a2, 2
/* 1371E8 80243EA8 8FAE0124 */  lw        $t6, 0x124($sp)
/* 1371EC 80243EAC 24C6000D */  addiu     $a2, $a2, 0xd
/* 1371F0 80243EB0 AFB60010 */  sw        $s6, 0x10($sp)
/* 1371F4 80243EB4 AFB40014 */  sw        $s4, 0x14($sp)
/* 1371F8 80243EB8 8E620000 */  lw        $v0, ($s3)
/* 1371FC 80243EBC 8FAF0128 */  lw        $t7, 0x128($sp)
/* 137200 80243EC0 01D02821 */  addu      $a1, $t6, $s0
/* 137204 80243EC4 01E63021 */  addu      $a2, $t7, $a2
/* 137208 80243EC8 0C04993B */  jal       draw_string
/* 13720C 80243ECC 00C23023 */   subu     $a2, $a2, $v0
/* 137210 80243ED0 8EA30000 */  lw        $v1, ($s5)
/* 137214 80243ED4 8FAE012C */  lw        $t6, 0x12c($sp)
/* 137218 80243ED8 8FAF0124 */  lw        $t7, 0x124($sp)
/* 13721C 80243EDC 00031880 */  sll       $v1, $v1, 2
/* 137220 80243EE0 000E17C2 */  srl       $v0, $t6, 0x1f
/* 137224 80243EE4 01C21021 */  addu      $v0, $t6, $v0
/* 137228 80243EE8 02821007 */  srav      $v0, $v0, $s4
/* 13722C 80243EEC 01E28821 */  addu      $s1, $t7, $v0
/* 137230 80243EF0 2625FFFE */  addiu     $a1, $s1, -2
/* 137234 80243EF4 3C028025 */  lui       $v0, %hi(D_8024F090)
/* 137238 80243EF8 00431021 */  addu      $v0, $v0, $v1
/* 13723C 80243EFC 8C42F090 */  lw        $v0, %lo(D_8024F090)($v0)
/* 137240 80243F00 8FAE0128 */  lw        $t6, 0x128($sp)
/* 137244 80243F04 00021080 */  sll       $v0, $v0, 2
/* 137248 80243F08 3C048027 */  lui       $a0, %hi(gPauseMenuCommonIconIDs)
/* 13724C 80243F0C 00822021 */  addu      $a0, $a0, $v0
/* 137250 80243F10 8C8400E8 */  lw        $a0, %lo(gPauseMenuCommonIconIDs)($a0)
/* 137254 80243F14 0C051261 */  jal       set_hud_element_render_pos
/* 137258 80243F18 25C60034 */   addiu    $a2, $t6, 0x34
/* 13725C 80243F1C 8EA20000 */  lw        $v0, ($s5)
/* 137260 80243F20 00021080 */  sll       $v0, $v0, 2
/* 137264 80243F24 3C018025 */  lui       $at, %hi(D_8024F090)
/* 137268 80243F28 00220821 */  addu      $at, $at, $v0
/* 13726C 80243F2C 8C22F090 */  lw        $v0, %lo(D_8024F090)($at)
/* 137270 80243F30 00021080 */  sll       $v0, $v0, 2
/* 137274 80243F34 3C048027 */  lui       $a0, %hi(gPauseMenuCommonIconIDs)
/* 137278 80243F38 00822021 */  addu      $a0, $a0, $v0
/* 13727C 80243F3C 8C8400E8 */  lw        $a0, %lo(gPauseMenuCommonIconIDs)($a0)
/* 137280 80243F40 0C051280 */  jal       set_hud_element_flags
/* 137284 80243F44 34058000 */   ori      $a1, $zero, 0x8000
/* 137288 80243F48 8EA20000 */  lw        $v0, ($s5)
/* 13728C 80243F4C 00021080 */  sll       $v0, $v0, 2
/* 137290 80243F50 3C018025 */  lui       $at, %hi(D_8024F090)
/* 137294 80243F54 00220821 */  addu      $at, $at, $v0
/* 137298 80243F58 8C22F090 */  lw        $v0, %lo(D_8024F090)($at)
/* 13729C 80243F5C 3C053F00 */  lui       $a1, 0x3f00
/* 1372A0 80243F60 00021080 */  sll       $v0, $v0, 2
/* 1372A4 80243F64 3C048027 */  lui       $a0, %hi(gPauseMenuCommonIconIDs)
/* 1372A8 80243F68 00822021 */  addu      $a0, $a0, $v0
/* 1372AC 80243F6C 8C8400E8 */  lw        $a0, %lo(gPauseMenuCommonIconIDs)($a0)
/* 1372B0 80243F70 0C051308 */  jal       set_hud_element_scale
/* 1372B4 80243F74 00000000 */   nop
/* 1372B8 80243F78 8EA20000 */  lw        $v0, ($s5)
/* 1372BC 80243F7C 00021080 */  sll       $v0, $v0, 2
/* 1372C0 80243F80 3C018025 */  lui       $at, %hi(D_8024F090)
/* 1372C4 80243F84 00220821 */  addu      $at, $at, $v0
/* 1372C8 80243F88 8C22F090 */  lw        $v0, %lo(D_8024F090)($at)
/* 1372CC 80243F8C 00021080 */  sll       $v0, $v0, 2
/* 1372D0 80243F90 3C048027 */  lui       $a0, %hi(gPauseMenuCommonIconIDs)
/* 1372D4 80243F94 00822021 */  addu      $a0, $a0, $v0
/* 1372D8 80243F98 8C8400E8 */  lw        $a0, %lo(gPauseMenuCommonIconIDs)($a0)
/* 1372DC 80243F9C 0C0511F8 */  jal       draw_icon_2
/* 1372E0 80243FA0 00000000 */   nop
/* 1372E4 80243FA4 8EA20000 */  lw        $v0, ($s5)
/* 1372E8 80243FA8 3C108027 */  lui       $s0, %hi(gPauseMenuCommonIconIDs)
/* 1372EC 80243FAC 261000E8 */  addiu     $s0, $s0, %lo(gPauseMenuCommonIconIDs)
/* 1372F0 80243FB0 00021080 */  sll       $v0, $v0, 2
/* 1372F4 80243FB4 3C038025 */  lui       $v1, %hi(D_8024F090)
/* 1372F8 80243FB8 00621821 */  addu      $v1, $v1, $v0
/* 1372FC 80243FBC 8C63F090 */  lw        $v1, %lo(D_8024F090)($v1)
/* 137300 80243FC0 24020006 */  addiu     $v0, $zero, 6
/* 137304 80243FC4 14620008 */  bne       $v1, $v0, .L80243FE8
/* 137308 80243FC8 02342821 */   addu     $a1, $s1, $s4
/* 13730C 80243FCC 8FAF0128 */  lw        $t7, 0x128($sp)
/* 137310 80243FD0 8E04001C */  lw        $a0, 0x1c($s0)
/* 137314 80243FD4 0C051261 */  jal       set_hud_element_render_pos
/* 137318 80243FD8 25E60032 */   addiu    $a2, $t7, 0x32
/* 13731C 80243FDC 8E04001C */  lw        $a0, 0x1c($s0)
/* 137320 80243FE0 0C0511F8 */  jal       draw_icon_2
/* 137324 80243FE4 00000000 */   nop
.L80243FE8:
/* 137328 80243FE8 8EA20000 */  lw        $v0, ($s5)
/* 13732C 80243FEC 00021080 */  sll       $v0, $v0, 2
/* 137330 80243FF0 3C048025 */  lui       $a0, %hi(D_8024F058)
/* 137334 80243FF4 00822021 */  addu      $a0, $a0, $v0
/* 137338 80243FF8 0C093BA0 */  jal       pause_get_menu_string
/* 13733C 80243FFC 8C84F058 */   lw       $a0, %lo(D_8024F058)($a0)
/* 137340 80244000 0040202D */  daddu     $a0, $v0, $zero
/* 137344 80244004 2625000A */  addiu     $a1, $s1, 0xa
/* 137348 80244008 8FAE0128 */  lw        $t6, 0x128($sp)
/* 13734C 8024400C 240700FF */  addiu     $a3, $zero, 0xff
/* 137350 80244010 AFB60010 */  sw        $s6, 0x10($sp)
/* 137354 80244014 AFA00014 */  sw        $zero, 0x14($sp)
/* 137358 80244018 0C04993B */  jal       draw_string
/* 13735C 8024401C 25C6002C */   addiu    $a2, $t6, 0x2c
.L80244020:
/* 137360 80244020 8FBF00FC */  lw        $ra, 0xfc($sp)
/* 137364 80244024 8FBE00F8 */  lw        $fp, 0xf8($sp)
/* 137368 80244028 8FB700F4 */  lw        $s7, 0xf4($sp)
/* 13736C 8024402C 8FB600F0 */  lw        $s6, 0xf0($sp)
/* 137370 80244030 8FB500EC */  lw        $s5, 0xec($sp)
/* 137374 80244034 8FB400E8 */  lw        $s4, 0xe8($sp)
/* 137378 80244038 8FB300E4 */  lw        $s3, 0xe4($sp)
/* 13737C 8024403C 8FB200E0 */  lw        $s2, 0xe0($sp)
/* 137380 80244040 8FB100DC */  lw        $s1, 0xdc($sp)
/* 137384 80244044 8FB000D8 */  lw        $s0, 0xd8($sp)
/* 137388 80244048 D7BA0118 */  ldc1      $f26, 0x118($sp)
/* 13738C 8024404C D7B80110 */  ldc1      $f24, 0x110($sp)
/* 137390 80244050 D7B60108 */  ldc1      $f22, 0x108($sp)
/* 137394 80244054 D7B40100 */  ldc1      $f20, 0x100($sp)
/* 137398 80244058 03E00008 */  jr        $ra
/* 13739C 8024405C 27BD0120 */   addiu    $sp, $sp, 0x120
