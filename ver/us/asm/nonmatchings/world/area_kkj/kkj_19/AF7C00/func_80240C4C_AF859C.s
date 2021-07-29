.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240C4C_AF859C
/* AF859C 80240C4C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* AF85A0 80240C50 AFB00010 */  sw        $s0, 0x10($sp)
/* AF85A4 80240C54 0080802D */  daddu     $s0, $a0, $zero
/* AF85A8 80240C58 10A00002 */  beqz      $a1, .L80240C64
/* AF85AC 80240C5C AFBF0014 */   sw       $ra, 0x14($sp)
/* AF85B0 80240C60 AE000074 */  sw        $zero, 0x74($s0)
.L80240C64:
/* AF85B4 80240C64 8E020074 */  lw        $v0, 0x74($s0)
/* AF85B8 80240C68 24420010 */  addiu     $v0, $v0, 0x10
/* AF85BC 80240C6C AE020074 */  sw        $v0, 0x74($s0)
/* AF85C0 80240C70 28420100 */  slti      $v0, $v0, 0x100
/* AF85C4 80240C74 14400002 */  bnez      $v0, .L80240C80
/* AF85C8 80240C78 240200FF */   addiu    $v0, $zero, 0xff
/* AF85CC 80240C7C AE020074 */  sw        $v0, 0x74($s0)
.L80240C80:
/* AF85D0 80240C80 C6000074 */  lwc1      $f0, 0x74($s0)
/* AF85D4 80240C84 46800020 */  cvt.s.w   $f0, $f0
/* AF85D8 80240C88 44050000 */  mfc1      $a1, $f0
/* AF85DC 80240C8C 0C04DF62 */  jal       set_screen_overlay_params_front
/* AF85E0 80240C90 0000202D */   daddu    $a0, $zero, $zero
/* AF85E4 80240C94 8E020074 */  lw        $v0, 0x74($s0)
/* AF85E8 80240C98 8FBF0014 */  lw        $ra, 0x14($sp)
/* AF85EC 80240C9C 8FB00010 */  lw        $s0, 0x10($sp)
/* AF85F0 80240CA0 384200FF */  xori      $v0, $v0, 0xff
/* AF85F4 80240CA4 2C420001 */  sltiu     $v0, $v0, 1
/* AF85F8 80240CA8 00021040 */  sll       $v0, $v0, 1
/* AF85FC 80240CAC 03E00008 */  jr        $ra
/* AF8600 80240CB0 27BD0018 */   addiu    $sp, $sp, 0x18
