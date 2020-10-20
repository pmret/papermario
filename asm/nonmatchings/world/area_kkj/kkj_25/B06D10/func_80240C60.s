.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240C60
/* B07660 80240C60 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* B07664 80240C64 AFB00028 */  sw        $s0, 0x28($sp)
/* B07668 80240C68 0080802D */  daddu     $s0, $a0, $zero
/* B0766C 80240C6C AFBF002C */  sw        $ra, 0x2c($sp)
/* B07670 80240C70 C6020084 */  lwc1      $f2, 0x84($s0)
/* B07674 80240C74 468010A0 */  cvt.s.w   $f2, $f2
/* B07678 80240C78 C6040088 */  lwc1      $f4, 0x88($s0)
/* B0767C 80240C7C 46802120 */  cvt.s.w   $f4, $f4
/* B07680 80240C80 C606008C */  lwc1      $f6, 0x8c($s0)
/* B07684 80240C84 468031A0 */  cvt.s.w   $f6, $f6
/* B07688 80240C88 C6000090 */  lwc1      $f0, 0x90($s0)
/* B0768C 80240C8C 46800020 */  cvt.s.w   $f0, $f0
/* B07690 80240C90 27A20020 */  addiu     $v0, $sp, 0x20
/* B07694 80240C94 E7A00010 */  swc1      $f0, 0x10($sp)
/* B07698 80240C98 8E030094 */  lw        $v1, 0x94($s0)
/* B0769C 80240C9C 44051000 */  mfc1      $a1, $f2
/* B076A0 80240CA0 44062000 */  mfc1      $a2, $f4
/* B076A4 80240CA4 44073000 */  mfc1      $a3, $f6
/* B076A8 80240CA8 0000202D */  daddu     $a0, $zero, $zero
/* B076AC 80240CAC AFA20018 */  sw        $v0, 0x18($sp)
/* B076B0 80240CB0 0C01C28C */  jal       func_80070A30
/* B076B4 80240CB4 AFA30014 */   sw       $v1, 0x14($sp)
/* B076B8 80240CB8 8FA20020 */  lw        $v0, 0x20($sp)
/* B076BC 80240CBC AE020084 */  sw        $v0, 0x84($s0)
/* B076C0 80240CC0 8FBF002C */  lw        $ra, 0x2c($sp)
/* B076C4 80240CC4 8FB00028 */  lw        $s0, 0x28($sp)
/* B076C8 80240CC8 24020002 */  addiu     $v0, $zero, 2
/* B076CC 80240CCC 03E00008 */  jr        $ra
/* B076D0 80240CD0 27BD0030 */   addiu    $sp, $sp, 0x30
