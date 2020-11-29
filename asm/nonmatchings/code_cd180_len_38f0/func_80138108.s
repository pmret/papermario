.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80138108
/* CE808 80138108 3C048016 */  lui       $a0, %hi(D_8015C790)
/* CE80C 8013810C 2484C790 */  addiu     $a0, $a0, %lo(D_8015C790)
/* CE810 80138110 0000282D */  daddu     $a1, $zero, $zero
/* CE814 80138114 24830014 */  addiu     $v1, $a0, 0x14
/* CE818 80138118 3C01437F */  lui       $at, 0x437f
/* CE81C 8013811C 44811000 */  mtc1      $at, $f2
/* CE820 80138120 3C01BF80 */  lui       $at, %hi(D_BF806900)
/* CE824 80138124 44810000 */  mtc1      $at, $f0
/* CE828 80138128 2402FFFF */  addiu     $v0, $zero, -1
/* CE82C 8013812C 3C018015 */  lui       $at, %hi(D_80156900)
/* CE830 80138130 AC226900 */  sw        $v0, %lo(D_BF806900)($at)
/* CE834 80138134 3C018015 */  lui       $at, %hi(D_80156908)
/* CE838 80138138 AC226908 */  sw        $v0, %lo(D_80156908)($at)
/* CE83C 8013813C 3C018015 */  lui       $at, %hi(D_80156904)
/* CE840 80138140 E4206904 */  swc1      $f0, %lo(D_80156904)($at)
/* CE844 80138144 3C018015 */  lui       $at, %hi(D_8015690C)
/* CE848 80138148 E420690C */  swc1      $f0, %lo(D_8015690C)($at)
.L8013814C:
/* CE84C 8013814C 24A50001 */  addiu     $a1, $a1, 1
/* CE850 80138150 A060FFEE */  sb        $zero, -0x12($v1)
/* CE854 80138154 A060FFED */  sb        $zero, -0x13($v1)
/* CE858 80138158 A0800000 */  sb        $zero, ($a0)
/* CE85C 8013815C AC60FFFC */  sw        $zero, -4($v1)
/* CE860 80138160 AC60FFF8 */  sw        $zero, -8($v1)
/* CE864 80138164 AC60FFF4 */  sw        $zero, -0xc($v1)
/* CE868 80138168 AC60FFF0 */  sw        $zero, -0x10($v1)
/* CE86C 8013816C E4620000 */  swc1      $f2, ($v1)
/* CE870 80138170 24630018 */  addiu     $v1, $v1, 0x18
/* CE874 80138174 28A20002 */  slti      $v0, $a1, 2
/* CE878 80138178 1440FFF4 */  bnez      $v0, .L8013814C
/* CE87C 8013817C 24840018 */   addiu    $a0, $a0, 0x18
/* CE880 80138180 03E00008 */  jr        $ra
/* CE884 80138184 00000000 */   nop      
