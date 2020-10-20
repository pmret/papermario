.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024086C_C9679C
/* C9679C 8024086C 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* C967A0 80240870 AFB1001C */  sw        $s1, 0x1c($sp)
/* C967A4 80240874 0080882D */  daddu     $s1, $a0, $zero
/* C967A8 80240878 AFBF0034 */  sw        $ra, 0x34($sp)
/* C967AC 8024087C AFB60030 */  sw        $s6, 0x30($sp)
/* C967B0 80240880 AFB5002C */  sw        $s5, 0x2c($sp)
/* C967B4 80240884 AFB40028 */  sw        $s4, 0x28($sp)
/* C967B8 80240888 AFB30024 */  sw        $s3, 0x24($sp)
/* C967BC 8024088C AFB20020 */  sw        $s2, 0x20($sp)
/* C967C0 80240890 AFB00018 */  sw        $s0, 0x18($sp)
/* C967C4 80240894 F7B60040 */  sdc1      $f22, 0x40($sp)
/* C967C8 80240898 F7B40038 */  sdc1      $f20, 0x38($sp)
/* C967CC 8024089C 8E30000C */  lw        $s0, 0xc($s1)
/* C967D0 802408A0 8E160000 */  lw        $s6, ($s0)
/* C967D4 802408A4 26100004 */  addiu     $s0, $s0, 4
/* C967D8 802408A8 0C0B1EAF */  jal       get_variable
/* C967DC 802408AC 02C0282D */   daddu    $a1, $s6, $zero
/* C967E0 802408B0 44820000 */  mtc1      $v0, $f0
/* C967E4 802408B4 00000000 */  nop       
/* C967E8 802408B8 46800020 */  cvt.s.w   $f0, $f0
/* C967EC 802408BC E7A00010 */  swc1      $f0, 0x10($sp)
/* C967F0 802408C0 8E140000 */  lw        $s4, ($s0)
/* C967F4 802408C4 26100004 */  addiu     $s0, $s0, 4
/* C967F8 802408C8 0220202D */  daddu     $a0, $s1, $zero
/* C967FC 802408CC 0C0B1EAF */  jal       get_variable
/* C96800 802408D0 0280282D */   daddu    $a1, $s4, $zero
/* C96804 802408D4 0220202D */  daddu     $a0, $s1, $zero
/* C96808 802408D8 8E150000 */  lw        $s5, ($s0)
/* C9680C 802408DC 4482B000 */  mtc1      $v0, $f22
/* C96810 802408E0 00000000 */  nop       
/* C96814 802408E4 4680B5A0 */  cvt.s.w   $f22, $f22
/* C96818 802408E8 0C0B1EAF */  jal       get_variable
/* C9681C 802408EC 02A0282D */   daddu    $a1, $s5, $zero
/* C96820 802408F0 2404FFFC */  addiu     $a0, $zero, -4
/* C96824 802408F4 44820000 */  mtc1      $v0, $f0
/* C96828 802408F8 00000000 */  nop       
/* C9682C 802408FC 46800020 */  cvt.s.w   $f0, $f0
/* C96830 80240900 0C00EABB */  jal       get_npc_unsafe
/* C96834 80240904 E7A00014 */   swc1     $f0, 0x14($sp)
/* C96838 80240908 3C048007 */  lui       $a0, %hi(gCurrentCameraID)
/* C9683C 8024090C 8C847410 */  lw        $a0, %lo(gCurrentCameraID)($a0)
/* C96840 80240910 3C014334 */  lui       $at, 0x4334
/* C96844 80240914 44816000 */  mtc1      $at, $f12
/* C96848 80240918 00041880 */  sll       $v1, $a0, 2
/* C9684C 8024091C 00641821 */  addu      $v1, $v1, $a0
/* C96850 80240920 00031880 */  sll       $v1, $v1, 2
/* C96854 80240924 00641823 */  subu      $v1, $v1, $a0
/* C96858 80240928 000320C0 */  sll       $a0, $v1, 3
/* C9685C 8024092C 00641821 */  addu      $v1, $v1, $a0
/* C96860 80240930 000318C0 */  sll       $v1, $v1, 3
/* C96864 80240934 3C01800B */  lui       $at, 0x800b
/* C96868 80240938 00230821 */  addu      $at, $at, $v1
/* C9686C 8024093C C4201DEC */  lwc1      $f0, 0x1dec($at)
/* C96870 80240940 460C0300 */  add.s     $f12, $f0, $f12
/* C96874 80240944 0C00A6C9 */  jal       clamp_angle
/* C96878 80240948 0040982D */   daddu    $s3, $v0, $zero
/* C9687C 8024094C 27B00010 */  addiu     $s0, $sp, 0x10
/* C96880 80240950 0200202D */  daddu     $a0, $s0, $zero
/* C96884 80240954 27B20014 */  addiu     $s2, $sp, 0x14
/* C96888 80240958 0240282D */  daddu     $a1, $s2, $zero
/* C9688C 8024095C 3C064170 */  lui       $a2, 0x4170
/* C96890 80240960 8E67000C */  lw        $a3, 0xc($s3)
/* C96894 80240964 0C00A7E7 */  jal       add_vec2D_polar
/* C96898 80240968 46000506 */   mov.s    $f20, $f0
/* C9689C 8024096C 0200202D */  daddu     $a0, $s0, $zero
/* C968A0 80240970 3C064120 */  lui       $a2, 0x4120
/* C968A4 80240974 4407A000 */  mfc1      $a3, $f20
/* C968A8 80240978 0C00A7E7 */  jal       add_vec2D_polar
/* C968AC 8024097C 0240282D */   daddu    $a1, $s2, $zero
/* C968B0 80240980 0220202D */  daddu     $a0, $s1, $zero
/* C968B4 80240984 C7A00010 */  lwc1      $f0, 0x10($sp)
/* C968B8 80240988 4600008D */  trunc.w.s $f2, $f0
/* C968BC 8024098C 44061000 */  mfc1      $a2, $f2
/* C968C0 80240990 0C0B2026 */  jal       set_variable
/* C968C4 80240994 02C0282D */   daddu    $a1, $s6, $zero
/* C968C8 80240998 0220202D */  daddu     $a0, $s1, $zero
/* C968CC 8024099C 4600B08D */  trunc.w.s $f2, $f22
/* C968D0 802409A0 44061000 */  mfc1      $a2, $f2
/* C968D4 802409A4 0C0B2026 */  jal       set_variable
/* C968D8 802409A8 0280282D */   daddu    $a1, $s4, $zero
/* C968DC 802409AC 0220202D */  daddu     $a0, $s1, $zero
/* C968E0 802409B0 C7A00014 */  lwc1      $f0, 0x14($sp)
/* C968E4 802409B4 4600008D */  trunc.w.s $f2, $f0
/* C968E8 802409B8 44061000 */  mfc1      $a2, $f2
/* C968EC 802409BC 0C0B2026 */  jal       set_variable
/* C968F0 802409C0 02A0282D */   daddu    $a1, $s5, $zero
/* C968F4 802409C4 8FBF0034 */  lw        $ra, 0x34($sp)
/* C968F8 802409C8 8FB60030 */  lw        $s6, 0x30($sp)
/* C968FC 802409CC 8FB5002C */  lw        $s5, 0x2c($sp)
/* C96900 802409D0 8FB40028 */  lw        $s4, 0x28($sp)
/* C96904 802409D4 8FB30024 */  lw        $s3, 0x24($sp)
/* C96908 802409D8 8FB20020 */  lw        $s2, 0x20($sp)
/* C9690C 802409DC 8FB1001C */  lw        $s1, 0x1c($sp)
/* C96910 802409E0 8FB00018 */  lw        $s0, 0x18($sp)
/* C96914 802409E4 D7B60040 */  ldc1      $f22, 0x40($sp)
/* C96918 802409E8 D7B40038 */  ldc1      $f20, 0x38($sp)
/* C9691C 802409EC 24020002 */  addiu     $v0, $zero, 2
/* C96920 802409F0 03E00008 */  jr        $ra
/* C96924 802409F4 27BD0048 */   addiu    $sp, $sp, 0x48
