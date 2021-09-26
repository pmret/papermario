.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E004A78C
/* 358C4C E004A78C 27BDFEE8 */  addiu     $sp, $sp, -0x118
/* 358C50 E004A790 AFBF00FC */  sw        $ra, 0xfc($sp)
/* 358C54 E004A794 AFBE00F8 */  sw        $fp, 0xf8($sp)
/* 358C58 E004A798 AFB700F4 */  sw        $s7, 0xf4($sp)
/* 358C5C E004A79C AFB600F0 */  sw        $s6, 0xf0($sp)
/* 358C60 E004A7A0 AFB500EC */  sw        $s5, 0xec($sp)
/* 358C64 E004A7A4 AFB400E8 */  sw        $s4, 0xe8($sp)
/* 358C68 E004A7A8 AFB300E4 */  sw        $s3, 0xe4($sp)
/* 358C6C E004A7AC AFB200E0 */  sw        $s2, 0xe0($sp)
/* 358C70 E004A7B0 AFB100DC */  sw        $s1, 0xdc($sp)
/* 358C74 E004A7B4 AFB000D8 */  sw        $s0, 0xd8($sp)
/* 358C78 E004A7B8 F7B80110 */  sdc1      $f24, 0x110($sp)
/* 358C7C E004A7BC F7B60108 */  sdc1      $f22, 0x108($sp)
/* 358C80 E004A7C0 F7B40100 */  sdc1      $f20, 0x100($sp)
/* 358C84 E004A7C4 AFA40118 */  sw        $a0, 0x118($sp)
/* 358C88 E004A7C8 8C91000C */  lw        $s1, 0xc($a0)
/* 358C8C E004A7CC 922F0050 */  lbu       $t7, 0x50($s1)
/* 358C90 E004A7D0 AFAF00A4 */  sw        $t7, 0xa4($sp)
/* 358C94 E004A7D4 922F0051 */  lbu       $t7, 0x51($s1)
/* 358C98 E004A7D8 AFAF00A8 */  sw        $t7, 0xa8($sp)
/* 358C9C E004A7DC 8FAF00A4 */  lw        $t7, 0xa4($sp)
/* 358CA0 E004A7E0 AFAF00BC */  sw        $t7, 0xbc($sp)
/* 358CA4 E004A7E4 8FAF00A8 */  lw        $t7, 0xa8($sp)
/* 358CA8 E004A7E8 AFAF00C0 */  sw        $t7, 0xc0($sp)
/* 358CAC E004A7EC 922F0052 */  lbu       $t7, 0x52($s1)
/* 358CB0 E004A7F0 AFAF00AC */  sw        $t7, 0xac($sp)
/* 358CB4 E004A7F4 922F0053 */  lbu       $t7, 0x53($s1)
/* 358CB8 E004A7F8 AFAF00B0 */  sw        $t7, 0xb0($sp)
/* 358CBC E004A7FC 8FAF00AC */  lw        $t7, 0xac($sp)
/* 358CC0 E004A800 AFAF00C4 */  sw        $t7, 0xc4($sp)
/* 358CC4 E004A804 8FAF00B0 */  lw        $t7, 0xb0($sp)
/* 358CC8 E004A808 AFAF00C8 */  sw        $t7, 0xc8($sp)
/* 358CCC E004A80C 922F0054 */  lbu       $t7, 0x54($s1)
/* 358CD0 E004A810 AFAF00B4 */  sw        $t7, 0xb4($sp)
/* 358CD4 E004A814 922F0055 */  lbu       $t7, 0x55($s1)
/* 358CD8 E004A818 AFAF00B8 */  sw        $t7, 0xb8($sp)
/* 358CDC E004A81C 8FAF00B4 */  lw        $t7, 0xb4($sp)
/* 358CE0 E004A820 AFAF00CC */  sw        $t7, 0xcc($sp)
/* 358CE4 E004A824 8FAF00B8 */  lw        $t7, 0xb8($sp)
/* 358CE8 E004A828 AFAF00D0 */  sw        $t7, 0xd0($sp)
/* 358CEC E004A82C 96220000 */  lhu       $v0, ($s1)
/* 358CF0 E004A830 00021880 */  sll       $v1, $v0, 2
/* 358CF4 E004A834 28420002 */  slti      $v0, $v0, 2
/* 358CF8 E004A838 3C09E005 */  lui       $t1, %hi(D_E004AE60)
/* 358CFC E004A83C 01234821 */  addu      $t1, $t1, $v1
/* 358D00 E004A840 8D29AE60 */  lw        $t1, %lo(D_E004AE60)($t1)
/* 358D04 E004A844 14400013 */  bnez      $v0, .LE004A894
/* 358D08 E004A848 3C06DB06 */   lui      $a2, 0xdb06
/* 358D0C E004A84C 8FAF00A4 */  lw        $t7, 0xa4($sp)
/* 358D10 E004A850 000F7883 */  sra       $t7, $t7, 2
/* 358D14 E004A854 AFAF00BC */  sw        $t7, 0xbc($sp)
/* 358D18 E004A858 8FAF00A8 */  lw        $t7, 0xa8($sp)
/* 358D1C E004A85C 000F7883 */  sra       $t7, $t7, 2
/* 358D20 E004A860 AFAF00C0 */  sw        $t7, 0xc0($sp)
/* 358D24 E004A864 8FAF00AC */  lw        $t7, 0xac($sp)
/* 358D28 E004A868 000F7883 */  sra       $t7, $t7, 2
/* 358D2C E004A86C AFAF00C4 */  sw        $t7, 0xc4($sp)
/* 358D30 E004A870 8FAF00B0 */  lw        $t7, 0xb0($sp)
/* 358D34 E004A874 000F7883 */  sra       $t7, $t7, 2
/* 358D38 E004A878 AFAF00C8 */  sw        $t7, 0xc8($sp)
/* 358D3C E004A87C 8FAF00B4 */  lw        $t7, 0xb4($sp)
/* 358D40 E004A880 000F7883 */  sra       $t7, $t7, 2
/* 358D44 E004A884 AFAF00CC */  sw        $t7, 0xcc($sp)
/* 358D48 E004A888 8FAF00B8 */  lw        $t7, 0xb8($sp)
/* 358D4C E004A88C 000F7883 */  sra       $t7, $t7, 2
/* 358D50 E004A890 AFAF00D0 */  sw        $t7, 0xd0($sp)
.LE004A894:
/* 358D54 E004A894 34C60024 */  ori       $a2, $a2, 0x24
/* 358D58 E004A898 27A40020 */  addiu     $a0, $sp, 0x20
/* 358D5C E004A89C 3C13800A */  lui       $s3, %hi(gMasterGfxPos)
/* 358D60 E004A8A0 2673A66C */  addiu     $s3, $s3, %lo(gMasterGfxPos)
/* 358D64 E004A8A4 3C02E700 */  lui       $v0, 0xe700
/* 358D68 E004A8A8 8E680000 */  lw        $t0, ($s3)
/* 358D6C E004A8AC 4480A000 */  mtc1      $zero, $f20
/* 358D70 E004A8B0 3C013F80 */  lui       $at, 0x3f80
/* 358D74 E004A8B4 4481C000 */  mtc1      $at, $f24
/* 358D78 E004A8B8 0100182D */  daddu     $v1, $t0, $zero
/* 358D7C E004A8BC 4405A000 */  mfc1      $a1, $f20
/* 358D80 E004A8C0 25080008 */  addiu     $t0, $t0, 8
/* 358D84 E004A8C4 AC620000 */  sw        $v0, ($v1)
/* 358D88 E004A8C8 AC600004 */  sw        $zero, 4($v1)
/* 358D8C E004A8CC AD060000 */  sw        $a2, ($t0)
/* 358D90 E004A8D0 8FAF0118 */  lw        $t7, 0x118($sp)
/* 358D94 E004A8D4 4407A000 */  mfc1      $a3, $f20
/* 358D98 E004A8D8 8DE20010 */  lw        $v0, 0x10($t7)
/* 358D9C E004A8DC 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 358DA0 E004A8E0 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 358DA4 E004A8E4 8C46001C */  lw        $a2, 0x1c($v0)
/* 358DA8 E004A8E8 3C02DE00 */  lui       $v0, 0xde00
/* 358DAC E004A8EC AD020008 */  sw        $v0, 8($t0)
/* 358DB0 E004A8F0 3C028000 */  lui       $v0, 0x8000
/* 358DB4 E004A8F4 AD09000C */  sw        $t1, 0xc($t0)
/* 358DB8 E004A8F8 00C23021 */  addu      $a2, $a2, $v0
/* 358DBC E004A8FC 00031080 */  sll       $v0, $v1, 2
/* 358DC0 E004A900 00431021 */  addu      $v0, $v0, $v1
/* 358DC4 E004A904 00021080 */  sll       $v0, $v0, 2
/* 358DC8 E004A908 00431023 */  subu      $v0, $v0, $v1
/* 358DCC E004A90C 000218C0 */  sll       $v1, $v0, 3
/* 358DD0 E004A910 00431021 */  addu      $v0, $v0, $v1
/* 358DD4 E004A914 000210C0 */  sll       $v0, $v0, 3
/* 358DD8 E004A918 AD060004 */  sw        $a2, 4($t0)
/* 358DDC E004A91C 3C01800B */  lui       $at, %hi(gCameras+0x6C)
/* 358DE0 E004A920 00220821 */  addu      $at, $at, $v0
/* 358DE4 E004A924 C4221DEC */  lwc1      $f2, %lo(gCameras+0x6C)($at)
/* 358DE8 E004A928 3C100001 */  lui       $s0, 1
/* 358DEC E004A92C AE680000 */  sw        $t0, ($s3)
/* 358DF0 E004A930 E7B80010 */  swc1      $f24, 0x10($sp)
/* 358DF4 E004A934 C6200004 */  lwc1      $f0, 4($s1)
/* 358DF8 E004A938 25020008 */  addiu     $v0, $t0, 8
/* 358DFC E004A93C AE620000 */  sw        $v0, ($s3)
/* 358E00 E004A940 46001087 */  neg.s     $f2, $f2
/* 358E04 E004A944 E7A00014 */  swc1      $f0, 0x14($sp)
/* 358E08 E004A948 C6200008 */  lwc1      $f0, 8($s1)
/* 358E0C E004A94C 44061000 */  mfc1      $a2, $f2
/* 358E10 E004A950 25080010 */  addiu     $t0, $t0, 0x10
/* 358E14 E004A954 AE680000 */  sw        $t0, ($s3)
/* 358E18 E004A958 E7A00018 */  swc1      $f0, 0x18($sp)
/* 358E1C E004A95C C620000C */  lwc1      $f0, 0xc($s1)
/* 358E20 E004A960 36101630 */  ori       $s0, $s0, 0x1630
/* 358E24 E004A964 0C080180 */  jal       shim_guPositionF
/* 358E28 E004A968 E7A0001C */   swc1     $f0, 0x1c($sp)
/* 358E2C E004A96C 27A40020 */  addiu     $a0, $sp, 0x20
/* 358E30 E004A970 3C158007 */  lui       $s5, %hi(gMatrixListPos)
/* 358E34 E004A974 26B541F0 */  addiu     $s5, $s5, %lo(gMatrixListPos)
/* 358E38 E004A978 3C16800A */  lui       $s6, %hi(gDisplayContext)
/* 358E3C E004A97C 26D6A674 */  addiu     $s6, $s6, %lo(gDisplayContext)
/* 358E40 E004A980 96A50000 */  lhu       $a1, ($s5)
/* 358E44 E004A984 8EC20000 */  lw        $v0, ($s6)
/* 358E48 E004A988 00052980 */  sll       $a1, $a1, 6
/* 358E4C E004A98C 00B02821 */  addu      $a1, $a1, $s0
/* 358E50 E004A990 0C080118 */  jal       shim_guMtxF2L
/* 358E54 E004A994 00452821 */   addu     $a1, $v0, $a1
/* 358E58 E004A998 24140001 */  addiu     $s4, $zero, 1
/* 358E5C E004A99C 3C02DA38 */  lui       $v0, 0xda38
/* 358E60 E004A9A0 8E650000 */  lw        $a1, ($s3)
/* 358E64 E004A9A4 96A40000 */  lhu       $a0, ($s5)
/* 358E68 E004A9A8 00A0302D */  daddu     $a2, $a1, $zero
/* 358E6C E004A9AC 24A50008 */  addiu     $a1, $a1, 8
/* 358E70 E004A9B0 ACC20000 */  sw        $v0, ($a2)
/* 358E74 E004A9B4 3082FFFF */  andi      $v0, $a0, 0xffff
/* 358E78 E004A9B8 00021180 */  sll       $v0, $v0, 6
/* 358E7C E004A9BC 00501021 */  addu      $v0, $v0, $s0
/* 358E80 E004A9C0 00942021 */  addu      $a0, $a0, $s4
/* 358E84 E004A9C4 8EC30000 */  lw        $v1, ($s6)
/* 358E88 E004A9C8 00A0B82D */  daddu     $s7, $a1, $zero
/* 358E8C E004A9CC 00621821 */  addu      $v1, $v1, $v0
/* 358E90 E004A9D0 ACC30004 */  sw        $v1, 4($a2)
/* 358E94 E004A9D4 8E2F0038 */  lw        $t7, 0x38($s1)
/* 358E98 E004A9D8 26E30008 */  addiu     $v1, $s7, 8
/* 358E9C E004A9DC AFAF00A0 */  sw        $t7, 0xa0($sp)
/* 358EA0 E004A9E0 AE650000 */  sw        $a1, ($s3)
/* 358EA4 E004A9E4 A6A40000 */  sh        $a0, ($s5)
/* 358EA8 E004A9E8 AE630000 */  sw        $v1, ($s3)
/* 358EAC E004A9EC 8FAF0118 */  lw        $t7, 0x118($sp)
/* 358EB0 E004A9F0 8DE20008 */  lw        $v0, 8($t7)
/* 358EB4 E004A9F4 26310058 */  addiu     $s1, $s1, 0x58
/* 358EB8 E004A9F8 0282102A */  slt       $v0, $s4, $v0
/* 358EBC E004A9FC 10400090 */  beqz      $v0, .LE004AC40
/* 358EC0 E004AA00 AFA300D4 */   sw       $v1, 0xd4($sp)
/* 358EC4 E004AA04 27B20060 */  addiu     $s2, $sp, 0x60
/* 358EC8 E004AA08 4600A586 */  mov.s     $f22, $f20
/* 358ECC E004AA0C 3C01E005 */  lui       $at, %hi(D_E004AEE8)
/* 358ED0 E004AA10 D434AEE8 */  ldc1      $f20, %lo(D_E004AEE8)($at)
/* 358ED4 E004AA14 02A0B02D */  daddu     $s6, $s5, $zero
/* 358ED8 E004AA18 3C150001 */  lui       $s5, 1
/* 358EDC E004AA1C 36B51630 */  ori       $s5, $s5, 0x1630
/* 358EE0 E004AA20 3C1EF200 */  lui       $fp, 0xf200
/* 358EE4 E004AA24 26300044 */  addiu     $s0, $s1, 0x44
.LE004AA28:
/* 358EE8 E004AA28 8E020008 */  lw        $v0, 8($s0)
/* 358EEC E004AA2C 0440007E */  bltz      $v0, .LE004AC28
/* 358EF0 E004AA30 00000000 */   nop
/* 358EF4 E004AA34 8E05FFC0 */  lw        $a1, -0x40($s0)
/* 358EF8 E004AA38 8E06FFC4 */  lw        $a2, -0x3c($s0)
/* 358EFC E004AA3C 8E07FFC8 */  lw        $a3, -0x38($s0)
/* 358F00 E004AA40 0C080108 */  jal       shim_guTranslateF
/* 358F04 E004AA44 27A40020 */   addiu    $a0, $sp, 0x20
/* 358F08 E004AA48 E7B80010 */  swc1      $f24, 0x10($sp)
/* 358F0C E004AA4C 8E05FFF0 */  lw        $a1, -0x10($s0)
/* 358F10 E004AA50 4406B000 */  mfc1      $a2, $f22
/* 358F14 E004AA54 4407B000 */  mfc1      $a3, $f22
/* 358F18 E004AA58 0C080104 */  jal       shim_guRotateF
/* 358F1C E004AA5C 0240202D */   daddu    $a0, $s2, $zero
/* 358F20 E004AA60 0240202D */  daddu     $a0, $s2, $zero
/* 358F24 E004AA64 27A50020 */  addiu     $a1, $sp, 0x20
/* 358F28 E004AA68 0C080114 */  jal       shim_guMtxCatF
/* 358F2C E004AA6C 00A0302D */   daddu    $a2, $a1, $zero
/* 358F30 E004AA70 C604FFD8 */  lwc1      $f4, -0x28($s0)
/* 358F34 E004AA74 46002121 */  cvt.d.s   $f4, $f4
/* 358F38 E004AA78 46342102 */  mul.d     $f4, $f4, $f20
/* 358F3C E004AA7C 00000000 */  nop
/* 358F40 E004AA80 C602FFDC */  lwc1      $f2, -0x24($s0)
/* 358F44 E004AA84 460010A1 */  cvt.d.s   $f2, $f2
/* 358F48 E004AA88 46341082 */  mul.d     $f2, $f2, $f20
/* 358F4C E004AA8C 00000000 */  nop
/* 358F50 E004AA90 C600FFE0 */  lwc1      $f0, -0x20($s0)
/* 358F54 E004AA94 46000021 */  cvt.d.s   $f0, $f0
/* 358F58 E004AA98 46340002 */  mul.d     $f0, $f0, $f20
/* 358F5C E004AA9C 00000000 */  nop
/* 358F60 E004AAA0 46202120 */  cvt.s.d   $f4, $f4
/* 358F64 E004AAA4 462010A0 */  cvt.s.d   $f2, $f2
/* 358F68 E004AAA8 46200020 */  cvt.s.d   $f0, $f0
/* 358F6C E004AAAC 44052000 */  mfc1      $a1, $f4
/* 358F70 E004AAB0 44061000 */  mfc1      $a2, $f2
/* 358F74 E004AAB4 44070000 */  mfc1      $a3, $f0
/* 358F78 E004AAB8 0C080110 */  jal       shim_guScaleF
/* 358F7C E004AABC 0240202D */   daddu    $a0, $s2, $zero
/* 358F80 E004AAC0 0240202D */  daddu     $a0, $s2, $zero
/* 358F84 E004AAC4 27A50020 */  addiu     $a1, $sp, 0x20
/* 358F88 E004AAC8 0C080114 */  jal       shim_guMtxCatF
/* 358F8C E004AACC 00A0302D */   daddu    $a2, $a1, $zero
/* 358F90 E004AAD0 E7B60010 */  swc1      $f22, 0x10($sp)
/* 358F94 E004AAD4 8E05FFEC */  lw        $a1, -0x14($s0)
/* 358F98 E004AAD8 4406B000 */  mfc1      $a2, $f22
/* 358F9C E004AADC 4407C000 */  mfc1      $a3, $f24
/* 358FA0 E004AAE0 0C080104 */  jal       shim_guRotateF
/* 358FA4 E004AAE4 0240202D */   daddu    $a0, $s2, $zero
/* 358FA8 E004AAE8 0240202D */  daddu     $a0, $s2, $zero
/* 358FAC E004AAEC 27A50020 */  addiu     $a1, $sp, 0x20
/* 358FB0 E004AAF0 0C080114 */  jal       shim_guMtxCatF
/* 358FB4 E004AAF4 00A0302D */   daddu    $a2, $a1, $zero
/* 358FB8 E004AAF8 27A40020 */  addiu     $a0, $sp, 0x20
/* 358FBC E004AAFC 96C50000 */  lhu       $a1, ($s6)
/* 358FC0 E004AB00 3C02800A */  lui       $v0, %hi(gDisplayContext)
/* 358FC4 E004AB04 8C42A674 */  lw        $v0, %lo(gDisplayContext)($v0)
/* 358FC8 E004AB08 00052980 */  sll       $a1, $a1, 6
/* 358FCC E004AB0C 00B52821 */  addu      $a1, $a1, $s5
/* 358FD0 E004AB10 0C080118 */  jal       shim_guMtxF2L
/* 358FD4 E004AB14 00452821 */   addu     $a1, $v0, $a1
/* 358FD8 E004AB18 3C06000F */  lui       $a2, 0xf
/* 358FDC E004AB1C 34C6C000 */  ori       $a2, $a2, 0xc000
/* 358FE0 E004AB20 3C080107 */  lui       $t0, 0x107
/* 358FE4 E004AB24 3508C000 */  ori       $t0, $t0, 0xc000
/* 358FE8 E004AB28 3C07D838 */  lui       $a3, 0xd838
/* 358FEC E004AB2C 34E70002 */  ori       $a3, $a3, 2
/* 358FF0 E004AB30 8E630000 */  lw        $v1, ($s3)
/* 358FF4 E004AB34 C600FFF8 */  lwc1      $f0, -8($s0)
/* 358FF8 E004AB38 0060282D */  daddu     $a1, $v1, $zero
/* 358FFC E004AB3C 24630008 */  addiu     $v1, $v1, 8
/* 359000 E004AB40 4600018D */  trunc.w.s $f6, $f0
/* 359004 E004AB44 44023000 */  mfc1      $v0, $f6
/* 359008 E004AB48 00000000 */  nop
/* 35900C E004AB4C 30420FFF */  andi      $v0, $v0, 0xfff
/* 359010 E004AB50 005E1025 */  or        $v0, $v0, $fp
/* 359014 E004AB54 AE630000 */  sw        $v1, ($s3)
/* 359018 E004AB58 ACA20000 */  sw        $v0, ($a1)
/* 35901C E004AB5C 24620008 */  addiu     $v0, $v1, 8
/* 359020 E004AB60 AE620000 */  sw        $v0, ($s3)
/* 359024 E004AB64 96C40000 */  lhu       $a0, ($s6)
/* 359028 E004AB68 24620010 */  addiu     $v0, $v1, 0x10
/* 35902C E004AB6C AE620000 */  sw        $v0, ($s3)
/* 359030 E004AB70 24820001 */  addiu     $v0, $a0, 1
/* 359034 E004AB74 A6C20000 */  sh        $v0, ($s6)
/* 359038 E004AB78 24620018 */  addiu     $v0, $v1, 0x18
/* 35903C E004AB7C 3084FFFF */  andi      $a0, $a0, 0xffff
/* 359040 E004AB80 00042180 */  sll       $a0, $a0, 6
/* 359044 E004AB84 C600FFF8 */  lwc1      $f0, -8($s0)
/* 359048 E004AB88 00952021 */  addu      $a0, $a0, $s5
/* 35904C E004AB8C AE620000 */  sw        $v0, ($s3)
/* 359050 E004AB90 4600018D */  trunc.w.s $f6, $f0
/* 359054 E004AB94 44023000 */  mfc1      $v0, $f6
/* 359058 E004AB98 00000000 */  nop
/* 35905C E004AB9C 2442007C */  addiu     $v0, $v0, 0x7c
/* 359060 E004ABA0 30420FFF */  andi      $v0, $v0, 0xfff
/* 359064 E004ABA4 00461025 */  or        $v0, $v0, $a2
/* 359068 E004ABA8 ACA20004 */  sw        $v0, 4($a1)
/* 35906C E004ABAC C6000000 */  lwc1      $f0, ($s0)
/* 359070 E004ABB0 24620020 */  addiu     $v0, $v1, 0x20
/* 359074 E004ABB4 AE620000 */  sw        $v0, ($s3)
/* 359078 E004ABB8 4600018D */  trunc.w.s $f6, $f0
/* 35907C E004ABBC 44023000 */  mfc1      $v0, $f6
/* 359080 E004ABC0 00000000 */  nop
/* 359084 E004ABC4 30420FFF */  andi      $v0, $v0, 0xfff
/* 359088 E004ABC8 005E1025 */  or        $v0, $v0, $fp
/* 35908C E004ABCC AC620000 */  sw        $v0, ($v1)
/* 359090 E004ABD0 C6000000 */  lwc1      $f0, ($s0)
/* 359094 E004ABD4 3C02DA38 */  lui       $v0, 0xda38
/* 359098 E004ABD8 AC620008 */  sw        $v0, 8($v1)
/* 35909C E004ABDC 3C02800A */  lui       $v0, %hi(gDisplayContext)
/* 3590A0 E004ABE0 8C42A674 */  lw        $v0, %lo(gDisplayContext)($v0)
/* 3590A4 E004ABE4 3C0F0900 */  lui       $t7, 0x900
/* 3590A8 E004ABE8 25EF0940 */  addiu     $t7, $t7, 0x940
/* 3590AC E004ABEC AC6F0014 */  sw        $t7, 0x14($v1)
/* 3590B0 E004ABF0 AC670018 */  sw        $a3, 0x18($v1)
/* 3590B4 E004ABF4 00441021 */  addu      $v0, $v0, $a0
/* 3590B8 E004ABF8 AC62000C */  sw        $v0, 0xc($v1)
/* 3590BC E004ABFC 3C02DE00 */  lui       $v0, 0xde00
/* 3590C0 E004AC00 AC620010 */  sw        $v0, 0x10($v1)
/* 3590C4 E004AC04 24020040 */  addiu     $v0, $zero, 0x40
/* 3590C8 E004AC08 AC62001C */  sw        $v0, 0x1c($v1)
/* 3590CC E004AC0C 4600018D */  trunc.w.s $f6, $f0
/* 3590D0 E004AC10 44023000 */  mfc1      $v0, $f6
/* 3590D4 E004AC14 00000000 */  nop
/* 3590D8 E004AC18 2442007C */  addiu     $v0, $v0, 0x7c
/* 3590DC E004AC1C 30420FFF */  andi      $v0, $v0, 0xfff
/* 3590E0 E004AC20 00481025 */  or        $v0, $v0, $t0
/* 3590E4 E004AC24 AC620004 */  sw        $v0, 4($v1)
.LE004AC28:
/* 3590E8 E004AC28 8FAF0118 */  lw        $t7, 0x118($sp)
/* 3590EC E004AC2C 26940001 */  addiu     $s4, $s4, 1
/* 3590F0 E004AC30 8DE20008 */  lw        $v0, 8($t7)
/* 3590F4 E004AC34 0282102A */  slt       $v0, $s4, $v0
/* 3590F8 E004AC38 1440FF7B */  bnez      $v0, .LE004AA28
/* 3590FC E004AC3C 26100058 */   addiu    $s0, $s0, 0x58
.LE004AC40:
/* 359100 E004AC40 3C0AD9FF */  lui       $t2, 0xd9ff
/* 359104 E004AC44 354AF9FF */  ori       $t2, $t2, 0xf9ff
/* 359108 E004AC48 3C0BD9FF */  lui       $t3, 0xd9ff
/* 35910C E004AC4C 356BFFFF */  ori       $t3, $t3, 0xffff
/* 359110 E004AC50 3C05800A */  lui       $a1, %hi(gMasterGfxPos)
/* 359114 E004AC54 24A5A66C */  addiu     $a1, $a1, %lo(gMasterGfxPos)
/* 359118 E004AC58 3C02DF00 */  lui       $v0, 0xdf00
/* 35911C E004AC5C 8CA30000 */  lw        $v1, ($a1)
/* 359120 E004AC60 3C09FA00 */  lui       $t1, 0xfa00
/* 359124 E004AC64 0060202D */  daddu     $a0, $v1, $zero
/* 359128 E004AC68 24630008 */  addiu     $v1, $v1, 8
/* 35912C E004AC6C ACA30000 */  sw        $v1, ($a1)
/* 359130 E004AC70 AC820000 */  sw        $v0, ($a0)
/* 359134 E004AC74 3C02DE01 */  lui       $v0, 0xde01
/* 359138 E004AC78 AC800004 */  sw        $zero, 4($a0)
/* 35913C E004AC7C AEE20000 */  sw        $v0, ($s7)
/* 359140 E004AC80 24620008 */  addiu     $v0, $v1, 8
/* 359144 E004AC84 AEE30004 */  sw        $v1, 4($s7)
/* 359148 E004AC88 ACA20000 */  sw        $v0, ($a1)
/* 35914C E004AC8C AC690000 */  sw        $t1, ($v1)
/* 359150 E004AC90 8FAF00BC */  lw        $t7, 0xbc($sp)
/* 359154 E004AC94 3C0CE300 */  lui       $t4, 0xe300
/* 359158 E004AC98 000F1600 */  sll       $v0, $t7, 0x18
/* 35915C E004AC9C 8FAF00C0 */  lw        $t7, 0xc0($sp)
/* 359160 E004ACA0 3C07FB00 */  lui       $a3, 0xfb00
/* 359164 E004ACA4 000F2400 */  sll       $a0, $t7, 0x10
/* 359168 E004ACA8 8FAF00C4 */  lw        $t7, 0xc4($sp)
/* 35916C E004ACAC 00441025 */  or        $v0, $v0, $a0
/* 359170 E004ACB0 000F2200 */  sll       $a0, $t7, 8
/* 359174 E004ACB4 8FAF00A0 */  lw        $t7, 0xa0($sp)
/* 359178 E004ACB8 00441025 */  or        $v0, $v0, $a0
/* 35917C E004ACBC 31E800FF */  andi      $t0, $t7, 0xff
/* 359180 E004ACC0 00481025 */  or        $v0, $v0, $t0
/* 359184 E004ACC4 AC620004 */  sw        $v0, 4($v1)
/* 359188 E004ACC8 24620010 */  addiu     $v0, $v1, 0x10
/* 35918C E004ACCC ACA20000 */  sw        $v0, ($a1)
/* 359190 E004ACD0 AC670008 */  sw        $a3, 8($v1)
/* 359194 E004ACD4 8FAF00C8 */  lw        $t7, 0xc8($sp)
/* 359198 E004ACD8 358C1801 */  ori       $t4, $t4, 0x1801
/* 35919C E004ACDC 000F1600 */  sll       $v0, $t7, 0x18
/* 3591A0 E004ACE0 8FAF00CC */  lw        $t7, 0xcc($sp)
/* 3591A4 E004ACE4 3C06DE00 */  lui       $a2, 0xde00
/* 3591A8 E004ACE8 000F2400 */  sll       $a0, $t7, 0x10
/* 3591AC E004ACEC 8FAF00D0 */  lw        $t7, 0xd0($sp)
/* 3591B0 E004ACF0 00441025 */  or        $v0, $v0, $a0
/* 3591B4 E004ACF4 000F2200 */  sll       $a0, $t7, 8
/* 3591B8 E004ACF8 00441025 */  or        $v0, $v0, $a0
/* 3591BC E004ACFC AC62000C */  sw        $v0, 0xc($v1)
/* 3591C0 E004AD00 24620018 */  addiu     $v0, $v1, 0x18
/* 3591C4 E004AD04 ACA20000 */  sw        $v0, ($a1)
/* 3591C8 E004AD08 24620020 */  addiu     $v0, $v1, 0x20
/* 3591CC E004AD0C AC6A0010 */  sw        $t2, 0x10($v1)
/* 3591D0 E004AD10 AC600014 */  sw        $zero, 0x14($v1)
/* 3591D4 E004AD14 ACA20000 */  sw        $v0, ($a1)
/* 3591D8 E004AD18 24020200 */  addiu     $v0, $zero, 0x200
/* 3591DC E004AD1C AC62001C */  sw        $v0, 0x1c($v1)
/* 3591E0 E004AD20 24620028 */  addiu     $v0, $v1, 0x28
/* 3591E4 E004AD24 AC6B0018 */  sw        $t3, 0x18($v1)
/* 3591E8 E004AD28 ACA20000 */  sw        $v0, ($a1)
/* 3591EC E004AD2C AC660020 */  sw        $a2, 0x20($v1)
/* 3591F0 E004AD30 8FAF00D4 */  lw        $t7, 0xd4($sp)
/* 3591F4 E004AD34 24620030 */  addiu     $v0, $v1, 0x30
/* 3591F8 E004AD38 AC6F0024 */  sw        $t7, 0x24($v1)
/* 3591FC E004AD3C ACA20000 */  sw        $v0, ($a1)
/* 359200 E004AD40 AC690028 */  sw        $t1, 0x28($v1)
/* 359204 E004AD44 8FAF00A4 */  lw        $t7, 0xa4($sp)
/* 359208 E004AD48 3C0DE300 */  lui       $t5, 0xe300
/* 35920C E004AD4C 000F1600 */  sll       $v0, $t7, 0x18
/* 359210 E004AD50 8FAF00A8 */  lw        $t7, 0xa8($sp)
/* 359214 E004AD54 35AD1A01 */  ori       $t5, $t5, 0x1a01
/* 359218 E004AD58 000F2400 */  sll       $a0, $t7, 0x10
/* 35921C E004AD5C 8FAF00AC */  lw        $t7, 0xac($sp)
/* 359220 E004AD60 00441025 */  or        $v0, $v0, $a0
/* 359224 E004AD64 000F2200 */  sll       $a0, $t7, 8
/* 359228 E004AD68 00441025 */  or        $v0, $v0, $a0
/* 35922C E004AD6C 00481025 */  or        $v0, $v0, $t0
/* 359230 E004AD70 AC62002C */  sw        $v0, 0x2c($v1)
/* 359234 E004AD74 24620038 */  addiu     $v0, $v1, 0x38
/* 359238 E004AD78 ACA20000 */  sw        $v0, ($a1)
/* 35923C E004AD7C AC670030 */  sw        $a3, 0x30($v1)
/* 359240 E004AD80 8FAF00B0 */  lw        $t7, 0xb0($sp)
/* 359244 E004AD84 3C0ED838 */  lui       $t6, 0xd838
/* 359248 E004AD88 000F1600 */  sll       $v0, $t7, 0x18
/* 35924C E004AD8C 8FAF00B4 */  lw        $t7, 0xb4($sp)
/* 359250 E004AD90 35CE0002 */  ori       $t6, $t6, 2
/* 359254 E004AD94 000F2400 */  sll       $a0, $t7, 0x10
/* 359258 E004AD98 8FAF00B8 */  lw        $t7, 0xb8($sp)
/* 35925C E004AD9C 00441025 */  or        $v0, $v0, $a0
/* 359260 E004ADA0 000F2200 */  sll       $a0, $t7, 8
/* 359264 E004ADA4 00441025 */  or        $v0, $v0, $a0
/* 359268 E004ADA8 AC620034 */  sw        $v0, 0x34($v1)
/* 35926C E004ADAC 24620040 */  addiu     $v0, $v1, 0x40
/* 359270 E004ADB0 ACA20000 */  sw        $v0, ($a1)
/* 359274 E004ADB4 24620048 */  addiu     $v0, $v1, 0x48
/* 359278 E004ADB8 AC6A0038 */  sw        $t2, 0x38($v1)
/* 35927C E004ADBC AC60003C */  sw        $zero, 0x3c($v1)
/* 359280 E004ADC0 ACA20000 */  sw        $v0, ($a1)
/* 359284 E004ADC4 24020400 */  addiu     $v0, $zero, 0x400
/* 359288 E004ADC8 AC620044 */  sw        $v0, 0x44($v1)
/* 35928C E004ADCC 24620050 */  addiu     $v0, $v1, 0x50
/* 359290 E004ADD0 AC6B0040 */  sw        $t3, 0x40($v1)
/* 359294 E004ADD4 ACA20000 */  sw        $v0, ($a1)
/* 359298 E004ADD8 AC660048 */  sw        $a2, 0x48($v1)
/* 35929C E004ADDC 8FAF00D4 */  lw        $t7, 0xd4($sp)
/* 3592A0 E004ADE0 24620058 */  addiu     $v0, $v1, 0x58
/* 3592A4 E004ADE4 AC6F004C */  sw        $t7, 0x4c($v1)
/* 3592A8 E004ADE8 ACA20000 */  sw        $v0, ($a1)
/* 3592AC E004ADEC 240200C0 */  addiu     $v0, $zero, 0xc0
/* 3592B0 E004ADF0 AC6C0050 */  sw        $t4, 0x50($v1)
/* 3592B4 E004ADF4 AC620054 */  sw        $v0, 0x54($v1)
/* 3592B8 E004ADF8 24620060 */  addiu     $v0, $v1, 0x60
/* 3592BC E004ADFC ACA20000 */  sw        $v0, ($a1)
/* 3592C0 E004AE00 24020030 */  addiu     $v0, $zero, 0x30
/* 3592C4 E004AE04 AC62005C */  sw        $v0, 0x5c($v1)
/* 3592C8 E004AE08 24620068 */  addiu     $v0, $v1, 0x68
/* 3592CC E004AE0C AC6D0058 */  sw        $t5, 0x58($v1)
/* 3592D0 E004AE10 ACA20000 */  sw        $v0, ($a1)
/* 3592D4 E004AE14 24020040 */  addiu     $v0, $zero, 0x40
/* 3592D8 E004AE18 AC6E0060 */  sw        $t6, 0x60($v1)
/* 3592DC E004AE1C AC620064 */  sw        $v0, 0x64($v1)
/* 3592E0 E004AE20 8FBF00FC */  lw        $ra, 0xfc($sp)
/* 3592E4 E004AE24 8FBE00F8 */  lw        $fp, 0xf8($sp)
/* 3592E8 E004AE28 8FB700F4 */  lw        $s7, 0xf4($sp)
/* 3592EC E004AE2C 8FB600F0 */  lw        $s6, 0xf0($sp)
/* 3592F0 E004AE30 8FB500EC */  lw        $s5, 0xec($sp)
/* 3592F4 E004AE34 8FB400E8 */  lw        $s4, 0xe8($sp)
/* 3592F8 E004AE38 8FB300E4 */  lw        $s3, 0xe4($sp)
/* 3592FC E004AE3C 8FB200E0 */  lw        $s2, 0xe0($sp)
/* 359300 E004AE40 8FB100DC */  lw        $s1, 0xdc($sp)
/* 359304 E004AE44 8FB000D8 */  lw        $s0, 0xd8($sp)
/* 359308 E004AE48 D7B80110 */  ldc1      $f24, 0x110($sp)
/* 35930C E004AE4C D7B60108 */  ldc1      $f22, 0x108($sp)
/* 359310 E004AE50 D7B40100 */  ldc1      $f20, 0x100($sp)
/* 359314 E004AE54 03E00008 */  jr        $ra
/* 359318 E004AE58 27BD0118 */   addiu    $sp, $sp, 0x118
/* 35931C E004AE5C 00000000 */  nop
