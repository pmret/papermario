.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_80242560_A4EF80
.double 0.1

glabel D_80242568_A4EF88
.double 0.4

.section .text

glabel func_80240B64_A4D584
/* A4D584 80240B64 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* A4D588 80240B68 AFB20028 */  sw        $s2, 0x28($sp)
/* A4D58C 80240B6C 0080902D */  daddu     $s2, $a0, $zero
/* A4D590 80240B70 AFBF002C */  sw        $ra, 0x2c($sp)
/* A4D594 80240B74 AFB10024 */  sw        $s1, 0x24($sp)
/* A4D598 80240B78 AFB00020 */  sw        $s0, 0x20($sp)
/* A4D59C 80240B7C 8E510148 */  lw        $s1, 0x148($s2)
/* A4D5A0 80240B80 0C00EABB */  jal       get_npc_unsafe
/* A4D5A4 80240B84 86240008 */   lh       $a0, 8($s1)
/* A4D5A8 80240B88 8E23006C */  lw        $v1, 0x6c($s1)
/* A4D5AC 80240B8C 14600006 */  bnez      $v1, .L80240BA8
/* A4D5B0 80240B90 0040802D */   daddu    $s0, $v0, $zero
/* A4D5B4 80240B94 8603008E */  lh        $v1, 0x8e($s0)
/* A4D5B8 80240B98 00031100 */  sll       $v0, $v1, 4
/* A4D5BC 80240B9C 00431023 */  subu      $v0, $v0, $v1
/* A4D5C0 80240BA0 080902EE */  j         .L80240BB8
/* A4D5C4 80240BA4 24430082 */   addiu    $v1, $v0, 0x82
.L80240BA8:
/* A4D5C8 80240BA8 8603008E */  lh        $v1, 0x8e($s0)
/* A4D5CC 80240BAC 00031100 */  sll       $v0, $v1, 4
/* A4D5D0 80240BB0 00431023 */  subu      $v0, $v0, $v1
/* A4D5D4 80240BB4 2443001E */  addiu     $v1, $v0, 0x1e
.L80240BB8:
/* A4D5D8 80240BB8 00031400 */  sll       $v0, $v1, 0x10
/* A4D5DC 80240BBC 00021403 */  sra       $v0, $v0, 0x10
/* A4D5E0 80240BC0 28420100 */  slti      $v0, $v0, 0x100
/* A4D5E4 80240BC4 50400001 */  beql      $v0, $zero, .L80240BCC
/* A4D5E8 80240BC8 240300FF */   addiu    $v1, $zero, 0xff
.L80240BCC:
/* A4D5EC 80240BCC 8602008E */  lh        $v0, 0x8e($s0)
/* A4D5F0 80240BD0 3C018024 */  lui       $at, %hi(D_80242560_A4EF80)
/* A4D5F4 80240BD4 D4222560 */  ldc1      $f2, %lo(D_80242560_A4EF80)($at)
/* A4D5F8 80240BD8 44820000 */  mtc1      $v0, $f0
/* A4D5FC 80240BDC 00000000 */  nop
/* A4D600 80240BE0 46800020 */  cvt.s.w   $f0, $f0
/* A4D604 80240BE4 46000021 */  cvt.d.s   $f0, $f0
/* A4D608 80240BE8 46220002 */  mul.d     $f0, $f0, $f2
/* A4D60C 80240BEC 00000000 */  nop
/* A4D610 80240BF0 3C018024 */  lui       $at, %hi(D_80242568_A4EF88)
/* A4D614 80240BF4 D4222568 */  ldc1      $f2, %lo(D_80242568_A4EF88)($at)
/* A4D618 80240BF8 46220000 */  add.d     $f0, $f0, $f2
/* A4D61C 80240BFC A20300AC */  sb        $v1, 0xac($s0)
/* A4D620 80240C00 3C013FF0 */  lui       $at, 0x3ff0
/* A4D624 80240C04 44811800 */  mtc1      $at, $f3
/* A4D628 80240C08 44801000 */  mtc1      $zero, $f2
/* A4D62C 80240C0C 46200020 */  cvt.s.d   $f0, $f0
/* A4D630 80240C10 E6000054 */  swc1      $f0, 0x54($s0)
/* A4D634 80240C14 46000021 */  cvt.d.s   $f0, $f0
/* A4D638 80240C18 4620103C */  c.lt.d    $f2, $f0
/* A4D63C 80240C1C 00000000 */  nop
/* A4D640 80240C20 45000005 */  bc1f      .L80240C38
/* A4D644 80240C24 24030005 */   addiu    $v1, $zero, 5
/* A4D648 80240C28 3C013F80 */  lui       $at, 0x3f80
/* A4D64C 80240C2C 44810000 */  mtc1      $at, $f0
/* A4D650 80240C30 00000000 */  nop
/* A4D654 80240C34 E6000054 */  swc1      $f0, 0x54($s0)
.L80240C38:
/* A4D658 80240C38 C6000054 */  lwc1      $f0, 0x54($s0)
/* A4D65C 80240C3C 9602008E */  lhu       $v0, 0x8e($s0)
/* A4D660 80240C40 46000086 */  mov.s     $f2, $f0
/* A4D664 80240C44 24420001 */  addiu     $v0, $v0, 1
/* A4D668 80240C48 A602008E */  sh        $v0, 0x8e($s0)
/* A4D66C 80240C4C 00021400 */  sll       $v0, $v0, 0x10
/* A4D670 80240C50 00021403 */  sra       $v0, $v0, 0x10
/* A4D674 80240C54 E6000058 */  swc1      $f0, 0x58($s0)
/* A4D678 80240C58 14430008 */  bne       $v0, $v1, .L80240C7C
/* A4D67C 80240C5C E602005C */   swc1     $f2, 0x5c($s0)
/* A4D680 80240C60 0C00EAE8 */  jal       enable_npc_shadow
/* A4D684 80240C64 0200202D */   daddu    $a0, $s0, $zero
/* A4D688 80240C68 3C03E0EF */  lui       $v1, 0xe0ef
/* A4D68C 80240C6C 8E220000 */  lw        $v0, ($s1)
/* A4D690 80240C70 3463FFFF */  ori       $v1, $v1, 0xffff
/* A4D694 80240C74 00431024 */  and       $v0, $v0, $v1
/* A4D698 80240C78 AE220000 */  sw        $v0, ($s1)
.L80240C7C:
/* A4D69C 80240C7C 8E22006C */  lw        $v0, 0x6c($s1)
/* A4D6A0 80240C80 1440000E */  bnez      $v0, .L80240CBC
/* A4D6A4 80240C84 00000000 */   nop
/* A4D6A8 80240C88 8602008E */  lh        $v0, 0x8e($s0)
/* A4D6AC 80240C8C 28420014 */  slti      $v0, $v0, 0x14
/* A4D6B0 80240C90 14400017 */  bnez      $v0, .L80240CF0
/* A4D6B4 80240C94 0000282D */   daddu    $a1, $zero, $zero
/* A4D6B8 80240C98 00A0302D */  daddu     $a2, $a1, $zero
/* A4D6BC 80240C9C AFA00010 */  sw        $zero, 0x10($sp)
/* A4D6C0 80240CA0 AFA00014 */  sw        $zero, 0x14($sp)
/* A4D6C4 80240CA4 AFA00018 */  sw        $zero, 0x18($sp)
/* A4D6C8 80240CA8 8E040024 */  lw        $a0, 0x24($s0)
/* A4D6CC 80240CAC 0C0B7A25 */  jal       func_802DE894
/* A4D6D0 80240CB0 00A0382D */   daddu    $a3, $a1, $zero
/* A4D6D4 80240CB4 08090333 */  j         .L80240CCC
/* A4D6D8 80240CB8 00000000 */   nop
.L80240CBC:
/* A4D6DC 80240CBC 8602008E */  lh        $v0, 0x8e($s0)
/* A4D6E0 80240CC0 2842000A */  slti      $v0, $v0, 0xa
/* A4D6E4 80240CC4 1440000A */  bnez      $v0, .L80240CF0
/* A4D6E8 80240CC8 00000000 */   nop
.L80240CCC:
/* A4D6EC 80240CCC 3C013F80 */  lui       $at, 0x3f80
/* A4D6F0 80240CD0 44810000 */  mtc1      $at, $f0
/* A4D6F4 80240CD4 240200FF */  addiu     $v0, $zero, 0xff
/* A4D6F8 80240CD8 A20200AC */  sb        $v0, 0xac($s0)
/* A4D6FC 80240CDC 24020014 */  addiu     $v0, $zero, 0x14
/* A4D700 80240CE0 E6000054 */  swc1      $f0, 0x54($s0)
/* A4D704 80240CE4 E6000058 */  swc1      $f0, 0x58($s0)
/* A4D708 80240CE8 E600005C */  swc1      $f0, 0x5c($s0)
/* A4D70C 80240CEC AE420070 */  sw        $v0, 0x70($s2)
.L80240CF0:
/* A4D710 80240CF0 8FBF002C */  lw        $ra, 0x2c($sp)
/* A4D714 80240CF4 8FB20028 */  lw        $s2, 0x28($sp)
/* A4D718 80240CF8 8FB10024 */  lw        $s1, 0x24($sp)
/* A4D71C 80240CFC 8FB00020 */  lw        $s0, 0x20($sp)
/* A4D720 80240D00 03E00008 */  jr        $ra
/* A4D724 80240D04 27BD0030 */   addiu    $sp, $sp, 0x30
