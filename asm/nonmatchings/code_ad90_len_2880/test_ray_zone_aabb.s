.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel test_ray_zone_aabb
/* B858 80030458 27BDFFA0 */  addiu     $sp, $sp, -0x60
/* B85C 8003045C 3C0146FF */  lui       $at, 0x46ff
/* B860 80030460 3421FE00 */  ori       $at, $at, 0xfe00
/* B864 80030464 44811000 */  mtc1      $at, $f2
/* B868 80030468 44802000 */  mtc1      $zero, $f4
/* B86C 8003046C 3C01BF80 */  lui       $at, 0xbf80
/* B870 80030470 44810000 */  mtc1      $at, $f0
/* B874 80030474 44072000 */  mfc1      $a3, $f4
/* B878 80030478 27A20038 */  addiu     $v0, $sp, 0x38
/* B87C 8003047C AFBF0058 */  sw        $ra, 0x58($sp)
/* B880 80030480 E7A20044 */  swc1      $f2, 0x44($sp)
/* B884 80030484 AFA20018 */  sw        $v0, 0x18($sp)
/* B888 80030488 27A2003C */  addiu     $v0, $sp, 0x3c
/* B88C 8003048C AFA2001C */  sw        $v0, 0x1c($sp)
/* B890 80030490 27A20040 */  addiu     $v0, $sp, 0x40
/* B894 80030494 AFA20020 */  sw        $v0, 0x20($sp)
/* B898 80030498 27A20044 */  addiu     $v0, $sp, 0x44
/* B89C 8003049C AFA20024 */  sw        $v0, 0x24($sp)
/* B8A0 800304A0 27A20048 */  addiu     $v0, $sp, 0x48
/* B8A4 800304A4 AFA20028 */  sw        $v0, 0x28($sp)
/* B8A8 800304A8 27A2004C */  addiu     $v0, $sp, 0x4c
/* B8AC 800304AC AFA2002C */  sw        $v0, 0x2c($sp)
/* B8B0 800304B0 27A20050 */  addiu     $v0, $sp, 0x50
/* B8B4 800304B4 E7A00010 */  swc1      $f0, 0x10($sp)
/* B8B8 800304B8 E7A40014 */  swc1      $f4, 0x14($sp)
/* B8BC 800304BC 0C017449 */  jal       test_ray_zones
/* B8C0 800304C0 AFA20030 */   sw       $v0, 0x30($sp)
/* B8C4 800304C4 0040182D */  daddu     $v1, $v0, $zero
/* B8C8 800304C8 04600008 */  bltz      $v1, .L800304EC
/* B8CC 800304CC 000310C0 */   sll      $v0, $v1, 3
/* B8D0 800304D0 00431023 */  subu      $v0, $v0, $v1
/* B8D4 800304D4 3C03800E */  lui       $v1, 0x800e
/* B8D8 800304D8 8C6391D4 */  lw        $v1, -0x6e2c($v1)
/* B8DC 800304DC 00021080 */  sll       $v0, $v0, 2
/* B8E0 800304E0 00431021 */  addu      $v0, $v0, $v1
/* B8E4 800304E4 0800C13C */  j         .L800304F0
/* B8E8 800304E8 8C420010 */   lw       $v0, 0x10($v0)
.L800304EC:
/* B8EC 800304EC 0000102D */  daddu     $v0, $zero, $zero
.L800304F0:
/* B8F0 800304F0 8FBF0058 */  lw        $ra, 0x58($sp)
/* B8F4 800304F4 03E00008 */  jr        $ra
/* B8F8 800304F8 27BD0060 */   addiu    $sp, $sp, 0x60
