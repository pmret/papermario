.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802403D8_DDF6E8
/* DDF6E8 802403D8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* DDF6EC 802403DC F7B40018 */  sdc1      $f20, 0x18($sp)
/* DDF6F0 802403E0 4480A000 */  mtc1      $zero, $f20
/* DDF6F4 802403E4 00000000 */  nop       
/* DDF6F8 802403E8 4405A000 */  mfc1      $a1, $f20
/* DDF6FC 802403EC AFBF0010 */  sw        $ra, 0x10($sp)
/* DDF700 802403F0 0C04E035 */  jal       func_801380D4
/* DDF704 802403F4 24040001 */   addiu    $a0, $zero, 1
/* DDF708 802403F8 4405A000 */  mfc1      $a1, $f20
/* DDF70C 802403FC 0C04DF69 */  jal       func_80137DA4
/* DDF710 80240400 2404000B */   addiu    $a0, $zero, 0xb
/* DDF714 80240404 8FBF0010 */  lw        $ra, 0x10($sp)
/* DDF718 80240408 D7B40018 */  ldc1      $f20, 0x18($sp)
/* DDF71C 8024040C 24020002 */  addiu     $v0, $zero, 2
/* DDF720 80240410 03E00008 */  jr        $ra
/* DDF724 80240414 27BD0020 */   addiu    $sp, $sp, 0x20
/* DDF728 80240418 00000000 */  nop       
/* DDF72C 8024041C 00000000 */  nop       
