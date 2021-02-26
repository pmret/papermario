.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80052B0C
/* 2DF0C 80052B0C 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 2DF10 80052B10 AFB60040 */  sw        $s6, 0x40($sp)
/* 2DF14 80052B14 0080B02D */  daddu     $s6, $a0, $zero
/* 2DF18 80052B18 24050001 */  addiu     $a1, $zero, 1
/* 2DF1C 80052B1C 3C028008 */  lui       $v0, %hi(D_80078E24)
/* 2DF20 80052B20 8C428E24 */  lw        $v0, %lo(D_80078E24)($v0)
/* 2DF24 80052B24 240619E0 */  addiu     $a2, $zero, 0x19e0
/* 2DF28 80052B28 AFBF0044 */  sw        $ra, 0x44($sp)
/* 2DF2C 80052B2C AFB5003C */  sw        $s5, 0x3c($sp)
/* 2DF30 80052B30 AFB40038 */  sw        $s4, 0x38($sp)
/* 2DF34 80052B34 AFB30034 */  sw        $s3, 0x34($sp)
/* 2DF38 80052B38 AFB20030 */  sw        $s2, 0x30($sp)
/* 2DF3C 80052B3C AFB1002C */  sw        $s1, 0x2c($sp)
/* 2DF40 80052B40 AFB00028 */  sw        $s0, 0x28($sp)
/* 2DF44 80052B44 8C550018 */  lw        $s5, 0x18($v0)
/* 2DF48 80052B48 0000982D */  daddu     $s3, $zero, $zero
/* 2DF4C 80052B4C 0C015F10 */  jal       func_80057C40
/* 2DF50 80052B50 02A0202D */   daddu    $a0, $s5, $zero
/* 2DF54 80052B54 02A0202D */  daddu     $a0, $s5, $zero
/* 2DF58 80052B58 24050001 */  addiu     $a1, $zero, 1
/* 2DF5C 80052B5C 24060A9C */  addiu     $a2, $zero, 0xa9c
/* 2DF60 80052B60 3C12800A */  lui       $s2, %hi(D_8009A5A0)
/* 2DF64 80052B64 2652A5A0 */  addiu     $s2, $s2, %lo(D_8009A5A0)
/* 2DF68 80052B68 0C015F10 */  jal       func_80057C40
/* 2DF6C 80052B6C AE420000 */   sw       $v0, ($s2)
/* 2DF70 80052B70 02A0202D */  daddu     $a0, $s5, $zero
/* 2DF74 80052B74 24050001 */  addiu     $a1, $zero, 1
/* 2DF78 80052B78 24060A9C */  addiu     $a2, $zero, 0xa9c
/* 2DF7C 80052B7C 3C11800A */  lui       $s1, %hi(D_8009A644)
/* 2DF80 80052B80 2631A644 */  addiu     $s1, $s1, %lo(D_8009A644)
/* 2DF84 80052B84 0C015F10 */  jal       func_80057C40
/* 2DF88 80052B88 AE220000 */   sw       $v0, ($s1)
/* 2DF8C 80052B8C 02A0202D */  daddu     $a0, $s5, $zero
/* 2DF90 80052B90 24050001 */  addiu     $a1, $zero, 1
/* 2DF94 80052B94 3C01800A */  lui       $at, %hi(D_8009A5DC)
/* 2DF98 80052B98 AC22A5DC */  sw        $v0, %lo(D_8009A5DC)($at)
/* 2DF9C 80052B9C 0C015F10 */  jal       func_80057C40
/* 2DFA0 80052BA0 24060A9C */   addiu    $a2, $zero, 0xa9c
/* 2DFA4 80052BA4 02A0202D */  daddu     $a0, $s5, $zero
/* 2DFA8 80052BA8 24050001 */  addiu     $a1, $zero, 1
/* 2DFAC 80052BAC 3C01800A */  lui       $at, %hi(D_8009A5AC)
/* 2DFB0 80052BB0 AC22A5AC */  sw        $v0, %lo(D_8009A5AC)($at)
/* 2DFB4 80052BB4 0C015F10 */  jal       func_80057C40
/* 2DFB8 80052BB8 240606CC */   addiu    $a2, $zero, 0x6cc
/* 2DFBC 80052BBC 02A0202D */  daddu     $a0, $s5, $zero
/* 2DFC0 80052BC0 24050001 */  addiu     $a1, $zero, 1
/* 2DFC4 80052BC4 24060834 */  addiu     $a2, $zero, 0x834
/* 2DFC8 80052BC8 3C10800A */  lui       $s0, %hi(D_8009A620)
/* 2DFCC 80052BCC 2610A620 */  addiu     $s0, $s0, %lo(D_8009A620)
/* 2DFD0 80052BD0 0C015F10 */  jal       func_80057C40
/* 2DFD4 80052BD4 AE020000 */   sw       $v0, ($s0)
/* 2DFD8 80052BD8 02A0202D */  daddu     $a0, $s5, $zero
/* 2DFDC 80052BDC 24050001 */  addiu     $a1, $zero, 1
/* 2DFE0 80052BE0 8E280000 */  lw        $t0, ($s1)
/* 2DFE4 80052BE4 8E070000 */  lw        $a3, ($s0)
/* 2DFE8 80052BE8 8E430000 */  lw        $v1, ($s2)
/* 2DFEC 80052BEC 34068000 */  ori       $a2, $zero, 0x8000
/* 2DFF0 80052BF0 3C01800A */  lui       $at, %hi(D_8009A608)
/* 2DFF4 80052BF4 AC22A608 */  sw        $v0, %lo(D_8009A608)($at)
/* 2DFF8 80052BF8 0060A02D */  daddu     $s4, $v1, $zero
/* 2DFFC 80052BFC AD070004 */  sw        $a3, 4($t0)
/* 2E000 80052C00 0C015F10 */  jal       func_80057C40
/* 2E004 80052C04 AC430000 */   sw       $v1, ($v0)
/* 2E008 80052C08 0280802D */  daddu     $s0, $s4, $zero
/* 2E00C 80052C0C 24435000 */  addiu     $v1, $v0, 0x5000
/* 2E010 80052C10 AE82005C */  sw        $v0, 0x5c($s4)
/* 2E014 80052C14 24427000 */  addiu     $v0, $v0, 0x7000
/* 2E018 80052C18 AE830060 */  sw        $v1, 0x60($s4)
/* 2E01C 80052C1C AE820064 */  sw        $v0, 0x64($s4)
/* 2E020 80052C20 AE830068 */  sw        $v1, 0x68($s4)
.L80052C24:
/* 2E024 80052C24 02A0202D */  daddu     $a0, $s5, $zero
/* 2E028 80052C28 24050001 */  addiu     $a1, $zero, 1
/* 2E02C 80052C2C 0C015F10 */  jal       func_80057C40
/* 2E030 80052C30 24060A9C */   addiu    $a2, $zero, 0xa9c
/* 2E034 80052C34 AE02006C */  sw        $v0, 0x6c($s0)
/* 2E038 80052C38 26730001 */  addiu     $s3, $s3, 1
/* 2E03C 80052C3C 1260FFF9 */  beqz      $s3, .L80052C24
/* 2E040 80052C40 26100008 */   addiu    $s0, $s0, 8
/* 2E044 80052C44 02A0202D */  daddu     $a0, $s5, $zero
/* 2E048 80052C48 24050001 */  addiu     $a1, $zero, 1
/* 2E04C 80052C4C 0C015F10 */  jal       func_80057C40
/* 2E050 80052C50 24065200 */   addiu    $a2, $zero, 0x5200
/* 2E054 80052C54 02A0202D */  daddu     $a0, $s5, $zero
/* 2E058 80052C58 24050001 */  addiu     $a1, $zero, 1
/* 2E05C 80052C5C 24060030 */  addiu     $a2, $zero, 0x30
/* 2E060 80052C60 0C015F10 */  jal       func_80057C40
/* 2E064 80052C64 AE8200A0 */   sw       $v0, 0xa0($s4)
/* 2E068 80052C68 02A0202D */  daddu     $a0, $s5, $zero
/* 2E06C 80052C6C 24050001 */  addiu     $a1, $zero, 1
/* 2E070 80052C70 24060360 */  addiu     $a2, $zero, 0x360
/* 2E074 80052C74 0C015F10 */  jal       func_80057C40
/* 2E078 80052C78 AE820004 */   sw       $v0, 4($s4)
/* 2E07C 80052C7C 02A0202D */  daddu     $a0, $s5, $zero
/* 2E080 80052C80 24050001 */  addiu     $a1, $zero, 1
/* 2E084 80052C84 24060200 */  addiu     $a2, $zero, 0x200
/* 2E088 80052C88 0C015F10 */  jal       func_80057C40
/* 2E08C 80052C8C AE820054 */   sw       $v0, 0x54($s4)
/* 2E090 80052C90 02A0202D */  daddu     $a0, $s5, $zero
/* 2E094 80052C94 24050001 */  addiu     $a1, $zero, 1
/* 2E098 80052C98 24060040 */  addiu     $a2, $zero, 0x40
/* 2E09C 80052C9C 0C015F10 */  jal       func_80057C40
/* 2E0A0 80052CA0 AE820058 */   sw       $v0, 0x58($s4)
/* 2E0A4 80052CA4 0000982D */  daddu     $s3, $zero, $zero
/* 2E0A8 80052CA8 8E840004 */  lw        $a0, 4($s4)
/* 2E0AC 80052CAC 44960000 */  mtc1      $s6, $f0
/* 2E0B0 80052CB0 00000000 */  nop
/* 2E0B4 80052CB4 46800020 */  cvt.s.w   $f0, $f0
/* 2E0B8 80052CB8 AE820094 */  sw        $v0, 0x94($s4)
/* 2E0BC 80052CBC 0C014BE9 */  jal       func_80052FA4
/* 2E0C0 80052CC0 E6800000 */   swc1     $f0, ($s4)
/* 2E0C4 80052CC4 0C014C08 */  jal       func_80053020
/* 2E0C8 80052CC8 26840008 */   addiu    $a0, $s4, 8
/* 2E0CC 80052CCC 0C014C16 */  jal       func_80053058
/* 2E0D0 80052CD0 26840014 */   addiu    $a0, $s4, 0x14
/* 2E0D4 80052CD4 0C01576F */  jal       func_80055DBC
/* 2E0D8 80052CD8 00000000 */   nop
/* 2E0DC 80052CDC 0280102D */  daddu     $v0, $s4, $zero
/* 2E0E0 80052CE0 AE8000A4 */  sw        $zero, 0xa4($s4)
/* 2E0E4 80052CE4 AE8000A8 */  sw        $zero, 0xa8($s4)
.L80052CE8:
/* 2E0E8 80052CE8 A0400070 */  sb        $zero, 0x70($v0)
/* 2E0EC 80052CEC A0400071 */  sb        $zero, 0x71($v0)
/* 2E0F0 80052CF0 26730001 */  addiu     $s3, $s3, 1
/* 2E0F4 80052CF4 1260FFFC */  beqz      $s3, .L80052CE8
/* 2E0F8 80052CF8 24420008 */   addiu    $v0, $v0, 8
/* 2E0FC 80052CFC 0000982D */  daddu     $s3, $zero, $zero
/* 2E100 80052D00 0280182D */  daddu     $v1, $s4, $zero
.L80052D04:
/* 2E104 80052D04 A0600040 */  sb        $zero, 0x40($v1)
/* 2E108 80052D08 A0600041 */  sb        $zero, 0x41($v1)
/* 2E10C 80052D0C 26730001 */  addiu     $s3, $s3, 1
/* 2E110 80052D10 2E620004 */  sltiu     $v0, $s3, 4
/* 2E114 80052D14 1440FFFB */  bnez      $v0, .L80052D04
/* 2E118 80052D18 24630004 */   addiu    $v1, $v1, 4
/* 2E11C 80052D1C 0000982D */  daddu     $s3, $zero, $zero
/* 2E120 80052D20 2416FFFF */  addiu     $s6, $zero, -1
/* 2E124 80052D24 241200FF */  addiu     $s2, $zero, 0xff
/* 2E128 80052D28 24111320 */  addiu     $s1, $zero, 0x1320
.L80052D2C:
/* 2E12C 80052D2C 327000FF */  andi      $s0, $s3, 0xff
/* 2E130 80052D30 0200202D */  daddu     $a0, $s0, $zero
/* 2E134 80052D34 0C015ADC */  jal       func_80056B70
/* 2E138 80052D38 0000282D */   daddu    $a1, $zero, $zero
/* 2E13C 80052D3C 0200202D */  daddu     $a0, $s0, $zero
/* 2E140 80052D40 8E850004 */  lw        $a1, 4($s4)
/* 2E144 80052D44 0C015BB5 */  jal       func_80056ED4
/* 2E148 80052D48 26730001 */   addiu    $s3, $s3, 1
/* 2E14C 80052D4C 02911021 */  addu      $v0, $s4, $s1
/* 2E150 80052D50 AC400000 */  sw        $zero, ($v0)
/* 2E154 80052D54 AC400004 */  sw        $zero, 4($v0)
/* 2E158 80052D58 A456000C */  sh        $s6, 0xc($v0)
/* 2E15C 80052D5C A052000E */  sb        $s2, 0xe($v0)
/* 2E160 80052D60 A052000F */  sb        $s2, 0xf($v0)
/* 2E164 80052D64 A0400010 */  sb        $zero, 0x10($v0)
/* 2E168 80052D68 A0400042 */  sb        $zero, 0x42($v0)
/* 2E16C 80052D6C A0400043 */  sb        $zero, 0x43($v0)
/* 2E170 80052D70 A0400044 */  sb        $zero, 0x44($v0)
/* 2E174 80052D74 A0400045 */  sb        $zero, 0x45($v0)
/* 2E178 80052D78 2E620018 */  sltiu     $v0, $s3, 0x18
/* 2E17C 80052D7C 1440FFEB */  bnez      $v0, .L80052D2C
/* 2E180 80052D80 26310048 */   addiu    $s1, $s1, 0x48
/* 2E184 80052D84 0280202D */  daddu     $a0, $s4, $zero
/* 2E188 80052D88 3C0500FC */  lui       $a1, 0xfc
/* 2E18C 80052D8C 0C014FDB */  jal       func_80053F6C
/* 2E190 80052D90 02A0302D */   daddu    $a2, $s5, $zero
/* 2E194 80052D94 0000982D */  daddu     $s3, $zero, $zero
/* 2E198 80052D98 0280802D */  daddu     $s0, $s4, $zero
.L80052D9C:
/* 2E19C 80052D9C 02A0202D */  daddu     $a0, $s5, $zero
/* 2E1A0 80052DA0 24050001 */  addiu     $a1, $zero, 1
/* 2E1A4 80052DA4 0C015F10 */  jal       func_80057C40
/* 2E1A8 80052DA8 24060840 */   addiu    $a2, $zero, 0x840
/* 2E1AC 80052DAC AE021310 */  sw        $v0, 0x1310($s0)
/* 2E1B0 80052DB0 26730001 */  addiu     $s3, $s3, 1
/* 2E1B4 80052DB4 2E620003 */  sltiu     $v0, $s3, 3
/* 2E1B8 80052DB8 1440FFF8 */  bnez      $v0, .L80052D9C
/* 2E1BC 80052DBC 26100004 */   addiu    $s0, $s0, 4
/* 2E1C0 80052DC0 24050001 */  addiu     $a1, $zero, 1
/* 2E1C4 80052DC4 0000302D */  daddu     $a2, $zero, $zero
/* 2E1C8 80052DC8 3C10800A */  lui       $s0, %hi(D_8009A644)
/* 2E1CC 80052DCC 2610A644 */  addiu     $s0, $s0, %lo(D_8009A644)
/* 2E1D0 80052DD0 8E040000 */  lw        $a0, ($s0)
/* 2E1D4 80052DD4 0C013782 */  jal       func_8004DE08
/* 2E1D8 80052DD8 0280382D */   daddu    $a3, $s4, $zero
/* 2E1DC 80052DDC 27B20020 */  addiu     $s2, $sp, 0x20
/* 2E1E0 80052DE0 0240282D */  daddu     $a1, $s2, $zero
/* 2E1E4 80052DE4 24020003 */  addiu     $v0, $zero, 3
/* 2E1E8 80052DE8 8E040000 */  lw        $a0, ($s0)
/* 2E1EC 80052DEC 241000FF */  addiu     $s0, $zero, 0xff
/* 2E1F0 80052DF0 A3A00020 */  sb        $zero, 0x20($sp)
/* 2E1F4 80052DF4 A3A20021 */  sb        $v0, 0x21($sp)
/* 2E1F8 80052DF8 A3B00022 */  sb        $s0, 0x22($sp)
/* 2E1FC 80052DFC 0C0137FD */  jal       func_8004DFF4
/* 2E200 80052E00 A3B00023 */   sb       $s0, 0x23($sp)
/* 2E204 80052E04 24050002 */  addiu     $a1, $zero, 2
/* 2E208 80052E08 00A0302D */  daddu     $a2, $a1, $zero
/* 2E20C 80052E0C 3C11800A */  lui       $s1, %hi(D_8009A5DC)
/* 2E210 80052E10 2631A5DC */  addiu     $s1, $s1, %lo(D_8009A5DC)
/* 2E214 80052E14 8E240000 */  lw        $a0, ($s1)
/* 2E218 80052E18 0C013782 */  jal       func_8004DE08
/* 2E21C 80052E1C 0280382D */   daddu    $a3, $s4, $zero
/* 2E220 80052E20 0240282D */  daddu     $a1, $s2, $zero
/* 2E224 80052E24 8E240000 */  lw        $a0, ($s1)
/* 2E228 80052E28 24020002 */  addiu     $v0, $zero, 2
/* 2E22C 80052E2C A3A20020 */  sb        $v0, 0x20($sp)
/* 2E230 80052E30 A3B00021 */  sb        $s0, 0x21($sp)
/* 2E234 80052E34 A3B00022 */  sb        $s0, 0x22($sp)
/* 2E238 80052E38 0C0137FD */  jal       func_8004DFF4
/* 2E23C 80052E3C A3B00023 */   sb       $s0, 0x23($sp)
/* 2E240 80052E40 24050004 */  addiu     $a1, $zero, 4
/* 2E244 80052E44 24060001 */  addiu     $a2, $zero, 1
/* 2E248 80052E48 0280382D */  daddu     $a3, $s4, $zero
/* 2E24C 80052E4C 3C10800A */  lui       $s0, %hi(D_8009A620)
/* 2E250 80052E50 2610A620 */  addiu     $s0, $s0, %lo(D_8009A620)
/* 2E254 80052E54 8E040000 */  lw        $a0, ($s0)
/* 2E258 80052E58 24020010 */  addiu     $v0, $zero, 0x10
/* 2E25C 80052E5C 0C012C3C */  jal       func_8004B0F0
/* 2E260 80052E60 AFA20010 */   sw       $v0, 0x10($sp)
/* 2E264 80052E64 24050006 */  addiu     $a1, $zero, 6
/* 2E268 80052E68 24060001 */  addiu     $a2, $zero, 1
/* 2E26C 80052E6C 3C04800A */  lui       $a0, %hi(D_8009A608)
/* 2E270 80052E70 8C84A608 */  lw        $a0, %lo(D_8009A608)($a0)
/* 2E274 80052E74 0C014210 */  jal       func_80050840
/* 2E278 80052E78 0280382D */   daddu    $a3, $s4, $zero
/* 2E27C 80052E7C 0C0148B1 */  jal       func_800522C4
/* 2E280 80052E80 0280202D */   daddu    $a0, $s4, $zero
/* 2E284 80052E84 0280202D */  daddu     $a0, $s4, $zero
/* 2E288 80052E88 0C01531C */  jal       func_80054C70
/* 2E28C 80052E8C 02A0282D */   daddu    $a1, $s5, $zero
/* 2E290 80052E90 8E82003C */  lw        $v0, 0x3c($s4)
/* 2E294 80052E94 24050020 */  addiu     $a1, $zero, 0x20
/* 2E298 80052E98 94440000 */  lhu       $a0, ($v0)
/* 2E29C 80052E9C 0C01504B */  jal       func_8005412C
/* 2E2A0 80052EA0 27A60018 */   addiu    $a2, $sp, 0x18
/* 2E2A4 80052EA4 14400007 */  bnez      $v0, .L80052EC4
/* 2E2A8 80052EA8 3C0200FF */   lui      $v0, 0xff
/* 2E2AC 80052EAC 3442FFFF */  ori       $v0, $v0, 0xffff
/* 2E2B0 80052EB0 8FA40018 */  lw        $a0, 0x18($sp)
/* 2E2B4 80052EB4 8FA6001C */  lw        $a2, 0x1c($sp)
/* 2E2B8 80052EB8 8E8500A0 */  lw        $a1, 0xa0($s4)
/* 2E2BC 80052EBC 0C0152AC */  jal       func_80054AB0
/* 2E2C0 80052EC0 00C23024 */   and      $a2, $a2, $v0
.L80052EC4:
/* 2E2C4 80052EC4 8E040000 */  lw        $a0, ($s0)
/* 2E2C8 80052EC8 0C012CB7 */  jal       func_8004B2DC
/* 2E2CC 80052ECC 00000000 */   nop
/* 2E2D0 80052ED0 8E82003C */  lw        $v0, 0x3c($s4)
/* 2E2D4 80052ED4 24050040 */  addiu     $a1, $zero, 0x40
/* 2E2D8 80052ED8 94440002 */  lhu       $a0, 2($v0)
/* 2E2DC 80052EDC 0C01504B */  jal       func_8005412C
/* 2E2E0 80052EE0 27A60018 */   addiu    $a2, $sp, 0x18
/* 2E2E4 80052EE4 14400004 */  bnez      $v0, .L80052EF8
/* 2E2E8 80052EE8 00000000 */   nop
/* 2E2EC 80052EEC 8FA50018 */  lw        $a1, 0x18($sp)
/* 2E2F0 80052EF0 0C01506A */  jal       func_800541A8
/* 2E2F4 80052EF4 0280202D */   daddu    $a0, $s4, $zero
.L80052EF8:
/* 2E2F8 80052EF8 8E82003C */  lw        $v0, 0x3c($s4)
/* 2E2FC 80052EFC 24050040 */  addiu     $a1, $zero, 0x40
/* 2E300 80052F00 94440004 */  lhu       $a0, 4($v0)
/* 2E304 80052F04 0C01504B */  jal       func_8005412C
/* 2E308 80052F08 27A60018 */   addiu    $a2, $sp, 0x18
/* 2E30C 80052F0C 54400005 */  bnel      $v0, $zero, .L80052F24
/* 2E310 80052F10 0000202D */   daddu    $a0, $zero, $zero
/* 2E314 80052F14 8FA50018 */  lw        $a1, 0x18($sp)
/* 2E318 80052F18 0C015099 */  jal       func_80054264
/* 2E31C 80052F1C 0280202D */   daddu    $a0, $s4, $zero
/* 2E320 80052F20 0000202D */  daddu     $a0, $zero, $zero
.L80052F24:
/* 2E324 80052F24 268304EC */  addiu     $v1, $s4, 0x4ec
/* 2E328 80052F28 268205EC */  addiu     $v0, $s4, 0x5ec
/* 2E32C 80052F2C AE8212F0 */  sw        $v0, 0x12f0($s4)
/* 2E330 80052F30 268200AC */  addiu     $v0, $s4, 0xac
/* 2E334 80052F34 AE8212F4 */  sw        $v0, 0x12f4($s4)
/* 2E338 80052F38 268200EC */  addiu     $v0, $s4, 0xec
/* 2E33C 80052F3C AE8212F8 */  sw        $v0, 0x12f8($s4)
/* 2E340 80052F40 268209EC */  addiu     $v0, $s4, 0x9ec
/* 2E344 80052F44 AE8212FC */  sw        $v0, 0x12fc($s4)
/* 2E348 80052F48 26820DEC */  addiu     $v0, $s4, 0xdec
/* 2E34C 80052F4C AE821300 */  sw        $v0, 0x1300($s4)
/* 2E350 80052F50 268211EC */  addiu     $v0, $s4, 0x11ec
/* 2E354 80052F54 AE8312EC */  sw        $v1, 0x12ec($s4)
/* 2E358 80052F58 AE821304 */  sw        $v0, 0x1304($s4)
/* 2E35C 80052F5C AE831308 */  sw        $v1, 0x1308($s4)
/* 2E360 80052F60 A2800053 */  sb        $zero, 0x53($s4)
/* 2E364 80052F64 A2800052 */  sb        $zero, 0x52($s4)
/* 2E368 80052F68 A2800051 */  sb        $zero, 0x51($s4)
/* 2E36C 80052F6C 0C015EE0 */  jal       func_80057B80
/* 2E370 80052F70 A2800050 */   sb       $zero, 0x50($s4)
/* 2E374 80052F74 0C015340 */  jal       func_80054D00
/* 2E378 80052F78 02A0202D */   daddu    $a0, $s5, $zero
/* 2E37C 80052F7C 8FBF0044 */  lw        $ra, 0x44($sp)
/* 2E380 80052F80 8FB60040 */  lw        $s6, 0x40($sp)
/* 2E384 80052F84 8FB5003C */  lw        $s5, 0x3c($sp)
/* 2E388 80052F88 8FB40038 */  lw        $s4, 0x38($sp)
/* 2E38C 80052F8C 8FB30034 */  lw        $s3, 0x34($sp)
/* 2E390 80052F90 8FB20030 */  lw        $s2, 0x30($sp)
/* 2E394 80052F94 8FB1002C */  lw        $s1, 0x2c($sp)
/* 2E398 80052F98 8FB00028 */  lw        $s0, 0x28($sp)
/* 2E39C 80052F9C 03E00008 */  jr        $ra
/* 2E3A0 80052FA0 27BD0048 */   addiu    $sp, $sp, 0x48
