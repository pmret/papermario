.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_80150020
.double 180.0

glabel D_80150028
.double 32767.0

.section .text

glabel reload_mesh_animator_node
/* B6C30 80120530 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* B6C34 80120534 AFB00030 */  sw        $s0, 0x30($sp)
/* B6C38 80120538 0080802D */  daddu     $s0, $a0, $zero
/* B6C3C 8012053C AFB10034 */  sw        $s1, 0x34($sp)
/* B6C40 80120540 00A0882D */  daddu     $s1, $a1, $zero
/* B6C44 80120544 00C0282D */  daddu     $a1, $a2, $zero
/* B6C48 80120548 AFB20038 */  sw        $s2, 0x38($sp)
/* B6C4C 8012054C 00E0902D */  daddu     $s2, $a3, $zero
/* B6C50 80120550 27A60010 */  addiu     $a2, $sp, 0x10
/* B6C54 80120554 12000042 */  beqz      $s0, .L80120660
/* B6C58 80120558 AFBF003C */   sw       $ra, 0x3c($sp)
/* B6C5C 8012055C 8E020000 */  lw        $v0, ($s0)
/* B6C60 80120560 AFA00014 */  sw        $zero, 0x14($sp)
/* B6C64 80120564 AFA00018 */  sw        $zero, 0x18($sp)
/* B6C68 80120568 AFA0001C */  sw        $zero, 0x1c($sp)
/* B6C6C 8012056C AFA20010 */  sw        $v0, 0x10($sp)
/* B6C70 80120570 86020004 */  lh        $v0, 4($s0)
/* B6C74 80120574 3C018015 */  lui       $at, %hi(D_80150020)
/* B6C78 80120578 D4220020 */  ldc1      $f2, %lo(D_80150020)($at)
/* B6C7C 8012057C 44820000 */  mtc1      $v0, $f0
/* B6C80 80120580 00000000 */  nop
/* B6C84 80120584 46800020 */  cvt.s.w   $f0, $f0
/* B6C88 80120588 46000021 */  cvt.d.s   $f0, $f0
/* B6C8C 8012058C 46220002 */  mul.d     $f0, $f0, $f2
/* B6C90 80120590 00000000 */  nop
/* B6C94 80120594 3C018015 */  lui       $at, %hi(D_80150028)
/* B6C98 80120598 D4240028 */  ldc1      $f4, %lo(D_80150028)($at)
/* B6C9C 8012059C 46240003 */  div.d     $f0, $f0, $f4
/* B6CA0 801205A0 46200020 */  cvt.s.d   $f0, $f0
/* B6CA4 801205A4 E7A00020 */  swc1      $f0, 0x20($sp)
/* B6CA8 801205A8 86020006 */  lh        $v0, 6($s0)
/* B6CAC 801205AC 44820000 */  mtc1      $v0, $f0
/* B6CB0 801205B0 00000000 */  nop
/* B6CB4 801205B4 46800020 */  cvt.s.w   $f0, $f0
/* B6CB8 801205B8 46000021 */  cvt.d.s   $f0, $f0
/* B6CBC 801205BC 46220002 */  mul.d     $f0, $f0, $f2
/* B6CC0 801205C0 00000000 */  nop
/* B6CC4 801205C4 46240003 */  div.d     $f0, $f0, $f4
/* B6CC8 801205C8 46200020 */  cvt.s.d   $f0, $f0
/* B6CCC 801205CC E7A00024 */  swc1      $f0, 0x24($sp)
/* B6CD0 801205D0 86020008 */  lh        $v0, 8($s0)
/* B6CD4 801205D4 44820000 */  mtc1      $v0, $f0
/* B6CD8 801205D8 00000000 */  nop
/* B6CDC 801205DC 46800020 */  cvt.s.w   $f0, $f0
/* B6CE0 801205E0 46000021 */  cvt.d.s   $f0, $f0
/* B6CE4 801205E4 46220002 */  mul.d     $f0, $f0, $f2
/* B6CE8 801205E8 00000000 */  nop
/* B6CEC 801205EC 0220202D */  daddu     $a0, $s1, $zero
/* B6CF0 801205F0 46240003 */  div.d     $f0, $f0, $f4
/* B6CF4 801205F4 46200020 */  cvt.s.d   $f0, $f0
/* B6CF8 801205F8 0C0479C6 */  jal       add_anim_node
/* B6CFC 801205FC E7A00028 */   swc1     $f0, 0x28($sp)
/* B6D00 80120600 96030020 */  lhu       $v1, 0x20($s0)
/* B6D04 80120604 0040302D */  daddu     $a2, $v0, $zero
/* B6D08 80120608 A4C300F8 */  sh        $v1, 0xf8($a2)
/* B6D0C 8012060C 8E020024 */  lw        $v0, 0x24($s0)
/* B6D10 80120610 3C038015 */  lui       $v1, %hi(D_80153B68)
/* B6D14 80120614 8C633B68 */  lw        $v1, %lo(D_80153B68)($v1)
/* B6D18 80120618 ACC200FC */  sw        $v0, 0xfc($a2)
/* B6D1C 8012061C 8C620000 */  lw        $v0, ($v1)
/* B6D20 80120620 10500005 */  beq       $v0, $s0, .L80120638
/* B6D24 80120624 0000202D */   daddu    $a0, $zero, $zero
.L80120628:
/* B6D28 80120628 24630004 */  addiu     $v1, $v1, 4
/* B6D2C 8012062C 8C620000 */  lw        $v0, ($v1)
/* B6D30 80120630 1450FFFD */  bne       $v0, $s0, .L80120628
/* B6D34 80120634 24840001 */   addiu    $a0, $a0, 1
.L80120638:
/* B6D38 80120638 00041080 */  sll       $v0, $a0, 2
/* B6D3C 8012063C 84C300F6 */  lh        $v1, 0xf6($a2)
/* B6D40 80120640 00521021 */  addu      $v0, $v0, $s2
/* B6D44 80120644 AC430000 */  sw        $v1, ($v0)
/* B6D48 80120648 8E04001C */  lw        $a0, 0x1c($s0)
/* B6D4C 8012064C 10800004 */  beqz      $a0, .L80120660
/* B6D50 80120650 0220282D */   daddu    $a1, $s1, $zero
/* B6D54 80120654 84C600F6 */  lh        $a2, 0xf6($a2)
/* B6D58 80120658 0C04814C */  jal       reload_mesh_animator_node
/* B6D5C 8012065C 0240382D */   daddu    $a3, $s2, $zero
.L80120660:
/* B6D60 80120660 8FBF003C */  lw        $ra, 0x3c($sp)
/* B6D64 80120664 8FB20038 */  lw        $s2, 0x38($sp)
/* B6D68 80120668 8FB10034 */  lw        $s1, 0x34($sp)
/* B6D6C 8012066C 8FB00030 */  lw        $s0, 0x30($sp)
/* B6D70 80120670 03E00008 */  jr        $ra
/* B6D74 80120674 27BD0040 */   addiu    $sp, $sp, 0x40
