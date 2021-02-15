.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802415E0_D6FF90
/* D6FF90 802415E0 27BDFF10 */  addiu     $sp, $sp, -0xf0
/* D6FF94 802415E4 AFB100DC */  sw        $s1, 0xdc($sp)
/* D6FF98 802415E8 AFBF00E0 */  sw        $ra, 0xe0($sp)
/* D6FF9C 802415EC AFB000D8 */  sw        $s0, 0xd8($sp)
/* D6FFA0 802415F0 F7B400E8 */  sdc1      $f20, 0xe8($sp)
/* D6FFA4 802415F4 0C00E769 */  jal       func_80039DA4
/* D6FFA8 802415F8 0080882D */   daddu    $s1, $a0, $zero
/* D6FFAC 802415FC 44800000 */  mtc1      $zero, $f0
/* D6FFB0 80241600 3C03800A */  lui       $v1, %hi(D_8009A634)
/* D6FFB4 80241604 8463A634 */  lh        $v1, %lo(D_8009A634)($v1)
/* D6FFB8 80241608 C6220034 */  lwc1      $f2, 0x34($s1)
/* D6FFBC 8024160C 00031080 */  sll       $v0, $v1, 2
/* D6FFC0 80241610 00431021 */  addu      $v0, $v0, $v1
/* D6FFC4 80241614 00021080 */  sll       $v0, $v0, 2
/* D6FFC8 80241618 00431023 */  subu      $v0, $v0, $v1
/* D6FFCC 8024161C 000218C0 */  sll       $v1, $v0, 3
/* D6FFD0 80241620 00431021 */  addu      $v0, $v0, $v1
/* D6FFD4 80241624 000210C0 */  sll       $v0, $v0, 3
/* D6FFD8 80241628 44060000 */  mfc1      $a2, $f0
/* D6FFDC 8024162C 3C01800B */  lui       $at, %hi(D_800B1DEC)
/* D6FFE0 80241630 00220821 */  addu      $at, $at, $v0
/* D6FFE4 80241634 C4201DEC */  lwc1      $f0, %lo(D_800B1DEC)($at)
/* D6FFE8 80241638 3C013F80 */  lui       $at, 0x3f80
/* D6FFEC 8024163C 4481A000 */  mtc1      $at, $f20
/* D6FFF0 80241640 46001080 */  add.s     $f2, $f2, $f0
/* D6FFF4 80241644 4407A000 */  mfc1      $a3, $f20
/* D6FFF8 80241648 44051000 */  mfc1      $a1, $f2
/* D6FFFC 8024164C 27A40018 */  addiu     $a0, $sp, 0x18
/* D70000 80241650 0C019EC8 */  jal       guRotateF
/* D70004 80241654 AFA60010 */   sw       $a2, 0x10($sp)
/* D70008 80241658 3C013F36 */  lui       $at, 0x3f36
/* D7000C 8024165C 3421DB6E */  ori       $at, $at, 0xdb6e
/* D70010 80241660 44810000 */  mtc1      $at, $f0
/* D70014 80241664 27B00098 */  addiu     $s0, $sp, 0x98
/* D70018 80241668 44050000 */  mfc1      $a1, $f0
/* D7001C 8024166C 0200202D */  daddu     $a0, $s0, $zero
/* D70020 80241670 00A0302D */  daddu     $a2, $a1, $zero
/* D70024 80241674 0C019DF0 */  jal       guScaleF
/* D70028 80241678 00A0382D */   daddu    $a3, $a1, $zero
/* D7002C 8024167C 27A40018 */  addiu     $a0, $sp, 0x18
/* D70030 80241680 0200282D */  daddu     $a1, $s0, $zero
/* D70034 80241684 0C019D80 */  jal       guMtxCatF
/* D70038 80241688 0080302D */   daddu    $a2, $a0, $zero
/* D7003C 8024168C 27B00058 */  addiu     $s0, $sp, 0x58
/* D70040 80241690 8E250038 */  lw        $a1, 0x38($s1)
/* D70044 80241694 8E26003C */  lw        $a2, 0x3c($s1)
/* D70048 80241698 8E270040 */  lw        $a3, 0x40($s1)
/* D7004C 8024169C 0C019E40 */  jal       guTranslateF
/* D70050 802416A0 0200202D */   daddu    $a0, $s0, $zero
/* D70054 802416A4 27A40018 */  addiu     $a0, $sp, 0x18
/* D70058 802416A8 0200282D */  daddu     $a1, $s0, $zero
/* D7005C 802416AC 0C019D80 */  jal       guMtxCatF
/* D70060 802416B0 0080302D */   daddu    $a2, $a0, $zero
/* D70064 802416B4 8E250028 */  lw        $a1, 0x28($s1)
/* D70068 802416B8 4406A000 */  mfc1      $a2, $f20
/* D7006C 802416BC 0C0B76A3 */  jal       func_802DDA8C
/* D70070 802416C0 24040002 */   addiu    $a0, $zero, 2
/* D70074 802416C4 24040002 */  addiu     $a0, $zero, 2
/* D70078 802416C8 0000282D */  daddu     $a1, $zero, $zero
/* D7007C 802416CC 00A0302D */  daddu     $a2, $a1, $zero
/* D70080 802416D0 00A0382D */  daddu     $a3, $a1, $zero
/* D70084 802416D4 27A20018 */  addiu     $v0, $sp, 0x18
/* D70088 802416D8 0C0B7710 */  jal       render_sprite
/* D7008C 802416DC AFA20010 */   sw       $v0, 0x10($sp)
/* D70090 802416E0 8FBF00E0 */  lw        $ra, 0xe0($sp)
/* D70094 802416E4 8FB100DC */  lw        $s1, 0xdc($sp)
/* D70098 802416E8 8FB000D8 */  lw        $s0, 0xd8($sp)
/* D7009C 802416EC D7B400E8 */  ldc1      $f20, 0xe8($sp)
/* D700A0 802416F0 03E00008 */  jr        $ra
/* D700A4 802416F4 27BD00F0 */   addiu    $sp, $sp, 0xf0
