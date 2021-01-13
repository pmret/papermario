.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218020_47F0D0
/* 47F0D0 80218020 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 47F0D4 80218024 AFB20020 */  sw        $s2, 0x20($sp)
/* 47F0D8 80218028 0080902D */  daddu     $s2, $a0, $zero
/* 47F0DC 8021802C AFBF0024 */  sw        $ra, 0x24($sp)
/* 47F0E0 80218030 AFB1001C */  sw        $s1, 0x1c($sp)
/* 47F0E4 80218034 AFB00018 */  sw        $s0, 0x18($sp)
/* 47F0E8 80218038 8E440148 */  lw        $a0, 0x148($s2)
/* 47F0EC 8021803C 0C09A75B */  jal       get_actor
/* 47F0F0 80218040 00A0802D */   daddu    $s0, $a1, $zero
/* 47F0F4 80218044 1200002D */  beqz      $s0, .L802180FC
/* 47F0F8 80218048 0040882D */   daddu    $s1, $v0, $zero
/* 47F0FC 8021804C C6220018 */  lwc1      $f2, 0x18($s1)
/* 47F100 80218050 C6200144 */  lwc1      $f0, 0x144($s1)
/* 47F104 80218054 46001081 */  sub.s     $f2, $f2, $f0
/* 47F108 80218058 46021082 */  mul.s     $f2, $f2, $f2
/* 47F10C 8021805C 00000000 */  nop
/* 47F110 80218060 C626001C */  lwc1      $f6, 0x1c($s1)
/* 47F114 80218064 C6200148 */  lwc1      $f0, 0x148($s1)
/* 47F118 80218068 46003181 */  sub.s     $f6, $f6, $f0
/* 47F11C 8021806C 46063182 */  mul.s     $f6, $f6, $f6
/* 47F120 80218070 00000000 */  nop
/* 47F124 80218074 C624014C */  lwc1      $f4, 0x14c($s1)
/* 47F128 80218078 C6200020 */  lwc1      $f0, 0x20($s1)
/* 47F12C 8021807C 46040001 */  sub.s     $f0, $f0, $f4
/* 47F130 80218080 46000002 */  mul.s     $f0, $f0, $f0
/* 47F134 80218084 00000000 */  nop
/* 47F138 80218088 46061080 */  add.s     $f2, $f2, $f6
/* 47F13C 8021808C 46001300 */  add.s     $f12, $f2, $f0
/* 47F140 80218090 46006104 */  sqrt.s    $f4, $f12
/* 47F144 80218094 46042032 */  c.eq.s    $f4, $f4
/* 47F148 80218098 00000000 */  nop
/* 47F14C 8021809C 45010004 */  bc1t      .L802180B0
/* 47F150 802180A0 00000000 */   nop
/* 47F154 802180A4 0C0187BC */  jal       sqrtf
/* 47F158 802180A8 00000000 */   nop
/* 47F15C 802180AC 46000106 */  mov.s     $f4, $f0
.L802180B0:
/* 47F160 802180B0 C620004C */  lwc1      $f0, 0x4c($s1)
/* 47F164 802180B4 3C013F00 */  lui       $at, 0x3f00
/* 47F168 802180B8 44811000 */  mtc1      $at, $f2
/* 47F16C 802180BC 46002003 */  div.s     $f0, $f4, $f0
/* 47F170 802180C0 46020002 */  mul.s     $f0, $f0, $f2
/* 47F174 802180C4 00000000 */  nop
/* 47F178 802180C8 3C013F80 */  lui       $at, 0x3f80
/* 47F17C 802180CC 44811000 */  mtc1      $at, $f2
/* 47F180 802180D0 00000000 */  nop
/* 47F184 802180D4 46020000 */  add.s     $f0, $f0, $f2
/* 47F188 802180D8 4600020D */  trunc.w.s $f8, $f0
/* 47F18C 802180DC E6480070 */  swc1      $f8, 0x70($s2)
/* 47F190 802180E0 C620014C */  lwc1      $f0, 0x14c($s1)
/* 47F194 802180E4 24040359 */  addiu     $a0, $zero, 0x359
/* 47F198 802180E8 E7A00010 */  swc1      $f0, 0x10($sp)
/* 47F19C 802180EC 8E260144 */  lw        $a2, 0x144($s1)
/* 47F1A0 802180F0 8E270148 */  lw        $a3, 0x148($s1)
/* 47F1A4 802180F4 0C052757 */  jal       play_sound_at_position
/* 47F1A8 802180F8 0000282D */   daddu    $a1, $zero, $zero
.L802180FC:
/* 47F1AC 802180FC 8E420070 */  lw        $v0, 0x70($s2)
/* 47F1B0 80218100 0040182D */  daddu     $v1, $v0, $zero
/* 47F1B4 80218104 2442FFFF */  addiu     $v0, $v0, -1
/* 47F1B8 80218108 1C60000A */  bgtz      $v1, .L80218134
/* 47F1BC 8021810C AE420070 */   sw       $v0, 0x70($s2)
/* 47F1C0 80218110 C620014C */  lwc1      $f0, 0x14c($s1)
/* 47F1C4 80218114 24040759 */  addiu     $a0, $zero, 0x759
/* 47F1C8 80218118 E7A00010 */  swc1      $f0, 0x10($sp)
/* 47F1CC 8021811C 8E260144 */  lw        $a2, 0x144($s1)
/* 47F1D0 80218120 8E270148 */  lw        $a3, 0x148($s1)
/* 47F1D4 80218124 0C052757 */  jal       play_sound_at_position
/* 47F1D8 80218128 0000282D */   daddu    $a1, $zero, $zero
/* 47F1DC 8021812C 0808604E */  j         .L80218138
/* 47F1E0 80218130 24020002 */   addiu    $v0, $zero, 2
.L80218134:
/* 47F1E4 80218134 0000102D */  daddu     $v0, $zero, $zero
.L80218138:
/* 47F1E8 80218138 8FBF0024 */  lw        $ra, 0x24($sp)
/* 47F1EC 8021813C 8FB20020 */  lw        $s2, 0x20($sp)
/* 47F1F0 80218140 8FB1001C */  lw        $s1, 0x1c($sp)
/* 47F1F4 80218144 8FB00018 */  lw        $s0, 0x18($sp)
/* 47F1F8 80218148 03E00008 */  jr        $ra
/* 47F1FC 8021814C 27BD0028 */   addiu    $sp, $sp, 0x28
