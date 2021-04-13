.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_80151248
.double 0.01

.section .text

glabel basic_hidden_window_update
/* DDC74 80147574 3C028016 */  lui       $v0, %hi(gUIPanels)
/* DDC78 80147578 24429D50 */  addiu     $v0, $v0, %lo(gUIPanels)
/* DDC7C 8014757C 00042140 */  sll       $a0, $a0, 5
/* DDC80 80147580 00822021 */  addu      $a0, $a0, $v0
/* DDC84 80147584 9086001C */  lbu       $a2, 0x1c($a0)
/* DDC88 80147588 8FA70014 */  lw        $a3, 0x14($sp)
/* DDC8C 8014758C 8FA80018 */  lw        $t0, 0x18($sp)
/* DDC90 80147590 8FA90024 */  lw        $t1, 0x24($sp)
/* DDC94 80147594 28C2000A */  slti      $v0, $a2, 0xa
/* DDC98 80147598 10400022 */  beqz      $v0, .L80147624
/* DDC9C 8014759C 00000000 */   nop
/* DDCA0 801475A0 3C038015 */  lui       $v1, %hi(D_8014F2A8)
/* DDCA4 801475A4 2463F2A8 */  addiu     $v1, $v1, %lo(D_8014F2A8)
/* DDCA8 801475A8 3C028015 */  lui       $v0, %hi(D_8014F2B4)
/* DDCAC 801475AC 00461021 */  addu      $v0, $v0, $a2
/* DDCB0 801475B0 9042F2B4 */  lbu       $v0, %lo(D_8014F2B4)($v0)
/* DDCB4 801475B4 00C31821 */  addu      $v1, $a2, $v1
/* DDCB8 801475B8 ACA20000 */  sw        $v0, ($a1)
/* DDCBC 801475BC 90620000 */  lbu       $v0, ($v1)
/* DDCC0 801475C0 3C018015 */  lui       $at, %hi(D_80151248)
/* DDCC4 801475C4 D4221248 */  ldc1      $f2, %lo(D_80151248)($at)
/* DDCC8 801475C8 44820000 */  mtc1      $v0, $f0
/* DDCCC 801475CC 00000000 */  nop
/* DDCD0 801475D0 46800020 */  cvt.s.w   $f0, $f0
/* DDCD4 801475D4 46000021 */  cvt.d.s   $f0, $f0
/* DDCD8 801475D8 46220002 */  mul.d     $f0, $f0, $f2
/* DDCDC 801475DC 00000000 */  nop
/* DDCE0 801475E0 46200020 */  cvt.s.d   $f0, $f0
/* DDCE4 801475E4 E4E00000 */  swc1      $f0, ($a3)
/* DDCE8 801475E8 90620000 */  lbu       $v0, ($v1)
/* DDCEC 801475EC 44820000 */  mtc1      $v0, $f0
/* DDCF0 801475F0 00000000 */  nop
/* DDCF4 801475F4 46800020 */  cvt.s.w   $f0, $f0
/* DDCF8 801475F8 46000021 */  cvt.d.s   $f0, $f0
/* DDCFC 801475FC 46220002 */  mul.d     $f0, $f0, $f2
/* DDD00 80147600 00000000 */  nop
/* DDD04 80147604 00061023 */  negu      $v0, $a2
/* DDD08 80147608 46200020 */  cvt.s.d   $f0, $f0
/* DDD0C 8014760C E5000000 */  swc1      $f0, ($t0)
/* DDD10 80147610 44820000 */  mtc1      $v0, $f0
/* DDD14 80147614 00000000 */  nop
/* DDD18 80147618 46800020 */  cvt.s.w   $f0, $f0
/* DDD1C 8014761C 03E00008 */  jr        $ra
/* DDD20 80147620 E5200000 */   swc1     $f0, ($t1)
.L80147624:
/* DDD24 80147624 3C028015 */  lui       $v0, %hi(D_8014F2BD)
/* DDD28 80147628 9042F2BD */  lbu       $v0, %lo(D_8014F2BD)($v0)
/* DDD2C 8014762C ACA20000 */  sw        $v0, ($a1)
/* DDD30 80147630 ACE00000 */  sw        $zero, ($a3)
/* DDD34 80147634 AD000000 */  sw        $zero, ($t0)
/* DDD38 80147638 AD200000 */  sw        $zero, ($t1)
/* DDD3C 8014763C 90820000 */  lbu       $v0, ($a0)
/* DDD40 80147640 304200F7 */  andi      $v0, $v0, 0xf7
/* DDD44 80147644 34420004 */  ori       $v0, $v0, 4
/* DDD48 80147648 03E00008 */  jr        $ra
/* DDD4C 8014764C A0820000 */   sb       $v0, ($a0)
