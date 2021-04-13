.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80058CB8
/* 340B8 80058CB8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 340BC 80058CBC 00071400 */  sll       $v0, $a3, 0x10
/* 340C0 80058CC0 AFBF0010 */  sw        $ra, 0x10($sp)
/* 340C4 80058CC4 A4850006 */  sh        $a1, 6($a0)
/* 340C8 80058CC8 10400008 */  beqz      $v0, .L80058CEC
/* 340CC 80058CCC A4860008 */   sh       $a2, 8($a0)
/* 340D0 80058CD0 8C820010 */  lw        $v0, 0x10($a0)
/* 340D4 80058CD4 AC82000C */  sw        $v0, 0xc($a0)
/* 340D8 80058CD8 A4470000 */  sh        $a3, ($v0)
/* 340DC 80058CDC 0C0162A0 */  jal       func_80058A80
/* 340E0 80058CE0 8C84000C */   lw       $a0, 0xc($a0)
/* 340E4 80058CE4 0801633C */  j         .L80058CF0
/* 340E8 80058CE8 00000000 */   nop
.L80058CEC:
/* 340EC 80058CEC AC80000C */  sw        $zero, 0xc($a0)
.L80058CF0:
/* 340F0 80058CF0 8FBF0010 */  lw        $ra, 0x10($sp)
/* 340F4 80058CF4 03E00008 */  jr        $ra
/* 340F8 80058CF8 27BD0018 */   addiu    $sp, $sp, 0x18
