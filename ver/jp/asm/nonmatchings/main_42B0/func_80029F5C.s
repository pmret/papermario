.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80029F5C
/* 535C 80029F5C 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 5360 80029F60 AFB00018 */  sw        $s0, 0x18($sp)
/* 5364 80029F64 0080802D */  daddu     $s0, $a0, $zero
/* 5368 80029F68 AFB1001C */  sw        $s1, 0x1c($sp)
/* 536C 80029F6C 00A0882D */  daddu     $s1, $a1, $zero
/* 5370 80029F70 3C0140C9 */  lui       $at, 0x40c9
/* 5374 80029F74 34210FD0 */  ori       $at, $at, 0xfd0
/* 5378 80029F78 44810000 */  mtc1      $at, $f0
/* 537C 80029F7C 44872000 */  mtc1      $a3, $f4
/* 5380 80029F80 27A50010 */  addiu     $a1, $sp, 0x10
/* 5384 80029F84 F7B40028 */  sdc1      $f20, 0x28($sp)
/* 5388 80029F88 46002002 */  mul.s     $f0, $f4, $f0
/* 538C 80029F8C 00000000 */  nop
/* 5390 80029F90 4486A000 */  mtc1      $a2, $f20
/* 5394 80029F94 3C0143B4 */  lui       $at, 0x43b4
/* 5398 80029F98 44816000 */  mtc1      $at, $f12
/* 539C 80029F9C 27A60014 */  addiu     $a2, $sp, 0x14
/* 53A0 80029FA0 AFBF0020 */  sw        $ra, 0x20($sp)
/* 53A4 80029FA4 0C00A81D */  jal       func_8002A074
/* 53A8 80029FA8 460C0303 */   div.s    $f12, $f0, $f12
/* 53AC 80029FAC C7A20010 */  lwc1      $f2, 0x10($sp)
/* 53B0 80029FB0 4602A082 */  mul.s     $f2, $f20, $f2
/* 53B4 80029FB4 00000000 */  nop
/* 53B8 80029FB8 C6000000 */  lwc1      $f0, ($s0)
/* 53BC 80029FBC 46020000 */  add.s     $f0, $f0, $f2
/* 53C0 80029FC0 E6000000 */  swc1      $f0, ($s0)
/* 53C4 80029FC4 C7A00014 */  lwc1      $f0, 0x14($sp)
/* 53C8 80029FC8 4600A502 */  mul.s     $f20, $f20, $f0
/* 53CC 80029FCC 00000000 */  nop
/* 53D0 80029FD0 C6200000 */  lwc1      $f0, ($s1)
/* 53D4 80029FD4 46140001 */  sub.s     $f0, $f0, $f20
/* 53D8 80029FD8 E6200000 */  swc1      $f0, ($s1)
/* 53DC 80029FDC 8FBF0020 */  lw        $ra, 0x20($sp)
/* 53E0 80029FE0 8FB1001C */  lw        $s1, 0x1c($sp)
/* 53E4 80029FE4 8FB00018 */  lw        $s0, 0x18($sp)
/* 53E8 80029FE8 D7B40028 */  ldc1      $f20, 0x28($sp)
/* 53EC 80029FEC 03E00008 */  jr        $ra
/* 53F0 80029FF0 27BD0030 */   addiu    $sp, $sp, 0x30
