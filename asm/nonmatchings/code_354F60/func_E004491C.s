.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E004491C
/* 35587C E004491C 27BDFEE8 */  addiu     $sp, $sp, -0x118
/* 355880 E0044920 3C07DB06 */  lui       $a3, 0xdb06
/* 355884 E0044924 34E70024 */  ori       $a3, $a3, 0x24
/* 355888 E0044928 AFA40118 */  sw        $a0, 0x118($sp)
/* 35588C E004492C 27A40018 */  addiu     $a0, $sp, 0x18
/* 355890 E0044930 3C05800A */  lui       $a1, %hi(gMasterGfxPos)
/* 355894 E0044934 24A5A66C */  addiu     $a1, $a1, %lo(gMasterGfxPos)
/* 355898 E0044938 AFBF00FC */  sw        $ra, 0xfc($sp)
/* 35589C E004493C AFBE00F8 */  sw        $fp, 0xf8($sp)
/* 3558A0 E0044940 AFB700F4 */  sw        $s7, 0xf4($sp)
/* 3558A4 E0044944 AFB600F0 */  sw        $s6, 0xf0($sp)
/* 3558A8 E0044948 AFB500EC */  sw        $s5, 0xec($sp)
/* 3558AC E004494C AFB400E8 */  sw        $s4, 0xe8($sp)
/* 3558B0 E0044950 AFB300E4 */  sw        $s3, 0xe4($sp)
/* 3558B4 E0044954 AFB200E0 */  sw        $s2, 0xe0($sp)
/* 3558B8 E0044958 AFB100DC */  sw        $s1, 0xdc($sp)
/* 3558BC E004495C AFB000D8 */  sw        $s0, 0xd8($sp)
/* 3558C0 E0044960 F7B80110 */  sdc1      $f24, 0x110($sp)
/* 3558C4 E0044964 F7B60108 */  sdc1      $f22, 0x108($sp)
/* 3558C8 E0044968 F7B40100 */  sdc1      $f20, 0x100($sp)
/* 3558CC E004496C 8CA30000 */  lw        $v1, ($a1)
/* 3558D0 E0044970 8FA90118 */  lw        $t1, 0x118($sp)
/* 3558D4 E0044974 0060302D */  daddu     $a2, $v1, $zero
/* 3558D8 E0044978 8D31000C */  lw        $s1, 0xc($t1)
/* 3558DC E004497C 24630008 */  addiu     $v1, $v1, 8
/* 3558E0 E0044980 ACA30000 */  sw        $v1, ($a1)
/* 3558E4 E0044984 86320002 */  lh        $s2, 2($s1)
/* 3558E8 E0044988 3C02E700 */  lui       $v0, 0xe700
/* 3558EC E004498C ACC20000 */  sw        $v0, ($a2)
/* 3558F0 E0044990 24620008 */  addiu     $v0, $v1, 8
/* 3558F4 E0044994 ACC00004 */  sw        $zero, 4($a2)
/* 3558F8 E0044998 ACA20000 */  sw        $v0, ($a1)
/* 3558FC E004499C AC670000 */  sw        $a3, ($v1)
/* 355900 E00449A0 8D260010 */  lw        $a2, 0x10($t1)
/* 355904 E00449A4 24620010 */  addiu     $v0, $v1, 0x10
/* 355908 E00449A8 ACA20000 */  sw        $v0, ($a1)
/* 35590C E00449AC 8CC5001C */  lw        $a1, 0x1c($a2)
/* 355910 E00449B0 3C02DE00 */  lui       $v0, 0xde00
/* 355914 E00449B4 AC620008 */  sw        $v0, 8($v1)
/* 355918 E00449B8 3C020900 */  lui       $v0, 0x900
/* 35591C E00449BC 24420F20 */  addiu     $v0, $v0, 0xf20
/* 355920 E00449C0 AC62000C */  sw        $v0, 0xc($v1)
/* 355924 E00449C4 3C028000 */  lui       $v0, 0x8000
/* 355928 E00449C8 00A22821 */  addu      $a1, $a1, $v0
/* 35592C E00449CC AC650004 */  sw        $a1, 4($v1)
/* 355930 E00449D0 8E250004 */  lw        $a1, 4($s1)
/* 355934 E00449D4 8E260008 */  lw        $a2, 8($s1)
/* 355938 E00449D8 8E220020 */  lw        $v0, 0x20($s1)
/* 35593C E00449DC 8E27000C */  lw        $a3, 0xc($s1)
/* 355940 E00449E0 2442FFFF */  addiu     $v0, $v0, -1
/* 355944 E00449E4 00021840 */  sll       $v1, $v0, 1
/* 355948 E00449E8 0C080108 */  jal       func_E0200420
/* 35594C E00449EC 0062A021 */   addu     $s4, $v1, $v0
/* 355950 E00449F0 27B00058 */  addiu     $s0, $sp, 0x58
/* 355954 E00449F4 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 355958 E00449F8 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 35595C E00449FC 44800000 */  mtc1      $zero, $f0
/* 355960 E0044A00 00031080 */  sll       $v0, $v1, 2
/* 355964 E0044A04 00431021 */  addu      $v0, $v0, $v1
/* 355968 E0044A08 00021080 */  sll       $v0, $v0, 2
/* 35596C E0044A0C 00431023 */  subu      $v0, $v0, $v1
/* 355970 E0044A10 000218C0 */  sll       $v1, $v0, 3
/* 355974 E0044A14 00431021 */  addu      $v0, $v0, $v1
/* 355978 E0044A18 000210C0 */  sll       $v0, $v0, 3
/* 35597C E0044A1C 44060000 */  mfc1      $a2, $f0
/* 355980 E0044A20 3C01800B */  lui       $at, %hi(D_800B1DEC)
/* 355984 E0044A24 00220821 */  addu      $at, $at, $v0
/* 355988 E0044A28 C4201DEC */  lwc1      $f0, %lo(D_800B1DEC)($at)
/* 35598C E0044A2C 3C073F80 */  lui       $a3, 0x3f80
/* 355990 E0044A30 46000007 */  neg.s     $f0, $f0
/* 355994 E0044A34 44050000 */  mfc1      $a1, $f0
/* 355998 E0044A38 0200202D */  daddu     $a0, $s0, $zero
/* 35599C E0044A3C 0C080104 */  jal       func_E0200410
/* 3559A0 E0044A40 AFA60010 */   sw       $a2, 0x10($sp)
/* 3559A4 E0044A44 0200202D */  daddu     $a0, $s0, $zero
/* 3559A8 E0044A48 27A50018 */  addiu     $a1, $sp, 0x18
/* 3559AC E0044A4C 0C080114 */  jal       func_E0200450
/* 3559B0 E0044A50 27A60098 */   addiu    $a2, $sp, 0x98
/* 3559B4 E0044A54 2E42001F */  sltiu     $v0, $s2, 0x1f
/* 3559B8 E0044A58 1040002E */  beqz      $v0, .LE0044B14
/* 3559BC E0044A5C 00121080 */   sll      $v0, $s2, 2
/* 3559C0 E0044A60 3C01E004 */  lui       $at, %hi(jtbl_E0044F00)
/* 3559C4 E0044A64 00220821 */  addu      $at, $at, $v0
/* 3559C8 E0044A68 8C224F00 */  lw        $v0, %lo(jtbl_E0044F00)($at)
/* 3559CC E0044A6C 00400008 */  jr        $v0
/* 3559D0 E0044A70 00000000 */   nop
glabel LE0044A74_3559D4
/* 3559D4 E0044A74 3C013F80 */  lui       $at, 0x3f80
/* 3559D8 E0044A78 4481C000 */  mtc1      $at, $f24
/* 3559DC E0044A7C 3C013F00 */  lui       $at, 0x3f00
/* 3559E0 E0044A80 4481B000 */  mtc1      $at, $f22
/* 3559E4 E0044A84 3C013DCC */  lui       $at, 0x3dcc
/* 3559E8 E0044A88 3421CCCD */  ori       $at, $at, 0xcccd
/* 3559EC E0044A8C 4481A000 */  mtc1      $at, $f20
/* 3559F0 E0044A90 080112CC */  j         .LE0044B30
/* 3559F4 E0044A94 00000000 */   nop
glabel LE0044A98_3559F8
/* 3559F8 E0044A98 3C013F80 */  lui       $at, 0x3f80
/* 3559FC E0044A9C 4481C000 */  mtc1      $at, $f24
/* 355A00 E0044AA0 3C013F4C */  lui       $at, 0x3f4c
/* 355A04 E0044AA4 3421CCCD */  ori       $at, $at, 0xcccd
/* 355A08 E0044AA8 4481B000 */  mtc1      $at, $f22
/* 355A0C E0044AAC 86220000 */  lh        $v0, ($s1)
/* 355A10 E0044AB0 3C013F33 */  lui       $at, 0x3f33
/* 355A14 E0044AB4 34213333 */  ori       $at, $at, 0x3333
/* 355A18 E0044AB8 4481A000 */  mtc1      $at, $f20
/* 355A1C E0044ABC 1040001C */  beqz      $v0, .LE0044B30
/* 355A20 E0044AC0 3C06E200 */   lui      $a2, 0xe200
/* 355A24 E0044AC4 34C6001C */  ori       $a2, $a2, 0x1c
/* 355A28 E0044AC8 3C050050 */  lui       $a1, 0x50
/* 355A2C E0044ACC 3C04800A */  lui       $a0, %hi(gMasterGfxPos)
/* 355A30 E0044AD0 2484A66C */  addiu     $a0, $a0, %lo(gMasterGfxPos)
/* 355A34 E0044AD4 8C820000 */  lw        $v0, ($a0)
/* 355A38 E0044AD8 34A54B50 */  ori       $a1, $a1, 0x4b50
/* 355A3C E0044ADC 0040182D */  daddu     $v1, $v0, $zero
/* 355A40 E0044AE0 24420008 */  addiu     $v0, $v0, 8
/* 355A44 E0044AE4 AC820000 */  sw        $v0, ($a0)
/* 355A48 E0044AE8 AC660000 */  sw        $a2, ($v1)
/* 355A4C E0044AEC 080112CC */  j         .LE0044B30
/* 355A50 E0044AF0 AC650004 */   sw       $a1, 4($v1)
glabel LE0044AF4_355A54
/* 355A54 E0044AF4 3C013FB3 */  lui       $at, 0x3fb3
/* 355A58 E0044AF8 34213333 */  ori       $at, $at, 0x3333
/* 355A5C E0044AFC 4481B000 */  mtc1      $at, $f22
/* 355A60 E0044B00 3C013F33 */  lui       $at, 0x3f33
/* 355A64 E0044B04 34213333 */  ori       $at, $at, 0x3333
/* 355A68 E0044B08 4481A000 */  mtc1      $at, $f20
/* 355A6C E0044B0C 080112CC */  j         .LE0044B30
/* 355A70 E0044B10 4600B606 */   mov.s    $f24, $f22
.LE0044B14:
glabel LE0044B14_355A74
/* 355A74 E0044B14 3C013F33 */  lui       $at, 0x3f33
/* 355A78 E0044B18 34213333 */  ori       $at, $at, 0x3333
/* 355A7C E0044B1C 4481A000 */  mtc1      $at, $f20
/* 355A80 E0044B20 3C013FB3 */  lui       $at, 0x3fb3
/* 355A84 E0044B24 34213333 */  ori       $at, $at, 0x3333
/* 355A88 E0044B28 4481C000 */  mtc1      $at, $f24
/* 355A8C E0044B2C 4600A586 */  mov.s     $f22, $f20
.LE0044B30:
/* 355A90 E0044B30 8FA90118 */  lw        $t1, 0x118($sp)
/* 355A94 E0044B34 2631002C */  addiu     $s1, $s1, 0x2c
/* 355A98 E0044B38 8D220008 */  lw        $v0, 8($t1)
/* 355A9C E0044B3C 2442FFFF */  addiu     $v0, $v0, -1
/* 355AA0 E0044B40 18400083 */  blez      $v0, .LE0044D50
/* 355AA4 E0044B44 0000902D */   daddu    $s2, $zero, $zero
/* 355AA8 E0044B48 27B60058 */  addiu     $s6, $sp, 0x58
/* 355AAC E0044B4C 3C178007 */  lui       $s7, %hi(gMatrixListPos)
/* 355AB0 E0044B50 26F741F0 */  addiu     $s7, $s7, %lo(gMatrixListPos)
/* 355AB4 E0044B54 3C150001 */  lui       $s5, 1
/* 355AB8 E0044B58 36B51630 */  ori       $s5, $s5, 0x1630
/* 355ABC E0044B5C 3C13800A */  lui       $s3, %hi(gMasterGfxPos)
/* 355AC0 E0044B60 2673A66C */  addiu     $s3, $s3, %lo(gMasterGfxPos)
/* 355AC4 E0044B64 2631001C */  addiu     $s1, $s1, 0x1c
/* 355AC8 E0044B68 3C1EE004 */  lui       $fp, %hi(D_E0044DD0)
/* 355ACC E0044B6C 27DE4DD0 */  addiu     $fp, $fp, %lo(D_E0044DD0)
/* 355AD0 E0044B70 029E8021 */  addu      $s0, $s4, $fp
.LE0044B74:
/* 355AD4 E0044B74 8E34000C */  lw        $s4, 0xc($s1)
/* 355AD8 E0044B78 0680006E */  bltz      $s4, .LE0044D34
/* 355ADC E0044B7C 00000000 */   nop
/* 355AE0 E0044B80 8E25FFE8 */  lw        $a1, -0x18($s1)
/* 355AE4 E0044B84 8E26FFEC */  lw        $a2, -0x14($s1)
/* 355AE8 E0044B88 8E27FFF0 */  lw        $a3, -0x10($s1)
/* 355AEC E0044B8C 0C080108 */  jal       func_E0200420
/* 355AF0 E0044B90 02C0202D */   daddu    $a0, $s6, $zero
/* 355AF4 E0044B94 02C0202D */  daddu     $a0, $s6, $zero
/* 355AF8 E0044B98 27A50098 */  addiu     $a1, $sp, 0x98
/* 355AFC E0044B9C C6200000 */  lwc1      $f0, ($s1)
/* 355B00 E0044BA0 27A60018 */  addiu     $a2, $sp, 0x18
/* 355B04 E0044BA4 E7A00080 */  swc1      $f0, 0x80($sp)
/* 355B08 E0044BA8 E7A0006C */  swc1      $f0, 0x6c($sp)
/* 355B0C E0044BAC 0C080114 */  jal       func_E0200450
/* 355B10 E0044BB0 E7A00058 */   swc1     $f0, 0x58($sp)
/* 355B14 E0044BB4 27A40018 */  addiu     $a0, $sp, 0x18
/* 355B18 E0044BB8 96E50000 */  lhu       $a1, ($s7)
/* 355B1C E0044BBC 3C02800A */  lui       $v0, %hi(gDisplayContext)
/* 355B20 E0044BC0 8C42A674 */  lw        $v0, %lo(gDisplayContext)($v0)
/* 355B24 E0044BC4 00052980 */  sll       $a1, $a1, 6
/* 355B28 E0044BC8 00B52821 */  addu      $a1, $a1, $s5
/* 355B2C E0044BCC 0C080118 */  jal       func_E0200460
/* 355B30 E0044BD0 00452821 */   addu     $a1, $v0, $a1
/* 355B34 E0044BD4 27C20024 */  addiu     $v0, $fp, 0x24
/* 355B38 E0044BD8 0202102A */  slt       $v0, $s0, $v0
/* 355B3C E0044BDC 50400001 */  beql      $v0, $zero, .LE0044BE4
/* 355B40 E0044BE0 03C0802D */   daddu    $s0, $fp, $zero
.LE0044BE4:
/* 355B44 E0044BE4 92020000 */  lbu       $v0, ($s0)
/* 355B48 E0044BE8 44822000 */  mtc1      $v0, $f4
/* 355B4C E0044BEC 00000000 */  nop
/* 355B50 E0044BF0 46802120 */  cvt.s.w   $f4, $f4
/* 355B54 E0044BF4 46182102 */  mul.s     $f4, $f4, $f24
/* 355B58 E0044BF8 00000000 */  nop
/* 355B5C E0044BFC 26100001 */  addiu     $s0, $s0, 1
/* 355B60 E0044C00 92020000 */  lbu       $v0, ($s0)
/* 355B64 E0044C04 44821000 */  mtc1      $v0, $f2
/* 355B68 E0044C08 00000000 */  nop
/* 355B6C E0044C0C 468010A0 */  cvt.s.w   $f2, $f2
/* 355B70 E0044C10 46161082 */  mul.s     $f2, $f2, $f22
/* 355B74 E0044C14 00000000 */  nop
/* 355B78 E0044C18 26100001 */  addiu     $s0, $s0, 1
/* 355B7C E0044C1C 92020000 */  lbu       $v0, ($s0)
/* 355B80 E0044C20 44820000 */  mtc1      $v0, $f0
/* 355B84 E0044C24 00000000 */  nop
/* 355B88 E0044C28 46800020 */  cvt.s.w   $f0, $f0
/* 355B8C E0044C2C 46140002 */  mul.s     $f0, $f0, $f20
/* 355B90 E0044C30 00000000 */  nop
/* 355B94 E0044C34 4600218D */  trunc.w.s $f6, $f4
/* 355B98 E0044C38 44033000 */  mfc1      $v1, $f6
/* 355B9C E0044C3C 00000000 */  nop
/* 355BA0 E0044C40 28620100 */  slti      $v0, $v1, 0x100
/* 355BA4 E0044C44 4600118D */  trunc.w.s $f6, $f2
/* 355BA8 E0044C48 44073000 */  mfc1      $a3, $f6
/* 355BAC E0044C4C 4600018D */  trunc.w.s $f6, $f0
/* 355BB0 E0044C50 44083000 */  mfc1      $t0, $f6
/* 355BB4 E0044C54 14400002 */  bnez      $v0, .LE0044C60
/* 355BB8 E0044C58 26100001 */   addiu    $s0, $s0, 1
/* 355BBC E0044C5C 240300FF */  addiu     $v1, $zero, 0xff
.LE0044C60:
/* 355BC0 E0044C60 28E20100 */  slti      $v0, $a3, 0x100
/* 355BC4 E0044C64 50400001 */  beql      $v0, $zero, .LE0044C6C
/* 355BC8 E0044C68 240700FF */   addiu    $a3, $zero, 0xff
.LE0044C6C:
/* 355BCC E0044C6C 29020100 */  slti      $v0, $t0, 0x100
/* 355BD0 E0044C70 50400001 */  beql      $v0, $zero, .LE0044C78
/* 355BD4 E0044C74 240800FF */   addiu    $t0, $zero, 0xff
.LE0044C78:
/* 355BD8 E0044C78 3C06D838 */  lui       $a2, 0xd838
/* 355BDC E0044C7C 34C60002 */  ori       $a2, $a2, 2
/* 355BE0 E0044C80 3C02FA00 */  lui       $v0, 0xfa00
/* 355BE4 E0044C84 00031E00 */  sll       $v1, $v1, 0x18
/* 355BE8 E0044C88 8E640000 */  lw        $a0, ($s3)
/* 355BEC E0044C8C 3C09E004 */  lui       $t1, %hi(D_E0044DB0)
/* 355BF0 E0044C90 25294DB0 */  addiu     $t1, $t1, %lo(D_E0044DB0)
/* 355BF4 E0044C94 0080282D */  daddu     $a1, $a0, $zero
/* 355BF8 E0044C98 24840008 */  addiu     $a0, $a0, 8
/* 355BFC E0044C9C AE640000 */  sw        $a0, ($s3)
/* 355C00 E0044CA0 ACA20000 */  sw        $v0, ($a1)
/* 355C04 E0044CA4 30E200FF */  andi      $v0, $a3, 0xff
/* 355C08 E0044CA8 00021400 */  sll       $v0, $v0, 0x10
/* 355C0C E0044CAC 00621825 */  or        $v1, $v1, $v0
/* 355C10 E0044CB0 310200FF */  andi      $v0, $t0, 0xff
/* 355C14 E0044CB4 00021200 */  sll       $v0, $v0, 8
/* 355C18 E0044CB8 00621825 */  or        $v1, $v1, $v0
/* 355C1C E0044CBC 346300FF */  ori       $v1, $v1, 0xff
/* 355C20 E0044CC0 24820008 */  addiu     $v0, $a0, 8
/* 355C24 E0044CC4 ACA30004 */  sw        $v1, 4($a1)
/* 355C28 E0044CC8 AE620000 */  sw        $v0, ($s3)
/* 355C2C E0044CCC 96E20000 */  lhu       $v0, ($s7)
/* 355C30 E0044CD0 3C03DA38 */  lui       $v1, 0xda38
/* 355C34 E0044CD4 AC830000 */  sw        $v1, ($a0)
/* 355C38 E0044CD8 24430001 */  addiu     $v1, $v0, 1
/* 355C3C E0044CDC 3042FFFF */  andi      $v0, $v0, 0xffff
/* 355C40 E0044CE0 00021180 */  sll       $v0, $v0, 6
/* 355C44 E0044CE4 A6E30000 */  sh        $v1, ($s7)
/* 355C48 E0044CE8 3C03800A */  lui       $v1, %hi(gDisplayContext)
/* 355C4C E0044CEC 8C63A674 */  lw        $v1, %lo(gDisplayContext)($v1)
/* 355C50 E0044CF0 00551021 */  addu      $v0, $v0, $s5
/* 355C54 E0044CF4 00621821 */  addu      $v1, $v1, $v0
/* 355C58 E0044CF8 24820010 */  addiu     $v0, $a0, 0x10
/* 355C5C E0044CFC AC830004 */  sw        $v1, 4($a0)
/* 355C60 E0044D00 AE620000 */  sw        $v0, ($s3)
/* 355C64 E0044D04 3C02DE00 */  lui       $v0, 0xde00
/* 355C68 E0044D08 AC820008 */  sw        $v0, 8($a0)
/* 355C6C E0044D0C 32820007 */  andi      $v0, $s4, 7
/* 355C70 E0044D10 00021080 */  sll       $v0, $v0, 2
/* 355C74 E0044D14 00491021 */  addu      $v0, $v0, $t1
/* 355C78 E0044D18 8C430000 */  lw        $v1, ($v0)
/* 355C7C E0044D1C 24820018 */  addiu     $v0, $a0, 0x18
/* 355C80 E0044D20 AE620000 */  sw        $v0, ($s3)
/* 355C84 E0044D24 24020040 */  addiu     $v0, $zero, 0x40
/* 355C88 E0044D28 AC860010 */  sw        $a2, 0x10($a0)
/* 355C8C E0044D2C AC820014 */  sw        $v0, 0x14($a0)
/* 355C90 E0044D30 AC83000C */  sw        $v1, 0xc($a0)
.LE0044D34:
/* 355C94 E0044D34 8FA90118 */  lw        $t1, 0x118($sp)
/* 355C98 E0044D38 26520001 */  addiu     $s2, $s2, 1
/* 355C9C E0044D3C 8D220008 */  lw        $v0, 8($t1)
/* 355CA0 E0044D40 2442FFFF */  addiu     $v0, $v0, -1
/* 355CA4 E0044D44 0242102A */  slt       $v0, $s2, $v0
/* 355CA8 E0044D48 1440FF8A */  bnez      $v0, .LE0044B74
/* 355CAC E0044D4C 2631002C */   addiu    $s1, $s1, 0x2c
.LE0044D50:
/* 355CB0 E0044D50 3C03800A */  lui       $v1, %hi(gMasterGfxPos)
/* 355CB4 E0044D54 2463A66C */  addiu     $v1, $v1, %lo(gMasterGfxPos)
/* 355CB8 E0044D58 8C620000 */  lw        $v0, ($v1)
/* 355CBC E0044D5C 0040202D */  daddu     $a0, $v0, $zero
/* 355CC0 E0044D60 24420008 */  addiu     $v0, $v0, 8
/* 355CC4 E0044D64 AC620000 */  sw        $v0, ($v1)
/* 355CC8 E0044D68 3C02E700 */  lui       $v0, 0xe700
/* 355CCC E0044D6C AC820000 */  sw        $v0, ($a0)
/* 355CD0 E0044D70 AC800004 */  sw        $zero, 4($a0)
/* 355CD4 E0044D74 8FBF00FC */  lw        $ra, 0xfc($sp)
/* 355CD8 E0044D78 8FBE00F8 */  lw        $fp, 0xf8($sp)
/* 355CDC E0044D7C 8FB700F4 */  lw        $s7, 0xf4($sp)
/* 355CE0 E0044D80 8FB600F0 */  lw        $s6, 0xf0($sp)
/* 355CE4 E0044D84 8FB500EC */  lw        $s5, 0xec($sp)
/* 355CE8 E0044D88 8FB400E8 */  lw        $s4, 0xe8($sp)
/* 355CEC E0044D8C 8FB300E4 */  lw        $s3, 0xe4($sp)
/* 355CF0 E0044D90 8FB200E0 */  lw        $s2, 0xe0($sp)
/* 355CF4 E0044D94 8FB100DC */  lw        $s1, 0xdc($sp)
/* 355CF8 E0044D98 8FB000D8 */  lw        $s0, 0xd8($sp)
/* 355CFC E0044D9C D7B80110 */  ldc1      $f24, 0x110($sp)
/* 355D00 E0044DA0 D7B60108 */  ldc1      $f22, 0x108($sp)
/* 355D04 E0044DA4 D7B40100 */  ldc1      $f20, 0x100($sp)
/* 355D08 E0044DA8 03E00008 */  jr        $ra
/* 355D0C E0044DAC 27BD0118 */   addiu    $sp, $sp, 0x118
