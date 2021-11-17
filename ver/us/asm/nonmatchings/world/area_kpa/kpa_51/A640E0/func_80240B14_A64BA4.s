.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

dlabel D_80242F90_A67020
.double 0.1

dlabel D_80242F98_A67028
.double 0.4

.section .text

glabel func_80240B14_A64BA4
/* A64BA4 80240B14 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* A64BA8 80240B18 AFB20028 */  sw        $s2, 0x28($sp)
/* A64BAC 80240B1C 0080902D */  daddu     $s2, $a0, $zero
/* A64BB0 80240B20 AFBF002C */  sw        $ra, 0x2c($sp)
/* A64BB4 80240B24 AFB10024 */  sw        $s1, 0x24($sp)
/* A64BB8 80240B28 AFB00020 */  sw        $s0, 0x20($sp)
/* A64BBC 80240B2C 8E510148 */  lw        $s1, 0x148($s2)
/* A64BC0 80240B30 0C00EABB */  jal       get_npc_unsafe
/* A64BC4 80240B34 86240008 */   lh       $a0, 8($s1)
/* A64BC8 80240B38 8E23006C */  lw        $v1, 0x6c($s1)
/* A64BCC 80240B3C 14600006 */  bnez      $v1, .L80240B58
/* A64BD0 80240B40 0040802D */   daddu    $s0, $v0, $zero
/* A64BD4 80240B44 8603008E */  lh        $v1, 0x8e($s0)
/* A64BD8 80240B48 00031100 */  sll       $v0, $v1, 4
/* A64BDC 80240B4C 00431023 */  subu      $v0, $v0, $v1
/* A64BE0 80240B50 080902DA */  j         .L80240B68
/* A64BE4 80240B54 24430082 */   addiu    $v1, $v0, 0x82
.L80240B58:
/* A64BE8 80240B58 8603008E */  lh        $v1, 0x8e($s0)
/* A64BEC 80240B5C 00031100 */  sll       $v0, $v1, 4
/* A64BF0 80240B60 00431023 */  subu      $v0, $v0, $v1
/* A64BF4 80240B64 2443001E */  addiu     $v1, $v0, 0x1e
.L80240B68:
/* A64BF8 80240B68 00031400 */  sll       $v0, $v1, 0x10
/* A64BFC 80240B6C 00021403 */  sra       $v0, $v0, 0x10
/* A64C00 80240B70 28420100 */  slti      $v0, $v0, 0x100
/* A64C04 80240B74 50400001 */  beql      $v0, $zero, .L80240B7C
/* A64C08 80240B78 240300FF */   addiu    $v1, $zero, 0xff
.L80240B7C:
/* A64C0C 80240B7C 8602008E */  lh        $v0, 0x8e($s0)
/* A64C10 80240B80 3C018024 */  lui       $at, %hi(D_80242F90_A67020)
/* A64C14 80240B84 D4222F90 */  ldc1      $f2, %lo(D_80242F90_A67020)($at)
/* A64C18 80240B88 44820000 */  mtc1      $v0, $f0
/* A64C1C 80240B8C 00000000 */  nop
/* A64C20 80240B90 46800020 */  cvt.s.w   $f0, $f0
/* A64C24 80240B94 46000021 */  cvt.d.s   $f0, $f0
/* A64C28 80240B98 46220002 */  mul.d     $f0, $f0, $f2
/* A64C2C 80240B9C 00000000 */  nop
/* A64C30 80240BA0 3C018024 */  lui       $at, %hi(D_80242F98_A67028)
/* A64C34 80240BA4 D4222F98 */  ldc1      $f2, %lo(D_80242F98_A67028)($at)
/* A64C38 80240BA8 46220000 */  add.d     $f0, $f0, $f2
/* A64C3C 80240BAC A20300AC */  sb        $v1, 0xac($s0)
/* A64C40 80240BB0 3C013FF0 */  lui       $at, 0x3ff0
/* A64C44 80240BB4 44811800 */  mtc1      $at, $f3
/* A64C48 80240BB8 44801000 */  mtc1      $zero, $f2
/* A64C4C 80240BBC 46200020 */  cvt.s.d   $f0, $f0
/* A64C50 80240BC0 E6000054 */  swc1      $f0, 0x54($s0)
/* A64C54 80240BC4 46000021 */  cvt.d.s   $f0, $f0
/* A64C58 80240BC8 4620103C */  c.lt.d    $f2, $f0
/* A64C5C 80240BCC 00000000 */  nop
/* A64C60 80240BD0 45000005 */  bc1f      .L80240BE8
/* A64C64 80240BD4 24030005 */   addiu    $v1, $zero, 5
/* A64C68 80240BD8 3C013F80 */  lui       $at, 0x3f80
/* A64C6C 80240BDC 44810000 */  mtc1      $at, $f0
/* A64C70 80240BE0 00000000 */  nop
/* A64C74 80240BE4 E6000054 */  swc1      $f0, 0x54($s0)
.L80240BE8:
/* A64C78 80240BE8 C6000054 */  lwc1      $f0, 0x54($s0)
/* A64C7C 80240BEC 9602008E */  lhu       $v0, 0x8e($s0)
/* A64C80 80240BF0 46000086 */  mov.s     $f2, $f0
/* A64C84 80240BF4 24420001 */  addiu     $v0, $v0, 1
/* A64C88 80240BF8 A602008E */  sh        $v0, 0x8e($s0)
/* A64C8C 80240BFC 00021400 */  sll       $v0, $v0, 0x10
/* A64C90 80240C00 00021403 */  sra       $v0, $v0, 0x10
/* A64C94 80240C04 E6000058 */  swc1      $f0, 0x58($s0)
/* A64C98 80240C08 14430008 */  bne       $v0, $v1, .L80240C2C
/* A64C9C 80240C0C E602005C */   swc1     $f2, 0x5c($s0)
/* A64CA0 80240C10 0C00EAE8 */  jal       enable_npc_shadow
/* A64CA4 80240C14 0200202D */   daddu    $a0, $s0, $zero
/* A64CA8 80240C18 3C03E0EF */  lui       $v1, 0xe0ef
/* A64CAC 80240C1C 8E220000 */  lw        $v0, ($s1)
/* A64CB0 80240C20 3463FFFF */  ori       $v1, $v1, 0xffff
/* A64CB4 80240C24 00431024 */  and       $v0, $v0, $v1
/* A64CB8 80240C28 AE220000 */  sw        $v0, ($s1)
.L80240C2C:
/* A64CBC 80240C2C 8E22006C */  lw        $v0, 0x6c($s1)
/* A64CC0 80240C30 1440000E */  bnez      $v0, .L80240C6C
/* A64CC4 80240C34 00000000 */   nop
/* A64CC8 80240C38 8602008E */  lh        $v0, 0x8e($s0)
/* A64CCC 80240C3C 28420014 */  slti      $v0, $v0, 0x14
/* A64CD0 80240C40 14400017 */  bnez      $v0, .L80240CA0
/* A64CD4 80240C44 0000282D */   daddu    $a1, $zero, $zero
/* A64CD8 80240C48 00A0302D */  daddu     $a2, $a1, $zero
/* A64CDC 80240C4C AFA00010 */  sw        $zero, 0x10($sp)
/* A64CE0 80240C50 AFA00014 */  sw        $zero, 0x14($sp)
/* A64CE4 80240C54 AFA00018 */  sw        $zero, 0x18($sp)
/* A64CE8 80240C58 8E040024 */  lw        $a0, 0x24($s0)
/* A64CEC 80240C5C 0C0B7A25 */  jal       func_802DE894
/* A64CF0 80240C60 00A0382D */   daddu    $a3, $a1, $zero
/* A64CF4 80240C64 0809031F */  j         .L80240C7C
/* A64CF8 80240C68 00000000 */   nop
.L80240C6C:
/* A64CFC 80240C6C 8602008E */  lh        $v0, 0x8e($s0)
/* A64D00 80240C70 2842000A */  slti      $v0, $v0, 0xa
/* A64D04 80240C74 1440000A */  bnez      $v0, .L80240CA0
/* A64D08 80240C78 00000000 */   nop
.L80240C7C:
/* A64D0C 80240C7C 3C013F80 */  lui       $at, 0x3f80
/* A64D10 80240C80 44810000 */  mtc1      $at, $f0
/* A64D14 80240C84 240200FF */  addiu     $v0, $zero, 0xff
/* A64D18 80240C88 A20200AC */  sb        $v0, 0xac($s0)
/* A64D1C 80240C8C 24020014 */  addiu     $v0, $zero, 0x14
/* A64D20 80240C90 E6000054 */  swc1      $f0, 0x54($s0)
/* A64D24 80240C94 E6000058 */  swc1      $f0, 0x58($s0)
/* A64D28 80240C98 E600005C */  swc1      $f0, 0x5c($s0)
/* A64D2C 80240C9C AE420070 */  sw        $v0, 0x70($s2)
.L80240CA0:
/* A64D30 80240CA0 8FBF002C */  lw        $ra, 0x2c($sp)
/* A64D34 80240CA4 8FB20028 */  lw        $s2, 0x28($sp)
/* A64D38 80240CA8 8FB10024 */  lw        $s1, 0x24($sp)
/* A64D3C 80240CAC 8FB00020 */  lw        $s0, 0x20($sp)
/* A64D40 80240CB0 03E00008 */  jr        $ra
/* A64D44 80240CB4 27BD0030 */   addiu    $sp, $sp, 0x30
