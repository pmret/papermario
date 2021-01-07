.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8021CF54_6A4154
/* 6A4154 8021CF54 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 6A4158 8021CF58 AFBF0010 */  sw        $ra, 0x10($sp)
/* 6A415C 8021CF5C 8C82000C */  lw        $v0, 0xc($a0)
/* 6A4160 8021CF60 0C0B1EAF */  jal       get_variable
/* 6A4164 8021CF64 8C450000 */   lw       $a1, ($v0)
/* 6A4168 8021CF68 8C43000C */  lw        $v1, 0xc($v0)
/* 6A416C 8021CF6C 3C013D23 */  lui       $at, 0x3d23
/* 6A4170 8021CF70 3421D70A */  ori       $at, $at, 0xd70a
/* 6A4174 8021CF74 44810000 */  mtc1      $at, $f0
/* 6A4178 8021CF78 00000000 */  nop       
/* 6A417C 8021CF7C E4600038 */  swc1      $f0, 0x38($v1)
/* 6A4180 8021CF80 E4600030 */  swc1      $f0, 0x30($v1)
/* 6A4184 8021CF84 8C43000C */  lw        $v1, 0xc($v0)
/* 6A4188 8021CF88 3C013FF0 */  lui       $at, 0x3ff0
/* 6A418C 8021CF8C 44810000 */  mtc1      $at, $f0
/* 6A4190 8021CF90 00000000 */  nop       
/* 6A4194 8021CF94 E4600034 */  swc1      $f0, 0x34($v1)
/* 6A4198 8021CF98 8C43000C */  lw        $v1, 0xc($v0)
/* 6A419C 8021CF9C 3C013D4C */  lui       $at, 0x3d4c
/* 6A41A0 8021CFA0 3421CCCD */  ori       $at, $at, 0xcccd
/* 6A41A4 8021CFA4 44810000 */  mtc1      $at, $f0
/* 6A41A8 8021CFA8 00000000 */  nop       
/* 6A41AC 8021CFAC E460003C */  swc1      $f0, 0x3c($v1)
/* 6A41B0 8021CFB0 8FBF0010 */  lw        $ra, 0x10($sp)
/* 6A41B4 8021CFB4 24020002 */  addiu     $v0, $zero, 2
/* 6A41B8 8021CFB8 03E00008 */  jr        $ra
/* 6A41BC 8021CFBC 27BD0018 */   addiu    $sp, $sp, 0x18
