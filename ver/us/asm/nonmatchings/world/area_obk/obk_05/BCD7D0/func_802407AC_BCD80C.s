.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802407AC_BCD80C
/* BCD80C 802407AC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* BCD810 802407B0 AFB10014 */  sw        $s1, 0x14($sp)
/* BCD814 802407B4 0080882D */  daddu     $s1, $a0, $zero
/* BCD818 802407B8 AFBF0018 */  sw        $ra, 0x18($sp)
/* BCD81C 802407BC AFB00010 */  sw        $s0, 0x10($sp)
/* BCD820 802407C0 0C00EAD2 */  jal       get_npc_safe
/* BCD824 802407C4 8E24014C */   lw       $a0, 0x14c($s1)
/* BCD828 802407C8 0040802D */  daddu     $s0, $v0, $zero
/* BCD82C 802407CC 8E230074 */  lw        $v1, 0x74($s1)
/* BCD830 802407D0 24020001 */  addiu     $v0, $zero, 1
/* BCD834 802407D4 10620036 */  beq       $v1, $v0, .L802408B0
/* BCD838 802407D8 28620002 */   slti     $v0, $v1, 2
/* BCD83C 802407DC 10400005 */  beqz      $v0, .L802407F4
/* BCD840 802407E0 24020002 */   addiu    $v0, $zero, 2
/* BCD844 802407E4 10600007 */  beqz      $v1, .L80240804
/* BCD848 802407E8 00000000 */   nop
/* BCD84C 802407EC 08090247 */  j         .L8024091C
/* BCD850 802407F0 00000000 */   nop
.L802407F4:
/* BCD854 802407F4 10620036 */  beq       $v1, $v0, .L802408D0
/* BCD858 802407F8 00000000 */   nop
/* BCD85C 802407FC 08090247 */  j         .L8024091C
/* BCD860 80240800 00000000 */   nop
.L80240804:
/* BCD864 80240804 0C00A67F */  jal       rand_int
/* BCD868 80240808 240400B4 */   addiu    $a0, $zero, 0xb4
/* BCD86C 8024080C 24040032 */  addiu     $a0, $zero, 0x32
/* BCD870 80240810 3C01C3D7 */  lui       $at, 0xc3d7
/* BCD874 80240814 44810000 */  mtc1      $at, $f0
/* BCD878 80240818 2442001E */  addiu     $v0, $v0, 0x1e
/* BCD87C 8024081C A602008E */  sh        $v0, 0x8e($s0)
/* BCD880 80240820 0C00A67F */  jal       rand_int
/* BCD884 80240824 E6000040 */   swc1     $f0, 0x40($s0)
/* BCD888 80240828 3C014220 */  lui       $at, 0x4220
/* BCD88C 8024082C 44811000 */  mtc1      $at, $f2
/* BCD890 80240830 44820000 */  mtc1      $v0, $f0
/* BCD894 80240834 00000000 */  nop
/* BCD898 80240838 46800020 */  cvt.s.w   $f0, $f0
/* BCD89C 8024083C 46020000 */  add.s     $f0, $f0, $f2
/* BCD8A0 80240840 0C00A64D */  jal       func_80029934
/* BCD8A4 80240844 E600003C */   swc1     $f0, 0x3c($s0)
/* BCD8A8 80240848 46000000 */  add.s     $f0, $f0, $f0
/* BCD8AC 8024084C 3C014000 */  lui       $at, 0x4000
/* BCD8B0 80240850 44811000 */  mtc1      $at, $f2
/* BCD8B4 80240854 00000000 */  nop
/* BCD8B8 80240858 46020000 */  add.s     $f0, $f0, $f2
/* BCD8BC 8024085C 24040064 */  addiu     $a0, $zero, 0x64
/* BCD8C0 80240860 0C00A67F */  jal       rand_int
/* BCD8C4 80240864 E6000018 */   swc1     $f0, 0x18($s0)
/* BCD8C8 80240868 28420032 */  slti      $v0, $v0, 0x32
/* BCD8CC 8024086C 10400007 */  beqz      $v0, .L8024088C
/* BCD8D0 80240870 00000000 */   nop
/* BCD8D4 80240874 3C014387 */  lui       $at, 0x4387
/* BCD8D8 80240878 44810000 */  mtc1      $at, $f0
/* BCD8DC 8024087C 00000000 */  nop
/* BCD8E0 80240880 E6000038 */  swc1      $f0, 0x38($s0)
/* BCD8E4 80240884 08090229 */  j         .L802408A4
/* BCD8E8 80240888 E600000C */   swc1     $f0, 0xc($s0)
.L8024088C:
/* BCD8EC 8024088C 3C01C387 */  lui       $at, 0xc387
/* BCD8F0 80240890 44810000 */  mtc1      $at, $f0
/* BCD8F4 80240894 3C0142B4 */  lui       $at, 0x42b4
/* BCD8F8 80240898 44811000 */  mtc1      $at, $f2
/* BCD8FC 8024089C E6000038 */  swc1      $f0, 0x38($s0)
/* BCD900 802408A0 E602000C */  swc1      $f2, 0xc($s0)
.L802408A4:
/* BCD904 802408A4 24020001 */  addiu     $v0, $zero, 1
/* BCD908 802408A8 08090247 */  j         .L8024091C
/* BCD90C 802408AC AE220074 */   sw       $v0, 0x74($s1)
.L802408B0:
/* BCD910 802408B0 9602008E */  lhu       $v0, 0x8e($s0)
/* BCD914 802408B4 2442FFFF */  addiu     $v0, $v0, -1
/* BCD918 802408B8 A602008E */  sh        $v0, 0x8e($s0)
/* BCD91C 802408BC 00021400 */  sll       $v0, $v0, 0x10
/* BCD920 802408C0 14400016 */  bnez      $v0, .L8024091C
/* BCD924 802408C4 24020002 */   addiu    $v0, $zero, 2
/* BCD928 802408C8 08090247 */  j         .L8024091C
/* BCD92C 802408CC AE220074 */   sw       $v0, 0x74($s1)
.L802408D0:
/* BCD930 802408D0 8E050018 */  lw        $a1, 0x18($s0)
/* BCD934 802408D4 8E06000C */  lw        $a2, 0xc($s0)
/* BCD938 802408D8 0C00EA95 */  jal       npc_move_heading
/* BCD93C 802408DC 0200202D */   daddu    $a0, $s0, $zero
/* BCD940 802408E0 C6020038 */  lwc1      $f2, 0x38($s0)
/* BCD944 802408E4 3C01C38C */  lui       $at, 0xc38c
/* BCD948 802408E8 44810000 */  mtc1      $at, $f0
/* BCD94C 802408EC 00000000 */  nop
/* BCD950 802408F0 4600103C */  c.lt.s    $f2, $f0
/* BCD954 802408F4 00000000 */  nop
/* BCD958 802408F8 45030008 */  bc1tl     .L8024091C
/* BCD95C 802408FC AE200074 */   sw       $zero, 0x74($s1)
/* BCD960 80240900 3C01438C */  lui       $at, 0x438c
/* BCD964 80240904 44810000 */  mtc1      $at, $f0
/* BCD968 80240908 00000000 */  nop
/* BCD96C 8024090C 4602003C */  c.lt.s    $f0, $f2
/* BCD970 80240910 00000000 */  nop
/* BCD974 80240914 45030001 */  bc1tl     .L8024091C
/* BCD978 80240918 AE200074 */   sw       $zero, 0x74($s1)
.L8024091C:
/* BCD97C 8024091C 8FBF0018 */  lw        $ra, 0x18($sp)
/* BCD980 80240920 8FB10014 */  lw        $s1, 0x14($sp)
/* BCD984 80240924 8FB00010 */  lw        $s0, 0x10($sp)
/* BCD988 80240928 24020002 */  addiu     $v0, $zero, 2
/* BCD98C 8024092C 03E00008 */  jr        $ra
/* BCD990 80240930 27BD0020 */   addiu    $sp, $sp, 0x20
