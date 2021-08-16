.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E006A94C
/* 36D96C E006A94C 27BDFEE0 */  addiu     $sp, $sp, -0x120
/* 36D970 E006A950 AFA40120 */  sw        $a0, 0x120($sp)
/* 36D974 E006A954 8FA80120 */  lw        $t0, 0x120($sp)
/* 36D978 E006A958 3C07DB06 */  lui       $a3, 0xdb06
/* 36D97C E006A95C AFB100E4 */  sw        $s1, 0xe4($sp)
/* 36D980 E006A960 3C11800A */  lui       $s1, %hi(gMasterGfxPos)
/* 36D984 E006A964 2631A66C */  addiu     $s1, $s1, %lo(gMasterGfxPos)
/* 36D988 E006A968 AFBF0104 */  sw        $ra, 0x104($sp)
/* 36D98C E006A96C AFBE0100 */  sw        $fp, 0x100($sp)
/* 36D990 E006A970 AFB700FC */  sw        $s7, 0xfc($sp)
/* 36D994 E006A974 AFB600F8 */  sw        $s6, 0xf8($sp)
/* 36D998 E006A978 AFB500F4 */  sw        $s5, 0xf4($sp)
/* 36D99C E006A97C AFB400F0 */  sw        $s4, 0xf0($sp)
/* 36D9A0 E006A980 AFB300EC */  sw        $s3, 0xec($sp)
/* 36D9A4 E006A984 AFB200E8 */  sw        $s2, 0xe8($sp)
/* 36D9A8 E006A988 AFB000E0 */  sw        $s0, 0xe0($sp)
/* 36D9AC E006A98C F7B80118 */  sdc1      $f24, 0x118($sp)
/* 36D9B0 E006A990 F7B60110 */  sdc1      $f22, 0x110($sp)
/* 36D9B4 E006A994 F7B40108 */  sdc1      $f20, 0x108($sp)
/* 36D9B8 E006A998 8E230000 */  lw        $v1, ($s1)
/* 36D9BC E006A99C 8D12000C */  lw        $s2, 0xc($t0)
/* 36D9C0 E006A9A0 0060282D */  daddu     $a1, $v1, $zero
/* 36D9C4 E006A9A4 8E570000 */  lw        $s7, ($s2)
/* 36D9C8 E006A9A8 24630008 */  addiu     $v1, $v1, 8
/* 36D9CC E006A9AC AE230000 */  sw        $v1, ($s1)
/* 36D9D0 E006A9B0 00171080 */  sll       $v0, $s7, 2
/* 36D9D4 E006A9B4 3C08E007 */  lui       $t0, %hi(D_E006ADF0)
/* 36D9D8 E006A9B8 01024021 */  addu      $t0, $t0, $v0
/* 36D9DC E006A9BC 8D08ADF0 */  lw        $t0, %lo(D_E006ADF0)($t0)
/* 36D9E0 E006A9C0 34E70024 */  ori       $a3, $a3, 0x24
/* 36D9E4 E006A9C4 AFA800D8 */  sw        $t0, 0xd8($sp)
/* 36D9E8 E006A9C8 3C06E007 */  lui       $a2, %hi(D_E006AE00)
/* 36D9EC E006A9CC 00C23021 */  addu      $a2, $a2, $v0
/* 36D9F0 E006A9D0 8CC6AE00 */  lw        $a2, %lo(D_E006AE00)($a2)
/* 36D9F4 E006A9D4 3C02E700 */  lui       $v0, 0xe700
/* 36D9F8 E006A9D8 ACA20000 */  sw        $v0, ($a1)
/* 36D9FC E006A9DC ACA00004 */  sw        $zero, 4($a1)
/* 36DA00 E006A9E0 AC670000 */  sw        $a3, ($v1)
/* 36DA04 E006A9E4 8FA80120 */  lw        $t0, 0x120($sp)
/* 36DA08 E006A9E8 27A40098 */  addiu     $a0, $sp, 0x98
/* 36DA0C E006A9EC 8D050010 */  lw        $a1, 0x10($t0)
/* 36DA10 E006A9F0 24620008 */  addiu     $v0, $v1, 8
/* 36DA14 E006A9F4 AE220000 */  sw        $v0, ($s1)
/* 36DA18 E006A9F8 8CA5001C */  lw        $a1, 0x1c($a1)
/* 36DA1C E006A9FC 3C02DE00 */  lui       $v0, 0xde00
/* 36DA20 E006AA00 AC620008 */  sw        $v0, 8($v1)
/* 36DA24 E006AA04 3C028000 */  lui       $v0, 0x8000
/* 36DA28 E006AA08 AC66000C */  sw        $a2, 0xc($v1)
/* 36DA2C E006AA0C 00A22821 */  addu      $a1, $a1, $v0
/* 36DA30 E006AA10 AC650004 */  sw        $a1, 4($v1)
/* 36DA34 E006AA14 8E450010 */  lw        $a1, 0x10($s2)
/* 36DA38 E006AA18 8E460014 */  lw        $a2, 0x14($s2)
/* 36DA3C E006AA1C 8E470018 */  lw        $a3, 0x18($s2)
/* 36DA40 E006AA20 24630010 */  addiu     $v1, $v1, 0x10
/* 36DA44 E006AA24 0C080108 */  jal       func_E0200420
/* 36DA48 E006AA28 AE230000 */   sw       $v1, ($s1)
/* 36DA4C E006AA2C 8FA80120 */  lw        $t0, 0x120($sp)
/* 36DA50 E006AA30 24140001 */  addiu     $s4, $zero, 1
/* 36DA54 E006AA34 8D020008 */  lw        $v0, 8($t0)
/* 36DA58 E006AA38 0282102A */  slt       $v0, $s4, $v0
/* 36DA5C E006AA3C 104000D2 */  beqz      $v0, .LE006AD88
/* 36DA60 E006AA40 26520094 */   addiu    $s2, $s2, 0x94
/* 36DA64 E006AA44 2AF60002 */  slti      $s6, $s7, 2
/* 36DA68 E006AA48 27B00058 */  addiu     $s0, $sp, 0x58
/* 36DA6C E006AA4C 0220982D */  daddu     $s3, $s1, $zero
/* 36DA70 E006AA50 3C1E8007 */  lui       $fp, %hi(gMatrixListPos)
/* 36DA74 E006AA54 27DE41F0 */  addiu     $fp, $fp, %lo(gMatrixListPos)
/* 36DA78 E006AA58 3C150001 */  lui       $s5, 1
/* 36DA7C E006AA5C 36B51630 */  ori       $s5, $s5, 0x1630
/* 36DA80 E006AA60 26510024 */  addiu     $s1, $s2, 0x24
/* 36DA84 E006AA64 3C013F80 */  lui       $at, 0x3f80
/* 36DA88 E006AA68 4481C000 */  mtc1      $at, $f24
/* 36DA8C E006AA6C 4480B000 */  mtc1      $zero, $f22
.LE006AA70:
/* 36DA90 E006AA70 3C01437F */  lui       $at, 0x437f
/* 36DA94 E006AA74 44811000 */  mtc1      $at, $f2
/* 36DA98 E006AA78 C6200000 */  lwc1      $f0, ($s1)
/* 36DA9C E006AA7C 46800020 */  cvt.s.w   $f0, $f0
/* 36DAA0 E006AA80 16C00003 */  bnez      $s6, .LE006AA90
/* 36DAA4 E006AA84 46020503 */   div.s    $f20, $f0, $f2
/* 36DAA8 E006AA88 0C01AA17 */  jal       func_E006A85C
/* 36DAAC E006AA8C 0240202D */   daddu    $a0, $s2, $zero
.LE006AA90:
/* 36DAB0 E006AA90 E7B60010 */  swc1      $f22, 0x10($sp)
/* 36DAB4 E006AA94 8E250038 */  lw        $a1, 0x38($s1)
/* 36DAB8 E006AA98 4406C000 */  mfc1      $a2, $f24
/* 36DABC E006AA9C 4407B000 */  mfc1      $a3, $f22
/* 36DAC0 E006AAA0 0C080104 */  jal       func_E0200410
/* 36DAC4 E006AAA4 0200202D */   daddu    $a0, $s0, $zero
/* 36DAC8 E006AAA8 0200202D */  daddu     $a0, $s0, $zero
/* 36DACC E006AAAC 27A50098 */  addiu     $a1, $sp, 0x98
/* 36DAD0 E006AAB0 0C080114 */  jal       func_E0200450
/* 36DAD4 E006AAB4 27A60018 */   addiu    $a2, $sp, 0x18
/* 36DAD8 E006AAB8 56C00060 */  bnel      $s6, $zero, .LE006AC3C
/* 36DADC E006AABC E7B60010 */   swc1     $f22, 0x10($sp)
/* 36DAE0 E006AAC0 C6220040 */  lwc1      $f2, 0x40($s1)
/* 36DAE4 E006AAC4 24020003 */  addiu     $v0, $zero, 3
/* 36DAE8 E006AAC8 56E20005 */  bnel      $s7, $v0, .LE006AAE0
/* 36DAEC E006AACC 46161000 */   add.s    $f0, $f2, $f22
/* 36DAF0 E006AAD0 3C014234 */  lui       $at, 0x4234
/* 36DAF4 E006AAD4 44810000 */  mtc1      $at, $f0
/* 36DAF8 E006AAD8 00000000 */  nop
/* 36DAFC E006AADC 46001000 */  add.s     $f0, $f2, $f0
.LE006AAE0:
/* 36DB00 E006AAE0 44050000 */  mfc1      $a1, $f0
/* 36DB04 E006AAE4 4406B000 */  mfc1      $a2, $f22
/* 36DB08 E006AAE8 4407B000 */  mfc1      $a3, $f22
/* 36DB0C E006AAEC 0200202D */  daddu     $a0, $s0, $zero
/* 36DB10 E006AAF0 0C080104 */  jal       func_E0200410
/* 36DB14 E006AAF4 E7B80010 */   swc1     $f24, 0x10($sp)
/* 36DB18 E006AAF8 0200202D */  daddu     $a0, $s0, $zero
/* 36DB1C E006AAFC 27A50018 */  addiu     $a1, $sp, 0x18
/* 36DB20 E006AB00 0C080114 */  jal       func_E0200450
/* 36DB24 E006AB04 00A0302D */   daddu    $a2, $a1, $zero
/* 36DB28 E006AB08 E7B60010 */  swc1      $f22, 0x10($sp)
/* 36DB2C E006AB0C 8E25003C */  lw        $a1, 0x3c($s1)
/* 36DB30 E006AB10 4406B000 */  mfc1      $a2, $f22
/* 36DB34 E006AB14 4407C000 */  mfc1      $a3, $f24
/* 36DB38 E006AB18 0C080104 */  jal       func_E0200410
/* 36DB3C E006AB1C 0200202D */   daddu    $a0, $s0, $zero
/* 36DB40 E006AB20 0200202D */  daddu     $a0, $s0, $zero
/* 36DB44 E006AB24 27A50018 */  addiu     $a1, $sp, 0x18
/* 36DB48 E006AB28 0C080114 */  jal       func_E0200450
/* 36DB4C E006AB2C 00A0302D */   daddu    $a2, $a1, $zero
/* 36DB50 E006AB30 8E250034 */  lw        $a1, 0x34($s1)
/* 36DB54 E006AB34 4406B000 */  mfc1      $a2, $f22
/* 36DB58 E006AB38 4407B000 */  mfc1      $a3, $f22
/* 36DB5C E006AB3C 0C080108 */  jal       func_E0200420
/* 36DB60 E006AB40 0200202D */   daddu    $a0, $s0, $zero
/* 36DB64 E006AB44 0200202D */  daddu     $a0, $s0, $zero
/* 36DB68 E006AB48 27A50018 */  addiu     $a1, $sp, 0x18
/* 36DB6C E006AB4C 0C080114 */  jal       func_E0200450
/* 36DB70 E006AB50 00A0302D */   daddu    $a2, $a1, $zero
/* 36DB74 E006AB54 3C014040 */  lui       $at, 0x4040
/* 36DB78 E006AB58 44810000 */  mtc1      $at, $f0
/* 36DB7C E006AB5C 00000000 */  nop
/* 36DB80 E006AB60 4600A000 */  add.s     $f0, $f20, $f0
/* 36DB84 E006AB64 3C013FD0 */  lui       $at, 0x3fd0
/* 36DB88 E006AB68 44811800 */  mtc1      $at, $f3
/* 36DB8C E006AB6C 44801000 */  mtc1      $zero, $f2
/* 36DB90 E006AB70 46000021 */  cvt.d.s   $f0, $f0
/* 36DB94 E006AB74 46220002 */  mul.d     $f0, $f0, $f2
/* 36DB98 E006AB78 00000000 */  nop
/* 36DB9C E006AB7C 32830003 */  andi      $v1, $s4, 3
/* 36DBA0 E006AB80 24020001 */  addiu     $v0, $zero, 1
/* 36DBA4 E006AB84 46200120 */  cvt.s.d   $f4, $f0
/* 36DBA8 E006AB88 10620010 */  beq       $v1, $v0, .LE006ABCC
/* 36DBAC E006AB8C 46002186 */   mov.s    $f6, $f4
/* 36DBB0 E006AB90 28620002 */  slti      $v0, $v1, 2
/* 36DBB4 E006AB94 10400005 */  beqz      $v0, .LE006ABAC
/* 36DBB8 E006AB98 24020002 */   addiu    $v0, $zero, 2
/* 36DBBC E006AB9C 10600007 */  beqz      $v1, .LE006ABBC
/* 36DBC0 E006ABA0 00000000 */   nop
/* 36DBC4 E006ABA4 0801AAFD */  j         .LE006ABF4
/* 36DBC8 E006ABA8 4600A006 */   mov.s    $f0, $f20
.LE006ABAC:
/* 36DBCC E006ABAC 5062000C */  beql      $v1, $v0, .LE006ABE0
/* 36DBD0 E006ABB0 4600A021 */   cvt.d.s  $f0, $f20
/* 36DBD4 E006ABB4 0801AAFD */  j         .LE006ABF4
/* 36DBD8 E006ABB8 4600A006 */   mov.s    $f0, $f20
.LE006ABBC:
/* 36DBDC E006ABBC 3C01E007 */  lui       $at, %hi(D_E006AF58)
/* 36DBE0 E006ABC0 D422AF58 */  ldc1      $f2, %lo(D_E006AF58)($at)
/* 36DBE4 E006ABC4 0801AAFA */  j         .LE006ABE8
/* 36DBE8 E006ABC8 4600A021 */   cvt.d.s  $f0, $f20
.LE006ABCC:
/* 36DBEC E006ABCC 3C013FE0 */  lui       $at, 0x3fe0
/* 36DBF0 E006ABD0 44811800 */  mtc1      $at, $f3
/* 36DBF4 E006ABD4 44801000 */  mtc1      $zero, $f2
/* 36DBF8 E006ABD8 0801AAFA */  j         .LE006ABE8
/* 36DBFC E006ABDC 4600A021 */   cvt.d.s  $f0, $f20
.LE006ABE0:
/* 36DC00 E006ABE0 3C01E007 */  lui       $at, %hi(D_E006AF60)
/* 36DC04 E006ABE4 D422AF60 */  ldc1      $f2, %lo(D_E006AF60)($at)
.LE006ABE8:
/* 36DC08 E006ABE8 46220002 */  mul.d     $f0, $f0, $f2
/* 36DC0C E006ABEC 00000000 */  nop
/* 36DC10 E006ABF0 46200020 */  cvt.s.d   $f0, $f0
.LE006ABF4:
/* 36DC14 E006ABF4 44053000 */  mfc1      $a1, $f6
/* 36DC18 E006ABF8 44060000 */  mfc1      $a2, $f0
/* 36DC1C E006ABFC 44072000 */  mfc1      $a3, $f4
/* 36DC20 E006AC00 0C080110 */  jal       func_E0200440
/* 36DC24 E006AC04 0200202D */   daddu    $a0, $s0, $zero
/* 36DC28 E006AC08 0200202D */  daddu     $a0, $s0, $zero
/* 36DC2C E006AC0C 27A50018 */  addiu     $a1, $sp, 0x18
/* 36DC30 E006AC10 0C080114 */  jal       func_E0200450
/* 36DC34 E006AC14 00A0302D */   daddu    $a2, $a1, $zero
/* 36DC38 E006AC18 8E620000 */  lw        $v0, ($s3)
/* 36DC3C E006AC1C 0040202D */  daddu     $a0, $v0, $zero
/* 36DC40 E006AC20 24420008 */  addiu     $v0, $v0, 8
/* 36DC44 E006AC24 AE620000 */  sw        $v0, ($s3)
/* 36DC48 E006AC28 3C02FA00 */  lui       $v0, 0xfa00
/* 36DC4C E006AC2C AC820000 */  sw        $v0, ($a0)
/* 36DC50 E006AC30 92220003 */  lbu       $v0, 3($s1)
/* 36DC54 E006AC34 0801AB33 */  j         .LE006ACCC
/* 36DC58 E006AC38 2403F000 */   addiu    $v1, $zero, -0x1000
.LE006AC3C:
/* 36DC5C E006AC3C 8E25003C */  lw        $a1, 0x3c($s1)
/* 36DC60 E006AC40 4406B000 */  mfc1      $a2, $f22
/* 36DC64 E006AC44 4407C000 */  mfc1      $a3, $f24
/* 36DC68 E006AC48 0C080104 */  jal       func_E0200410
/* 36DC6C E006AC4C 0200202D */   daddu    $a0, $s0, $zero
/* 36DC70 E006AC50 0200202D */  daddu     $a0, $s0, $zero
/* 36DC74 E006AC54 27A50018 */  addiu     $a1, $sp, 0x18
/* 36DC78 E006AC58 0C080114 */  jal       func_E0200450
/* 36DC7C E006AC5C 00A0302D */   daddu    $a2, $a1, $zero
/* 36DC80 E006AC60 E7B80010 */  swc1      $f24, 0x10($sp)
/* 36DC84 E006AC64 8E250040 */  lw        $a1, 0x40($s1)
/* 36DC88 E006AC68 4406B000 */  mfc1      $a2, $f22
/* 36DC8C E006AC6C 4407B000 */  mfc1      $a3, $f22
/* 36DC90 E006AC70 0C080104 */  jal       func_E0200410
/* 36DC94 E006AC74 0200202D */   daddu    $a0, $s0, $zero
/* 36DC98 E006AC78 0200202D */  daddu     $a0, $s0, $zero
/* 36DC9C E006AC7C 27A50018 */  addiu     $a1, $sp, 0x18
/* 36DCA0 E006AC80 0C080114 */  jal       func_E0200450
/* 36DCA4 E006AC84 00A0302D */   daddu    $a2, $a1, $zero
/* 36DCA8 E006AC88 8E250034 */  lw        $a1, 0x34($s1)
/* 36DCAC E006AC8C 4406B000 */  mfc1      $a2, $f22
/* 36DCB0 E006AC90 4407B000 */  mfc1      $a3, $f22
/* 36DCB4 E006AC94 0C080108 */  jal       func_E0200420
/* 36DCB8 E006AC98 0200202D */   daddu    $a0, $s0, $zero
/* 36DCBC E006AC9C 0200202D */  daddu     $a0, $s0, $zero
/* 36DCC0 E006ACA0 27A50018 */  addiu     $a1, $sp, 0x18
/* 36DCC4 E006ACA4 0C080114 */  jal       func_E0200450
/* 36DCC8 E006ACA8 00A0302D */   daddu    $a2, $a1, $zero
/* 36DCCC E006ACAC 8E620000 */  lw        $v0, ($s3)
/* 36DCD0 E006ACB0 0040202D */  daddu     $a0, $v0, $zero
/* 36DCD4 E006ACB4 24420008 */  addiu     $v0, $v0, 8
/* 36DCD8 E006ACB8 AE620000 */  sw        $v0, ($s3)
/* 36DCDC E006ACBC 3C02FA00 */  lui       $v0, 0xfa00
/* 36DCE0 E006ACC0 AC820000 */  sw        $v0, ($a0)
/* 36DCE4 E006ACC4 92220003 */  lbu       $v0, 3($s1)
/* 36DCE8 E006ACC8 2403B500 */  addiu     $v1, $zero, -0x4b00
.LE006ACCC:
/* 36DCEC E006ACCC 00431025 */  or        $v0, $v0, $v1
/* 36DCF0 E006ACD0 AC820004 */  sw        $v0, 4($a0)
/* 36DCF4 E006ACD4 27A40018 */  addiu     $a0, $sp, 0x18
/* 36DCF8 E006ACD8 26940001 */  addiu     $s4, $s4, 1
/* 36DCFC E006ACDC 26310094 */  addiu     $s1, $s1, 0x94
/* 36DD00 E006ACE0 97C50000 */  lhu       $a1, ($fp)
/* 36DD04 E006ACE4 3C02800A */  lui       $v0, %hi(gDisplayContext)
/* 36DD08 E006ACE8 8C42A674 */  lw        $v0, %lo(gDisplayContext)($v0)
/* 36DD0C E006ACEC 00052980 */  sll       $a1, $a1, 6
/* 36DD10 E006ACF0 00B52821 */  addu      $a1, $a1, $s5
/* 36DD14 E006ACF4 0C080118 */  jal       func_E0200460
/* 36DD18 E006ACF8 00452821 */   addu     $a1, $v0, $a1
/* 36DD1C E006ACFC 3C02DA38 */  lui       $v0, 0xda38
/* 36DD20 E006AD00 34420002 */  ori       $v0, $v0, 2
/* 36DD24 E006AD04 3C06D838 */  lui       $a2, 0xd838
/* 36DD28 E006AD08 34C60002 */  ori       $a2, $a2, 2
/* 36DD2C E006AD0C 8E640000 */  lw        $a0, ($s3)
/* 36DD30 E006AD10 97C30000 */  lhu       $v1, ($fp)
/* 36DD34 E006AD14 0080282D */  daddu     $a1, $a0, $zero
/* 36DD38 E006AD18 24840008 */  addiu     $a0, $a0, 8
/* 36DD3C E006AD1C AE640000 */  sw        $a0, ($s3)
/* 36DD40 E006AD20 ACA20000 */  sw        $v0, ($a1)
/* 36DD44 E006AD24 24620001 */  addiu     $v0, $v1, 1
/* 36DD48 E006AD28 3063FFFF */  andi      $v1, $v1, 0xffff
/* 36DD4C E006AD2C 00031980 */  sll       $v1, $v1, 6
/* 36DD50 E006AD30 A7C20000 */  sh        $v0, ($fp)
/* 36DD54 E006AD34 3C02800A */  lui       $v0, %hi(gDisplayContext)
/* 36DD58 E006AD38 8C42A674 */  lw        $v0, %lo(gDisplayContext)($v0)
/* 36DD5C E006AD3C 00751821 */  addu      $v1, $v1, $s5
/* 36DD60 E006AD40 00431021 */  addu      $v0, $v0, $v1
/* 36DD64 E006AD44 ACA20004 */  sw        $v0, 4($a1)
/* 36DD68 E006AD48 24820008 */  addiu     $v0, $a0, 8
/* 36DD6C E006AD4C AE620000 */  sw        $v0, ($s3)
/* 36DD70 E006AD50 3C02DE00 */  lui       $v0, 0xde00
/* 36DD74 E006AD54 AC820000 */  sw        $v0, ($a0)
/* 36DD78 E006AD58 8FA800D8 */  lw        $t0, 0xd8($sp)
/* 36DD7C E006AD5C 24020040 */  addiu     $v0, $zero, 0x40
/* 36DD80 E006AD60 AC860008 */  sw        $a2, 8($a0)
/* 36DD84 E006AD64 AC82000C */  sw        $v0, 0xc($a0)
/* 36DD88 E006AD68 AC880004 */  sw        $t0, 4($a0)
/* 36DD8C E006AD6C 8FA80120 */  lw        $t0, 0x120($sp)
/* 36DD90 E006AD70 26520094 */  addiu     $s2, $s2, 0x94
/* 36DD94 E006AD74 8D020008 */  lw        $v0, 8($t0)
/* 36DD98 E006AD78 24840010 */  addiu     $a0, $a0, 0x10
/* 36DD9C E006AD7C 0282102A */  slt       $v0, $s4, $v0
/* 36DDA0 E006AD80 1440FF3B */  bnez      $v0, .LE006AA70
/* 36DDA4 E006AD84 AE640000 */   sw       $a0, ($s3)
.LE006AD88:
/* 36DDA8 E006AD88 3C03800A */  lui       $v1, %hi(gMasterGfxPos)
/* 36DDAC E006AD8C 2463A66C */  addiu     $v1, $v1, %lo(gMasterGfxPos)
/* 36DDB0 E006AD90 8C620000 */  lw        $v0, ($v1)
/* 36DDB4 E006AD94 0040202D */  daddu     $a0, $v0, $zero
/* 36DDB8 E006AD98 24420008 */  addiu     $v0, $v0, 8
/* 36DDBC E006AD9C AC620000 */  sw        $v0, ($v1)
/* 36DDC0 E006ADA0 3C02E700 */  lui       $v0, 0xe700
/* 36DDC4 E006ADA4 AC820000 */  sw        $v0, ($a0)
/* 36DDC8 E006ADA8 AC800004 */  sw        $zero, 4($a0)
/* 36DDCC E006ADAC 8FBF0104 */  lw        $ra, 0x104($sp)
/* 36DDD0 E006ADB0 8FBE0100 */  lw        $fp, 0x100($sp)
/* 36DDD4 E006ADB4 8FB700FC */  lw        $s7, 0xfc($sp)
/* 36DDD8 E006ADB8 8FB600F8 */  lw        $s6, 0xf8($sp)
/* 36DDDC E006ADBC 8FB500F4 */  lw        $s5, 0xf4($sp)
/* 36DDE0 E006ADC0 8FB400F0 */  lw        $s4, 0xf0($sp)
/* 36DDE4 E006ADC4 8FB300EC */  lw        $s3, 0xec($sp)
/* 36DDE8 E006ADC8 8FB200E8 */  lw        $s2, 0xe8($sp)
/* 36DDEC E006ADCC 8FB100E4 */  lw        $s1, 0xe4($sp)
/* 36DDF0 E006ADD0 8FB000E0 */  lw        $s0, 0xe0($sp)
/* 36DDF4 E006ADD4 D7B80118 */  ldc1      $f24, 0x118($sp)
/* 36DDF8 E006ADD8 D7B60110 */  ldc1      $f22, 0x110($sp)
/* 36DDFC E006ADDC D7B40108 */  ldc1      $f20, 0x108($sp)
/* 36DE00 E006ADE0 03E00008 */  jr        $ra
/* 36DE04 E006ADE4 27BD0120 */   addiu    $sp, $sp, 0x120
/* 36DE08 E006ADE8 00000000 */  nop
/* 36DE0C E006ADEC 00000000 */  nop
