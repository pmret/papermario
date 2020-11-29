.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80133A94
/* CA194 80133A94 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* CA198 80133A98 3C028015 */  lui       $v0, %hi(D_801565A0)
/* CA19C 80133A9C 8C4265A0 */  lw        $v0, %lo(D_801565A0)($v0)
/* CA1A0 80133AA0 00042080 */  sll       $a0, $a0, 2
/* CA1A4 80133AA4 AFBF0010 */  sw        $ra, 0x10($sp)
/* CA1A8 80133AA8 00822021 */  addu      $a0, $a0, $v0
/* CA1AC 80133AAC 8C840000 */  lw        $a0, ($a0)
/* CA1B0 80133AB0 3C03FFFB */  lui       $v1, 0xfffb
/* CA1B4 80133AB4 8C820000 */  lw        $v0, ($a0)
/* CA1B8 80133AB8 3463FFFF */  ori       $v1, $v1, 0xffff
/* CA1BC 80133ABC A4850018 */  sh        $a1, 0x18($a0)
/* CA1C0 80133AC0 00052940 */  sll       $a1, $a1, 5
/* CA1C4 80133AC4 34424000 */  ori       $v0, $v0, 0x4000
/* CA1C8 80133AC8 00431824 */  and       $v1, $v0, $v1
/* CA1CC 80133ACC AC830000 */  sw        $v1, ($a0)
/* CA1D0 80133AD0 3C028008 */  lui       $v0, %hi(gItemTable+0x18)
/* CA1D4 80133AD4 00451021 */  addu      $v0, $v0, $a1
/* CA1D8 80133AD8 944278F8 */  lhu       $v0, %lo(gItemTable+0x18)($v0)
/* CA1DC 80133ADC 30421000 */  andi      $v0, $v0, 0x1000
/* CA1E0 80133AE0 10400005 */  beqz      $v0, .L80133AF8
/* CA1E4 80133AE4 3C020004 */   lui      $v0, 4
/* CA1E8 80133AE8 00621025 */  or        $v0, $v1, $v0
/* CA1EC 80133AEC 2403BFFF */  addiu     $v1, $zero, -0x4001
/* CA1F0 80133AF0 00431024 */  and       $v0, $v0, $v1
/* CA1F4 80133AF4 AC820000 */  sw        $v0, ($a0)
.L80133AF8:
/* CA1F8 80133AF8 0C04C44A */  jal       func_80131128
/* CA1FC 80133AFC 00000000 */   nop      
/* CA200 80133B00 8FBF0010 */  lw        $ra, 0x10($sp)
/* CA204 80133B04 03E00008 */  jr        $ra
/* CA208 80133B08 27BD0018 */   addiu    $sp, $sp, 0x18
