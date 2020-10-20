.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240CA8_B534D8
/* B534D8 80240CA8 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* B534DC 80240CAC AFB3001C */  sw        $s3, 0x1c($sp)
/* B534E0 80240CB0 0080982D */  daddu     $s3, $a0, $zero
/* B534E4 80240CB4 AFBF0020 */  sw        $ra, 0x20($sp)
/* B534E8 80240CB8 AFB20018 */  sw        $s2, 0x18($sp)
/* B534EC 80240CBC AFB10014 */  sw        $s1, 0x14($sp)
/* B534F0 80240CC0 AFB00010 */  sw        $s0, 0x10($sp)
/* B534F4 80240CC4 8E720148 */  lw        $s2, 0x148($s3)
/* B534F8 80240CC8 86440008 */  lh        $a0, 8($s2)
/* B534FC 80240CCC 0C00EABB */  jal       get_npc_unsafe
/* B53500 80240CD0 00A0882D */   daddu    $s1, $a1, $zero
/* B53504 80240CD4 8E240008 */  lw        $a0, 8($s1)
/* B53508 80240CD8 0040802D */  daddu     $s0, $v0, $zero
/* B5350C 80240CDC 00041FC2 */  srl       $v1, $a0, 0x1f
/* B53510 80240CE0 00832021 */  addu      $a0, $a0, $v1
/* B53514 80240CE4 00042043 */  sra       $a0, $a0, 1
/* B53518 80240CE8 0C00A67F */  jal       rand_int
/* B5351C 80240CEC 24840001 */   addiu    $a0, $a0, 1
/* B53520 80240CF0 8E230008 */  lw        $v1, 8($s1)
/* B53524 80240CF4 240400B4 */  addiu     $a0, $zero, 0xb4
/* B53528 80240CF8 00032FC2 */  srl       $a1, $v1, 0x1f
/* B5352C 80240CFC 00651821 */  addu      $v1, $v1, $a1
/* B53530 80240D00 00031843 */  sra       $v1, $v1, 1
/* B53534 80240D04 00621821 */  addu      $v1, $v1, $v0
/* B53538 80240D08 0C00A67F */  jal       rand_int
/* B5353C 80240D0C A603008E */   sh       $v1, 0x8e($s0)
/* B53540 80240D10 C60C000C */  lwc1      $f12, 0xc($s0)
/* B53544 80240D14 44820000 */  mtc1      $v0, $f0
/* B53548 80240D18 00000000 */  nop       
/* B5354C 80240D1C 46800020 */  cvt.s.w   $f0, $f0
/* B53550 80240D20 46006300 */  add.s     $f12, $f12, $f0
/* B53554 80240D24 3C0142B4 */  lui       $at, 0x42b4
/* B53558 80240D28 44810000 */  mtc1      $at, $f0
/* B5355C 80240D2C 0C00A6C9 */  jal       clamp_angle
/* B53560 80240D30 46006301 */   sub.s    $f12, $f12, $f0
/* B53564 80240D34 E600000C */  swc1      $f0, 0xc($s0)
/* B53568 80240D38 8E4200CC */  lw        $v0, 0xcc($s2)
/* B5356C 80240D3C 8C420000 */  lw        $v0, ($v0)
/* B53570 80240D40 AE020028 */  sw        $v0, 0x28($s0)
/* B53574 80240D44 24020003 */  addiu     $v0, $zero, 3
/* B53578 80240D48 AE620070 */  sw        $v0, 0x70($s3)
/* B5357C 80240D4C 8FBF0020 */  lw        $ra, 0x20($sp)
/* B53580 80240D50 8FB3001C */  lw        $s3, 0x1c($sp)
/* B53584 80240D54 8FB20018 */  lw        $s2, 0x18($sp)
/* B53588 80240D58 8FB10014 */  lw        $s1, 0x14($sp)
/* B5358C 80240D5C 8FB00010 */  lw        $s0, 0x10($sp)
/* B53590 80240D60 03E00008 */  jr        $ra
/* B53594 80240D64 27BD0028 */   addiu    $sp, $sp, 0x28
