.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240B18_B07518
/* B07518 80240B18 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* B0751C 80240B1C AFB00028 */  sw        $s0, 0x28($sp)
/* B07520 80240B20 0080802D */  daddu     $s0, $a0, $zero
/* B07524 80240B24 AFBF002C */  sw        $ra, 0x2c($sp)
/* B07528 80240B28 C6020084 */  lwc1      $f2, 0x84($s0)
/* B0752C 80240B2C 468010A0 */  cvt.s.w   $f2, $f2
/* B07530 80240B30 C6040088 */  lwc1      $f4, 0x88($s0)
/* B07534 80240B34 46802120 */  cvt.s.w   $f4, $f4
/* B07538 80240B38 C606008C */  lwc1      $f6, 0x8c($s0)
/* B0753C 80240B3C 468031A0 */  cvt.s.w   $f6, $f6
/* B07540 80240B40 C6000090 */  lwc1      $f0, 0x90($s0)
/* B07544 80240B44 46800020 */  cvt.s.w   $f0, $f0
/* B07548 80240B48 27A20020 */  addiu     $v0, $sp, 0x20
/* B0754C 80240B4C E7A00010 */  swc1      $f0, 0x10($sp)
/* B07550 80240B50 8E030094 */  lw        $v1, 0x94($s0)
/* B07554 80240B54 44051000 */  mfc1      $a1, $f2
/* B07558 80240B58 44062000 */  mfc1      $a2, $f4
/* B0755C 80240B5C 44073000 */  mfc1      $a3, $f6
/* B07560 80240B60 0000202D */  daddu     $a0, $zero, $zero
/* B07564 80240B64 AFA20018 */  sw        $v0, 0x18($sp)
/* B07568 80240B68 0C01C28C */  jal       func_80070A30
/* B0756C 80240B6C AFA30014 */   sw       $v1, 0x14($sp)
/* B07570 80240B70 8FA20020 */  lw        $v0, 0x20($sp)
/* B07574 80240B74 AE020084 */  sw        $v0, 0x84($s0)
/* B07578 80240B78 8FBF002C */  lw        $ra, 0x2c($sp)
/* B0757C 80240B7C 8FB00028 */  lw        $s0, 0x28($sp)
/* B07580 80240B80 24020002 */  addiu     $v0, $zero, 2
/* B07584 80240B84 03E00008 */  jr        $ra
/* B07588 80240B88 27BD0030 */   addiu    $sp, $sp, 0x30
