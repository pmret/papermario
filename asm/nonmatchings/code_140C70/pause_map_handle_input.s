.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel pause_map_handle_input
/* 141BB8 8024E878 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* 141BBC 8024E87C 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* 141BC0 8024E880 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 141BC4 8024E884 AFBF0018 */  sw        $ra, 0x18($sp)
/* 141BC8 8024E888 AFB10014 */  sw        $s1, 0x14($sp)
/* 141BCC 8024E88C AFB00010 */  sw        $s0, 0x10($sp)
/* 141BD0 8024E890 80620040 */  lb        $v0, 0x40($v1)
/* 141BD4 8024E894 3C013D4C */  lui       $at, 0x3d4c
/* 141BD8 8024E898 3421CCCD */  ori       $at, $at, 0xcccd
/* 141BDC 8024E89C 44811000 */  mtc1      $at, $f2
/* 141BE0 8024E8A0 44820000 */  mtc1      $v0, $f0
/* 141BE4 8024E8A4 00000000 */  nop       
/* 141BE8 8024E8A8 46800020 */  cvt.s.w   $f0, $f0
/* 141BEC 8024E8AC 46020202 */  mul.s     $f8, $f0, $f2
/* 141BF0 8024E8B0 00000000 */  nop       
/* 141BF4 8024E8B4 80620044 */  lb        $v0, 0x44($v1)
/* 141BF8 8024E8B8 00021023 */  negu      $v0, $v0
/* 141BFC 8024E8BC 44820000 */  mtc1      $v0, $f0
/* 141C00 8024E8C0 00000000 */  nop       
/* 141C04 8024E8C4 46800020 */  cvt.s.w   $f0, $f0
/* 141C08 8024E8C8 46020182 */  mul.s     $f6, $f0, $f2
/* 141C0C 8024E8CC 00000000 */  nop       
/* 141C10 8024E8D0 3C018027 */  lui       $at, 0x8027
/* 141C14 8024E8D4 C42A0718 */  lwc1      $f10, 0x718($at)
/* 141C18 8024E8D8 44800000 */  mtc1      $zero, $f0
/* 141C1C 8024E8DC 3C018027 */  lui       $at, 0x8027
/* 141C20 8024E8E0 C4220714 */  lwc1      $f2, 0x714($at)
/* 141C24 8024E8E4 46004032 */  c.eq.s    $f8, $f0
/* 141C28 8024E8E8 00000000 */  nop       
/* 141C2C 8024E8EC 45000022 */  bc1f      .L8024E978
/* 141C30 8024E8F0 00000000 */   nop      
/* 141C34 8024E8F4 46003032 */  c.eq.s    $f6, $f0
/* 141C38 8024E8F8 00000000 */  nop       
/* 141C3C 8024E8FC 4500001E */  bc1f      .L8024E978
/* 141C40 8024E900 2402FFFF */   addiu    $v0, $zero, -1
/* 141C44 8024E904 3C048027 */  lui       $a0, 0x8027
/* 141C48 8024E908 8C84071C */  lw        $a0, 0x71c($a0)
/* 141C4C 8024E90C 1082001A */  beq       $a0, $v0, .L8024E978
/* 141C50 8024E910 00041080 */   sll      $v0, $a0, 2
/* 141C54 8024E914 3C038025 */  lui       $v1, 0x8025
/* 141C58 8024E918 246302B8 */  addiu     $v1, $v1, 0x2b8
/* 141C5C 8024E91C 00441021 */  addu      $v0, $v0, $a0
/* 141C60 8024E920 00021080 */  sll       $v0, $v0, 2
/* 141C64 8024E924 00431021 */  addu      $v0, $v0, $v1
/* 141C68 8024E928 84430000 */  lh        $v1, ($v0)
/* 141C6C 8024E92C 44830000 */  mtc1      $v1, $f0
/* 141C70 8024E930 00000000 */  nop       
/* 141C74 8024E934 46800020 */  cvt.s.w   $f0, $f0
/* 141C78 8024E938 46020201 */  sub.s     $f8, $f0, $f2
/* 141C7C 8024E93C 3C018027 */  lui       $at, 0x8027
/* 141C80 8024E940 D4240090 */  ldc1      $f4, 0x90($at)
/* 141C84 8024E944 460040A1 */  cvt.d.s   $f2, $f8
/* 141C88 8024E948 46241082 */  mul.d     $f2, $f2, $f4
/* 141C8C 8024E94C 00000000 */  nop       
/* 141C90 8024E950 84420002 */  lh        $v0, 2($v0)
/* 141C94 8024E954 44820000 */  mtc1      $v0, $f0
/* 141C98 8024E958 00000000 */  nop       
/* 141C9C 8024E95C 46800020 */  cvt.s.w   $f0, $f0
/* 141CA0 8024E960 460A0181 */  sub.s     $f6, $f0, $f10
/* 141CA4 8024E964 46003021 */  cvt.d.s   $f0, $f6
/* 141CA8 8024E968 46240002 */  mul.d     $f0, $f0, $f4
/* 141CAC 8024E96C 00000000 */  nop       
/* 141CB0 8024E970 46201220 */  cvt.s.d   $f8, $f2
/* 141CB4 8024E974 462001A0 */  cvt.s.d   $f6, $f0
.L8024E978:
/* 141CB8 8024E978 3C028027 */  lui       $v0, 0x8027
/* 141CBC 8024E97C 24420714 */  addiu     $v0, $v0, 0x714
/* 141CC0 8024E980 C4420000 */  lwc1      $f2, ($v0)
/* 141CC4 8024E984 3C038027 */  lui       $v1, 0x8027
/* 141CC8 8024E988 24630718 */  addiu     $v1, $v1, 0x718
/* 141CCC 8024E98C 46081080 */  add.s     $f2, $f2, $f8
/* 141CD0 8024E990 C4600000 */  lwc1      $f0, ($v1)
/* 141CD4 8024E994 46060000 */  add.s     $f0, $f0, $f6
/* 141CD8 8024E998 3C014180 */  lui       $at, 0x4180
/* 141CDC 8024E99C 44812000 */  mtc1      $at, $f4
/* 141CE0 8024E9A0 00000000 */  nop       
/* 141CE4 8024E9A4 4604103C */  c.lt.s    $f2, $f4
/* 141CE8 8024E9A8 E4420000 */  swc1      $f2, ($v0)
/* 141CEC 8024E9AC 45000002 */  bc1f      .L8024E9B8
/* 141CF0 8024E9B0 E4600000 */   swc1     $f0, ($v1)
/* 141CF4 8024E9B4 E4440000 */  swc1      $f4, ($v0)
.L8024E9B8:
/* 141CF8 8024E9B8 3C014100 */  lui       $at, 0x4100
/* 141CFC 8024E9BC 44811000 */  mtc1      $at, $f2
/* 141D00 8024E9C0 00000000 */  nop       
/* 141D04 8024E9C4 4602003C */  c.lt.s    $f0, $f2
/* 141D08 8024E9C8 00000000 */  nop       
/* 141D0C 8024E9CC 45030001 */  bc1tl     .L8024E9D4
/* 141D10 8024E9D0 E4620000 */   swc1     $f2, ($v1)
.L8024E9D4:
/* 141D14 8024E9D4 C4420000 */  lwc1      $f2, ($v0)
/* 141D18 8024E9D8 3C01439E */  lui       $at, 0x439e
/* 141D1C 8024E9DC 44810000 */  mtc1      $at, $f0
/* 141D20 8024E9E0 00000000 */  nop       
/* 141D24 8024E9E4 4602003E */  c.le.s    $f0, $f2
/* 141D28 8024E9E8 00000000 */  nop       
/* 141D2C 8024E9EC 45000006 */  bc1f      .L8024EA08
/* 141D30 8024E9F0 00000000 */   nop      
/* 141D34 8024E9F4 3C01439D */  lui       $at, 0x439d
/* 141D38 8024E9F8 34218000 */  ori       $at, $at, 0x8000
/* 141D3C 8024E9FC 44810000 */  mtc1      $at, $f0
/* 141D40 8024EA00 00000000 */  nop       
/* 141D44 8024EA04 E4400000 */  swc1      $f0, ($v0)
.L8024EA08:
/* 141D48 8024EA08 C4620000 */  lwc1      $f2, ($v1)
/* 141D4C 8024EA0C 3C01439A */  lui       $at, 0x439a
/* 141D50 8024EA10 44810000 */  mtc1      $at, $f0
/* 141D54 8024EA14 00000000 */  nop       
/* 141D58 8024EA18 4602003E */  c.le.s    $f0, $f2
/* 141D5C 8024EA1C 00000000 */  nop       
/* 141D60 8024EA20 45000006 */  bc1f      .L8024EA3C
/* 141D64 8024EA24 00000000 */   nop      
/* 141D68 8024EA28 3C014399 */  lui       $at, 0x4399
/* 141D6C 8024EA2C 34218000 */  ori       $at, $at, 0x8000
/* 141D70 8024EA30 44810000 */  mtc1      $at, $f0
/* 141D74 8024EA34 00000000 */  nop       
/* 141D78 8024EA38 E4600000 */  swc1      $f0, ($v1)
.L8024EA3C:
/* 141D7C 8024EA3C 3C048027 */  lui       $a0, 0x8027
/* 141D80 8024EA40 24840704 */  addiu     $a0, $a0, 0x704
/* 141D84 8024EA44 C4400000 */  lwc1      $f0, ($v0)
/* 141D88 8024EA48 C4860000 */  lwc1      $f6, ($a0)
/* 141D8C 8024EA4C 3C058027 */  lui       $a1, 0x8027
/* 141D90 8024EA50 24A50708 */  addiu     $a1, $a1, 0x708
/* 141D94 8024EA54 46060000 */  add.s     $f0, $f0, $f6
/* 141D98 8024EA58 3C018027 */  lui       $at, 0x8027
/* 141D9C 8024EA5C D4240098 */  ldc1      $f4, 0x98($at)
/* 141DA0 8024EA60 C4620000 */  lwc1      $f2, ($v1)
/* 141DA4 8024EA64 46000021 */  cvt.d.s   $f0, $f0
/* 141DA8 8024EA68 46240001 */  sub.d     $f0, $f0, $f4
/* 141DAC 8024EA6C C4A80000 */  lwc1      $f8, ($a1)
/* 141DB0 8024EA70 46081080 */  add.s     $f2, $f2, $f8
/* 141DB4 8024EA74 4620030D */  trunc.w.d $f12, $f0
/* 141DB8 8024EA78 44026000 */  mfc1      $v0, $f12
/* 141DBC 8024EA7C 3C018027 */  lui       $at, 0x8027
/* 141DC0 8024EA80 D42000A0 */  ldc1      $f0, 0xa0($at)
/* 141DC4 8024EA84 460010A1 */  cvt.d.s   $f2, $f2
/* 141DC8 8024EA88 46201081 */  sub.d     $f2, $f2, $f0
/* 141DCC 8024EA8C 3C018027 */  lui       $at, 0x8027
/* 141DD0 8024EA90 D42000A8 */  ldc1      $f0, 0xa8($at)
/* 141DD4 8024EA94 44822000 */  mtc1      $v0, $f4
/* 141DD8 8024EA98 00000000 */  nop       
/* 141DDC 8024EA9C 46802121 */  cvt.d.w   $f4, $f4
/* 141DE0 8024EAA0 4624003E */  c.le.d    $f0, $f4
/* 141DE4 8024EAA4 4620130D */  trunc.w.d $f12, $f2
/* 141DE8 8024EAA8 44026000 */  mfc1      $v0, $f12
/* 141DEC 8024EAAC 45000006 */  bc1f      .L8024EAC8
/* 141DF0 8024EAB0 00000000 */   nop      
/* 141DF4 8024EAB4 46202081 */  sub.d     $f2, $f4, $f0
/* 141DF8 8024EAB8 46003021 */  cvt.d.s   $f0, $f6
/* 141DFC 8024EABC 46220001 */  sub.d     $f0, $f0, $f2
/* 141E00 8024EAC0 46200020 */  cvt.s.d   $f0, $f0
/* 141E04 8024EAC4 E4800000 */  swc1      $f0, ($a0)
.L8024EAC8:
/* 141E08 8024EAC8 3C018027 */  lui       $at, 0x8027
/* 141E0C 8024EACC D42000B0 */  ldc1      $f0, 0xb0($at)
/* 141E10 8024EAD0 4620203E */  c.le.d    $f4, $f0
/* 141E14 8024EAD4 00000000 */  nop       
/* 141E18 8024EAD8 45000009 */  bc1f      .L8024EB00
/* 141E1C 8024EADC 00000000 */   nop      
/* 141E20 8024EAE0 3C018027 */  lui       $at, 0x8027
/* 141E24 8024EAE4 D42200B8 */  ldc1      $f2, 0xb8($at)
/* 141E28 8024EAE8 C4800000 */  lwc1      $f0, ($a0)
/* 141E2C 8024EAEC 46222080 */  add.d     $f2, $f4, $f2
/* 141E30 8024EAF0 46000021 */  cvt.d.s   $f0, $f0
/* 141E34 8024EAF4 46220001 */  sub.d     $f0, $f0, $f2
/* 141E38 8024EAF8 46200020 */  cvt.s.d   $f0, $f0
/* 141E3C 8024EAFC E4800000 */  swc1      $f0, ($a0)
.L8024EB00:
/* 141E40 8024EB00 3C01402E */  lui       $at, 0x402e
/* 141E44 8024EB04 44813800 */  mtc1      $at, $f7
/* 141E48 8024EB08 44803000 */  mtc1      $zero, $f6
/* 141E4C 8024EB0C 44822000 */  mtc1      $v0, $f4
/* 141E50 8024EB10 00000000 */  nop       
/* 141E54 8024EB14 46802121 */  cvt.d.w   $f4, $f4
/* 141E58 8024EB18 4624303E */  c.le.d    $f6, $f4
/* 141E5C 8024EB1C 00000000 */  nop       
/* 141E60 8024EB20 45000006 */  bc1f      .L8024EB3C
/* 141E64 8024EB24 00000000 */   nop      
/* 141E68 8024EB28 46262081 */  sub.d     $f2, $f4, $f6
/* 141E6C 8024EB2C 46004021 */  cvt.d.s   $f0, $f8
/* 141E70 8024EB30 46220001 */  sub.d     $f0, $f0, $f2
/* 141E74 8024EB34 46200020 */  cvt.s.d   $f0, $f0
/* 141E78 8024EB38 E4A00000 */  swc1      $f0, ($a1)
.L8024EB3C:
/* 141E7C 8024EB3C 3C01C02E */  lui       $at, 0xc02e
/* 141E80 8024EB40 44810800 */  mtc1      $at, $f1
/* 141E84 8024EB44 44800000 */  mtc1      $zero, $f0
/* 141E88 8024EB48 00000000 */  nop       
/* 141E8C 8024EB4C 4620203E */  c.le.d    $f4, $f0
/* 141E90 8024EB50 00000000 */  nop       
/* 141E94 8024EB54 45000007 */  bc1f      .L8024EB74
/* 141E98 8024EB58 00000000 */   nop      
/* 141E9C 8024EB5C C4A00000 */  lwc1      $f0, ($a1)
/* 141EA0 8024EB60 46262080 */  add.d     $f2, $f4, $f6
/* 141EA4 8024EB64 46000021 */  cvt.d.s   $f0, $f0
/* 141EA8 8024EB68 46220001 */  sub.d     $f0, $f0, $f2
/* 141EAC 8024EB6C 46200020 */  cvt.s.d   $f0, $f0
/* 141EB0 8024EB70 E4A00000 */  swc1      $f0, ($a1)
.L8024EB74:
/* 141EB4 8024EB74 C4800000 */  lwc1      $f0, ($a0)
/* 141EB8 8024EB78 44801000 */  mtc1      $zero, $f2
/* 141EBC 8024EB7C 00000000 */  nop       
/* 141EC0 8024EB80 4600103C */  c.lt.s    $f2, $f0
/* 141EC4 8024EB84 00000000 */  nop       
/* 141EC8 8024EB88 45030001 */  bc1tl     .L8024EB90
/* 141ECC 8024EB8C E4820000 */   swc1     $f2, ($a0)
.L8024EB90:
/* 141ED0 8024EB90 C4A00000 */  lwc1      $f0, ($a1)
/* 141ED4 8024EB94 4600103C */  c.lt.s    $f2, $f0
/* 141ED8 8024EB98 00000000 */  nop       
/* 141EDC 8024EB9C 45030001 */  bc1tl     .L8024EBA4
/* 141EE0 8024EBA0 E4A20000 */   swc1     $f2, ($a1)
.L8024EBA4:
/* 141EE4 8024EBA4 C4800000 */  lwc1      $f0, ($a0)
/* 141EE8 8024EBA8 3C01C2AC */  lui       $at, 0xc2ac
/* 141EEC 8024EBAC 44811000 */  mtc1      $at, $f2
/* 141EF0 8024EBB0 00000000 */  nop       
/* 141EF4 8024EBB4 4602003C */  c.lt.s    $f0, $f2
/* 141EF8 8024EBB8 00000000 */  nop       
/* 141EFC 8024EBBC 45030001 */  bc1tl     .L8024EBC4
/* 141F00 8024EBC0 E4820000 */   swc1     $f2, ($a0)
.L8024EBC4:
/* 141F04 8024EBC4 C4A00000 */  lwc1      $f0, ($a1)
/* 141F08 8024EBC8 3C01C352 */  lui       $at, 0xc352
/* 141F0C 8024EBCC 44811000 */  mtc1      $at, $f2
/* 141F10 8024EBD0 00000000 */  nop       
/* 141F14 8024EBD4 4602003C */  c.lt.s    $f0, $f2
/* 141F18 8024EBD8 00000000 */  nop       
/* 141F1C 8024EBDC 45030001 */  bc1tl     .L8024EBE4
/* 141F20 8024EBE0 E4A20000 */   swc1     $f2, ($a1)
.L8024EBE4:
/* 141F24 8024EBE4 3C028027 */  lui       $v0, %hi(gPauseMenuPressedButtons)
/* 141F28 8024EBE8 8C4200C4 */  lw        $v0, %lo(gPauseMenuPressedButtons)($v0)
/* 141F2C 8024EBEC 30424000 */  andi      $v0, $v0, 0x4000
/* 141F30 8024EBF0 10400007 */  beqz      $v0, .L8024EC10
/* 141F34 8024EBF4 2402FFFF */   addiu    $v0, $zero, -1
/* 141F38 8024EBF8 0C05272D */  jal       play_sound
/* 141F3C 8024EBFC 240400CA */   addiu    $a0, $zero, 0xca
/* 141F40 8024EC00 3C018027 */  lui       $at, %hi(gPauseMenuCurrentTab)
/* 141F44 8024EC04 A02000D4 */  sb        $zero, %lo(gPauseMenuCurrentTab)($at)
/* 141F48 8024EC08 08093B27 */  j         .L8024EC9C
/* 141F4C 8024EC0C 00000000 */   nop      
.L8024EC10:
/* 141F50 8024EC10 3C118027 */  lui       $s1, 0x8027
/* 141F54 8024EC14 2631071C */  addiu     $s1, $s1, 0x71c
/* 141F58 8024EC18 3C018027 */  lui       $at, %hi(gPauseMenuCurrentDescIconScript)
/* 141F5C 8024EC1C AC2000CC */  sw        $zero, %lo(gPauseMenuCurrentDescIconScript)($at)
/* 141F60 8024EC20 8E260000 */  lw        $a2, ($s1)
/* 141F64 8024EC24 14C20005 */  bne       $a2, $v0, .L8024EC3C
/* 141F68 8024EC28 3C03001D */   lui      $v1, 0x1d
/* 141F6C 8024EC2C 3C018027 */  lui       $at, %hi(gPauseMenuCurrentDescString)
/* 141F70 8024EC30 AC2000C8 */  sw        $zero, %lo(gPauseMenuCurrentDescString)($at)
/* 141F74 8024EC34 08093B27 */  j         .L8024EC9C
/* 141F78 8024EC38 00000000 */   nop      
.L8024EC3C:
/* 141F7C 8024EC3C 346300F3 */  ori       $v1, $v1, 0xf3
/* 141F80 8024EC40 0000202D */  daddu     $a0, $zero, $zero
/* 141F84 8024EC44 3C05F5DE */  lui       $a1, 0xf5de
/* 141F88 8024EC48 34A50180 */  ori       $a1, $a1, 0x180
/* 141F8C 8024EC4C 3C108027 */  lui       $s0, %hi(gPauseMenuCurrentDescString)
/* 141F90 8024EC50 261000C8 */  addiu     $s0, $s0, %lo(gPauseMenuCurrentDescString)
/* 141F94 8024EC54 00061040 */  sll       $v0, $a2, 1
/* 141F98 8024EC58 00461021 */  addu      $v0, $v0, $a2
/* 141F9C 8024EC5C 00431021 */  addu      $v0, $v0, $v1
/* 141FA0 8024EC60 0C0B1EAF */  jal       get_variable
/* 141FA4 8024EC64 AE020000 */   sw       $v0, ($s0)
/* 141FA8 8024EC68 8E240000 */  lw        $a0, ($s1)
/* 141FAC 8024EC6C 00041880 */  sll       $v1, $a0, 2
/* 141FB0 8024EC70 00641821 */  addu      $v1, $v1, $a0
/* 141FB4 8024EC74 00031880 */  sll       $v1, $v1, 2
/* 141FB8 8024EC78 3C018025 */  lui       $at, 0x8025
/* 141FBC 8024EC7C 00230821 */  addu      $at, $at, $v1
/* 141FC0 8024EC80 8C2302C4 */  lw        $v1, 0x2c4($at)
/* 141FC4 8024EC84 0043102A */  slt       $v0, $v0, $v1
/* 141FC8 8024EC88 14400004 */  bnez      $v0, .L8024EC9C
/* 141FCC 8024EC8C 00000000 */   nop      
/* 141FD0 8024EC90 8E020000 */  lw        $v0, ($s0)
/* 141FD4 8024EC94 24420001 */  addiu     $v0, $v0, 1
/* 141FD8 8024EC98 AE020000 */  sw        $v0, ($s0)
.L8024EC9C:
/* 141FDC 8024EC9C 8FBF0018 */  lw        $ra, 0x18($sp)
/* 141FE0 8024ECA0 8FB10014 */  lw        $s1, 0x14($sp)
/* 141FE4 8024ECA4 8FB00010 */  lw        $s0, 0x10($sp)
/* 141FE8 8024ECA8 03E00008 */  jr        $ra
/* 141FEC 8024ECAC 27BD0020 */   addiu    $sp, $sp, 0x20
