.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800504C8
/* 2B8C8 800504C8 28A204B1 */  slti      $v0, $a1, 0x4b1
/* 2B8CC 800504CC 14400003 */  bnez      $v0, .L800504DC
/* 2B8D0 800504D0 28A2F6A0 */   slti     $v0, $a1, -0x960
/* 2B8D4 800504D4 08014139 */  j         .L800504E4
/* 2B8D8 800504D8 240504B0 */   addiu    $a1, $zero, 0x4b0
.L800504DC:
/* 2B8DC 800504DC 54400001 */  bnel      $v0, $zero, .L800504E4
/* 2B8E0 800504E0 2405F6A0 */   addiu    $a1, $zero, -0x960
.L800504E4:
/* 2B8E4 800504E4 03E00008 */  jr        $ra
/* 2B8E8 800504E8 A485020E */   sh       $a1, 0x20e($a0)
