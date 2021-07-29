.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_80242F38_992718
.double 0.7142857142857143

.section .text

glabel func_80241BA8_991388
/* 991388 80241BA8 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 99138C 80241BAC AFB20028 */  sw        $s2, 0x28($sp)
/* 991390 80241BB0 0080902D */  daddu     $s2, $a0, $zero
/* 991394 80241BB4 AFBF002C */  sw        $ra, 0x2c($sp)
/* 991398 80241BB8 AFB10024 */  sw        $s1, 0x24($sp)
/* 99139C 80241BBC AFB00020 */  sw        $s0, 0x20($sp)
/* 9913A0 80241BC0 8E420148 */  lw        $v0, 0x148($s2)
/* 9913A4 80241BC4 0C00EABB */  jal       get_npc_unsafe
/* 9913A8 80241BC8 84440008 */   lh       $a0, 8($v0)
/* 9913AC 80241BCC 24040054 */  addiu     $a0, $zero, 0x54
/* 9913B0 80241BD0 0C00AB39 */  jal       heap_malloc
/* 9913B4 80241BD4 0040882D */   daddu    $s1, $v0, $zero
/* 9913B8 80241BD8 27A40010 */  addiu     $a0, $sp, 0x10
/* 9913BC 80241BDC 0040802D */  daddu     $s0, $v0, $zero
/* 9913C0 80241BE0 24020035 */  addiu     $v0, $zero, 0x35
/* 9913C4 80241BE4 AE02000C */  sw        $v0, 0xc($s0)
/* 9913C8 80241BE8 0040282D */  daddu     $a1, $v0, $zero
/* 9913CC 80241BEC 0000302D */  daddu     $a2, $zero, $zero
/* 9913D0 80241BF0 AE000000 */  sw        $zero, ($s0)
/* 9913D4 80241BF4 0C0B7A76 */  jal       spr_get_npc_raster_info
/* 9913D8 80241BF8 AE000010 */   sw       $zero, 0x10($s0)
/* 9913DC 80241BFC C7A00018 */  lwc1      $f0, 0x18($sp)
/* 9913E0 80241C00 46800020 */  cvt.s.w   $f0, $f0
/* 9913E4 80241C04 E600004C */  swc1      $f0, 0x4c($s0)
/* 9913E8 80241C08 C7A0001C */  lwc1      $f0, 0x1c($sp)
/* 9913EC 80241C0C 46800020 */  cvt.s.w   $f0, $f0
/* 9913F0 80241C10 E6000050 */  swc1      $f0, 0x50($s0)
/* 9913F4 80241C14 46000086 */  mov.s     $f2, $f0
/* 9913F8 80241C18 3C018024 */  lui       $at, %hi(D_80242F38_992718)
/* 9913FC 80241C1C D4202F38 */  ldc1      $f0, %lo(D_80242F38_992718)($at)
/* 991400 80241C20 460010A1 */  cvt.d.s   $f2, $f2
/* 991404 80241C24 46201082 */  mul.d     $f2, $f2, $f0
/* 991408 80241C28 00000000 */  nop
/* 99140C 80241C2C 3C013FE0 */  lui       $at, 0x3fe0
/* 991410 80241C30 44810800 */  mtc1      $at, $f1
/* 991414 80241C34 44800000 */  mtc1      $zero, $f0
/* 991418 80241C38 00000000 */  nop
/* 99141C 80241C3C 46201082 */  mul.d     $f2, $f2, $f0
/* 991420 80241C40 00000000 */  nop
/* 991424 80241C44 3C014270 */  lui       $at, 0x4270
/* 991428 80241C48 44813000 */  mtc1      $at, $f6
/* 99142C 80241C4C C6200038 */  lwc1      $f0, 0x38($s1)
/* 991430 80241C50 0000202D */  daddu     $a0, $zero, $zero
/* 991434 80241C54 E6000014 */  swc1      $f0, 0x14($s0)
/* 991438 80241C58 C620003C */  lwc1      $f0, 0x3c($s1)
/* 99143C 80241C5C 3C01437F */  lui       $at, 0x437f
/* 991440 80241C60 44812000 */  mtc1      $at, $f4
/* 991444 80241C64 46000021 */  cvt.d.s   $f0, $f0
/* 991448 80241C68 46220000 */  add.d     $f0, $f0, $f2
/* 99144C 80241C6C 3C014300 */  lui       $at, 0x4300
/* 991450 80241C70 44814000 */  mtc1      $at, $f8
/* 991454 80241C74 3C0142B4 */  lui       $at, 0x42b4
/* 991458 80241C78 44811000 */  mtc1      $at, $f2
/* 99145C 80241C7C 46200020 */  cvt.s.d   $f0, $f0
/* 991460 80241C80 E6000018 */  swc1      $f0, 0x18($s0)
/* 991464 80241C84 C62A0040 */  lwc1      $f10, 0x40($s1)
/* 991468 80241C88 3C013F36 */  lui       $at, 0x3f36
/* 99146C 80241C8C 3421DB6E */  ori       $at, $at, 0xdb6e
/* 991470 80241C90 44810000 */  mtc1      $at, $f0
/* 991474 80241C94 3C058024 */  lui       $a1, %hi(func_80241610_990DF0)
/* 991478 80241C98 24A51610 */  addiu     $a1, $a1, %lo(func_80241610_990DF0)
/* 99147C 80241C9C AE000020 */  sw        $zero, 0x20($s0)
/* 991480 80241CA0 AE000024 */  sw        $zero, 0x24($s0)
/* 991484 80241CA4 E6020028 */  swc1      $f2, 0x28($s0)
/* 991488 80241CA8 E6060038 */  swc1      $f6, 0x38($s0)
/* 99148C 80241CAC E604003C */  swc1      $f4, 0x3c($s0)
/* 991490 80241CB0 E6080040 */  swc1      $f8, 0x40($s0)
/* 991494 80241CB4 E6040044 */  swc1      $f4, 0x44($s0)
/* 991498 80241CB8 AE000048 */  sw        $zero, 0x48($s0)
/* 99149C 80241CBC AE000004 */  sw        $zero, 4($s0)
/* 9914A0 80241CC0 E600002C */  swc1      $f0, 0x2c($s0)
/* 9914A4 80241CC4 E6000030 */  swc1      $f0, 0x30($s0)
/* 9914A8 80241CC8 E6000034 */  swc1      $f0, 0x34($s0)
/* 9914AC 80241CCC 0C048C8F */  jal       create_generic_entity_frontUI
/* 9914B0 80241CD0 E60A001C */   swc1     $f10, 0x1c($s0)
/* 9914B4 80241CD4 0240202D */  daddu     $a0, $s2, $zero
/* 9914B8 80241CD8 3C05FD05 */  lui       $a1, 0xfd05
/* 9914BC 80241CDC 34A50F8A */  ori       $a1, $a1, 0xf8a
/* 9914C0 80241CE0 0200302D */  daddu     $a2, $s0, $zero
/* 9914C4 80241CE4 0C0B2026 */  jal       set_variable
/* 9914C8 80241CE8 ACC20008 */   sw       $v0, 8($a2)
/* 9914CC 80241CEC 8FBF002C */  lw        $ra, 0x2c($sp)
/* 9914D0 80241CF0 8FB20028 */  lw        $s2, 0x28($sp)
/* 9914D4 80241CF4 8FB10024 */  lw        $s1, 0x24($sp)
/* 9914D8 80241CF8 8FB00020 */  lw        $s0, 0x20($sp)
/* 9914DC 80241CFC 24020002 */  addiu     $v0, $zero, 2
/* 9914E0 80241D00 03E00008 */  jr        $ra
/* 9914E4 80241D04 27BD0030 */   addiu    $sp, $sp, 0x30
