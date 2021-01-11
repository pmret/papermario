.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E007685C
/* 3778CC E007685C 27BDFF00 */  addiu     $sp, $sp, -0x100
/* 3778D0 E0076860 3C02DB06 */  lui       $v0, 0xdb06
/* 3778D4 E0076864 34420024 */  ori       $v0, $v0, 0x24
/* 3778D8 E0076868 3C09800A */  lui       $t1, %hi(gMasterGfxPos)
/* 3778DC E007686C 2529A66C */  addiu     $t1, $t1, %lo(gMasterGfxPos)
/* 3778E0 E0076870 AFBF00F4 */  sw        $ra, 0xf4($sp)
/* 3778E4 E0076874 AFB600F0 */  sw        $s6, 0xf0($sp)
/* 3778E8 E0076878 AFB500EC */  sw        $s5, 0xec($sp)
/* 3778EC E007687C AFB400E8 */  sw        $s4, 0xe8($sp)
/* 3778F0 E0076880 AFB300E4 */  sw        $s3, 0xe4($sp)
/* 3778F4 E0076884 AFB200E0 */  sw        $s2, 0xe0($sp)
/* 3778F8 E0076888 AFB100DC */  sw        $s1, 0xdc($sp)
/* 3778FC E007688C AFB000D8 */  sw        $s0, 0xd8($sp)
/* 377900 E0076890 F7B400F8 */  sdc1      $f20, 0xf8($sp)
/* 377904 E0076894 8C93000C */  lw        $s3, 0xc($a0)
/* 377908 E0076898 8D280000 */  lw        $t0, ($t1)
/* 37790C E007689C 8E750000 */  lw        $s5, ($s3)
/* 377910 E00768A0 8E760028 */  lw        $s6, 0x28($s3)
/* 377914 E00768A4 0100282D */  daddu     $a1, $t0, $zero
/* 377918 E00768A8 ACA20000 */  sw        $v0, ($a1)
/* 37791C E00768AC 8C820010 */  lw        $v0, 0x10($a0)
/* 377920 E00768B0 3C038000 */  lui       $v1, 0x8000
/* 377924 E00768B4 8C42001C */  lw        $v0, 0x1c($v0)
/* 377928 E00768B8 25080008 */  addiu     $t0, $t0, 8
/* 37792C E00768BC 00431021 */  addu      $v0, $v0, $v1
/* 377930 E00768C0 ACA20004 */  sw        $v0, 4($a1)
/* 377934 E00768C4 3C02DE00 */  lui       $v0, 0xde00
/* 377938 E00768C8 AD020000 */  sw        $v0, ($t0)
/* 37793C E00768CC 00151080 */  sll       $v0, $s5, 2
/* 377940 E00768D0 3C01E007 */  lui       $at, %hi(D_E0076ED0)
/* 377944 E00768D4 00220821 */  addu      $at, $at, $v0
/* 377948 E00768D8 8C226ED0 */  lw        $v0, %lo(D_E0076ED0)($at)
/* 37794C E00768DC 27A40018 */  addiu     $a0, $sp, 0x18
/* 377950 E00768E0 AD280000 */  sw        $t0, ($t1)
/* 377954 E00768E4 AD020004 */  sw        $v0, 4($t0)
/* 377958 E00768E8 8E650010 */  lw        $a1, 0x10($s3)
/* 37795C E00768EC 8E660014 */  lw        $a2, 0x14($s3)
/* 377960 E00768F0 8E670018 */  lw        $a3, 0x18($s3)
/* 377964 E00768F4 25080008 */  addiu     $t0, $t0, 8
/* 377968 E00768F8 0C080108 */  jal       func_E0200420
/* 37796C E00768FC AD280000 */   sw       $t0, ($t1)
/* 377970 E0076900 24020002 */  addiu     $v0, $zero, 2
/* 377974 E0076904 16A20008 */  bne       $s5, $v0, .LE0076928
/* 377978 E0076908 27A40058 */   addiu    $a0, $sp, 0x58
/* 37797C E007690C 44800000 */  mtc1      $zero, $f0
/* 377980 E0076910 3C073F80 */  lui       $a3, 0x3f80
/* 377984 E0076914 E7A00010 */  swc1      $f0, 0x10($sp)
/* 377988 E0076918 8E650064 */  lw        $a1, 0x64($s3)
/* 37798C E007691C 44060000 */  mfc1      $a2, $f0
/* 377990 E0076920 0801DA5C */  j         .LE0076970
/* 377994 E0076924 00000000 */   nop
.LE0076928:
/* 377998 E0076928 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 37799C E007692C 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 3779A0 E0076930 44800000 */  mtc1      $zero, $f0
/* 3779A4 E0076934 00031080 */  sll       $v0, $v1, 2
/* 3779A8 E0076938 00431021 */  addu      $v0, $v0, $v1
/* 3779AC E007693C 00021080 */  sll       $v0, $v0, 2
/* 3779B0 E0076940 00431023 */  subu      $v0, $v0, $v1
/* 3779B4 E0076944 000218C0 */  sll       $v1, $v0, 3
/* 3779B8 E0076948 00431021 */  addu      $v0, $v0, $v1
/* 3779BC E007694C 000210C0 */  sll       $v0, $v0, 3
/* 3779C0 E0076950 44060000 */  mfc1      $a2, $f0
/* 3779C4 E0076954 3C01800B */  lui       $at, %hi(D_800B1DEC)
/* 3779C8 E0076958 00220821 */  addu      $at, $at, $v0
/* 3779CC E007695C C4201DEC */  lwc1      $f0, %lo(D_800B1DEC)($at)
/* 3779D0 E0076960 3C073F80 */  lui       $a3, 0x3f80
/* 3779D4 E0076964 46000007 */  neg.s     $f0, $f0
/* 3779D8 E0076968 44050000 */  mfc1      $a1, $f0
/* 3779DC E007696C AFA60010 */  sw        $a2, 0x10($sp)
.LE0076970:
/* 3779E0 E0076970 0C080104 */  jal       func_E0200410
/* 3779E4 E0076974 00000000 */   nop
/* 3779E8 E0076978 27B40058 */  addiu     $s4, $sp, 0x58
/* 3779EC E007697C 0280202D */  daddu     $a0, $s4, $zero
/* 3779F0 E0076980 27A50018 */  addiu     $a1, $sp, 0x18
/* 3779F4 E0076984 27B00098 */  addiu     $s0, $sp, 0x98
/* 3779F8 E0076988 0C080114 */  jal       func_E0200450
/* 3779FC E007698C 0200302D */   daddu    $a2, $s0, $zero
/* 377A00 E0076990 8E65001C */  lw        $a1, 0x1c($s3)
/* 377A04 E0076994 3C013F80 */  lui       $at, 0x3f80
/* 377A08 E0076998 4481A000 */  mtc1      $at, $f20
/* 377A0C E007699C 8E660020 */  lw        $a2, 0x20($s3)
/* 377A10 E00769A0 4407A000 */  mfc1      $a3, $f20
/* 377A14 E00769A4 0C080110 */  jal       func_E0200440
/* 377A18 E00769A8 0280202D */   daddu    $a0, $s4, $zero
/* 377A1C E00769AC 0280202D */  daddu     $a0, $s4, $zero
/* 377A20 E00769B0 0200282D */  daddu     $a1, $s0, $zero
/* 377A24 E00769B4 0C080114 */  jal       func_E0200450
/* 377A28 E00769B8 0200302D */   daddu    $a2, $s0, $zero
/* 377A2C E00769BC 16A00016 */  bnez      $s5, .LE0076A18
/* 377A30 E00769C0 3C120001 */   lui      $s2, 1
/* 377A34 E00769C4 C660001C */  lwc1      $f0, 0x1c($s3)
/* 377A38 E00769C8 C6640024 */  lwc1      $f4, 0x24($s3)
/* 377A3C E00769CC 46040001 */  sub.s     $f0, $f0, $f4
/* 377A40 E00769D0 3C014120 */  lui       $at, 0x4120
/* 377A44 E00769D4 44811000 */  mtc1      $at, $f2
/* 377A48 E00769D8 46000007 */  neg.s     $f0, $f0
/* 377A4C E00769DC 46040003 */  div.s     $f0, $f0, $f4
/* 377A50 E00769E0 46020002 */  mul.s     $f0, $f0, $f2
/* 377A54 E00769E4 00000000 */  nop
/* 377A58 E00769E8 44050000 */  mfc1      $a1, $f0
/* 377A5C E00769EC 44800000 */  mtc1      $zero, $f0
/* 377A60 E00769F0 00000000 */  nop
/* 377A64 E00769F4 44060000 */  mfc1      $a2, $f0
/* 377A68 E00769F8 0280202D */  daddu     $a0, $s4, $zero
/* 377A6C E00769FC 0C080108 */  jal       func_E0200420
/* 377A70 E0076A00 00C0382D */   daddu    $a3, $a2, $zero
/* 377A74 E0076A04 0280202D */  daddu     $a0, $s4, $zero
/* 377A78 E0076A08 0200282D */  daddu     $a1, $s0, $zero
/* 377A7C E0076A0C 0C080114 */  jal       func_E0200450
/* 377A80 E0076A10 0200302D */   daddu    $a2, $s0, $zero
/* 377A84 E0076A14 3C120001 */  lui       $s2, 1
.LE0076A18:
/* 377A88 E0076A18 36521630 */  ori       $s2, $s2, 0x1630
/* 377A8C E0076A1C 0200202D */  daddu     $a0, $s0, $zero
/* 377A90 E0076A20 3C108007 */  lui       $s0, %hi(gMatrixListPos)
/* 377A94 E0076A24 261041F0 */  addiu     $s0, $s0, %lo(gMatrixListPos)
/* 377A98 E0076A28 3C11800A */  lui       $s1, %hi(gDisplayContext)
/* 377A9C E0076A2C 2631A674 */  addiu     $s1, $s1, %lo(gDisplayContext)
/* 377AA0 E0076A30 96050000 */  lhu       $a1, ($s0)
/* 377AA4 E0076A34 8E220000 */  lw        $v0, ($s1)
/* 377AA8 E0076A38 00052980 */  sll       $a1, $a1, 6
/* 377AAC E0076A3C 00B22821 */  addu      $a1, $a1, $s2
/* 377AB0 E0076A40 0C080118 */  jal       func_E0200460
/* 377AB4 E0076A44 00452821 */   addu     $a1, $v0, $a1
/* 377AB8 E0076A48 3C03DA38 */  lui       $v1, 0xda38
/* 377ABC E0076A4C 34630002 */  ori       $v1, $v1, 2
/* 377AC0 E0076A50 3C06D838 */  lui       $a2, 0xd838
/* 377AC4 E0076A54 34C60002 */  ori       $a2, $a2, 2
/* 377AC8 E0076A58 3C09800A */  lui       $t1, %hi(gMasterGfxPos)
/* 377ACC E0076A5C 2529A66C */  addiu     $t1, $t1, %lo(gMasterGfxPos)
/* 377AD0 E0076A60 27A40018 */  addiu     $a0, $sp, 0x18
/* 377AD4 E0076A64 8D280000 */  lw        $t0, ($t1)
/* 377AD8 E0076A68 96020000 */  lhu       $v0, ($s0)
/* 377ADC E0076A6C 0100282D */  daddu     $a1, $t0, $zero
/* 377AE0 E0076A70 25080008 */  addiu     $t0, $t0, 8
/* 377AE4 E0076A74 AD280000 */  sw        $t0, ($t1)
/* 377AE8 E0076A78 ACA30000 */  sw        $v1, ($a1)
/* 377AEC E0076A7C 24430001 */  addiu     $v1, $v0, 1
/* 377AF0 E0076A80 3042FFFF */  andi      $v0, $v0, 0xffff
/* 377AF4 E0076A84 00021180 */  sll       $v0, $v0, 6
/* 377AF8 E0076A88 A6030000 */  sh        $v1, ($s0)
/* 377AFC E0076A8C 8E230000 */  lw        $v1, ($s1)
/* 377B00 E0076A90 00521021 */  addu      $v0, $v0, $s2
/* 377B04 E0076A94 00621821 */  addu      $v1, $v1, $v0
/* 377B08 E0076A98 3C02DE00 */  lui       $v0, 0xde00
/* 377B0C E0076A9C ACA30004 */  sw        $v1, 4($a1)
/* 377B10 E0076AA0 AD020000 */  sw        $v0, ($t0)
/* 377B14 E0076AA4 00151080 */  sll       $v0, $s5, 2
/* 377B18 E0076AA8 3C03E007 */  lui       $v1, %hi(D_E0076EC0)
/* 377B1C E0076AAC 00621821 */  addu      $v1, $v1, $v0
/* 377B20 E0076AB0 8C636EC0 */  lw        $v1, %lo(D_E0076EC0)($v1)
/* 377B24 E0076AB4 25020008 */  addiu     $v0, $t0, 8
/* 377B28 E0076AB8 AD220000 */  sw        $v0, ($t1)
/* 377B2C E0076ABC 24020040 */  addiu     $v0, $zero, 0x40
/* 377B30 E0076AC0 AD060008 */  sw        $a2, 8($t0)
/* 377B34 E0076AC4 AD02000C */  sw        $v0, 0xc($t0)
/* 377B38 E0076AC8 AD030004 */  sw        $v1, 4($t0)
/* 377B3C E0076ACC 8E650004 */  lw        $a1, 4($s3)
/* 377B40 E0076AD0 8E660008 */  lw        $a2, 8($s3)
/* 377B44 E0076AD4 8E67000C */  lw        $a3, 0xc($s3)
/* 377B48 E0076AD8 25080010 */  addiu     $t0, $t0, 0x10
/* 377B4C E0076ADC 0C080108 */  jal       func_E0200420
/* 377B50 E0076AE0 AD280000 */   sw       $t0, ($t1)
/* 377B54 E0076AE4 24020002 */  addiu     $v0, $zero, 2
/* 377B58 E0076AE8 16A20008 */  bne       $s5, $v0, .LE0076B0C
/* 377B5C E0076AEC 0280202D */   daddu    $a0, $s4, $zero
/* 377B60 E0076AF0 44800000 */  mtc1      $zero, $f0
/* 377B64 E0076AF4 4407A000 */  mfc1      $a3, $f20
/* 377B68 E0076AF8 E7A00010 */  swc1      $f0, 0x10($sp)
/* 377B6C E0076AFC 8E650064 */  lw        $a1, 0x64($s3)
/* 377B70 E0076B00 44060000 */  mfc1      $a2, $f0
/* 377B74 E0076B04 0801DAD5 */  j         .LE0076B54
/* 377B78 E0076B08 00000000 */   nop
.LE0076B0C:
/* 377B7C E0076B0C 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 377B80 E0076B10 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 377B84 E0076B14 44800000 */  mtc1      $zero, $f0
/* 377B88 E0076B18 00031080 */  sll       $v0, $v1, 2
/* 377B8C E0076B1C 00431021 */  addu      $v0, $v0, $v1
/* 377B90 E0076B20 00021080 */  sll       $v0, $v0, 2
/* 377B94 E0076B24 00431023 */  subu      $v0, $v0, $v1
/* 377B98 E0076B28 000218C0 */  sll       $v1, $v0, 3
/* 377B9C E0076B2C 00431021 */  addu      $v0, $v0, $v1
/* 377BA0 E0076B30 000210C0 */  sll       $v0, $v0, 3
/* 377BA4 E0076B34 44060000 */  mfc1      $a2, $f0
/* 377BA8 E0076B38 3C01800B */  lui       $at, %hi(D_800B1DEC)
/* 377BAC E0076B3C 00220821 */  addu      $at, $at, $v0
/* 377BB0 E0076B40 C4201DEC */  lwc1      $f0, %lo(D_800B1DEC)($at)
/* 377BB4 E0076B44 4407A000 */  mfc1      $a3, $f20
/* 377BB8 E0076B48 46000007 */  neg.s     $f0, $f0
/* 377BBC E0076B4C 44050000 */  mfc1      $a1, $f0
/* 377BC0 E0076B50 AFA60010 */  sw        $a2, 0x10($sp)
.LE0076B54:
/* 377BC4 E0076B54 0C080104 */  jal       func_E0200410
/* 377BC8 E0076B58 00000000 */   nop
/* 377BCC E0076B5C 27B10058 */  addiu     $s1, $sp, 0x58
/* 377BD0 E0076B60 0220202D */  daddu     $a0, $s1, $zero
/* 377BD4 E0076B64 27A50018 */  addiu     $a1, $sp, 0x18
/* 377BD8 E0076B68 27B00098 */  addiu     $s0, $sp, 0x98
/* 377BDC E0076B6C 0C080114 */  jal       func_E0200450
/* 377BE0 E0076B70 0200302D */   daddu    $a2, $s0, $zero
/* 377BE4 E0076B74 8E65001C */  lw        $a1, 0x1c($s3)
/* 377BE8 E0076B78 8E660020 */  lw        $a2, 0x20($s3)
/* 377BEC E0076B7C 3C073F80 */  lui       $a3, 0x3f80
/* 377BF0 E0076B80 0C080110 */  jal       func_E0200440
/* 377BF4 E0076B84 0220202D */   daddu    $a0, $s1, $zero
/* 377BF8 E0076B88 0220202D */  daddu     $a0, $s1, $zero
/* 377BFC E0076B8C 0200282D */  daddu     $a1, $s0, $zero
/* 377C00 E0076B90 0C080114 */  jal       func_E0200450
/* 377C04 E0076B94 0200302D */   daddu    $a2, $s0, $zero
/* 377C08 E0076B98 16A00016 */  bnez      $s5, .LE0076BF4
/* 377C0C E0076B9C 3C120001 */   lui      $s2, 1
/* 377C10 E0076BA0 C660001C */  lwc1      $f0, 0x1c($s3)
/* 377C14 E0076BA4 C6640024 */  lwc1      $f4, 0x24($s3)
/* 377C18 E0076BA8 46040001 */  sub.s     $f0, $f0, $f4
/* 377C1C E0076BAC 3C014120 */  lui       $at, 0x4120
/* 377C20 E0076BB0 44811000 */  mtc1      $at, $f2
/* 377C24 E0076BB4 46000007 */  neg.s     $f0, $f0
/* 377C28 E0076BB8 46040003 */  div.s     $f0, $f0, $f4
/* 377C2C E0076BBC 46020002 */  mul.s     $f0, $f0, $f2
/* 377C30 E0076BC0 00000000 */  nop
/* 377C34 E0076BC4 44050000 */  mfc1      $a1, $f0
/* 377C38 E0076BC8 44800000 */  mtc1      $zero, $f0
/* 377C3C E0076BCC 00000000 */  nop
/* 377C40 E0076BD0 44060000 */  mfc1      $a2, $f0
/* 377C44 E0076BD4 0220202D */  daddu     $a0, $s1, $zero
/* 377C48 E0076BD8 0C080108 */  jal       func_E0200420
/* 377C4C E0076BDC 00C0382D */   daddu    $a3, $a2, $zero
/* 377C50 E0076BE0 0220202D */  daddu     $a0, $s1, $zero
/* 377C54 E0076BE4 0200282D */  daddu     $a1, $s0, $zero
/* 377C58 E0076BE8 0C080114 */  jal       func_E0200450
/* 377C5C E0076BEC 0200302D */   daddu    $a2, $s0, $zero
/* 377C60 E0076BF0 3C120001 */  lui       $s2, 1
.LE0076BF4:
/* 377C64 E0076BF4 36521630 */  ori       $s2, $s2, 0x1630
/* 377C68 E0076BF8 0200202D */  daddu     $a0, $s0, $zero
/* 377C6C E0076BFC 3C108007 */  lui       $s0, %hi(gMatrixListPos)
/* 377C70 E0076C00 261041F0 */  addiu     $s0, $s0, %lo(gMatrixListPos)
/* 377C74 E0076C04 3C11800A */  lui       $s1, %hi(gDisplayContext)
/* 377C78 E0076C08 2631A674 */  addiu     $s1, $s1, %lo(gDisplayContext)
/* 377C7C E0076C0C 96050000 */  lhu       $a1, ($s0)
/* 377C80 E0076C10 8E220000 */  lw        $v0, ($s1)
/* 377C84 E0076C14 00052980 */  sll       $a1, $a1, 6
/* 377C88 E0076C18 00B22821 */  addu      $a1, $a1, $s2
/* 377C8C E0076C1C 0C080118 */  jal       func_E0200460
/* 377C90 E0076C20 00452821 */   addu     $a1, $v0, $a1
/* 377C94 E0076C24 3C03DA38 */  lui       $v1, 0xda38
/* 377C98 E0076C28 34630002 */  ori       $v1, $v1, 2
/* 377C9C E0076C2C 3C06D838 */  lui       $a2, 0xd838
/* 377CA0 E0076C30 3C07800A */  lui       $a3, %hi(gMasterGfxPos)
/* 377CA4 E0076C34 24E7A66C */  addiu     $a3, $a3, %lo(gMasterGfxPos)
/* 377CA8 E0076C38 34C60002 */  ori       $a2, $a2, 2
/* 377CAC E0076C3C 3C08DE00 */  lui       $t0, 0xde00
/* 377CB0 E0076C40 00154880 */  sll       $t1, $s5, 2
/* 377CB4 E0076C44 8CE50000 */  lw        $a1, ($a3)
/* 377CB8 E0076C48 96020000 */  lhu       $v0, ($s0)
/* 377CBC E0076C4C 3C014080 */  lui       $at, 0x4080
/* 377CC0 E0076C50 44812000 */  mtc1      $at, $f4
/* 377CC4 E0076C54 00A0202D */  daddu     $a0, $a1, $zero
/* 377CC8 E0076C58 24A50008 */  addiu     $a1, $a1, 8
/* 377CCC E0076C5C ACE50000 */  sw        $a1, ($a3)
/* 377CD0 E0076C60 AC830000 */  sw        $v1, ($a0)
/* 377CD4 E0076C64 24430001 */  addiu     $v1, $v0, 1
/* 377CD8 E0076C68 3042FFFF */  andi      $v0, $v0, 0xffff
/* 377CDC E0076C6C 00021180 */  sll       $v0, $v0, 6
/* 377CE0 E0076C70 A6030000 */  sh        $v1, ($s0)
/* 377CE4 E0076C74 8E230000 */  lw        $v1, ($s1)
/* 377CE8 E0076C78 00521021 */  addu      $v0, $v0, $s2
/* 377CEC E0076C7C 00621821 */  addu      $v1, $v1, $v0
/* 377CF0 E0076C80 24A20008 */  addiu     $v0, $a1, 8
/* 377CF4 E0076C84 AC830004 */  sw        $v1, 4($a0)
/* 377CF8 E0076C88 ACE20000 */  sw        $v0, ($a3)
/* 377CFC E0076C8C ACA80000 */  sw        $t0, ($a1)
/* 377D00 E0076C90 3C03E007 */  lui       $v1, %hi(D_E0076EB0)
/* 377D04 E0076C94 00691821 */  addu      $v1, $v1, $t1
/* 377D08 E0076C98 8C636EB0 */  lw        $v1, %lo(D_E0076EB0)($v1)
/* 377D0C E0076C9C 24A20010 */  addiu     $v0, $a1, 0x10
/* 377D10 E0076CA0 ACE20000 */  sw        $v0, ($a3)
/* 377D14 E0076CA4 24020040 */  addiu     $v0, $zero, 0x40
/* 377D18 E0076CA8 ACA2000C */  sw        $v0, 0xc($a1)
/* 377D1C E0076CAC 24A20018 */  addiu     $v0, $a1, 0x18
/* 377D20 E0076CB0 ACA60008 */  sw        $a2, 8($a1)
/* 377D24 E0076CB4 ACE20000 */  sw        $v0, ($a3)
/* 377D28 E0076CB8 3C02FA00 */  lui       $v0, 0xfa00
/* 377D2C E0076CBC ACA20010 */  sw        $v0, 0x10($a1)
/* 377D30 E0076CC0 ACA30004 */  sw        $v1, 4($a1)
/* 377D34 E0076CC4 92620068 */  lbu       $v0, 0x68($s3)
/* 377D38 E0076CC8 92640069 */  lbu       $a0, 0x69($s3)
/* 377D3C E0076CCC 9266006A */  lbu       $a2, 0x6a($s3)
/* 377D40 E0076CD0 24A30020 */  addiu     $v1, $a1, 0x20
/* 377D44 E0076CD4 ACE30000 */  sw        $v1, ($a3)
/* 377D48 E0076CD8 3C03FB00 */  lui       $v1, 0xfb00
/* 377D4C E0076CDC ACA30018 */  sw        $v1, 0x18($a1)
/* 377D50 E0076CE0 32C300FF */  andi      $v1, $s6, 0xff
/* 377D54 E0076CE4 00021600 */  sll       $v0, $v0, 0x18
/* 377D58 E0076CE8 00042400 */  sll       $a0, $a0, 0x10
/* 377D5C E0076CEC 00441025 */  or        $v0, $v0, $a0
/* 377D60 E0076CF0 00063200 */  sll       $a2, $a2, 8
/* 377D64 E0076CF4 00461025 */  or        $v0, $v0, $a2
/* 377D68 E0076CF8 00431025 */  or        $v0, $v0, $v1
/* 377D6C E0076CFC ACA20014 */  sw        $v0, 0x14($a1)
/* 377D70 E0076D00 9262006B */  lbu       $v0, 0x6b($s3)
/* 377D74 E0076D04 9263006C */  lbu       $v1, 0x6c($s3)
/* 377D78 E0076D08 9264006D */  lbu       $a0, 0x6d($s3)
/* 377D7C E0076D0C 00021600 */  sll       $v0, $v0, 0x18
/* 377D80 E0076D10 00031C00 */  sll       $v1, $v1, 0x10
/* 377D84 E0076D14 00431025 */  or        $v0, $v0, $v1
/* 377D88 E0076D18 00042200 */  sll       $a0, $a0, 8
/* 377D8C E0076D1C 9263006E */  lbu       $v1, 0x6e($s3)
/* 377D90 E0076D20 00441025 */  or        $v0, $v0, $a0
/* 377D94 E0076D24 00431025 */  or        $v0, $v0, $v1
/* 377D98 E0076D28 ACA2001C */  sw        $v0, 0x1c($a1)
/* 377D9C E0076D2C C6620034 */  lwc1      $f2, 0x34($s3)
/* 377DA0 E0076D30 46041082 */  mul.s     $f2, $f2, $f4
/* 377DA4 E0076D34 00000000 */  nop
/* 377DA8 E0076D38 3C06F200 */  lui       $a2, 0xf200
/* 377DAC E0076D3C 3C040100 */  lui       $a0, 0x100
/* 377DB0 E0076D40 C6600040 */  lwc1      $f0, 0x40($s3)
/* 377DB4 E0076D44 24A20028 */  addiu     $v0, $a1, 0x28
/* 377DB8 E0076D48 46040002 */  mul.s     $f0, $f0, $f4
/* 377DBC E0076D4C 00000000 */  nop
/* 377DC0 E0076D50 ACE20000 */  sw        $v0, ($a3)
/* 377DC4 E0076D54 24A20030 */  addiu     $v0, $a1, 0x30
/* 377DC8 E0076D58 ACE20000 */  sw        $v0, ($a3)
/* 377DCC E0076D5C 4600118D */  trunc.w.s $f6, $f2
/* 377DD0 E0076D60 440A3000 */  mfc1      $t2, $f6
/* 377DD4 E0076D64 4600018D */  trunc.w.s $f6, $f0
/* 377DD8 E0076D68 440B3000 */  mfc1      $t3, $f6
/* 377DDC E0076D6C 31430FFF */  andi      $v1, $t2, 0xfff
/* 377DE0 E0076D70 00031B00 */  sll       $v1, $v1, 0xc
/* 377DE4 E0076D74 31620FFF */  andi      $v0, $t3, 0xfff
/* 377DE8 E0076D78 00461025 */  or        $v0, $v0, $a2
/* 377DEC E0076D7C 00621825 */  or        $v1, $v1, $v0
/* 377DF0 E0076D80 2542007C */  addiu     $v0, $t2, 0x7c
/* 377DF4 E0076D84 30420FFF */  andi      $v0, $v0, 0xfff
/* 377DF8 E0076D88 00021300 */  sll       $v0, $v0, 0xc
/* 377DFC E0076D8C ACA30020 */  sw        $v1, 0x20($a1)
/* 377E00 E0076D90 256301FC */  addiu     $v1, $t3, 0x1fc
/* 377E04 E0076D94 30630FFF */  andi      $v1, $v1, 0xfff
/* 377E08 E0076D98 00641825 */  or        $v1, $v1, $a0
/* 377E0C E0076D9C 00431025 */  or        $v0, $v0, $v1
/* 377E10 E0076DA0 ACA20024 */  sw        $v0, 0x24($a1)
/* 377E14 E0076DA4 ACA80028 */  sw        $t0, 0x28($a1)
/* 377E18 E0076DA8 3C02E007 */  lui       $v0, %hi(D_E0076E90)
/* 377E1C E0076DAC 00491021 */  addu      $v0, $v0, $t1
/* 377E20 E0076DB0 8C426E90 */  lw        $v0, %lo(D_E0076E90)($v0)
/* 377E24 E0076DB4 ACA2002C */  sw        $v0, 0x2c($a1)
/* 377E28 E0076DB8 C662004C */  lwc1      $f2, 0x4c($s3)
/* 377E2C E0076DBC 24A20038 */  addiu     $v0, $a1, 0x38
/* 377E30 E0076DC0 46041082 */  mul.s     $f2, $f2, $f4
/* 377E34 E0076DC4 00000000 */  nop
/* 377E38 E0076DC8 ACE20000 */  sw        $v0, ($a3)
/* 377E3C E0076DCC C6600058 */  lwc1      $f0, 0x58($s3)
/* 377E40 E0076DD0 24A20040 */  addiu     $v0, $a1, 0x40
/* 377E44 E0076DD4 ACE20000 */  sw        $v0, ($a3)
/* 377E48 E0076DD8 46040002 */  mul.s     $f0, $f0, $f4
/* 377E4C E0076DDC 00000000 */  nop
/* 377E50 E0076DE0 24A20048 */  addiu     $v0, $a1, 0x48
/* 377E54 E0076DE4 ACE20000 */  sw        $v0, ($a3)
/* 377E58 E0076DE8 ACA80038 */  sw        $t0, 0x38($a1)
/* 377E5C E0076DEC 4600118D */  trunc.w.s $f6, $f2
/* 377E60 E0076DF0 440A3000 */  mfc1      $t2, $f6
/* 377E64 E0076DF4 4600018D */  trunc.w.s $f6, $f0
/* 377E68 E0076DF8 440B3000 */  mfc1      $t3, $f6
/* 377E6C E0076DFC 2543001E */  addiu     $v1, $t2, 0x1e
/* 377E70 E0076E00 30630FFF */  andi      $v1, $v1, 0xfff
/* 377E74 E0076E04 00031B00 */  sll       $v1, $v1, 0xc
/* 377E78 E0076E08 2562001E */  addiu     $v0, $t3, 0x1e
/* 377E7C E0076E0C 30420FFF */  andi      $v0, $v0, 0xfff
/* 377E80 E0076E10 00461025 */  or        $v0, $v0, $a2
/* 377E84 E0076E14 00621825 */  or        $v1, $v1, $v0
/* 377E88 E0076E18 ACA30030 */  sw        $v1, 0x30($a1)
/* 377E8C E0076E1C 2543011A */  addiu     $v1, $t2, 0x11a
/* 377E90 E0076E20 30630FFF */  andi      $v1, $v1, 0xfff
/* 377E94 E0076E24 00031B00 */  sll       $v1, $v1, 0xc
/* 377E98 E0076E28 2562021A */  addiu     $v0, $t3, 0x21a
/* 377E9C E0076E2C 30420FFF */  andi      $v0, $v0, 0xfff
/* 377EA0 E0076E30 00441025 */  or        $v0, $v0, $a0
/* 377EA4 E0076E34 00621825 */  or        $v1, $v1, $v0
/* 377EA8 E0076E38 ACA30034 */  sw        $v1, 0x34($a1)
/* 377EAC E0076E3C 3C03E007 */  lui       $v1, %hi(D_E0076EA0)
/* 377EB0 E0076E40 00691821 */  addu      $v1, $v1, $t1
/* 377EB4 E0076E44 8C636EA0 */  lw        $v1, %lo(D_E0076EA0)($v1)
/* 377EB8 E0076E48 3C02E700 */  lui       $v0, 0xe700
/* 377EBC E0076E4C ACA20040 */  sw        $v0, 0x40($a1)
/* 377EC0 E0076E50 ACA00044 */  sw        $zero, 0x44($a1)
/* 377EC4 E0076E54 ACA3003C */  sw        $v1, 0x3c($a1)
/* 377EC8 E0076E58 8FBF00F4 */  lw        $ra, 0xf4($sp)
/* 377ECC E0076E5C 8FB600F0 */  lw        $s6, 0xf0($sp)
/* 377ED0 E0076E60 8FB500EC */  lw        $s5, 0xec($sp)
/* 377ED4 E0076E64 8FB400E8 */  lw        $s4, 0xe8($sp)
/* 377ED8 E0076E68 8FB300E4 */  lw        $s3, 0xe4($sp)
/* 377EDC E0076E6C 8FB200E0 */  lw        $s2, 0xe0($sp)
/* 377EE0 E0076E70 8FB100DC */  lw        $s1, 0xdc($sp)
/* 377EE4 E0076E74 8FB000D8 */  lw        $s0, 0xd8($sp)
/* 377EE8 E0076E78 D7B400F8 */  ldc1      $f20, 0xf8($sp)
/* 377EEC E0076E7C 03E00008 */  jr        $ra
/* 377EF0 E0076E80 27BD0100 */   addiu    $sp, $sp, 0x100
/* 377EF4 E0076E84 00000000 */  nop
/* 377EF8 E0076E88 00000000 */  nop
/* 377EFC E0076E8C 00000000 */  nop
