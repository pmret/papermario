.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240AF8_E05E58
/* E05E58 80240AF8 27BDFEF0 */  addiu     $sp, $sp, -0x110
/* E05E5C 80240AFC AFB000C8 */  sw        $s0, 0xc8($sp)
/* E05E60 80240B00 0080802D */  daddu     $s0, $a0, $zero
/* E05E64 80240B04 AFB100CC */  sw        $s1, 0xcc($sp)
/* E05E68 80240B08 00A0882D */  daddu     $s1, $a1, $zero
/* E05E6C 80240B0C AFB600E0 */  sw        $s6, 0xe0($sp)
/* E05E70 80240B10 24160040 */  addiu     $s6, $zero, 0x40
/* E05E74 80240B14 AFBF00E4 */  sw        $ra, 0xe4($sp)
/* E05E78 80240B18 AFB500DC */  sw        $s5, 0xdc($sp)
/* E05E7C 80240B1C AFB400D8 */  sw        $s4, 0xd8($sp)
/* E05E80 80240B20 AFB300D4 */  sw        $s3, 0xd4($sp)
/* E05E84 80240B24 AFB200D0 */  sw        $s2, 0xd0($sp)
/* E05E88 80240B28 F7BC0108 */  sdc1      $f28, 0x108($sp)
/* E05E8C 80240B2C F7BA0100 */  sdc1      $f26, 0x100($sp)
/* E05E90 80240B30 F7B800F8 */  sdc1      $f24, 0xf8($sp)
/* E05E94 80240B34 F7B600F0 */  sdc1      $f22, 0xf0($sp)
/* E05E98 80240B38 F7B400E8 */  sdc1      $f20, 0xe8($sp)
/* E05E9C 80240B3C C6200010 */  lwc1      $f0, 0x10($s1)
/* E05EA0 80240B40 46800020 */  cvt.s.w   $f0, $f0
/* E05EA4 80240B44 8E020068 */  lw        $v0, 0x68($s0)
/* E05EA8 80240B48 8E030014 */  lw        $v1, 0x14($s0)
/* E05EAC 80240B4C 44060000 */  mfc1      $a2, $f0
/* E05EB0 80240B50 8E07001C */  lw        $a3, 0x1c($s0)
/* E05EB4 80240B54 00431021 */  addu      $v0, $v0, $v1
/* E05EB8 80240B58 2442FFF0 */  addiu     $v0, $v0, -0x10
/* E05EBC 80240B5C 44822000 */  mtc1      $v0, $f4
/* E05EC0 80240B60 00000000 */  nop
/* E05EC4 80240B64 46802120 */  cvt.s.w   $f4, $f4
/* E05EC8 80240B68 8E03006C */  lw        $v1, 0x6c($s0)
/* E05ECC 80240B6C 44052000 */  mfc1      $a1, $f4
/* E05ED0 80240B70 AFA70010 */  sw        $a3, 0x10($sp)
/* E05ED4 80240B74 8E270018 */  lw        $a3, 0x18($s1)
/* E05ED8 80240B78 2463003C */  addiu     $v1, $v1, 0x3c
/* E05EDC 80240B7C 4483A000 */  mtc1      $v1, $f20
/* E05EE0 80240B80 00000000 */  nop
/* E05EE4 80240B84 4680A520 */  cvt.s.w   $f20, $f20
/* E05EE8 80240B88 0C00A8ED */  jal       update_lerp
/* E05EEC 80240B8C 2404000A */   addiu    $a0, $zero, 0xa
/* E05EF0 80240B90 C6220014 */  lwc1      $f2, 0x14($s1)
/* E05EF4 80240B94 468010A0 */  cvt.s.w   $f2, $f2
/* E05EF8 80240B98 4405A000 */  mfc1      $a1, $f20
/* E05EFC 80240B9C 44061000 */  mfc1      $a2, $f2
/* E05F00 80240BA0 8E02001C */  lw        $v0, 0x1c($s0)
/* E05F04 80240BA4 24040005 */  addiu     $a0, $zero, 5
/* E05F08 80240BA8 AFA20010 */  sw        $v0, 0x10($sp)
/* E05F0C 80240BAC 8E270018 */  lw        $a3, 0x18($s1)
/* E05F10 80240BB0 0C00A8ED */  jal       update_lerp
/* E05F14 80240BB4 46000506 */   mov.s    $f20, $f0
/* E05F18 80240BB8 27B50038 */  addiu     $s5, $sp, 0x38
/* E05F1C 80240BBC 8E220018 */  lw        $v0, 0x18($s1)
/* E05F20 80240BC0 8E03001C */  lw        $v1, 0x1c($s0)
/* E05F24 80240BC4 14430004 */  bne       $v0, $v1, .L80240BD8
/* E05F28 80240BC8 46000706 */   mov.s    $f28, $f0
/* E05F2C 80240BCC 4480B000 */  mtc1      $zero, $f22
/* E05F30 80240BD0 080902FD */  j         .L80240BF4
/* E05F34 80240BD4 00000000 */   nop
.L80240BD8:
/* E05F38 80240BD8 00621823 */  subu      $v1, $v1, $v0
/* E05F3C 80240BDC 00031080 */  sll       $v0, $v1, 2
/* E05F40 80240BE0 00431021 */  addu      $v0, $v0, $v1
/* E05F44 80240BE4 00021040 */  sll       $v0, $v0, 1
/* E05F48 80240BE8 4482B000 */  mtc1      $v0, $f22
/* E05F4C 80240BEC 00000000 */  nop
/* E05F50 80240BF0 4680B5A0 */  cvt.s.w   $f22, $f22
.L80240BF4:
/* E05F54 80240BF4 8E02001C */  lw        $v0, 0x1c($s0)
/* E05F58 80240BF8 3C054000 */  lui       $a1, 0x4000
/* E05F5C 80240BFC 3C063F80 */  lui       $a2, 0x3f80
/* E05F60 80240C00 AFA20010 */  sw        $v0, 0x10($sp)
/* E05F64 80240C04 8E270018 */  lw        $a3, 0x18($s1)
/* E05F68 80240C08 0C00A8ED */  jal       update_lerp
/* E05F6C 80240C0C 24040004 */   addiu    $a0, $zero, 4
/* E05F70 80240C10 8E220018 */  lw        $v0, 0x18($s1)
/* E05F74 80240C14 8E04001C */  lw        $a0, 0x1c($s0)
/* E05F78 80240C18 1444000C */  bne       $v0, $a0, .L80240C4C
/* E05F7C 80240C1C 46000686 */   mov.s    $f26, $f0
/* E05F80 80240C20 0000202D */  daddu     $a0, $zero, $zero
/* E05F84 80240C24 0080282D */  daddu     $a1, $a0, $zero
/* E05F88 80240C28 0080302D */  daddu     $a2, $a0, $zero
/* E05F8C 80240C2C 0080382D */  daddu     $a3, $a0, $zero
/* E05F90 80240C30 AFA00010 */  sw        $zero, 0x10($sp)
/* E05F94 80240C34 AFA00014 */  sw        $zero, 0x14($sp)
/* E05F98 80240C38 0C04EAA7 */  jal       func_8013AA9C
/* E05F9C 80240C3C AFA00018 */   sw       $zero, 0x18($sp)
/* E05FA0 80240C40 3C020001 */  lui       $v0, 1
/* E05FA4 80240C44 0809032A */  j         .L80240CA8
/* E05FA8 80240C48 02C2B025 */   or       $s6, $s6, $v0
.L80240C4C:
/* E05FAC 80240C4C 3C054180 */  lui       $a1, 0x4180
/* E05FB0 80240C50 3C064396 */  lui       $a2, 0x4396
/* E05FB4 80240C54 AFA40010 */  sw        $a0, 0x10($sp)
/* E05FB8 80240C58 8E270018 */  lw        $a3, 0x18($s1)
/* E05FBC 80240C5C 0C00A8ED */  jal       update_lerp
/* E05FC0 80240C60 0000202D */   daddu    $a0, $zero, $zero
/* E05FC4 80240C64 3C01437F */  lui       $at, 0x437f
/* E05FC8 80240C68 44811000 */  mtc1      $at, $f2
/* E05FCC 80240C6C 00000000 */  nop
/* E05FD0 80240C70 4600103C */  c.lt.s    $f2, $f0
/* E05FD4 80240C74 00000000 */  nop
/* E05FD8 80240C78 45030001 */  bc1tl     .L80240C80
/* E05FDC 80240C7C 46001006 */   mov.s    $f0, $f2
.L80240C80:
/* E05FE0 80240C80 4600010D */  trunc.w.s $f4, $f0
/* E05FE4 80240C84 E7A40014 */  swc1      $f4, 0x14($sp)
/* E05FE8 80240C88 0000202D */  daddu     $a0, $zero, $zero
/* E05FEC 80240C8C 24050007 */  addiu     $a1, $zero, 7
/* E05FF0 80240C90 240600FF */  addiu     $a2, $zero, 0xff
/* E05FF4 80240C94 00C0382D */  daddu     $a3, $a2, $zero
/* E05FF8 80240C98 00C0102D */  daddu     $v0, $a2, $zero
/* E05FFC 80240C9C AFA20010 */  sw        $v0, 0x10($sp)
/* E06000 80240CA0 0C04EAA7 */  jal       func_8013AA9C
/* E06004 80240CA4 AFA00018 */   sw       $zero, 0x18($sp)
.L80240CA8:
/* E06008 80240CA8 AFB50010 */  sw        $s5, 0x10($sp)
/* E0600C 80240CAC 8E240004 */  lw        $a0, 4($s1)
/* E06010 80240CB0 8E250008 */  lw        $a1, 8($s1)
/* E06014 80240CB4 8E260000 */  lw        $a2, ($s1)
/* E06018 80240CB8 8E27000C */  lw        $a3, 0xc($s1)
/* E0601C 80240CBC 0C04BA38 */  jal       func_8012E8E0
/* E06020 80240CC0 3C140001 */   lui      $s4, 1
/* E06024 80240CC4 92A2000A */  lbu       $v0, 0xa($s5)
/* E06028 80240CC8 3C013FE0 */  lui       $at, 0x3fe0
/* E0602C 80240CCC 4481C800 */  mtc1      $at, $f25
/* E06030 80240CD0 4480C000 */  mtc1      $zero, $f24
/* E06034 80240CD4 44820000 */  mtc1      $v0, $f0
/* E06038 80240CD8 00000000 */  nop
/* E0603C 80240CDC 46800021 */  cvt.d.w   $f0, $f0
/* E06040 80240CE0 46380002 */  mul.d     $f0, $f0, $f24
/* E06044 80240CE4 00000000 */  nop
/* E06048 80240CE8 36941630 */  ori       $s4, $s4, 0x1630
/* E0604C 80240CEC 4600A0A1 */  cvt.d.s   $f2, $f20
/* E06050 80240CF0 27B10048 */  addiu     $s1, $sp, 0x48
/* E06054 80240CF4 4600E707 */  neg.s     $f28, $f28
/* E06058 80240CF8 4480A000 */  mtc1      $zero, $f20
/* E0605C 80240CFC 46201080 */  add.d     $f2, $f2, $f0
/* E06060 80240D00 4406E000 */  mfc1      $a2, $f28
/* E06064 80240D04 4407A000 */  mfc1      $a3, $f20
/* E06068 80240D08 462010A0 */  cvt.s.d   $f2, $f2
/* E0606C 80240D0C 44051000 */  mfc1      $a1, $f2
/* E06070 80240D10 0C019E40 */  jal       guTranslateF
/* E06074 80240D14 0220202D */   daddu    $a0, $s1, $zero
/* E06078 80240D18 27B00088 */  addiu     $s0, $sp, 0x88
/* E0607C 80240D1C 4405B000 */  mfc1      $a1, $f22
/* E06080 80240D20 3C013F80 */  lui       $at, 0x3f80
/* E06084 80240D24 4481B000 */  mtc1      $at, $f22
/* E06088 80240D28 4406A000 */  mfc1      $a2, $f20
/* E0608C 80240D2C 3C013E4C */  lui       $at, 0x3e4c
/* E06090 80240D30 3421CCCD */  ori       $at, $at, 0xcccd
/* E06094 80240D34 44810000 */  mtc1      $at, $f0
/* E06098 80240D38 4407B000 */  mfc1      $a3, $f22
/* E0609C 80240D3C 0200202D */  daddu     $a0, $s0, $zero
/* E060A0 80240D40 0C019EC8 */  jal       guRotateF
/* E060A4 80240D44 E7A00010 */   swc1     $f0, 0x10($sp)
/* E060A8 80240D48 0200202D */  daddu     $a0, $s0, $zero
/* E060AC 80240D4C 0220282D */  daddu     $a1, $s1, $zero
/* E060B0 80240D50 0C019D80 */  jal       guMtxCatF
/* E060B4 80240D54 0220302D */   daddu    $a2, $s1, $zero
/* E060B8 80240D58 0200202D */  daddu     $a0, $s0, $zero
/* E060BC 80240D5C 4405D000 */  mfc1      $a1, $f26
/* E060C0 80240D60 4407B000 */  mfc1      $a3, $f22
/* E060C4 80240D64 0C019DF0 */  jal       guScaleF
/* E060C8 80240D68 00A0302D */   daddu    $a2, $a1, $zero
/* E060CC 80240D6C 0200202D */  daddu     $a0, $s0, $zero
/* E060D0 80240D70 0220282D */  daddu     $a1, $s1, $zero
/* E060D4 80240D74 0C019D80 */  jal       guMtxCatF
/* E060D8 80240D78 0220302D */   daddu    $a2, $s1, $zero
/* E060DC 80240D7C 0220202D */  daddu     $a0, $s1, $zero
/* E060E0 80240D80 3C108007 */  lui       $s0, %hi(gMatrixListPos)
/* E060E4 80240D84 261041F0 */  addiu     $s0, $s0, %lo(gMatrixListPos)
/* E060E8 80240D88 3C13800A */  lui       $s3, %hi(gDisplayContext)
/* E060EC 80240D8C 2673A674 */  addiu     $s3, $s3, %lo(gDisplayContext)
/* E060F0 80240D90 96050000 */  lhu       $a1, ($s0)
/* E060F4 80240D94 8E620000 */  lw        $v0, ($s3)
/* E060F8 80240D98 00052980 */  sll       $a1, $a1, 6
/* E060FC 80240D9C 00B42821 */  addu      $a1, $a1, $s4
/* E06100 80240DA0 0C019D40 */  jal       guMtxF2L
/* E06104 80240DA4 00452821 */   addu     $a1, $v0, $a1
/* E06108 80240DA8 3C02DA38 */  lui       $v0, 0xda38
/* E0610C 80240DAC 34420002 */  ori       $v0, $v0, 2
/* E06110 80240DB0 3C12800A */  lui       $s2, %hi(gMasterGfxPos)
/* E06114 80240DB4 2652A66C */  addiu     $s2, $s2, %lo(gMasterGfxPos)
/* E06118 80240DB8 8E440000 */  lw        $a0, ($s2)
/* E0611C 80240DBC 96050000 */  lhu       $a1, ($s0)
/* E06120 80240DC0 0080302D */  daddu     $a2, $a0, $zero
/* E06124 80240DC4 ACC20000 */  sw        $v0, ($a2)
/* E06128 80240DC8 30A2FFFF */  andi      $v0, $a1, 0xffff
/* E0612C 80240DCC 00021180 */  sll       $v0, $v0, 6
/* E06130 80240DD0 8E630000 */  lw        $v1, ($s3)
/* E06134 80240DD4 00541021 */  addu      $v0, $v0, $s4
/* E06138 80240DD8 00621821 */  addu      $v1, $v1, $v0
/* E0613C 80240DDC 3C028000 */  lui       $v0, 0x8000
/* E06140 80240DE0 00621821 */  addu      $v1, $v1, $v0
/* E06144 80240DE4 ACC30004 */  sw        $v1, 4($a2)
/* E06148 80240DE8 8EA20000 */  lw        $v0, ($s5)
/* E0614C 80240DEC 24840008 */  addiu     $a0, $a0, 8
/* E06150 80240DF0 AE440000 */  sw        $a0, ($s2)
/* E06154 80240DF4 AFA20020 */  sw        $v0, 0x20($sp)
/* E06158 80240DF8 8EA20004 */  lw        $v0, 4($s5)
/* E0615C 80240DFC 24A50001 */  addiu     $a1, $a1, 1
/* E06160 80240E00 A6050000 */  sh        $a1, ($s0)
/* E06164 80240E04 AFA20024 */  sw        $v0, 0x24($sp)
/* E06168 80240E08 92A20008 */  lbu       $v0, 8($s5)
/* E0616C 80240E0C A7A20028 */  sh        $v0, 0x28($sp)
/* E06170 80240E10 92A20009 */  lbu       $v0, 9($s5)
/* E06174 80240E14 A7A2002A */  sh        $v0, 0x2a($sp)
/* E06178 80240E18 92A2000A */  lbu       $v0, 0xa($s5)
/* E0617C 80240E1C 44820000 */  mtc1      $v0, $f0
/* E06180 80240E20 00000000 */  nop
/* E06184 80240E24 46800021 */  cvt.d.w   $f0, $f0
/* E06188 80240E28 46380002 */  mul.d     $f0, $f0, $f24
/* E0618C 80240E2C 00000000 */  nop
/* E06190 80240E30 0220382D */  daddu     $a3, $s1, $zero
/* E06194 80240E34 0000202D */  daddu     $a0, $zero, $zero
/* E06198 80240E38 02C0302D */  daddu     $a2, $s6, $zero
/* E0619C 80240E3C 27A50020 */  addiu     $a1, $sp, 0x20
/* E061A0 80240E40 A7A0002E */  sh        $zero, 0x2e($sp)
/* E061A4 80240E44 240200FF */  addiu     $v0, $zero, 0xff
/* E061A8 80240E48 A3A20030 */  sb        $v0, 0x30($sp)
/* E061AC 80240E4C 46200007 */  neg.d     $f0, $f0
/* E061B0 80240E50 4620010D */  trunc.w.d $f4, $f0
/* E061B4 80240E54 44022000 */  mfc1      $v0, $f4
/* E061B8 80240E58 0C04EBDC */  jal       func_8013AF70
/* E061BC 80240E5C A7A2002C */   sh       $v0, 0x2c($sp)
/* E061C0 80240E60 3C04D838 */  lui       $a0, 0xd838
/* E061C4 80240E64 8E420000 */  lw        $v0, ($s2)
/* E061C8 80240E68 34840002 */  ori       $a0, $a0, 2
/* E061CC 80240E6C 0040182D */  daddu     $v1, $v0, $zero
/* E061D0 80240E70 24420008 */  addiu     $v0, $v0, 8
/* E061D4 80240E74 AE420000 */  sw        $v0, ($s2)
/* E061D8 80240E78 24020040 */  addiu     $v0, $zero, 0x40
/* E061DC 80240E7C AC640000 */  sw        $a0, ($v1)
/* E061E0 80240E80 AC620004 */  sw        $v0, 4($v1)
/* E061E4 80240E84 8FBF00E4 */  lw        $ra, 0xe4($sp)
/* E061E8 80240E88 8FB600E0 */  lw        $s6, 0xe0($sp)
/* E061EC 80240E8C 8FB500DC */  lw        $s5, 0xdc($sp)
/* E061F0 80240E90 8FB400D8 */  lw        $s4, 0xd8($sp)
/* E061F4 80240E94 8FB300D4 */  lw        $s3, 0xd4($sp)
/* E061F8 80240E98 8FB200D0 */  lw        $s2, 0xd0($sp)
/* E061FC 80240E9C 8FB100CC */  lw        $s1, 0xcc($sp)
/* E06200 80240EA0 8FB000C8 */  lw        $s0, 0xc8($sp)
/* E06204 80240EA4 D7BC0108 */  ldc1      $f28, 0x108($sp)
/* E06208 80240EA8 D7BA0100 */  ldc1      $f26, 0x100($sp)
/* E0620C 80240EAC D7B800F8 */  ldc1      $f24, 0xf8($sp)
/* E06210 80240EB0 D7B600F0 */  ldc1      $f22, 0xf0($sp)
/* E06214 80240EB4 D7B400E8 */  ldc1      $f20, 0xe8($sp)
/* E06218 80240EB8 03E00008 */  jr        $ra
/* E0621C 80240EBC 27BD0110 */   addiu    $sp, $sp, 0x110
