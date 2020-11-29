.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802403B8_B1CE08
/* B1CE08 802403B8 27BDFEA0 */  addiu     $sp, $sp, -0x160
/* B1CE0C 802403BC F7B40138 */  sdc1      $f20, 0x138($sp)
/* B1CE10 802403C0 4480A000 */  mtc1      $zero, $f20
/* B1CE14 802403C4 3C03800A */  lui       $v1, %hi(D_8009A634)
/* B1CE18 802403C8 8463A634 */  lh        $v1, %lo(D_8009A634)($v1)
/* B1CE1C 802403CC F7BC0158 */  sdc1      $f28, 0x158($sp)
/* B1CE20 802403D0 3C01BF80 */  lui       $at, 0xbf80
/* B1CE24 802403D4 4481E000 */  mtc1      $at, $f28
/* B1CE28 802403D8 AFB20128 */  sw        $s2, 0x128($sp)
/* B1CE2C 802403DC 0080902D */  daddu     $s2, $a0, $zero
/* B1CE30 802403E0 AFB10124 */  sw        $s1, 0x124($sp)
/* B1CE34 802403E4 27B100A0 */  addiu     $s1, $sp, 0xa0
/* B1CE38 802403E8 AFBF0134 */  sw        $ra, 0x134($sp)
/* B1CE3C 802403EC AFB40130 */  sw        $s4, 0x130($sp)
/* B1CE40 802403F0 AFB3012C */  sw        $s3, 0x12c($sp)
/* B1CE44 802403F4 AFB00120 */  sw        $s0, 0x120($sp)
/* B1CE48 802403F8 F7BA0150 */  sdc1      $f26, 0x150($sp)
/* B1CE4C 802403FC F7B80148 */  sdc1      $f24, 0x148($sp)
/* B1CE50 80240400 F7B60140 */  sdc1      $f22, 0x140($sp)
/* B1CE54 80240404 00031080 */  sll       $v0, $v1, 2
/* B1CE58 80240408 00431021 */  addu      $v0, $v0, $v1
/* B1CE5C 8024040C 00021080 */  sll       $v0, $v0, 2
/* B1CE60 80240410 00431023 */  subu      $v0, $v0, $v1
/* B1CE64 80240414 000218C0 */  sll       $v1, $v0, 3
/* B1CE68 80240418 00431021 */  addu      $v0, $v0, $v1
/* B1CE6C 8024041C 000210C0 */  sll       $v0, $v0, 3
/* B1CE70 80240420 4406A000 */  mfc1      $a2, $f20
/* B1CE74 80240424 3C01800B */  lui       $at, %hi(D_800B1DEC)
/* B1CE78 80240428 00220821 */  addu      $at, $at, $v0
/* B1CE7C 8024042C C4361DEC */  lwc1      $f22, %lo(D_800B1DEC)($at)
/* B1CE80 80240430 4407E000 */  mfc1      $a3, $f28
/* B1CE84 80240434 4600B587 */  neg.s     $f22, $f22
/* B1CE88 80240438 4405B000 */  mfc1      $a1, $f22
/* B1CE8C 8024043C 0220202D */  daddu     $a0, $s1, $zero
/* B1CE90 80240440 0C019EC8 */  jal       guRotateF
/* B1CE94 80240444 E7B40010 */   swc1     $f20, 0x10($sp)
/* B1CE98 80240448 C64C008C */  lwc1      $f12, 0x8c($s2)
/* B1CE9C 8024044C 0C00A6C9 */  jal       clamp_angle
/* B1CEA0 80240450 00000000 */   nop      
/* B1CEA4 80240454 44050000 */  mfc1      $a1, $f0
/* B1CEA8 80240458 4406A000 */  mfc1      $a2, $f20
/* B1CEAC 8024045C 4407A000 */  mfc1      $a3, $f20
/* B1CEB0 80240460 3C013F80 */  lui       $at, 0x3f80
/* B1CEB4 80240464 4481C000 */  mtc1      $at, $f24
/* B1CEB8 80240468 27A40020 */  addiu     $a0, $sp, 0x20
/* B1CEBC 8024046C 0C019EC8 */  jal       guRotateF
/* B1CEC0 80240470 E7B80010 */   swc1     $f24, 0x10($sp)
/* B1CEC4 80240474 0220202D */  daddu     $a0, $s1, $zero
/* B1CEC8 80240478 27A50020 */  addiu     $a1, $sp, 0x20
/* B1CECC 8024047C 0C019D80 */  jal       guMtxCatF
/* B1CED0 80240480 00A0302D */   daddu    $a2, $a1, $zero
/* B1CED4 80240484 4405B000 */  mfc1      $a1, $f22
/* B1CED8 80240488 4406A000 */  mfc1      $a2, $f20
/* B1CEDC 8024048C 4407C000 */  mfc1      $a3, $f24
/* B1CEE0 80240490 0220202D */  daddu     $a0, $s1, $zero
/* B1CEE4 80240494 0C019EC8 */  jal       guRotateF
/* B1CEE8 80240498 E7B40010 */   swc1     $f20, 0x10($sp)
/* B1CEEC 8024049C 27A40020 */  addiu     $a0, $sp, 0x20
/* B1CEF0 802404A0 0220282D */  daddu     $a1, $s1, $zero
/* B1CEF4 802404A4 0C019D80 */  jal       guMtxCatF
/* B1CEF8 802404A8 0080302D */   daddu    $a2, $a0, $zero
/* B1CEFC 802404AC E7B40010 */  swc1      $f20, 0x10($sp)
/* B1CF00 802404B0 8E4500A8 */  lw        $a1, 0xa8($s2)
/* B1CF04 802404B4 4406A000 */  mfc1      $a2, $f20
/* B1CF08 802404B8 4407C000 */  mfc1      $a3, $f24
/* B1CF0C 802404BC 0C019EC8 */  jal       guRotateF
/* B1CF10 802404C0 0220202D */   daddu    $a0, $s1, $zero
/* B1CF14 802404C4 27A40020 */  addiu     $a0, $sp, 0x20
/* B1CF18 802404C8 0220282D */  daddu     $a1, $s1, $zero
/* B1CF1C 802404CC 0C019D80 */  jal       guMtxCatF
/* B1CF20 802404D0 0080302D */   daddu    $a2, $a0, $zero
/* B1CF24 802404D4 27B300E0 */  addiu     $s3, $sp, 0xe0
/* B1CF28 802404D8 3C013F36 */  lui       $at, 0x3f36
/* B1CF2C 802404DC 3421DB6E */  ori       $at, $at, 0xdb6e
/* B1CF30 802404E0 4481D000 */  mtc1      $at, $f26
/* B1CF34 802404E4 3C06BF36 */  lui       $a2, 0xbf36
/* B1CF38 802404E8 34C6DB6E */  ori       $a2, $a2, 0xdb6e
/* B1CF3C 802404EC 4405D000 */  mfc1      $a1, $f26
/* B1CF40 802404F0 4407D000 */  mfc1      $a3, $f26
/* B1CF44 802404F4 0C019DF0 */  jal       guScaleF
/* B1CF48 802404F8 0260202D */   daddu    $a0, $s3, $zero
/* B1CF4C 802404FC 27A40020 */  addiu     $a0, $sp, 0x20
/* B1CF50 80240500 0260282D */  daddu     $a1, $s3, $zero
/* B1CF54 80240504 0C019D80 */  jal       guMtxCatF
/* B1CF58 80240508 0080302D */   daddu    $a2, $a0, $zero
/* B1CF5C 8024050C 27B40060 */  addiu     $s4, $sp, 0x60
/* B1CF60 80240510 8E450028 */  lw        $a1, 0x28($s2)
/* B1CF64 80240514 C640002C */  lwc1      $f0, 0x2c($s2)
/* B1CF68 80240518 8E470030 */  lw        $a3, 0x30($s2)
/* B1CF6C 8024051C 46000007 */  neg.s     $f0, $f0
/* B1CF70 80240520 44060000 */  mfc1      $a2, $f0
/* B1CF74 80240524 0C019E40 */  jal       guTranslateF
/* B1CF78 80240528 0280202D */   daddu    $a0, $s4, $zero
/* B1CF7C 8024052C 27A40020 */  addiu     $a0, $sp, 0x20
/* B1CF80 80240530 0280282D */  daddu     $a1, $s4, $zero
/* B1CF84 80240534 0C019D80 */  jal       guMtxCatF
/* B1CF88 80240538 0080302D */   daddu    $a2, $a0, $zero
/* B1CF8C 8024053C 24040001 */  addiu     $a0, $zero, 1
/* B1CF90 80240540 0000282D */  daddu     $a1, $zero, $zero
/* B1CF94 80240544 00A0302D */  daddu     $a2, $a1, $zero
/* B1CF98 80240548 00A0382D */  daddu     $a3, $a1, $zero
/* B1CF9C 8024054C 27B00020 */  addiu     $s0, $sp, 0x20
/* B1CFA0 80240550 0C0B7710 */  jal       render_sprite
/* B1CFA4 80240554 AFB00010 */   sw       $s0, 0x10($sp)
/* B1CFA8 80240558 4405B000 */  mfc1      $a1, $f22
/* B1CFAC 8024055C 4406A000 */  mfc1      $a2, $f20
/* B1CFB0 80240560 4407E000 */  mfc1      $a3, $f28
/* B1CFB4 80240564 0220202D */  daddu     $a0, $s1, $zero
/* B1CFB8 80240568 0C019EC8 */  jal       guRotateF
/* B1CFBC 8024056C E7B40010 */   swc1     $f20, 0x10($sp)
/* B1CFC0 80240570 C64C008C */  lwc1      $f12, 0x8c($s2)
/* B1CFC4 80240574 0C00A6C9 */  jal       clamp_angle
/* B1CFC8 80240578 00000000 */   nop      
/* B1CFCC 8024057C 44050000 */  mfc1      $a1, $f0
/* B1CFD0 80240580 4406A000 */  mfc1      $a2, $f20
/* B1CFD4 80240584 4407A000 */  mfc1      $a3, $f20
/* B1CFD8 80240588 0200202D */  daddu     $a0, $s0, $zero
/* B1CFDC 8024058C 0C019EC8 */  jal       guRotateF
/* B1CFE0 80240590 E7B80010 */   swc1     $f24, 0x10($sp)
/* B1CFE4 80240594 0220202D */  daddu     $a0, $s1, $zero
/* B1CFE8 80240598 0200282D */  daddu     $a1, $s0, $zero
/* B1CFEC 8024059C 0C019D80 */  jal       guMtxCatF
/* B1CFF0 802405A0 0200302D */   daddu    $a2, $s0, $zero
/* B1CFF4 802405A4 4405B000 */  mfc1      $a1, $f22
/* B1CFF8 802405A8 4406A000 */  mfc1      $a2, $f20
/* B1CFFC 802405AC 4407C000 */  mfc1      $a3, $f24
/* B1D000 802405B0 0220202D */  daddu     $a0, $s1, $zero
/* B1D004 802405B4 0C019EC8 */  jal       guRotateF
/* B1D008 802405B8 E7B40010 */   swc1     $f20, 0x10($sp)
/* B1D00C 802405BC 0200202D */  daddu     $a0, $s0, $zero
/* B1D010 802405C0 0220282D */  daddu     $a1, $s1, $zero
/* B1D014 802405C4 0C019D80 */  jal       guMtxCatF
/* B1D018 802405C8 0200302D */   daddu    $a2, $s0, $zero
/* B1D01C 802405CC E7B40010 */  swc1      $f20, 0x10($sp)
/* B1D020 802405D0 8E4500A8 */  lw        $a1, 0xa8($s2)
/* B1D024 802405D4 4406A000 */  mfc1      $a2, $f20
/* B1D028 802405D8 4407C000 */  mfc1      $a3, $f24
/* B1D02C 802405DC 0C019EC8 */  jal       guRotateF
/* B1D030 802405E0 0220202D */   daddu    $a0, $s1, $zero
/* B1D034 802405E4 0200202D */  daddu     $a0, $s0, $zero
/* B1D038 802405E8 0220282D */  daddu     $a1, $s1, $zero
/* B1D03C 802405EC 0C019D80 */  jal       guMtxCatF
/* B1D040 802405F0 0200302D */   daddu    $a2, $s0, $zero
/* B1D044 802405F4 4405D000 */  mfc1      $a1, $f26
/* B1D048 802405F8 0260202D */  daddu     $a0, $s3, $zero
/* B1D04C 802405FC 00A0302D */  daddu     $a2, $a1, $zero
/* B1D050 80240600 0C019DF0 */  jal       guScaleF
/* B1D054 80240604 00A0382D */   daddu    $a3, $a1, $zero
/* B1D058 80240608 0200202D */  daddu     $a0, $s0, $zero
/* B1D05C 8024060C 0260282D */  daddu     $a1, $s3, $zero
/* B1D060 80240610 0C019D80 */  jal       guMtxCatF
/* B1D064 80240614 0200302D */   daddu    $a2, $s0, $zero
/* B1D068 80240618 8E450028 */  lw        $a1, 0x28($s2)
/* B1D06C 8024061C 8E46002C */  lw        $a2, 0x2c($s2)
/* B1D070 80240620 4407A000 */  mfc1      $a3, $f20
/* B1D074 80240624 0C019E40 */  jal       guTranslateF
/* B1D078 80240628 0280202D */   daddu    $a0, $s4, $zero
/* B1D07C 8024062C 0200202D */  daddu     $a0, $s0, $zero
/* B1D080 80240630 0280282D */  daddu     $a1, $s4, $zero
/* B1D084 80240634 0C019D80 */  jal       guMtxCatF
/* B1D088 80240638 0200302D */   daddu    $a2, $s0, $zero
/* B1D08C 8024063C 24050007 */  addiu     $a1, $zero, 7
/* B1D090 80240640 240600FF */  addiu     $a2, $zero, 0xff
/* B1D094 80240644 00C0382D */  daddu     $a3, $a2, $zero
/* B1D098 80240648 8E5100A4 */  lw        $s1, 0xa4($s2)
/* B1D09C 8024064C 00C0102D */  daddu     $v0, $a2, $zero
/* B1D0A0 80240650 AFA20010 */  sw        $v0, 0x10($sp)
/* B1D0A4 80240654 24020014 */  addiu     $v0, $zero, 0x14
/* B1D0A8 80240658 AFA20014 */  sw        $v0, 0x14($sp)
/* B1D0AC 8024065C AFA00018 */  sw        $zero, 0x18($sp)
/* B1D0B0 80240660 0C0B77FE */  jal       func_802DDFF8
/* B1D0B4 80240664 0220202D */   daddu    $a0, $s1, $zero
/* B1D0B8 80240668 24040001 */  addiu     $a0, $zero, 1
/* B1D0BC 8024066C 0000282D */  daddu     $a1, $zero, $zero
/* B1D0C0 80240670 00A0302D */  daddu     $a2, $a1, $zero
/* B1D0C4 80240674 00A0382D */  daddu     $a3, $a1, $zero
/* B1D0C8 80240678 0C0B7710 */  jal       render_sprite
/* B1D0CC 8024067C AFB00010 */   sw       $s0, 0x10($sp)
/* B1D0D0 80240680 0220202D */  daddu     $a0, $s1, $zero
/* B1D0D4 80240684 0000282D */  daddu     $a1, $zero, $zero
/* B1D0D8 80240688 00A0302D */  daddu     $a2, $a1, $zero
/* B1D0DC 8024068C 00A0382D */  daddu     $a3, $a1, $zero
/* B1D0E0 80240690 AFA00010 */  sw        $zero, 0x10($sp)
/* B1D0E4 80240694 AFA00014 */  sw        $zero, 0x14($sp)
/* B1D0E8 80240698 0C0B77FE */  jal       func_802DDFF8
/* B1D0EC 8024069C AFA00018 */   sw       $zero, 0x18($sp)
/* B1D0F0 802406A0 8FBF0134 */  lw        $ra, 0x134($sp)
/* B1D0F4 802406A4 8FB40130 */  lw        $s4, 0x130($sp)
/* B1D0F8 802406A8 8FB3012C */  lw        $s3, 0x12c($sp)
/* B1D0FC 802406AC 8FB20128 */  lw        $s2, 0x128($sp)
/* B1D100 802406B0 8FB10124 */  lw        $s1, 0x124($sp)
/* B1D104 802406B4 8FB00120 */  lw        $s0, 0x120($sp)
/* B1D108 802406B8 D7BC0158 */  ldc1      $f28, 0x158($sp)
/* B1D10C 802406BC D7BA0150 */  ldc1      $f26, 0x150($sp)
/* B1D110 802406C0 D7B80148 */  ldc1      $f24, 0x148($sp)
/* B1D114 802406C4 D7B60140 */  ldc1      $f22, 0x140($sp)
/* B1D118 802406C8 D7B40138 */  ldc1      $f20, 0x138($sp)
/* B1D11C 802406CC 03E00008 */  jr        $ra
/* B1D120 802406D0 27BD0160 */   addiu    $sp, $sp, 0x160
