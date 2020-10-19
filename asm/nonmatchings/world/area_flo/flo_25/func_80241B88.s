.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241B88
/* CF4758 80241B88 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* CF475C 80241B8C AFB10014 */  sw        $s1, 0x14($sp)
/* CF4760 80241B90 0080882D */  daddu     $s1, $a0, $zero
/* CF4764 80241B94 AFBF0024 */  sw        $ra, 0x24($sp)
/* CF4768 80241B98 AFB40020 */  sw        $s4, 0x20($sp)
/* CF476C 80241B9C AFB3001C */  sw        $s3, 0x1c($sp)
/* CF4770 80241BA0 AFB20018 */  sw        $s2, 0x18($sp)
/* CF4774 80241BA4 AFB00010 */  sw        $s0, 0x10($sp)
/* CF4778 80241BA8 F7BC0048 */  sdc1      $f28, 0x48($sp)
/* CF477C 80241BAC F7BA0040 */  sdc1      $f26, 0x40($sp)
/* CF4780 80241BB0 F7B80038 */  sdc1      $f24, 0x38($sp)
/* CF4784 80241BB4 F7B60030 */  sdc1      $f22, 0x30($sp)
/* CF4788 80241BB8 F7B40028 */  sdc1      $f20, 0x28($sp)
/* CF478C 80241BBC 8E30000C */  lw        $s0, 0xc($s1)
/* CF4790 80241BC0 8E130000 */  lw        $s3, ($s0)
/* CF4794 80241BC4 26100004 */  addiu     $s0, $s0, 4
/* CF4798 80241BC8 0C0B1EAF */  jal       get_variable
/* CF479C 80241BCC 0260282D */   daddu    $a1, $s3, $zero
/* CF47A0 80241BD0 4482E000 */  mtc1      $v0, $f28
/* CF47A4 80241BD4 00000000 */  nop       
/* CF47A8 80241BD8 4680E720 */  cvt.s.w   $f28, $f28
/* CF47AC 80241BDC 8E140000 */  lw        $s4, ($s0)
/* CF47B0 80241BE0 26100004 */  addiu     $s0, $s0, 4
/* CF47B4 80241BE4 0220202D */  daddu     $a0, $s1, $zero
/* CF47B8 80241BE8 0C0B1EAF */  jal       get_variable
/* CF47BC 80241BEC 0280282D */   daddu    $a1, $s4, $zero
/* CF47C0 80241BF0 4482D000 */  mtc1      $v0, $f26
/* CF47C4 80241BF4 00000000 */  nop       
/* CF47C8 80241BF8 4680D6A0 */  cvt.s.w   $f26, $f26
/* CF47CC 80241BFC 8E100000 */  lw        $s0, ($s0)
/* CF47D0 80241C00 0220202D */  daddu     $a0, $s1, $zero
/* CF47D4 80241C04 0C0B1EAF */  jal       get_variable
/* CF47D8 80241C08 0200282D */   daddu    $a1, $s0, $zero
/* CF47DC 80241C0C 4482C000 */  mtc1      $v0, $f24
/* CF47E0 80241C10 00000000 */  nop       
/* CF47E4 80241C14 4680C620 */  cvt.s.w   $f24, $f24
/* CF47E8 80241C18 3C128011 */  lui       $s2, %hi(gPlayerStatus)
/* CF47EC 80241C1C 2652EFC8 */  addiu     $s2, $s2, %lo(gPlayerStatus)
/* CF47F0 80241C20 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* CF47F4 80241C24 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* CF47F8 80241C28 C64200A8 */  lwc1      $f2, 0xa8($s2)
/* CF47FC 80241C2C 44800000 */  mtc1      $zero, $f0
/* CF4800 80241C30 00031080 */  sll       $v0, $v1, 2
/* CF4804 80241C34 00431021 */  addu      $v0, $v0, $v1
/* CF4808 80241C38 00021080 */  sll       $v0, $v0, 2
/* CF480C 80241C3C 00431023 */  subu      $v0, $v0, $v1
/* CF4810 80241C40 000218C0 */  sll       $v1, $v0, 3
/* CF4814 80241C44 00431021 */  addu      $v0, $v0, $v1
/* CF4818 80241C48 000210C0 */  sll       $v0, $v0, 3
/* CF481C 80241C4C 46001032 */  c.eq.s    $f2, $f0
/* CF4820 80241C50 3C01800B */  lui       $at, 0x800b
/* CF4824 80241C54 00220821 */  addu      $at, $at, $v0
/* CF4828 80241C58 C4361DEC */  lwc1      $f22, 0x1dec($at)
/* CF482C 80241C5C 45000005 */  bc1f      .L80241C74
/* CF4830 80241C60 00000000 */   nop      
/* CF4834 80241C64 3C0142C8 */  lui       $at, 0x42c8
/* CF4838 80241C68 44810000 */  mtc1      $at, $f0
/* CF483C 80241C6C 08090721 */  j         .L80241C84
/* CF4840 80241C70 4600B581 */   sub.s    $f22, $f22, $f0
.L80241C74:
/* CF4844 80241C74 3C0142C8 */  lui       $at, 0x42c8
/* CF4848 80241C78 44810000 */  mtc1      $at, $f0
/* CF484C 80241C7C 00000000 */  nop       
/* CF4850 80241C80 4600B580 */  add.s     $f22, $f22, $f0
.L80241C84:
/* CF4854 80241C84 0C00A6C9 */  jal       clamp_angle
/* CF4858 80241C88 4600B306 */   mov.s    $f12, $f22
/* CF485C 80241C8C 46000586 */  mov.s     $f22, $f0
/* CF4860 80241C90 3C014170 */  lui       $at, 0x4170
/* CF4864 80241C94 4481A000 */  mtc1      $at, $f20
/* CF4868 80241C98 0C00A8BB */  jal       sin_deg
/* CF486C 80241C9C 4600B306 */   mov.s    $f12, $f22
/* CF4870 80241CA0 46140002 */  mul.s     $f0, $f0, $f20
/* CF4874 80241CA4 00000000 */  nop       
/* CF4878 80241CA8 864200B0 */  lh        $v0, 0xb0($s2)
/* CF487C 80241CAC 3C013F00 */  lui       $at, 0x3f00
/* CF4880 80241CB0 44812000 */  mtc1      $at, $f4
/* CF4884 80241CB4 44821000 */  mtc1      $v0, $f2
/* CF4888 80241CB8 00000000 */  nop       
/* CF488C 80241CBC 468010A0 */  cvt.s.w   $f2, $f2
/* CF4890 80241CC0 46041082 */  mul.s     $f2, $f2, $f4
/* CF4894 80241CC4 00000000 */  nop       
/* CF4898 80241CC8 4600E700 */  add.s     $f28, $f28, $f0
/* CF489C 80241CCC 4602D680 */  add.s     $f26, $f26, $f2
/* CF48A0 80241CD0 0C00A8D4 */  jal       cos_deg
/* CF48A4 80241CD4 4600B306 */   mov.s    $f12, $f22
/* CF48A8 80241CD8 46140002 */  mul.s     $f0, $f0, $f20
/* CF48AC 80241CDC 00000000 */  nop       
/* CF48B0 80241CE0 0220202D */  daddu     $a0, $s1, $zero
/* CF48B4 80241CE4 0260282D */  daddu     $a1, $s3, $zero
/* CF48B8 80241CE8 4600E18D */  trunc.w.s $f6, $f28
/* CF48BC 80241CEC 44063000 */  mfc1      $a2, $f6
/* CF48C0 80241CF0 0C0B2026 */  jal       set_variable
/* CF48C4 80241CF4 4600C601 */   sub.s    $f24, $f24, $f0
/* CF48C8 80241CF8 0220202D */  daddu     $a0, $s1, $zero
/* CF48CC 80241CFC 4600D18D */  trunc.w.s $f6, $f26
/* CF48D0 80241D00 44063000 */  mfc1      $a2, $f6
/* CF48D4 80241D04 0C0B2026 */  jal       set_variable
/* CF48D8 80241D08 0280282D */   daddu    $a1, $s4, $zero
/* CF48DC 80241D0C 0220202D */  daddu     $a0, $s1, $zero
/* CF48E0 80241D10 4600C18D */  trunc.w.s $f6, $f24
/* CF48E4 80241D14 44063000 */  mfc1      $a2, $f6
/* CF48E8 80241D18 0C0B2026 */  jal       set_variable
/* CF48EC 80241D1C 0200282D */   daddu    $a1, $s0, $zero
/* CF48F0 80241D20 8FBF0024 */  lw        $ra, 0x24($sp)
/* CF48F4 80241D24 8FB40020 */  lw        $s4, 0x20($sp)
/* CF48F8 80241D28 8FB3001C */  lw        $s3, 0x1c($sp)
/* CF48FC 80241D2C 8FB20018 */  lw        $s2, 0x18($sp)
/* CF4900 80241D30 8FB10014 */  lw        $s1, 0x14($sp)
/* CF4904 80241D34 8FB00010 */  lw        $s0, 0x10($sp)
/* CF4908 80241D38 D7BC0048 */  ldc1      $f28, 0x48($sp)
/* CF490C 80241D3C D7BA0040 */  ldc1      $f26, 0x40($sp)
/* CF4910 80241D40 D7B80038 */  ldc1      $f24, 0x38($sp)
/* CF4914 80241D44 D7B60030 */  ldc1      $f22, 0x30($sp)
/* CF4918 80241D48 D7B40028 */  ldc1      $f20, 0x28($sp)
/* CF491C 80241D4C 24020002 */  addiu     $v0, $zero, 2
/* CF4920 80241D50 03E00008 */  jr        $ra
/* CF4924 80241D54 27BD0050 */   addiu    $sp, $sp, 0x50
