.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240F40_ABC1D0
/* ABC1D0 80240F40 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* ABC1D4 80240F44 AFB00010 */  sw        $s0, 0x10($sp)
/* ABC1D8 80240F48 0080802D */  daddu     $s0, $a0, $zero
/* ABC1DC 80240F4C 10A00002 */  beqz      $a1, .L80240F58
/* ABC1E0 80240F50 AFBF0014 */   sw       $ra, 0x14($sp)
/* ABC1E4 80240F54 AE000074 */  sw        $zero, 0x74($s0)
.L80240F58:
/* ABC1E8 80240F58 0000202D */  daddu     $a0, $zero, $zero
/* ABC1EC 80240F5C 240500D0 */  addiu     $a1, $zero, 0xd0
/* ABC1F0 80240F60 00A0302D */  daddu     $a2, $a1, $zero
/* ABC1F4 80240F64 0C04DF84 */  jal       set_transition_stencil_color
/* ABC1F8 80240F68 00A0382D */   daddu    $a3, $a1, $zero
/* ABC1FC 80240F6C C6000074 */  lwc1      $f0, 0x74($s0)
/* ABC200 80240F70 46800020 */  cvt.s.w   $f0, $f0
/* ABC204 80240F74 44050000 */  mfc1      $a1, $f0
/* ABC208 80240F78 0C04DF62 */  jal       set_transition_stencil_zoom_0
/* ABC20C 80240F7C 24040001 */   addiu    $a0, $zero, 1
/* ABC210 80240F80 8E020074 */  lw        $v0, 0x74($s0)
/* ABC214 80240F84 240300FF */  addiu     $v1, $zero, 0xff
/* ABC218 80240F88 14430003 */  bne       $v0, $v1, .L80240F98
/* ABC21C 80240F8C 24420007 */   addiu    $v0, $v0, 7
/* ABC220 80240F90 080903EB */  j         .L80240FAC
/* ABC224 80240F94 24020002 */   addiu    $v0, $zero, 2
.L80240F98:
/* ABC228 80240F98 AE020074 */  sw        $v0, 0x74($s0)
/* ABC22C 80240F9C 28420100 */  slti      $v0, $v0, 0x100
/* ABC230 80240FA0 50400001 */  beql      $v0, $zero, .L80240FA8
/* ABC234 80240FA4 AE030074 */   sw       $v1, 0x74($s0)
.L80240FA8:
/* ABC238 80240FA8 0000102D */  daddu     $v0, $zero, $zero
.L80240FAC:
/* ABC23C 80240FAC 8FBF0014 */  lw        $ra, 0x14($sp)
/* ABC240 80240FB0 8FB00010 */  lw        $s0, 0x10($sp)
/* ABC244 80240FB4 03E00008 */  jr        $ra
/* ABC248 80240FB8 27BD0018 */   addiu    $sp, $sp, 0x18
/* ABC24C 80240FBC 00000000 */  nop
