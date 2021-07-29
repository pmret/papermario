.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel test_ray_zone
/* D610 80032210 27BDFFA0 */  addiu     $sp, $sp, -0x60
/* D614 80032214 AFB00058 */  sw        $s0, 0x58($sp)
/* D618 80032218 00E0802D */  daddu     $s0, $a3, $zero
/* D61C 8003221C 3C0146FF */  lui       $at, 0x46ff
/* D620 80032220 3421FE00 */  ori       $at, $at, 0xfe00
/* D624 80032224 44811000 */  mtc1      $at, $f2
/* D628 80032228 44802000 */  mtc1      $zero, $f4
/* D62C 8003222C 3C01BF80 */  lui       $at, 0xbf80
/* D630 80032230 44810000 */  mtc1      $at, $f0
/* D634 80032234 44072000 */  mfc1      $a3, $f4
/* D638 80032238 27A20038 */  addiu     $v0, $sp, 0x38
/* D63C 8003223C AFBF005C */  sw        $ra, 0x5c($sp)
/* D640 80032240 E7A20044 */  swc1      $f2, 0x44($sp)
/* D644 80032244 AFA20018 */  sw        $v0, 0x18($sp)
/* D648 80032248 27A2003C */  addiu     $v0, $sp, 0x3c
/* D64C 8003224C AFA2001C */  sw        $v0, 0x1c($sp)
/* D650 80032250 27A20040 */  addiu     $v0, $sp, 0x40
/* D654 80032254 AFA20020 */  sw        $v0, 0x20($sp)
/* D658 80032258 27A20044 */  addiu     $v0, $sp, 0x44
/* D65C 8003225C AFA20024 */  sw        $v0, 0x24($sp)
/* D660 80032260 27A20048 */  addiu     $v0, $sp, 0x48
/* D664 80032264 AFA20028 */  sw        $v0, 0x28($sp)
/* D668 80032268 27A2004C */  addiu     $v0, $sp, 0x4c
/* D66C 8003226C AFA2002C */  sw        $v0, 0x2c($sp)
/* D670 80032270 27A20050 */  addiu     $v0, $sp, 0x50
/* D674 80032274 E7A00010 */  swc1      $f0, 0x10($sp)
/* D678 80032278 E7A40014 */  swc1      $f4, 0x14($sp)
/* D67C 8003227C 0C017449 */  jal       test_ray_zones
/* D680 80032280 AFA20030 */   sw       $v0, 0x30($sp)
/* D684 80032284 0040202D */  daddu     $a0, $v0, $zero
/* D688 80032288 04800010 */  bltz      $a0, .L800322CC
/* D68C 8003228C 0000102D */   daddu    $v0, $zero, $zero
/* D690 80032290 12000007 */  beqz      $s0, .L800322B0
/* D694 80032294 000410C0 */   sll      $v0, $a0, 3
/* D698 80032298 00441023 */  subu      $v0, $v0, $a0
/* D69C 8003229C 3C03800E */  lui       $v1, %hi(D_800D91D4)
/* D6A0 800322A0 8C6391D4 */  lw        $v1, %lo(D_800D91D4)($v1)
/* D6A4 800322A4 00021080 */  sll       $v0, $v0, 2
/* D6A8 800322A8 00621821 */  addu      $v1, $v1, $v0
/* D6AC 800322AC AE030000 */  sw        $v1, ($s0)
.L800322B0:
/* D6B0 800322B0 000410C0 */  sll       $v0, $a0, 3
/* D6B4 800322B4 00441023 */  subu      $v0, $v0, $a0
/* D6B8 800322B8 3C03800E */  lui       $v1, %hi(D_800D91D4)
/* D6BC 800322BC 8C6391D4 */  lw        $v1, %lo(D_800D91D4)($v1)
/* D6C0 800322C0 00021080 */  sll       $v0, $v0, 2
/* D6C4 800322C4 00431021 */  addu      $v0, $v0, $v1
/* D6C8 800322C8 8C420010 */  lw        $v0, 0x10($v0)
.L800322CC:
/* D6CC 800322CC 8FBF005C */  lw        $ra, 0x5c($sp)
/* D6D0 800322D0 8FB00058 */  lw        $s0, 0x58($sp)
/* D6D4 800322D4 03E00008 */  jr        $ra
/* D6D8 800322D8 27BD0060 */   addiu    $sp, $sp, 0x60
