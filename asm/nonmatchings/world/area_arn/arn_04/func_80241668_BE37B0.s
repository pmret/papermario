.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241668_BE4E18
/* BE4E18 80241668 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* BE4E1C 8024166C AFB3001C */  sw        $s3, 0x1c($sp)
/* BE4E20 80241670 0080982D */  daddu     $s3, $a0, $zero
/* BE4E24 80241674 AFBF0020 */  sw        $ra, 0x20($sp)
/* BE4E28 80241678 AFB20018 */  sw        $s2, 0x18($sp)
/* BE4E2C 8024167C AFB10014 */  sw        $s1, 0x14($sp)
/* BE4E30 80241680 AFB00010 */  sw        $s0, 0x10($sp)
/* BE4E34 80241684 8E720148 */  lw        $s2, 0x148($s3)
/* BE4E38 80241688 86440008 */  lh        $a0, 8($s2)
/* BE4E3C 8024168C 0C00EABB */  jal       get_npc_unsafe
/* BE4E40 80241690 00A0882D */   daddu    $s1, $a1, $zero
/* BE4E44 80241694 8E240008 */  lw        $a0, 8($s1)
/* BE4E48 80241698 0040802D */  daddu     $s0, $v0, $zero
/* BE4E4C 8024169C 00041FC2 */  srl       $v1, $a0, 0x1f
/* BE4E50 802416A0 00832021 */  addu      $a0, $a0, $v1
/* BE4E54 802416A4 00042043 */  sra       $a0, $a0, 1
/* BE4E58 802416A8 0C00A67F */  jal       rand_int
/* BE4E5C 802416AC 24840001 */   addiu    $a0, $a0, 1
/* BE4E60 802416B0 8E230008 */  lw        $v1, 8($s1)
/* BE4E64 802416B4 240400B4 */  addiu     $a0, $zero, 0xb4
/* BE4E68 802416B8 00032FC2 */  srl       $a1, $v1, 0x1f
/* BE4E6C 802416BC 00651821 */  addu      $v1, $v1, $a1
/* BE4E70 802416C0 00031843 */  sra       $v1, $v1, 1
/* BE4E74 802416C4 00621821 */  addu      $v1, $v1, $v0
/* BE4E78 802416C8 0C00A67F */  jal       rand_int
/* BE4E7C 802416CC A603008E */   sh       $v1, 0x8e($s0)
/* BE4E80 802416D0 C60C000C */  lwc1      $f12, 0xc($s0)
/* BE4E84 802416D4 44820000 */  mtc1      $v0, $f0
/* BE4E88 802416D8 00000000 */  nop       
/* BE4E8C 802416DC 46800020 */  cvt.s.w   $f0, $f0
/* BE4E90 802416E0 46006300 */  add.s     $f12, $f12, $f0
/* BE4E94 802416E4 3C0142B4 */  lui       $at, 0x42b4
/* BE4E98 802416E8 44810000 */  mtc1      $at, $f0
/* BE4E9C 802416EC 0C00A6C9 */  jal       clamp_angle
/* BE4EA0 802416F0 46006301 */   sub.s    $f12, $f12, $f0
/* BE4EA4 802416F4 E600000C */  swc1      $f0, 0xc($s0)
/* BE4EA8 802416F8 8E4200CC */  lw        $v0, 0xcc($s2)
/* BE4EAC 802416FC 8C420000 */  lw        $v0, ($v0)
/* BE4EB0 80241700 AE020028 */  sw        $v0, 0x28($s0)
/* BE4EB4 80241704 24020003 */  addiu     $v0, $zero, 3
/* BE4EB8 80241708 AE620070 */  sw        $v0, 0x70($s3)
/* BE4EBC 8024170C 8FBF0020 */  lw        $ra, 0x20($sp)
/* BE4EC0 80241710 8FB3001C */  lw        $s3, 0x1c($sp)
/* BE4EC4 80241714 8FB20018 */  lw        $s2, 0x18($sp)
/* BE4EC8 80241718 8FB10014 */  lw        $s1, 0x14($sp)
/* BE4ECC 8024171C 8FB00010 */  lw        $s0, 0x10($sp)
/* BE4ED0 80241720 03E00008 */  jr        $ra
/* BE4ED4 80241724 27BD0028 */   addiu    $sp, $sp, 0x28
