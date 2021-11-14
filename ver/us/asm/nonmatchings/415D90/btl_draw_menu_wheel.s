.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

dlabel jtbl_802AB770
.word L802A1DB4_416B44, L802A2644_4173D4, L802A1CC4_416A54, L802A1DB4_416B44, L802A2644_4173D4, L802A2644_4173D4, L802A2644_4173D4, L802A2644_4173D4, L802A2644_4173D4, L802A2644_4173D4, L802A2644_4173D4, L802A1DB4_416B44, L802A2644_4173D4, L802A2644_4173D4, L802A2644_4173D4, L802A2644_4173D4, L802A2644_4173D4, L802A2644_4173D4, L802A2644_4173D4, L802A2644_4173D4, L802A2644_4173D4, L802A1DB4_416B44, L802A2644_4173D4, L802A2644_4173D4, L802A2644_4173D4, L802A2644_4173D4, L802A2644_4173D4, L802A2644_4173D4, L802A2644_4173D4, L802A2644_4173D4, L802A2644_4173D4, L802A1DB4_416B44

dlabel D_802AB7F0
.double 1.6071428571428572

dlabel D_802AB7F8
.double 22.5

dlabel D_802AB800
.double 0.01

.section .text

glabel btl_draw_menu_wheel
/* 4169E4 802A1C54 3C02802B */  lui       $v0, %hi(D_802AD000)
/* 4169E8 802A1C58 9042D000 */  lbu       $v0, %lo(D_802AD000)($v0)
/* 4169EC 802A1C5C 27BDFF88 */  addiu     $sp, $sp, -0x78
/* 4169F0 802A1C60 AFBF0054 */  sw        $ra, 0x54($sp)
/* 4169F4 802A1C64 AFBE0050 */  sw        $fp, 0x50($sp)
/* 4169F8 802A1C68 AFB7004C */  sw        $s7, 0x4c($sp)
/* 4169FC 802A1C6C AFB60048 */  sw        $s6, 0x48($sp)
/* 416A00 802A1C70 AFB50044 */  sw        $s5, 0x44($sp)
/* 416A04 802A1C74 AFB40040 */  sw        $s4, 0x40($sp)
/* 416A08 802A1C78 AFB3003C */  sw        $s3, 0x3c($sp)
/* 416A0C 802A1C7C AFB20038 */  sw        $s2, 0x38($sp)
/* 416A10 802A1C80 AFB10034 */  sw        $s1, 0x34($sp)
/* 416A14 802A1C84 AFB00030 */  sw        $s0, 0x30($sp)
/* 416A18 802A1C88 F7BA0070 */  sdc1      $f26, 0x70($sp)
/* 416A1C 802A1C8C F7B80068 */  sdc1      $f24, 0x68($sp)
/* 416A20 802A1C90 F7B60060 */  sdc1      $f22, 0x60($sp)
/* 416A24 802A1C94 F7B40058 */  sdc1      $f20, 0x58($sp)
/* 416A28 802A1C98 24420001 */  addiu     $v0, $v0, 1
/* 416A2C 802A1C9C 00021600 */  sll       $v0, $v0, 0x18
/* 416A30 802A1CA0 00021E03 */  sra       $v1, $v0, 0x18
/* 416A34 802A1CA4 2C620020 */  sltiu     $v0, $v1, 0x20
/* 416A38 802A1CA8 10400266 */  beqz      $v0, L802A2644_4173D4
/* 416A3C 802A1CAC 00031080 */   sll      $v0, $v1, 2
/* 416A40 802A1CB0 3C01802B */  lui       $at, %hi(jtbl_802AB770)
/* 416A44 802A1CB4 00220821 */  addu      $at, $at, $v0
/* 416A48 802A1CB8 8C22B770 */  lw        $v0, %lo(jtbl_802AB770)($at)
/* 416A4C 802A1CBC 00400008 */  jr        $v0
/* 416A50 802A1CC0 00000000 */   nop
dlabel L802A1CC4_416A54
/* 416A54 802A1CC4 0C051086 */  jal       func_80144218
/* 416A58 802A1CC8 2404FFFF */   addiu    $a0, $zero, -1
/* 416A5C 802A1CCC 3C128080 */  lui       $s2, 0x8080
/* 416A60 802A1CD0 44800000 */  mtc1      $zero, $f0
/* 416A64 802A1CD4 3C13802B */  lui       $s3, %hi(D_802AD048)
/* 416A68 802A1CD8 8E73D048 */  lw        $s3, %lo(D_802AD048)($s3)
/* 416A6C 802A1CDC 44050000 */  mfc1      $a1, $f0
/* 416A70 802A1CE0 0260202D */  daddu     $a0, $s3, $zero
/* 416A74 802A1CE4 00A0302D */  daddu     $a2, $a1, $zero
/* 416A78 802A1CE8 0C051489 */  jal       set_hud_element_transform_rotation
/* 416A7C 802A1CEC 00A0382D */   daddu    $a3, $a1, $zero
/* 416A80 802A1CF0 3C11802B */  lui       $s1, %hi(D_802AD006)
/* 416A84 802A1CF4 2631D006 */  addiu     $s1, $s1, %lo(D_802AD006)
/* 416A88 802A1CF8 86220000 */  lh        $v0, ($s1)
/* 416A8C 802A1CFC 36528081 */  ori       $s2, $s2, 0x8081
/* 416A90 802A1D00 000229C0 */  sll       $a1, $v0, 7
/* 416A94 802A1D04 00A22823 */  subu      $a1, $a1, $v0
/* 416A98 802A1D08 00052840 */  sll       $a1, $a1, 1
/* 416A9C 802A1D0C 00B20018 */  mult      $a1, $s2
/* 416AA0 802A1D10 0260202D */  daddu     $a0, $s3, $zero
/* 416AA4 802A1D14 00004010 */  mfhi      $t0
/* 416AA8 802A1D18 01051021 */  addu      $v0, $t0, $a1
/* 416AAC 802A1D1C 000211C3 */  sra       $v0, $v0, 7
/* 416AB0 802A1D20 00052FC3 */  sra       $a1, $a1, 0x1f
/* 416AB4 802A1D24 0C0513AC */  jal       set_hud_element_alpha
/* 416AB8 802A1D28 00452823 */   subu     $a1, $v0, $a1
/* 416ABC 802A1D2C 0260202D */  daddu     $a0, $s3, $zero
/* 416AC0 802A1D30 3C10802B */  lui       $s0, %hi(D_802AD00A)
/* 416AC4 802A1D34 2610D00A */  addiu     $s0, $s0, %lo(D_802AD00A)
/* 416AC8 802A1D38 86060000 */  lh        $a2, ($s0)
/* 416ACC 802A1D3C 24050F64 */  addiu     $a1, $zero, 0xf64
/* 416AD0 802A1D40 00A62823 */  subu      $a1, $a1, $a2
/* 416AD4 802A1D44 0C051261 */  jal       set_hud_element_render_pos
/* 416AD8 802A1D48 24C600D4 */   addiu    $a2, $a2, 0xd4
/* 416ADC 802A1D4C 0C05108E */  jal       func_80144238
/* 416AE0 802A1D50 0260202D */   daddu    $a0, $s3, $zero
/* 416AE4 802A1D54 86220000 */  lh        $v0, ($s1)
/* 416AE8 802A1D58 000229C0 */  sll       $a1, $v0, 7
/* 416AEC 802A1D5C 00A22823 */  subu      $a1, $a1, $v0
/* 416AF0 802A1D60 00052840 */  sll       $a1, $a1, 1
/* 416AF4 802A1D64 00B20018 */  mult      $a1, $s2
/* 416AF8 802A1D68 3C13802B */  lui       $s3, %hi(D_802AD044)
/* 416AFC 802A1D6C 8E73D044 */  lw        $s3, %lo(D_802AD044)($s3)
/* 416B00 802A1D70 0260202D */  daddu     $a0, $s3, $zero
/* 416B04 802A1D74 00004010 */  mfhi      $t0
/* 416B08 802A1D78 01051021 */  addu      $v0, $t0, $a1
/* 416B0C 802A1D7C 000211C3 */  sra       $v0, $v0, 7
/* 416B10 802A1D80 00052FC3 */  sra       $a1, $a1, 0x1f
/* 416B14 802A1D84 0C0513AC */  jal       set_hud_element_alpha
/* 416B18 802A1D88 00452823 */   subu     $a1, $v0, $a1
/* 416B1C 802A1D8C 0260202D */  daddu     $a0, $s3, $zero
/* 416B20 802A1D90 86060000 */  lh        $a2, ($s0)
/* 416B24 802A1D94 24050028 */  addiu     $a1, $zero, 0x28
/* 416B28 802A1D98 00A62823 */  subu      $a1, $a1, $a2
/* 416B2C 802A1D9C 0C051261 */  jal       set_hud_element_render_pos
/* 416B30 802A1DA0 24C600D4 */   addiu    $a2, $a2, 0xd4
/* 416B34 802A1DA4 0C05108E */  jal       func_80144238
/* 416B38 802A1DA8 0260202D */   daddu    $a0, $s3, $zero
/* 416B3C 802A1DAC 080A8991 */  j         L802A2644_4173D4
/* 416B40 802A1DB0 00000000 */   nop
dlabel L802A1DB4_416B44
/* 416B44 802A1DB4 3C03802B */  lui       $v1, %hi(D_802AD006)
/* 416B48 802A1DB8 8463D006 */  lh        $v1, %lo(D_802AD006)($v1)
/* 416B4C 802A1DBC 3C02802B */  lui       $v0, %hi(D_802AD008)
/* 416B50 802A1DC0 8442D008 */  lh        $v0, %lo(D_802AD008)($v0)
/* 416B54 802A1DC4 00620018 */  mult      $v1, $v0
/* 416B58 802A1DC8 00001812 */  mflo      $v1
/* 416B5C 802A1DCC 3C028080 */  lui       $v0, 0x8080
/* 416B60 802A1DD0 34428081 */  ori       $v0, $v0, 0x8081
/* 416B64 802A1DD4 00620018 */  mult      $v1, $v0
/* 416B68 802A1DD8 2404FFFF */  addiu     $a0, $zero, -1
/* 416B6C 802A1DDC 00001010 */  mfhi      $v0
/* 416B70 802A1DE0 00431021 */  addu      $v0, $v0, $v1
/* 416B74 802A1DE4 000211C3 */  sra       $v0, $v0, 7
/* 416B78 802A1DE8 00031FC3 */  sra       $v1, $v1, 0x1f
/* 416B7C 802A1DEC 0C051086 */  jal       func_80144218
/* 416B80 802A1DF0 0043A823 */   subu     $s5, $v0, $v1
/* 416B84 802A1DF4 3C03802B */  lui       $v1, %hi(D_802AD002)
/* 416B88 802A1DF8 8063D002 */  lb        $v1, %lo(D_802AD002)($v1)
/* 416B8C 802A1DFC 3C02802B */  lui       $v0, %hi(D_802AD100)
/* 416B90 802A1E00 8C42D100 */  lw        $v0, %lo(D_802AD100)($v0)
/* 416B94 802A1E04 00431023 */  subu      $v0, $v0, $v1
/* 416B98 802A1E08 000218C0 */  sll       $v1, $v0, 3
/* 416B9C 802A1E0C 00621823 */  subu      $v1, $v1, $v0
/* 416BA0 802A1E10 00031880 */  sll       $v1, $v1, 2
/* 416BA4 802A1E14 3C02802B */  lui       $v0, %hi(D_802AD06C)
/* 416BA8 802A1E18 2442D06C */  addiu     $v0, $v0, %lo(D_802AD06C)
/* 416BAC 802A1E1C C4420000 */  lwc1      $f2, ($v0)
/* 416BB0 802A1E20 4483C000 */  mtc1      $v1, $f24
/* 416BB4 802A1E24 00000000 */  nop
/* 416BB8 802A1E28 4680C620 */  cvt.s.w   $f24, $f24
/* 416BBC 802A1E2C 4602C03C */  c.lt.s    $f24, $f2
/* 416BC0 802A1E30 00000000 */  nop
/* 416BC4 802A1E34 45000007 */  bc1f      .L802A1E54
/* 416BC8 802A1E38 0000B82D */   daddu    $s7, $zero, $zero
/* 416BCC 802A1E3C 3C01802B */  lui       $at, %hi(D_802AD070)
/* 416BD0 802A1E40 C420D070 */  lwc1      $f0, %lo(D_802AD070)($at)
/* 416BD4 802A1E44 46001001 */  sub.s     $f0, $f2, $f0
/* 416BD8 802A1E48 4618003C */  c.lt.s    $f0, $f24
/* 416BDC 802A1E4C 080A879F */  j         .L802A1E7C
/* 416BE0 802A1E50 E4400000 */   swc1     $f0, ($v0)
.L802A1E54:
/* 416BE4 802A1E54 4618103C */  c.lt.s    $f2, $f24
/* 416BE8 802A1E58 00000000 */  nop
/* 416BEC 802A1E5C 4502000B */  bc1fl     .L802A1E8C
/* 416BF0 802A1E60 24170001 */   addiu    $s7, $zero, 1
/* 416BF4 802A1E64 3C01802B */  lui       $at, %hi(D_802AD070)
/* 416BF8 802A1E68 C420D070 */  lwc1      $f0, %lo(D_802AD070)($at)
/* 416BFC 802A1E6C 46001000 */  add.s     $f0, $f2, $f0
/* 416C00 802A1E70 E4400000 */  swc1      $f0, ($v0)
/* 416C04 802A1E74 4600C03C */  c.lt.s    $f24, $f0
/* 416C08 802A1E78 00000000 */  nop
.L802A1E7C:
/* 416C0C 802A1E7C 45000003 */  bc1f      .L802A1E8C
/* 416C10 802A1E80 00000000 */   nop
/* 416C14 802A1E84 E4580000 */  swc1      $f24, ($v0)
/* 416C18 802A1E88 24170001 */  addiu     $s7, $zero, 1
.L802A1E8C:
/* 416C1C 802A1E8C 16E00010 */  bnez      $s7, .L802A1ED0
/* 416C20 802A1E90 00000000 */   nop
/* 416C24 802A1E94 3C02802B */  lui       $v0, %hi(D_802AD070)
/* 416C28 802A1E98 2442D070 */  addiu     $v0, $v0, %lo(D_802AD070)
/* 416C2C 802A1E9C C4400000 */  lwc1      $f0, ($v0)
/* 416C30 802A1EA0 3C013FF0 */  lui       $at, 0x3ff0
/* 416C34 802A1EA4 44811800 */  mtc1      $at, $f3
/* 416C38 802A1EA8 44801000 */  mtc1      $zero, $f2
/* 416C3C 802A1EAC 46000021 */  cvt.d.s   $f0, $f0
/* 416C40 802A1EB0 46220080 */  add.d     $f2, $f0, $f2
/* 416C44 802A1EB4 46220002 */  mul.d     $f0, $f0, $f2
/* 416C48 802A1EB8 00000000 */  nop
/* 416C4C 802A1EBC 46220002 */  mul.d     $f0, $f0, $f2
/* 416C50 802A1EC0 00000000 */  nop
/* 416C54 802A1EC4 46200020 */  cvt.s.d   $f0, $f0
/* 416C58 802A1EC8 080A87BB */  j         .L802A1EEC
/* 416C5C 802A1ECC E4400000 */   swc1     $f0, ($v0)
.L802A1ED0:
/* 416C60 802A1ED0 3C013E99 */  lui       $at, 0x3e99
/* 416C64 802A1ED4 3421999A */  ori       $at, $at, 0x999a
/* 416C68 802A1ED8 44810000 */  mtc1      $at, $f0
/* 416C6C 802A1EDC 3C01802B */  lui       $at, %hi(D_802AD004)
/* 416C70 802A1EE0 A020D004 */  sb        $zero, %lo(D_802AD004)($at)
/* 416C74 802A1EE4 3C01802B */  lui       $at, %hi(D_802AD070)
/* 416C78 802A1EE8 E420D070 */  swc1      $f0, %lo(D_802AD070)($at)
.L802A1EEC:
/* 416C7C 802A1EEC 3C02802B */  lui       $v0, %hi(main_menu_numOptions)
/* 416C80 802A1EF0 8C42D0AC */  lw        $v0, %lo(main_menu_numOptions)($v0)
/* 416C84 802A1EF4 3C01802B */  lui       $at, %hi(D_802AD06C)
/* 416C88 802A1EF8 C438D06C */  lwc1      $f24, %lo(D_802AD06C)($at)
/* 416C8C 802A1EFC 1840008A */  blez      $v0, .L802A2128
/* 416C90 802A1F00 0000A02D */   daddu    $s4, $zero, $zero
/* 416C94 802A1F04 3C118080 */  lui       $s1, 0x8080
/* 416C98 802A1F08 36318081 */  ori       $s1, $s1, 0x8081
/* 416C9C 802A1F0C 00151080 */  sll       $v0, $s5, 2
/* 416CA0 802A1F10 00551021 */  addu      $v0, $v0, $s5
/* 416CA4 802A1F14 00021900 */  sll       $v1, $v0, 4
/* 416CA8 802A1F18 00621823 */  subu      $v1, $v1, $v0
/* 416CAC 802A1F1C 00031840 */  sll       $v1, $v1, 1
/* 416CB0 802A1F20 00710018 */  mult      $v1, $s1
/* 416CB4 802A1F24 4480A000 */  mtc1      $zero, $f20
/* 416CB8 802A1F28 0003B7C3 */  sra       $s6, $v1, 0x1f
/* 416CBC 802A1F2C 00151040 */  sll       $v0, $s5, 1
/* 416CC0 802A1F30 00558021 */  addu      $s0, $v0, $s5
/* 416CC4 802A1F34 00004010 */  mfhi      $t0
/* 416CC8 802A1F38 01031821 */  addu      $v1, $t0, $v1
/* 416CCC 802A1F3C 000391C3 */  sra       $s2, $v1, 7
.L802A1F40:
/* 416CD0 802A1F40 27A40020 */  addiu     $a0, $sp, 0x20
/* 416CD4 802A1F44 3C0642AE */  lui       $a2, 0x42ae
/* 416CD8 802A1F48 4407C000 */  mfc1      $a3, $f24
/* 416CDC 802A1F4C 27A50024 */  addiu     $a1, $sp, 0x24
/* 416CE0 802A1F50 E7B40020 */  swc1      $f20, 0x20($sp)
/* 416CE4 802A1F54 0C00A7E7 */  jal       add_vec2D_polar
/* 416CE8 802A1F58 E7B40024 */   swc1     $f20, 0x24($sp)
/* 416CEC 802A1F5C 00141080 */  sll       $v0, $s4, 2
/* 416CF0 802A1F60 C7A00020 */  lwc1      $f0, 0x20($sp)
/* 416CF4 802A1F64 3C01802B */  lui       $at, %hi(D_802AD060)
/* 416CF8 802A1F68 C422D060 */  lwc1      $f2, %lo(D_802AD060)($at)
/* 416CFC 802A1F6C 468010A0 */  cvt.s.w   $f2, $f2
/* 416D00 802A1F70 46001080 */  add.s     $f2, $f2, $f0
/* 416D04 802A1F74 C7A40024 */  lwc1      $f4, 0x24($sp)
/* 416D08 802A1F78 3C01802B */  lui       $at, %hi(D_802AD064)
/* 416D0C 802A1F7C C420D064 */  lwc1      $f0, %lo(D_802AD064)($at)
/* 416D10 802A1F80 46800020 */  cvt.s.w   $f0, $f0
/* 416D14 802A1F84 46040000 */  add.s     $f0, $f0, $f4
/* 416D18 802A1F88 3C13802B */  lui       $s3, %hi(D_802AD028)
/* 416D1C 802A1F8C 02629821 */  addu      $s3, $s3, $v0
/* 416D20 802A1F90 8E73D028 */  lw        $s3, %lo(D_802AD028)($s3)
/* 416D24 802A1F94 4407A000 */  mfc1      $a3, $f20
/* 416D28 802A1F98 46000187 */  neg.s     $f6, $f0
/* 416D2C 802A1F9C 44051000 */  mfc1      $a1, $f2
/* 416D30 802A1FA0 44063000 */  mfc1      $a2, $f6
/* 416D34 802A1FA4 0260202D */  daddu     $a0, $s3, $zero
/* 416D38 802A1FA8 E7A00024 */  swc1      $f0, 0x24($sp)
/* 416D3C 802A1FAC 0C051461 */  jal       set_hud_element_transform_pos
/* 416D40 802A1FB0 AFA50020 */   sw       $a1, 0x20($sp)
/* 416D44 802A1FB4 0260202D */  daddu     $a0, $s3, $zero
/* 416D48 802A1FB8 0000282D */  daddu     $a1, $zero, $zero
/* 416D4C 802A1FBC 0C051261 */  jal       set_hud_element_render_pos
/* 416D50 802A1FC0 00A0302D */   daddu    $a2, $a1, $zero
/* 416D54 802A1FC4 0260202D */  daddu     $a0, $s3, $zero
/* 416D58 802A1FC8 0C0513AC */  jal       set_hud_element_alpha
/* 416D5C 802A1FCC 02562823 */   subu     $a1, $s2, $s6
/* 416D60 802A1FD0 3C014260 */  lui       $at, 0x4260
/* 416D64 802A1FD4 44810000 */  mtc1      $at, $f0
/* 416D68 802A1FD8 00000000 */  nop
/* 416D6C 802A1FDC 4600C032 */  c.eq.s    $f24, $f0
/* 416D70 802A1FE0 3C053F80 */  lui       $a1, 0x3f80
/* 416D74 802A1FE4 45000005 */  bc1f      .L802A1FFC
/* 416D78 802A1FE8 24020001 */   addiu    $v0, $zero, 1
/* 416D7C 802A1FEC 16E20003 */  bne       $s7, $v0, .L802A1FFC
/* 416D80 802A1FF0 00000000 */   nop
/* 416D84 802A1FF4 3C053FCC */  lui       $a1, 0x3fcc
/* 416D88 802A1FF8 34A5CCCD */  ori       $a1, $a1, 0xcccd
.L802A1FFC:
/* 416D8C 802A1FFC 0C051308 */  jal       set_hud_element_scale
/* 416D90 802A2000 0260202D */   daddu    $a0, $s3, $zero
/* 416D94 802A2004 0C05108E */  jal       func_80144238
/* 416D98 802A2008 0260202D */   daddu    $a0, $s3, $zero
/* 416D9C 802A200C 3C02802B */  lui       $v0, %hi(D_802AD06B)
/* 416DA0 802A2010 8042D06B */  lb        $v0, %lo(D_802AD06B)($v0)
/* 416DA4 802A2014 3C03802B */  lui       $v1, %hi(D_802AD002)
/* 416DA8 802A2018 8063D002 */  lb        $v1, %lo(D_802AD002)($v1)
/* 416DAC 802A201C 00431021 */  addu      $v0, $v0, $v1
/* 416DB0 802A2020 5682003A */  bnel      $s4, $v0, .L802A210C
/* 416DB4 802A2024 26940001 */   addiu    $s4, $s4, 1
/* 416DB8 802A2028 27A40020 */  addiu     $a0, $sp, 0x20
/* 416DBC 802A202C 3C0642AE */  lui       $a2, 0x42ae
/* 416DC0 802A2030 3C074260 */  lui       $a3, 0x4260
/* 416DC4 802A2034 27A50024 */  addiu     $a1, $sp, 0x24
/* 416DC8 802A2038 AFA00020 */  sw        $zero, 0x20($sp)
/* 416DCC 802A203C 0C00A7E7 */  jal       add_vec2D_polar
/* 416DD0 802A2040 AFA00024 */   sw       $zero, 0x24($sp)
/* 416DD4 802A2044 C7A00020 */  lwc1      $f0, 0x20($sp)
/* 416DD8 802A2048 3C01802B */  lui       $at, %hi(D_802AD060)
/* 416DDC 802A204C C422D060 */  lwc1      $f2, %lo(D_802AD060)($at)
/* 416DE0 802A2050 468010A0 */  cvt.s.w   $f2, $f2
/* 416DE4 802A2054 46001080 */  add.s     $f2, $f2, $f0
/* 416DE8 802A2058 C7A40024 */  lwc1      $f4, 0x24($sp)
/* 416DEC 802A205C 3C01802B */  lui       $at, %hi(D_802AD064)
/* 416DF0 802A2060 C420D064 */  lwc1      $f0, %lo(D_802AD064)($at)
/* 416DF4 802A2064 46800020 */  cvt.s.w   $f0, $f0
/* 416DF8 802A2068 46040000 */  add.s     $f0, $f0, $f4
/* 416DFC 802A206C 0000382D */  daddu     $a3, $zero, $zero
/* 416E00 802A2070 3C13802B */  lui       $s3, %hi(D_802AD040)
/* 416E04 802A2074 8E73D040 */  lw        $s3, %lo(D_802AD040)($s3)
/* 416E08 802A2078 46000187 */  neg.s     $f6, $f0
/* 416E0C 802A207C 44051000 */  mfc1      $a1, $f2
/* 416E10 802A2080 44063000 */  mfc1      $a2, $f6
/* 416E14 802A2084 0260202D */  daddu     $a0, $s3, $zero
/* 416E18 802A2088 E7A00024 */  swc1      $f0, 0x24($sp)
/* 416E1C 802A208C 0C051461 */  jal       set_hud_element_transform_pos
/* 416E20 802A2090 AFA50020 */   sw       $a1, 0x20($sp)
/* 416E24 802A2094 0260202D */  daddu     $a0, $s3, $zero
/* 416E28 802A2098 0000282D */  daddu     $a1, $zero, $zero
/* 416E2C 802A209C 0C051261 */  jal       set_hud_element_render_pos
/* 416E30 802A20A0 00A0302D */   daddu    $a2, $a1, $zero
/* 416E34 802A20A4 00102900 */  sll       $a1, $s0, 4
/* 416E38 802A20A8 00B02823 */  subu      $a1, $a1, $s0
/* 416E3C 802A20AC 00052880 */  sll       $a1, $a1, 2
/* 416E40 802A20B0 00B10018 */  mult      $a1, $s1
/* 416E44 802A20B4 0260202D */  daddu     $a0, $s3, $zero
/* 416E48 802A20B8 00004010 */  mfhi      $t0
/* 416E4C 802A20BC 01051021 */  addu      $v0, $t0, $a1
/* 416E50 802A20C0 000211C3 */  sra       $v0, $v0, 7
/* 416E54 802A20C4 00052FC3 */  sra       $a1, $a1, 0x1f
/* 416E58 802A20C8 0C0513AC */  jal       set_hud_element_alpha
/* 416E5C 802A20CC 00452823 */   subu     $a1, $v0, $a1
/* 416E60 802A20D0 3C053F99 */  lui       $a1, 0x3f99
/* 416E64 802A20D4 34A5999A */  ori       $a1, $a1, 0x999a
/* 416E68 802A20D8 0C051308 */  jal       set_hud_element_scale
/* 416E6C 802A20DC 0260202D */   daddu    $a0, $s3, $zero
/* 416E70 802A20E0 16E00005 */  bnez      $s7, .L802A20F8
/* 416E74 802A20E4 0260202D */   daddu    $a0, $s3, $zero
/* 416E78 802A20E8 0C051280 */  jal       set_hud_element_flags
/* 416E7C 802A20EC 24050002 */   addiu    $a1, $zero, 2
/* 416E80 802A20F0 080A8840 */  j         .L802A2100
/* 416E84 802A20F4 00000000 */   nop
.L802A20F8:
/* 416E88 802A20F8 0C05128B */  jal       clear_hud_element_flags
/* 416E8C 802A20FC 24050002 */   addiu    $a1, $zero, 2
.L802A2100:
/* 416E90 802A2100 0C05108E */  jal       func_80144238
/* 416E94 802A2104 0260202D */   daddu    $a0, $s3, $zero
/* 416E98 802A2108 26940001 */  addiu     $s4, $s4, 1
.L802A210C:
/* 416E9C 802A210C 3C02802B */  lui       $v0, %hi(main_menu_numOptions)
/* 416EA0 802A2110 8C42D0AC */  lw        $v0, %lo(main_menu_numOptions)($v0)
/* 416EA4 802A2114 3C0141E0 */  lui       $at, 0x41e0
/* 416EA8 802A2118 44810000 */  mtc1      $at, $f0
/* 416EAC 802A211C 0282102A */  slt       $v0, $s4, $v0
/* 416EB0 802A2120 1440FF87 */  bnez      $v0, .L802A1F40
/* 416EB4 802A2124 4600C600 */   add.s    $f24, $f24, $f0
.L802A2128:
/* 416EB8 802A2128 3C11802B */  lui       $s1, %hi(D_802AD100)
/* 416EBC 802A212C 2631D100 */  addiu     $s1, $s1, %lo(D_802AD100)
/* 416EC0 802A2130 3C10802B */  lui       $s0, %hi(D_802AD002)
/* 416EC4 802A2134 2610D002 */  addiu     $s0, $s0, %lo(D_802AD002)
/* 416EC8 802A2138 82030000 */  lb        $v1, ($s0)
/* 416ECC 802A213C 8E220000 */  lw        $v0, ($s1)
/* 416ED0 802A2140 3C01802B */  lui       $at, %hi(D_802AD06C)
/* 416ED4 802A2144 C420D06C */  lwc1      $f0, %lo(D_802AD06C)($at)
/* 416ED8 802A2148 00431023 */  subu      $v0, $v0, $v1
/* 416EDC 802A214C 000218C0 */  sll       $v1, $v0, 3
/* 416EE0 802A2150 00621823 */  subu      $v1, $v1, $v0
/* 416EE4 802A2154 00031880 */  sll       $v1, $v1, 2
/* 416EE8 802A2158 4483C000 */  mtc1      $v1, $f24
/* 416EEC 802A215C 00000000 */  nop
/* 416EF0 802A2160 4680C620 */  cvt.s.w   $f24, $f24
/* 416EF4 802A2164 46180001 */  sub.s     $f0, $f0, $f24
/* 416EF8 802A2168 3C01802B */  lui       $at, %hi(D_802AB7F0)
/* 416EFC 802A216C D43AB7F0 */  ldc1      $f26, %lo(D_802AB7F0)($at)
/* 416F00 802A2170 46000021 */  cvt.d.s   $f0, $f0
/* 416F04 802A2174 463A0002 */  mul.d     $f0, $f0, $f26
/* 416F08 802A2178 00000000 */  nop
/* 416F0C 802A217C 3C01802B */  lui       $at, %hi(D_802AB7F8)
/* 416F10 802A2180 D424B7F8 */  ldc1      $f4, %lo(D_802AB7F8)($at)
/* 416F14 802A2184 46200020 */  cvt.s.d   $f0, $f0
/* 416F18 802A2188 46000005 */  abs.s     $f0, $f0
/* 416F1C 802A218C 46000021 */  cvt.d.s   $f0, $f0
/* 416F20 802A2190 46240001 */  sub.d     $f0, $f0, $f4
/* 416F24 802A2194 3C01802B */  lui       $at, %hi(D_802AB800)
/* 416F28 802A2198 D422B800 */  ldc1      $f2, %lo(D_802AB800)($at)
/* 416F2C 802A219C 46200020 */  cvt.s.d   $f0, $f0
/* 416F30 802A21A0 46000005 */  abs.s     $f0, $f0
/* 416F34 802A21A4 46000021 */  cvt.d.s   $f0, $f0
/* 416F38 802A21A8 46240003 */  div.d     $f0, $f0, $f4
/* 416F3C 802A21AC 46220000 */  add.d     $f0, $f0, $f2
/* 416F40 802A21B0 12E00003 */  beqz      $s7, .L802A21C0
/* 416F44 802A21B4 46200620 */   cvt.s.d  $f24, $f0
/* 416F48 802A21B8 3C013F80 */  lui       $at, 0x3f80
/* 416F4C 802A21BC 4481C000 */  mtc1      $at, $f24
.L802A21C0:
/* 416F50 802A21C0 0000282D */  daddu     $a1, $zero, $zero
/* 416F54 802A21C4 00A0302D */  daddu     $a2, $a1, $zero
/* 416F58 802A21C8 3C1E8080 */  lui       $fp, 0x8080
/* 416F5C 802A21CC 37DE8081 */  ori       $fp, $fp, 0x8081
/* 416F60 802A21D0 3C13802B */  lui       $s3, %hi(D_802AD04C)
/* 416F64 802A21D4 8E73D04C */  lw        $s3, %lo(D_802AD04C)($s3)
/* 416F68 802A21D8 4480A000 */  mtc1      $zero, $f20
/* 416F6C 802A21DC 0C05149D */  jal       set_hud_element_transform_rotation_pivot
/* 416F70 802A21E0 0260202D */   daddu    $a0, $s3, $zero
/* 416F74 802A21E4 4405A000 */  mfc1      $a1, $f20
/* 416F78 802A21E8 4406A000 */  mfc1      $a2, $f20
/* 416F7C 802A21EC 3C07C22C */  lui       $a3, 0xc22c
/* 416F80 802A21F0 0C051489 */  jal       set_hud_element_transform_rotation
/* 416F84 802A21F4 0260202D */   daddu    $a0, $s3, $zero
/* 416F88 802A21F8 4405C000 */  mfc1      $a1, $f24
/* 416F8C 802A21FC 3C013F80 */  lui       $at, 0x3f80
/* 416F90 802A2200 4481B000 */  mtc1      $at, $f22
/* 416F94 802A2204 0C051308 */  jal       set_hud_element_scale
/* 416F98 802A2208 0260202D */   daddu    $a0, $s3, $zero
/* 416F9C 802A220C 4405B000 */  mfc1      $a1, $f22
/* 416FA0 802A2210 3C063FE6 */  lui       $a2, 0x3fe6
/* 416FA4 802A2214 34C66666 */  ori       $a2, $a2, 0x6666
/* 416FA8 802A2218 4407B000 */  mfc1      $a3, $f22
/* 416FAC 802A221C 0C051475 */  jal       set_hud_element_transform_scale
/* 416FB0 802A2220 0260202D */   daddu    $a0, $s3, $zero
/* 416FB4 802A2224 00151040 */  sll       $v0, $s5, 1
/* 416FB8 802A2228 0055B021 */  addu      $s6, $v0, $s5
/* 416FBC 802A222C 001628C0 */  sll       $a1, $s6, 3
/* 416FC0 802A2230 00B52821 */  addu      $a1, $a1, $s5
/* 416FC4 802A2234 000528C0 */  sll       $a1, $a1, 3
/* 416FC8 802A2238 00BE0018 */  mult      $a1, $fp
/* 416FCC 802A223C 0260202D */  daddu     $a0, $s3, $zero
/* 416FD0 802A2240 00004010 */  mfhi      $t0
/* 416FD4 802A2244 01051021 */  addu      $v0, $t0, $a1
/* 416FD8 802A2248 000211C3 */  sra       $v0, $v0, 7
/* 416FDC 802A224C 00052FC3 */  sra       $a1, $a1, 0x1f
/* 416FE0 802A2250 0C0513AC */  jal       set_hud_element_alpha
/* 416FE4 802A2254 00452823 */   subu     $a1, $v0, $a1
/* 416FE8 802A2258 0260202D */  daddu     $a0, $s3, $zero
/* 416FEC 802A225C 2405004F */  addiu     $a1, $zero, 0x4f
/* 416FF0 802A2260 0C051261 */  jal       set_hud_element_render_pos
/* 416FF4 802A2264 240600B0 */   addiu    $a2, $zero, 0xb0
/* 416FF8 802A2268 0C05108E */  jal       func_80144238
/* 416FFC 802A226C 0260202D */   daddu    $a0, $s3, $zero
/* 417000 802A2270 82030000 */  lb        $v1, ($s0)
/* 417004 802A2274 8E220000 */  lw        $v0, ($s1)
/* 417008 802A2278 3C01802B */  lui       $at, %hi(D_802AD06C)
/* 41700C 802A227C C420D06C */  lwc1      $f0, %lo(D_802AD06C)($at)
/* 417010 802A2280 00431023 */  subu      $v0, $v0, $v1
/* 417014 802A2284 000218C0 */  sll       $v1, $v0, 3
/* 417018 802A2288 00621823 */  subu      $v1, $v1, $v0
/* 41701C 802A228C 00031880 */  sll       $v1, $v1, 2
/* 417020 802A2290 4483C000 */  mtc1      $v1, $f24
/* 417024 802A2294 00000000 */  nop
/* 417028 802A2298 4680C620 */  cvt.s.w   $f24, $f24
/* 41702C 802A229C 46180001 */  sub.s     $f0, $f0, $f24
/* 417030 802A22A0 46000021 */  cvt.d.s   $f0, $f0
/* 417034 802A22A4 463A0002 */  mul.d     $f0, $f0, $f26
/* 417038 802A22A8 00000000 */  nop
/* 41703C 802A22AC 4405A000 */  mfc1      $a1, $f20
/* 417040 802A22B0 3C13802B */  lui       $s3, %hi(D_802AD048)
/* 417044 802A22B4 8E73D048 */  lw        $s3, %lo(D_802AD048)($s3)
/* 417048 802A22B8 00A0302D */  daddu     $a2, $a1, $zero
/* 41704C 802A22BC 46200620 */  cvt.s.d   $f24, $f0
/* 417050 802A22C0 4600C607 */  neg.s     $f24, $f24
/* 417054 802A22C4 4407C000 */  mfc1      $a3, $f24
/* 417058 802A22C8 0C051489 */  jal       set_hud_element_transform_rotation
/* 41705C 802A22CC 0260202D */   daddu    $a0, $s3, $zero
/* 417060 802A22D0 0260202D */  daddu     $a0, $s3, $zero
/* 417064 802A22D4 24050012 */  addiu     $a1, $zero, 0x12
/* 417068 802A22D8 0C05149D */  jal       set_hud_element_transform_rotation_pivot
/* 41706C 802A22DC 2406FFEC */   addiu    $a2, $zero, -0x14
/* 417070 802A22E0 3C053F73 */  lui       $a1, 0x3f73
/* 417074 802A22E4 34A53333 */  ori       $a1, $a1, 0x3333
/* 417078 802A22E8 0C051308 */  jal       set_hud_element_scale
/* 41707C 802A22EC 0260202D */   daddu    $a0, $s3, $zero
/* 417080 802A22F0 001511C0 */  sll       $v0, $s5, 7
/* 417084 802A22F4 00551023 */  subu      $v0, $v0, $s5
/* 417088 802A22F8 00021040 */  sll       $v0, $v0, 1
/* 41708C 802A22FC 005E0018 */  mult      $v0, $fp
/* 417090 802A2300 0000A02D */  daddu     $s4, $zero, $zero
/* 417094 802A2304 0260202D */  daddu     $a0, $s3, $zero
/* 417098 802A2308 00004010 */  mfhi      $t0
/* 41709C 802A230C 01028021 */  addu      $s0, $t0, $v0
/* 4170A0 802A2310 001081C3 */  sra       $s0, $s0, 7
/* 4170A4 802A2314 000217C3 */  sra       $v0, $v0, 0x1f
/* 4170A8 802A2318 02028023 */  subu      $s0, $s0, $v0
/* 4170AC 802A231C 0C0513AC */  jal       set_hud_element_alpha
/* 4170B0 802A2320 0200282D */   daddu    $a1, $s0, $zero
/* 4170B4 802A2324 0260202D */  daddu     $a0, $s3, $zero
/* 4170B8 802A2328 3C11802B */  lui       $s1, %hi(D_802AD00A)
/* 4170BC 802A232C 2631D00A */  addiu     $s1, $s1, %lo(D_802AD00A)
/* 4170C0 802A2330 86260000 */  lh        $a2, ($s1)
/* 4170C4 802A2334 24120028 */  addiu     $s2, $zero, 0x28
/* 4170C8 802A2338 02462823 */  subu      $a1, $s2, $a2
/* 4170CC 802A233C 0C051261 */  jal       set_hud_element_render_pos
/* 4170D0 802A2340 24C600D4 */   addiu    $a2, $a2, 0xd4
/* 4170D4 802A2344 0C05108E */  jal       func_80144238
/* 4170D8 802A2348 0260202D */   daddu    $a0, $s3, $zero
/* 4170DC 802A234C 3C13802B */  lui       $s3, %hi(D_802AD044)
/* 4170E0 802A2350 8E73D044 */  lw        $s3, %lo(D_802AD044)($s3)
/* 4170E4 802A2354 0200282D */  daddu     $a1, $s0, $zero
/* 4170E8 802A2358 0C0513AC */  jal       set_hud_element_alpha
/* 4170EC 802A235C 0260202D */   daddu    $a0, $s3, $zero
/* 4170F0 802A2360 86260000 */  lh        $a2, ($s1)
/* 4170F4 802A2364 0260202D */  daddu     $a0, $s3, $zero
/* 4170F8 802A2368 02462823 */  subu      $a1, $s2, $a2
/* 4170FC 802A236C 0C051261 */  jal       set_hud_element_render_pos
/* 417100 802A2370 24C600D4 */   addiu    $a2, $a2, 0xd4
/* 417104 802A2374 4405B000 */  mfc1      $a1, $f22
/* 417108 802A2378 0C051308 */  jal       set_hud_element_scale
/* 41710C 802A237C 0260202D */   daddu    $a0, $s3, $zero
/* 417110 802A2380 0C05108E */  jal       func_80144238
/* 417114 802A2384 0260202D */   daddu    $a0, $s3, $zero
/* 417118 802A2388 3C02802B */  lui       $v0, %hi(main_menu_numOptions)
/* 41711C 802A238C 8C42D0AC */  lw        $v0, %lo(main_menu_numOptions)($v0)
/* 417120 802A2390 3C01802B */  lui       $at, %hi(D_802AD06C)
/* 417124 802A2394 C438D06C */  lwc1      $f24, %lo(D_802AD06C)($at)
/* 417128 802A2398 1840004D */  blez      $v0, .L802A24D0
/* 41712C 802A239C 00161100 */   sll      $v0, $s6, 4
/* 417130 802A23A0 00561023 */  subu      $v0, $v0, $s6
/* 417134 802A23A4 00021080 */  sll       $v0, $v0, 2
/* 417138 802A23A8 005E0018 */  mult      $v0, $fp
/* 41713C 802A23AC 24160018 */  addiu     $s6, $zero, 0x18
/* 417140 802A23B0 000247C3 */  sra       $t0, $v0, 0x1f
/* 417144 802A23B4 AFA80028 */  sw        $t0, 0x28($sp)
/* 417148 802A23B8 3C12802B */  lui       $s2, %hi(D_802AD010)
/* 41714C 802A23BC 2652D010 */  addiu     $s2, $s2, %lo(D_802AD010)
/* 417150 802A23C0 00004010 */  mfhi      $t0
/* 417154 802A23C4 01021021 */  addu      $v0, $t0, $v0
/* 417158 802A23C8 0002F1C3 */  sra       $fp, $v0, 7
.L802A23CC:
/* 41715C 802A23CC 27A40020 */  addiu     $a0, $sp, 0x20
/* 417160 802A23D0 3C0642AE */  lui       $a2, 0x42ae
/* 417164 802A23D4 4407C000 */  mfc1      $a3, $f24
/* 417168 802A23D8 27A50024 */  addiu     $a1, $sp, 0x24
/* 41716C 802A23DC AFA00020 */  sw        $zero, 0x20($sp)
/* 417170 802A23E0 0C00A7E7 */  jal       add_vec2D_polar
/* 417174 802A23E4 AFA00024 */   sw       $zero, 0x24($sp)
/* 417178 802A23E8 0000202D */  daddu     $a0, $zero, $zero
/* 41717C 802A23EC 0080282D */  daddu     $a1, $a0, $zero
/* 417180 802A23F0 0080302D */  daddu     $a2, $a0, $zero
/* 417184 802A23F4 C7A00020 */  lwc1      $f0, 0x20($sp)
/* 417188 802A23F8 3C01802B */  lui       $at, %hi(D_802AD060)
/* 41718C 802A23FC C424D060 */  lwc1      $f4, %lo(D_802AD060)($at)
/* 417190 802A2400 46802120 */  cvt.s.w   $f4, $f4
/* 417194 802A2404 46002100 */  add.s     $f4, $f4, $f0
/* 417198 802A2408 C7A20024 */  lwc1      $f2, 0x24($sp)
/* 41719C 802A240C 3C01802B */  lui       $at, %hi(D_802AD064)
/* 4171A0 802A2410 C420D064 */  lwc1      $f0, %lo(D_802AD064)($at)
/* 4171A4 802A2414 46800020 */  cvt.s.w   $f0, $f0
/* 4171A8 802A2418 46020000 */  add.s     $f0, $f0, $f2
/* 4171AC 802A241C 0080382D */  daddu     $a3, $a0, $zero
/* 4171B0 802A2420 4600218D */  trunc.w.s $f6, $f4
/* 4171B4 802A2424 44113000 */  mfc1      $s1, $f6
/* 4171B8 802A2428 4600018D */  trunc.w.s $f6, $f0
/* 4171BC 802A242C 44103000 */  mfc1      $s0, $f6
/* 4171C0 802A2430 2622FFF4 */  addiu     $v0, $s1, -0xc
/* 4171C4 802A2434 3042FFFF */  andi      $v0, $v0, 0xffff
/* 4171C8 802A2438 E7A40020 */  swc1      $f4, 0x20($sp)
/* 4171CC 802A243C E7A00024 */  swc1      $f0, 0x24($sp)
/* 4171D0 802A2440 AFA20010 */  sw        $v0, 0x10($sp)
/* 4171D4 802A2444 2602FFF4 */  addiu     $v0, $s0, -0xc
/* 4171D8 802A2448 3042FFFF */  andi      $v0, $v0, 0xffff
/* 4171DC 802A244C AFA20014 */  sw        $v0, 0x14($sp)
/* 4171E0 802A2450 AFB60018 */  sw        $s6, 0x18($sp)
/* 4171E4 802A2454 0C099E8F */  jal       btl_draw_prim_quad
/* 4171E8 802A2458 AFB6001C */   sw       $s6, 0x1c($sp)
/* 4171EC 802A245C 0220282D */  daddu     $a1, $s1, $zero
/* 4171F0 802A2460 8E530000 */  lw        $s3, ($s2)
/* 4171F4 802A2464 0200302D */  daddu     $a2, $s0, $zero
/* 4171F8 802A2468 0C051261 */  jal       set_hud_element_render_pos
/* 4171FC 802A246C 0260202D */   daddu    $a0, $s3, $zero
/* 417200 802A2470 8FA80028 */  lw        $t0, 0x28($sp)
/* 417204 802A2474 0260202D */  daddu     $a0, $s3, $zero
/* 417208 802A2478 0C0513AC */  jal       set_hud_element_alpha
/* 41720C 802A247C 03C82823 */   subu     $a1, $fp, $t0
/* 417210 802A2480 3C02802B */  lui       $v0, %hi(D_802AD06B)
/* 417214 802A2484 8042D06B */  lb        $v0, %lo(D_802AD06B)($v0)
/* 417218 802A2488 3C03802B */  lui       $v1, %hi(D_802AD002)
/* 41721C 802A248C 8063D002 */  lb        $v1, %lo(D_802AD002)($v1)
/* 417220 802A2490 00431021 */  addu      $v0, $v0, $v1
/* 417224 802A2494 16820003 */  bne       $s4, $v0, .L802A24A4
/* 417228 802A2498 0260202D */   daddu    $a0, $s3, $zero
/* 41722C 802A249C 0C0513AC */  jal       set_hud_element_alpha
/* 417230 802A24A0 02A0282D */   daddu    $a1, $s5, $zero
.L802A24A4:
/* 417234 802A24A4 0C0511EA */  jal       draw_hud_element_clipped
/* 417238 802A24A8 0260202D */   daddu    $a0, $s3, $zero
/* 41723C 802A24AC 26520004 */  addiu     $s2, $s2, 4
/* 417240 802A24B0 26940001 */  addiu     $s4, $s4, 1
/* 417244 802A24B4 3C02802B */  lui       $v0, %hi(main_menu_numOptions)
/* 417248 802A24B8 8C42D0AC */  lw        $v0, %lo(main_menu_numOptions)($v0)
/* 41724C 802A24BC 3C0141E0 */  lui       $at, 0x41e0
/* 417250 802A24C0 44810000 */  mtc1      $at, $f0
/* 417254 802A24C4 0282102A */  slt       $v0, $s4, $v0
/* 417258 802A24C8 1440FFC0 */  bnez      $v0, .L802A23CC
/* 41725C 802A24CC 4600C600 */   add.s    $f24, $f24, $f0
.L802A24D0:
/* 417260 802A24D0 12E00024 */  beqz      $s7, .L802A2564
/* 417264 802A24D4 0000202D */   daddu    $a0, $zero, $zero
/* 417268 802A24D8 0080282D */  daddu     $a1, $a0, $zero
/* 41726C 802A24DC 0080302D */  daddu     $a2, $a0, $zero
/* 417270 802A24E0 0080382D */  daddu     $a3, $a0, $zero
/* 417274 802A24E4 24020030 */  addiu     $v0, $zero, 0x30
/* 417278 802A24E8 AFA20018 */  sw        $v0, 0x18($sp)
/* 41727C 802A24EC 24020010 */  addiu     $v0, $zero, 0x10
/* 417280 802A24F0 AFA2001C */  sw        $v0, 0x1c($sp)
/* 417284 802A24F4 3C02802B */  lui       $v0, %hi(D_802AD060)
/* 417288 802A24F8 8C42D060 */  lw        $v0, %lo(D_802AD060)($v0)
/* 41728C 802A24FC 3C03802B */  lui       $v1, %hi(D_802AD064)
/* 417290 802A2500 8C63D064 */  lw        $v1, %lo(D_802AD064)($v1)
/* 417294 802A2504 24510014 */  addiu     $s1, $v0, 0x14
/* 417298 802A2508 2470FFDE */  addiu     $s0, $v1, -0x22
/* 41729C 802A250C 2442002E */  addiu     $v0, $v0, 0x2e
/* 4172A0 802A2510 3042FFFF */  andi      $v0, $v0, 0xffff
/* 4172A4 802A2514 AFA20010 */  sw        $v0, 0x10($sp)
/* 4172A8 802A2518 3202FFFF */  andi      $v0, $s0, 0xffff
/* 4172AC 802A251C 0C099E8F */  jal       btl_draw_prim_quad
/* 4172B0 802A2520 AFA20014 */   sw       $v0, 0x14($sp)
/* 4172B4 802A2524 0220282D */  daddu     $a1, $s1, $zero
/* 4172B8 802A2528 0200302D */  daddu     $a2, $s0, $zero
/* 4172BC 802A252C 3C03802B */  lui       $v1, %hi(D_802AD002)
/* 4172C0 802A2530 8063D002 */  lb        $v1, %lo(D_802AD002)($v1)
/* 4172C4 802A2534 3C04802B */  lui       $a0, %hi(D_802AD06B)
/* 4172C8 802A2538 8084D06B */  lb        $a0, %lo(D_802AD06B)($a0)
/* 4172CC 802A253C 24020035 */  addiu     $v0, $zero, 0x35
/* 4172D0 802A2540 AFA20010 */  sw        $v0, 0x10($sp)
/* 4172D4 802A2544 AFA00014 */  sw        $zero, 0x14($sp)
/* 4172D8 802A2548 00641821 */  addu      $v1, $v1, $a0
/* 4172DC 802A254C 00031880 */  sll       $v1, $v1, 2
/* 4172E0 802A2550 3C04802B */  lui       $a0, %hi(battle_menu_messageIDs)
/* 4172E4 802A2554 00832021 */  addu      $a0, $a0, $v1
/* 4172E8 802A2558 8C84D090 */  lw        $a0, %lo(battle_menu_messageIDs)($a0)
/* 4172EC 802A255C 0C04993B */  jal       draw_msg
/* 4172F0 802A2560 02A0382D */   daddu    $a3, $s5, $zero
.L802A2564:
/* 4172F4 802A2564 3C04800E */  lui       $a0, %hi(gBattleStatus)
/* 4172F8 802A2568 2484C070 */  addiu     $a0, $a0, %lo(gBattleStatus)
/* 4172FC 802A256C 8C820000 */  lw        $v0, ($a0)
/* 417300 802A2570 3C030200 */  lui       $v1, 0x200
/* 417304 802A2574 00431024 */  and       $v0, $v0, $v1
/* 417308 802A2578 14400005 */  bnez      $v0, .L802A2590
/* 41730C 802A257C 00000000 */   nop
/* 417310 802A2580 8C820004 */  lw        $v0, 4($a0)
/* 417314 802A2584 30420040 */  andi      $v0, $v0, 0x40
/* 417318 802A2588 10400003 */  beqz      $v0, .L802A2598
/* 41731C 802A258C 00000000 */   nop
.L802A2590:
/* 417320 802A2590 3C01802B */  lui       $at, %hi(D_802AD104)
/* 417324 802A2594 AC20D104 */  sw        $zero, %lo(D_802AD104)($at)
.L802A2598:
/* 417328 802A2598 3C02802B */  lui       $v0, %hi(D_802AD104)
/* 41732C 802A259C 8C42D104 */  lw        $v0, %lo(D_802AD104)($v0)
/* 417330 802A25A0 10400028 */  beqz      $v0, L802A2644_4173D4
/* 417334 802A25A4 3C028080 */   lui      $v0, 0x8080
/* 417338 802A25A8 34428081 */  ori       $v0, $v0, 0x8081
/* 41733C 802A25AC 00152840 */  sll       $a1, $s5, 1
/* 417340 802A25B0 00B52821 */  addu      $a1, $a1, $s5
/* 417344 802A25B4 000528C0 */  sll       $a1, $a1, 3
/* 417348 802A25B8 00B52821 */  addu      $a1, $a1, $s5
/* 41734C 802A25BC 000528C0 */  sll       $a1, $a1, 3
/* 417350 802A25C0 00A20018 */  mult      $a1, $v0
/* 417354 802A25C4 3C13802B */  lui       $s3, %hi(D_802AD05C)
/* 417358 802A25C8 8E73D05C */  lw        $s3, %lo(D_802AD05C)($s3)
/* 41735C 802A25CC 0260202D */  daddu     $a0, $s3, $zero
/* 417360 802A25D0 00004010 */  mfhi      $t0
/* 417364 802A25D4 01051021 */  addu      $v0, $t0, $a1
/* 417368 802A25D8 000211C3 */  sra       $v0, $v0, 7
/* 41736C 802A25DC 00052FC3 */  sra       $a1, $a1, 0x1f
/* 417370 802A25E0 0C0513AC */  jal       set_hud_element_alpha
/* 417374 802A25E4 00452823 */   subu     $a1, $v0, $a1
/* 417378 802A25E8 0C0511EA */  jal       draw_hud_element_clipped
/* 41737C 802A25EC 0260202D */   daddu    $a0, $s3, $zero
/* 417380 802A25F0 3C13802B */  lui       $s3, %hi(D_802AD050)
/* 417384 802A25F4 8E73D050 */  lw        $s3, %lo(D_802AD050)($s3)
/* 417388 802A25F8 02A0282D */  daddu     $a1, $s5, $zero
/* 41738C 802A25FC 0C0513AC */  jal       set_hud_element_alpha
/* 417390 802A2600 0260202D */   daddu    $a0, $s3, $zero
/* 417394 802A2604 0C0511EA */  jal       draw_hud_element_clipped
/* 417398 802A2608 0260202D */   daddu    $a0, $s3, $zero
/* 41739C 802A260C 3C13802B */  lui       $s3, %hi(D_802AD054)
/* 4173A0 802A2610 8E73D054 */  lw        $s3, %lo(D_802AD054)($s3)
/* 4173A4 802A2614 02A0282D */  daddu     $a1, $s5, $zero
/* 4173A8 802A2618 0C0513AC */  jal       set_hud_element_alpha
/* 4173AC 802A261C 0260202D */   daddu    $a0, $s3, $zero
/* 4173B0 802A2620 0C0511EA */  jal       draw_hud_element_clipped
/* 4173B4 802A2624 0260202D */   daddu    $a0, $s3, $zero
/* 4173B8 802A2628 3C13802B */  lui       $s3, %hi(D_802AD058)
/* 4173BC 802A262C 8E73D058 */  lw        $s3, %lo(D_802AD058)($s3)
/* 4173C0 802A2630 02A0282D */  daddu     $a1, $s5, $zero
/* 4173C4 802A2634 0C0513AC */  jal       set_hud_element_alpha
/* 4173C8 802A2638 0260202D */   daddu    $a0, $s3, $zero
/* 4173CC 802A263C 0C0511EA */  jal       draw_hud_element_clipped
/* 4173D0 802A2640 0260202D */   daddu    $a0, $s3, $zero
dlabel L802A2644_4173D4
/* 4173D4 802A2644 8FBF0054 */  lw        $ra, 0x54($sp)
/* 4173D8 802A2648 8FBE0050 */  lw        $fp, 0x50($sp)
/* 4173DC 802A264C 8FB7004C */  lw        $s7, 0x4c($sp)
/* 4173E0 802A2650 8FB60048 */  lw        $s6, 0x48($sp)
/* 4173E4 802A2654 8FB50044 */  lw        $s5, 0x44($sp)
/* 4173E8 802A2658 8FB40040 */  lw        $s4, 0x40($sp)
/* 4173EC 802A265C 8FB3003C */  lw        $s3, 0x3c($sp)
/* 4173F0 802A2660 8FB20038 */  lw        $s2, 0x38($sp)
/* 4173F4 802A2664 8FB10034 */  lw        $s1, 0x34($sp)
/* 4173F8 802A2668 8FB00030 */  lw        $s0, 0x30($sp)
/* 4173FC 802A266C D7BA0070 */  ldc1      $f26, 0x70($sp)
/* 417400 802A2670 D7B80068 */  ldc1      $f24, 0x68($sp)
/* 417404 802A2674 D7B60060 */  ldc1      $f22, 0x60($sp)
/* 417408 802A2678 D7B40058 */  ldc1      $f20, 0x58($sp)
/* 41740C 802A267C 03E00008 */  jr        $ra
/* 417410 802A2680 27BD0078 */   addiu    $sp, $sp, 0x78
