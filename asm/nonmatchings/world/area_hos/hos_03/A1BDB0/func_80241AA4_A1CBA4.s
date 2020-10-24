.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241AA4_A1CBA4
/* A1CBA4 80241AA4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A1CBA8 80241AA8 AFB00010 */  sw        $s0, 0x10($sp)
/* A1CBAC 80241AAC 0080802D */  daddu     $s0, $a0, $zero
/* A1CBB0 80241AB0 AFBF0014 */  sw        $ra, 0x14($sp)
/* A1CBB4 80241AB4 8E020148 */  lw        $v0, 0x148($s0)
/* A1CBB8 80241AB8 0C00EABB */  jal       get_npc_unsafe
/* A1CBBC 80241ABC 84440008 */   lh       $a0, 8($v0)
/* A1CBC0 80241AC0 0040202D */  daddu     $a0, $v0, $zero
/* A1CBC4 80241AC4 8482008E */  lh        $v0, 0x8e($a0)
/* A1CBC8 80241AC8 9483008E */  lhu       $v1, 0x8e($a0)
/* A1CBCC 80241ACC 18400005 */  blez      $v0, .L80241AE4
/* A1CBD0 80241AD0 2462FFFF */   addiu    $v0, $v1, -1
/* A1CBD4 80241AD4 A482008E */  sh        $v0, 0x8e($a0)
/* A1CBD8 80241AD8 00021400 */  sll       $v0, $v0, 0x10
/* A1CBDC 80241ADC 1C400006 */  bgtz      $v0, .L80241AF8
/* A1CBE0 80241AE0 00000000 */   nop      
.L80241AE4:
/* A1CBE4 80241AE4 8482008C */  lh        $v0, 0x8c($a0)
/* A1CBE8 80241AE8 14400003 */  bnez      $v0, .L80241AF8
/* A1CBEC 80241AEC 2402000E */   addiu    $v0, $zero, 0xe
/* A1CBF0 80241AF0 A480008E */  sh        $zero, 0x8e($a0)
/* A1CBF4 80241AF4 AE020070 */  sw        $v0, 0x70($s0)
.L80241AF8:
/* A1CBF8 80241AF8 8FBF0014 */  lw        $ra, 0x14($sp)
/* A1CBFC 80241AFC 8FB00010 */  lw        $s0, 0x10($sp)
/* A1CC00 80241B00 03E00008 */  jr        $ra
/* A1CC04 80241B04 27BD0018 */   addiu    $sp, $sp, 0x18
