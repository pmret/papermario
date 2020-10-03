.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel add_vec2D_polar
/* 539C 80029F9C 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 53A0 80029FA0 AFB00018 */  sw        $s0, 0x18($sp)
/* 53A4 80029FA4 0080802D */  daddu     $s0, $a0, $zero
/* 53A8 80029FA8 AFB1001C */  sw        $s1, 0x1c($sp)
/* 53AC 80029FAC 00A0882D */  daddu     $s1, $a1, $zero
/* 53B0 80029FB0 3C0140C9 */  lui       $at, 0x40c9
/* 53B4 80029FB4 34210FD0 */  ori       $at, $at, 0xfd0
/* 53B8 80029FB8 44810000 */  mtc1      $at, $f0
/* 53BC 80029FBC 44872000 */  mtc1      $a3, $f4
/* 53C0 80029FC0 27A50010 */  addiu     $a1, $sp, 0x10
/* 53C4 80029FC4 F7B40028 */  sdc1      $f20, 0x28($sp)
/* 53C8 80029FC8 46002002 */  mul.s     $f0, $f4, $f0
/* 53CC 80029FCC 00000000 */  nop       
/* 53D0 80029FD0 4486A000 */  mtc1      $a2, $f20
/* 53D4 80029FD4 3C0143B4 */  lui       $at, 0x43b4
/* 53D8 80029FD8 44816000 */  mtc1      $at, $f12
/* 53DC 80029FDC 27A60014 */  addiu     $a2, $sp, 0x14
/* 53E0 80029FE0 AFBF0020 */  sw        $ra, 0x20($sp)
/* 53E4 80029FE4 0C00A82D */  jal       sin_cos_rad
/* 53E8 80029FE8 460C0303 */   div.s    $f12, $f0, $f12
/* 53EC 80029FEC C7A20010 */  lwc1      $f2, 0x10($sp)
/* 53F0 80029FF0 4602A082 */  mul.s     $f2, $f20, $f2
/* 53F4 80029FF4 00000000 */  nop       
/* 53F8 80029FF8 C6000000 */  lwc1      $f0, ($s0)
/* 53FC 80029FFC 46020000 */  add.s     $f0, $f0, $f2
/* 5400 8002A000 E6000000 */  swc1      $f0, ($s0)
/* 5404 8002A004 C7A00014 */  lwc1      $f0, 0x14($sp)
/* 5408 8002A008 4600A502 */  mul.s     $f20, $f20, $f0
/* 540C 8002A00C 00000000 */  nop       
/* 5410 8002A010 C6200000 */  lwc1      $f0, ($s1)
/* 5414 8002A014 46140001 */  sub.s     $f0, $f0, $f20
/* 5418 8002A018 E6200000 */  swc1      $f0, ($s1)
/* 541C 8002A01C 8FBF0020 */  lw        $ra, 0x20($sp)
/* 5420 8002A020 8FB1001C */  lw        $s1, 0x1c($sp)
/* 5424 8002A024 8FB00018 */  lw        $s0, 0x18($sp)
/* 5428 8002A028 D7B40028 */  ldc1      $f20, 0x28($sp)
/* 542C 8002A02C 03E00008 */  jr        $ra
/* 5430 8002A030 27BD0030 */   addiu    $sp, $sp, 0x30
